#include "gameview.h"

GameView::GameView()
{

}

// Métodos para acessar o QML
QObject* GameView::qmlObject;
void GameView::setViewer(QObject* qmlGameView){
        GameView:: qmlObject = qmlGameView;

}

int GameView::getOpacity(){
    return GameCanvas::qmlObject->property("opacity").toBool();
}
int GameView::setOpacity(int level){
    return GameCanvas::qmlObject->setProperty("opacity",level);
}

int GameView::getCurrentLevel(){
    return GameView::qmlObject->property("currentLevel").toInt();
}
int GameView::setCurrentLevel(int level){
    return GameView::qmlObject->setProperty("currentLevel",level);
}

bool GameCanvas::getIsAnimated(){
    return GameView::qmlObject->property("isAnimated").toInt();
}
bool GameCanvas::setIsAnimated(bool animate){
    return GameView::qmlObject->setProperty("isAnimated",animate);
}

QString GameView::getState(){
   return GameView::qmlObject->property("state").toString();
}
void GameView::setState(QString state){
   GameView::qmlObject->setProperty("state",state);
}

QObject* GameView::levels(){
    return GameView::qmlObject->property("levels");
}



