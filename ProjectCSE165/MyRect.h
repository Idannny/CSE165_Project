#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class MyRect: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);

public slots:
    void spawn(); //spawn is an event that will be created by extension
};

#endif // MYRECT_H
