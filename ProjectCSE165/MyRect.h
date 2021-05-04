#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>


class MyRect: public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent * event);
};

#endif // MYRECT_H
