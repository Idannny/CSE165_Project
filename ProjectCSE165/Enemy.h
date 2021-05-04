#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QObject> //any object using signals (line 12-13) and slots needs this

class Enemy: public QObject,public QGraphicsRectItem{
    Q_OBJECT //Macro

public:
    Enemy(QGraphicsItem * parent = 0);
public slots: //a member function that can be accesed by .cpp
    void move();
    //refactor, adds definition to bullet.cpp
};


#endif // ENEMY_H
