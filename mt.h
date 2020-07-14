#ifdef WIN32  
#endif
#pragma once
#ifndef MT_H
#define MT_H
#include<iostream>
#include <set>

void game_init(); //游戏开始
//void game_over(); //游戏结束
int calc_damage(int monster_id); //计算伤害
int handle_keypress(int key_no); //对一个按键的处理判断
//void show_dialog();

#endif // MT_H
