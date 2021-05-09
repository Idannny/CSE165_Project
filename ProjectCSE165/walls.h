#ifndef WALLS_H
#define WALLS_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QObject> //any object using signals (line 12-13) and slots needs this
#include <QMediaPlayer>

class Walls: public QObject,public QGraphicsRectItem{  //, public Player{
    Q_OBJECT; //Macro

    //making new objects to represent rectangles
    QGraphicsRectItem * rectangle1;
    QGraphicsRectItem * rectangle2;
    //QGraphicsRectItem * rectangle3;



public:
    Walls(QGraphicsItem * parent = 0);
//    QMediaPlayer *resetSound;

public slots: //a member function that can be accesed by .cpp
    void moveDown();
    void move2();

private:
QMediaPlayer *resetSound;
    //refactor, adds definition to bullet.cpp
};


#endif // WALLS_H
