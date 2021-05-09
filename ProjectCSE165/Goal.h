#ifndef GOAL_H
#define GOAL_H


#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QObject> //any object using signals (line 12-13) and slots needs this

#include "Player.h"
class Goal: public QObject,public QGraphicsEllipseItem{
    Q_OBJECT //Macro

public:
    Goal(QGraphicsItem * parent = 0);

public slots: //a member function that can be accesed by .cpp
    void move();


};

#endif // GOAL_H
