#ifdef WIN32  
#endif
#pragma once
#ifndef VARIABLES_H
#define VARIABLES_H
#include<iostream>
#include<QString>
using namespace std;

#define TOTAL_FLOOR 33 //�ܲ���
#define X 11 //ÿ���x����
#define Y 11 //ÿ���y����
#define MONSTER_NUM 62 //���������

#define MOVE_LEFT 0;
#define MOVE_UP 1;
#define MOVE_RIGHT 2;
#define MOVE_DOWN 3;

typedef int FLOOR[X * Y];

class people
{
public:
	//��Ա����
	int hp;//����
	int at;//����
	int df;//����
	int exp;//����ֵ
	int gold;//���
    QString name;
    QString img;

	//��Ա����
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
	//��Ա����
	int pos_x;//x����
	int pos_y;//y����
	int floor;
	int face;//����
	int lv;
	int ykey;
	int bkey;
	int rkey;
    int status;//״̬
    int dms_door;

    int floor_up;
    int book;

	//��Ա����
	character(int h, int a, int d, int g, int e, int x, int y, 
        int floor, int face, int l, int yk, int bk, int rk,int dms,string n, string i);
	~character();

private:

};

class GLOBAL_VARS
{
public:
	int end_no; //��ֱ��
	//int dialog_no; //�Ի����
	int store_no; //�̵���
    QString gain_item_msg; //�����Ʒʱ��ʾ����
    QString hint_msg; //��ʾ����
	int OperationStatus; //����״̬��0Ϊ������Ϸ�У�1Ϊ�Ի���״̬��2Ϊ��Ϸ����״̬
	int BuyTimes_0;//�̵���Ĵ���
	int BuyTimes_1;
    QString mt_class;
	GLOBAL_VARS();
    GLOBAL_VARS(int end, int op,int b1,int b2);
	~GLOBAL_VARS();
};



extern FLOOR Tower[TOTAL_FLOOR];

#endif //!VARIABLES_H

