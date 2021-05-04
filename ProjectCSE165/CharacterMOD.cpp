#include "CharacterMOD.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"

#include <QDebug>


void characterOne::keyPressEvent(QKeyEvent *event){
//qDebug() <<"we know a key was pressed";

    if(event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }
    else if(event->key() == Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if(event->key() == Qt::Key_Down){
        setPos(x(),y()+10);
    }
    else if (event->key() == Qt::Key_Space){
        //create bullt obj

        Bullet *bullet = new Bullet();
//           qDebug() << "made obj";
               scene()-> addItem(bullet);
    }


}
