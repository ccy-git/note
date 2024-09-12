#ifndef MYNOTE_H
#define MYNOTE_H

#include <QMainWindow>
#include <QFile>

namespace Ui {
class MyNote;
}

class MyNote : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyNote(QWidget *parent = nullptr);
    ~MyNote();

    QFile file;

private:
    Ui::MyNote *ui;
};

#endif // MYNOTE_H
