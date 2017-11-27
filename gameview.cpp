#include "gameview.h"

GameView::GameView()
{

}

// Métodos para acessar o QML
QObject* GameView::qmlObject;
void GameView::setViewer(QObject* qmlGameView){
        GameView:: qmlObject = qmlGameView;

}

bool opacity(){
    return GameView::qmlObject->property("opacity").toBool();
}

int GameView::currentLevel(){
    return GameView::qmlObject->property("currentLevel").toInt();
}
bool GameView::isAnimated(){
    return GameView::qmlObject->property("isAnimated").toBool();
}
void GameView::state(QString state){
   GameView::qmlObject->setProperty("state",state);
}
QObject* GameView::levels(){
    return GameView::qmlObject->property("levels");
}



