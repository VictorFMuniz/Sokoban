#ifndef GAME_H
#define GAME_H

#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>
#include <QObject>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = 0);
    //~Game();

private:
    //var boardItems; // list of floor, goal and border items on the field
    int maxIndex; // number of cells in the current level's field = gameCanvas.numOfColumns * gameCanvas.numOfRows
    //var board; // array containing the description of the current level's board
    int numOfGoals; // number of goal items (= number of objects)
    int numOfTreasures; // number of objects already on a goal item
    //var itemObjects; // list of object items on the field
    //var itemMan; // man item
    //var undoHistory; // list of moves of the man and whether the man pushed an object on each move
    int undoHistoryStep; // number of the current step in the undo history


public:
    static QObject* qmlObject;
    static void setViewer(QObject* ob);


    int Q_INVOKABLE index(int column, int row);
    void startNewGame(); /* Initialization */
    void deleteBlocks();
    void createBoard();
    void initBoard();
    QObject* createBlockObject(QObject* item, int column, int row);
    bool createBlock(int column, int row);
    void setZooming(bool isZooming);/* Zooming */
    void recenterMan(int x, int y,int dx, int dy);
    void zoomIn();
    void zoomOut();
    void testLevelWon();
    int findItemObjectNumber(int column, int row);
    void changeManPosition(int oldX, int oldY, int newX, int newY, int dx, int dy);
    void changeObjectPosition(int which, int oldX, int oldY, int newX, int newY);
    void moveMan(int dx,int dy);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void moveManWithMouse(int x, int y);
    void addToUndoHistory(int dx, int dy,bool isPushing);
    void undo();
    void goToPreviousLevel();/* Change levels */
    void goToNextLevel();
};


#endif // GAME_H
