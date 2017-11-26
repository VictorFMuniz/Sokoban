#include "gamecanvas.h"




GameCanvas::GameCanvas()
{

}

// Métodos para acessar o QML
QObject* GameCanvas::qmlObject;
void GameCanvas::setViewer(QObject* qmlGameCanvas){
        Game:: qmlObject = qmlGameCanvas->findChild<QObject*>("gameCanvas");

}

bool GameCanvas::isAnimated(){

}
int GameCanvas::x(){
    return GameCanvas::qmlObject->property("x").toInt();
}
int GameCanvas::y(){
    return GameCanvas::qmlObject->property("y").toInt();
}
int GameCanvas::width(){
    return GameCanvas::qmlObject->property("width").toInt();
}
int GameCanvas::height(){
    return GameCanvas::qmlObject->property("height").toInt();
}
int GameCanvas::opacity(){
    return GameCanvas::qmlObject->property("opacity").toBool();
}
int GameCanvas::numOfColumns(){
    return GameCanvas::qmlObject->property("numOfColumns").toInt();
}
int GameCanvas::numOfRows(){
    return GameCanvas::qmlObject->property("numOfRows").toInt();
}
float GameCanvas::blockSize(){
    return GameCanvas::qmlObject->property("blockSize").toFloat();
}
float GameCanvas::offsetX(){
    return GameCanvas::qmlObject->property("offsetX").toFloat();
}
float GameCanvas::offsetY(){
    return GameCanvas::qmlObject->property("offsetY").toFloat();
}
float GameCanvas::addBlockSize(){
    return GameCanvas::qmlObject->property("addBlockSize").toFloat();
}
float GameCanvas::addOffsetX(){
    return GameCanvas::qmlObject->property("addOffsetX").toFloat();
}
float GameCanvas::addOffsetY(){
    return GameCanvas::qmlObject->property("addOffsetY").toFloat();
}
