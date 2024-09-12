#include "mainwindow.h"
#include "listwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QMessageBox>
#include <QDir>
#include <QInputDialog>
#include <mynote.h>
#include <QAction>


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
    ui->showWindows->setVisible(false);
    this->setMaximumSize(437,430);
    this->setMinimumSize(437,430);
//    窗口置顶
    setWindowFlags(Qt::WindowStaysOnTopHint);
    // 设置鼠标追踪，即使鼠标没有点击也会触发 mouseMoveEvent
      setMouseTracking(true);

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enterEvent(QEvent *event){
    QMainWindow::enterEvent(event);
    QPoint windowPos = this->pos();
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
//    如果 鼠标在窗口内并且满足隐藏的条件，并且显示按钮时可见的，此时调用函数显示窗口。
    if (frameGeometry().contains(QCursor::pos()) && (windowPos.y() <= screenGeometry.top() +10) &&  ui->showWindows->isVisible()){
        // 鼠标进入时显示窗口
        on_showWindows();
    }
}
void MainWindow::hideWindow()
{
//     如果鼠标不在窗口内，隐藏窗口并将其移出屏幕
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    if (!frameGeometry().contains(QCursor::pos())) {
        move(x(), screenGeometry.top() - height()-distance);
//        qDebug() << screenGeometry.top() - height() << endl;
//        qDebug() << "screenGeometry.top()" <<screenGeometry.top() << endl;
        ui->showWindows->setVisible(true);
    }
}

void MainWindow::leaveEvent(QEvent *event)
{
    QMainWindow::leaveEvent(event);
    // 获取窗口的全局位置
    QPoint windowPos = this->pos();
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    if (windowPos.y() <= screenGeometry.top() +distance){
         hideWindow();  // 鼠标离开时隐藏窗口
    }
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

    file.write(text.toUtf8());
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

void MainWindow::on_addText_triggered()
{
    MainWindow *w = new MainWindow;
    w->show();
}

void MainWindow::on_myNote_triggered()
{
    MyNote *mynote = new MyNote;
    mynote->show();

}

void MainWindow::on_showWindows()
{
    QSize windowSize = this->size();  // 获取窗口的宽高
    int windowHeight = windowSize.height();  // 获取窗口高度
    move(x(),y()+windowHeight+distance);
    ui->showWindows->setVisible(false);
}
