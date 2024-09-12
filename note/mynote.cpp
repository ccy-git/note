#include "mynote.h"
#include "ui_mynote.h"

MyNote::MyNote(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyNote)
{
    ui->setupUi(this);

}

MyNote::~MyNote()
{
    delete ui;
}

void getNote(){

}
