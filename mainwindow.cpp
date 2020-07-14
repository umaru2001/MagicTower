#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "store.h"
#include "mt.h"
#include"fight.h"


FLOOR Tower[TOTAL_FLOOR];
int result = 0;
character *braver = new character(900, 10, 10, 1000, 0, 10, 0, 0, 1, 1, 1, 1, 1, 0,"a", "O");
//hp,at,df,gold,exp,(x,y),floor,face,lv,ykey,bkey,rkey,"name","img";
monster m_array[1]=
{ monster(50, 18, 2, 1000, 1, 1, "slm", "H") //hp,at,df,gold,exp,id,"name","img";
};

void init_tower()
{
    FLOOR tmpfloor_1 = {
            10, 0, 51, 51, 51, 0, 0, 0, 0, 0, 0,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
            0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0,
            0, 51, 0, 1, 0, 1, 0, 0, 0, 1, 0,
            1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0,
            0, 0, 0, 1, 0, 0, 51, 51, 51, 1, 0,
            0, 51, 0, 1, 0, 1, 1, 1, 1, 1, 0,
            1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            34, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1,
            35, 37, 0, 1, 0, 0, 0, 1, 0, 51, 0,
            36, 38, 39, 1, 0, 0, 0, 1, 0, 0, 0,
    };
    memcpy(Tower[0], tmpfloor_1, sizeof(int) * X * Y);

    FLOOR tmpfloor_2 = {
        11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 1, 0, 51, 0, 51, 0, 1, 1,
        0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
        0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,
        0, 26, 45, 0, 1, 0, 0, 0, 1, 31, 47,
        0, 1, 44, 0, 0, 0, 0, 0, 31, 31, 46,
        0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,
        0, 1, 43, 0, 1, 0, 0, 0, 1, 21, 21,
        14, 1, 42, 0, 0, 0, 0, 0, 0, 21, 21,
    };
    memcpy(Tower[1], tmpfloor_2, sizeof(int) * X * Y);
}

GLOBAL_VARS *vars = new GLOBAL_VARS(0, 0);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene_floor = new QGraphicsScene;
    pixmap_items = new QGraphicsPixmapItem*[X * Y];
    setWindowTitle("魔塔");
    this->setWindowIcon(QPixmap(":/Titles/icon.png"));
}

void MainWindow::display_data()
{
    switch(braver->status)
    {
    case 0:
        ui->my_status->setText(QString::fromWCharArray(L"正常"));
        break;
    case 1:
        ui->my_status->setText(QString::fromWCharArray(L"中毒"));
        break;
    case 2:
        ui->my_status->setText(QString::fromWCharArray(L"衰弱"));
        break;
    }
    ui->my_lv->setText(QString::number(braver->lv));
    ui->my_hp->setText(QString::number(braver->hp));
    ui->my_at->setText(QString::number(braver->at));
    ui->my_df->setText(QString::number(braver->df));
    ui->my_exp->setText(QString::number(braver->exp));
    ui->my_ykey->setText(QString::number(braver->ykey));
    ui->my_bkey->setText(QString::number(braver->bkey));
    ui->my_rkey->setText(QString::number(braver->rkey));
    ui->my_gold->setText(QString::number(braver->gold));
    ui->floor_status->setText(QString::fromWCharArray(L"主塔"));
    ui->floor->setText(QString::number(braver->floor + 1) + QString::fromWCharArray(L"F"));
    ui->system_status->setText(vars->hint_msg);
    ui->item_status->setText(vars->gain_item_msg);
}

void MainWindow::init_image()
{
    img_wall = QImage(":/new/prefix1/Images/Image 88.png");
    img_upstair = QImage(":/new/prefix1/Images/Image 76.png");
    img_downstair = QImage(":/new/prefix1/Images/Image 73.png");
    img_ykey = QImage(":/new/prefix1/Images/Image 1.png");
    img_bkey = QImage(":/new/prefix1/Images/Image 4.png");
    img_rkey = QImage(":/new/prefix1/Images/Image 7.png");
    img_bbottle = QImage(":/new/prefix1/Images/Image 22.png");
    img_rbottle = QImage(":/new/prefix1/Images/Image 19.png");
    img_rgem = QImage(":/new/prefix1/Images/Image 10.png");
    img_bgem = QImage(":/new/prefix1/Images/Image 13.png");
    img_sword = QImage(":/new/prefix1/Images/Image 1520.bmp");
    img_shield = QImage(":/new/prefix1/Images/Image 1547.bmp");
    img_lstore = QImage(":/new/prefix1/Images/Image 559.png");
    img_rstore = QImage(":/new/prefix1/Images/Image 562.png");
    img_gold=QImage(":/new/prefix1/Images/Image 31.png");
    img_falsewall = QImage(":/new/prefix1/Images/Image 88.png");
    img_mstore[0] = QImage(":/new/prefix1/Images/Image 1541.png");
    img_mstore2[0] = QImage(":/new/prefix1/Images/Image 1582.png");
    img_ydoor[0] = QImage(":/new/prefix1/Images/Image 106.png");
    img_bdoor[0] = QImage(":/new/prefix1/Images/Image 115.png");
    img_rdoor[0] = QImage(":/new/prefix1/Images/Image 123.png");
    img_gdoor[0] = QImage(":/new/prefix1/Images/Image 139.png");
    img_idoor[0] = QImage(":/new/prefix1/Images/Image 131.png");
    img_npcold[0] = QImage(":/new/prefix1/Images/Image 1586.png");
    img_npcred[0] = QImage(":/new/prefix1/Images/Image 1562.png");
    img_thief[0] = QImage(":/new/prefix1/Images/Image 1568.png");
    img_braver[0][0] = QImage(":/new/prefix1/Images/Image 1607.png");//1607
    img_braver[1][0] = QImage(":/new/prefix1/Images/Image 3350.png");//3350
    img_braver[2][0] = QImage(":/new/prefix1/Images/Image 4134.png");
    img_braver[3][0] = QImage(":/new/prefix1/Images/Image 4138.png");//4138
    img_braver[0][1] = QImage(":/new/prefix1/Images/Image 4130.png");//4130
    img_braver[1][1] = QImage(":/new/prefix1/Images/Image 3290.png");//3290
    img_braver[2][1] = QImage(":/new/prefix1/Images/Image 4136.png");
    img_braver[3][1] = QImage(":/new/prefix1/Images/Image 3286.png");//3286
    img_monster[0][0] = QImage(":/new/prefix1/Images/Image 465.png");
}

void MainWindow::init_graphics()
{
    //窗口大小为固定值，不可以更改
    this->setFixedSize(511, 534);
    this->setFocusPolicy(Qt::StrongFocus);

    //首先画背景。背景为深红色砖块
    QImage img_background = QImage(":/new/prefix1/Images/Image 103.bmp");
    QPalette palette;
    palette.setBrush(QPalette::Window, QPixmap::fromImage(img_background));
    this->setPalette(palette);

    //绘制游戏界面内的下图层。
    QImage img_llayer = QImage(":/new/prefix1/Images/Image 79.png");
    QGraphicsScene *scene_llayer = new QGraphicsScene;
    scene_llayer->setBackgroundBrush(QPixmap::fromImage(img_llayer));
    ui->Game_print_down->setScene(scene_llayer);
    //QObject::connect(scene_llayer, SIGNAL(sceneRectChanged(QRectF)), this, SLOT(sceneRectChanged(QRectF)));

    //上图层graphicsView8背景透明 对齐方式靠左靠上
    ui->Game_print_up->setStyleSheet("background:transparent;");
    ui->Game_print_up->setFocusPolicy(Qt::NoFocus);

    //初始化物品栏
    QGraphicsScene *scene_ykey = new QGraphicsScene;
    scene_ykey->addPixmap(QPixmap::fromImage(img_ykey));
    ui->graphicsView_3->setScene(scene_ykey);
    ui->graphicsView_3->setStyleSheet("background:transparent;border:none;");

    QGraphicsScene *scene_bkey = new QGraphicsScene;
    scene_bkey->addPixmap(QPixmap::fromImage(img_bkey));
    ui->graphicsView_4->setScene(scene_bkey);
    ui->graphicsView_4->setStyleSheet("background:transparent;border:none;");

    QGraphicsScene *scene_rkey = new QGraphicsScene;
    scene_rkey->addPixmap(QPixmap::fromImage(img_rkey));
    ui->graphicsView_5->setScene(scene_rkey);
    ui->graphicsView_5->setStyleSheet("background:transparent;border:none;");

    QGraphicsScene *scene_gold = new QGraphicsScene;
    scene_gold->addPixmap(QPixmap::fromImage(img_gold));
    ui->graphicsView_6->setScene(scene_gold);
    ui->graphicsView_6->setStyleSheet("background:transparent;border:none;");

    QImage img_llayer2 = QImage(":/new/prefix1/Images/Image 79.png");
    QGraphicsScene *scene_llayer2 = new QGraphicsScene;
    scene_llayer->setBackgroundBrush(QPixmap::fromImage(img_llayer));
    ui->floor_graphics->setScene(scene_llayer);

    QImage img_llayer3 = QImage(":/new/prefix1/Images/Image 79.png");
    QGraphicsScene *scene_llayer3 = new QGraphicsScene;
    scene_llayer->setBackgroundBrush(QPixmap::fromImage(img_llayer));
    ui->Mystatus_01->setScene(scene_llayer);

    QImage img_llayer4 = QImage(":/new/prefix1/Images/Image 79.png");
    QGraphicsScene *scene_llayer4 = new QGraphicsScene;
    scene_llayer->setBackgroundBrush(QPixmap::fromImage(img_llayer));
    ui->Mystatus_03->setScene(scene_llayer);
    //QObject::connect(scene_llayer, SIGNAL(sceneRectChanged(QRectF)), this, SLOT(sceneRectChanged(QRectF)));
}

void MainWindow::print_floor()
{
    int x, y;
    scene_floor->clear();
    for (y = 0; y <= Y - 1; y++) {
        for (x = 0; x <= X - 1; x++) {
            if (braver->pos_x == x && braver->pos_y == y){
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_braver[braver->face][1]));
                //pixmap_items[0]->setPixmap(QPixmap::fromImage(img_braver[braver->face][0]));
                pixmap_items[0]->setPos(QPointF(32 * x, 32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            //else if (Tower[braver->floor][y * X + x] == 0) //空地
            else if (Tower[braver->floor][y * X + x] >= 1 && Tower[braver->floor][y * X + x] <= 9) //墙
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_wall));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 11 ) //下楼
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_downstair));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if ( Tower[braver->floor][y * X + x] == 12) //GameOver
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_upstair));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 10) //上楼
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_upstair));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 34) //小血瓶
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_rbottle));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 35) //大血瓶
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_bbottle));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 36) //红宝石
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_rgem));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 37) //蓝宝石
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_bgem));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 38) //铁剑
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_sword));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 39) //铁盾
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_shield));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 42) //商店
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_mstore[0]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 43) //商店
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_mstore2[0]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 44) //商店
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_mstore[0]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 45) //商店
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_mstore2[0]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 46) //钥匙商店
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_thief[0]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 47) //任意门商店
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_npcold[0]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 21) //门
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_ydoor[0]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 26) //暗墙
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_falsewall));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 31) //黄钥匙
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_ykey));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 51) //绿色史莱姆
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[0][0]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
        }
    }
    ui->Game_print_up->setScene(scene_floor);
}

int calc_damage(int monster_id)
{
    //计算伤害值。
    if (braver->at <= m_array[monster_id].df)
    {
        if (m_array[monster_id].at > braver->df)
            return -1;
        else
            return -2;
    }
    else {
        if (m_array[monster_id].at > braver->df) {
            int atk_times = (m_array[monster_id].hp - 1) / (braver->at - m_array[monster_id].df);
            return atk_times * (m_array[monster_id].at - braver->df);
        }
        else {
            return 0;
        }
    }
}

int handle_keypress(int key_no)
{
    // 返回操作状态。0为可以操作，1为对话模式（暂未实现），2为game_over, 3为开门, 4为上下楼, 5为战斗, 6为提示获得物品信息, 7为开启商店处理
    int target_pos;
    int old_data = -1;
    if (key_no == 0) { //向左
        braver->face = 1; //0/1/2/3分别代表下左右上
        if (braver->pos_x == 0)
            return 0;
        else
            target_pos = braver->pos_y * X + (braver->pos_x - 1);
    }
    else if (key_no == 1) { //向上
        braver->face = 3;
        if (braver->pos_y == 0)
            return 0;
        else
            target_pos = (braver->pos_y - 1) * X + braver->pos_x;
    }
    else if (key_no == 2) { //向右
        braver->face = 2;
        if (braver->pos_x == X - 1)
            return 0;
        else
            target_pos = braver->pos_y * X + (braver->pos_x + 1);
    }
    else if (key_no == 3) { //向下
        braver->face = 0;
        if (braver->pos_y == Y - 1)
            return 0;
        else
            target_pos = (braver->pos_y + 1) * X + braver->pos_x;
    }
    else {
        return 0;
    }
    old_data = Tower[braver->floor][target_pos];
    if (Tower[braver->floor][target_pos] == 0) {
        //平地 直接走过去
        braver->pos_x = target_pos % X;
        braver->pos_y = target_pos / X;
        return 0;
    }
    else if (Tower[braver->floor][target_pos] >= 1 && Tower[braver->floor][target_pos] <= 9) {
        //撞墙 位置不变化
        return 0;
    }
    else if (Tower[braver->floor][target_pos] == 10) {
        //上楼
        if (braver->floor != TOTAL_FLOOR - 1) {
            braver->floor += 1;
            int target_pos_upper = 0;
            for (int _it = 0; _it <= X * Y - 1; _it++) {
                if (Tower[braver->floor][_it] == 11) {
                    target_pos_upper = _it;
                    break;
                }
            }
            braver->pos_x = target_pos_upper % X;
            braver->pos_y = target_pos_upper / X;
        }
        return 4;
    }
    else if (Tower[braver->floor][target_pos] == 11) {
        //下楼
        if (braver->floor != 0) {
            braver->floor -= 1;
            int target_pos_lower = 0;
            for (int _it = 0; _it <= X * Y - 1; _it++) {
                if (Tower[braver->floor][_it] == 10) {
                    target_pos_lower = _it;
                    break;
                }
            }
            braver->pos_x = target_pos_lower % X;
            braver->pos_y = target_pos_lower / X;

        }
        return 4;
    }
    else if (Tower[braver->floor][target_pos] == 12) {
        //触发结局一：离开。直接Game Over
        vars->end_no = 1;
        return 1;
    }
    else if (Tower[braver->floor][target_pos] == 14) {
        vars->hint_msg = "3层之后的内容，还未制作完成。";
        return 1;
    }

    else if (Tower[braver->floor][target_pos] == 21) {
        //黄门
        if (braver->ykey >= 1) {
            braver->ykey -= 1;
            Tower[braver->floor][target_pos] = 0;
        }
        return 3;
    }
    else if (Tower[braver->floor][target_pos] == 22) {
        //蓝门
        if (braver->bkey >= 1) {
            braver->bkey -= 1;
            Tower[braver->floor][target_pos] = 0;
        }
        return 3;
    }
    else if (Tower[braver->floor][target_pos] == 23) {
        //红门
        if (braver->rkey >= 1) {
            braver->rkey -= 1;
            Tower[braver->floor][target_pos] = 0;
        }
        return 3;
    }
    else if (Tower[braver->floor][target_pos] == 25) {
        //铁门
        Tower[braver->floor][target_pos] = 0;
        return 3;
    }
    else if (Tower[braver->floor][target_pos] == 26) {
        //暗墙
        return 0;
    }
    else if (Tower[braver->floor][target_pos] == 31) {
        //黄钥匙
        Tower[braver->floor][target_pos] = 0;
        braver->ykey += 1;
        vars->gain_item_msg = "获得了一把黄钥匙";
        return 6;
    }
    else if (Tower[braver->floor][target_pos] == 32) {
        //蓝钥匙
        Tower[braver->floor][target_pos] = 0;
        braver->bkey += 1;
        vars->gain_item_msg = "获得了一把蓝钥匙";
        return 6;
    }
    else if (Tower[braver->floor][target_pos] == 33) {
        //红钥匙
        Tower[braver->floor][target_pos] = 0;
        braver->rkey += 1;
        vars->gain_item_msg = "获得了一把红钥匙";
        return 6;
    }
    else if (Tower[braver->floor][target_pos] == 34) {
        //小血瓶 序号：34
        Tower[braver->floor][target_pos] = 0;
        braver->hp += 50;
        vars->gain_item_msg = "获得了小血瓶 生命值增加50";
        return 6;
    }
    else if (Tower[braver->floor][target_pos] == 35) {
        //大血瓶 序号：35
        Tower[braver->floor][target_pos] = 0;
        braver->hp += 200;
        vars->gain_item_msg = "获得了大血瓶 生命值增加200";
        return 6;
    }
    else if (Tower[braver->floor][target_pos] == 36) {
        //红宝石 序号：36
        Tower[braver->floor][target_pos] = 0;
        braver->at += 1;
        vars->gain_item_msg = "获得了红宝石 攻击力增加1点";
        return 6;
    }
    else if (Tower[braver->floor][target_pos] == 37) {
        //蓝宝石 序号：37
        Tower[braver->floor][target_pos] = 0;
        braver->df += 1;
        vars->gain_item_msg = "获得了蓝宝石 防御力增加1点";
        return 6;
    }
    else if (Tower[braver->floor][target_pos] == 38) {
        //铁剑 序号：38
        Tower[braver->floor][target_pos] = 0;
        braver->at += 10;
        vars->gain_item_msg = "获得了铁剑 攻击力增加10点";
        return 6;
    }
    else if (Tower[braver->floor][target_pos] == 39) {
        //铁盾 序号：39
        Tower[braver->floor][target_pos] = 0;
        braver->df += 10;
        vars->gain_item_msg = "获得了铁盾 防御力增加10点";
        return 6;
    }
    else if (Tower[braver->floor][target_pos] == 42) {
        //商店处理1
        vars->store_no = 0;
        return 7;
    }
    else if (Tower[braver->floor][target_pos] == 43) {
        //商店处理2
        vars->store_no = 1;
        return 7;
    }
    else if (Tower[braver->floor][target_pos] == 44) {
        //商店处理3
        vars->store_no = 2;
        return 7;
    }
    else if (Tower[braver->floor][target_pos] == 45) {
        //商店处理4
        vars->store_no = 3;
        return 7;
    }
    else if (Tower[braver->floor][target_pos] == 46) {
        //商店处理4
        vars->store_no = 4;
        return 7;
    }
    else if (Tower[braver->floor][target_pos] == 47) {
        //商店处理4
        vars->store_no = 5;
        return 7;
    }
    else if (Tower[braver->floor][target_pos] >= 51) {
        //怪物
        int monster_id = Tower[braver->floor][target_pos] - 51;
        int damage = calc_damage(monster_id);
        if (damage == -2) {
            //在打不过时，不进行任何处理
            vars->hint_msg = "你还不能打败他";
            return 0;
        }
        else if (damage == -1 || damage >= braver->hp) {
            //在打不过时，不进行任何处理
            vars->hint_msg = "你还不能打败他";
            return 0;
        }
        else {
            Fight *fight = new Fight(braver->name,m_array[monster_id].name,braver->hp,m_array[monster_id].hp,braver->at,braver->df,m_array[monster_id].at,m_array[monster_id].df);
            fight->show();
            braver->hp -= damage;
            braver->gold += m_array[monster_id].gold;
            braver->exp += m_array[monster_id].exp;
            Tower[braver->floor][target_pos] = 0;
            QObject::connect(fight,&Fight::quit,[=]()
            {
                    fight->close();
            });
            return 5;
        }
    }
    return 0;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
        if (result == 0)
        {

            if(event->key() == Qt::Key_Up){ //向上
                // = 0;
                result = handle_keypress(1);
            }
            if(event->key() == Qt::Key_Down){ //向下
                result = handle_keypress(3);
            }
            if(event->key() == Qt::Key_Left){ //向左
                result = handle_keypress(0);
            }
            if(event->key() == Qt::Key_Right){ //向右
                result = handle_keypress(2);
            }
            if(event->key()==Qt::Key_T){
                dmsdoor *wdmsdoor= new dmsdoor;
                wdmsdoor->braver = braver;
                wdmsdoor->vars = vars;
                connect(wdmsdoor,&dmsdoor::closeSignal,this,[=](){
                    print_floor();
                });
                wdmsdoor->set_text();
                wdmsdoor->show();
                result=0;
            }
        }

        else if (result == 1) {
            vars->hint_msg="游戏结束！";
            result = 2;
        }
        if (result == 0) { //0为可以操作
            print_floor();
            display_data();
        }
        else if (result == 1) { //1为对话模式,暂未实现此功能
            print_floor();
            display_data();
            //show_dialog();暂无定义此功能
        }
        else if (result == 2) { //2为game_over,游戏结束
            this->close();
            //break;
        }
        else if (result == 3) { //3为正在开门中
            result = 0;
            print_floor();
            display_data();
        }
        else if (result == 4) { //4为上下楼转场
            result = 0;
            print_floor();
            display_data();
        }
        else if (result == 5) { //5为战斗，后续会加入战斗动画
            result = 0;
            print_floor();
            display_data();
        }
        else if (result == 6) { //6为打开获得物品界面
            result = 0;
            print_floor();
            display_data();
        }
        else if (result == 7) { //7为开启商店处理
            store *sstore = new store;
            sstore->braver = braver;
            sstore->vars = vars;
            connect(sstore,&store::closeSignal,this,[=](){
                display_data();
            });
            sstore->set_text();
            sstore->show();
            vars->hint_msg = " ";
            result = 0;
        }
}

void MainWindow::game_start()
{
    init_image();
    init_graphics();
    display_data();
    init_tower();
    print_floor();
}

MainWindow::~MainWindow()
{
    delete ui;
}

