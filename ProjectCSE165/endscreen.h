#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <QMainWindow>

namespace Ui {
class EndScreen;
}

class EndScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit EndScreen(QWidget *parent = nullptr);
    ~EndScreen();

private:
    Ui::EndScreen *ui;
};

#endif // ENDSCREEN_H
