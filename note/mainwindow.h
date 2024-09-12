#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QMouseEvent>
#include <QScreen>
#include <QTimer>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//    当前日期
    QString currentDate;
//    存储文件名称
     QString fileName;
protected:
     void leaveEvent(QEvent *event) override;  // 鼠标离开事件
     void enterEvent(QEvent *event) override;
private slots:
    void on_textEdit_textChanged();

    void on_save_clicked();

    void on_addList_triggered();

    void on_editName_clicked();

    void on_deleteText_clicked();

    void on_addText_triggered();

    void on_myNote_triggered();

    void hideWindow();          // 隐藏窗口

    void on_showWindows();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int distance = 10; //贴边距离
};

#endif // MAINWINDOW_H
