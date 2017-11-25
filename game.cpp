#include <QObject>

    explicit Game::Game(QObject *parent = 0){
        //var boardItems; // list of floor, goal and border items on the field
        int maxIndex=0; // number of cells in the current level's field = gameCanvas.numOfColumns * gameCanvas.numOfRows
        //var board; // array containing the description of the current level's board
        int numOfGoals = 0; // number of goal items (= number of objects)
        int numOfTreasures = 0; // number of objects already on a goal item
        //var itemObjects; // list of object items on the field
        //var itemMan; // man item
        //var undoHistory; // list of moves of the man and whether the man pushed an object on each move
        int undoHistoryStep; // number of the current step in the undo history
    }
 //   ~Game();

    int Q_INVOKABLE index(int column, int row) {

    }
    void Game::startNewGame(){

    }

    void Game::deleteBlocks(){
        for (int i = 0; i < maxIndex; ++i) {
            if (boardItems[i] != null)
            {
                boardItems[i].opacity = 0;
                boardItems[i].destroy();
            }
        }
        for (var i = 0; i < numOfGoals; ++i) { // numOfGoals = number of objects
            if (itemObjects[i] != null)
            {
                itemObjects[i].opacity = 0;
                itemObjects[i].destroy();
            }
        }
        if (itemMan != null)
            itemMan.opacity = 0;
    }

    void Game::createBoard(){

    }

    void Game::initBoard(){

    }

    QObject* Game::createBlockObject(QObject* item, int column, int row){

    }

    bool Game::createBlock(int column, int row){

    }

    void Game::setZooming(bool isZooming){

    }

    void Game::recenterMan(int x, int y,int dx, int dy){

    }

    void Game::zoomIn() {

    }

    void Game::zoomOut() {

    }

    void Game::testLevelWon() {

    }

    int Game::findItemObjectNumber(int column, int row) {

    }

    void Game::changeManPosition(int oldX, int oldY, int newX, int newY, int dx, int dy) {

    }

    void Game::changeObjectPosition(int which, int oldX, int oldY, int newX, int newY) {

    }

    void Game::moveMan(int dx,int dy) {

    }

    void Game::moveUp() {

    }

    void Game::moveDown() {

    }

    void Game::moveLeft() {

    }

    void Game::moveRight() {

    }

    void Game::moveManWithMouse(int x, int y) {

    }

    void Game::addToUndoHistory(int dx, int dy,bool isPushing) {

    }

    void Game::undo() {

    }

    void Game::goToPreviousLevel() {

    }

    void Game::goToNextLevel() {

    }
