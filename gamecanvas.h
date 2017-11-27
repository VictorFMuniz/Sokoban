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
    static QObject* qmlObject;
    static void setViewer(QObject*);

    bool setIsAnimated();
    bool getIsAnimated(bool);
    int setX();
    int getX(int);
    int getY();
    int setY(int);
    int getWidth();
    int setWidth(int);
    int getHeight();
    int setHeight(int);
    int getOpacity();
    int setOpacity(int);
    int getNumOfColumns();
    int setNumOfColumns(int);
    int getNumOfRows();
    int setNumOfRows(int);
    float getBlockSize();
    float setBlockSize(float);
    float getOffsetX();
    float setOffsetX(float);
    float getOffsetY();
    float setOffsetY(float);
    float getAddBlockSize();
    float setAddBlockSize(float);
    float getAddOffsetX();
    float setAddOffsetX(float);
    float getAddOffsetY();
    float setAddOffsetY(float);

#endif // GAMECANVAS_H
