#ifndef FIGHT_H
#define FIGHT_H
#include <QWidget>
#include <QKeyEvent>
#include "variables.h"
#include <QString>
#include <QEvent>
#include <QTimer>
#include <QMainWindow>

namespace Ui {
class Fight;
}

class Fight : public QWidget
{
    Q_OBJECT

signals:
    //void quit();
    void closeSignal();
public:
    explicit Fight(QWidget *parent = nullptr);
    ~Fight();

    character* braver;
    monster mo;
    int mo_hp;
    int tar_pos;

    void keyPressEvent(QKeyEvent *ev) override;
    void setTextMonster();
    void setTextBraver();
    void setTextGoldExp();
    void fight();
    int calc_my_damage();
    int calc_mo_damage();
    void init_text();
    void is_braver_survival();
    void is_monster_remain(); //用于复活怪物的判断
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::Fight *ui;
};

#endif // FIGHT_H
