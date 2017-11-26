#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>
#include <QObject>

class GameView : public QObject
{
    Q_OBJECT
public:
    explicit GameView(QObject *parent = 0);
    //~Game();

    bool opacity();

    int currentLevel();
    bool isAnimated();
    void state(QString);
    QObject* levels();
#endif // GAMEVIEW_H
