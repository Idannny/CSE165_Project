#include "mainwindow.h"
#include <QGraphicsScene>
#include "MyRect.h" //extends QraphicsRect
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QApplication>
#include <QColor> //allows for a change in color
#include <QTimer>
<<<<<<< HEAD
#include <QPushButton>
=======
>>>>>>> 14bc31f28bbfa56d2857a0bdd2511ffedfb6cd6b
#include <QLabel>

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


//keep characters in its own class

int main(int argc, char *argv[]){


    QApplication a(argc, argv); //we have an application window:




    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();



    //set color of the scene:

/*
    QGraphicsScene scene{
        backgrouund-color: red;
    }
*/

    QLabel *label = new QLabel();
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label->setText("first line\nsecond line");
    label->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    //Here is how to change position:
//    label->setGeometry(QRectF(10,10,30,80));




    // create an item to add to the scene
    MyRect * player = new MyRect();
    player->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels

    // add the item to the scene
    scene->addItem(player);

    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //bc then bullet goes on forever and creates a large window
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    view->show();
    view->setFixedSize(800,800); //window of focus set at 800px... this is the full game window
    scene->setSceneRect(0,0, 800,800);// coords and size of entire scene// view and scene are now at the origin (topleft)
    //item (player) is defaulted at scene coords

    //adding a reset button:
    QPushButton * button = new QPushButton(view);
    button->setText("Reset");
    button->setToolTip("A Button with my message");
    button->show();

    //Adding a label

   // QLabel * countLabel = new QLabel(view);
   // countLabel->


    // attributes are just variables ie. view as a pointer defined by a class QGraphicsView

    //member function ie. height() width()
    player->setPos(view ->width()/2, view->height() - player->rect().height());// setting location of the player according to window view

    //SPAWN enemy
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player, SLOT(spawn()));
    timer -> start(2000); //create an enemy every 2 seconds
    return a.exec(); //execution of the command


    //a testing comment

}
