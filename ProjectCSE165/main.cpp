#include "mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QApplication>

//-QgraphScene
//Qgraphics items
//qgraphics view


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

        //creates a scene objeptr
    QGraphicsScene *scene = new QGraphicsScene();

    //creates an item to put into scene
    QGraphicsRectItem *rect = new QGraphicsRectItem();
    rect ->setRect(0,0,100,100); //100wide100high

          //add the item to the scene
        scene->addItem(rect);

            // add a view
        QGraphicsView *view = new QGraphicsView(scene);
        view->show();
        // added item to the scene



    return a.exec();
}
