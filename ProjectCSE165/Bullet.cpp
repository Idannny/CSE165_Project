#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

Bullet::Bullet(){ //every time space is pressed
    // drew the rect
    setRect(0,0,10,50);

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move())); // connect signal to object, bullet's constructor //every timeout bullet will move

    timer->start(50); //every 50 ms timeout signals move to move bullet

}

void Bullet::move(){
    // move bullet up
    setPos(x(),y()-10); //direction of bullet coordinates

    //when bullets move off the screen delete them waste of memoory
    if (pos().y() + rect().height() < 0 ){// 0 is origin for y (Topleft)// with rect().height()we now have that after the size of the bullet moves offscreen it is deleted
        scene() -> removeItem(this);
        delete this;
        qDebug() << "Bullet dead";
    }

}
