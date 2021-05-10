#include "Game.h"
//#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>

//#include "Bullet.h"
//#include "Button.h"
//#include "Enemy.h"
#include "Goal.h"
#include "Warrants.h"
#include <QList>
#include <QDebug>

//#include <QMediaPlayer>

//Game Mechanics:

extern Game * game;
extern QMouseEvent * press;
extern Player * player;
extern Attack *attack; //allows us to use these as a player //kinda like attributes

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){ //Player is able to use in main

    characterSprite = new QGraphicsPixmapItem;
  setPixmap(QPixmap(":/sprites/character.png"));
   show();
//Attribute of player
//    resetSound = new QMediaPlayer();
//    resetSound->setMedia(QUrl("qrc:/audio/zoom.wav"));//https://mixkit.co/free-sound-effects/

    //adds sound When you pick up a coin:
    goalSound = new QMediaPlayer();
    goalSound->setMedia(QUrl("qrc:/audio/coin.wav"));
    goalSound->setVolume(25);

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


//           Attack().moveUp();
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

//        Attack().moveDown();
        }
    }


    //ATTACKS
    else if (event->key() == Qt::Key_Up){
        // create a bullet
        Attack * attack = new Attack();
        attack->setPos(x(),y()-65);

        scene()->addItem(attack);
    }
    else if (event->key() == Qt::Key_Down){
    // create a bullet
    Attack * attack = new Attack();
    attack->setPos(x(),y()+10);

    scene()->addItem(attack);
    }
    else if (event->key() == Qt::Key_Right){
       // create a bullet
       Attack * attack = new Attack();
       attack->setPos(x()+100,y()-10);

       scene()->addItem(attack);
    }
    else if (event->key() == Qt::Key_Left){
       // create a bullet
       Attack * attack = new Attack();
       attack->setPos(x()-30,y()-10);

       scene()->addItem(attack);
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

    setPos(400, 800);

    //new Player();
    // QPushButton::connect(my_button,SIGNAL(clicked()),game, SLOT(Button()));
//     QObject::connect(game,SIGNAL(released()),game, SLOT(Player()));
}
