#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private slots:
    void on_textEdit_textChanged();

    void on_save_clicked();

    void on_addList_triggered();

    void on_editName_clicked();

    void on_deleteText_clicked();

    void on_addText_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
