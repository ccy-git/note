#include "mainwindow.h"
#include "listwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QMessageBox>
#include <QDir>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDateTime dateTime = QDateTime::currentDateTime();
    currentDate = dateTime.toString("yyyy-MM-dd");
//    默认文件名为当前时间
    fileName = currentDate;

    ui->label->setText(fileName);
    ui->label->setAlignment(Qt::AlignHCenter);
//    窗口置顶
    setWindowFlags(Qt::WindowStaysOnTopHint);
//    去掉标题栏
//    this->setWindowFlags(Qt::FramelessWindowHint);`

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textEdit_textChanged()
{

}

void MainWindow::on_save_clicked()
{
//    读取文本域信息
    QString text = ui->textEdit->toPlainText();

//    创建目录
    QDir dir(QDir::currentPath());
    if(!dir.exists(currentDate))    //如果Images文件夹不存在
    {
        dir.mkdir(currentDate);    //创建文件夹（名为Images）

        qDebug()<<QString("文件夹%1创建成功！").arg(currentDate);
    }
    else
    {
        qDebug()<<QString("文件夹%1已存在！").arg(currentDate);
    }

//    获取当前文本名称
    QString textName = ui->label->text();
//    输出文件名测试
    qDebug() << textName << endl;
//    输出信息测试
    qDebug() << text;
//    获取当前时间戳
    QString timestamp = QString::number(QDateTime::currentMSecsSinceEpoch());
    QString path = "./"+currentDate+"/"+fileName+"-"+timestamp +".note";
//    qDebug() << path;
    QFile file(path);

    bool isOpen = file.open(QIODevice::WriteOnly);
    if(isOpen == false){
        QMessageBox::warning(this,tr("警告信息"),tr("保存失败"));
        return;
    }

    file.write(textName.toUtf8());
     QMessageBox::warning(this,tr("警告信息"),tr("保存成功"));
    file.close();

}

void MainWindow::on_addList_triggered()
{
//      qDebug() << "123";
//    新建列表
      ListWindow *w1 = new ListWindow;
      w1->show();

}

void MainWindow::on_editName_clicked()
{
    bool bOk = false;
//    修改笔记名称
    QString noteName = QInputDialog::getText(this,
                                             "请输入",
                                             "请输入笔记名称",
                                              QLineEdit::Normal,
                                             "",
                                             &bOk);
    if(bOk&&!noteName.isEmpty()){
        ui->label->setText(noteName);
        fileName = noteName;
    }
}

void MainWindow::on_deleteText_clicked()
{
    ui->textEdit->clear();
}
