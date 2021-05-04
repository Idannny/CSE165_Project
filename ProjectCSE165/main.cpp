#include "mainwindow.h"
#include <QGraphicsScene>
#include "MyRect.h" //extends QraphicsRect
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QApplication>


//-QgraphScene
//Qgraphics items
//qgraphics view
//events
//Qdebug
//event propagation system

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to add to the scene
    MyRect * rect = new MyRect();
    rect->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels

    // add the item to the scene
    scene->addItem(rect);

    // make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    view->show();

    //==new code==


    return a.exec();
}
