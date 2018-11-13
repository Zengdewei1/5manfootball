#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<ctype.h>
#include<time.h>
#include<MATH.H>
#include"mouse.h"
#include"hanzi.h"
#include"multikey.h"
#include"menu.h"
#include"tool.h"
#include"game.h"
void main()
{
    int driver,mode;
	FILE *fpGame;
	int match=5;
	driver=VGA;
	mode=VGAHI;
	initgraph(&driver,&mode,"C:\\BORLANDC\\BGI");
    setfillstyle(1,GREEN);
    bar(0,0,640,480);
	if(fpGame=fopen("c:\\mycode\\name\\game.txt","r")==NULL)
	{
		printf("cant not open");
		getch();
		exit(1);
	}
	fscanf(fpGame,"%d",&match);
	fclose(fpGame);
	game(Left,Right,Red,Blue,match);
	// xiuxi();
	while(1)
	{
		if(KeyPress(KEY_ENTER))
		{
			break;
		}
	}
	game(Right,Left,Red,Blue,match);
	match++;
	printf("%d",match);
	if(fpGame=fopen("c:\\mycode\\name\\game.txt","w")==NULL)
	{
		printf("cant not open");
		getch();
		exit(1);
	}
	fprintf(fpGame,"%d",match);
	fclose(fpGame);
	// result();
	while(1)
	{
		if(KeyPress(KEY_ENTER))
		{
			menu();
		}
	}
	// menu();
}