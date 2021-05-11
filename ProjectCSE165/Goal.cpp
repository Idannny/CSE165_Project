#include "Game.h"
#include <stdlib.h> //rand()
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsItem>
#include <QList>

extern coinScore * score;

Goal::Goal(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    coinSprite = new QGraphicsPixmapItem;
  setPixmap(QPixmap(":/sprites/coinNewAgain.png"));
   show();

     int random_x = rand() % 500; //create random goal within screen
     int random_y = rand() % 500;

//     qDebug()<<"Spawning Goal";
//     qDebug()<<"x: "<< random_x << "y: " << random_y;

      // wont spawn on character
//         random_x = 200;
        qDebug()<<"Goal INSIDE x: "<<random_x<< " y: " <<random_y;

//        if(random_x < 400 || random_x > 500 && random_y < 400 || random_y > 500){
     setPos(random_x,random_y);
//SHOULDNT SPAWN ON CHARACTER
//end of while
}

void Goal::move()
{
//    QList<QGraphicsItem *> coinCollect = collidingItems();
//    for (int i = 0, n = coinCollect.size(); i<n; i++){ //when goal is hit by
//        if(typeid(*(coinCollect[i])) == typeid(Goal)){

//          qDebug()<<"goal check";
//             }
//            }
////      setPos(100,100);

}


