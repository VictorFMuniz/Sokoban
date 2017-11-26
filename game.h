#ifndef GAME_H
#define GAME_H

#include <QDebug>
#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>
#include <QObject>

class game : public QObject
{
    Q_OBJECT
public:
    explicit game(QObject *parent = 0);
    //~game();

private:
    var boardItems; // list of floor, goal and border items on the field
    int maxIndex; // number of cells in the current level's field = gameCanvas.numOfColumns * gameCanvas.numOfRows
    var board; // array containing the description of the current level's board
    int numOfGoals; // number of goal items (= number of objects)
    int numOfTreasures; // number of objects already on a goal item
    //var itemObjects; // list of object items on the field
    //var itemMan; // man item
    //var undoHistory; // list of moves of the man and whether the man pushed an object on each move
    int undoHistoryStep; // number of the current step in the undo history

    Q_INVOKABLE int index(int column, int row);
    Q_INVOKABLE void startNewGame(); /* Initialization */
    Q_INVOKABLE void deleteBlocks();
    Q_INVOKABLE void createBoard();
    Q_INVOKABLE  void initBoard();
    Q_INVOKABLE QObject* createBlockObject(QObject* item, int column, int row);
    Q_INVOKABLE bool createBlock(int column, int row);
    Q_INVOKABLE void setZooming(bool isZooming);/* Zooming */
    Q_INVOKABLE void recenterMan(int x, int y,int dx, int dy);
    Q_INVOKABLE void zoomIn();
    Q_INVOKABLE void zoomOut();
    Q_INVOKABLE void testLevelWon();
    Q_INVOKABLE int findItemObjectNumber(int column, int row);
    Q_INVOKABLE void changeManPosition(int oldX, int oldY, int newX, int newY, int dx, int dy);
    Q_INVOKABLE void changeObjectPosition(int which, int oldX, int oldY, int newX, int newY);
    Q_INVOKABLE void moveMan(int dx,int dy);
    Q_INVOKABLE void moveUp();
    Q_INVOKABLE void moveDown();
    Q_INVOKABLE void moveLeft();
    Q_INVOKABLE void moveRight();
    Q_INVOKABLE void moveManWithMouse(int x, int y);
    Q_INVOKABLE void addToUndoHistory(int dx, int dy,bool isPushing);
    Q_INVOKABLE void undo();
    Q_INVOKABLE void goToPreviousLevel();/* Change levels */
    Q_INVOKABLE void goToNextLevel();
};


#endif // GAME_H
