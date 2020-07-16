#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "store.h"
#include "mt.h"
#include "fight.h"


FLOOR Tower[TOTAL_FLOOR];
int result = 0;
character *braver = new character(900, 10, 10, 1000, 0, 10, 0, 0, 1, 1, 1, 1, 1, 0,"a", "O");
//hp,at,df,gold,exp,(x,y),floor,face,lv,ykey,bkey,rkey,"name","img";
monster m_array[2]=
{ monster(35, 19, 2, 1000, 1, 1, "绿色史莱姆", "H"), //hp,at,df,gold,exp,id,"name","img";
  monster(45, 23, 3, 1, 1, 1, "红色史莱姆","R")
};

void init_tower()
{
    FLOOR tmpfloor_1 = {
            10, 0, 51, 52, 51, 0, 0, 0, 0, 0, 0,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
            0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0,
            0, 51, 0, 1, 0, 1, 0, 0, 0, 1, 0,
            1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0,
            0, 0, 0, 1, 0, 0, 51, 51, 51, 1, 0,
            0, 51, 0, 1, 0, 1, 1, 1, 1, 1, 0,
            1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            34, 13, 0, 1, 26, 0, 1, 1, 1, 0, 1,
            35, 37, 0, 1, 0, 0, 0, 1, 0, 51, 0,
            36, 38, 39, 1, 47, 0, 0, 1, 0, 0, 0,
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
    ui->my_status->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->mystatus->setStyleSheet("QLabel {color:orange;font: bold 12px;}");
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
    ui->floor_status->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->floor->setText(QString::number(braver->floor + 1) + QString::fromWCharArray(L"F"));
    ui->system_status->setText(vars->hint_msg);
    ui->item_status->setText(vars->gain_item_msg);
    ui->my_lv->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->my_at->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->my_hp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->my_df->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->my_exp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->mylv->setStyleSheet("QLabel {color:orange;font: bold 12px;}");
    ui->myat->setStyleSheet("QLabel {color:orange;font: bold 12px;}");
    ui->myhp->setStyleSheet("QLabel {color:orange;font: bold 12px;}");
    ui->mydf->setStyleSheet("QLabel {color:orange;font: bold 12px;}");
    ui->myexp->setStyleSheet("QLabel {color:orange;font: bold 12px;}");
    ui->my_ykey->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->my_bkey->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->my_rkey->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->my_gold->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->floor->setStyleSheet("QLabel {color:orange;font: bold 15px;}");

}

void MainWindow::init_image()
{
    img_wall = QImage(":/new/prefix1/Images/Image 88.png");
    img_wall_red = QImage(":/new/prefix1/Images/Image 103.bmp");
    img_wall_blue = QImage(":/new/prefix1/Images/Image 100.png");
    img_wall_grey = QImage(":/new/prefix1/Images/Image 740.png");
    img_wall_hole = QImage(":/new/prefix1/Images/Image 888.bmp");
    img_ice = QImage(":/new/prefix1/Images/Image 760.bmp");
    img_wall_lava[0] = QImage(":/new/prefix1/Images/Image 82.png");
    img_wall_lava[1] = QImage(":/new/prefix1/Images/Image 84.png");
    img_wall_manga[0] = QImage(":/new/prefix1/Images/Image 92.png");
    img_wall_manga[1] = QImage(":/new/prefix1/Images/Image 93.png");
    img_wall_spring[0] = QImage(":/new/prefix1/Images/Image 767.bmp");
    img_wall_spring[1] = QImage(":/new/prefix1/Images/Image 767.png");
    img_wall_starry[0] = QImage(":/new/prefix1/Images/Image 95.png");
    img_wall_starry[1] = QImage(":/new/prefix1/Images/Image 96.png");
    img_wall_magiccircle[0] = QImage(":/new/prefix1/Images/Image 753.bmp");
    img_wall_magiccircle[1] = QImage(":/new/prefix1/Images/Image 755.bmp");
    img_upstair = QImage(":/new/prefix1/Images/Image 76.png");
    img_downstair = QImage(":/new/prefix1/Images/Image 73.png");
    img_ykey = QImage(":/new/prefix1/Images/Image 1.png");
    img_bkey = QImage(":/new/prefix1/Images/Image 4.png");
    img_rkey = QImage(":/new/prefix1/Images/Image 7.png");
    img_bbottle = QImage(":/new/prefix1/Images/Image 22.png");
    img_rbottle = QImage(":/new/prefix1/Images/Image 19.png");
    img_rgem = QImage(":/new/prefix1/Images/Image 10.png");
    img_bgem = QImage(":/new/prefix1/Images/Image 13.png");
    img_ggem = QImage(":/new/prefix1/Images/Image 16.png");
    img_sword = QImage(":/new/prefix1/Images/Image 1520.bmp");
    img_shield = QImage(":/new/prefix1/Images/Image 1547.bmp");
    img_lstore = QImage(":/new/prefix1/Images/Image 559.png");
    img_lstore2 = QImage(":/new/prefix1/Images/Image 553.png");
    img_rstore = QImage(":/new/prefix1/Images/Image 562.png");
    img_rstore2 = QImage(":/new/prefix1/Images/Image 556.png");
    img_gold=QImage(":/new/prefix1/Images/Image 31.png");
    img_mstore[0] = QImage(":/new/prefix1/Images/Image 1541.png");
    img_mstore[1] = QImage(":/new/prefix1/Images/Image 1543.png");
    img_mstore2[0] = QImage(":/new/prefix1/Images/Image 1582.png");
    img_mstore2[1] = QImage(":/new/prefix1/Images/Image 1580.png");
    img_ydoor[0] = QImage(":/new/prefix1/Images/Image 106.png");
    img_bdoor[0] = QImage(":/new/prefix1/Images/Image 115.png");
    img_rdoor[0] = QImage(":/new/prefix1/Images/Image 123.png");
    img_gdoor[0] = QImage(":/new/prefix1/Images/Image 139.png");
    img_idoor[0] = QImage(":/new/prefix1/Images/Image 131.png");
    img_npcold[0] = QImage(":/new/prefix1/Images/Image 1586.png");
    img_npcold[1] = QImage(":/new/prefix1/Images/Image 1588.png");
    img_npcred[0] = QImage(":/new/prefix1/Images/Image 1562.png");
    img_npcred[1] = QImage(":/new/prefix1/Images/Image 1564.png");
    img_thief[0] = QImage(":/new/prefix1/Images/Image 1568.png");
    img_thief[1] = QImage(":/new/prefix1/Images/Image 1570.png");
    img_npcelf[0] = QImage(":/new/prefix1/Images/Image 565.png");
    img_npcelf[1] = QImage(":/new/prefix1/Images/Image 567.png");
    img_braver[0][0] = QImage(":/new/prefix1/Images/Image 1607.png");//1607
    img_braver[1][0] = QImage(":/new/prefix1/Images/Image 3350.png");//3350
    img_braver[2][0] = QImage(":/new/prefix1/Images/Image 4134.png");
    img_braver[3][0] = QImage(":/new/prefix1/Images/Image 4138.png");//4138
    img_braver[0][1] = QImage(":/new/prefix1/Images/Image 4130.png");//4130
    img_braver[1][1] = QImage(":/new/prefix1/Images/Image 3290.png");//3290
    img_braver[2][1] = QImage(":/new/prefix1/Images/Image 4136.png");
    img_braver[3][1] = QImage(":/new/prefix1/Images/Image 3286.png");//3286
    img_braver[0][1] = QImage(":/new/prefix1/Images/Image 4132.png");
    img_braver[1][1] = QImage(":/new/prefix1/Images/Image 3355.png");
    img_braver[2][1] = QImage(":/new/prefix1/Images/Image 3293.png");
    img_braver[3][1] = QImage(":/new/prefix1/Images/Image 3288.png");

    img_monster[0][0] = QImage(":/new/prefix1/Images/Image 463.png");
    img_monster[0][1] = QImage(":/new/prefix1/Images/Image 465.png");
    img_monster[1][0] = QImage(":/new/prefix1/Images/Image 469.png");
    img_monster[1][1] = QImage(":/new/prefix1/Images/Image 471.png");
    img_monster[2][0] = QImage(":/new/prefix1/Images/Image 475.png");
    img_monster[2][1] = QImage(":/new/prefix1/Images/Image 477.png");
    img_monster[3][0] = QImage(":/new/prefix1/Images/Image 481.png");
    img_monster[3][1] = QImage(":/new/prefix1/Images/Image 483.png");
    img_monster[4][0] = QImage(":/new/prefix1/Images/Image 529.png");
    img_monster[4][1] = QImage(":/new/prefix1/Images/Image 531.png");

    img_monster[5][0] = QImage(":/new/prefix1/Images/Image 535.png");
    img_monster[5][1] = QImage(":/new/prefix1/Images/Image 537.png");
    img_monster[6][0] = QImage(":/new/prefix1/Images/Image 541.png");
    img_monster[6][1] = QImage(":/new/prefix1/Images/Image 543.png");
    img_monster[7][0] = QImage(":/new/prefix1/Images/Image 421.png");
    img_monster[7][1] = QImage(":/new/prefix1/Images/Image 423.png");
    img_monster[8][0] = QImage(":/new/prefix1/Images/Image 427.png");
    img_monster[8][1] = QImage(":/new/prefix1/Images/Image 429.png");
    img_monster[9][0] = QImage(":/new/prefix1/Images/Image 710.bmp");
    img_monster[9][1] = QImage(":/new/prefix1/Images/Image 712.bmp");
    img_monster[10][0] = QImage(":/new/prefix1/Images/Image 433.png");
    img_monster[10][1] = QImage(":/new/prefix1/Images/Image 435.png");
    img_monster[11][0] = QImage(":/new/prefix1/Images/Image 337.png");
    img_monster[11][1] = QImage(":/new/prefix1/Images/Image 339.png");
    img_monster[12][0] = QImage(":/new/prefix1/Images/Image 343.png");
    img_monster[12][1] = QImage(":/new/prefix1/Images/Image 345.png");
    img_monster[13][0] = QImage(":/new/prefix1/Images/Image 349.png");
    img_monster[13][1] = QImage(":/new/prefix1/Images/Image 351.png");
    img_monster[14][0] = QImage(":/new/prefix1/Images/Image 387.png");
    img_monster[14][1] = QImage(":/new/prefix1/Images/Image 385.png");
    img_monster[15][0] = QImage(":/new/prefix1/Images/Image 367.png");
    img_monster[15][1] = QImage(":/new/prefix1/Images/Image 369.png");

    img_monster[16][0] = QImage(":/new/prefix1/Images/Image 373.png");
    img_monster[16][1] = QImage(":/new/prefix1/Images/Image 375.png");
    img_monster[17][0] = QImage(":/new/prefix1/Images/Image 325.png");
    img_monster[17][1] = QImage(":/new/prefix1/Images/Image 327.png");
    img_monster[18][0] = QImage(":/new/prefix1/Images/Image 331.png");
    img_monster[18][1] = QImage(":/new/prefix1/Images/Image 333.png");
    img_monster[19][0] = QImage(":/new/prefix1/Images/Image 608.bmp");
    img_monster[19][1] = QImage(":/new/prefix1/Images/Image 610.bmp");

    img_monster[20][0] = QImage(":/new/prefix1/Images/Image 160.png");
    img_monster[20][1] = QImage(":/new/prefix1/Images/Image 162.png");
    img_monster[21][0] = QImage(":/new/prefix1/Images/Image 301.png");
    img_monster[21][1] = QImage(":/new/prefix1/Images/Image 303.png");
    img_monster[22][0] = QImage(":/new/prefix1/Images/Image 307.png");
    img_monster[22][1] = QImage(":/new/prefix1/Images/Image 309.png");
    img_monster[23][0] = QImage(":/new/prefix1/Images/Image 313.png");
    img_monster[23][1] = QImage(":/new/prefix1/Images/Image 315.png");
    img_monster[24][0] = QImage(":/new/prefix1/Images/Image 415.png");
    img_monster[24][1] = QImage(":/new/prefix1/Images/Image 417.png");
    img_monster[25][0] = QImage(":/new/prefix1/Images/Image 596.bmp");
    img_monster[25][1] = QImage(":/new/prefix1/Images/Image 598.bmp");
    img_monster[26][0] = QImage(":/new/prefix1/Images/Image 638.bmp");
    img_monster[26][1] = QImage(":/new/prefix1/Images/Image 640.bmp");
    img_monster[27][0] = QImage(":/new/prefix1/Images/Image 644.bmp");
    img_monster[27][1] = QImage(":/new/prefix1/Images/Image 646.bmp");
    img_monster[28][0] = QImage(":/new/prefix1/Images/Image 319.png");
    img_monster[28][1] = QImage(":/new/prefix1/Images/Image 321.png");
    img_monster[29][0] = QImage(":/new/prefix1/Images/Image 499.png");
    img_monster[29][1] = QImage(":/new/prefix1/Images/Image 501.png");
    img_monster[30][0] = QImage(":/new/prefix1/Images/Image 505.png");
    img_monster[30][1] = QImage(":/new/prefix1/Images/Image 507.png");
    img_monster[31][0] = QImage(":/new/prefix1/Images/Image 517.png");
    img_monster[31][1] = QImage(":/new/prefix1/Images/Image 519.png");
    img_monster[32][0] = QImage(":/new/prefix1/Images/Image 602.bmp");
    img_monster[32][1] = QImage(":/new/prefix1/Images/Image 604.bmp");
    img_monster[33][0] = QImage(":/new/prefix1/Images/Image 686.bmp");
    img_monster[33][1] = QImage(":/new/prefix1/Images/Image 688.bmp");

    img_monster[34][0] = QImage(":/new/prefix1/Images/Image 547.png");
    img_monster[34][1] = QImage(":/new/prefix1/Images/Image 549.png");
    img_monster[35][0] = QImage(":/new/prefix1/Images/Image 379.png");
    img_monster[35][1] = QImage(":/new/prefix1/Images/Image 381.png");
    img_monster[36][0] = QImage(":/new/prefix1/Images/Image 614.bmp");
    img_monster[36][1] = QImage(":/new/prefix1/Images/Image 616.bmp");
    img_monster[37][0] = QImage(":/new/prefix1/Images/Image 465.png");
    img_monster[37][1] = QImage(":/new/prefix1/Images/Image 465.png");
    img_monster[38][0] = QImage(":/new/prefix1/Images/Image 722.bmp");
    img_monster[38][1] = QImage(":/new/prefix1/Images/Image 724.bmp");
    img_monster[39][0] = QImage(":/new/prefix1/Images/Image 439.png");
    img_monster[39][1] = QImage(":/new/prefix1/Images/Image 441.png");
    img_monster[40][0] = QImage(":/new/prefix1/Images/Image 620.bmp");
    img_monster[40][1] = QImage(":/new/prefix1/Images/Image 622.bmp");
    img_monster[41][0] = QImage(":/new/prefix1/Images/Image 403.png");
    img_monster[41][1] = QImage(":/new/prefix1/Images/Image 405.png");

    img_monster[42][0] = QImage(":/new/prefix1/Images/Image 445.png");
    img_monster[42][1] = QImage(":/new/prefix1/Images/Image 447.png");
    img_monster[43][0] = QImage(":/new/prefix1/Images/Image 451.png");
    img_monster[43][1] = QImage(":/new/prefix1/Images/Image 453.png");
    img_monster[44][0] = QImage(":/new/prefix1/Images/Image 457.png");
    img_monster[44][1] = QImage(":/new/prefix1/Images/Image 459.png");
    img_monster[45][0] = QImage(":/new/prefix1/Images/Image 692.bmp");
    img_monster[45][1] = QImage(":/new/prefix1/Images/Image 694.bmp");
    img_monster[46][0] = QImage(":/new/prefix1/Images/Image 355.png");
    img_monster[46][1] = QImage(":/new/prefix1/Images/Image 357.png");
    img_monster[47][0] = QImage(":/new/prefix1/Images/Image 650.bmp");
    img_monster[47][1] = QImage(":/new/prefix1/Images/Image 652.bmp");
    img_monster[48][0] = QImage(":/new/prefix1/Images/Image 361.png");
    img_monster[48][1] = QImage(":/new/prefix1/Images/Image 363.png");
    img_monster[49][0] = QImage(":/new/prefix1/Images/Image 716.bmp");
    img_monster[49][1] = QImage(":/new/prefix1/Images/Image 718.bmp");
    img_monster[50][0] = QImage(":/new/prefix1/Images/Image 728.bmp");
    img_monster[50][1] = QImage(":/new/prefix1/Images/Image 730.bmp");
    img_monster[51][0] = QImage(":/new/prefix1/Images/Image 397.png");
    img_monster[51][1] = QImage(":/new/prefix1/Images/Image 399.png");
    img_monster[52][0] = QImage(":/new/prefix1/Images/Image 409.png");
    img_monster[52][1] = QImage(":/new/prefix1/Images/Image 411.png");
    img_monster[53][0] = QImage(":/new/prefix1/Images/Image 393.png");
    img_monster[53][1] = QImage(":/new/prefix1/Images/Image 391.png");
    img_monster[54][0] = QImage(":/new/prefix1/Images/Image 523.png");
    img_monster[54][1] = QImage(":/new/prefix1/Images/Image 525.png");

    img_monster[55][0] = QImage(":/new/prefix1/Images/Image 465.png");
    img_monster[55][1] = QImage(":/new/prefix1/Images/Image 465.png");
    img_monster[56][0] = QImage(":/new/prefix1/Images/Image 698.bmp");
    img_monster[56][1] = QImage(":/new/prefix1/Images/Image 700.bmp");
    img_monster[57][0] = QImage(":/new/prefix1/Images/Image 465.png");
    img_monster[57][1] = QImage(":/new/prefix1/Images/Image 465.png");
    img_monster[58][0] = QImage(":/new/prefix1/Images/Image 511.png");
    img_monster[58][1] = QImage(":/new/prefix1/Images/Image 513.png");
    img_monster[59][0] = QImage(":/new/prefix1/Images/Image 734.bmp");
    img_monster[59][1] = QImage(":/new/prefix1/Images/Image 736.bmp");
    img_monster[60][0] = QImage(":/new/prefix1/Images/Image 668.bmp");
    img_monster[60][1] = QImage(":/new/prefix1/Images/Image 670.bmp");
    img_monster[61][0] = QImage(":/new/prefix1/Images/Image 664.bmp");
    img_monster[61][1] = QImage(":/new/prefix1/Images/Image 662.bmp");
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
    scene_llayer2->setBackgroundBrush(QPixmap::fromImage(img_llayer));
    ui->floor_graphics->setScene(scene_llayer2);

    QImage img_llayer3 = QImage(":/new/prefix1/Images/Image 79.png");
    QGraphicsScene *scene_llayer3 = new QGraphicsScene;
    scene_llayer3->setBackgroundBrush(QPixmap::fromImage(img_llayer));
    ui->Mystatus_01->setScene(scene_llayer3);

    QImage img_llayer4 = QImage(":/new/prefix1/Images/Image 79.png");
    QGraphicsScene *scene_llayer4 = new QGraphicsScene;
    scene_llayer4->setBackgroundBrush(QPixmap::fromImage(img_llayer));
    ui->Mystatus_03->setScene(scene_llayer4);
    //QObject::connect(scene_llayer, SIGNAL(sceneRectChanged(QRectF)), this, SLOT(sceneRectChanged(QRectF)));

    NormalTimer = new QTimer(this);
    NormalTimer->start(500);
    NormalTime=0;
    int pos_x=0;
    int pos_y=0;
    connect(NormalTimer,&QTimer::timeout,[=]() mutable{
        if(NormalTime < 1 && NormalTime >= 0)
        {
            NormalTime++;
        }
        else
        {
            NormalTime = 0;
        }
        print_floor_1(pos_x ,pos_y, NormalTime);
    });
}

void MainWindow::print_floor_1(int x,int y,int t)
{
    for (y = 0; y <= Y - 1; y++) {
        for (x = 0; x <= X - 1; x++) {
            //需要进行变换的事件序号：5，6，8，9，13，19，20，30，42-47，51+
            if (Tower[braver->floor][y * X + x] == 5) //岩浆
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_wall_manga[t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 6) //寒泉
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_wall_spring[t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 8) //星空
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_wall_starry[t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 9) //熔岩
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_wall_lava[t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 13) //魔法阵
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_wall_magiccircle[t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 19) //oldnpc
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_npcold[t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 20) //oldelf
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_npcelf[t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 30) //星空暗门
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_wall_magiccircle[t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 42) //商店1
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_mstore[t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 44) //商店3
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_mstore[t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 42) //商店1
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_mstore[t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 44) //商店3
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_mstore[t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 43) //商店1
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_mstore2[t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 45) //商店3
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_mstore2[t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 42) //商店1
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_mstore[t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 46) //钥匙商店
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_thief[t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 47) //任意门商店
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_npcold[t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 51) //绿色史莱姆
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[0][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 52) //红色史莱姆
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[1][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 53) //黑色史莱姆
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[2][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 54) //史莱姆王
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[3][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 55) //小蝙蝠
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[4][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 56) //大蝙蝠
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[5][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 57) //红蝙蝠
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[6][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 58) //骷髅
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[7][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 59) //骷髅剑士
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[8][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 60) //骷髅兵
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[9][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 61) //骷髅队长
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[10][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 62) //卫兵
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[11][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 63) //中级卫兵
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[12][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 64) //高级卫兵
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[13][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 65) //石头怪
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[14][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 66) //丧尸
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[15][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 67) //丧尸剑士
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[16][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 68) //双手剑士
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[17][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 69) //剑王
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[18][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 70) //八爪鱼
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[19][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 71) //水术士
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[20][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 72) //雷术士
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[21][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 73) //炎术士
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[22][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 74) //大法师
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[23][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 75) //暗黑魔法师
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[24][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 76) //极地法师
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[25][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 77) //死灵大法师
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[26][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 78) //死灵术士
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[27][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 79) //火炎大法师
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[28][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 80) //魔法师首领
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[29][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 81) //魔法师元帅
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[30][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 82) //魔王
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[31][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 83) //混沌术士
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[32][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 84) //魔神
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[33][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 85) //毒蝙蝠
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[34][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 86) //毒丧尸
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[35][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 87) //毒八爪鱼
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[36][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 88) //毒龙
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[37][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 89) //骷髅战士
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[38][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 90) //骷髅头目
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[39][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 91) //闪光八爪鱼
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[40][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 92) //不死战士
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[41][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 93) //骑士
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[42][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 94) //铁骑士
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[43][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 95) //近卫骑士
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[44][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 96) //剑神
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[45][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 97) //史莱姆人
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[46][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 98) //四手史莱姆人
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[47][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 99) //水银人
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[48][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 100) //重生骷髅兵
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[49][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 101) //烈焰丧尸
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[50][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 102) //不死骷髅兵
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[51][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 103) //死灵战士
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[52][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 104) //铁怪
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[53][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 105) //魔王·格勒第
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[54][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 106) //黄金龙
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[55][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 107) //斗神
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[56][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 108) //魔界八爪鱼
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[57][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 109) //魔王近卫兵
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[58][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 110) //冻死骨
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[59][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 111) //邪眼史莱姆
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[60][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 112) //鬼邪石
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_monster[61][t]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
        }
    }
}

void MainWindow::print_static(int x, int y)
{
    for (y = 0; y <= Y - 1; y++) {
        for (x = 0; x <= X - 1; x++) {
            //需要进行变换的事件序号：5，6，8，9，13，19，20，30，42-47，51+
            if (braver->pos_x == x && braver->pos_y == y){
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_braver[braver->face][1]));
                //pixmap_items[0]->setPixmap(QPixmap::fromImage(img_braver[braver->face][0]));
                pixmap_items[0]->setPos(QPointF(32 * x, 32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 1) //墙
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_wall));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 2) //灰墙
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_wall_grey));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 3) //蓝墙
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_wall_blue));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 4) //红墙
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_wall_red));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 7) //冰块
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_ice));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 11) //下楼
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_downstair));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 12) //密道
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
            else if (Tower[braver->floor][y * X + x] == 15) //经验商店左
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_lstore2));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 16) //金币商店左
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_lstore));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 17) //经验商店右
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_rstore2));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 18) //金币商店右
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_rstore));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 14) //洞
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_wall_hole));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 21) //黄门
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_ydoor[0]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 22) //蓝门
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_bdoor[0]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 23) //红门
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_rdoor[0]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 24) //绿门
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_gdoor[0]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 25) //铁门
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_idoor[0]));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 26) //暗墙-变黄门
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_wall));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 27) //暗墙-变魔法阵
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_wall_grey));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 28) //暗墙-变魔法阵
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_wall_blue));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 29) //暗墙-变魔法阵
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_wall_red));
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
            else if (Tower[braver->floor][y * X + x] == 32) //蓝钥匙
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_bkey));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 33) //红钥匙
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_rkey));
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
        }
    }
}

void MainWindow::print_floor()
{
    int x=0;
    int y=0;
    scene_floor->clear();
    print_floor_1(x , y, NormalTime);
    print_static(x,y);
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

int MainWindow::handle_keypress(int key_no)
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
        Fight *fight = new Fight;
        fight->braver = braver;
        fight->mo = m_array[monster_id];
        fight->tar_pos=target_pos;
        fight->setWindowModality(Qt::ApplicationModal);
        fight->init_text();
        fight->show();
        fight->fight();
        //delete fight;
        connect(fight,&Fight::closeSignal,this,[=](){
              display_data();
              print_floor();
        });
        return 0;
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
                result = 0;
            }
        }
        else if (result == 1) {
            vars->hint_msg="游戏结束！";
            result = 2;
        }
        if (result == 0) { //0为可以操作
            is_braver_survival();
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
            print_floor();
            display_data();
            QTimer * timerykey = new QTimer(this);

            result = 0;
        }
        else if (result == 4) { //4为上下楼转场
            result = 0;
            print_floor();
            display_data();
        }
        else if (result == 5) {
            //5为战斗，后续会加入战斗动画
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
            sstore->setWindowModality(Qt::ApplicationModal);
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

void MainWindow::is_braver_survival()
{
    if(braver->hp<=0)
    {
        result = 2; //后被定义为2
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

