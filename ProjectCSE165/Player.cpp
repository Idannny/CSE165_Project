#include "Game.h"
//#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>

//#include "Bullet.h"
//#include "Button.h"
//#include "Enemy.h"
#include "Goal.h"
#include <QList>
#include <QDebug>
//#include <QMediaPlayer>

//Game Mechanics:

extern Game * game;
extern QMouseEvent * press;
extern Player * player;


Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent){ //Player is able to use in main

//Attribute of player
//    resetSound = new QMediaPlayer();
//    resetSound->setMedia(QUrl("qrc:/audio/zoom.wav"));//https://mixkit.co/free-sound-effects/

    goalSound = new QMediaPlayer();

    goalSound->setMedia(QUrl("qrc:/audio/coin.wav"));

}



void Player::keyPressEvent(QKeyEvent *event){ //when moving the player left and right with boudaries:




 QList<QGraphicsItem *> coinCollect= collidingItems();

    for (int i = 0, n = coinCollect.size(); i<n; i++){ //when player hits coin
     if(typeid(*(coinCollect[i])) == typeid(Goal)){
         if (goalSound->state() == QMediaPlayer::PlayingState){
                    goalSound->setPosition(0);
                }
                else if (goalSound->state() == QMediaPlayer::StoppedState){
                    goalSound->play();
                }
            game->score->increase();
//          qDebug()<<"coin check";

         delete coinCollect[i];


          return;
             }
          }






    if (event->key() == Qt::Key_A){
        if(pos().x()>0){ // if the player reaches the bounds because scene's Left is origin x
            setPos(x()-15,y());
            }
    }
    else if (event->key() == Qt::Key_D){
        if(pos().x() <975){ //30 is the player's right corner & 800 is the Viewscreen's right boundry
        setPos(x()+15,y());
        }
    }
   else if (event->key() == Qt::Key_W){

        if(pos().y()>0){ //up boundary
        setPos(x(),y()-15);
        }
    }
    else if (event->key() == Qt::Key_S){ //prevent from using up and down
        if(pos().y() <975){ //"down boundary --adjust the 800 to a bigger number to go down further...
        setPos(x(),y()+15);
        }
    }
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());

        scene()->addItem(bullet);
    }

}

void Player::spawnWall(){ //to spawn the enemy as rectangular objects: similar to user
    //create Walls AND goal

    Walls * borderWall = new Walls(); //VERY IMPORTANT
    scene() -> addItem(borderWall);
    /*scene() -> addItem(endGoal);*///additem is member from Qgraphicsscene
}

void Player::spawnGoal()
{
    Goal * endGoal = new Goal();
    scene() -> addItem(endGoal);//
}

void Player::resetPlayer(){

    setPos(400, 975);

    //new Player();
    // QPushButton::connect(my_button,SIGNAL(clicked()),game, SLOT(Button()));

     QObject::connect(game,SIGNAL(released()),game, SLOT(Player()));
}
