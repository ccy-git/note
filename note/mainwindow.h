#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QMouseEvent>
#include <QScreen>
#include <QTimer>
#include <QDebug>
#include <QClipboard>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  QString getFileName(QString fileName);
//    当前日期
    QString currentDate;
//    存储文件名称
     QString fileName;
protected:
     void leaveEvent(QEvent *event) override;  // 鼠标离开事件
     void enterEvent(QEvent *event) override;
private slots:

    void on_save_clicked();

    void on_addList_triggered();

    void on_editName_clicked();

    void on_deleteText_clicked();

    void on_addText_triggered();

    void hideWindow();          // 隐藏窗口

    void on_showWindows();

    void getClipboardInfo(QClipboard::Mode mode); //获取剪切板的内容

    void on_clipBoard_clicked();
    void on_open_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int distance = 10; //贴边距离
    bool isStartClipBoard = false;
};

#endif // MAINWINDOW_H
