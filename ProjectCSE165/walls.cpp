//#include <Player.h>
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsItem>
#include <QList>
#include <stdlib.h> //rand()
#include <vector>

Walls::Walls(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){



    //WALLS
    // random spawn pos
     int random_x = rand() % 700; //create random enemy within screen
     int random_y = rand() % 600;

     if(random_x>400 &&random_x<500){ // wont spawn on character
         random_x = 200;
     }
     setPos(30+random_x,random_y-30);

     setRect(0,0,100,500);


    // connect
    QTimer * timer = new QTimer(this);

   connect(timer,SIGNAL(timeout()),this,SLOT(move())); // connect signal to object, bullet's constructor //every timeout bullet will move

   timer->start(25); //every 25 ms timeout signals move to move bullet

}



void Walls::move(){

    //when bullets move off the screen delete them waste of memoory
    if (pos().y() + rect().height() < 0 ){// 0 is origin for y (Topleft)// with rect().height()we now have that after the size of the
        scene() -> removeItem(this);
        delete this;
//        qDebug() << "Bullet dead";
    }

}
