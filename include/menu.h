#ifndef _MENU_H_
#define _MENU_H_

int menu();
int result(int historyMatch);
void record(int x,int y,int dx,int row,int length,int slider_dy,int game_amount);
void menu_page();
int history(int *resultID);
int changci(int *matchtype);
int jiaoxue();
int choose_team(char (*s)[10],int *path);
int choose_player(char (*s)[10],int path);
void Vs(int path);
int shop(int path_);

#endif