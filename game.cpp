#include <QObject>
#include <vector>
#include <math.h>

using namespace std;

    explicit game::game(QObject *parent = 0){

    }
//    ~game();

    int Q_INVOKABLE index(int column, int row) {

    }
    void game::startNewGame(){
        gameView.state = "playing";
        if(gameView.currentLevel < 0) {
            gameView.currentLevel = 0;
        }
        gameCanvas.isAnimated = false;

        if(gameView.currentLevel >= gameView.levels.length) {
            gameView.currentLevel = 0;
        }
        undoHistory = new vector<int>();
        undoHistoryStep = 0;
        deleteBlocks();

        gameCanvas.addBlockSize = 0;
        gameCanvas.addOffsetX = 0;
        gameCanvas.addOffsetY = 0;
        gameCanvas.numOfRows = gameView.levels[gameView.currentLevel].length;

        gameCanvas.numOfColumns = 0;
            for (int i = 0; i < gameCanvas.numOfRows; ++i) {
                gameCanvas.numOfColumns =   max(gameCanvas.numOfColumns, gameView.levels[gameView.currentLevel][i].length);
            }
            maxIndex = gameCanvas.numOfRows * gameCanvas.numOfColumns;

            initBoard(); // initialize board
            gameCanvas.isAnimated = true;
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

    void game::createBoard(){
        board = new Array(gameCanvas.numOfRows);
            numOfGoals = 0;
            numOfTreasures = 0;

            for (var row = 0; row < gameCanvas.numOfRows; ++row) {
                board[row] = new Array(gameCanvas.numOfColumns);
                for (var column = 0; column < gameCanvas.numOfColumns; ++column) {
                    // 0: outside, 1: inside, 2: border, 3: goal, 4: object, 5: man, 6: object on goal, 7: man on goal
                    var boardElement = (column < gameView.levels[gameView.currentLevel][row].length) ? gameView.levels[gameView.currentLevel][row].charAt(column) : ' ';
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

    void game::initBoard(){

    }

    QObject* game::createBlockObject(QObject* item, int column, int row){

    }

    bool game::createBlock(int column, int row){

    }

    void game::setZooming(bool isZooming){

    }

    void game::recenterMan(int x, int y,int dx, int dy){

    }

    void game::zoomIn() {

    }

    void game::zoomOut() {

    }

    void game::testLevelWon() {

    }

    int game::findItemObjectNumber(int column, int row) {

    }

    void game::changeManPosition(int oldX, int oldY, int newX, int newY, int dx, int dy) {

    }

    void game::changeObjectPosition(int which, int oldX, int oldY, int newX, int newY) {

    }

    void game::moveMan(int dx,int dy) {

    }

    void game::moveUp() {

    }

    void game::moveDown() {

    }

    void game::moveLeft() {

    }

    void game::moveRight() {

    }

    void game::moveManWithMouse(int x, int y) {

    }

    void game::addToUndoHistory(int dx, int dy,bool isPushing) {

    }

    void game::undo() {

    }

    void game::goToPreviousLevel() {

    }

    void game::goToNextLevel() {

    }
