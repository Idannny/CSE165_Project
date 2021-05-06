//#include <Player.h>
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsItem>
#include <QList>
#include <stdlib.h> //rand()
#include <vector>

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){

    // draw the enemy

    //WALLS
//    random spawn pos
     int random_x = rand() % 700; //create random enemy within screen
     int random_y = rand() % 600;

     setPos(30+random_x,random_y);

     setRect(0,0,100,500);


    // connect
    QTimer * timer = new QTimer(this);

   connect(timer,SIGNAL(timeout()),this,SLOT(move())); // connect signal to object, bullet's constructor //every timeout bullet will move

   timer->start(25); //every 25 ms timeout signals move to move bullet

}



void Enemy::move(){

    //when bullets move off the screen delete them waste of memoory
    if (pos().y() + rect().height() < 0 ){// 0 is origin for y (Topleft)// with rect().height()we now have that after the size of the
        scene() -> removeItem(this);
        delete this;
//        qDebug() << "Bullet dead";
    }

}
