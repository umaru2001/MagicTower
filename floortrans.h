#ifndef FLOORTRANS_H
#define FLOORTRANS_H
#include <QWidget>
#include <QString>
#include <QKeyEvent>
#include <QEvent>
#include <QMainWindow>
#include "variables.h"

namespace Ui {
class floortrans;
}

class floortrans : public QWidget
{
    Q_OBJECT
signals:
    void refresh();

public:
    explicit floortrans(QWidget *parent = nullptr);
    ~floortrans();
    void keyPressEvent(QKeyEvent *event) override;
    void setText();
    void floorswitch();
    int atstairs();
    int Tfloor;
    int tem;
    character* braver;

private:
    Ui::floortrans *ui;
};

#endif // FLOORTRANS_H
