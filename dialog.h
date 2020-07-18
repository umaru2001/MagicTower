#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include <QString>
#include <QKeyEvent>
#include <QEvent>
#include <QMainWindow>
#include "variables.h"

namespace Ui {
class dialog;
}

class dialog : public QWidget
{
    Q_OBJECT

public:
    explicit dialog(QWidget *parent = nullptr);
    ~dialog();
    character *braver;
    GLOBAL_VARS *vars;
    void keyPressEvent(QKeyEvent *event) override;

    void dialog_1f();
    void dialog_11f();
    void dialog_12f();
    void dialog_15f();

    void is_dialog();

signals:
    void closeSignal();

private:
    Ui::dialog *ui;
    void closeEvent(QCloseEvent *event) override;
};

#endif // DIALOG_H
