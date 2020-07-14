#ifndef STORE_H
#define STORE_H
#include <QWidget>
#include <QString>
#include <QKeyEvent>
#include <QEvent>
#include "variables.h"

namespace Ui {
class store;
}

class store : public QWidget
{
    Q_OBJECT

public:
    explicit store(QWidget *parent = nullptr);
    ~store();
    void keyPressEvent(QKeyEvent *event);
    void set_text();

private:
    Ui::store *ui;
    void closeEvent(QCloseEvent *event) override;
signals:
    void closeSignal();
public:
    character* braver;
    GLOBAL_VARS* vars;
};

#endif // STORE_H
