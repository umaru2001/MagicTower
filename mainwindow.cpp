#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "store.h"
#include "mt.h"
#include "fight.h"
#include "dialog.h"
#include "mypushbutton.h"

FLOOR Tower[TOTAL_FLOOR];
int result = 0;
int isIceMagic = 0;
character* braver = new character(90000, 100, 100, 1000, 0, 4, 5, 22, 3, 1, 1, 1, 1, 0, "a", "O");
//hp,at,df,gold,exp,(x,y),floor,face,lv,ykey,bkey,rkey,"name","img";
monster m_array[MONSTER_NUM] =
{   monster(35,19,2,0,1,0, "绿色史莱姆", "51"),
  //hp,at,df,gold,exp,id,"name","img";
    monster(45,23,3,1,1,1, "红色史莱姆","52"),
    monster(70,45,15,6,1,2,"黑色史莱姆","53"),
    monster(400,149,94,18,2,3,"史莱姆王","54"),
    monster(35,30,3,2,1,4,"小蝙蝠","55"),
    monster(70,61,29,8,1,5,"大蝙蝠","56"),
    monster(200,201,119,25,3,6,"红蝙蝠","57"),
    monster(70,80,0,5,1,7,"骷髅","58"),
    monster(320,189,15,17,2,8,"骷髅剑士","59"),
    monster(210,140,102,15,2,9,"骷髅兵","60"),
    monster(500,330,34,30,4,10,"骷髅队长","61"),
    monster(20,50,36,4,1,11,"初级守卫","62"),
    monster(210,120,118,20,3,12,"中级守卫","63"),
    monster(310,724,700,54,6,13,"高级守卫","64"),
    monster(10,70,110,12,2,14,"石头怪","65"),
    monster(110,90,30,8,1,15,"丧尸","66"),
    monster(535,305,180,41,5,16,"丧尸剑士","67"),
    monster(180,123,81,14,2,17,"双手剑士","68"),
    monster(920,1330,660,73,8,18,"剑王","69"),
    monster(300,188,150,22,3,19,"八爪鱼","70"),
    monster(50,18,4,3,1,20,"水术士","71"),
    monster(160,30,37,10,2,21,"雷术士","72"),
    monster(330,90,170,38,4,22,"炎术士","73"),
    monster(496,112,182,43,5,23,"大法师","74"),
    monster(700,120,250,46,5,24,"暗黑魔法师","75"),
    monster(868,155,880,84,8,25,"极地法师","76"),
    monster(850,175,490,63,7,26,"死灵大法师","77"),
    monster(905,200,830,89,9,27,"死灵术士","78"),
    monster(1130,220,540,67,7,28,"火炎大法师","79"),
    monster(610,120,210,44,5,29,"魔法师首领","80"),
    monster(810,155,502,57,6,30,"魔法师元帅","81"),
    monster(1620,210,730,82,9,31,"魔王","82"),
    monster(1330,250,800,92,10,32,"混沌术士","83"),
    monster(3900,310,1104,700,300,33,"魔神·些多","84"),
    monster(402,556,245,51,5,34,"毒蝙蝠","85"),
    monster(660,500,387,48,5,35,"毒丧尸","86"),
    monster(938,530,400,52,5,36,"毒八爪鱼","87"),
    monster(3500,1446,999,800,190,37,"毒龙","88"),
    monster(830,570,390,20,3,38,"骷髅战士","89"),
    monster(999,999,90,55,6,39,"骷髅头目","90"),
    monster(1144,999,826,74,8,40,"闪光八爪鱼","91"),
    monster(1100,1240,800,22,3,41,"不死战士","92"),
    monster(210,113,47,12,2,42,"骑士","93"),
    monster(370,233,130,27,3,43,"铁骑士","94"),
    monster(1002,1000,592,73,8,44,"近卫骑士","95"),
    monster(2000,1600,980,800,190,45,"剑神·沙士","96"),
    monster(176,98,66,12,2,46,"史莱姆人","97"),
    monster(280,234,164,36,4,47,"四手史莱姆人","98"),
    monster(888,661,552,59,6,48,"水银人","99"),
    monster(800,640,320,30,4,49,"重生骷髅兵","100"),
    monster(1097,1024,800,80,8,50,"烈焰丧尸","101"),
    monster(1400,1400,601,33,4,51,"不死骷髅兵","102"),
    monster(1100,1120,900,22,3,52,"死灵战士","103"),
    monster(20,780,800,57,6,53,"铁怪","104"),
    monster(1500,370,190,400,70,54,"魔王·格勒第","105"),
    monster(3000,1530,1530,1800,180,55,"黄金龙","106"),
    monster(4400,1287,1200,800,190,56,"斗神·高巴","107"),
    monster(2020,1080,700,400,100,57,"魔界八爪鱼","108"),
    monster(1220,1010,633,70,8,58,"魔王近卫兵","109"),
    monster(1080,1011,603,72,8,59,"冻死骨","110"),
    monster(932,721,562,61,6,60,"邪眼史莱姆","111"),
    monster(20,1399,999,99,9,61,"鬼邪石","112")
};

void MainWindow::init_tower()
{
    FLOOR tmpfloor_1 = {
            10, 0, 51, 52, 51, 0, 0, 0, 0, 0, 0,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
            35, 37, 58, 21, 0, 1, 34, 31, 36, 1, 31,
            31, 58, 0, 1, 0, 1, 34, 31, 37, 1, 31,
            1, 21, 1, 1, 0, 1, 32, 31, 53, 1, 31,
            36, 62, 62, 1, 0, 21,71 , 51, 55, 1, 0,
            31, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0,
            1, 21, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            62, 62, 62, 1, 26, 0, 1, 1, 1, 21, 1,
            36, 37, 31, 1, 0, 0, 0, 1, 151, 66, 31,
            35, 20, 32, 1, 47, 0, 26, 1, 0, 0, 0,
    };
    memcpy(Tower[1], tmpfloor_1, sizeof(int) * X * Y);
    FLOOR tmpfloor_2 = {
        11, 0, 0, 62, 0, 0, 0, 62, 0, 0, 0,
        0, 1, 1, 22, 1, 1, 1, 22, 1, 1, 0,
        0, 1, 32, 36, 34, 1, 37, 35, 31, 1, 0,
        0, 1, 52, 52, 52, 1, 53, 53, 53, 1, 0,
        0, 1, 1, 21, 1, 1, 1, 21, 1, 1, 0,
        0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 21, 1, 1, 1, 21, 1, 1, 0,
        0, 1, 52, 52, 52, 1, 53, 53, 53, 1, 0,
        0, 1, 32, 36, 34, 1, 37, 35, 31, 1, 0,
        0, 1, 1, 22, 1, 1, 1, 22, 1, 1, 0,
        10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    memcpy(Tower[2], tmpfloor_2, sizeof(int) * X * Y);
    FLOOR tmpfloor_3 = {
        39, 31, 34, 1, 52, 55, 1, 0, 0, 0, 0,
        52, 0, 0, 1, 52, 55, 21, 34, 34, 0, 0,
        52, 1, 1, 1, 1, 1, 0, 0, 0, 1, 52,
        58, 1, 16, 42, 18, 1, 0, 0, 0, 1, 52,
        0, 1, 1, 21, 1, 1, 0, 0, 0, 1, 55,
        51, 1, 71, 58, 0, 21, 31, 31, 31, 1, 55,
        51, 1, 0, 0, 52, 1, 0, 0, 0, 1, 0,
        0, 21, 0, 0, 55, 1, 1, 22, 1, 1, 0,
        1, 1, 1, 1, 55, 1, 62, 38, 62, 1, 0,
        1, 0, 0, 0, 34, 21, 52, 62, 52, 1, 0,
        11, 0, 1, 1, 1, 1, 36, 37, 34, 1, 10,
    };
    memcpy(Tower[3], tmpfloor_3, sizeof(int) * X * Y);
    FLOOR tmpfloor_4 = {
    31, 53, 31, 1, 15, 43, 17, 1, 52, 53, 52,
    21, 1, 21, 1, 1, 21, 1, 1, 21, 1, 21,
    36, 1, 36, 1, 34, 58, 34, 1, 0, 1, 35,
    0, 1, 58, 1, 38, 56, 39, 1, 58, 1, 31,
    51, 1, 58, 1, 1, 21, 1, 1, 31, 1, 55,
    52, 1, 34, 1, 0, 56, 37, 1, 31, 1, 55,
    53, 1, 71, 1, 36, 58, 0, 1, 34, 1, 0,
    55, 1, 0, 1, 1, 32, 1, 1, 34, 1, 0,
    0, 1, 0, 1, 35, 58, 35, 1, 0, 1, 0,
    0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0,
    10, 1, 0, 53, 0, 0, 0, 53, 0, 1, 11,
    };
    memcpy(Tower[4], tmpfloor_4, sizeof(int) * X * Y);
    FLOOR tmpfloor_5 = {
    31, 1, 36, 1, 35, 71, 0, 0, 71, 31, 32,
    31, 1, 34, 1, 71, 0, 0, 0, 0, 71, 31,
    0, 1, 71, 1, 59, 0, 1, 1, 21, 1, 1,
    62, 21, 0, 1, 39, 59, 1, 0, 0, 58, 47,
    55, 1, 0, 1, 1, 1, 1, 0, 0, 31, 58,
    56, 1, 72, 0, 0, 0, 0, 0, 0, 0, 0,
    36, 1, 1, 53, 1, 1, 1, 1, 0, 0, 0,
    37, 46, 1, 53, 1, 0, 0, 0, 62, 66, 0,
    1, 1, 1, 55, 1, 21, 1, 22, 1, 21, 1,
    0, 0, 1, 0, 1, 55, 1, 37, 21, 0, 1,
    11, 0, 55, 0, 0, 0, 1, 31, 1, 10, 1,
    };
    memcpy(Tower[5], tmpfloor_5, sizeof(int) * X * Y);
    FLOOR tmpfloor_6 = {
    0, 0, 1, 37, 1, 31, 53, 156, 1, 35, 35,
    0, 0, 1, 36, 1, 31, 31, 53, 1, 60, 35,
    0, 66, 22, 0, 22, 66, 0, 0, 1, 0, 60,
    161, 0, 1, 66, 1, 0, 0, 0, 1, 59, 0,
    1, 1, 1, 21, 1, 1, 1, 1, 1, 21, 1,
    0, 0, 72, 0, 21, 21, 21, 72, 0, 0, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    0, 1, 56, 21, 56, 0, 0, 0, 0, 0, 1,
    0, 1, 21, 1, 21, 1, 1, 1, 1, 22, 1,
    0, 1, 56, 1, 0, 0, 1, 1, 0, 0, 1,
    0, 0, 0, 1, 10, 0, 21, 21, 35, 11, 1,
    };
    memcpy(Tower[6], tmpfloor_6, sizeof(int) * X * Y);
    FLOOR tmpfloor_7 = {
    10, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 0, 0, 1, 21, 1, 59, 0, 1, 1,
    1, 37, 59, 0, 1, 0, 1, 36, 59, 0, 1,
    0, 59, 1, 1, 1, 0, 1, 1, 1, 0, 0,
    0, 22, 36, 36, 36, 0, 37, 37, 37, 22, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 1, 34, 37, 38, 1, 39, 36, 34, 1, 0,
    0, 1, 32, 34, 37, 1, 36, 34, 32, 1, 0,
    0, 1, 1, 31, 31, 93, 31, 31, 1, 1, 0,
    0, 0, 1, 1, 1, 23, 1, 1, 1, 0, 0,
    1, 36, 35, 21, 11, 0, 0, 21, 35, 37, 1,
    };
    memcpy(Tower[7], tmpfloor_7, sizeof(int) * X * Y);
    FLOOR tmpfloor_8 = {
    11, 1, 0, 0, 0, 0, 1, 0, 31, 59, 0,
    0, 1, 0, 1, 1, 21, 1, 21, 1, 1, 37,
    0, 1, 0, 1, 31, 0, 22, 0, 0, 1, 36,
    0, 1, 0, 1, 72, 1, 1, 1, 0, 1, 53,
    55, 1, 37, 1, 34, 1, 10, 0, 0, 1, 53,
    56, 1, 37, 1, 34, 1, 1, 1, 1, 1, 0,
    72, 1, 53, 1, 0, 0, 0, 1, 38, 57, 0,
    0, 1, 53, 1, 1, 1, 62, 1, 21, 1, 1,
    0, 1, 34, 59, 0, 1, 59, 1, 0, 0, 0,
    0, 1, 1, 1, 21, 1, 0, 1, 1, 1, 0,
    0, 0, 72, 0, 0, 1, 0, 0, 80, 0, 0,
    };
    memcpy(Tower[8], tmpfloor_8, sizeof(int) * X * Y);
    FLOOR tmpfloor_9 = {
    0, 1, 0, 0, 62, 62, 62, 66, 66, 66, 1,
    59, 21, 0, 1, 1, 1, 1, 1, 1, 35, 1,
    59, 1, 31, 1, 52, 52, 52, 51, 1, 72, 1,
    59, 1, 31, 1, 55, 1, 1, 51, 1, 72, 1,
    58, 1, 31, 1, 55, 1, 11, 51, 1, 72, 1,
    58, 1, 32, 1, 55, 1, 1, 1, 1, 71, 1,
    58, 1, 32, 1, 56, 56, 56, 35, 71, 71, 1,
    58, 1, 33, 1, 1, 1, 1, 1, 1, 1, 1,
    53, 1, 36, 36, 36, 37, 37, 37, 0, 0, 0,
    53, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
    };
    memcpy(Tower[9], tmpfloor_9, sizeof(int) * X * Y);
    FLOOR tmpfloor_10 = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
            0, 1, 34, 34, 34, 34, 34, 34, 34, 1, 0,
            0, 1, 36, 36, 36, 161, 37, 37, 37, 1, 0,
            0, 1, 0, 0, 93, 97, 93, 0, 0, 1, 0,
            0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0,
            0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0,
            0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0,
            0, 1, 1, 1, 1, 23, 1, 1, 1, 1, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11,
    };
    memcpy(Tower[10], tmpfloor_10, sizeof(int) * X * Y);
    FLOOR tmpfloor_11 = {
            0, 0, 0, 0, 0, 0, 1, 31, 31, 0, 10,
            0, 0, 0, 0, 0, 0, 1, 34, 34, 1, 0,
            1, 22, 1, 1, 0, 0, 1, 56, 56, 1, 0,
            62, 66, 62, 1, 0, 0, 1, 58, 58, 1, 0,
            35, 37, 35, 1, 0, 0, 1, 55, 55, 1, 0,
            36, 62, 36, 1, 0, 0, 1, 66, 0, 1, 0,
            1, 21, 1, 1, 0, 0, 1, 56, 56, 1, 0,
            36, 62, 37, 1, 0, 0, 1, 68, 0, 1, 0,
            36, 68, 37, 1, 0, 0, 1, 20, 68, 1, 0,
            1, 21, 1, 1, 0, 0, 1, 1, 1, 1, 0,
            11, 0, 0, 56, 0, 0, 21, 0, 0, 0, 0,

    };
    memcpy(Tower[11], tmpfloor_11, sizeof(int) * X * Y);
    FLOOR tmpfloor_12 = {
            10, 62, 0, 64, 20,1, 0, 0, 0, 1, 11,
            62, 0, 0, 0, 64, 1, 0, 1, 35, 1, 0,
            0, 0, 0, 0, 0, 1, 71, 1, 97, 1, 31,
            0, 0, 0, 0, 0, 1, 72, 1, 66, 1, 51,
            0, 35, 0, 35, 0, 1, 37, 1, 34, 1, 52,
            0, 0, 0, 0, 0, 1, 34, 1, 37, 1, 53,
            34, 0, 0, 0, 34, 1, 62, 1, 36, 1, 34,
            0, 34, 0, 34, 0, 1, 93, 1, 59, 1, 54,
            0, 0, 34, 0, 0, 1, 34, 1, 58, 1, 55,
            0, 0, 0, 0, 0, 1, 34, 1, 0, 1, 32,
            0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,

    };
    memcpy(Tower[12], tmpfloor_12, sizeof(int) * X * Y);
    FLOOR tmpfloor_13 = {
            11, 0, 1, 1, 0, 0, 0, 0, 36, 36, 36,
            0, 93, 0, 0, 1, 0, 0, 0, 37, 37, 37,
            1, 1, 0, 36, 1, 0, 0, 0, 34, 34, 34,
            0, 1, 0, 35, 59, 1, 1, 0, 0, 0, 0,
            0, 0, 54, 1, 59, 62, 0, 63, 0, 0, 0,
            0, 0, 0, 0, 1, 62, 37, 1, 0, 0, 0,
            0, 0, 0, 0, 1, 0, 35, 0, 1, 1, 0,
            21, 0, 0, 0, 0, 1, 1, 68, 0, 36, 1,
            161, 23, 0, 0, 0, 0, 0, 1, 0, 35, 1,
            23, 0, 0, 0, 0, 0, 0, 1, 0, 68, 0,
            28, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10,

    };
    memcpy(Tower[13], tmpfloor_13, sizeof(int) * X * Y);
    FLOOR tmpfloor_14 = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0,
            0, 0, 0, 0, 0, 1, 0, 36, 36, 1, 0,
            0, 0, 0, 0, 0, 1, 161, 35, 35, 1, 0,
            0, 0, 0, 0, 0, 1, 0, 37, 37, 1, 59,
            0, 0, 0, 0, 0, 1, 93, 72, 72, 1, 0,
            0, 0, 0, 0, 68, 1, 93, 0, 0, 1, 0,
            1, 21, 1, 1, 0, 1, 0, 0, 65, 1, 0,
            0, 97, 0, 1, 0, 1, 1, 1, 21, 1, 0,
            31, 10, 97, 22, 58, 0, 0, 0, 0, 0, 0,
            31, 31, 0, 1, 0, 0, 0, 0, 0, 0, 11,

    };
    memcpy(Tower[14], tmpfloor_14, sizeof(int) * X * Y);
    FLOOR tmpfloor_15 = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0,
            0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0,
            0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0,
            0, 5, 5, 5, 35, 20, 35,5, 5, 5, 0,
            0, 5, 5, 5, 0, 60, 0, 5, 5, 5, 0,
            0, 5, 5, 5, 5, 60, 5, 5, 5, 5, 0,
            0, 5, 5, 5, 5, 23, 5, 5, 5, 5, 0,
            0, 5, 5, 5, 5, 23, 5, 5, 5, 5, 0,
            0, 11, 0,0, 0, 0, 0, 0, 0, 10, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

    };
    memcpy(Tower[15], tmpfloor_15, sizeof(int) * X * Y);
    FLOOR tmpfloor_16 = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 1,40, 10, 40, 1, 0, 0, 0,
            0, 0, 0, 1,151, 61, 35, 1, 0, 0, 0,
            0, 0, 0, 1, 1, 61, 1, 1, 0, 0, 0,
            0, 0, 0, 0, 1,23, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

    };
    memcpy(Tower[16], tmpfloor_16, sizeof(int) * X * Y);
    FLOOR tmpfloor_17 = {
            0, 0, 0, 0, 1,40, 3, 0, 0, 0, 0,
            0, 1, 1, 1, 1, 23, 3, 3, 3, 3, 0,
            0, 1,57,40, 1, 0, 3, 63, 41, 3,0,
            0, 1,57, 57, 1, 0, 3,94, 63, 3,0,
            0, 1,21, 1, 1, 0, 3, 22, 3, 3, 0,
            10, 0, 0, 0, 0,11, 0, 0, 0, 0,27,
            0, 1, 1,21, 1, 0, 3, 22, 3, 3, 0,
            0, 1,57,57, 1, 0, 3, 94,63, 3, 0,
            0, 1,57,40, 1, 0, 3, 63,41, 3, 0,
            0, 1, 1, 1, 1, 23, 3, 3, 3, 3, 0,
            0, 0, 0, 0, 1,162, 3, 0, 0, 0, 0,

    };
    memcpy(Tower[17], tmpfloor_17, sizeof(int) * X * Y);
    FLOOR tmpfloor_18 = {
            1, 31, 1,31, 1, 31, 1, 31, 1, 31, 1,
            1, 94,1,73, 1, 67, 1, 98,1, 31, 1,
            1, 61,1,63, 1, 74, 1, 94,1, 31, 1,
            1, 57, 1, 70, 1, 73, 1, 61, 1, 74, 1,
            1, 21, 1, 21, 1,21, 1, 21, 1, 21, 1,
            11, 0, 0, 0, 0,0, 0, 0, 0, 0,10,
            1, 21, 1,21, 1, 21, 1, 21, 1, 21, 1,
            1, 57,1,70, 1, 73, 1, 61,1, 74, 1,
            1, 61,1,63, 1, 74, 1, 94,1, 31, 1,
            1, 94, 1, 73, 1, 67, 1, 98, 1, 31, 1,
            1, 31, 1, 31, 1,31, 1, 31, 1, 31, 1,

    };
    memcpy(Tower[18], tmpfloor_18, sizeof(int) * X * Y);
    FLOOR tmpfloor_19 = {
            1, 94, 0,1, 16, 42, 18, 1, 0, 80, 1,
            1, 0,0,1, 1, 21, 1, 1,0, 0, 1,
            1, 37,37,37, 73, 0, 73, 34,34, 34, 1,
            1, 1, 1, 1, 1, 74, 1, 1, 1, 1, 1,
            0, 0, 0, 0, 1,22, 1, 0, 0, 0, 0,
            10, 0, 0, 0, 0,0, 0, 0, 0, 0,11,
            0, 0, 0,0, 1, 22, 1, 0, 0, 0, 0,
            1, 1,1,1, 1, 1, 74, 1,1, 1, 1,
            1, 36,36,36, 73, 0, 73, 35,35, 35, 1,
            1, 0, 0, 1, 1, 21, 1, 1, 0, 0, 1,
            1, 80, 0, 1, 15, 45, 17, 1, 0, 94, 1,

    };
    memcpy(Tower[19], tmpfloor_19, sizeof(int) * X * Y);
    FLOOR tmpfloor_20 = {
            8, 8, 8,8, 74, 8, 8, 8, 8, 8, 40,
            8, 8,8,8, 31, 8, 8, 8,8, 8, 75,
            8, 8,8,8, 73, 8, 8, 8,8, 8, 73,
            8, 8, 8, 8, 73, 8, 8, 8, 8, 8, 73,
            8, 8, 8, 8, 63,8, 8, 8, 8, 8, 63,
            11, 0, 0, 0, 36,0, 0, 0, 36, 63,73,
            8, 8, 8,8, 63, 8, 8, 8, 8, 8, 74,
            8, 8,8,8, 73, 8, 8, 8,8, 8, 74,
            8, 8,8,8, 74, 8, 8, 8,8, 8, 31,
            8, 8, 8, 8, 74, 8, 8, 8, 8, 8, 0,
            8, 8, 8, 8, 31, 0, 0, 0, 0, 0, 10,

    };
    memcpy(Tower[20], tmpfloor_20, sizeof(int) * X * Y);
    FLOOR tmpfloor_21 = {
            61, 57, 73,0, 0, 0, 0, 0, 0, 0, 61,
            35, 8,8,8, 8, 8, 8, 8,8, 8, 36,
            36, 8,8,8, 8, 8, 8, 8,8, 8, 57,
            37, 8, 8, 8, 8, 8, 8, 8, 8, 8, 73,
            0, 8, 8, 8, 8,8, 8, 8, 8, 8, 0,
            0, 0, 75, 41, 75,10, 0, 73, 57, 36,61,
            36, 8, 8,8, 8, 8, 8, 8, 8, 8, 8,
            35, 8,8,8, 8, 8, 8, 8,8, 8, 8,
            73, 8,8,8, 8, 8, 8, 8,8, 8, 8,
            57, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
            61, 37, 0, 0, 94, 0, 0, 57, 57, 0, 11,

    };
    memcpy(Tower[21], tmpfloor_21, sizeof(int) * X * Y);
    FLOOR tmpfloor_22 = {
        8, 8, 8,8, 8, 8, 8, 8, 8, 8, 8,
        8, 8,8,8, 8, 10, 8, 8,8, 8, 8,
        8, 8,8,8, 40, 151, 41, 8,8, 8, 8,
        8, 8, 8, 8, 80, 105, 80, 8, 8, 8, 8,
        8, 8, 8, 8, 8,23, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8,11, 8, 8, 8, 8,8,
        8, 8, 8,8, 8, 8, 8, 8, 8, 8, 8,
        8, 8,8,8, 8, 8, 8, 8,8, 8, 8,
        8, 8,8,8, 8, 8, 8, 8,8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,

    };
    memcpy(Tower[22], tmpfloor_22, sizeof(int) * X * Y);
    FLOOR mi1 = {
            0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0,
            0, 51,55,56,53,34,62,66,71,58, 0,
            0, 51,55,56,53,34,62,66,71,58,0,
            0, 51,55,56,53,34,62,66,71,58,0,
            0, 51,55,56,53,34,62,66,71,58, 0,
            0, 51,55,56,53,34,62,66,71,58,0,
            0, 51,55,56,53,34,62,66,71,58, 0,
            0, 51,55,56,53,34,62,66,71,58, 0,
            161, 51,55,56,53,34,62,66,71,58, 0,
            161, 51,55,56,53,34,62,66,71,58, 0,
            12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//13层密室

    };
    memcpy(Tower[31], mi1, sizeof(int) * X * Y);
    FLOOR mi2 = {
            0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0,
            0, 51,55,56,53,34,62,66,71,58, 0,
            0, 51,55,56,53,34,62,66,71,58,0,
            0, 51,55,56,53,34,62,66,71,58,0,
            0, 51,55,56,53,34,62,66,71,58, 0,
            0, 51,55,56,53,34,62,66,71,58,12,
            0, 51,55,56,53,34,62,66,71,58, 0,
            0, 51,55,56,53,34,62,66,71,58, 0,
            0, 51,55,56,53,34,62,66,71,58, 0,
            0, 51,55,56,53,34,62,66,71,58, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//17层密室

    };
    memcpy(Tower[32], mi2, sizeof(int) * X * Y);

    chamber=new int[31];
    chamber[13]=31;
    chamber[17]=32;
}

GLOBAL_VARS *vars = new GLOBAL_VARS(0, 0, 0, 0);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene_floor = new QGraphicsScene;
    pixmap_items = new QGraphicsPixmapItem * [X * Y];
    setWindowTitle("魔塔");
    this->setWindowIcon(QPixmap(":/Titles/icon.png"));
    MyPushButton* backBtn = new MyPushButton(":/Titles/back.png");
    backBtn->setParent(this);
    backBtn->move(0, 0);
    connect(backBtn, &QPushButton::clicked, [=]()
        {
            backBtn->zoom1();
            backBtn->zoom2();
            QTimer::singleShot(500, this, [=]()
                {
                    this->hide();
                    emit this->back();
                });
        });
}

void MainWindow::init_audio()
{
    door_open =new QSound("D:/C++/magicTower/Music/Sound_tx/door_open.wav");
    gain = new QSound("D:/C++/magicTower/Music/Sound_tx/gain.wav");
    go = new QSound("D:/C++/magicTower/Music/Sound_tx/go.wav");
    hole = new QSound("D:/C++/magicTower/Music/Sound_tx/hole.wav");
    lava =new QSound("D:/C++/magicTower/Music/Sound_tx/lava.wav");
    lava_min =new QSound("D:/C++/magicTower/Music/Sound_tx/lava_min.wav");
    trans =new QSound("D:/C++/magicTower/Music/Sound_tx/trans.wav");
    up_and_down=new QSound("D:/C++/magicTower/Music/Sound_tx/up_and_down.wav");

    door_open->setLoops(1);
    gain->setLoops(1);
    go->setLoops(1);
    hole->setLoops(1);
    lava->setLoops(1);
    lava_min->setLoops(1);
    trans->setLoops(1);
    up_and_down->setLoops(1);
    door_open->setLoops(1);
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
    ui->floor->setText(QString::number(braver->floor) + QString::fromWCharArray(L"F"));
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
    img_sword = QImage(":/Graphics/Titles/Image 1040.png");
    img_shield = QImage(":/Graphics/Titles/Image 1058.png");
    img_sword2 = QImage(":/Graphics/Titles/Image 1043.png");
    img_shield2 = QImage(":/Graphics/Titles/Image 1061.png");
    img_lstore = QImage(":/new/prefix1/Images/Image 559.png");
    img_lstore2 = QImage(":/new/prefix1/Images/Image 553.png");
    img_rstore = QImage(":/new/prefix1/Images/Image 562.png");
    img_rstore2 = QImage(":/new/prefix1/Images/Image 556.png");
    img_gold=QImage(":/new/prefix1/Images/Image 31.png");
    img_mstore[0] = QImage(":/new/prefix1/Images/Image 1541.png");
    img_mstore[1] = QImage(":/new/prefix1/Images/Image 1543.png");
    img_mstore2[0] = QImage(":/new/prefix1/Images/Image 1582.png");
    img_mstore2[1] = QImage(":/new/prefix1/Images/Image 1580.png");
    img_uplv= QImage(":/new/prefix1/Images/Image 52.png");
    img_magickey= QImage(":/new/prefix1/Images/Image 34.png");
    img_magicwater= QImage(":/new/prefix1/Images/Image 55.png");
    img_icemagic= QImage(":/new/prefix1/Images/Image 43.png");

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

    for(int l = 0; l <= 4 ; l++)
    {
        img_ydoor[l] = QImage(":/Images/men001.png").copy(0,32*l,32,32);
        img_bdoor[l] = QImage(":/Images/men001.png").copy(32,32*l,32,32);
        img_rdoor[l] = QImage(":/Images/men001.png").copy(64,32*l,32,32);
        img_gdoor[l] = QImage(":/Images/men001.png").copy(96,32*l,32,32);
        img_idoor[l] = QImage(":/Images/men003.png").copy(96,32*l,32,32);
    }
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

    Opendoor=new QTimer(this);
    Opendoortime=0;
    connect(Opendoor,&QTimer::timeout,[=]()mutable{
        if(Opendoortime<=3 && Opendoortime>=0)
        {
            Opendoortime++;
            print_floor();
        }
        else
        {
            Opendoor->stop();
            OpenDoorTempData = -1;
            OpenDoorTargetPos = -1;
            Opendoortime=0;
        }
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
            else if (Tower[braver->floor][y * X + x] == 12) //魔法阵
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
            if (braver->pos_x == x && braver->pos_y == y){
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_braver[braver->face][1]));
                //pixmap_items[0]->setPixmap(QPixmap::fromImage(img_braver[braver->face][0]));
                pixmap_items[0]->setPos(QPointF(32 * x, 32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 0 && y * X + x == OpenDoorTargetPos)
            {
                if (OpenDoorTempData == 21) //正在被打开的黄门
                {
                    pixmap_items[Opendoortime] = new QGraphicsPixmapItem;
                    pixmap_items[Opendoortime]->setPixmap(QPixmap::fromImage(img_ydoor[Opendoortime]));
                    pixmap_items[Opendoortime]->setPos(QPointF(32 * x,32 * y));
                    scene_floor->addItem(pixmap_items[Opendoortime]);
                }
                if (OpenDoorTempData == 22) //正在被打开的蓝门
                {
                    pixmap_items[Opendoortime] = new QGraphicsPixmapItem;
                    pixmap_items[Opendoortime]->setPixmap(QPixmap::fromImage(img_bdoor[Opendoortime]));
                    pixmap_items[Opendoortime]->setPos(QPointF(32 * x,32 * y));
                    scene_floor->addItem(pixmap_items[Opendoortime]);
                }
                if (OpenDoorTempData == 23) //正在被打开的红门
                {
                    pixmap_items[Opendoortime] = new QGraphicsPixmapItem;
                    pixmap_items[Opendoortime]->setPixmap(QPixmap::fromImage(img_rdoor[Opendoortime]));
                    pixmap_items[Opendoortime]->setPos(QPointF(32 * x,32 * y));
                    scene_floor->addItem(pixmap_items[Opendoortime]);
                }
                if (OpenDoorTempData == 24) //正在被打开的绿门
                {
                    pixmap_items[Opendoortime] = new QGraphicsPixmapItem;
                    pixmap_items[Opendoortime]->setPixmap(QPixmap::fromImage(img_gdoor[Opendoortime]));
                    pixmap_items[Opendoortime]->setPos(QPointF(32 * x,32 * y));
                    scene_floor->addItem(pixmap_items[Opendoortime]);
                }
                if (OpenDoorTempData == 25) //正在被打开的铁门
                {
                    pixmap_items[Opendoortime] = new QGraphicsPixmapItem;
                    pixmap_items[Opendoortime]->setPixmap(QPixmap::fromImage(img_idoor[Opendoortime]));
                    pixmap_items[Opendoortime]->setPos(QPointF(32 * x,32 * y));
                    scene_floor->addItem(pixmap_items[Opendoortime]);
                }
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
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_wall));
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
            else if (Tower[braver->floor][y * X + x] == 40) //银剑
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_sword2));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 41) //银盾
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_shield2));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 161) //魔法钥匙
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_magickey));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 151) //升级器
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_uplv));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 162) //圣水
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_magicwater));
                pixmap_items[0]->setPos(QPointF(32 * x,32 * y));
                scene_floor->addItem(pixmap_items[0]);
            }
            else if (Tower[braver->floor][y * X + x] == 159) //冰霜魔法
            {
                pixmap_items[0] = new QGraphicsPixmapItem;
                pixmap_items[0]->setPixmap(QPixmap::fromImage(img_icemagic));
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
    // 返回操作状态。0为可以操作，1为穿越，2为game_over, 3为开门, 4为上下楼, 5为战斗, 6为提示获得物品信息, 7为开启商店处理,8为穿越
    target_pos = 0;
    old_data = -1;
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
    else if ((Tower[braver->floor][target_pos] >= 1 && Tower[braver->floor][target_pos] <= 8)
             || (Tower[braver->floor][target_pos] >= 15 && Tower[braver->floor][target_pos] <= 18)
             || (Tower[braver->floor][target_pos] >= 26 && Tower[braver->floor][target_pos] <= 30))
    {
        //撞墙 位置不变化
        return 0;
    }
    else if (Tower[braver->floor][target_pos] == 9) {
        if(isIceMagic==0)
        {
            braver->hp-=50;
            lava->play();
        }
        else if(isIceMagic==1)
        {
            braver->hp-=10;
            lava_min->play();
            Tower[braver->floor][target_pos] = 0;
        }
        braver->pos_x = target_pos % X;
        braver->pos_y = target_pos / X;
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
        //魔法阵出口
            braver->floor = FloorTempData;
            int target_pos_lower = 0;
            for (int _it = 0; _it <= X * Y - 1; _it++) {
                if (Tower[braver->floor][_it] == 13) {
                    target_pos_lower = _it;
                    break;
                }
            }
            braver->pos_x = target_pos_lower % X;
            braver->pos_y = target_pos_lower / X;
            FloorTempData = -1;
        return 8;
    }
    else if (Tower[braver->floor][target_pos] == 13) {
        //魔法阵入口
        FloorTempData = braver->floor;
            braver->floor = chamber[FloorTempData];
            int target_pos_lower = 0;
            for (int _it = 0; _it <= X * Y - 1; _it++) {
                if (Tower[braver->floor][_it] == 12) {
                    target_pos_lower = _it;
                    break;
                }
            }
            braver->pos_x = target_pos_lower % X;
            braver->pos_y = target_pos_lower / X;
        return 8;
    }
    else if (Tower[braver->floor][target_pos] == 14) {
        //掉进洞里
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
        return 9;
    }
    else if (Tower[braver->floor][target_pos] == 19||Tower[braver->floor][target_pos] == 20) {
        //对话npc
        dialog *dia=new dialog(this);
        dia->show();
        delete dia;
        return 0;
    }
    else if (Tower[braver->floor][target_pos] == 21) {
        //黄门
        if (braver->ykey >= 1) {
            braver->ykey -= 1;
            return 3;
        }        
        else {
            return 0;
        }
    }
    else if (Tower[braver->floor][target_pos] == 22) {
        //蓝门
        if (braver->bkey >= 1) {
            braver->bkey -= 1;
            return 3;
        }        
        else {
            return 0;
        }
    }
    else if (Tower[braver->floor][target_pos] == 23) {
        //红门
        if (braver->rkey >= 1) {
            braver->rkey -= 1;
            return 3;
        }
        else {
            return 0;
        }
    }
    else if (Tower[braver->floor][target_pos] == 24) {
        //绿门
        //is_greendoor_open();
        return 3;
    }
    else if (Tower[braver->floor][target_pos] == 25) {
        //铁门
        return 3;
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
        braver->hp += 150;
        vars->gain_item_msg = "获得了小血瓶 生命值增加150";
        return 6;
    }
    else if (Tower[braver->floor][target_pos] == 35) {
        //大血瓶 序号：35
        Tower[braver->floor][target_pos] = 0;
        braver->hp += 400;
        vars->gain_item_msg = "获得了大血瓶 生命值增加400";
        return 6;
    }
    else if (Tower[braver->floor][target_pos] == 36) {
        //红宝石 序号：36
        Tower[braver->floor][target_pos] = 0;
        braver->at += 3;
        vars->gain_item_msg = "获得了红宝石 攻击力增加3点";
        return 6;
    }
    else if (Tower[braver->floor][target_pos] == 37) {
        //蓝宝石 序号：37
        Tower[braver->floor][target_pos] = 0;
        braver->df += 3;
        vars->gain_item_msg = "获得了蓝宝石 防御力增加3点";
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
        braver->df += 13;
        vars->gain_item_msg = "获得了铁盾 防御力增加13点";
        return 6;
    }
    else if (Tower[braver->floor][target_pos] == 40) {
        //银剑
        Tower[braver->floor][target_pos] = 0;
        braver->at += 16;
        vars->gain_item_msg = "获得了银剑 攻击力增加16点";
        return 6;
    }
    else if (Tower[braver->floor][target_pos] == 41) {
        //银盾
        Tower[braver->floor][target_pos] = 0;
        braver->df += 22;
        vars->gain_item_msg = "获得了银盾 攻击力增加22点";
        return 6;
    }
    else if (Tower[braver->floor][target_pos] == 151) {
        Tower[braver->floor][target_pos] = 0;
        braver->lv += 1;
        braver->hp += 300;
        braver->df += 3;
        braver->at += 3;
        vars->gain_item_msg = "获得了升级器 等级增加1级";
        return 6;
    }
    else if (Tower[braver->floor][target_pos] == 161) {
        Tower[braver->floor][target_pos] = 0;
        braver->ykey += 1;
        braver->bkey += 1;
        braver->rkey += 1;
        vars->gain_item_msg = "获得了魔法钥匙 各钥匙数量加1";
        return 6;
    }
    else if (Tower[braver->floor][target_pos] == 162) {
        Tower[braver->floor][target_pos] = 0;
        braver->hp = braver->hp*2;
        vars->gain_item_msg = "获得了圣水 体力翻倍";
        return 6;
    }
    else if (Tower[braver->floor][target_pos] == 159) {
        Tower[braver->floor][target_pos] = 0;
        isIceMagic = 1;
        vars->gain_item_msg = "获得了冰霜魔法 碰到熔岩时体力损失减小 并能移除熔岩";
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
    else if (Tower[braver->floor][target_pos] >= 51&&Tower[braver->floor][target_pos] <= 120) {
        //怪物
        int monster_id = Tower[braver->floor][target_pos] - 51;
        Fight *fight = new Fight;
        fight->braver = braver;
        fight->mo = m_array[monster_id];
        fight->tar_pos=target_pos;
        fight->setWindowModality(Qt::ApplicationModal);
        fight->init_text();
        fight->show();
        fight->is_fight_times();
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
                result = handle_keypress(1);
                go->play();
            }
            if(event->key() == Qt::Key_Down){ //向下
                result = handle_keypress(3);
                go->play();
            }
            if(event->key() == Qt::Key_Left){ //向左
                result = handle_keypress(0);
                go->play();
            }
            if(event->key() == Qt::Key_Right){ //向右
                result = handle_keypress(2);
                go->play();
            }
            if(event->key()==Qt::Key_T){
                dmsdoor *wdmsdoor= new dmsdoor;
                wdmsdoor->braver = braver;
                wdmsdoor->vars = vars;
                wdmsdoor->pos = target_pos;
                wdmsdoor->olddata = old_data;
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
            display_data();
            door_open->play();
            Opendoor->start(30);
            OpenDoorTargetPos=target_pos;
            OpenDoorTempData=old_data;
            Tower[braver->floor][target_pos] = 0;
            print_floor();
            result = 0;
        }
        else if (result == 4) { //4为上下楼转场
            up_and_down->play();
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
            gain->play();
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
        else if (result == 8) { //8为魔法阵
            trans->play();
            result = 0;
            print_floor();
            display_data();
        }
        else if (result == 9) { //8为掉落
            hole->play();
            result = 0;
            print_floor();
            display_data();
        }
}

void MainWindow::game_start()
{
    init_audio();
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

