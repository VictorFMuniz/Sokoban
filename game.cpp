#include "game.h"
#include <QDebug>
#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>
#include <QObject>
#include <vector>
#include <math.h>

using namespace std;

    explicit game::game(QObject *parent = 0) {

    }
//    ~game();
    // nao entendi oq ta acontecendo nesse método
    int index(int column, int row) {
        return column + (row * gameCanvas.getNumOfColumns());
    }
    void game::startNewGame(){
        gameView.setState("playing");
        if(gameView.getCurrentLevel() < 0) {
            gameView.setCurrentLevel() = 0;
        }
        gameCanvas.setIsAnimated(false);

        if(gameView.getCurrentLevel() >= gameView.getLevels().length) {
            gameView.setCurrentLevel() = 0;
        }
        undoHistory = new vector<int>();
        undoHistoryStep = 0;
        deleteBlocks();

        gameCanvas.addBlockSize(0);
        gameCanvas.addOffsetX(0);
        gameCanvas.addOffsetY(0);
        gameCanvas.numOfRows(gameView.getLevels()[gameView.getCurrentLevel()].length;);

        gameCanvas.setNumOfColumns(0);
            for (int i = 0; i < gameCanvas.getNumOfRows(); ++i) {
                gameCanvas.setNumOfColumns(max(gameCanvas.getNumOfColumns(), gameView.getLevels()[gameView.getCurrentLevel()][i].length));
            }
            maxIndex = gameCanvas.getNumOfRows() * gameCanvas.getNumOfColumns();

            initBoard(); // initialize board
            gameCanvas.setIsAnimated(true);
    }

    void game::deleteBlocks(){
        for (int i = 0; i < maxIndex; ++i) {

                if (boardItems[i] != NULL)
                {
                    boardItems[i].opacity = 0;
                    boardItems[i].destroy();
                }
            }
            for (int i = 0; i < numOfGoals; ++i) {
                if (itemObjects[i] != NULL)
                {
                    itemObjects[i].opacity = 0;
                    itemObjects[i].destroy();
                }
            }
            if (itemMan != NULL)
                itemMan.opacity = 0;
    }

    void game::createBoard() {
        vector<int> board(gameCanvas.getNumOfRows());
            numOfGoals = 0;
            numOfTreasures = 0;

            for (int row = 0; row < gameCanvas.getNumOfRows(); ++row) {
                 *board[row] = new vector<int>(gameCanvas.getNumOfColumns()); //verificar o funcionamento disso
                for (int column = 0; column < gameCanvas.getNumOfColumns(); ++column) {

                    char boardElement = (column < gameView.getLevels()[gameView.getCurrentLevel()][row].length) ? gameView.getLevels()[gameView.getCurrentLevel()][row].charAt(column) : ' ';
                    switch (boardElement) {
                        case ' ': board[row][column] = 1; break;
                        case '#': board[row][column] = 2; break;
                        case '.': board[row][column] = 3; ++numOfGoals; break;
                        case '$': board[row][column] = 4; break;
                        case '@': board[row][column] = 5; break;
                        case '*': board[row][column] = 6; ++numOfGoals; ++numOfTreasures; break;
                        case '+': board[row][column] = 7; ++numOfGoals; break;
                        default: board[row][column] = 0;
                    }
                }
            }
    }

    void game::initBoard() {
        boardItems = new vector<QObject*>(maxIndex);
        itemObjects = new vector<QObject*>();

        createBoard();

        for (int column = 0; column < gameCanvas.getNumOfColumns(); ++column) {
            for (int row = 0; row < gameCanvas.getNumOfRows(); ++row) {
                boardItems[index(column, row)] = NULL;
                createBlock(column, row);
            }
        }
    }

    QObject* game::createBlockObject(QObject* item, int column, int row) {
        QObject* dynamicObject = NULL;
        QDeclarativeEngine engine;
        QDeclarativeComponent comp(&engine, QUrl::fromLocalFile(".qml"));
        QObject *component = comp.create(items);

        if (component.status == Component.Ready) { // não sei que classe é essa: Component
            dynamicObject = component.createObject(gameCanvas);
            if (dynamicObject == NULL) {
                console.log("error creating block");
                console.log(component.errorString());
                return NULL;
            }
            dynamicObject.column = column;
            dynamicObject.row = row;
        } else {
            console.log("error loading block component");
            console.log(component.errorString());
            return NULL;
        }
        return dynamicObject;
    }

    bool game::createBlock(int column, int row) {
        QObject* blockSet = {"ItemFloor.qml", "ItemGoal.qml", "ItemObject.qml", "ItemMan.qml", "ItemBorder0.qml", "ItemBorder1.qml", "ItemBorder2.qml", "ItemBorder3.qml"};
            int which = board[row][column]; // 0: outside, 1: inside, 2: border, 3: goal, 4: object, 5: man, 6: object on goal, 7: man on goal
            QObject* item;

            if (which <= 0)
                return true;

            switch (which) {
                case 1:
                case 4: // when the spot has an object on it, put a floor item on this place and separately create the object below
                case 5: // when the spot has the man on it, put a floor item on this place and separately create the man below
                default:
                    item = blockSet[0];
                    break;
                case 3:
                case 6: // when the spot has an object on it, put a goal item on this place and separately create the object below
                case 7: // when the spot has the man on it, put a goal item on this place and separately create the man below
                    item = blockSet[1];
                    break;
                case 2: // border
                    if (board[row][column-1] != 2 && board[row][column+1] == 2)
                        item = blockSet[4];
                    else if (board[row][column-1] == 2 && board[row][column+1] == 2)
                        item = blockSet[5];
                    else if (board[row][column-1] == 2 && board[row][column+1] != 2)
                        item = blockSet[6];
                    else
                        item = blockSet[7];
                    break;
            }

            QObject* dynamicObject = createBlockObject(item, column, row);
            if (dynamicObject == NULL)
                return false;
            boardItems[index(column, row)] = dynamicObject;

            if (which == 4 || which == 6) { // create the object
                dynamicObject = createBlockObject(blockSet[2], column, row);
                if (dynamicObject == NULL)
                    return false;
                dynamicObject.z = 1;
                itemObjects[itemObjects.length] = dynamicObject;
            } else if (which == 5 || which == 7) { // create the man
                if (itemMan == NULL) {
                    dynamicObject = createBlockObject(blockSet[3], column, row);
                    if (dynamicObject == NULL)
                        return false;
                    dynamicObject.z = 1;
                    itemMan = dynamicObject;
                } else { // the man already exists from a previous level, reposition him
                    itemMan.column = column;
                    itemMan.row = row;
                    itemMan.opacity = 1;
                }
            }
            return true;
    }

    void game::setZooming(bool isZooming){
        for (int row = 0; row < gameCanvas.getNumOfRows(); ++row) {
            for (int column = 0; column < gameCanvas.getNumOfColumns(); ++column) {
                if (board[row][column] > 0){
                    boardItems[index(column, row)].isZooming = isZooming;
                }
            }
        }
        for (int i = 0; i < numOfGoals; ++i) {
            // numOfGoals = number of objects
            itemObjects[i].isZooming = isZooming;
        }
        if (itemMan != NULL){
            itemMan.isZooming = isZooming;
        }
    }

    void game::recenterMan(int x, int y, int dx, int dy){
        int currentManPixelX = x * gameCanvas.getBlockSize() + gameCanvas.getOffsetX();
        int currentManPixelY = y * gameCanvas.getBlockSize() + gameCanvas.getOffsetY();

        if (gameCanvas.getNumOfColumns() * gameCanvas.getBlockSize() <= gameCanvas.getWidth()) {
            dx = 0;
            gameCanvas.addOffsetX(0);
        }
        if (gameCanvas.getNumOfRows() * gameCanvas.getBlockSize() <= gameCanvas.getHeight()) {
            dy = 0;
            gameCanvas.addOffsetY(0);
        }

        if (dx < 0 || dx > 1)
            while (currentManPixelX < 3 * gameCanvas.blockSize()) {
                gameCanvas.addOffsetX(gameCanvas.getBlockSize());
                currentManPixelX += gameCanvas.getBlockSize();
            }
        if (dy < 0 || dy > 1)
            while (currentManPixelY < 3 * gameCanvas.getBlockSize()) {
                gameCanvas.addOffsetY(gameCanvasgetBlockSize());
                currentManPixelY += gameCanvas.getBlockSize();
            }
        if (dx > 0)
            while (currentManPixelX > gameCanvas.getWidth() - 3 * gameCanvas.getBlockSize()) {
                gameCanvas.addOffsetX(-(gameCanvas.getBlockSize()));
                currentManPixelX -= gameCanvas.getBlockSize();
            }
        if (dy > 0)
            while (currentManPixelY > gameCanvas.getHeight() - 3 * gameCanvas.getBlockSize()) {
                gameCanvas.addOffsetY(-(gameCanvas.getBlockSize()));
                currentManPixelY -= gameCanvas.getBlockSize();
            }
    }

    void game::zoomIn() {
        if (6 * gameCanvas.getBlockSize() > gameCanvas.getWidth() || 6 * gameCanvas.getBlockSize() > gameCanvas.getHeight()){
            return;
        }
        setZooming(true);
        gameCanvas.addBlockSize(5);
        recenterMan(itemMan.column, itemMan.row, 2, 2); // dx = 2 and dy = 2 in order to force recentering in both directions
        setZooming(false);
    }

    void game::zoomOut() {
        if (gameCanvas.getBlockSize() < 10){
            return;
        }

        setZooming(true);
        gameCanvas.addBlockSize(-5);
        recenterMan(itemMan.column, itemMan.row, 2, 2); // dx = 2 and dy = 2 in order to force recentering in both directions
        setZooming(false);
    }

    void game::testLevelWon() {
        if (numOfTreasures == numOfGoals) {
            if (gameView.getCurrentLevel() >= gameView.getLevels().length - 1)
                gameView.setState("gamewon");
            else
                gameView.setState("levelwon");
        }
    }

    int game::findItemObjectNumber(int column, int row) {
        int which = -1;
        for (int i = 0; i < itemObjects.length; ++i) {
            if (itemObjects[i].column == column && itemObjects[i].row == row) {
                which = i;
                break;
            }
        }
        return which;
    }

    void game::changeManPosition(int oldX, int oldY, int newX, int newY, int dx, int dy) {
        board[newY][newX] += 4; // 1: inside -> 5: man; 3: goal -> 7: man on goal
        board[oldY][oldX] -= 4; // 5 -> 1; 7 -> 3
        recenterMan(newX, newY, dx, dy);
    }

    void game::changeObjectPosition(int which, int oldX, int oldY, int newX, int newY) {
        if (board[oldY][oldX] == 6) // if object previously on goal
            --numOfTreasures;
        board[newY][newX] += 3; // 1: inside -> 4: object; 3: goal -> 6: treasure
        board[oldY][oldX] -= 3; // 4 -> 1; 6 -> 3
        itemObjects[which].column = newX;
        itemObjects[which].row = newY;
        if (board[newY][newX] == 6) // if object now on goal
            ++numOfTreasures;
    }

    void game::moveMan(int dx,int dy) {
        // 0: outside, 1: inside, 2: border, 3: goal, 4: object, 5: man, 6: object on goal, 7: man on goal
        if (board[itemMan.row+dy][itemMan.column+dx] == 1 || board[itemMan.row+dy][itemMan.column+dx] == 3) {
            changeManPosition(itemMan.column, itemMan.row, itemMan.column + dx, itemMan.row + dy, dx, dy);
            addToUndoHistory(dx, dy, 0);
            itemMan.column += dx;
            itemMan.row += dy;
        }
        else if ((board[itemMan.row+dy][itemMan.column+dx] == 4 || board[itemMan.row+dy][itemMan.column+dx] == 6)
            && (board[itemMan.row+2*dy][itemMan.column+2*dx] == 1 || board[itemMan.row+2*dy][itemMan.column+2*dx] == 3)) {
            int which = findItemObjectNumber(itemMan.column + dx, itemMan.row + dy);
            changeObjectPosition(which, itemMan.column + dx, itemMan.row + dy, itemMan.column + 2 * dx, itemMan.row + 2 * dy);
            changeManPosition(itemMan.column, itemMan.row, itemMan.column + dx, itemMan.row + dy, dx, dy); // must do this after changeObjectPosition because if the man goes to the place where the block was, the new type of the place is miscalculated
            addToUndoHistory(dx, dy, 1);
            itemMan.column += dx;
            itemMan.row += dy;
        }
        testLevelWon();
    }

    void game::moveUp() {
        moveMan(0, -1);
    }

    void game::moveDown() {
        moveMan(0, 1);
    }

    void game::moveLeft() {
        moveMan(-1, 0);
    }

    void game::moveRight() {
        moveMan(1, 0);
    }

    void game::moveManWithMouse(int x, int y) {
        int dx = (int) floor((x - gameCanvas.getOffsetX()) / gameCanvas.getBlockSize()) - itemMan.column;
        int dy = (int) floor((y - gameCanvas.getOffsetY()) / gameCanvas.getBlockSize()) - itemMan.row;

        if (dx != 0 && dy != 0) // we allow movement in one direction only
            return;

        int oldManX = 0;
        int oldManY = 0;
        if (dx > 0) {
            for (int i = 0; i < dx && itemMan.column != oldManX; ++i) {
                oldManX = itemMan.column;
                moveRight();
            }
        } else if (dx < 0) {
            for (int i = 0; i > dx && itemMan.column != oldManX; --i) {
                oldManX = itemMan.column;
                moveLeft();
            }
        } else if (dy > 0) {
            for (int i = 0; i < dy && itemMan.row != oldManY; ++i) {
                oldManY = itemMan.row;
                moveDown();
            }
        } else if (dy < 0) {
            for (int i = 0; i > dy && itemMan.row != oldManY; --i) {
                oldManY = itemMan.row;
                moveUp();
            }
        }
    }

    void game::addToUndoHistory(int dx, int dy,bool isPushing) {
        int num = undoHistoryStep;
        int move = (dx == -1 ? 0 : (dx == 1 ? 1 : (dy == -1 ? 2 : 3)));
        if (isPushing)
            move += 4;
        undoHistory[num] = move;
        ++undoHistoryStep;
    }

    void game::undo() {
        int dx;
        int dy;

        if (undoHistoryStep < 1)
            return;
        --undoHistoryStep;

        switch (undoHistory[undoHistoryStep]) {
            case 0: case 4: dx = -1; dy = 0; break;
            case 1: case 5: dx = 1; dy = 0; break;
            case 2: case 6: dx = 0; dy = -1; break;
            case 3: case 7: dx = 0; dy = 1; break;
        }
        changeManPosition(itemMan.column, itemMan.row, itemMan.column - dx, itemMan.row - dy, -dx, -dy); // must do this before changeObjectPosition because if the man is on the place where the block returns, the new type of the place is miscalculated
        if (undoHistory[undoHistoryStep] >= 4) { // if an object was moved in this step
            int which = findItemObjectNumber(itemMan.column + dx, itemMan.row + dy);
            changeObjectPosition(which, itemMan.column + dx, itemMan.row + dy, itemMan.column, itemMan.row);
        }
        itemMan.column -= dx;
        itemMan.row -= dy;
    }

    void game::goToPreviousLevel() {
        if (gameView.getCurrentLevel() > 0) {
            --gameView.setCurrentLevel();
        } else {
            gameView.setCurrentLevel(gameView.getLevels().length - 1);
        }
        startNewGame();
    }

    void game::goToNextLevel() {
        if (gameView.getCurrentLevel() < gameView.getLevels().length - 1){
            gameView.setCurrentLevel(gameView.getCurrentLevel()+1);
       } else{
            gameView.setCurrentLevel(0);
       }
       startNewGame();
    }
