#ifndef WARRANTS_H
#define WARRANTS_H

#include <QGraphicsRectItem>
#include <QObject> //any object using signals (line 12-13) and slots needs this

class Bullet: public QObject,public QGraphicsRectItem{
    Q_OBJECT //Macro

public:
    Bullet();
public slots: //a member function that can be accesed by .cpp
    void moveUp(); //refactor, adds definition to bullet.cpp

};

#endif // WARRANTS_H
