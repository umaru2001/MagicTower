#ifndef DMSDOOR_H
#define DMSDOOR_H

#include <QWidget>
#include <QString>
#include <QKeyEvent>
#include <QEvent>
#include "variables.h"

namespace Ui {
class dmsdoor;
}

class dmsdoor : public QWidget
{
    Q_OBJECT

public:
    explicit dmsdoor(QWidget *parent = nullptr);
    ~dmsdoor();
    void keyPressEvent(QKeyEvent *event) override;
    void set_text();
    void is_falsewall();
    character* braver;
    GLOBAL_VARS* vars;

private:
    Ui::dmsdoor *ui;
    void closeEvent(QCloseEvent *event) override;
signals:
    void closeSignal();
};

//extern dmsdoor *wdmsdoor;
#endif // DMSDOOR_H
