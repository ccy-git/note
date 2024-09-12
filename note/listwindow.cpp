#include "listwindow.h"
#include "ui_listwindow.h"
#include <QDateTime>.h>


ListWindow::ListWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ListWindow)
{
    ui->setupUi(this);
    QDateTime dateTime = QDateTime::currentDateTime();
    QString currentDateTime = dateTime.toString("yyyy-MM-dd hh:mm:ss");
    ui->label->setText(currentDateTime);

}

ListWindow::~ListWindow()
{
    delete ui;
}

void addList(){

}
void ListWindow::on_pushButton_clicked()
{

}
