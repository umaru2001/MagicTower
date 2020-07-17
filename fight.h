#ifndef FIGHT_H
#define FIGHT_H
#include <QWidget>
#include <QKeyEvent>
#include "variables.h"
#include <QString>
#include <QEvent>
#include <QTimer>
#include <QMainWindow>
#include <QtMultimedia/QSound>

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
    void fight_twotimes();
    void fight_threetimes();
    void fight_fourtimes();
    void is_fight_times();
    int calc_my_damage();
    int calc_mo_damage();
    void init_text();
    void is_braver_survival();
    void is_monster_remain(); //用于复活怪物的判断
    void closeEvent(QCloseEvent *event) override;

    QSound *attack;

private:
    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;
    QTimer *timer5;
    Ui::Fight *ui;
};

#endif // FIGHT_H
