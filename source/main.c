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
    game();
}