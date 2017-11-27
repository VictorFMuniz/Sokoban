#include "gamecanvas.h"




GameCanvas::GameCanvas()
{

}

// Métodos para acessar o QML
QObject* GameCanvas::qmlObject;
void GameCanvas::setViewer(QObject* qmlGameCanvas){
        GameCanvas:: qmlObject = qmlGameCanvas->findChild<QObject*>("gameCanvas");

}

bool GameCanvas::getIsAnimated(){
    return GameCanvas::qmlObject->property("isAnimated").toInt();
}
bool GameCanvas::setIsAnimated(bool animate){
    return GameCanvas::qmlObject->setProperty("isAnimated",animate);
}

int GameCanvas::getX(){
    return GameCanvas::qmlObject->property("x").toInt();
}
int GameCanvas::setX(int x){
    return GameCanvas::qmlObject->setProperty("x",x);
}

int GameCanvas::getY(){
    return GameCanvas::qmlObject->property("y").toInt();
}
int GameCanvas::setY(int y){
    return GameCanvas::qmlObject->setProperty("y",y);
}

int GameCanvas::getWidth(){
    return GameCanvas::qmlObject->property("width").toInt();
}
int GameCanvas::setWidth(int w){
    return GameCanvas::qmlObject->setProperty("width",w);
}

int GameCanvas::getHeight(){
    return GameCanvas::qmlObject->property("height").toInt();
}
int GameCanvas::setHeight(int h){
    return GameCanvas::qmlObject->setProperty("height",h);
}

int GameCanvas::getOpacity(){
    return GameCanvas::qmlObject->property("opacity").toBool();
}
int GameCanvas::setOpacity(int level){
    return GameCanvas::qmlObject->setProperty("opacity",level);
}

int GameCanvas::getNumOfColumns(){
    return GameCanvas::qmlObject->property("numOfColumns").toInt();
}
int GameCanvas::setNumOfColumns(int col){
    return GameCanvas::qmlObject->setProperty("numOfColumns",col);
}

int GameCanvas::getNumOfRows(){
    return GameCanvas::qmlObject->property("numOfRows").toInt();
}
int GameCanvas::setNumOfRows(int row){
    return GameCanvas::qmlObject->setProperty("numOfRows",row);
}

float GameCanvas::getBlockSize(){
    return GameCanvas::qmlObject->property("blockSize").toFloat();
}
float GameCanvas::setBlockSize(float blkSz){
    return GameCanvas::qmlObject->setProperty("blockSize",blkSz);
}

float GameCanvas::getOffsetX(){
    return GameCanvas::qmlObject->property("offsetX").toFloat();
}
float GameCanvas::setOffsetX(float offX){
    return GameCanvas::qmlObject->setProperty("offsetX",offX);
}

float GameCanvas::getOffsetY(){
    return GameCanvas::qmlObject->property("offsetY").toFloat();
}
float GameCanvas::setOffsetY(float offY){
    return GameCanvas::qmlObject->setProperty("offsetY",offY);
}

float GameCanvas::getAddBlockSize(){
    return GameCanvas::qmlObject->property("addBlockSize").toFloat();
}
float GameCanvas::setAddBlockSize(float addBSz){
    return GameCanvas::qmlObject->setProperty("addBlockSize",addBSz);
}

float GameCanvas::getAddOffsetX(){
    return GameCanvas::qmlObject->property("addOffsetX").toFloat();
}
float GameCanvas::setAddOffsetX(float addOffX){
    return GameCanvas::qmlObject->setPoperty("addOffsetX",addOffX);
}

float GameCanvas::getAddOffsetY(){
    return GameCanvas::qmlObject->property("addOffsetY").toFloat();
}
float GameCanvas::setAddOffsetY(float addOffY){
    return GameCanvas::qmlObject->setProperty("addOffsetY",addOffY);
}
