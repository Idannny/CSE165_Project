#ifndef BOSS_H
#define BOSS_H

#endif // BOSS_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject> //any object using signals (line 12-13) and slots needs this
#include <QMediaPlayer>

class Boss: public QObject,public QGraphicsRectItem{



public:
    Boss(QGraphicsItem * parent = 0);
//    QMediaPlayer *resetSound;

public slots: //a member function that can be accesed by .cpp all of these slots are attributes that can change the direction and type of but will not create new types
//    void moveRight();
//    void moveLeft();



    //refactor, adds definition to bullet.cpp
};

