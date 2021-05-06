#include "Enemy.h"
//#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h> //rand()

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){
    // draw the enemy

    //WALLS
//    random spawn pos
//    int random_x = rand() % 700; //create random enemy within screen
//     int random_y = rand() % 600;

     setPos(30,0);
     setPos(600,0);
    setRect(0,0,100,500);
    //setRect(0,0,100,200);
    // connect
   // QTimer * timer = new QTimer(this);

   //connect(timer,SIGNAL(timeout()),this,SLOT(move())); // connect signal to object, bullet's constructor //every timeout bullet will move

   //timer->start(25); //every 50 ms timeout signals move to move bullet

}

void Enemy::move(){
    // move enemy down
    setPos(x(),y()); //moves down

    //when bullets move off the screen delete them waste of memoory
    if (pos().y() + rect().height() < 0 ){// 0 is origin for y (Topleft)// with rect().height()we now have that after the size of the bullet moves offscreen it is deleted
        scene() -> removeItem(this);
        delete this;
//        qDebug() << "Bullet dead";
    }

}
