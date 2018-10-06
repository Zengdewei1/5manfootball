#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>
#include"mouse.h"
#include"hanzi.h"
#include"multikey.h"
#include"menu.h"
#include"tool.h"
#include"game.h"
void main()
{
    int driver,mode;
	driver=VGA;
	mode=VGAHI;
	initgraph(&driver,&mode,"C:\\BORLANDC\\BGI");
    setfillstyle(1,GREEN);
    bar(0,0,640,480);
	// while(1)
	// {
	// 	reback(0,0,640,480);
	// }
    game(Left,Right,Red,Blue);
	// menu();
}