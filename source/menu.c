#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>
#include<time.h>
#include"mouse.h"
#include"hanzi.h"
#include"multikey.h"
#include"menu.h"
#include"tool.h"
#include"game.h"

void menu()
{
	menu_page();
	Initmouse(0,639,0,479);
	InstallKeyboard();
	while(1)
	{
		Newxy();
		if(Mouse_press(320,250,600,310))
		{
			choose_team();
		}
		if (Mouse_press(320,170,600,230))
		{
			changci();
		}
		if(Mouse_press(320,90,600,150))
		{
			jiaoxue();
		}
		if(KeyPress(KEY_ESC))
			exit(0);
	}
}

void menu_page()
{


	setcolor(BLACK);
	setfillstyle(1,GREEN);
	bar(0,0,639,479);
	setfillstyle(1,YELLOW);
	fillellipse(210,40,30,30);
	fillellipse(270,40,30,30);
	fillellipse(330,40,30,30);
	fillellipse(390,40,30,30);
	settextstyle(1,HORIZ_DIR,2);
	setfillstyle(1,BLUE);
	bar(320,90,600,150);
	bar(320,170,600,230);
	bar(320,250,600,310);
	settextstyle(1,HORIZ_DIR,5);
	puthz(355,100,"键盘教学",32,60,BLACK);
	puthz(355,180,"快速游戏",32,60,BLACK);
	puthz(355,260,"创建球队",32,60,BLACK);
	puthz(195,25,"梦想足球",32,60,BLACK);
}



//主客场界面
void changci()
{
	_result result_first,result_init,result_final;
	result_init.score_my=0;
	result_init.score_op=0;
	cleardevice();
	setfillstyle(1,GREEN);
	bar(0,0,639,479);
	setfillstyle(1,RED);
	bar(20,100,220,260);
	puthz(65,155,"主场",48,60,BLACK);

	setcolor(BLACK);
	line(230,100,410,260);
	setfillstyle(1,BLUE);
	bar(420,100,620,260);
	puthz(465,155,"客场",48,60,BLACK);
	puthz(270,300,"球衣",48,60,BLACK);
	puthz(65,300,"红色",48,60,RED);
	puthz(465,300,"蓝色",48,60,BLUE);
	Initmouse(0,639,0,479);
	InstallKeyboard();
	while(1)
	{
		Newxy();
		if(KeyPress(KEY_ESC))
			menu();
		if(Mouse_press(20,100,220,260))
		{
			result_first=game(Left,Right,Red,Blue,result_init);
			while(1)
			{
				if(KeyPress(KEY_ENTER))
					break;
			}
			result_final=game(Right,Left,Red,Blue,result_first);
		}
		if(Mouse_press(420,100,620,260))
		{
			result_first=game(Left,Right,Blue,Red,result_init);
			while(1)
			{
				if(KeyPress(KEY_ENTER))
					break;
			}
			result_final=game(Right,Left,Blue,Red,result_first);
		}
	}
}


//键盘教学界面
void jiaoxue()
{
	 cleardevice();
	 setfillstyle(1,YELLOW);
	 bar(0,0,640,480);
	 setcolor(1);
	 rectangle(250,0,378,32);
	 setfillstyle(1,GREEN);
	 floodfill(251,1,1);
	 puthz(250,0,"教学界面",32,32,YELLOW);
	 puthz(180,50,"球员移动",48,80,GREEN);
	 rectangle(80,117,103,140);
	 settextstyle(1,0,4);
	 outtextxy(80,110,"W");
	 line(103,129,120,129);
	 puthz(120,113,"上",32,80,BLUE);
	 rectangle(198,117,218,142);
	 outtextxy(200,110,"S");
	 line(218,129,235,129);
	 puthz(235,113,"下",32,40,BLUE);
	 rectangle(316,117,336,142);
	 outtextxy(318,110,"A");
	 line(336,129,353,129);
	 puthz(355,113,"左",32,40,BLUE);
	 rectangle(450,117,468,142);
	 outtextxy(450,110,"D");
	 line(468,129,488,129);
	 puthz(490,113,"右",32,40,BLUE);
	 puthz(180,165,"我方控球",48,80,RED);
	 rectangle(80,238,103,262);
	 outtextxy(85,230,"J");
	 line(103,250,123,250);
	 puthz(120,233,"射门",32,40,BLUE);
	 puthz(80,280,"按",32,40,BLUE);
	 rectangle(112,288,132,312);
	 outtextxy(112,280,"K");
	 puthz(132,280,"再按数字",32,32,BLUE);
	 outtextxy(260,278,"(0-4):");
	 puthz(350,280,"传球给指定球员",32,32,BLUE);
	 puthz(180,340,"我方控球",48,80,BROWN);
	 rectangle(80,400,103,424);
	 outtextxy(85,392,"J");
	 line(103,412,123,412);
	 puthz(120,398,"铲球",32,40,BLUE);
	 Initmouse(0,639,0,479);
	 InstallKeyboard();
	while(1)
	{
		Newxy();
		if(KeyPress(KEY_ESC))
			menu();
	}
}

//选择球队界面
void choose_team()
{
                int x=240;
	int y=100;
	cleardevice();
	setfillstyle(1,GREEN);
	 bar(0,0,640,480);


	 setcolor(MAGENTA);
	 x=250;
	 rectangle(x,y,x+128,y+40);
	 rectangle(x-128,y+100,x,y+100+40);
	 rectangle(x+128,y+100,x+128+128,y+100+40);
	 rectangle(x-95,y+100*2,x-95+128,y+100*2+40);
	 rectangle(x+95,y+100*2,x+95+128,y+100*2+40);
	 setfillstyle(1,LIGHTGREEN);
	 floodfill(x+1,y+1,MAGENTA);
	 floodfill(x-128+1,y+100+1,MAGENTA);
	 floodfill(x+128+1,y+100+1,MAGENTA);
	 floodfill(x-95+1,y+100*2+1,MAGENTA);
	 floodfill(x+95+1,y+100*2+1,MAGENTA);
	 circle(314,230,50);
	 setfillstyle(1,LIGHTCYAN);
	 floodfill(314,230,MAGENTA);
	 puthz(x,y,"广州恒大",32,32,BLUE);
	 puthz(x-128,y+100,"上海上港",32,32,BLUE);
	 puthz(x-95,y+100*2,"北京国安",32,32,BLUE);
	 puthz(x+95,y+100*2,"山东鲁能",32,32,BLUE);
	 puthz(x+128,y+100,"上海申花",32,32,BLUE);
	 puthz(282,195,"选择",32,32,BLUE);
	 puthz(282,227,"球队",32,32,BLUE);
	Initmouse(0,639,0,479);
	 InstallKeyboard();
	 NewBK();
	while(1)
	{
		Newxy();
		if(KeyPress(KEY_ESC))
			menu();
		if(Mouse_press(x,y,x+128,y+40))
		  {
	
			choose_player();
		  }
		if(Mouse_press(x-128,y+100,x,y+100+40))
		  {

			choose_player();
		  }
		if(Mouse_press(x+128,y+100,x+128+128,y+100+40))
		  {

			choose_player();
		  }
		if(Mouse_press(x-95,y+100*2,x-95+128,y+100*2+40))
		  {

			choose_player();
		  }
		if(Mouse_press(x+95,y+100*2,x+95+128,y+100*2+40))
		  {

			choose_player();
		  }
	}
}
// void match_info()
// {

// }
//选择球员界面
void choose_player()
{
    int i,j,x,y=100;
	int ID[10];
	_result result_first,result_init,result_final;
	result_init.score_my=0;
	result_init.score_op=0;
	for(i=0;i<10;i++)
		ID[i]=0;
	 cleardevice();
	 setfillstyle(1,GREEN);
	 bar(0,0,640,480);
	 setcolor(WHITE);
	 rectangle(260,0,388,32);
	 setfillstyle(1,YELLOW);
	 floodfill(261,1,WHITE);
	 puthz(260,0,"选择球员",32,32,BLUE);
	 setcolor(WHITE);
	 for(j=0;j<3;j++)
		{
		 x=130;
		 for(i=0;i<4;i++)
			{
			 rectangle(x,y,x+96,y+30);
			 x+=108;
			}
		 y+=100;
		}

	 y=101;
	 for(j=0;j<3;j++)
		{x=131;
		 for(i=0;i<4;i++)
			{
			 floodfill(x,y,WHITE);
			 x+=108;
			}
		 y+=100;
		}
	 rectangle(250,375,400,425);
	 setfillstyle(1,CYAN);
	 floodfill(300,401,WHITE);
	 x=260;
	 puthz(210,40,"左前锋",32,32,BLUE);
	 line(242,72,200,92);
	 line(242,72,284,92);
	 puthz(430,40,"右前锋",32,32,BLUE);
	 line(462,72,420,92);
	 line(462,72,504,92);
	 puthz(210,140,"左后卫",32,32,BLUE);
	 line(242,172,200,192);
				 line(242,172,284,192);

	 puthz(430,140,"右后卫",32,32,BLUE);
	 line(462,172,420,192);
	 line(462,172,504,192);

	 puthz(300,250,"守门员",32,32,BLUE);
	 line(340,282,300,295);
	 line(340,282,380,295);

	 setfillstyle(0,1);
	 floodfill(131,301,WHITE);
	 floodfill(463,301,WHITE);
	 setcolor(GREEN);
	 rectangle(130,300,130+96,300+30);
	 rectangle(130+108*3,300,130+108*3+96,300+30);
	 puthz(260,385,"确认选择",32,32,BLUE);

	 puthz(130,100,"孔卡",32,32,BLUE);
	 puthz(238,100,"金周荣",32,32,BLUE);
	 puthz(346,100,"杨世元",32,32,BLUE);
	 puthz(454,100,"埃弗拉",32,32,BLUE);

	 puthz(130,200,"杨博宇",32,32,BLUE);
	 puthz(238,200,"胡靖航",32,32,BLUE);
	 puthz(346,200,"朱征宇",32,32,BLUE);
	 puthz(454,200,"吴海天",32,32,BLUE);

	 puthz(238,300,"吴航",32,32,BLUE);
	 puthz(346,300,"贾天子",32,32,BLUE);
	 Initmouse(0,639,0,479);
	 InstallKeyboard();
	 NewBK();
	 while(1)
	 {
		 Newxy();
		 if(KeyPress(KEY_ESC))
			choose_team();
		if(Mouse_press(130,100,226,130))
	 	{
		 	ID[0]=1;
		 	ID[1]=0;
	 	}
		else if(Mouse_press(238,100,334,130))
	 	{
		 	ID[1]=1;
		 	ID[0]=0;
	 	}
		if(Mouse_press(346,100,442,130))
	 	{
		 	ID[2]=1;
		 	ID[3]=0;
	 	}
		else if(Mouse_press(454,100,550,130))
	 	{
		 	ID[3]=1;
		 	ID[2]=0;
	 	}
		if(Mouse_press(130,200,226,230))
	 	{
		 	ID[4]=1;
		 	ID[5]=0;
	 	}
	 	else if(Mouse_press(238,200,334,230))
	 	{
			ID[5]=1;
			ID[4]=0;
	 	}
		 if(Mouse_press(346,200,442,230))
	 	{
		 	ID[6]=1;
		 	ID[7]=0;
	 	}
		 else if(Mouse_press(454,200,550,230))
	 	{
		 	ID[7]=1;
		 	ID[6]=0;
	 	}
		if(Mouse_press(238,300,334,330))
	 	{
		 	ID[8]=1;
		 	ID[9]=0;
	 	}
		 else if(Mouse_press(346,300,442,330))
	 	{
		 	ID[9]=1;
		 	ID[8]=0;
	 	}
		if(ID[0]==1)
		{
			setcolor(RED);
			rectangle(130,100,226,130);
		}
		else
		{
			setcolor(WHITE);
			rectangle(130,100,226,130);
		}
		if(ID[1]==1)
		{
			setcolor(RED);
			rectangle(238,100,334,130);
		}
		else
		{
			setcolor(WHITE);
			rectangle(238,100,334,130);
		}
		if(ID[1]==1)
		{
			setcolor(RED);
			rectangle(238,100,334,130);
		}
		else
		{
			setcolor(WHITE);
			rectangle(238,100,334,130);
		}
		if(ID[1]==1)
		{
			setcolor(RED);
			rectangle(238,100,334,130);
		}
		else
		{
			setcolor(WHITE);
			rectangle(238,100,334,130);
		}
		if(ID[1]==1)
		{
			setcolor(RED);
			rectangle(238,100,334,130);
		}
		else
		{
			setcolor(WHITE);
			rectangle(238,100,334,130);
		}
		if(ID[1]==1)
		{
			setcolor(RED);
			rectangle(238,100,334,130);
		}
		else
		{
			setcolor(WHITE);
			rectangle(238,100,334,130);
		}
		if(ID[2])
		 	rectangle(346,100,442,130);
		if(ID[3])
		 	rectangle(454,100,550,130);
		if(ID[4])
		 	rectangle(130,200,226,230);
		if(ID[5])
		 	rectangle(238,200,334,230);
		if(ID[6])
		 	rectangle(346,200,442,230);
		if(ID[7])
		 	rectangle(454,200,550,230);
		if(ID[8])
		 	rectangle(238,300,334,330);
		if(ID[9])
		 	rectangle(346,300,442,330);
		if((ID[0]+ID[1]+ID[2]+ID[3]+ID[4]+ID[5]+ID[6]+ID[7]+ID[8]+ID[9])==5&&Mouse_press(250,375,400,425))//10个中有5个被选择时点击确定，进入游戏
		{
			result_first=game(Left,Right,Red,Blue,result_init);
			while(1)
			{
				if(KeyPress(KEY_ENTER))
					break;
			}
			result_final=game(Right,Left,Red,Blue,result_first);
		}
	 }
}

