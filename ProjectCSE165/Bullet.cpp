#include "Bullet.h"
#include <QTimer>

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
}
