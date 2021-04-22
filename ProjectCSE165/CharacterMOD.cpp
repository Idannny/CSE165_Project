#include "CharacterMOD.h"
#include <QKeyEvent>
#include <QtDebug>

void characterOne::keyPressEvent(QKeyEvent *event){
//qDebug() <<"we know a key was pressed";

    if(event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }
    if(event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }
    if(event->key() == Qt::Key_Up){
        setPos(x(),y()-10);
    }
    if(event->key() == Qt::Key_Down){
        setPos(x(),y()+10);
    }

}
