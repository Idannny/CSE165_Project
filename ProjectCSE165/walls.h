#ifndef WALLS_H
#define WALLS_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QObject> //any object using signals (line 12-13) and slots needs this

class Walls: public QObject,public QGraphicsRectItem{
    Q_OBJECT //Macro

public:
    Walls(QGraphicsItem * parent = 0);
public slots: //a member function that can be accesed by .cpp
    void move();
    //refactor, adds definition to bullet.cpp
};


#endif // WALLS_H
