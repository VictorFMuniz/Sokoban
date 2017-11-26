#ifndef GAMECANVAS_H
#define GAMECANVAS_H


#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>
#include <QObject>

class GameCanvas : public QObject
{
    Q_OBJECT
public:
    explicit GameCanvas(QObject *parent = 0);
    //~GameCanvas();

    bool isAnimated();
    int x();
    int y();
    int width();
    int height();
    int opacity();
    int numOfColumns();
    int numOfRows();
    float blockSize();
    float offsetX();
    float offsetY();
    float addBlockSize();
    float addOffsetX();
    float addOffsetY();

#endif // GAMECANVAS_H
