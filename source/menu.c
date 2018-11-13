#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>
#include<time.h>
#include<STDIO.H>
#include"mouse.h"
#include"hanzi.h"
#include"multikey.h"
#include"menu.h"
#include"tool.h"
#include"game.h"

void menu()
{
	setlinestyle(0,0,1);
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
	bar(50,150,200,250);
	settextstyle(1,HORIZ_DIR,5);

	puthz(75,175,"商城",48,48,BLACK);
	puthz(355,100,"键盘教学",32,60,BLACK);
	puthz(355,180,"快速游戏",32,60,BLACK);
	puthz(355,260,"创建球队",32,60,BLACK);
	puthz(195,25,"梦想足球",32,60,BLACK);
}



//主客场界面
void changci()
{
	cleardevice();
	setlinestyle(0,0,1);
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
			// game(Left,Right,Red,Blue);
			xiuxi();
			while(1)
			{
				if(KeyPress(KEY_ENTER))
				{
					break;
				}
			}
			// game(Right,Left,Red,Blue);
			result(1);
			while(1)
			{
				if(KeyPress(KEY_ENTER))
				{
					menu();
				}
			}
		}
		if(Mouse_press(420,100,620,260))
		{
			// game(Left,Right,Blue,Red);
			xiuxi();
			while(1)
			{
				if(KeyPress(KEY_ENTER))
				{
					break;
				}
			}
			// game(Right,Left,Blue,Red);
			result(1);
			while(1)
			{
				if(KeyPress(KEY_ENTER))
				{
					menu();
				}
			}
		}
	}
}


//键盘教学界面
void jiaoxue()
{
	 cleardevice();
	 setlinestyle(0,0,1);
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
                int path;
	int x=240;
	 int i=0;
	 int j=0;
                 char number;
	 char s[10][10];
	 char ch='\0';
	 FILE *fp;
	int y=100;
	cleardevice();
	setfillstyle(1,GREEN);
	bar(1,1,640,480);


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

	while(1)
	{
		Newxy();
		if(KeyPress(KEY_ESC))
		{
			NewBK();
			menu();
		}

		if(Mouse_press(x,y,x+128,y+40))
		  {
			NewBK();
			if((fp=fopen("c:\\mycode\\shop\\1.txt","r"))==NULL)
			  {
				settextstyle(1,0,3);
				outtextxy(200,200,"cannot open the file");
				exit(1);
			  }
                                           for(i=0;i<10;i++)
			{
                                                     fseek(fp,13+37*i,0);
                                                     number=fgetc(fp);
                                                     for(j=0;j<10;j++)
                                                          {
                                                                ch=fgetc(fp);
                                                                 s[i][j]=ch;  
                                                           }
                                                     s[i][2*(number-48)]='\0';
                                                 }
                                           
		            fclose(fp);
                                            path=1;
		            choose_player(s,path);
		  }

		if(Mouse_press(x-128,y+100,x,y+100+40))
		  {
			NewBK();
			if((fp=fopen("c:\\mycode\\shop\\2.txt","r"))==NULL)
			  {
				settextstyle(1,0,3);
				outtextxy(200,200,"cannot open the file");
				exit(1);
			  }
	                            for(i=0;i<10;i++)
			{
                                                     fseek(fp,13+37*i,0);
                                                     number=fgetc(fp);
                                                     for(j=0;j<10;j++)
                                                          {
                                                                ch=fgetc(fp);
                                                                 s[i][j]=ch;  
                                                           }
                                                     s[i][2*(number-48)]='\0';
                                                 }
                                             
			 fclose(fp);
                                                  path=2;
			 choose_player(s,path);
		  }

		if(Mouse_press(x+128,y+100,x+128+128,y+100+40))
		  {
			NewBK();
			if((fp=fopen("c:\\mycode\\shop\\5.txt","r"))==NULL)
			  {
				settextstyle(1,0,3);
				outtextxy(200,200,"cannot open the file");
				exit(1);
			  }
	                           for(i=0;i<10;i++)
			{
                                                     fseek(fp,13+37*i,0);
                                                     number=fgetc(fp);
                                                     for(j=0;j<10;j++)
                                                          {
                                                                ch=fgetc(fp);
                                                                 s[i][j]=ch;  
                                                           }
                                                     s[i][2*(number-48)]='\0';
                                                 }
                                             
			 fclose(fp);
                                                 path=5;
			 choose_player(s,path);
		  }

		if(Mouse_press(x-95,y+100*2,x-95+128,y+100*2+40))
		  {
			NewBK();
			if((fp=fopen("c:\\mycode\\shop\\3.txt","r"))==NULL)
			  {
				settextstyle(1,0,3);
				outtextxy(200,200,"cannot open the file");
				exit(1);
			  }
		           for(i=0;i<10;i++)
			{
                                                     fseek(fp,13+37*i,0);
                                                     number=fgetc(fp);
                                                     for(j=0;j<10;j++)
                                                          {
                                                                ch=fgetc(fp);
                                                                 s[i][j]=ch;  
                                                           }
                                                     s[i][2*(number-48)]='\0';
                                                 }
                                             
				 fclose(fp);
                                                                 path=3;
				 choose_player(s,path);
		  }

		if(Mouse_press(x+95,y+100*2,x+95+128,y+100*2+40))
		  {
			NewBK();
			if((fp=fopen("c:\\mycode\\shop\\4.txt","r"))==NULL)
			  {
				settextstyle(1,0,3);
				outtextxy(200,200,"cannot open the file");
				exit(1);
			  }
	                           for(i=0;i<10;i++)
			{
                                                     fseek(fp,13+37*i,0);
                                                     number=fgetc(fp);
                                                     for(j=0;j<10;j++)
                                                          {
                                                                ch=fgetc(fp);
                                                                 s[i][j]=ch;  
                                                           }
                                                     s[i][2*(number-48)]='\0';
                                                 }
                                             
				 fclose(fp);
                                                                 path=4;
				 choose_player(s,path);
		  }
	}
}



void choose_player(int team)
{
	 int i=0,j=0,x,y=100;
	 int *ID;
	 char **name;
	 char ch='\0';
	 FILE *fp;
	 name=(char**)malloc(sizeof(char*)*10);
	 for(i=0;i<10;i++)
	 {
		name[i]=(char*)malloc(sizeof(int)*10);
	 }
	 switch(team)
	 {
		case(1):fp=fopen("c:\\mycode\\name\\1.txt","r");
		 		break;
		case(2):fp=fopen("c:\\mycode\\name\\2.txt","r");
		 		break;
		case(3):fp=fopen("c:\\mycode\\name\\3.txt","r");
		 		break;
		case(4):fp=fopen("c:\\mycode\\name\\4.txt","r");
		 		break;
		case(5):fp=fopen("c:\\mycode\\name\\5.txt","r");
		 		break;
	 }
	 i=0;
	 if(fp==NULL)
			  {
				settextstyle(1,0,3);
				outtextxy(200,200,"cannot open the file");
				exit(1);
			  }
			while(!feof(fp))
				 {
					if((ch=fgetc(fp))!='\n')
					  {
						name[i][j]=ch;
						j++;
					  }
					if(ch=='\n')
					  {
						name[i][j]='\0';
						i++;
						j=0;
					  }

				 }
				 name[i][j-1]='\0';
				 fclose(fp);
	ID=(int*)malloc(sizeof(int)*10);
	if(ID==NULL)
	{
		exit(0);
	}
	 cleardevice();
	 InstallKeyboard();
	 setlinestyle(0,0,1);
	 setfillstyle(1,GREEN);
                 bar(1,1,640,480);

	 setcolor(WHITE);
	 rectangle(260,0,388,32);
	 setfillstyle(1,YELLOW);
	 floodfill(261,1,WHITE);
	 puthz(260,0,"选择球员",32,32,BLUE);
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
		{
                                 x=131;
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

                 setfillstyle(1,GREEN);
	 floodfill(131,301,WHITE);
	 floodfill(463,301,WHITE);
				 setcolor(GREEN);
	 rectangle(130,300,130+96,300+30);
	 rectangle(130+108*3,300,130+108*3+96,300+30);

	 setcolor(BLUE);
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



	 puthz(260,385,"确认选择",32,32,BLUE);

	 puthz(130,100,name[0],32,32,BLUE);
	 puthz(238,100,name[1],32,32,BLUE);
	 puthz(346,100,name[2],32,32,BLUE);
	 puthz(454,100,name[3],32,32,BLUE);
	 puthz(130,200,name[4],32,32,BLUE);
	 puthz(238,200,name[5],32,32,BLUE);
	 puthz(346,200,name[6],32,32,BLUE);
	 puthz(454,200,name[7],32,32,BLUE);
	 puthz(238,300,name[8],32,32,BLUE);
	 puthz(346,300,name[9],32,32,BLUE);
	free(name);
	 while(1)
	 {
		 Newxy();
		 if(KeyPress(KEY_ESC))
								   {
												NewBK();
			choose_team();
									}
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
		if(ID[2]==1)
		{
			setcolor(RED);
			rectangle(346,100,442,130);
		}
		else
		{
			setcolor(WHITE);
			rectangle(346,100,442,130);
		}
		if(ID[3]==1)
		{
			setcolor(RED);
			rectangle(454,100,550,130);
		}
		else
		{
			setcolor(WHITE);
			rectangle(454,100,550,130);
		}
		if(ID[4]==1)
		{
			setcolor(RED);
			rectangle(130,200,226,230);
		}
		else
		{
			setcolor(WHITE);
			rectangle(130,200,226,230);
		}
		if(ID[5]==1)
		{
			setcolor(RED);
			rectangle(238,200,334,230);
		}
		else
		{
			setcolor(WHITE);
			rectangle(238,200,334,230);
		}
		if(ID[6]==1)
		{
			setcolor(RED);
			rectangle(346,200,442,230);
		}
		else
		{
			setcolor(WHITE);
			rectangle(346,200,442,230);
		}
		if(ID[7]==1)
		{
			setcolor(RED);
			rectangle(454,200,550,230);
		}
		else
		{
			setcolor(WHITE);
			rectangle(454,200,550,230);
		}
		if(ID[8]==1)
		{
			setcolor(RED);
			rectangle(238,300,334,330);
		}
		else
		{
			setcolor(WHITE);
			rectangle(238,300,334,330);
		}
		if(ID[9]==1)
		{
			setcolor(RED);
			rectangle(346,300,442,330);
		}
		else
		{
			setcolor(WHITE);
			rectangle(346,300,442,330);
		}
		if((ID[0]+ID[1]+ID[2]+ID[3]+ID[4]+ID[5]+ID[6]+ID[7]+ID[8]+ID[9])==5&&Mouse_press(250,375,400,425))//10??????5???????????????????????
		{
			NewBK();
			free(ID);
			// game(Left,Right,Red,Blue);
			xiuxi();
			while(1)
			{
				if(KeyPress(KEY_ENTER))
				{
					break;
				}
			}
			// game(Right,Left,Red,Blue);
			// result();
			while(1)
			{
				if(KeyPress(KEY_ENTER))
				{
					menu();
				}
			}
		}
	 }
}

void xiuxi()
{
	cleardevice();
	setfillstyle(1,GREEN);
	bar(0,0,640,480);
	puthz(240,100,"中场休息",32,32,BLUE);
	puthz(160,200,"按",32,32,BLUE);
	outtextxy(200,200,"Enter");
	puthz(320,200,"进入比赛下半场",32,32,BLUE);
}

void result(int historyMatch)//historyMatch表示倒数第几场比赛
{
	FILE *fp,*fpGame;
	int i,match;
	int myGoal,opGoal,*pmyScore,*popScore,*pmyHelp,*popHelp;
	cleardevice();
	setfillstyle(1,GREEN);
	bar(0,0,640,480);
	pmyScore=(int *)malloc(sizeof(int)*4);
	pmyHelp=(int *)malloc(sizeof(int)*4);
	popScore=(int *)malloc(sizeof(int)*4);
	popHelp=(int *)malloc(sizeof(int)*4);
	if(pmyScore==NULL||pmyHelp==NULL||popScore==NULL||popHelp==NULL)
		exit(0);
	fp=fopen("c:\\mycode\\name\\result.txt","r");
	fpGame=fopen("c:\\mycode\\name\\game.txt","r");
	fscanf(fpGame,"%d",&match);
	fclose(fpGame);
	match-=historyMatch;
	switch(match%20){
		case 1:fp=fopen("c:\\mycode\\name\\result1.txt","w");
		case 2:fp=fopen("c:\\mycode\\name\\result2.txt","w");
		case 3:fp=fopen("c:\\mycode\\name\\result3.txt","w");
		case 4:fp=fopen("c:\\mycode\\name\\result4.txt","w");
		case 5:fp=fopen("c:\\mycode\\name\\result5.txt","w");
		case 6:fp=fopen("c:\\mycode\\name\\result6.txt","w");
		case 7:fp=fopen("c:\\mycode\\name\\result7.txt","w");
		case 8:fp=fopen("c:\\mycode\\name\\result8.txt","w");
		case 9:fp=fopen("c:\\mycode\\name\\result9.txt","w");
		case 10:fp=fopen("c:\\mycode\\name\\result10.txt","w");
		case 11:fp=fopen("c:\\mycode\\name\\result11.txt","w");
		case 12:fp=fopen("c:\\mycode\\name\\result12.txt","w");
		case 13:fp=fopen("c:\\mycode\\name\\result13.tx3t","w");
		case 14:fp=fopen("c:\\mycode\\name\\result14.txt","w");
		case 15:fp=fopen("c:\\mycode\\name\\result15.txt","w");
		case 16:fp=fopen("c:\\mycode\\name\\result16.txt","w");
		case 17:fp=fopen("c:\\mycode\\name\\result17.txt","w");
		case 18:fp=fopen("c:\\mycode\\name\\result18.txt","w");
		case 19:fp=fopen("c:\\mycode\\name\\result19.txt","w");
		case 20:fp=fopen("c:\\mycode\\name\\result20.txt","w");
	}
	fscanf(fp,"%d\n%d\n",&myGoal,&opGoal);
	for(i=0;i<4;i++)
	{
		fscanf(fp,"%d\n",&pmyScore);
	}
	for(i=0;i<4;i++)
	{
		fscanf(fp,"%d\n",&popScore);
	}
	for(i=0;i<4;i++)
	{
		fscanf(fp,"%d\n",&pmyHelp);
	}
	for(i=0;i<4;i++)
	{
		fscanf(fp,"%d\n",&popHelp);
	}
	fclose(fp);
}

// //??????????
// void choose_player()
// {
//     int i,j,x,y=100;
// 	int ID[10];
// 	_result result_first,result_init,result_final;
// 	result_init.score_my=0;
// 	result_init.score_op=0;
// 	for(i=0;i<10;i++)
// 		ID[i]=0;
// 	 cleardevice();
// 	 setfillstyle(1,GREEN);
// 	 bar(0,0,640,480);
// 	 setcolor(WHITE);
// 	 rectangle(260,0,388,32);
// 	 setfillstyle(1,YELLOW);
// 	 floodfill(261,1,WHITE);
// 	 puthz(260,0,"??????",32,32,BLUE);
// 	 setcolor(WHITE);
// 	 for(j=0;j<3;j++)
// 		{
// 		 x=130;
// 		 for(i=0;i<4;i++)
// 			{
// 			 rectangle(x,y,x+96,y+30);
// 			 x+=108;
// 			}
// 		 y+=100;
// 		}

// 	 y=101;
// 	 for(j=0;j<3;j++)
// 		{x=131;
// 		 for(i=0;i<4;i++)
// 			{
// 			 floodfill(x,y,WHITE);
// 			 x+=108;
// 			}
// 		 y+=100;
// 		}
// 	 rectangle(250,375,400,425);
// 	 setfillstyle(1,CYAN);
// 	 floodfill(300,401,WHITE);
// 	 x=260;
// 	 puthz(210,40,"?????",32,32,BLUE);
// 	 line(242,72,200,92);
// 	 line(242,72,284,92);
// 	 puthz(430,40,"?????",32,32,BLUE);
// 	 line(462,72,420,92);
// 	 line(462,72,504,92);
// 	 puthz(210,140,"?????",32,32,BLUE);
// 	 line(242,172,200,192);
// 				 line(242,172,284,192);

// 	 puthz(430,140,"?????",32,32,BLUE);
// 	 line(462,172,420,192);
// 	 line(462,172,504,192);

// 	 puthz(300,250,"?????",32,32,BLUE);
// 	 line(340,282,300,295);
// 	 line(340,282,380,295);

// 	 setfillstyle(0,1);
// 	 floodfill(131,301,WHITE);
// 	 floodfill(463,301,WHITE);
// 	 setcolor(GREEN);
// 	 rectangle(130,300,130+96,300+30);
// 	 rectangle(130+108*3,300,130+108*3+96,300+30);
// 	 puthz(260,385,"??????",32,32,BLUE);

// 	 puthz(130,100,"???",32,32,BLUE);
// 	 puthz(238,100,"??????",32,32,BLUE);
// 	 puthz(346,100,"?????",32,32,BLUE);
// 	 puthz(454,100,"??????",32,32,BLUE);

// 	 puthz(130,200,"????",32,32,BLUE);
// 	 puthz(238,200,"??????",32,32,BLUE);
// 	 puthz(346,200,"??????",32,32,BLUE);
// 	 puthz(454,200,"????",32,32,BLUE);

// 	 puthz(238,300,"??",32,32,BLUE);
// 	 puthz(346,300,"??????",32,32,BLUE);
// 	 Initmouse(0,639,0,479);
// 	 InstallKeyboard();
// 	 NewBK();
// 	 while(1)
// 	 {
// 		 Newxy();
// 		 if(KeyPress(KEY_ESC))
// 			choose_team();
// 		if(Mouse_press(130,100,226,130))
// 	 	{
// 		 	ID[0]=1;
// 		 	ID[1]=0;
// 	 	}
// 		else if(Mouse_press(238,100,334,130))
// 	 	{
// 		 	ID[1]=1;
// 		 	ID[0]=0;
// 	 	}
// 		if(Mouse_press(346,100,442,130))
// 	 	{
// 		 	ID[2]=1;
// 		 	ID[3]=0;
// 	 	}
// 		else if(Mouse_press(454,100,550,130))
// 	 	{
// 		 	ID[3]=1;
// 		 	ID[2]=0;
// 	 	}
// 		if(Mouse_press(130,200,226,230))
// 	 	{
// 		 	ID[4]=1;
// 		 	ID[5]=0;
// 	 	}
// 	 	else if(Mouse_press(238,200,334,230))
// 	 	{
// 			ID[5]=1;
// 			ID[4]=0;
// 	 	}
// 		 if(Mouse_press(346,200,442,230))
// 	 	{
// 		 	ID[6]=1;
// 		 	ID[7]=0;
// 	 	}
// 		 else if(Mouse_press(454,200,550,230))
// 	 	{
// 		 	ID[7]=1;
// 		 	ID[6]=0;
// 	 	}
// 		if(Mouse_press(238,300,334,330))
// 	 	{
// 		 	ID[8]=1;
// 		 	ID[9]=0;
// 	 	}
// 		 else if(Mouse_press(346,300,442,330))
// 	 	{
// 		 	ID[9]=1;
// 		 	ID[8]=0;
// 	 	}
// 		if(ID[0]==1)
// 		{
// 			setcolor(RED);
// 			rectangle(130,100,226,130);
// 		}
// 		else
// 		{
// 			setcolor(WHITE);
// 			rectangle(130,100,226,130);
// 		}
// 		if(ID[1]==1)
// 		{
// 			setcolor(RED);
// 			rectangle(238,100,334,130);
// 		}
// 		else
// 		{
// 			setcolor(WHITE);
// 			rectangle(238,100,334,130);
// 		}
// 		if(ID[1]==1)
// 		{
// 			setcolor(RED);
// 			rectangle(238,100,334,130);
// 		}
// 		else
// 		{
// 			setcolor(WHITE);
// 			rectangle(238,100,334,130);
// 		}
// 		if(ID[1]==1)
// 		{
// 			setcolor(RED);
// 			rectangle(238,100,334,130);
// 		}
// 		else
// 		{
// 			setcolor(WHITE);
// 			rectangle(238,100,334,130);
// 		}
// 		if(ID[1]==1)
// 		{
// 			setcolor(RED);
// 			rectangle(238,100,334,130);
// 		}
// 		else
// 		{
// 			setcolor(WHITE);
// 			rectangle(238,100,334,130);
// 		}
// 		if(ID[1]==1)
// 		{
// 			setcolor(RED);
// 			rectangle(238,100,334,130);
// 		}
// 		else
// 		{
// 			setcolor(WHITE);
// 			rectangle(238,100,334,130);
// 		}
// 		if(ID[2])
// 		 	rectangle(346,100,442,130);
// 		if(ID[3])
// 		 	rectangle(454,100,550,130);
// 		if(ID[4])
// 		 	rectangle(130,200,226,230);
// 		if(ID[5])
// 		 	rectangle(238,200,334,230);
// 		if(ID[6])
// 		 	rectangle(346,200,442,230);
// 		if(ID[7])
// 		 	rectangle(454,200,550,230);
// 		if(ID[8])
// 		 	rectangle(238,300,334,330);
// 		if(ID[9])
// 		 	rectangle(346,300,442,330);
// 		if((ID[0]+ID[1]+ID[2]+ID[3]+ID[4]+ID[5]+ID[6]+ID[7]+ID[8]+ID[9])==5&&Mouse_press(250,375,400,425))//10??????5???????????????????????
// 		{
// 			result_first=game(Left,Right,Red,Blue,result_init);
// 			while(1)
// 			{
// 				if(KeyPress(KEY_ENTER))
// 					break;
// 			}
// 			result_final=game(Right,Left,Red,Blue,result_first);
// 		}
// 	 }
// }
void shop(int path_)
{

   int i,j,k,choose=1,ability;
   int color1=0,color2=0,color3=0,color4=0;
   int change1=0,change2=0,change3=0,change4=0;
   int bool;
   long amount,amount1,amount2,damount;
   char ch,length,path;
   char *c1,*c2,*c3,*c4,*c5,*c6;
   char money[4],money1[10][4],money2[10][4];
   char a1[36],a2[36];
   char s[10][10];
   char s1[11][10];
   char s2[11][10];
   char ability1[5][4];
   char ability2[5][4];
   char ability3[5][4];
   char ability4[5][4];
   FILE *fp1;
   FILE *fp2;
   FILE *fp;
   setfillstyle(1,GREEN);
   bar(1,1,639,479);
   setcolor(BLUE);
   rectangle(30,100,126,132);
   rectangle(30,150,126,182);
   rectangle(30,200,126,232);
   rectangle(30,250,126,282);
   rectangle(30,300,126,332);
   rectangle(180,50,340,82);
   rectangle(420,50,580,82);
   setlinestyle(0,0,1);
   line(410,50,400,66);
   line(400,66,410,82);
   line(410,50,410,82);
   line(590,50,600,66);
   line(600,66,590,82);
   line(590,50,590,82);
   circle(330,116,10);
   circle(330,316,10);
   circle(430,116,10);
   circle(430,316,10);
   line(1,116,11,132);
   line(11,132,21,100);

   puthz(30,100,"左前锋",32,32,BLUE);
   puthz(30,150,"右前锋",32,32,BLUE);
   puthz(30,200,"左后卫",32,32,BLUE);
   puthz(30,250,"右后卫",32,32,BLUE);
   puthz(30,300,"守门员",32,32,BLUE);
   puthz(1,50,"金额",32,32,BLUE);
   outtextxy(70,66,":");
   rectangle(212,100,308,132);
   rectangle(212,300,308,332);
   rectangle(452,100,548,132);
   rectangle(452,300,548,332);
   switch(path_)
		 {
		   case 1:   if((fp1=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
					   {
						  setlinestyle(0,0,1);
						  outtextxy(300,300,"cannot open the file");
						  exit(1);
					   }
					 break;
		   case 2:   if((fp1=fopen("c:\\mycode\\shop\\2.txt","r+"))==NULL)
					   {
						  setlinestyle(0,0,1);
						  outtextxy(300,300,"cannot open the file");
						  exit(1);
					   }
					 break;
		   case 3:   if((fp1=fopen("c:\\mycode\\shop\\3.txt","r+"))==NULL)
					   {
						  setlinestyle(0,0,1);
						  outtextxy(300,300,"cannot open the file");
						  exit(1);
					   }
					 break;
		   case 4:   if((fp1=fopen("c:\\mycode\\shop\\4.txt","r+"))==NULL)
					   {
						  setlinestyle(0,0,1);
						  outtextxy(300,300,"cannot open the file");
						  exit(1);
					   }
					 break;
		   case 5:   if((fp1=fopen("c:\\mycode\\shop\\5.txt","r+"))==NULL)
					   {
						  setlinestyle(0,0,1);
						  outtextxy(300,300,"cannot open the file");
						  exit(1);
					   }
					 break;
		 }
   length=fgetc(fp1);
	for(i=0;i<10;i++)
	  {
		ch=fgetc(fp1);
		s1[0][i]=ch;
	  }
   s1[0][2*(length-48)]='\0';
   ch=fgetc(fp1);

   for(j=1;j<11;j++)
	  {
		 length=fgetc(fp1);
		 for(i=0;i<10;i++)
			{
				ch=fgetc(fp1);
				s1[j][i]=ch;
			}
		 s1[j][2*(length-48)]='\0';
		 if(j<10)
		 fseek(fp1,26,1);

	  }
	for(i=1;i<11;i++)
	   {
		 fseek(fp1,13+37*(i-1)+26,0);
		 ch=fgetc(fp1);
		 money1[i-1][0]=ch;
		 ch=fgetc(fp1);
		 money1[i-1][1]=ch;
		 ch=fgetc(fp1);
		 money1[i-1][2]=ch;
		 ch=fgetc(fp1);
		 money1[i-1][3]=ch;
	   }
	fclose(fp1);

	if((fp=fopen("c:\\mycode\\shop\\path.txt","r+"))==NULL)
	 {
		setlinestyle(0,0,1);
		outtextxy(300,300,"cannot open the file");
		exit(1);
	 }
	 path=fgetc(fp);
	 if(path_==path-48)
	  {
		if(1<=path_<5)
		  {
			path+=1;
		  }
		if(path_==5)
		  {
			path=49;
		  }
		rewind(fp);
		fputc(path,fp);
	  }
	 fclose(fp);

	 if((fp=fopen("c:\\mycode\\shop\\money.txt","r+"))==NULL)
	 {
		setlinestyle(0,0,1);
		outtextxy(300,300,"cannot open the file");
		exit(1);
	 }
	 for(i=0;i<4;i++)
		{
		  ch=fgetc(fp);
		  money[i]=ch;
		}
	 fclose(fp);

	switch(path-48)
		  {
		   case 1:   if((fp2=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
					   {
						 setlinestyle(0,0,1);
						 outtextxy(300,300,"cannot open the file");
						 exit(1);
					   }
					   break;
		   case 2:  if((fp2=fopen("c:\\mycode\\shop\\2.txt","r+"))==NULL)
					  {
						setlinestyle(0,0,1);
						outtextxy(300,300,"cannot open the file");
						exit(1);
					  }
					  break;
		   case 3:  if((fp2=fopen("c:\\mycode\\shop\\3.txt","r+"))==NULL)
					  {
						setlinestyle(0,0,1);
						outtextxy(300,300,"cannot open the file");
						exit(1);
					  }
					  break;
		   case 4: if((fp2=fopen("c:\\mycode\\shop\\4.txt","r+"))==NULL)
					  {
						setlinestyle(0,0,1);
						outtextxy(300,300,"cannot open the file");
						exit(1);
					  }
					  break;
		   case 5: if((fp2=fopen("c:\\mycode\\shop\\5.txt","r+"))==NULL)
					  {
						setlinestyle(0,0,1);
						outtextxy(300,300,"cannot open the file");
						exit(1);
					  }
					  break;
		  }

   length=fgetc(fp2);
	for(i=0;i<10;i++)
	  {
		ch=fgetc(fp2);
		s2[0][i]=ch;
	  }
   s2[0][2*(length-48)]='\0';
   ch=fgetc(fp2);

   for(j=1;j<11;j++)
	  {
		 length=fgetc(fp2);
		 for(i=0;i<10;i++)
			{
				ch=fgetc(fp2);
				s2[j][i]=ch;
			}
		 s2[j][2*(length-48)]='\0';
		 if(j<10)
		 fseek(fp2,26,1);

	  }
   for(i=1;i<11;i++)
	   {
		 fseek(fp2,13+37*(i-1)+26,0);
		 ch=fgetc(fp2);
		 money2[i-1][0]=ch;
		 ch=fgetc(fp2);
		 money2[i-1][1]=ch;
		 ch=fgetc(fp2);
		 money2[i-1][2]=ch;
		 ch=fgetc(fp2);
		 money2[i-1][3]=ch;
	   }
   fclose(fp2);

   c1=s1[0];
   c2=s1[1];
   c3=s1[2];
   c4=s2[0];
   c5=s2[1];
   c6=s2[2];
   puthz(195,50,c1,32,32,BLUE);
   puthz(212,100,c2,32,32,BLUE);
   puthz(212,300,c3,32,32,BLUE);
   puthz(435,50,c4,32,32,BLUE);
   puthz(452,100,c5,32,32,BLUE);
   puthz(452,300,c6,32,32,BLUE);
   for(i=0;i<4;i++)
	  {
		draw_num(90+i*12,60,money[i]-48,6);
	  }
   for(i=0;i<4;i++)
	  {
		draw_num(150+i*12,113,money1[0][i]-48,6);
	  }
   for(i=0;i<4;i++)
	  {
		draw_num(150+i*12,313,money1[1][i]-48,6);
	  }
   for(i=0;i<4;i++)
	  {
		draw_num(565+i*12,113,money2[0][i]-48,6);
	  }
   for(i=0;i<4;i++)
	  {
		draw_num(565+i*12,313,money2[1][i]-48,6);
	  }
   while(1)
		{
			  Newxy();
			  if(change2==1&&change4==1)
				{
						   color1=0;
						   color2=0;
						   color3=0;
						   color4=0;
						   bool=1;
						   setfillstyle(1,GREEN);
						   bar(136,140,365,290);
						   bar(380,140,609,290);
						   bar(136,340,365,490);
						   bar(380,340,609,490);

						   bar(212,100,308,132);
						   bar(212,300,308,332);
						   bar(452,100,548,132);
						   bar(452,300,548,332);
						   setcolor(BLUE);
						   rectangle(212,100,308,132);
						   rectangle(212,300,308,332);
						   rectangle(452,100,548,132);
						   rectangle(452,300,548,332);
						   puthz(212,100,c2,32,32,BLUE);
						   puthz(212,300,c3,32,32,BLUE);
						   puthz(452,100,c5,32,32,BLUE);
						   puthz(452,300,c6,32,32,BLUE);
						   setfillstyle(1,LIGHTCYAN);
						   bar(308,140,452,290);
						   setcolor(BLUE);
						   rectangle(340,210,372,242);
						   rectangle(390,210,422,242);
						   puthz(350,160,"交换",32,32,BLUE);
						   puthz(340,210,"是",32,32,BLUE);
						   puthz(390,210,"否",32,32,BLUE);
						   while(bool)
								{
								  Newxy();
								  if(Mouse_press(390,210,422,242))
									{
									   NewBK();
									   setcolor(BLUE);
									   circle(330,316,10);
									   circle(430,316,10);
									   setfillstyle(1,GREEN);
									   floodfill(330,316,BLUE);
									   floodfill(430,316,BLUE);
									   bar(308,140,452,290);
									   change2=0;
									   change4=0;
									   bool=0;
									}
								  if(Mouse_press(340,210,372,242))
									{
									   NewBK();
									   setcolor(BLUE);
									   circle(330,316,10);
									   circle(430,316,10);
									   setfillstyle(1,GREEN);
									   floodfill(330,316,BLUE);
									   floodfill(430,316,BLUE);
									   bar(308,140,452,290);

									   for(i=1;i<11;i++)
										  {
											if(strcmp(c3,s1[i])==0)
											break;
										  }
									   for(j=1;j<11;j++)
										  {
											if(strcmp(c6,s2[j])==0)
											break;
										  }
									   if((fp1=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
										 {
										   setlinestyle(0,0,1);
										   outtextxy(300,300,"cannot open the file");
										   exit(1);
										 }
									   fseek(fp1,13+37*(i-1),0);
									   for(k=0;k<36;k++)
										  {
											ch=fgetc(fp1);
											a1[k]=ch;
										  }
									   fclose(fp1);
									   switch(path-48)
											 {
											   case 1:   if((fp2=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
														   {
															 setlinestyle(0,0,1);
															 outtextxy(300,300,"cannot open the file");
															 exit(1);
														   }
														 break;
											   case 2:  if((fp2=fopen("c:\\mycode\\shop\\2.txt","r+"))==NULL)
														  {
															 setlinestyle(0,0,1);
															 outtextxy(300,300,"cannot open the file");
															 exit(1);
														  }
														 break;
											   case 3:  if((fp2=fopen("c:\\mycode\\shop\\3.txt","r+"))==NULL)
														  {
															setlinestyle(0,0,1);
															outtextxy(300,300,"cannot open the file");
															exit(1);
														  }
														 break;
											   case 4: if((fp2=fopen("c:\\mycode\\shop\\4.txt","r+"))==NULL)
														 {
															  setlinestyle(0,0,1);
															  outtextxy(300,300,"cannot open the file");
															  exit(1);
														  }
														break;
											   case 5: if((fp2=fopen("c:\\mycode\\shop\\5.txt","r+"))==NULL)
														 {
															setlinestyle(0,0,1);
															outtextxy(300,300,"cannot open the file");
															exit(1);
														 }
														break;
									   }
									   fseek(fp2,13+37*(j-1),0);
									   for(k=0;k<36;k++)
										  {
											ch=fgetc(fp2);
											a2[k]=ch;
										  }

									   fseek(fp2,13+37*(j-1),0);
									   for(k=0;k<36;k++)
										  {
											ch=a1[k];
											fputc(ch,fp2);
										  }

									   fseek(fp2,13+37*(j-1),0);
									   length=fgetc(fp2);
									   for(k=0;k<10;k++)
										  {
											ch=fgetc(fp2);
											s2[j][k]=ch;
										  }
									   s2[j][2*(length-48)]='\0';
									   for(k=1;k<11;k++)
										  {
											fseek(fp2,13+37*(k-1)+26,0);
											ch=fgetc(fp2);
											money2[k-1][0]=ch;
											ch=fgetc(fp2);
											money2[k-1][1]=ch;
											ch=fgetc(fp2);
											money2[k-1][2]=ch;
											ch=fgetc(fp2);
											money2[k-1][3]=ch;
										  }
									   fclose(fp2);

									   if((fp1=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
										 {
										   setlinestyle(0,0,1);
										   outtextxy(300,300,"cannot open the file");
										   exit(1);
										 }
									   fseek(fp1,13+37*(i-1),0);
									   for(k=0;k<36;k++)
										  {
											ch=a2[k];
											fputc(ch,fp1);
										  }
									   fseek(fp1,13+37*(i-1),0);
									   length=fgetc(fp1);
									   for(k=0;k<10;k++)
										  {
											ch=fgetc(fp1);
											s1[i][k]=ch;
										  }
									   s1[i][2*(length-48)]='\0';
									   for(k=1;k<11;k++)
										  {
											fseek(fp1,13+37*(k-1)+26,0);
											ch=fgetc(fp1);
											money1[k-1][0]=ch;
											ch=fgetc(fp1);
											money1[k-1][1]=ch;
											ch=fgetc(fp1);
											money1[k-1][2]=ch;
											ch=fgetc(fp1);
											money1[k-1][3]=ch;
										  }
									   fclose(fp1);

									   c3=s1[i];
									   c6=s2[j];
									   amount1=(money2[(choose-1)*2+1][0]-48)*1000+(money2[(choose-1)*2+1][1]-48)*100+(money2[(choose-1)*2+1][2]-48)*10+(money2[(choose-1)*2+1][3]-48)*1;
									   amount2=(money1[(choose-1)*2+1][0]-48)*1000+(money1[(choose-1)*2+1][1]-48)*100+(money1[(choose-1)*2+1][2]-48)*10+(money1[(choose-1)*2+1][3]-48)*1;
									   damount=amount1-amount2;
									   amount=(money[0]-48)*1000+(money[1]-48)*100+(money[2]-48)*10+(money[3]-48)*1;
									   amount+=damount;
									   for(i=0;i<4;i++)
										  {
											money[3-i]=amount%10+48;
											amount=amount/10;
										  }
									   if((fp=fopen("c:\\mycode\\shop\\money.txt","r+"))==NULL)
										  {
											setlinestyle(0,0,1);
											outtextxy(300,300,"cannot open the file");
											exit(1);
										  }
									   for(i=0;i<4;i++)
										  {
											  ch=money[i];
											  fputc(ch,fp);
										   }
									   fclose(fp);
									   setfillstyle(1,GREEN);
									   setcolor(BLUE);
									   bar(150,113,198,125);
									   bar(150,313,198,325);
									   bar(565,113,613,125);
									   bar(565,313,613,325);
									   bar(90,60,138,72);
									   for(i=0;i<4;i++)
										  {
											draw_num(90+i*12,60,money[i]-48,6);
										  }
									   for(i=0;i<4;i++)
										  {
											 draw_num(150+i*12,113,money1[(choose-1)*2][i]-48,6);
										  }
									   for(i=0;i<4;i++)
										  {
											 draw_num(150+i*12,313,money1[(choose-1)*2+1][i]-48,6);
										  }
									   for(i=0;i<4;i++)
										  {
											draw_num(565+i*12,113,money2[(choose-1)*2][i]-48,6);
										  }
									   for(i=0;i<4;i++)
										  {
											 draw_num(565+i*12,313,money2[(choose-1)*2+1][i]-48,6);
										  }

									   setfillstyle(1,GREEN);
									   bar(212,300,308,332);
									   bar(452,300,548,332);
									   setcolor(BLUE);
									   rectangle(212,300,308,332);
									   rectangle(452,300,548,332);
									   puthz(212,300,c3,32,32,BLUE);
									   puthz(452,300,c6,32,32,BLUE);

									   change2=0;
									   change4=0;
									   bool=0;
									}

								}

				}
				  if(change2==1&&change3==1)
				{
						   color1=0;
						   color2=0;
						   color3=0;
						   color4=0;
						   bool=1;
						   setfillstyle(1,GREEN);
						   bar(136,140,365,290);
						   bar(380,140,609,290);
						   bar(136,340,365,490);
						   bar(380,340,609,490);

						   bar(212,100,308,132);
						   bar(212,300,308,332);
						   bar(452,100,548,132);
						   bar(452,300,548,332);
						   setcolor(BLUE);
						   rectangle(212,100,308,132);
						   rectangle(212,300,308,332);
						   rectangle(452,100,548,132);
						   rectangle(452,300,548,332);
						   puthz(212,100,c2,32,32,BLUE);
						   puthz(212,300,c3,32,32,BLUE);
						   puthz(452,100,c5,32,32,BLUE);
						   puthz(452,300,c6,32,32,BLUE);
						   setfillstyle(1,LIGHTCYAN);
						   bar(308,140,452,290);
						   setcolor(BLUE);
						   rectangle(340,210,372,242);
						   rectangle(390,210,422,242);
						   puthz(350,160,"交换",32,32,BLUE);
						   puthz(340,210,"是",32,32,BLUE);
						   puthz(390,210,"否",32,32,BLUE);
						   while(bool)
								{
								  Newxy();
								  if(Mouse_press(390,210,422,242))
									{
									   NewBK();
									   setcolor(BLUE);
									   circle(330,316,10);
									   circle(430,116,10);
									   setfillstyle(1,GREEN);
									   floodfill(330,316,BLUE);
									   floodfill(430,116,BLUE);
									   bar(308,140,452,290);
									   change2=0;
									   change3=0;
									   bool=0;
									}
								  if(Mouse_press(340,210,372,242))
									{
									   NewBK();
									   setcolor(BLUE);
									   circle(330,316,10);
									   circle(430,116,10);
									   setfillstyle(1,GREEN);
									   floodfill(330,316,BLUE);
									   floodfill(430,116,BLUE);
									   bar(308,140,452,290);

									   for(i=1;i<11;i++)
										  {
											if(strcmp(c3,s1[i])==0)
											break;
										  }
									   for(j=1;j<11;j++)
										  {
											if(strcmp(c5,s2[j])==0)
											break;
										  }
									   if((fp1=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
										 {
										   setlinestyle(0,0,1);
										   outtextxy(300,300,"cannot open the file");
										   exit(1);
										 }
									   fseek(fp1,13+37*(i-1),0);
									   for(k=0;k<36;k++)
										  {
											ch=fgetc(fp1);
											a1[k]=ch;
										  }
									   fclose(fp1);
									   switch(path-48)
											 {
											   case 1:   if((fp2=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
														   {
															 setlinestyle(0,0,1);
															 outtextxy(300,300,"cannot open the file");
															 exit(1);
														   }
														 break;
											   case 2:  if((fp2=fopen("c:\\mycode\\shop\\2.txt","r+"))==NULL)
														  {
															 setlinestyle(0,0,1);
															 outtextxy(300,300,"cannot open the file");
															 exit(1);
														  }
														 break;
											   case 3:  if((fp2=fopen("c:\\mycode\\shop\\3.txt","r+"))==NULL)
														  {
															setlinestyle(0,0,1);
															outtextxy(300,300,"cannot open the file");
															exit(1);
														  }
														 break;
											   case 4: if((fp2=fopen("c:\\mycode\\shop\\4.txt","r+"))==NULL)
														 {
															  setlinestyle(0,0,1);
															  outtextxy(300,300,"cannot open the file");
															  exit(1);
														  }
														break;
											   case 5: if((fp2=fopen("c:\\mycode\\shop\\5.txt","r+"))==NULL)
														 {
															setlinestyle(0,0,1);
															outtextxy(300,300,"cannot open the file");
															exit(1);
														 }
														break;
									   }
									   fseek(fp2,13+37*(j-1),0);
									   for(k=0;k<36;k++)
										  {
											ch=fgetc(fp2);
											a2[k]=ch;
										  }

									   fseek(fp2,13+37*(j-1),0);
									   for(k=0;k<36;k++)
										  {
											ch=a1[k];
											fputc(ch,fp2);
										  }

									   fseek(fp2,13+37*(j-1),0);
									   length=fgetc(fp2);
									   for(k=0;k<10;k++)
										  {
											ch=fgetc(fp2);
											s2[j][k]=ch;
										  }
									   s2[j][2*(length-48)]='\0';
									   for(k=1;k<11;k++)
										  {
											fseek(fp2,13+37*(k-1)+26,0);
											ch=fgetc(fp2);
											money2[k-1][0]=ch;
											ch=fgetc(fp2);
											money2[k-1][1]=ch;
											ch=fgetc(fp2);
											money2[k-1][2]=ch;
											ch=fgetc(fp2);
											money2[k-1][3]=ch;
										  }
									   fclose(fp2);
									   if((fp1=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
										 {
										   setlinestyle(0,0,1);
										   outtextxy(300,300,"cannot open the file");
										   exit(1);
										 }
									   fseek(fp1,13+37*(i-1),0);
									   for(k=0;k<36;k++)
										  {
											ch=a2[k];
											fputc(ch,fp1);
										  }
									   fseek(fp1,13+37*(i-1),0);
									   length=fgetc(fp1);
									   for(k=0;k<10;k++)
										  {
											ch=fgetc(fp1);
											s1[i][k]=ch;
										  }
									   s1[i][2*(length-48)]='\0';
									   for(k=1;k<11;k++)
										  {
											fseek(fp1,13+37*(k-1)+26,0);
											ch=fgetc(fp1);
											money1[k-1][0]=ch;
											ch=fgetc(fp1);
											money1[k-1][1]=ch;
											ch=fgetc(fp1);
											money1[k-1][2]=ch;
											ch=fgetc(fp1);
											money1[k-1][3]=ch;
										  }
									   fclose(fp1);
									   c3=s1[i];
									   c5=s2[j];
									   amount1=(money2[(choose-1)*2][0]-48)*1000+(money2[(choose-1)*2][1]-48)*100+(money2[(choose-1)*2][2]-48)*10+(money2[(choose-1)*2][3]-48)*1;
									   amount2=(money1[(choose-1)*2+1][0]-48)*1000+(money1[(choose-1)*2+1][1]-48)*100+(money1[(choose-1)*2+1][2]-48)*10+(money1[(choose-1)*2+1][3]-48)*1;
									   damount=amount1-amount2;
									   amount=(money[0]-48)*1000+(money[1]-48)*100+(money[2]-48)*10+(money[3]-48)*1;
									   amount+=damount;
									   for(i=0;i<4;i++)
										  {
											money[3-i]=amount%10+48;
											amount=amount/10;
										  }
									   if((fp=fopen("c:\\mycode\\shop\\money.txt","r+"))==NULL)
										  {
											setlinestyle(0,0,1);
											outtextxy(300,300,"cannot open the file");
											exit(1);
										  }
									   for(i=0;i<4;i++)
										  {
											  ch=money[i];
											  fputc(ch,fp);
										   }
									   fclose(fp);
									   setfillstyle(1,GREEN);
									   setcolor(BLUE);
									   bar(150,113,198,125);
									   bar(150,313,198,325);
									   bar(565,113,613,125);
									   bar(565,313,613,325);
									   bar(90,60,138,72);
									   for(i=0;i<4;i++)
										  {
											draw_num(90+i*12,60,money[i]-48,6);
										  }
									   for(i=0;i<4;i++)
										  {
											 draw_num(150+i*12,113,money1[(choose-1)*2][i]-48,6);
										  }
									   for(i=0;i<4;i++)
										  {
											 draw_num(150+i*12,313,money1[(choose-1)*2+1][i]-48,6);
										  }
									   for(i=0;i<4;i++)
										  {
											draw_num(565+i*12,113,money2[(choose-1)*2][i]-48,6);
										  }
									   for(i=0;i<4;i++)
										  {
											 draw_num(565+i*12,313,money2[(choose-1)*2+1][i]-48,6);
										  }

									   setfillstyle(1,GREEN);
									   bar(212,300,308,332);
									   bar(452,100,548,132);
									   setcolor(BLUE);
									   rectangle(212,300,308,332);
									   rectangle(452,100,548,132);
									   puthz(212,300,c3,32,32,BLUE);
									   puthz(452,100,c5,32,32,BLUE);

									   change2=0;
									   change3=0;
									   bool=0;
									}

								}

				}
			  if(change1==1&&change4==1)
				{
						   color1=0;
						   color2=0;
						   color3=0;
						   color4=0;
						   bool=1;
						   setfillstyle(1,GREEN);
						   bar(136,140,365,290);
						   bar(380,140,609,290);
						   bar(136,340,365,490);
						   bar(380,340,609,490);

						   bar(212,100,308,132);
						   bar(212,300,308,332);
						   bar(452,100,548,132);
						   bar(452,300,548,332);
						   setcolor(BLUE);
						   rectangle(212,100,308,132);
						   rectangle(212,300,308,332);
						   rectangle(452,100,548,132);
						   rectangle(452,300,548,332);
						   puthz(212,100,c2,32,32,BLUE);
						   puthz(212,300,c3,32,32,BLUE);
						   puthz(452,100,c5,32,32,BLUE);
						   puthz(452,300,c6,32,32,BLUE);
						   setfillstyle(1,LIGHTCYAN);
						   bar(308,140,452,290);
						   setcolor(BLUE);
						   rectangle(340,210,372,242);
						   rectangle(390,210,422,242);
						   puthz(350,160,"交换",32,32,BLUE);
						   puthz(340,210,"是",32,32,BLUE);
						   puthz(390,210,"否",32,32,BLUE);
						   while(bool)
								{
								  Newxy();
								  if(Mouse_press(390,210,422,242))
									{
									   NewBK();
									   setcolor(BLUE);
									   circle(330,116,10);
									   circle(430,316,10);
									   setfillstyle(1,GREEN);
									   floodfill(330,116,BLUE);
									   floodfill(430,316,BLUE);
									   bar(308,140,452,290);
									   change1=0;
									   change4=0;
									   bool=0;
									}
								  if(Mouse_press(340,210,372,242))
									{
									   NewBK();
									   setcolor(BLUE);
									   circle(330,116,10);
									   circle(430,316,10);
									   setfillstyle(1,GREEN);
									   floodfill(330,116,BLUE);
									   floodfill(430,316,BLUE);
									   bar(308,140,452,290);

									   for(i=1;i<11;i++)
										  {
											if(strcmp(c2,s1[i])==0)
											break;
										  }
									   for(j=1;j<11;j++)
										  {
											if(strcmp(c6,s2[j])==0)
											break;
										  }
									   if((fp1=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
										 {
										   setlinestyle(0,0,1);
										   outtextxy(300,300,"cannot open the file");
										   exit(1);
										 }
									   fseek(fp1,13+37*(i-1),0);
									   for(k=0;k<36;k++)
										  {
											ch=fgetc(fp1);
											a1[k]=ch;
										  }
									   fclose(fp1);
									   switch(path-48)
											 {
											   case 1:   if((fp2=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
														   {
															 setlinestyle(0,0,1);
															 outtextxy(300,300,"cannot open the file");
															 exit(1);
														   }
														 break;
											   case 2:  if((fp2=fopen("c:\\mycode\\shop\\2.txt","r+"))==NULL)
														  {
															 setlinestyle(0,0,1);
															 outtextxy(300,300,"cannot open the file");
															 exit(1);
														  }
														 break;
											   case 3:  if((fp2=fopen("c:\\mycode\\shop\\3.txt","r+"))==NULL)
														  {
															setlinestyle(0,0,1);
															outtextxy(300,300,"cannot open the file");
															exit(1);
														  }
														 break;
											   case 4: if((fp2=fopen("c:\\mycode\\shop\\4.txt","r+"))==NULL)
														 {
															  setlinestyle(0,0,1);
															  outtextxy(300,300,"cannot open the file");
															  exit(1);
														  }
														break;
											   case 5: if((fp2=fopen("c:\\mycode\\shop\\5.txt","r+"))==NULL)
														 {
															setlinestyle(0,0,1);
															outtextxy(300,300,"cannot open the file");
															exit(1);
														 }
														break;
									   }
									   fseek(fp2,13+37*(j-1),0);
									   for(k=0;k<36;k++)
										  {
											ch=fgetc(fp2);
											a2[k]=ch;
										  }

									   fseek(fp2,13+37*(j-1),0);
									   for(k=0;k<36;k++)
										  {
											ch=a1[k];
											fputc(ch,fp2);
										  }

									   fseek(fp2,13+37*(j-1),0);
									   length=fgetc(fp2);
									   for(k=0;k<10;k++)
										  {
											ch=fgetc(fp2);
											s2[j][k]=ch;
										  }
									   s2[j][2*(length-48)]='\0';
									   for(k=1;k<11;k++)
										  {
											fseek(fp2,13+37*(k-1)+26,0);
											ch=fgetc(fp2);
											money2[k-1][0]=ch;
											ch=fgetc(fp2);
											money2[k-1][1]=ch;
											ch=fgetc(fp2);
											money2[k-1][2]=ch;
											ch=fgetc(fp2);
											money2[k-1][3]=ch;
										  }
									   fclose(fp2);
									   if((fp1=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
										 {
										   setlinestyle(0,0,1);
										   outtextxy(300,300,"cannot open the file");
										   exit(1);
										 }
									   fseek(fp1,13+37*(i-1),0);
									   for(k=0;k<36;k++)
										  {
											ch=a2[k];
											fputc(ch,fp1);
										  }
									   fseek(fp1,13+37*(i-1),0);
									   length=fgetc(fp1);
									   for(k=0;k<10;k++)
										  {
											ch=fgetc(fp1);
											s1[i][k]=ch;
										  }
									   s1[i][2*(length-48)]='\0';
									   for(k=1;k<11;k++)
										  {
											fseek(fp1,13+37*(k-1)+26,0);
											ch=fgetc(fp1);
											money1[k-1][0]=ch;
											ch=fgetc(fp1);
											money1[k-1][1]=ch;
											ch=fgetc(fp1);
											money1[k-1][2]=ch;
											ch=fgetc(fp1);
											money1[k-1][3]=ch;
										  }
									   fclose(fp1);
									   c2=s1[i];
									   c6=s2[j];
									   amount1=(money2[(choose-1)*2+1][0]-48)*1000+(money2[(choose-1)*2+1][1]-48)*100+(money2[(choose-1)*2+1][2]-48)*10+(money2[(choose-1)*2+1][3]-48)*1;
									   amount2=(money1[(choose-1)*2][0]-48)*1000+(money1[(choose-1)*2][1]-48)*100+(money1[(choose-1)*2][2]-48)*10+(money1[(choose-1)*2][3]-48)*1;
									   damount=amount1-amount2;
									   amount=(money[0]-48)*1000+(money[1]-48)*100+(money[2]-48)*10+(money[3]-48)*1;
									   amount+=damount;
									   for(i=0;i<4;i++)
										  {
											money[3-i]=amount%10+48;
											amount=amount/10;
										  }
									   if((fp=fopen("c:\\mycode\\shop\\money.txt","r+"))==NULL)
										  {
											setlinestyle(0,0,1);
											outtextxy(300,300,"cannot open the file");
											exit(1);
										  }
									   for(i=0;i<4;i++)
										  {
											  ch=money[i];
											  fputc(ch,fp);
										   }
									   fclose(fp);
									   setfillstyle(1,GREEN);
									   setcolor(BLUE);
									   bar(150,113,198,125);
									   bar(150,313,198,325);
									   bar(565,113,613,125);
									   bar(565,313,613,325);
									   bar(90,60,138,72);
									   for(i=0;i<4;i++)
										  {
											draw_num(90+i*12,60,money[i]-48,6);
										  }
									   for(i=0;i<4;i++)
										  {
											 draw_num(150+i*12,113,money1[(choose-1)*2][i]-48,6);
										  }
									   for(i=0;i<4;i++)
										  {
											 draw_num(150+i*12,313,money1[(choose-1)*2+1][i]-48,6);
										  }
									   for(i=0;i<4;i++)
										  {
											draw_num(565+i*12,113,money2[(choose-1)*2][i]-48,6);
										  }
									   for(i=0;i<4;i++)
										  {
											 draw_num(565+i*12,313,money2[(choose-1)*2+1][i]-48,6);
										  }

									   setfillstyle(1,GREEN);
									   bar(212,100,308,132);
									   bar(452,300,548,332);
									   setcolor(BLUE);
									   rectangle(212,100,308,132);
									   rectangle(452,300,548,332);
									   puthz(212,100,c2,32,32,BLUE);
									   puthz(452,300,c6,32,32,BLUE);

									   change1=0;
									   change4=0;
									   bool=0;
									}

								}

				}
			  if(change1==1&&change3==1)
				{
						   color1=0;
						   color2=0;
						   color3=0;
						   color4=0;
						   bool=1;
						   setfillstyle(1,GREEN);
						   bar(136,140,365,290);
						   bar(380,140,609,290);
						   bar(136,340,365,490);
						   bar(380,340,609,490);

						   bar(212,100,308,132);
						   bar(212,300,308,332);
						   bar(452,100,548,132);
						   bar(452,300,548,332);
						   setcolor(BLUE);
						   rectangle(212,100,308,132);
						   rectangle(212,300,308,332);
						   rectangle(452,100,548,132);
						   rectangle(452,300,548,332);
						   puthz(212,100,c2,32,32,BLUE);
						   puthz(212,300,c3,32,32,BLUE);
						   puthz(452,100,c5,32,32,BLUE);
						   puthz(452,300,c6,32,32,BLUE);
						   setfillstyle(1,LIGHTCYAN);
						   bar(308,140,452,290);
						   setcolor(BLUE);
						   rectangle(340,210,372,242);
						   rectangle(390,210,422,242);
						   puthz(350,160,"交换",32,32,BLUE);
						   puthz(340,210,"是",32,32,BLUE);
						   puthz(390,210,"否",32,32,BLUE);
						   while(bool)
								{
								  Newxy();
								  if(Mouse_press(390,210,422,242))
									{
									   NewBK();
									   setcolor(BLUE);
									   circle(330,116,10);
									   circle(430,116,10);
									   setfillstyle(1,GREEN);
									   floodfill(330,116,BLUE);
									   floodfill(430,116,BLUE);
									   bar(308,140,452,290);
									   change1=0;
									   change3=0;
									   bool=0;
									}
								  if(Mouse_press(340,210,372,242))
									{
									   NewBK();
									   setcolor(BLUE);
									   circle(330,116,10);
									   circle(430,116,10);
									   setfillstyle(1,GREEN);
									   floodfill(330,116,BLUE);
									   floodfill(430,116,BLUE);
									   bar(308,140,452,290);

									   for(i=1;i<11;i++)
										  {
											if(strcmp(c2,s1[i])==0)
											break;
										  }
									   for(j=1;j<11;j++)
										  {
											if(strcmp(c5,s2[j])==0)
											break;
										  }
									   if((fp1=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
										 {
										   setlinestyle(0,0,1);
										   outtextxy(300,300,"cannot open the file");
										   exit(1);
										 }
									   fseek(fp1,13+37*(i-1),0);
									   for(k=0;k<36;k++)
										  {
											ch=fgetc(fp1);
											a1[k]=ch;
										  }
									   fclose(fp1);
									   switch(path-48)
											 {
											   case 1:   if((fp2=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
														   {
															 setlinestyle(0,0,1);
															 outtextxy(300,300,"cannot open the file");
															 exit(1);
														   }
														 break;
											   case 2:  if((fp2=fopen("c:\\mycode\\shop\\2.txt","r+"))==NULL)
														  {
															 setlinestyle(0,0,1);
															 outtextxy(300,300,"cannot open the file");
															 exit(1);
														  }
														 break;
											   case 3:  if((fp2=fopen("c:\\mycode\\shop\\3.txt","r+"))==NULL)
														  {
															setlinestyle(0,0,1);
															outtextxy(300,300,"cannot open the file");
															exit(1);
														  }
														 break;
											   case 4: if((fp2=fopen("c:\\mycode\\shop\\4.txt","r+"))==NULL)
														 {
															  setlinestyle(0,0,1);
															  outtextxy(300,300,"cannot open the file");
															  exit(1);
														  }
														break;
											   case 5: if((fp2=fopen("c:\\mycode\\shop\\5.txt","r+"))==NULL)
														 {
															setlinestyle(0,0,1);
															outtextxy(300,300,"cannot open the file");
															exit(1);
														 }
														break;
									   }
									   fseek(fp2,13+37*(j-1),0);
									   for(k=0;k<36;k++)
										  {
											ch=fgetc(fp2);
											a2[k]=ch;
										  }

									   fseek(fp2,13+37*(j-1),0);
									   for(k=0;k<36;k++)
										  {
											ch=a1[k];
											fputc(ch,fp2);
										  }

									   fseek(fp2,13+37*(j-1),0);
									   length=fgetc(fp2);
									   for(k=0;k<10;k++)
										  {
											ch=fgetc(fp2);
											s2[j][k]=ch;
										  }
									   s2[j][2*(length-48)]='\0';
									   for(k=1;k<11;k++)
										  {
											fseek(fp2,13+37*(k-1)+26,0);
											ch=fgetc(fp2);
											money2[k-1][0]=ch;
											ch=fgetc(fp2);
											money2[k-1][1]=ch;
											ch=fgetc(fp2);
											money2[k-1][2]=ch;
											ch=fgetc(fp2);
											money2[k-1][3]=ch;
										  }
									   fclose(fp2);
									   if((fp1=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
										 {
										   setlinestyle(0,0,1);
										   outtextxy(300,300,"cannot open the file");
										   exit(1);
										 }
									   fseek(fp1,13+37*(i-1),0);
									   for(k=0;k<36;k++)
										  {
											ch=a2[k];
											fputc(ch,fp1);
										  }
									   fseek(fp1,13+37*(i-1),0);
									   length=fgetc(fp1);
									   for(k=0;k<10;k++)
										  {
											ch=fgetc(fp1);
											s1[i][k]=ch;
										  }
									   s1[i][2*(length-48)]='\0';
									   for(k=1;k<11;k++)
										  {
											fseek(fp1,13+37*(k-1)+26,0);
											ch=fgetc(fp1);
											money1[k-1][0]=ch;
											ch=fgetc(fp1);
											money1[k-1][1]=ch;
											ch=fgetc(fp1);
											money1[k-1][2]=ch;
											ch=fgetc(fp1);
											money1[k-1][3]=ch;
										  }
									   fclose(fp1);
									   c2=s1[i];
									   c5=s2[j];
									   amount1=(money2[(choose-1)*2][0]-48)*1000+(money2[(choose-1)*2][1]-48)*100+(money2[(choose-1)*2][2]-48)*10+(money2[(choose-1)*2][3]-48)*1;
									   amount2=(money1[(choose-1)*2][0]-48)*1000+(money1[(choose-1)*2][1]-48)*100+(money1[(choose-1)*2][2]-48)*10+(money1[(choose-1)*2][3]-48)*1;
									   damount=amount1-amount2;
									   amount=(money[0]-48)*1000+(money[1]-48)*100+(money[2]-48)*10+(money[3]-48)*1;
									   amount+=damount;
									   for(i=0;i<4;i++)
										  {
											money[3-i]=amount%10+48;
											amount=amount/10;
										  }
									   if((fp=fopen("c:\\mycode\\shop\\money.txt","r+"))==NULL)
										  {
											setlinestyle(0,0,1);
											outtextxy(300,300,"cannot open the file");
											exit(1);
										  }
									   for(i=0;i<4;i++)
										  {
											  ch=money[i];
											  fputc(ch,fp);
										   }
									   fclose(fp);
									   setfillstyle(1,GREEN);
									   setcolor(BLUE);
									   bar(150,113,198,125);
									   bar(150,313,198,325);
									   bar(565,113,613,125);
									   bar(565,313,613,325);
									   bar(90,60,138,72);
									   for(i=0;i<4;i++)
										  {
											draw_num(90+i*12,60,money[i]-48,6);
										  }
									   for(i=0;i<4;i++)
										  {
											 draw_num(150+i*12,113,money1[(choose-1)*2][i]-48,6);
										  }
									   for(i=0;i<4;i++)
										  {
											 draw_num(150+i*12,313,money1[(choose-1)*2+1][i]-48,6);
										  }
									   for(i=0;i<4;i++)
										  {
											draw_num(565+i*12,113,money2[(choose-1)*2][i]-48,6);
										  }
									   for(i=0;i<4;i++)
										  {
											 draw_num(565+i*12,313,money2[(choose-1)*2+1][i]-48,6);
										  }

									   setfillstyle(1,GREEN);
									   bar(212,100,308,132);
									   bar(452,100,548,132);
									   setcolor(BLUE);
									   rectangle(212,100,308,132);
									   rectangle(452,100,548,132);
									   puthz(212,100,c2,32,32,BLUE);
									   puthz(452,100,c5,32,32,BLUE);

									   change1=0;
									   change3=0;
									   bool=0;
									}

								}

				}
			  if(Mouse_press(420,306,440,326))
				{
				  delay(100);
				  switch(change4)
						{
						  case 0:
								 if(change3==0)
								   {
									 NewBK();
									 setfillstyle(1,GREEN);
									 setcolor(BLUE);
									 bar(420,306,450,341);
									 circle(430,316,10);
									 setfillstyle(1,CYAN);
									 floodfill(430,316,BLUE);
									 change4=1;
								   }
									 break;
						  case 1:
									NewBK();
									setfillstyle(1,GREEN);
									setcolor(BLUE);
									bar(420,306,450,341);
									circle(430,316,10);
									setfillstyle(1,GREEN);
									floodfill(430,316,BLUE);
									change4=0;
									break;

						}

				}
			  if(Mouse_press(420,106,440,126))
				{
				  delay(100);
				  switch(change3)
						{
						  case 0:
								 if(change4==0)
								   {
									 NewBK();
									 setfillstyle(1,GREEN);
									 setcolor(BLUE);
									 bar(420,106,450,141);
									 circle(430,116,10);
									 setfillstyle(1,CYAN);
									 floodfill(430,116,BLUE);
									 change3=1;
								   }
									 break;
						  case 1:
									NewBK();
									setfillstyle(1,GREEN);
									setcolor(BLUE);
									bar(420,106,450,141);
									circle(430,116,10);
									setfillstyle(1,GREEN);
									floodfill(430,116,BLUE);
									change3=0;
									break;

						}

				}
				if(Mouse_press(320,306,340,326))
				{
				  delay(100);
				  switch(change2)
						{
						  case 0:
								 if(change1==0)
								   {
									 NewBK();
									 setfillstyle(1,GREEN);
									 setcolor(BLUE);
									 bar(320,306,350,341);
									 circle(330,316,10);
									 setfillstyle(1,CYAN);
									 floodfill(330,316,BLUE);
									 change2=1;
								   }
									 break;
						  case 1:
									NewBK();
									setfillstyle(1,GREEN);
									setcolor(BLUE);
									bar(320,306,350,341);
									circle(330,316,10);
									setfillstyle(1,GREEN);
									floodfill(330,316,BLUE);
									change2=0;
									break;

						}

				}
			  if(Mouse_press(320,106,340,126))
				{
				  delay(100);
				  switch(change1)
						{
						  case 0:
								 if(change2==0)
								   {
									 NewBK();
									 setfillstyle(1,GREEN);
									 setcolor(BLUE);
									 bar(320,106,350,141);
									 circle(330,116,10);
									 setfillstyle(1,CYAN);
									 floodfill(330,116,BLUE);
									 change1=1;
								   }
									 break;
						  case 1:
									NewBK();
									setfillstyle(1,GREEN);
									setcolor(BLUE);
									bar(320,106,350,141);
									circle(330,116,10);
									setfillstyle(1,GREEN);
									floodfill(330,116,BLUE);
									change1=0;
									break;

						}

				}




			  if(Mouse_press(452,300,548,332))
				{
				 delay(100);
				switch(color4)
				  {
					case 0:
							NewBK();
							setfillstyle(1,GREEN);
							setcolor(BLUE);
							bar(452,300,558,347);
							setfillstyle(1,YELLOW);
							bar(452,300,548,332);
							rectangle(452,300,548,332);
							puthz(452,300,c6,32,32,BLUE);


							bar(380,340,609,490);
							rectangle(380,340,609,490);
							puthz(414,340,"速度",32,32,BLUE);
							puthz(414,372,"力量",32,32,BLUE);
							puthz(414,404,"断球",32,32,BLUE);
							puthz(414,436,"抢球",32,32,BLUE);
							puthz(429,468,"CD",16,16,BLUE);

							for(i=1;i<11;i++)
							   {
								  if(strcmp(c6,s2[i])==0)
								  break;
							   }

							switch(path-48)
								  {
									 case 1:   if((fp2=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
												 {
													setlinestyle(0,0,1);
													outtextxy(300,300,"cannot open the file");
													exit(1);
												 }
											   break;
									 case 2:  if((fp2=fopen("c:\\mycode\\shop\\2.txt","r+"))==NULL)
												{
													setlinestyle(0,0,1);
													outtextxy(300,300,"cannot open the file");
													exit(1);
												}
											  break;
									 case 3:  if((fp2=fopen("c:\\mycode\\shop\\3.txt","r+"))==NULL)
												{
												  setlinestyle(0,0,1);
												  outtextxy(300,300,"cannot open the file");
												  exit(1);
												}
											  break;
									 case 4: if((fp2=fopen("c:\\mycode\\shop\\4.txt","r+"))==NULL)
											   {
												   setlinestyle(0,0,1);
												   outtextxy(300,300,"cannot open the file");
												   exit(1);
											   }
											   break;
									 case 5: if((fp2=fopen("c:\\mycode\\shop\\5.txt","r+"))==NULL)
											   {
												 setlinestyle(0,0,1);
												 outtextxy(300,300,"cannot open the file");
												 exit(1);
											   }
											   break;
								}
							fseek(fp2,13+37*(i-1)+11,0);
							for(j=0;j<5;j++)
							   {
								 for(i=0;i<3;i++)
									{
									  ch=fgetc(fp2);
									  ability4[j][i]=ch;
									}
								 ability4[j][i]='\0';

							   }
						   fclose(fp2);
						   for(j=0;j<5;j++)
						   for(i=0;i<3;i++)
							  {
								ability=ability4[j][i]-48;
								if(j<4)
								draw_num(499+i*15,350+j*32,ability,6);
								else draw_num(499+i*15,350+j*32-10,ability,5);
							  }
						   color4=1;
						   break;
					case 1:
							NewBK();
							setfillstyle(1,GREEN);
							setcolor(BLUE);
							bar(452,300,558,347);
							bar(380,340,609,490);
							rectangle(452,300,548,332);
							puthz(452,300,c6,32,32,BLUE);
							color4=0;
							break;
				  }
		  }

		   if(Mouse_press(452,100,548,132))
			 {
			   delay(100);
			switch(color3)
				  {
					case 0:
							NewBK();
							setfillstyle(1,GREEN);
							setcolor(BLUE);
							bar(452,100,558,147);
							setfillstyle(1,YELLOW);
							bar(452,100,548,132);
							rectangle(452,100,548,132);
							puthz(452,100,c5,32,32,BLUE);


							bar(380,140,609,290);
							rectangle(380,140,609,290);
							puthz(414,140,"速度",32,32,BLUE);
							puthz(414,172,"力量",32,32,BLUE);
							puthz(414,204,"断球",32,32,BLUE);
							puthz(414,236,"抢球",32,32,BLUE);
							puthz(429,275,"CD",16,16,BLUE);

							for(i=1;i<11;i++)
							   {
								  if(strcmp(c5,s2[i])==0)
								  break;
							   }

							switch(path-48)
								  {
									 case 1:   if((fp2=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
												 {
													setlinestyle(0,0,1);
													outtextxy(300,300,"cannot open the file");
													exit(1);
												 }
											   break;
									 case 2:  if((fp2=fopen("c:\\mycode\\shop\\2.txt","r+"))==NULL)
												{
													setlinestyle(0,0,1);
													outtextxy(300,300,"cannot open the file");
													exit(1);
												}
											  break;
									 case 3:  if((fp2=fopen("c:\\mycode\\shop\\3.txt","r+"))==NULL)
												{
												  setlinestyle(0,0,1);
												  outtextxy(300,300,"cannot open the file");
												  exit(1);
												}
											  break;
									 case 4: if((fp2=fopen("c:\\mycode\\shop\\4.txt","r+"))==NULL)
											   {
												   setlinestyle(0,0,1);
												   outtextxy(300,300,"cannot open the file");
												   exit(1);
											   }
											   break;
									 case 5: if((fp2=fopen("c:\\mycode\\shop\\5.txt","r+"))==NULL)
											   {
												 setlinestyle(0,0,1);
												 outtextxy(300,300,"cannot open the file");
												 exit(1);
											   }
											   break;
								}
							fseek(fp2,13+37*(i-1)+11,0);
							for(j=0;j<5;j++)
							   {
								 for(i=0;i<3;i++)
									{
									  ch=fgetc(fp2);
									  ability3[j][i]=ch;
									}
								 ability3[j][i]='\0';

							   }
						   fclose(fp2);
						   for(j=0;j<5;j++)
						   for(i=0;i<3;i++)
							  {
								ability=ability3[j][i]-48;
								if(j<4)
								draw_num(499+i*15,150+j*32,ability,6);
								else draw_num(499+i*15,150+j*32-5,ability,6);
							  }
						   color3=1;
						   break;
					case 1:
							NewBK();
							setfillstyle(1,GREEN);
							setcolor(BLUE);
							bar(452,100,558,147);
							bar(380,140,609,290);
							rectangle(452,100,548,132);
							puthz(452,100,c5,32,32,BLUE);
							color3=0;
							break;
				  }
		  }

		if(Mouse_press(212,300,308,332))
		  {
			delay(100);
			switch(color2)
				  {
					case 0:
							NewBK();
							setfillstyle(1,GREEN);
							setcolor(BLUE);
							bar(212,300,318,347);
							setfillstyle(1,YELLOW);
							bar(212,300,308,332);
							rectangle(212,300,308,332);
							puthz(212,300,c3,32,32,BLUE);
							bar(136,340,365,479);
							rectangle(136,340,365,479);
							puthz(170,340,"速度",32,32,BLUE);
							puthz(170,372,"力量",32,32,BLUE);
							puthz(170,404,"断球",32,32,BLUE);
							puthz(170,436,"抢球",32,32,BLUE);
							puthz(185,468,"CD",16,16,BLUE);

							for(i=1;i<11;i++)
							   {
								  if(strcmp(c3,s1[i])==0)
								  break;
							   }
							if((fp1=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
							  {
								setlinestyle(0,0,1);
								outtextxy(300,300,"cannot open the file");
								exit(1);
							  }
							fseek(fp1,13+37*(i-1)+11,0);
							for(j=0;j<5;j++)
							   {
								 for(i=0;i<3;i++)
									{
									  ch=fgetc(fp1);
									  ability2[j][i]=ch;
									}
								 ability2[j][i]='\0';

							   }
						   fclose(fp1);
						   for(j=0;j<5;j++)
						   for(i=0;i<3;i++)
							  {
								ability=ability2[j][i]-48;
								if(j<4)
								draw_num(250+i*15,350+j*32,ability,6);
								else draw_num(250+i*15,350+j*32-10,ability,5);
							  }
						   color2=1;
						   break;
					case 1:
							NewBK();
							setfillstyle(1,GREEN);
							setcolor(BLUE);
							bar(212,300,318,347);
							bar(136,340,365,490);
							rectangle(212,300,308,332);
							puthz(212,300,c3,32,32,BLUE);
							color2=0;
							break;
				  }
		  }

		if(Mouse_press(212,100,308,132))
		  {
			delay(100);
			switch(color1)
				  {
					case 0:
							NewBK();
							setfillstyle(1,GREEN);
							setcolor(BLUE);
							bar(212,100,318,147);
							setfillstyle(1,YELLOW);
							bar(212,100,308,132);
							rectangle(212,100,308,132);
							puthz(212,100,c2,32,32,BLUE);


							bar(136,140,365,290);
							rectangle(136,140,365,290);
							puthz(170,140,"速度",32,32,BLUE);
							puthz(170,172,"力量",32,32,BLUE);
							puthz(170,204,"断球",32,32,BLUE);
							puthz(170,236,"抢球",32,32,BLUE);
							puthz(185,275,"CD",16,16,BLUE);

							for(i=1;i<11;i++)
							   {
								  if(strcmp(c2,s1[i])==0)
								  break;
							   }
							if((fp1=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
							  {
								setlinestyle(0,0,1);
								outtextxy(300,300,"cannot open the file");
								exit(1);
							  }
							fseek(fp1,13+37*(i-1)+11,0);
							for(j=0;j<5;j++)
							   {
								 for(i=0;i<3;i++)
									{
									  ch=fgetc(fp1);
									  ability1[j][i]=ch;
									}
								 ability1[j][i]='\0';

							   }
						   fclose(fp1);
						   for(j=0;j<5;j++)
						   for(i=0;i<3;i++)
							  {
								ability=ability1[j][i]-48;
								if(j<4)
								draw_num(250+i*15,150+j*32,ability,6);
								else draw_num(250+i*15,150+j*32-5,ability,6);
							  }
						   color1=1;
						   break;
					case 1:
							NewBK();
							setfillstyle(1,GREEN);
							setcolor(BLUE);
							bar(212,100,318,147);
							bar(136,140,365,290);
							rectangle(212,100,308,132);
							puthz(212,100,c2,32,32,BLUE);
							color1=0;
							break;
				  }
		  }

		   if(Mouse_press(400,50,410,82))
			 {
			   color1=0;
			   color2=0;
			   color3=0;
			   color4=0;

			   setfillstyle(1,GREEN);
			   bar(136,140,365,290);
			   bar(136,340,365,490);
			   bar(380,140,609,290);
			   bar(380,340,609,490);

			   switch(path_)
					 {

					   case 1: path-=1;
							   if(path-48==1)
								 {
									path=53;
								 }
							   break;
					   case 2: path-=1;
							   switch(path-48)
									 {
									   case 2:  path=49;
												break;
									   case 0:  path=53;
												break;
									 }
							   break;
					   case 3: path-=1;
							   switch(path-48)
									 {
									   case 3: path=50;
											   break;
									   case 0: path=53;
											   break;
									 }
							   break;
					   case 4: path-=1;
							   switch(path-48)
									 {
									   case 4: path=51;
											   break;
									   case 0: path=53;
											   break;
									 }
							   break;
						case 5: path-=1;
							   switch(path-48)
									 {
									   case 0: path=52;
											   break;
									 }
							   break;

					 }

			   switch(path-48)
					 {
						case 1:   if((fp2=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
									{
									  setlinestyle(0,0,1);
									  outtextxy(300,300,"cannot open the file");
									  exit(1);
									}
								  break;
					   case 2:  if((fp2=fopen("c:\\mycode\\shop\\2.txt","r+"))==NULL)
								  {
									setlinestyle(0,0,1);
									outtextxy(300,300,"cannot open the file");
									exit(1);
								  }
								 break;
					   case 3:  if((fp2=fopen("c:\\mycode\\shop\\3.txt","r+"))==NULL)
								  {
									  setlinestyle(0,0,1);
									  outtextxy(300,300,"cannot open the file");
									  exit(1);
								  }
								  break;
					   case 4: if((fp2=fopen("c:\\mycode\\shop\\4.txt","r+"))==NULL)
								 {
								   setlinestyle(0,0,1);
								   outtextxy(300,300,"cannot open the file");
								   exit(1);
								 }
							   break;
					 case 5: if((fp2=fopen("c:\\mycode\\shop\\5.txt","r+"))==NULL)
							   {
								  setlinestyle(0,0,1);
								  outtextxy(300,300,"cannot open the file");
								  exit(1);
							   }
							 break;
					 }
			   length=fgetc(fp2);
			   for(i=0;i<10;i++)
				  {
				   ch=fgetc(fp2);
				   s2[0][i]=ch;
				  }
			   s2[0][2*(length-48)]='\0';
			   ch=fgetc(fp2);

			   for(j=1;j<11;j++)
				  {
					length=fgetc(fp2);
					for(i=0;i<10;i++)
					   {
						   ch=fgetc(fp2);
						   s2[j][i]=ch;
					   }
				   s2[j][2*(length-48)]='\0';
				   if(j<10)
				   fseek(fp2,26,1);

				  }
			   fclose(fp2);
			   switch(choose)
					 {
						 case 1:   c4=s2[0];
								   c5=s2[1];
								   c6=s2[2];
								   setfillstyle(1,GREEN);
								   setcolor(BLUE);
								   bar(180,50,340,82);
								   rectangle(180,50,340,82);
								   puthz(195,50,c1,32,32,BLUE);
								   bar(212,100,308,132);
								   rectangle(212,100,308,132);
								   puthz(212,100,c2,32,32,BLUE);
								   bar(212,300,308,332);
								   rectangle(212,300,308,332);
								   puthz(212,300,c3,32,32,BLUE);
								   bar(420,50,580,82);
								   rectangle(420,50,580,82);
								   puthz(435,50,c4,32,32,BLUE);
								   bar(452,100,548,132);
								   rectangle(452,100,548,132);
								   puthz(452,100,c5,32,32,BLUE);
								   bar(452,300,548,332);
								   rectangle(452,300,548,332);
								   puthz(452,300,c6,32,32,BLUE);
								   break;

						 case 2:   c4=s2[0];
								   c5=s2[3];
								   c6=s2[4];
								   setfillstyle(1,GREEN);
								   setcolor(BLUE);
								   bar(180,50,340,82);
								   rectangle(180,50,340,82);
								   puthz(195,50,c1,32,32,BLUE);
								   bar(212,100,308,132);
								   rectangle(212,100,308,132);
								   puthz(212,100,c2,32,32,BLUE);
								   bar(212,300,308,332);
								   rectangle(212,300,308,332);
								   puthz(212,300,c3,32,32,BLUE);
								   bar(420,50,580,82);
								   rectangle(420,50,580,82);
								   puthz(435,50,c4,32,32,BLUE);
								   bar(452,100,548,132);
								   rectangle(452,100,548,132);
								   puthz(452,100,c5,32,32,BLUE);
								   bar(452,300,548,332);
								   rectangle(452,300,548,332);
								   puthz(452,300,c6,32,32,BLUE);
								   break;

						 case 3:   c4=s2[0];
								   c5=s2[5];
								   c6=s2[6];
								   setfillstyle(1,GREEN);
								   setcolor(BLUE);
								   bar(180,50,340,82);
								   rectangle(180,50,340,82);
								   puthz(195,50,c1,32,32,BLUE);
								   bar(212,100,308,132);
								   rectangle(212,100,308,132);
								   puthz(212,100,c2,32,32,BLUE);
								   bar(212,300,308,332);
								   rectangle(212,300,308,332);
								   puthz(212,300,c3,32,32,BLUE);
								   bar(420,50,580,82);
								   rectangle(420,50,580,82);
								   puthz(435,50,c4,32,32,BLUE);
								   bar(452,100,548,132);
								   rectangle(452,100,548,132);
								   puthz(452,100,c5,32,32,BLUE);
								   bar(452,300,548,332);
								   rectangle(452,300,548,332);
								   puthz(452,300,c6,32,32,BLUE);
								   break;

						 case 4:   c4=s2[0];
								   c5=s2[7];
								   c6=s2[8];
								   setfillstyle(1,GREEN);
								   setcolor(BLUE);
								   bar(180,50,340,82);
								   rectangle(180,50,340,82);
								   puthz(195,50,c1,32,32,BLUE);
								   bar(212,100,308,132);
								   rectangle(212,100,308,132);
								   puthz(212,100,c2,32,32,BLUE);
								   bar(212,300,308,332);
								   rectangle(212,300,308,332);
								   puthz(212,300,c3,32,32,BLUE);
								   bar(420,50,580,82);
								   rectangle(420,50,580,82);
								   puthz(435,50,c4,32,32,BLUE);
								   bar(452,100,548,132);
								   rectangle(452,100,548,132);
								   puthz(452,100,c5,32,32,BLUE);
								   bar(452,300,548,332);
								   rectangle(452,300,548,332);
								   puthz(452,300,c6,32,32,BLUE);
								   break;

						 case 5:   c4=s2[0];
								   c5=s2[9];
								   c6=s2[10];
								   setfillstyle(1,GREEN);
								   setcolor(BLUE);
								   bar(180,50,340,82);
								   rectangle(180,50,340,82);
								   puthz(195,50,c1,32,32,BLUE);
								   bar(212,100,308,132);
								   rectangle(212,100,308,132);
								   puthz(212,100,c2,32,32,BLUE);
								   bar(212,300,308,332);
								   rectangle(212,300,308,332);
								   puthz(212,300,c3,32,32,BLUE);
								   bar(420,50,580,82);
								   rectangle(420,50,580,82);
								   puthz(435,50,c4,32,32,BLUE);
								   bar(452,100,548,132);
								   rectangle(452,100,548,132);
								   puthz(452,100,c5,32,32,BLUE);
								   bar(452,300,548,332);
								   rectangle(452,300,548,332);
								   puthz(452,300,c6,32,32,BLUE);
								   break;
					 }

			   if((fp=fopen("c:\\mycode\\shop\\path.txt","r+"))==NULL)
				 {
					setlinestyle(0,0,1);
					outtextxy(300,300,"cannot open the file");
					exit(1);
				 }
			   fputc(path,fp);
			   fclose(fp);

			 }

		   if(Mouse_press(590,50,600,82))
			 {
			   color1=0;
			   color2=0;
			   color3=0;
			   color4=0;
			   setfillstyle(1,GREEN);
			   bar(136,140,365,290);
			   bar(136,340,365,490);
			   bar(380,140,609,290);
			   bar(380,340,609,490);

			   switch(path_)
					 {

					   case 1: path+=1;
							   switch(path-48)
									 {
									   case 6: path=50;
											   break;
									 }
							   break;
					   case 2: path+=1;
							   switch(path-48)
									 {
									   case 2: path=51;
											   break;
									   case 6: path=49;
											   break;
									 }
							   break;
					   case 3:  path+=1;
							   switch(path-48)
									 {
									   case 3: path=52;
											   break;
									   case 6: path=49;
											   break;
									 }
							   break;
					   case 4:  path+=1;
							   switch(path-48)
									 {
									   case 4: path=53;
											   break;
									   case 6: path=49;
											   break;
									 }
							   break;
						case 5:  path+=1;
							   switch(path-48)
									 {
									   case 5: path=49;
											   break;

									 }
							   break;

					 }

			   switch(path-48)
					 {
						case 1:   if((fp2=fopen("c:\\mycode\\shop\\1.txt","r+"))==NULL)
									{
									  setlinestyle(0,0,1);
									  outtextxy(300,300,"cannot open the file");
									  exit(1);
									}
								  break;
					   case 2:  if((fp2=fopen("c:\\mycode\\shop\\2.txt","r+"))==NULL)
								  {
									setlinestyle(0,0,1);
									outtextxy(300,300,"cannot open the file");
									exit(1);
								  }
								 break;
					   case 3:  if((fp2=fopen("c:\\mycode\\shop\\3.txt","r+"))==NULL)
								  {
									  setlinestyle(0,0,1);
									  outtextxy(300,300,"cannot open the file");
									  exit(1);
								  }
								  break;
					   case 4: if((fp2=fopen("c:\\mycode\\shop\\4.txt","r+"))==NULL)
								 {
								   setlinestyle(0,0,1);
								   outtextxy(300,300,"cannot open the file");
								   exit(1);
								 }
							   break;
					 case 5: if((fp2=fopen("c:\\mycode\\shop\\5.txt","r+"))==NULL)
							   {
								  setlinestyle(0,0,1);
								  outtextxy(300,300,"cannot open the file");
								  exit(1);
							   }
							 break;
					 }
			   length=fgetc(fp2);
			   for(i=0;i<10;i++)
				  {
				   ch=fgetc(fp2);
				   s2[0][i]=ch;
				  }
			   s2[0][2*(length-48)]='\0';
			   ch=fgetc(fp2);

			   for(j=1;j<11;j++)
				  {
					length=fgetc(fp2);
					for(i=0;i<10;i++)
					   {
						   ch=fgetc(fp2);
						   s2[j][i]=ch;
					   }
				   s2[j][2*(length-48)]='\0';
				   if(j<10)
				   fseek(fp2,26,1);

				  }
			   fclose(fp2);
			   switch(choose)
					 {
						 case 1:   c4=s2[0];
								   c5=s2[1];
								   c6=s2[2];
								   setfillstyle(1,GREEN);
								   setcolor(BLUE);
								   bar(180,50,340,82);
								   rectangle(180,50,340,82);
								   puthz(195,50,c1,32,32,BLUE);
								   bar(212,100,308,132);
								   rectangle(212,100,308,132);
								   puthz(212,100,c2,32,32,BLUE);
								   bar(212,300,308,332);
								   rectangle(212,300,308,332);
								   puthz(212,300,c3,32,32,BLUE);
								   bar(420,50,580,82);
								   rectangle(420,50,580,82);
								   puthz(435,50,c4,32,32,BLUE);
								   bar(452,100,548,132);
								   rectangle(452,100,548,132);
								   puthz(452,100,c5,32,32,BLUE);
								   bar(452,300,548,332);
								   rectangle(452,300,548,332);
								   puthz(452,300,c6,32,32,BLUE);
								   break;

						 case 2:   c4=s2[0];
								   c5=s2[3];
								   c6=s2[4];
								   setfillstyle(1,GREEN);
								   setcolor(BLUE);
								   bar(180,50,340,82);
								   rectangle(180,50,340,82);
								   puthz(195,50,c1,32,32,BLUE);
								   bar(212,100,308,132);
								   rectangle(212,100,308,132);
								   puthz(212,100,c2,32,32,BLUE);
								   bar(212,300,308,332);
								   rectangle(212,300,308,332);
								   puthz(212,300,c3,32,32,BLUE);
								   bar(420,50,580,82);
								   rectangle(420,50,580,82);
								   puthz(435,50,c4,32,32,BLUE);
								   bar(452,100,548,132);
								   rectangle(452,100,548,132);
								   puthz(452,100,c5,32,32,BLUE);
								   bar(452,300,548,332);
								   rectangle(452,300,548,332);
								   puthz(452,300,c6,32,32,BLUE);
								   break;

						 case 3:   c4=s2[0];
								   c5=s2[5];
								   c6=s2[6];
								   setfillstyle(1,GREEN);
								   setcolor(BLUE);
								   bar(180,50,340,82);
								   rectangle(180,50,340,82);
								   puthz(195,50,c1,32,32,BLUE);
								   bar(212,100,308,132);
								   rectangle(212,100,308,132);
								   puthz(212,100,c2,32,32,BLUE);
								   bar(212,300,308,332);
								   rectangle(212,300,308,332);
								   puthz(212,300,c3,32,32,BLUE);
								   bar(420,50,580,82);
								   rectangle(420,50,580,82);
								   puthz(435,50,c4,32,32,BLUE);
								   bar(452,100,548,132);
								   rectangle(452,100,548,132);
								   puthz(452,100,c5,32,32,BLUE);
								   bar(452,300,548,332);
								   rectangle(452,300,548,332);
								   puthz(452,300,c6,32,32,BLUE);
								   break;

						 case 4:   c4=s2[0];
								   c5=s2[7];
								   c6=s2[8];
								   setfillstyle(1,GREEN);
								   setcolor(BLUE);
								   bar(180,50,340,82);
								   rectangle(180,50,340,82);
								   puthz(195,50,c1,32,32,BLUE);
								   bar(212,100,308,132);
								   rectangle(212,100,308,132);
								   puthz(212,100,c2,32,32,BLUE);
								   bar(212,300,308,332);
								   rectangle(212,300,308,332);
								   puthz(212,300,c3,32,32,BLUE);
								   bar(420,50,580,82);
								   rectangle(420,50,580,82);
								   puthz(435,50,c4,32,32,BLUE);
								   bar(452,100,548,132);
								   rectangle(452,100,548,132);
								   puthz(452,100,c5,32,32,BLUE);
								   bar(452,300,548,332);
								   rectangle(452,300,548,332);
								   puthz(452,300,c6,32,32,BLUE);
								   break;

						 case 5:   c4=s2[0];
								   c5=s2[9];
								   c6=s2[10];
								   setfillstyle(1,GREEN);
								   setcolor(BLUE);
								   bar(180,50,340,82);
								   rectangle(180,50,340,82);
								   puthz(195,50,c1,32,32,BLUE);
								   bar(212,100,308,132);
								   rectangle(212,100,308,132);
								   puthz(212,100,c2,32,32,BLUE);
								   bar(212,300,308,332);
								   rectangle(212,300,308,332);
								   puthz(212,300,c3,32,32,BLUE);
								   bar(420,50,580,82);
								   rectangle(420,50,580,82);
								   puthz(435,50,c4,32,32,BLUE);
								   bar(452,100,548,132);
								   rectangle(452,100,548,132);
								   puthz(452,100,c5,32,32,BLUE);
								   bar(452,300,548,332);
								   rectangle(452,300,548,332);
								   puthz(452,300,c6,32,32,BLUE);
								   break;
					 }

			   if((fp=fopen("c:\\mycode\\shop\\path.txt","r+"))==NULL)
				 {
					setlinestyle(0,0,1);
					outtextxy(300,300,"cannot open the file");
					exit(1);
				 }
			   fputc(path,fp);
			   fclose(fp);
		   }

		   if(Mouse_press(30,100,126,132))
			 {
				 color1=0;
				 color2=0;
				 color3=0;
				 color4=0;
				 choose=1;
				 c2=s1[1];
				 c3=s1[2];
				 c5=s2[1];
				 c6=s2[2];
				 setfillstyle(1,GREEN);
				 setcolor(BLUE);
				 bar(150,113,198,125);
				 bar(150,313,198,325);
				 bar(565,113,613,125);
				 bar(565,313,613,325);
				 for(i=0;i<4;i++)
	  {
		draw_num(150+i*12,113,money1[0][i]-48,6);
	  }
   for(i=0;i<4;i++)
	  {
		draw_num(150+i*12,313,money1[1][i]-48,6);
	  }
   for(i=0;i<4;i++)
	  {
		draw_num(565+i*12,113,money2[0][i]-48,6);
	  }
   for(i=0;i<4;i++)
	  {
		draw_num(565+i*12,313,money2[1][i]-48,6);
	  }

				 bar(1,100,21,132);
				 bar(1,150,21,182);
				 bar(1,200,21,232);
				 bar(1,250,21,282);
				 bar(1,300,21,332);
				 line(1,116,11,132);
				 line(11,132,21,100);

				 bar(136,140,365,290);
				 bar(136,340,365,490);
				 bar(380,140,609,290);
				 bar(380,340,609,490);

				 bar(180,50,340,82);
				 rectangle(180,50,340,82);
				 puthz(195,50,c1,32,32,BLUE);
				 bar(212,100,308,132);
				 rectangle(212,100,308,132);
				 puthz(212,100,c2,32,32,BLUE);
				 bar(212,300,308,332);
				 rectangle(212,300,308,332);
				 puthz(212,300,c3,32,32,BLUE);
				 bar(420,50,580,82);
				 rectangle(420,50,580,82);
				 puthz(435,50,c4,32,32,BLUE);
				 bar(452,100,548,132);
				 rectangle(452,100,548,132);
				 puthz(452,100,c5,32,32,BLUE);
				 bar(452,300,548,332);
				 rectangle(452,300,548,332);
				 puthz(452,300,c6,32,32,BLUE);

			 }
		   if(Mouse_press(30,150,126,182))
			 {
				 color1=0;
				 color2=0;
				 color3=0;
				 color4=0;
				 choose=2;
				 c2=s1[3];
				 c3=s1[4];
				 c5=s2[3];
				 c6=s2[4];
				 setfillstyle(1,GREEN);
				 setcolor(BLUE);
				 bar(150,113,198,125);
				 bar(150,313,198,325);
				 bar(565,113,613,125);
				 bar(565,313,613,325);
				 for(i=0;i<4;i++)
	  {
		draw_num(150+i*12,113,money1[2][i]-48,6);
	  }
   for(i=0;i<4;i++)
	  {
		draw_num(150+i*12,313,money1[3][i]-48,6);
	  }
   for(i=0;i<4;i++)
	  {
		draw_num(565+i*12,113,money2[2][i]-48,6);
	  }
   for(i=0;i<4;i++)
	  {
		draw_num(565+i*12,313,money2[3][i]-48,6);
	  }

				 bar(1,100,21,132);
				 bar(1,150,21,182);
				 bar(1,200,21,232);
				 bar(1,250,21,282);
				 bar(1,300,21,332);
				 line(1,166,11,182);
				 line(11,182,21,150);

				 bar(136,140,365,290);
				 bar(136,340,365,490);
				 bar(380,140,609,290);
				 bar(380,340,609,490);

				 bar(180,50,340,82);
				 rectangle(180,50,340,82);
				 puthz(195,50,c1,32,32,BLUE);
				 bar(212,100,308,132);
				 rectangle(212,100,308,132);
				 puthz(212,100,c2,32,32,BLUE);
				 bar(212,300,308,332);
				 rectangle(212,300,308,332);
				 puthz(212,300,c3,32,32,BLUE);
				 bar(420,50,580,82);
				 rectangle(420,50,580,82);
				 puthz(435,50,c4,32,32,BLUE);
				 bar(452,100,548,132);
				 rectangle(452,100,548,132);
				 puthz(452,100,c5,32,32,BLUE);
				 bar(452,300,548,332);
				 rectangle(452,300,548,332);
				 puthz(452,300,c6,32,32,BLUE);
			 }
		   if(Mouse_press(30,200,126,232))
			 {
				 color1=0;
				 color2=0;
				 color3=0;
				 color4=0;
				 choose=3;
				 c2=s1[5];
				 c3=s1[6];
				 c5=s2[5];
				 c6=s2[6];
				 setfillstyle(1,GREEN);
				 setcolor(BLUE);
				 bar(150,113,198,125);
				 bar(150,313,198,325);
				 bar(565,113,613,125);
				 bar(565,313,613,325);
				 for(i=0;i<4;i++)
	  {
		draw_num(150+i*12,113,money1[4][i]-48,6);
	  }
   for(i=0;i<4;i++)
	  {
		draw_num(150+i*12,313,money1[5][i]-48,6);
	  }
   for(i=0;i<4;i++)
	  {
		draw_num(565+i*12,113,money2[4][i]-48,6);
	  }
   for(i=0;i<4;i++)
	  {
		draw_num(565+i*12,313,money2[5][i]-48,6);
	  }

				 bar(1,100,21,132);
				 bar(1,150,21,182);
				 bar(1,200,21,232);
				 bar(1,250,21,282);
				 bar(1,300,21,332);
				 line(1,216,11,232);
				 line(11,232,21,200);

				 bar(136,140,365,290);
				 bar(136,340,365,490);
				 bar(380,140,609,290);
				 bar(380,340,609,490);

				 bar(180,50,340,82);
				 rectangle(180,50,340,82);
				 puthz(195,50,c1,32,32,BLUE);
				 bar(212,100,308,132);
				 rectangle(212,100,308,132);
				 puthz(212,100,c2,32,32,BLUE);
				 bar(212,300,308,332);
				 rectangle(212,300,308,332);
				 puthz(212,300,c3,32,32,BLUE);
				 bar(420,50,580,82);
				 rectangle(420,50,580,82);
				 puthz(435,50,c4,32,32,BLUE);
				 bar(452,100,548,132);
				 rectangle(452,100,548,132);
				 puthz(452,100,c5,32,32,BLUE);
				 bar(452,300,548,332);
				 rectangle(452,300,548,332);
				 puthz(452,300,c6,32,32,BLUE);
			 }
		   if(Mouse_press(30,250,126,282))
			 {
				 color1=0;
				 color2=0;
				 color3=0;
				 color4=0;
				 choose=4;
				 c2=s1[7];
				 c3=s1[8];
				 c5=s2[7];
				 c6=s2[8];
				 setfillstyle(1,GREEN);
				 setcolor(BLUE);
				 bar(150,113,198,125);
				 bar(150,313,198,325);
				 bar(565,113,613,125);
				 bar(565,313,613,325);
				 for(i=0;i<4;i++)
	  {
		draw_num(150+i*12,113,money1[6][i]-48,6);
	  }
   for(i=0;i<4;i++)
	  {
		draw_num(150+i*12,313,money1[7][i]-48,6);
	  }
   for(i=0;i<4;i++)
	  {
		draw_num(565+i*12,113,money2[6][i]-48,6);
	  }
   for(i=0;i<4;i++)
	  {
		draw_num(565+i*12,313,money2[7][i]-48,6);
	  }

				 bar(1,100,21,132);
				 bar(1,150,21,182);
				 bar(1,200,21,232);
				 bar(1,250,21,282);
				 bar(1,300,21,332);
				 line(1,266,11,282);
				 line(11,282,21,250);

				 bar(136,140,365,290);
				 bar(136,340,365,490);
				 bar(380,140,609,290);
				 bar(380,340,609,490);


				 bar(180,50,340,82);
				 rectangle(180,50,340,82);
				 puthz(195,50,c1,32,32,BLUE);
				 bar(212,100,308,132);
				 rectangle(212,100,308,132);
				 puthz(212,100,c2,32,32,BLUE);
				 bar(212,300,308,332);
				 rectangle(212,300,308,332);
				 puthz(212,300,c3,32,32,BLUE);
				 bar(420,50,580,82);
				 rectangle(420,50,580,82);
				 puthz(435,50,c4,32,32,BLUE);
				 bar(452,100,548,132);
				 rectangle(452,100,548,132);
				 puthz(452,100,c5,32,32,BLUE);
				 bar(452,300,548,332);
				 rectangle(452,300,548,332);
				 puthz(452,300,c6,32,32,BLUE);
			 }
		   if(Mouse_press(30,300,126,332))
			 {
				 color1=0;
				 color2=0;
				 color3=0;
				 color4=0;
				 choose=5;
				 c2=s1[9];
				 c3=s1[10];
				 c5=s2[9];
				 c6=s2[10];
				 setfillstyle(1,GREEN);
				 setcolor(BLUE);
				 bar(150,113,198,125);
				 bar(150,313,198,325);
				 bar(565,113,613,125);
				 bar(565,313,613,325);
				 for(i=0;i<4;i++)
	  {
		draw_num(150+i*12,113,money1[8][i]-48,6);
	  }
   for(i=0;i<4;i++)
	  {
		draw_num(150+i*12,313,money1[9][i]-48,6);
	  }
   for(i=0;i<4;i++)
	  {
		draw_num(565+i*12,113,money2[8][i]-48,6);
	  }
   for(i=0;i<4;i++)
	  {
		draw_num(565+i*12,313,money2[9][i]-48,6);
	  }

				 bar(1,100,21,132);
				 bar(1,150,21,182);
				 bar(1,200,21,232);
				 bar(1,250,21,282);
				 bar(1,300,21,332);
				 line(1,316,11,332);
				 line(11,332,21,300);

				 bar(136,140,365,290);
				 bar(136,340,365,490);
				 bar(380,140,609,290);
				 bar(380,340,609,490);


				 bar(180,50,340,82);
				 rectangle(180,50,340,82);
				 puthz(195,50,c1,32,32,BLUE);
				 bar(212,100,308,132);
				 rectangle(212,100,308,132);
				 puthz(212,100,c2,32,32,BLUE);
				 bar(212,300,308,332);
				 rectangle(212,300,308,332);
				 puthz(212,300,c3,32,32,BLUE);
				 bar(420,50,580,82);
				 rectangle(420,50,580,82);
				 puthz(435,50,c4,32,32,BLUE);
				 bar(452,100,548,132);
				 rectangle(452,100,548,132);
				 puthz(452,100,c5,32,32,BLUE);
				 bar(452,300,548,332);
				 rectangle(452,300,548,332);
				 puthz(452,300,c6,32,32,BLUE);
			 }
		   if(KeyPress(KEY_ESC))
			 {               
				NewBK();
				switch(path_)
                                                                          {
                                                                               case 1:    if((fp=fopen("c:\\mycode\\shop\\1.txt","r"))==NULL)
			                                               {
				                                   settextstyle(1,0,3);
				                                   outtextxy(200,200,"cannot open the file");
				                                   exit(1);
			                                                }
                                                                                              break;
                                                                                case 2:    if((fp=fopen("c:\\mycode\\shop\\2.txt","r"))==NULL)
			                                               {
				                                   settextstyle(1,0,3);
				                                   outtextxy(200,200,"cannot open the file");
				                                   exit(1);
			                                                }
                                                                                              break;
                                                                                 case 3:    if((fp=fopen("c:\\mycode\\shop\\3.txt","r"))==NULL)
			                                               {
				                                   settextstyle(1,0,3);
				                                   outtextxy(200,200,"cannot open the file");
				                                   exit(1);
			                                                }
                                                                                              break;
                                                                                  case 4:    if((fp=fopen("c:\\mycode\\shop\\4.txt","r"))==NULL)
			                                               {
				                                   settextstyle(1,0,3);
				                                   outtextxy(200,200,"cannot open the file");
				                                   exit(1);
			                                                }
                                                                                              break;
                                                                                   case 5:    if((fp=fopen("c:\\mycode\\shop\\5.txt","r"))==NULL)
			                                               {
				                                   settextstyle(1,0,3);
				                                   outtextxy(200,200,"cannot open the file");
				                                   exit(1);
			                                                }
                                                                                              break;
                                                                          }
                                                                 for(i=0;i<10;i++)
			                     {   
                                                                           fseek(fp,13+37*i,0);
                                                                           length=fgetc(fp);
                                                                           for(j=0;j<10;j++)
                                                                                {
                                                                                    ch=fgetc(fp);
                                                                                    s[i][j]=ch;  
                                                                                }
                                                                           s[i][2*(length-48)]='\0';
                                                                      }
                                                                //  choose_player(s,path_);
                                                     
			 }

		}

}