#ifdef WIN32  
#endif
#pragma once
#ifndef MT_H
#define MT_H
#include<iostream>
#include <set>

void game_init(); //��Ϸ��ʼ
//void game_over(); //��Ϸ����
int calc_damage(int monster_id); //�����˺�
int handle_keypress(int key_no); //��һ�������Ĵ����ж�
//void show_dialog();

#endif // MT_H
