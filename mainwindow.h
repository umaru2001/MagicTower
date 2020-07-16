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
    void print_floor();//展示楼层信息
    void print_floor_1(int x,int y,int t);
    void print_static(int x,int y);
    void is_greendoor_open();//实现绿门的判断

    void game_start();
    void is_braver_survival();
    void keyPressEvent(QKeyEvent *event);//键盘响应事件函数,原main函数改写
    int handle_keypress(int key_no); //对一个按键的处理判断
    ~MainWindow();

    int target_pos;
    int old_data;
    int OpenDoorTempData;
    int OpenDoorTargetPos;

private:
    Ui::MainWindow *ui;
    QImage img_wall;//棕墙
    QImage img_wall_grey;//灰墙
    QImage img_wall_blue;//蓝墙
    QImage img_wall_red;//红墙
    QImage img_ice;//冰块
    QImage img_wall_manga[2];//岩浆
    QImage img_wall_spring[2];//寒泉
    QImage img_wall_starry[2];//星空
    QImage img_wall_lava[2];//熔岩
    QImage img_upstair;
    QImage img_downstair;
    QImage img_wall_magiccircle[2];//魔法阵
    QImage img_wall_hole;//洞
    QImage img_ydoor[4];
    QImage img_bdoor[4];
    QImage img_rdoor[4];
    QImage img_gdoor[4];
    QImage img_idoor[4];   
    QImage img_monster[MONSTER_NUM][2];
    QImage img_braver[4][3];
    QImage img_lstore; //商店左边
    QImage img_mstore[2];//商店中间
    QImage img_rstore; //商店右边
    QImage img_lstore2; //商店左边
    QImage img_mstore2[2];//商店中间
    QImage img_rstore2; //商店右边
    QImage img_ykey;
    QImage img_bkey;
    QImage img_rkey;
    QImage img_rbottle; //红血瓶
    QImage img_bbottle; //蓝血瓶
    QImage img_rgem; //红宝石
    QImage img_bgem; //蓝宝石
    QImage img_ggem; //绿宝石
    QImage img_sword;
    QImage img_shield;
    QImage img_gold;
    QImage img_npcold[2];
    QImage img_npcred[2];
    QImage img_npcelf[2];
    QImage img_thief[2];
    QImage img_princess[2];

    QGraphicsScene *scene_floor;
    QGraphicsPixmapItem **pixmap_items;

    QTimer* NormalTimer; //层内动态效果的定时器
    int NormalTime;

    QTimer* Opendoor;
    int Opendoortime;

    //dmsdoor *wdmsdoor;
};
//character Braver(900, 10, 10, 1000, 0, 10, 0, 0, 1, 1, 1, 1, 1, 0,"a", "O");
#endif // MAINWINDOW_H
