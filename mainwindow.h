#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include "ActiveQt/QAxWidget"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMessageBox>
#include <QMainWindow>
#include <QWidget>
#include "dmsdoor.h"
#include "variables.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void display_data();
    void init_image();
    void init_graphics(); //初始化主界面
    void print_floor(); //展示楼层信息
    void game_start();
    void is_braver_survival();
    void keyPressEvent(QKeyEvent *event);//键盘响应事件函数,原main函数改写
    int handle_keypress(int key_no); //对一个按键的处理判断
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QImage img_wall;
    QImage img_upstair;
    QImage img_downstair;
    QImage img_ydoor[4];
    QImage img_bdoor[4];
    QImage img_rdoor[4];
    QImage img_gdoor[4];
    QImage img_idoor[4];
    QImage img_falsewall;
    QImage img_monster[1][4];
    QImage img_braver[4][2];
    QImage img_lstore; //商店左边
    QImage img_mstore[4];//商店中间
    QImage img_rstore; //商店右边
    QImage img_lstore2; //商店左边
    QImage img_mstore2[4];//商店中间
    QImage img_rstore2; //商店右边
    QImage img_ykey;
    QImage img_bkey;
    QImage img_rkey;
    QImage img_rbottle; //红血瓶
    QImage img_bbottle; //蓝血瓶
    QImage img_rgem; //红宝石
    QImage img_bgem; //蓝宝石
    QImage img_sword;
    QImage img_shield;
    QImage img_gold;
    QImage img_npcold[4];
    QImage img_npcred[4];
    QImage img_thief[4];
    QGraphicsScene *scene_floor;
    QGraphicsPixmapItem **pixmap_items;

    //dmsdoor *wdmsdoor;
};
//character Braver(900, 10, 10, 1000, 0, 10, 0, 0, 1, 1, 1, 1, 1, 0,"a", "O");
#endif // MAINWINDOW_H
