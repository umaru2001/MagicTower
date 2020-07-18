#ifdef WIN32  
#endif
#pragma once
#ifndef VARIABLES_H
#define VARIABLES_H
#include<iostream>
#include<QString>
using namespace std;

#define TOTAL_FLOOR 33 //总层数
#define X 11 //每层的x长度
#define Y 11 //每层的y长度
#define MONSTER_NUM 62 //怪物的数量

#define MOVE_LEFT 0;
#define MOVE_UP 1;
#define MOVE_RIGHT 2;
#define MOVE_DOWN 3;

typedef int FLOOR[X * Y];

class people
{
public:
	//成员变量
	int hp;//生命
	int at;//攻击
	int df;//防御
	int exp;//经验值
	int gold;//金币
    QString name;
    QString img;

	//成员函数
	people(int h, int a, int d, int g, int e, string n, string i);
	people();
	~people();

private:
};

class monster :public people
{
public:
	int id;
	monster(int h, int a, int d, int g, int e, int id, string n, string i);
	monster();
	~monster();

private:
};

class character :public people
{
public:
	//成员变量
	int pos_x;//x坐标
	int pos_y;//y坐标
	int floor;
	int face;//朝向
	int lv;
	int ykey;
	int bkey;
	int rkey;
    int status;//状态
    int dms_door;

    int floor_up;
    int book;

	//成员函数
	character(int h, int a, int d, int g, int e, int x, int y, 
        int floor, int face, int l, int yk, int bk, int rk,int dms,string n, string i);
	~character();

private:

};

class GLOBAL_VARS
{
public:
	int end_no; //结局编号
	//int dialog_no; //对话编号
	int store_no; //商店编号
    QString gain_item_msg; //获得物品时显示内容
    QString hint_msg; //提示内容
	int OperationStatus; //操作状态。0为正常游戏中，1为对话框状态，2为游戏结束状态
	int BuyTimes_0;//商店买的次数
	int BuyTimes_1;
    QString mt_class;
	GLOBAL_VARS();
    GLOBAL_VARS(int end, int op,int b1,int b2);
	~GLOBAL_VARS();
};



extern FLOOR Tower[TOTAL_FLOOR];

#endif //!VARIABLES_H

