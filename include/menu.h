#ifndef _MENU_H_
#define _MENU_H_

int menu();
void result(int historyMatch);
void record(int x,int y,int dx,int row,int length,int slider_dy,int game_amount);
int menu_page();
int history();
int changci(int *matchtype);
int jiaoxue();
int choose_team(char (*s)[10],int path);
int choose_player(char (*s)[10],int path);
void Vs(int path);
int shop(int path_);

#endif