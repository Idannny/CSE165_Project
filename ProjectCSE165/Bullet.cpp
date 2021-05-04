#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <Enemy.h>
#include <QLabel>

Bullet::Bullet(){ //every time space is pressed
    // drew the rect
    setRect(0,0,10,50);
//double
    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move())); // connect signal to object, bullet's constructor //every timeout bullet will move

    timer->start(50); //every 50 ms timeout signals move to move bullet

}

int count= 0;


void Bullet::move(){
    //before anything check if bullet collides with an enemy
    //if bullet collides with enemy destroy both

    QList<QGraphicsItem *> colliding_items = collidingItems(); //we cand find what the bullet is colliding with


    for (int i = 0, n = colliding_items.size(); i<n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
                //remove both
                count++;
                scene() ->removeItem(colliding_items[i]);
                scene() ->removeItem(this);
                //remove from heap
                delete colliding_items[i];
                delete this; //bullet
                qDebug()<<count;
                return;//no memory errors
        }
    }
    // move bullet up
    setPos(x(),y()-10); //direction of bullet coordinates



    //when bullets move off the screen delete them waste of memoory
    if (pos().y() + rect().height() < 0 ){// 0 is origin for y (Topleft)// with rect().height()we now have that after the size of the bullet moves offscreen it is deleted
        scene() -> removeItem(this);
        delete this;
        //qDebug() << "Bullet dead";
        //My comment LaFrance
        //second comment
    }
}
