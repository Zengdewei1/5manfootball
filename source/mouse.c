/*******************************         MOUSE.C         ********************************/
/*本函数库记载有关鼠标实现及相关操作          
                              作者：田若辰                            */

#include<time.h>
#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>
#include<stdio.h>
#include"mouse.h"
union REGS regs;

 int mx=0,my=0,buttons=0;
 int mouse_sq[16][16]={0};
 int default1=0;
//测试函数
// void main()
// {
//   int driver,mode;
// 	driver=VGA;
// 	mode=VGAHI;
// 	initgraph(&driver,&mode,"C:\\BORLANDC\\BGI");
//   Initmouse(0,639,0,479);
// 	while(1)
//     {
//       Newxy();
//       delay(100);
//     }
//   getch();
//   closegraph(); 
// }
/*画鼠标函数*/
void Cursor(int x,int y)
{
  setcolor(WHITE);
  line(x,y,x,y+15);
  line(x,y+15,x+4,y+10);
  line(x+4,y+10,x+10,y+10);
  line(x+10,y+10,x,y);
  // line(x+1,y+1,x+1,y+13);
  // line(x+2,y+3,x+2,y+11);
  // line(x+3,y+4,x+3,y+9);
  // line(x+4,y+5,x+4,y+9);
  // line(x+5,y+7,x+5,y+10);
  // line(x+6,y+8,x+6,y+10);
  // line(x+7,y+9,x+7,y+11);
  // line(x+8,y+11,x+8,y+11);
  // line(x+9,y+12,x+9,y+12);
}
/*初始化鼠标函数，四个形参确定鼠标可移动范围*/
int Initmouse(int xmi,int xma,int ymi,int yma)
{
  int retcode;
  regs.x.ax=0;
  int86(51,&regs,&regs);
  retcode=regs.x.ax;
  if(retcode==0)
  {
	return 0;
  }
  regs.x.ax=7;
  regs.x.cx=xmi;
  regs.x.dx=xma;
  int86(51,&regs,&regs);
  regs.x.ax=8;
  regs.x.cx=ymi;
  regs.x.dx=yma;
  //regs.x.bx=0;
  int86(51,&regs,&regs);
  default1=0;
  return retcode;
}
/*读取鼠标状态函数*/
int Readmouse()
{
  int xx0=mx,yy0=my,buto=0;
  int xnew,ynew;
//  do
//  {
	regs.x.ax=3;
	int86(51,&regs,&regs);
	xnew=regs.x.cx;
	ynew=regs.x.dx;
	buttons=regs.x.bx;
	delay(10);
//  }
//  while(xnew==xx0&&ynew==yy0&&buttons==buto);
  mx=xnew;
  my=ynew;
return (0);



}
/*更新鼠标位置函数*/
void Newxy()
{
  int xx0=mx,yy0=my,x,y;
  Readmouse();
	if(default1)
  {  
	  Mouse_putbk(xx0,yy0);
  }
	Mouse_savebk(mx,my);
	Cursor(mx,my);
	default1=1;



}
/*存鼠标覆盖背景函数*/
void Mouse_savebk(int x, int y)
{
  int i,j;
  for(i=0;i<=15;i++)
  for(j=0;j<=15;j++)
  mouse_sq[i][j]=getpixel(x+i,y+j);
}

/*恢复覆盖背景函数*/
void Mouse_putbk(int x,int y)
{
  int i,j;
  for(i=0;i<=15;i++)
  for(j=0;j<=15;j++)
  putpixel(x+i,y+j,mouse_sq[i][j]);
}
/*判断鼠标是否在某区域按下*/
int Mouse_press(int x1,int y1,int x2,int y2)
{
  if(mx>=x1&&mx<=x2&&my>=y1&&my<=y2&&buttons)
  return(1);
  else
  return(0);
}
/*判断鼠标是否位于某区域上方*/
int Mouse_above(int x1,int y1,int x2,int y2)
{
  if(mx>=x1&&mx<=x2&&my>=y1&&my<=y2)
  return(1);
  else
  return(0);
}

void NewBK()
{
        default1=0;
}