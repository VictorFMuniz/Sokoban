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

    static QObject* qmlObject;
    static void setViewer(QObject*);

    int getOpacity();
    int setOpacity(int);
    int getCurrentLevel();
    int setCurrentLevel(int);
    bool getIsAnimated();
    bool setIsAnimated(bool);
    QString getState();
    void setState(QString);
    QObject* levels();
#endif // GAMEVIEW_H
