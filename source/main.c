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
	_result result_first,result_init,result_final;
	result_init.score_my=0;
	result_init.score_op=0;
	driver=VGA;
	mode=VGAHI;
	initgraph(&driver,&mode,"C:\\BORLANDC\\BGI");
    setfillstyle(1,GREEN);
    bar(0,0,640,480);
	// while(1)
	// {
	// 	reback(0,0,640,480);
	// }
    result_first=game(Left,Right,Red,Blue,result_init);
	while(1)
	{
		if(KeyPress(KEY_ENTER))
			break;
	}
	result_final=game(Right,Left,Red,Blue,result_first);
	// menu();
}