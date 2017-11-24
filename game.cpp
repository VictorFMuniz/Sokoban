#include <QObject>

    explicit game::game(QObject *parent = 0){

    }
//    ~game();

    int Q_INVOKABLE index(int column, int row) {

    }
    void game::startNewGame(){

    }

    void game::deleteBlocks(){

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
