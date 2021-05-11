#include "endscreen.h"
#include "ui_endscreen.h"

EndScreen::EndScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EndScreen)
{
    ui->setupUi(this);
}

EndScreen::~EndScreen()
{
    delete ui;
}
