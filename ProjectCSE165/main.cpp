

//#include "mainwindow.h"

//#include <QGraphicsScene>
//#include "Player.h" //extends QraphicsRect//PORTED TO GAME.CPP
//#include <QGraphicsView>
//#include <QGraphicsItem>
#include <QApplication>
#include "Game.h"

//#include <QDialog>
//#include <QMessageBox>
//#include <QPushButton>

//#include "Button.h"


//----------------PORTED TO GAME.CPP-----------------
//#include <QColor> //allows for a change in color
//#include <QTimer>


//#include <QPushButton>

//#include <QLabel>
//#include <QDialogButtonBox> //for our button mechanics
//#include <QButtonGroup> //to allow us to check if a button has been pressed
//#include <QPalette>

//-QgraphScene
//Qgraphics items
//qgraphics view
//events
//Qdebug
//event propagation system

//3 different coordinates
// -QgraphicScene coords will get bigger by default scene rect scollable area Begins at TopLeft
//- QGraphicView coords Begins at TopLeft (origin)
//-QGraphcsItem coords Begins at TopLeft (origin)




//     create an item to add to the scene??//PORTED TO GAME.CPP
//    Player * player = new Player();
//    player->setRect(0,0,25,25); // change the rect from 0x0 (default) to 100x100 pixels

//    // add the item to the scene
//    scene->addItem(player);

//    // make rect focusable
//    player->setFlag(QGraphicsItem::ItemIsFocusable);
//    player->setFocus();


  //  PORTED TO GAME.CPP
    // create a view to visualize the scene

//   view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //bc then bullet goes on forever and creates a large window
//   view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //setting window title:
//    view->setWindowTitle("Final Game"); //Lets think of a Title


    // show the view
   /* view->show();
    view->setFixedSize(800,600); //window of focus set at 800px... this is the full game window
    scene->setSceneRect(10,10, 800,600);// *///coords and size of entire scene// view and scene are now at the origin (topleft)
    //item (player) is defaulted at scene coords


    //set color of the view: //PORTED TO GAME.CPP
//    QColor * color = new QColor();
//    //scene->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
//    color->setNamedColor("blue");
//    view->setAutoFillBackground(color);



//    //adding a reset button:
//    QPushButton * button = new QPushButton(view); //will be displayed in view
//    button->setText("Reset");
//    button->setToolTip("A Button with my message");
//    button->show();

    //https://stackoverflow.com/questions/32182670/qt-how-to-know-that-a-pushbutton-is-clicked -- how to check if a button is clicked:

    /*
    unsigned i = 0;
     connect(button, &QPushButton::clicked, [i]{

     });


    bool flag = false;
    if(button->clicked(flag = true) == true){

        delete view;
    }
    //button->delete(view);
    */

    /*
    if(connect(button->, SIGNAL(clicked()), this, SLOT(close()));){

    }
   */

    //Adding a label
   // QLabel * countLabel = new QLabel(view);
   // countLabel->


    // attributes are just variables ie. view as a pointer defined by a class QGraphicsView

    //member function ie. height() width()
    /*player->setPos(view ->width()/2, view->height() - player->rect().height());// setting location of the player according to window view

    //SPAWN enemy
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player, SLOT(spawn()));
    timer -> start(1000);*/ //create an enemy every 2 seconds
    //view parameters ported //DOES THE SAME THING AS ^^^

    //    QGraphicsView * view = new QGraphicsView(scene);
 //    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //bc then bullet goes on forever and creates a large window
 //    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
 //    //topleftcorner window title
 //    view->setWindowTitle("Final Game");
 //    view->show();
 //    view->setFixedSize(800,600); //window of focus set at 800px... this is the full game window
 //    scene->setSceneRect(10,10, 800,600);//
//QGraphicsView * view = new QGraphicsView(scene);

Game * game;//CLASS game is from game.h is now parenting main.cpp

int main(int argc, char *argv[]){
    QApplication videoGame(argc, argv);

       game = new Game();
       game->show();




    return videoGame.exec(); //execution of the command


    //a testing comment

}
