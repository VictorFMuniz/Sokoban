#include <QObject>

    explicit game::game(QObject *parent = 0){
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

    ~game(void);

    int Q_INVOKABLE index(int column, int row) {

    }
    void game::startNewGame(){

    }

    void game::deleteBlocks(){
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

    void game::createBoard(){

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
