//#include "Button.h" //including our button header file
#include "Game.h"

extern Game * game;
extern QMouseEvent * press;
extern Player * player;

Button::Button(QPushButton *parent): QPushButton(parent){
    //creating the button:

    my_button = new QPushButton("End Game", this); //"this" is the parent of the button now

    //setting the size and location of the button:

    my_button->setGeometry(QRect(QPoint(0,0) , QSize(100, 100))); //a rectangle at point (0,0) and size (100x100)


    //connecting the button signal to the appropiate slot:

    my_button->connect(my_button, &QPushButton::clicked, this, &Button::resetPosition);

    //qDebug()<<"button clicked";


} //end of main button definition

//creating a function for the event of the button:



void Button::resetPosition(){

    qDebug()<<"Reset";

    // connect(my_button,SIGNAL(clicked()),player, SLOT(handleButton()))



   // game->player->setPos(500, 975); //so the player in game, movesd to the desired position

  //  game->player = new Player(); //should recreate the player again

    game->player->resetPlayer(); //we call the resetPlayer function to reset the players position

    delete game;


    // my_button->startTimer(5000); //wait a second before transitioning:

    my_button->setText("You have Died");




    //after button has been pressed... we go to handle

   //my_button->connect(my_button, &QPushButton::clicked, this, &Button::handleButton);

}

void Button::handleButton(){

    //change the text
    qDebug()<<"button clicked";

   // my_button->resize(100, 100);

    my_button->setText("Reset Again?");

    //call button again:




    //paused.. press again to reset
   my_button->connect(my_button, &QPushButton::clicked, this, &Button::resetPosition);

    //my_button->connect(my_button, &QPushButton::clicked, this, &Button::handleButton);

  //game->connect(my_button,SIGNAL(clicked()),game, SLOT(new Button()));







   // player = new Player();
   // Player(keyPressEvent()); //trying to fix the error where if i click it doesnt let me use the keyboard...



}
