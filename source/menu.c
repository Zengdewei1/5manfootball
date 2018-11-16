#include "main.h"

void menu()
{
	
	menu_page();
	while (1)
	{
		Newxy();
		if (Mouse_press(320, 170, 600, 230))
		{
			NewBK();
			changci();
                                                menu_page();
                                               
		}
		if (Mouse_press(320, 90, 600, 150))
		{
			NewBK();
			jiaoxue();
                                                menu_page();
		}
		if (Mouse_press(320, 250, 600, 310))
		{
			NewBK();
			choose_team();
                                                menu_page();
		}
		if (Mouse_press(50, 150, 200, 250))
		{
			NewBK();
			history();
                                                menu_page();
		}
		// if(Mouse_press(50,300,200,350))
		// {
		// 	NewBK();
		//                                             result(1);
		// }
		if(KeyPress(KEY_ESC))
			exit(0);
	}
}
void result(int historyMatch) //historyMatch表示倒数第几场比赛
{
	FILE *fp, *fpGame;
	int i, match;
	int award_win=0,award_goal=0;
	int bool = 0;
	int myGoal, opGoal, *pmyScore, *popScore, *pmyHelp, *popHelp;
	pmyScore = (int *)malloc(sizeof(int) * 4);
	pmyHelp = (int *)malloc(sizeof(int) * 4);
	popScore = (int *)malloc(sizeof(int) * 4);
	popHelp = (int *)malloc(sizeof(int) * 4);
	if (pmyScore == NULL || pmyHelp == NULL || popScore == NULL || popHelp == NULL)
	{
		printf("malloc wrong");
		getch();
		exit(0);
	}

	setfillstyle(1, GREEN);
	bar(1, 1, 639, 479);
	setcolor(BLUE);
	rectangle(100, 20, 228, 52);
	rectangle(390, 20, 518, 52);
	rectangle(150, 300, 278, 332);
	rectangle(340, 300, 468, 332);
	rectangle(280, 20, 296, 52);
	rectangle(310, 20, 326, 52);

	circle(303, 30, 1);
	circle(303, 40, 1);
	draw_num(40, 100, 0, 8);
	draw_num(40, 150, 1, 8);
	draw_num(40, 200, 2, 8);
	draw_num(40, 250, 3, 8);
	draw_num(567, 100, 0, 8);
	draw_num(567, 150, 1, 8);
	draw_num(567, 200, 2, 8);
	draw_num(567, 250, 3, 8);

	puthz(15, 55, "球员", 32, 32, BLUE);
	puthz(90, 55, "进球", 32, 32, BLUE);
	puthz(180, 55, "助攻", 32, 32, BLUE);
	puthz(100, 20, "我方球队", 32, 32, BLUE);
	puthz(380, 55, "进球", 32, 32, BLUE);
	puthz(470, 55, "助攻", 32, 32, BLUE);
	puthz(545, 55, "球员", 32, 32, BLUE);
	puthz(390, 20, "我方球队", 32, 32, BLUE);
	puthz(150, 300, "查看奖励", 32, 32, BLUE);
	puthz(340, 300, "返回菜单", 32, 32, BLUE);

	fpGame = fopen("c:\\mycode\\result\\game.txt", "r");
	fscanf(fpGame, "%d", &match);
	fclose(fpGame);

	match -= historyMatch;
	switch (match % 20)
	{
	case 1:
		fp = fopen("c:\\mycode\\result\\result1.txt", "r");
		break;
	case 2:
		fp = fopen("c:\\mycode\\result\\result2.txt", "r");
		break;
	case 3:
		fp = fopen("c:\\mycode\\result\\result3.txt", "r");
		break;
	case 4:
		fp = fopen("c:\\mycode\\result\\result4.txt", "r");
		break;
	case 5:
		fp = fopen("c:\\mycode\\result\\result5.txt", "r");
		break;
	case 6:
		fp = fopen("c:\\mycode\\result\\result6.txt", "r");
		break;
	case 7:
		fp = fopen("c:\\mycode\\result\\result7.txt", "r");
		break;
	case 8:
		fp = fopen("c:\\mycode\\result\\result8.txt", "r");
		break;
	case 9:
		fp = fopen("c:\\mycode\\result\\result9.txt", "r");
		break;
	case 10:
		fp = fopen("c:\\mycode\\result\\result10.txt", "r");
		break;
	case 11:
		fp = fopen("c:\\mycode\\result\\result11.txt", "r");
		break;
	case 12:
		fp = fopen("c:\\mycode\\result\\result12.txt", "r");
		break;
	case 13:
		fp = fopen("c:\\mycode\\result\\result13.txt", "r");
		break;
	case 14:
		fp = fopen("c:\\mycode\\result\\result14.txt", "r");
		break;
	case 15:
		fp = fopen("c:\\mycode\\result\\result15.txt", "r");
		break;
	case 16:
		fp = fopen("c:\\mycode\\result\\result16.txt", "r");
		break;
	case 17:
		fp = fopen("c:\\mycode\\result\\result17.txt", "r");
		break;
	case 18:
		fp = fopen("c:\\mycode\\result\\result18.txt", "r");
		break;
	case 19:
		fp = fopen("c:\\mycode\\result\\result19.txt", "r");
		break;
	case 0:
		fp = fopen("c:\\mycode\\result\\result20.txt", "r");
		break;
	}
	fscanf(fp, "%d\n%d\n", &myGoal, &opGoal);
	for (i = 0; i < 4; i++)
	{
		fscanf(fp, "%d\n", pmyScore + i);
	}
	for (i = 0; i < 4; i++)
	{
		fscanf(fp, "%d\n", popScore + i);
	}
	for (i = 0; i < 4; i++)
	{
		fscanf(fp, "%d\n", pmyHelp + i);
	}
	for (i = 0; i < 4; i++)
	{
		fscanf(fp, "%d\n", popHelp + i);
	}
	fscanf(fp,"%d\n",&award_win);
	fscanf(fp,"%d\n",&award_goal);
	fclose(fp);
	draw_num(284, 28, myGoal, 8);
	draw_num(314, 28, opGoal, 8);
	for (i = 0; i < 4; i++)
	{
		draw_num(120, 100 + i * 50, *(pmyScore + i), 8);
	}
	for (i = 0; i < 4; i++)
	{
		draw_num(210, 100 + i * 50, *(pmyHelp + i), 8);
	}
	for (i = 0; i < 4; i++)
	{
		draw_num(410, 100 + i * 50, *(popScore + i), 8);
	}
	for (i = 0; i < 4; i++)
	{
		draw_num(500, 100 + i * 50, *(popHelp + i), 8);
	}
	while (1)
	{
		Newxy();
		if (Mouse_press(150, 300, 278, 332))
		{
			delay(100);
			switch (bool)
			{
			case 0:
				setcolor(BLUE);
				rectangle(140, 340, 400, 460);
				puthz(140, 360, "获胜奖励", 32, 32, BLUE);
				puthz(140, 400, "进球奖励", 32, 32, BLUE);
				outtextxy(270, 370, ":");
				outtextxy(270, 410, ":");
				printf("%d",award_win);
				printf("%d",award_goal);
				draw_num(300,370,award_win/100,10);
				draw_num(320,370,(award_win/10)%10,10);
				draw_num(340,370,award_win%10,10);
				draw_num(300,410,award_goal/100,10);
				draw_num(320,410,(award_goal/10)%10,10);
				draw_num(340,410,award_goal%10,10);
				bool = 1;
				break;
			case 1:
				setfillstyle(1, GREEN);
				bar(140, 340, 400, 460);
				bool = 0;
				break;
			}
		}
		if (Mouse_press(340, 300, 468, 332))
		{
			NewBK();
			return;
		}
	}
}
void history()
{
	FILE *fp;
	int i, j, k;
	int game_amount = 10;
	int game_realamount; //game_realamount代表总的游戏场数
	int slider_dy = 0;
	int mouse_oldy;
	int mouse_newy;
	fp = fopen("c:\\mycode\\result\\game.txt", "r");
	if (fp == NULL)
	{
		printf("can not open the file");
	}
	i = fgetc(fp);
	j = fgetc(fp);
	fclose(fp);
	game_amount = (i - 48) * 10 + (j - 48) - 1;
	if (game_amount > 20)
	{
		game_amount = 20;
	}
	game_realamount = game_amount;
	setfillstyle(1, GREEN);
	bar(1, 1, 639, 479);
	setcolor(BLUE);
	rectangle(120, 90, 500, 390);
	rectangle(500, 90, 520, 390);
	// record(120,90,380,5,300,225);
	if (game_amount >= 0 && game_amount < 5)
	{
		game_amount = 5;
	}
	rectangle(500, 90 + slider_dy, 520, 90 + 75 + 15 * (20 - game_amount) + slider_dy);
	setfillstyle(1, LIGHTBLUE);
	floodfill(510, 100 + slider_dy, BLUE);
	if (game_realamount == 0)
	{
	}
	if (game_realamount > 0)
	{
		for (i = 0; i < game_realamount; i++)
		{
			rectangle(120, 90 + 60 * i, 120 + 380, 90 + 60 * (i + 1));
			draw_num(120 + 30, 90 + 60 * i + 20, i + 1, 10);
			puthz(120 + 250, 90 + 60 * i + 14, "查看", 32, 32, BLUE);
		}
		setfillstyle(1, GREEN);
		bar(120, 390, 500, 640);
		rectangle(120, 90, 500, 390);
	}

	while (1)
	{
		Newxy();
		mouse_newy = Getmouse_y();
		if (Mouse_press(500, 90 + slider_dy, 520, 90 + 75 + 15 * (20 - game_amount) + slider_dy))
		{
			mouse_oldy = mouse_newy;
			Newxy();
			mouse_newy = Getmouse_y();
			if (mouse_newy != mouse_oldy)
			{
				setcolor(BLUE);
				setfillstyle(1, GREEN);
				bar(500, 90 + slider_dy, 520, 90 + 75 + 15 * (20 - game_amount) + slider_dy);
				rectangle(120, 90, 500, 390);
				rectangle(500, 90, 520, 390);
				if (mouse_newy - mouse_oldy > 0)
					slider_dy += mouse_newy - mouse_oldy + 5;
				if (mouse_newy - mouse_oldy < 0)
					slider_dy += mouse_newy - mouse_oldy - 5;
				if (slider_dy < 0)
				{
					slider_dy = 0;
				}
				if (slider_dy > 225 - (20 - game_amount) * 15)
				{
					slider_dy = 225 - (20 - game_amount) * 15;
				}
				rectangle(500, 90 + slider_dy, 520, 90 + 75 + 15 * (20 - game_amount) + slider_dy);
				setfillstyle(1, LIGHTBLUE);
				floodfill(510, 100 + slider_dy, BLUE);

				setfillstyle(1, GREEN);
				bar(120, 90, 500, 390);
				rectangle(120, 90, 500, 390);
				record(120, 90, 380, 5, 300, slider_dy, game_realamount);
			}
		}
		for (j = 0; j < 15; j++)
			if (15 * j <= slider_dy && slider_dy < 15 * (j + 1))
			{
				k = j + 1;
			}
		for (i = 0; i < 5; i++)
			if (Mouse_press(120 + 250, 90 - (slider_dy % 15) * 4 + 14 + 60 * i, 120 + 250 + 32 * 3, 90 + 32 + 14 - (slider_dy % 15) * 4 + 60 * i))
			{
				NewBK();
				result(k + i);
                                                                cleardevice();
                                                                setfillstyle(1, GREEN);
	                                                bar(1, 1, 639, 479);
	                                                setcolor(BLUE);
	                                                rectangle(120, 90, 500, 390);
	                                                rectangle(500, 90, 520, 390);
                                                                rectangle(500, 90 + slider_dy, 520, 90 + 75 + 15 * (20 - game_amount) + slider_dy);
	                                                setfillstyle(1, LIGHTBLUE);
	                                                floodfill(510, 100 + slider_dy, BLUE);
                                                                record(120, 90, 380, 5, 300, slider_dy, game_realamount);
                                                                
			}
		if (KeyPress(KEY_ESC))
		{
			NewBK();
                                                return;
		}
	}
}

void record(int x, int y, int dx, int row, int length, int slider_dy, int game_amount)
{
	int i, j;
	int dy;
	dy = length / row;
	y -= (slider_dy % 15) * 4;
	setcolor(BLUE);
	if (game_amount == 0)
	{
		return;
	}
	if (game_amount > 0 && game_amount <= 5)
	{
		for (i = 0; i < game_amount; i++)
		{
			rectangle(x, y + dy * i, x + dx, y + dy * (i + 1));
			draw_num(x + 30, y + dy * i + 20, i + 1, 10);
			puthz(x + 250, y + dy * i + 14, "查看", 32, 32, BLUE);
		}
	}
	if (game_amount > 5)
	{
		for (i = 0; i <= row; i++)
		{
			rectangle(x, y + dy * i, x + dx, y + dy * (i + 1));
			setfillstyle(1, GREEN);
			setcolor(BLUE);
			bar(120, 30, 500, 90); //消除上面超过的部分
			rectangle(120, 90, 500, 390);

			for (j = 0; j < (game_amount - 5); j++)
			{

				if (15 * j <= slider_dy && slider_dy < 15 * (j + 1))
				{
					draw_num(x + 30, y + dy * i + 20, i + j + 1, 10);
					bar(120, 390, 500, 460);
					rectangle(120, 90, 500, 390);
				}
			}
			if (slider_dy == 225 - (20 - game_amount) * 15)
				draw_num(x + 30, y + dy * i + 20, i + j + 1, 10);
			puthz(x + 250, y + dy * i + 14, "查看", 32, 32, BLUE);
			bar(120, 390, 500, 460);
			rectangle(120, 90, 500, 390);
		}
	}
}
void menu_page()
{
                cleardevice();
	setcolor(BLACK);
	setfillstyle(1, GREEN);
	bar(0, 0, 640, 480);
	setfillstyle(1, YELLOW);
	fillellipse(210, 40, 30, 30);
	fillellipse(270, 40, 30, 30);
	fillellipse(330, 40, 30, 30);
	fillellipse(390, 40, 30, 30);

	setfillstyle(1, BLUE);
	bar(320, 90, 600, 150);
	bar(320, 170, 600, 230);
	bar(320, 250, 600, 310);

	bar(50, 150, 200, 250);
	// bar(50,300,200,350);
	puthz(75, 175, "历史", 48, 48, BLACK);
	puthz(195, 25, "梦想足球", 32, 59, BLACK);
	puthz(355, 100, "键盘教学", 32, 60, BLACK);
	puthz(355, 180, "快速游戏", 32, 60, BLACK);
	puthz(355, 260, "创建球队", 32, 60, BLACK);
	// puthz(75,306,"结果",32,60,BLACK);
}

//主界面

//主客场界面
void changci()
{
	cleardevice();
	setfillstyle(1, GREEN);
	bar(0, 0, 639, 479);
	setfillstyle(1, RED);
	bar(20, 100, 220, 260);
	puthz(65, 155, "主场", 48, 60, BLACK);

	setcolor(BLACK);
	line(230, 100, 410, 260);
	setfillstyle(1, BLUE);
	bar(420, 100, 620, 260);
	puthz(465, 155, "客场", 48, 60, BLACK);
	puthz(270, 300, "球衣", 48, 60, BLACK);
	puthz(65, 300, "红色", 48, 60, RED);
	puthz(465, 300, "蓝色", 48, 60, BLUE);

	while (1)
	{
		Newxy();
		if (Mouse_press(20, 160, 220, 320) || Mouse_press(420, 160, 620, 320))
		{
			game(Left, Right, Red, Blue, 0);
			xiuxi();
			while (1)
			{
				if (KeyPress(KEY_ENTER))
				{
					break;
				}
			}
			game(Right, Left, Red, Blue, 0);
			
			while (1)
			{
				if (KeyPress(KEY_ENTER))
				{
					return;
				}
			}
		}
		if (KeyPress(KEY_ESC))
		{
			NewBK();
			return;
		}
	}
}

//键盘教学界面
void jiaoxue()
{
	cleardevice();
	setfillstyle(1, YELLOW);
	bar(1, 1, 640, 480);
	setcolor(1);
	rectangle(250, 0, 378, 32);
	setfillstyle(1, GREEN);
	floodfill(251, 1, 1);
	puthz(250, 0, "教学界面", 32, 32, YELLOW);
	puthz(180, 50, "球员移动", 48, 80, GREEN);
	rectangle(80, 117, 103, 140);
	settextstyle(1, 0, 4);
	outtextxy(80, 110, "W");
	line(103, 129, 120, 129);
	puthz(120, 113, "上", 32, 80, BLUE);
	rectangle(198, 117, 218, 142);
	outtextxy(200, 110, "S");
	line(218, 129, 235, 129);
	puthz(235, 113, "下", 32, 40, BLUE);
	rectangle(316, 117, 336, 142);
	outtextxy(318, 110, "A");
	line(336, 129, 353, 129);
	puthz(355, 113, "左", 32, 40, BLUE);
	rectangle(450, 117, 468, 142);
	outtextxy(450, 110, "D");
	line(468, 129, 488, 129);
	puthz(490, 113, "右", 32, 40, BLUE);
	puthz(180, 165, "我方控球", 48, 80, RED);
	rectangle(80, 238, 103, 262);
	outtextxy(85, 230, "J");
	line(103, 250, 123, 250);
	puthz(120, 233, "射门", 32, 40, BLUE);
	puthz(80, 280, "按", 32, 40, BLUE);
	rectangle(112, 288, 132, 312);
	outtextxy(112, 280, "K");
	puthz(132, 280, "再按数字", 32, 32, BLUE);
	outtextxy(260, 278, "(0-4):");
	puthz(350, 280, "传球给指定球员", 32, 32, BLUE);
	puthz(180, 340, "我方控球", 48, 80, BROWN);
	rectangle(80, 400, 103, 424);
	outtextxy(85, 392, "J");
	line(103, 412, 123, 412);
	puthz(120, 398, "铲球", 32, 40, BLUE);
	while (1)
	{
		Newxy();
		if (KeyPress(KEY_ESC))
		{
			NewBK();
			return;
		}
	}
}
void choose_teampage()
{
               
	int x =250;		
	int y = 100;
	cleardevice();
	setfillstyle(1, GREEN);
                setlinestyle(0,0,1);
	bar(1, 1, 640, 480);
	setcolor(MAGENTA);	
	rectangle(x, y, x + 128, y + 40);
	rectangle(x - 128, y + 100, x, y + 100 + 40);
	rectangle(x + 128, y + 100, x + 128 + 128, y + 100 + 40);
	rectangle(x - 95, y + 100 * 2, x - 95 + 128, y + 100 * 2 + 40);
	rectangle(x + 95, y + 100 * 2, x + 95 + 128, y + 100 * 2 + 40);
	setfillstyle(1, LIGHTGREEN);
	floodfill(x + 1, y + 1, MAGENTA);
	floodfill(x - 128 + 1, y + 100 + 1, MAGENTA);
	floodfill(x + 128 + 1, y + 100 + 1, MAGENTA);
	floodfill(x - 95 + 1, y + 100 * 2 + 1, MAGENTA);
	floodfill(x + 95 + 1, y + 100 * 2 + 1, MAGENTA);
	circle(314, 230, 50);
	setfillstyle(1, LIGHTCYAN);
	floodfill(314, 230, MAGENTA);
	puthz(x, y, "广州恒大", 32, 32, BLUE);
	puthz(x - 128, y + 100, "上海上港", 32, 32, BLUE);
	puthz(x - 95, y + 100 * 2, "北京国安", 32, 32, BLUE);
	puthz(x + 95, y + 100 * 2, "山东鲁能", 32, 32, BLUE);
	puthz(x + 128, y + 100, "上海申花", 32, 32, BLUE);
	puthz(282, 195, "选择", 32, 32, BLUE);
	puthz(282, 227, "球队", 32, 32, BLUE);
}

//选择球队界面
void choose_team()
{
                int path;
                int i = 0;
	int j = 0;
                char number;
	char s[10][10];
	char ch = '\0';
	FILE *fp;
	choose_teampage();
	while (1)
	{
		Newxy();
		if (KeyPress(KEY_ESC))
		{
			NewBK();
			return;
		}

		if (Mouse_press(250,100,250+128,100+40))
		{
			NewBK();
			if ((fp = fopen("c:\\mycode\\shop\\1.txt", "r")) == NULL)
			{
				settextstyle(1, 0, 3);
				outtextxy(200, 200, "cannot open the file");
				exit(1);
			}
			for (i = 0; i < 10; i++)
			{
				fseek(fp, 13 + 37 * i, 0);
				number = fgetc(fp);
				for (j = 0; j < 10; j++)
				{
					ch = fgetc(fp);
					s[i][j] = ch;
				}
				s[i][2 * (number - 48)] = '\0';
			}
			fclose(fp);
			path = 1;
			choose_player(s, path);
			choose_teampage();
		}

		if (Mouse_press(250-128,100+100,250,100+100 + 40))
		{
			NewBK();
			if ((fp = fopen("c:\\mycode\\shop\\2.txt", "r")) == NULL)
			{
				settextstyle(1, 0, 3);
				outtextxy(200, 200, "cannot open the file");
				exit(1);
			}
			for (i = 0; i < 10; i++)
			{
				fseek(fp, 13 + 37 * i, 0);
				number = fgetc(fp);
				for (j = 0; j < 10; j++)
				{
					ch = fgetc(fp);
					s[i][j] = ch;
				}
				s[i][2 * (number - 48)] = '\0';
			}

			fclose(fp);
			path = 2;
			choose_player(s, path);
			choose_teampage();
		}

		if (Mouse_press(250+128,100+100,250+128+128, 100+100 + 40))
		{
			NewBK();
			if ((fp = fopen("c:\\mycode\\shop\\5.txt", "r")) == NULL)
			{
				settextstyle(1, 0, 3);
				outtextxy(200, 200, "cannot open the file");
				exit(1);
			}
			for (i = 0; i < 10; i++)
			{
				fseek(fp, 13 + 37 * i, 0);
				number = fgetc(fp);
				for (j = 0; j < 10; j++)
				{
					ch = fgetc(fp);
					s[i][j] = ch;
				}
				s[i][2 * (number - 48)] = '\0';
			}

			fclose(fp);
			path = 5;
			choose_player(s, path);
			choose_teampage();
		}

		if (Mouse_press(250-95,100+100 * 2,250-95+128,100+100*2+40))
		{
			NewBK();
			if ((fp = fopen("c:\\mycode\\shop\\3.txt", "r")) == NULL)
			{
				settextstyle(1, 0, 3);
				outtextxy(200, 200, "cannot open the file");
				exit(1);
			}
			for (i = 0; i < 10; i++)
			{
				fseek(fp, 13 + 37 * i, 0);
				number = fgetc(fp);
				for (j = 0; j < 10; j++)
				{
					ch = fgetc(fp);
					s[i][j] = ch;
				}
				s[i][2 * (number - 48)] = '\0';
			}

			fclose(fp);
			path = 3;
			choose_player(s, path);
			choose_teampage();
		}

		if (Mouse_press(250+95,100+100 * 2,250+95+128,100+100*2+40))
		{
			NewBK();
			if ((fp = fopen("c:\\mycode\\shop\\4.txt", "r")) == NULL)
			{
				settextstyle(1, 0, 3);
				outtextxy(200, 200, "cannot open the file");
				exit(1);
			}
			for (i = 0; i < 10; i++)
			{
				fseek(fp, 13 + 37 * i, 0);
				number = fgetc(fp);
				for (j = 0; j < 10; j++)
				{
					ch = fgetc(fp);
					s[i][j] = ch;
				}
				s[i][2 * (number - 48)] = '\0';
			}

			fclose(fp);
			path = 4;
			choose_player(s, path);
			choose_teampage();
		}
		
	}
	
}

void choose_playerpage()
{
                int i, j, x, y = 100;
	cleardevice();
	setfillstyle(1, GREEN);
	bar(1, 1, 640, 480);

	setcolor(WHITE);
	rectangle(260, 0, 388, 32);
	setfillstyle(1, YELLOW);
	floodfill(261, 1, WHITE);
	puthz(260, 0, "选择球员", 32, 32, BLUE);
	for (j = 0; j < 3; j++)
	{
		x = 130;
		for (i = 0; i < 4; i++)
		{
			rectangle(x, y, x + 96, y + 30);
			x += 108;
		}
		y += 100;
	}

	y = 101;
	for (j = 0; j < 3; j++)
	{
		x = 131;
		for (i = 0; i < 4; i++)
		{
			floodfill(x, y, WHITE);
			x += 108;
		}
		y += 100;
	}
	rectangle(250, 375, 400, 425);
	setfillstyle(1, CYAN);
	floodfill(300, 401, WHITE);
	setfillstyle(1, GREEN);
	floodfill(131, 301, WHITE);
	floodfill(463, 301, WHITE);
	setcolor(GREEN);
	rectangle(130, 300, 130 + 96, 300 + 30);
	rectangle(130 + 108 * 3, 300, 130 + 108 * 3 + 96, 300 + 30);

	setfillstyle(1, LIGHTGREEN);
	bar(50, 300, 180, 400);
	puthz(65, 325, "商城", 48, 48, LIGHTBLUE);

	setcolor(BLUE);
	puthz(210, 40, "左前锋", 32, 32, BLUE);
	line(242, 72, 200, 92);
	line(242, 72, 284, 92);
	puthz(430, 40, "右前锋", 32, 32, BLUE);
	line(462, 72, 420, 92);
	line(462, 72, 504, 92);
	puthz(210, 140, "左后卫", 32, 32, BLUE);
	line(242, 172, 200, 192);
	line(242, 172, 284, 192);

	puthz(430, 140, "右后卫", 32, 32, BLUE);
	line(462, 172, 420, 192);
	line(462, 172, 504, 192);

	puthz(300, 250, "守门员", 32, 32, BLUE);
	line(340, 282, 300, 295);
	line(340, 282, 380, 295);

	puthz(260, 385, "确认选择", 32, 32, BLUE);
}
//选择球员界面
void choose_player(char (*s)[10], int path)
{
	
                choose_playerpage();
	puthz(130, 100, s[0], 32, 32, BLUE);
	puthz(238, 100, s[1], 32, 32, BLUE);
	puthz(346, 100, s[2], 32, 32, BLUE);
	puthz(454, 100, s[3], 32, 32, BLUE);

	puthz(130, 200, s[4], 32, 32, BLUE);
	puthz(238, 200, s[5], 32, 32, BLUE);
	puthz(346, 200, s[6], 32, 32, BLUE);
	puthz(454, 200, s[7], 32, 32, BLUE);

	puthz(238, 300, s[8], 32, 32, BLUE);
	puthz(346, 300, s[9], 32, 32, BLUE);

	playerID(path); //记录选择球员的球员ID
	
}

void Vs(int path)
{
	int i;
	char ch;
	FILE *fp;
	int op_path;
	int length;
	char s1[10];
	char s2[10];
	setfillstyle(1, GREEN);
	bar(1, 1, 639, 479);
	setcolor(BLUE);
	rectangle(50, 100, 242, 164);
	rectangle(390, 100, 582, 164);
	setlinestyle(0, 0, 3);
	line(260, 100, 290, 164);
	line(290, 164, 320, 100);
	line(330, 100, 370, 100);
	line(330, 100, 330, 132);
	line(330, 132, 370, 132);
	line(370, 132, 370, 164);
	line(370, 164, 330, 164);
	setlinestyle(0, 0, 1);

	setfillstyle(1, CYAN);
	circle(310, 300, 80);
	floodfill(310, 300, BLUE);
	puthz(280, 230, "按键", 32, 32, BLUE);
	outtextxy(290, 280, "Enter");
	puthz(280, 310, "确定", 32, 32, BLUE);
	switch (path)
	{
	case 1:
		if ((fp = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
		{
			settextstyle(1, 0, 3);
			outtextxy(200, 200, "cannot open the file");
			exit(1);
		}
		break;
	case 2:
		if ((fp = fopen("c:\\mycode\\shop\\2.txt", "r+")) == NULL)
		{
			settextstyle(1, 0, 3);
			outtextxy(200, 200, "cannot open the file");
			exit(1);
		}
		break;
	case 3:
		if ((fp = fopen("c:\\mycode\\shop\\3.txt", "r+")) == NULL)
		{
			settextstyle(1, 0, 3);
			outtextxy(200, 200, "cannot open the file");
			exit(1);
		}
		break;
	case 4:
		if ((fp = fopen("c:\\mycode\\shop\\4.txt", "r+")) == NULL)
		{
			settextstyle(1, 0, 3);
			outtextxy(200, 200, "cannot open the file");
			exit(1);
		}
		break;
	case 5:
		if ((fp = fopen("c:\\mycode\\shop\\5.txt", "r+")) == NULL)
		{
			settextstyle(1, 0, 3);
			outtextxy(200, 200, "cannot open the file");
			exit(1);
		}
		break;
	}
	length = fgetc(fp);
	for (i = 0; i < 10; i++)
	{
		ch = fgetc(fp);
		s1[i] = ch;
	}
	fclose(fp);
	s1[2 * (length - 48)] = '\0';
	puthz(50, 108, s1, 48, 48, BLUE);

	if ((fp = fopen("c:\\mycode\\shop\\opteam.txt", "r+")) == NULL)
	{
		settextstyle(1, 0, 3);
		outtextxy(200, 200, "cannot open the file");
		exit(1);
	}
	op_path = fgetc(fp);
	fclose(fp);
	switch (op_path - 48)
	{
	case 1:
		if ((fp = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
		{
			settextstyle(1, 0, 3);
			outtextxy(200, 200, "cannot open the file");
			exit(1);
		}
		break;
	case 2:
		if ((fp = fopen("c:\\mycode\\shop\\2.txt", "r+")) == NULL)
		{
			settextstyle(1, 0, 3);
			outtextxy(200, 200, "cannot open the file");
			exit(1);
		}
		break;
	case 3:
		if ((fp = fopen("c:\\mycode\\shop\\3.txt", "r+")) == NULL)
		{
			settextstyle(1, 0, 3);
			outtextxy(200, 200, "cannot open the file");
			exit(1);
		}
		break;
	case 4:
		if ((fp = fopen("c:\\mycode\\shop\\4.txt", "r+")) == NULL)
		{
			settextstyle(1, 0, 3);
			outtextxy(200, 200, "cannot open the file");
			exit(1);
		}
		break;
	case 5:
		if ((fp = fopen("c:\\mycode\\shop\\5.txt", "r+")) == NULL)
		{
			settextstyle(1, 0, 3);
			outtextxy(200, 200, "cannot open the file");
			exit(1);
		}
		break;
	}
	length = fgetc(fp);
	for (i = 0; i < 10; i++)
	{
		ch = fgetc(fp);
		s2[i] = ch;
	}
	fclose(fp);
	s2[2 * (length - 48)] = '\0';
	puthz(390, 108, s2, 48, 48, BLUE);

}

void shop(int path_)
{
	int i, j, k, choose = 1, ability;
	int color1 = 0, color2 = 0, color3 = 0, color4 = 0;
	int change1 = 0, change2 = 0, change3 = 0, change4 = 0;
	int bool;
	long amount, amount1, amount2, damount;
	char ch, length, path;
	char *c1, *c2, *c3, *c4, *c5, *c6;
	char money[4], money1[10][4], money2[10][4];
	char a1[36], a2[36];
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
	setfillstyle(1, GREEN);
	bar(1, 1, 639, 479);
	setcolor(BLUE);
	rectangle(30, 100, 126, 132);
	rectangle(30, 150, 126, 182);
	rectangle(30, 200, 126, 232);
	rectangle(30, 250, 126, 282);
	rectangle(30, 300, 126, 332);
	rectangle(180, 50, 340, 82);
	rectangle(420, 50, 580, 82);
	setlinestyle(0, 0, 1);
	line(410, 50, 400, 66);
	line(400, 66, 410, 82);
	line(410, 50, 410, 82);
	line(590, 50, 600, 66);
	line(600, 66, 590, 82);
	line(590, 50, 590, 82);
	circle(330, 116, 10);
	circle(330, 316, 10);
	circle(430, 116, 10);
	circle(430, 316, 10);
	line(1, 116, 11, 132);
	line(11, 132, 21, 100);

	puthz(30, 100, "左前锋", 32, 32, BLUE);
	puthz(30, 150, "右前锋", 32, 32, BLUE);
	puthz(30, 200, "左后卫", 32, 32, BLUE);
	puthz(30, 250, "右后卫", 32, 32, BLUE);
	puthz(30, 300, "守门员", 32, 32, BLUE);
	puthz(1, 50, "金额", 32, 32, BLUE);
	outtextxy(70, 66, ":");
	rectangle(212, 100, 308, 132);
	rectangle(212, 300, 308, 332);
	rectangle(452, 100, 548, 132);
	rectangle(452, 300, 548, 332);
	switch (path_)
	{
	case 1:
		if ((fp1 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
		{

			setlinestyle(0, 0, 1);
			outtextxy(300, 300, "cannot open the file");
			exit(1);
		}
		break;
	case 2:
		if ((fp1 = fopen("c:\\mycode\\shop\\2.txt", "r+")) == NULL)
		{
			setlinestyle(0, 0, 1);
			outtextxy(300, 300, "cannot open the file");
			exit(1);
		}
		break;
	case 3:
		if ((fp1 = fopen("c:\\mycode\\shop\\3.txt", "r+")) == NULL)
		{
			setlinestyle(0, 0, 1);
			outtextxy(300, 300, "cannot open the file");
			exit(1);
		}
		break;
	case 4:
		if ((fp1 = fopen("c:\\mycode\\shop\\4.txt", "r+")) == NULL)
		{
			setlinestyle(0, 0, 1);
			outtextxy(300, 300, "cannot open the file");
			exit(1);
		}
		break;
	case 5:
		if ((fp1 = fopen("c:\\mycode\\shop\\5.txt", "r+")) == NULL)
		{
			setlinestyle(0, 0, 1);
			outtextxy(300, 300, "cannot open the file");
			exit(1);
		}
		break;
	}
	length = fgetc(fp1);
	for (i = 0; i < 10; i++)
	{
		ch = fgetc(fp1);
		s1[0][i] = ch;
	}
	s1[0][2 * (length - 48)] = '\0';
	ch = fgetc(fp1);

	for (j = 1; j < 11; j++)
	{
		length = fgetc(fp1);
		for (i = 0; i < 10; i++)
		{
			ch = fgetc(fp1);
			s1[j][i] = ch;
		}
		s1[j][2 * (length - 48)] = '\0';
		if (j < 10)
			fseek(fp1, 26, 1);
	}
	for (i = 1; i < 11; i++)
	{
		fseek(fp1, 13 + 37 * (i - 1) + 26, 0);
		ch = fgetc(fp1);
		money1[i - 1][0] = ch;
		ch = fgetc(fp1);
		money1[i - 1][1] = ch;
		ch = fgetc(fp1);
		money1[i - 1][2] = ch;
		ch = fgetc(fp1);
		money1[i - 1][3] = ch;
	}
	fclose(fp1);

	if ((fp = fopen("c:\\mycode\\shop\\path.txt", "r+")) == NULL)
	{

		setlinestyle(0, 0, 1);
		outtextxy(300, 300, "cannot open the file");
		exit(1);
	}
	path = fgetc(fp);
	if (path_ == path - 48)
	{
		if (1 <= path_ < 5)
		{
			path += 1;
		}
		if (path_ == 5)
		{
			path = 49;
		}
		rewind(fp);
		fputc(path, fp);
	}
	fclose(fp);

	if ((fp = fopen("c:\\mycode\\shop\\money.txt", "r+")) == NULL)
	{
		setlinestyle(0, 0, 1);
		outtextxy(300, 300, "cannot open the file");
		exit(1);
	}
	for (i = 0; i < 4; i++)
	{
		ch = fgetc(fp);
		money[i] = ch;
	}
	fclose(fp);

	switch (path - 48)
	{
	case 1:
		if ((fp2 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
		{
			setlinestyle(0, 0, 1);
			outtextxy(300, 300, "cannot open the file");
			exit(1);
		}
		break;
	case 2:
		if ((fp2 = fopen("c:\\mycode\\shop\\2.txt", "r+")) == NULL)
		{
			setlinestyle(0, 0, 1);
			outtextxy(300, 300, "cannot open the file");
			exit(1);
		}
		break;
	case 3:
		if ((fp2 = fopen("c:\\mycode\\shop\\3.txt", "r+")) == NULL)
		{
			setlinestyle(0, 0, 1);
			outtextxy(300, 300, "cannot open the file");
			exit(1);
		}
		break;
	case 4:
		if ((fp2 = fopen("c:\\mycode\\shop\\4.txt", "r+")) == NULL)
		{
			setlinestyle(0, 0, 1);
			outtextxy(300, 300, "cannot open the file");
			exit(1);
		}
		break;
	case 5:
		if ((fp2 = fopen("c:\\mycode\\shop\\5.txt", "r+")) == NULL)
		{
			setlinestyle(0, 0, 1);
			outtextxy(300, 300, "cannot open the file");
			exit(1);
		}
		break;
	}

	length = fgetc(fp2);
	for (i = 0; i < 10; i++)
	{
		ch = fgetc(fp2);
		s2[0][i] = ch;
	}
	s2[0][2 * (length - 48)] = '\0';
	ch = fgetc(fp2);

	for (j = 1; j < 11; j++)
	{
		length = fgetc(fp2);
		for (i = 0; i < 10; i++)
		{
			ch = fgetc(fp2);
			s2[j][i] = ch;
		}
		s2[j][2 * (length - 48)] = '\0';
		if (j < 10)
			fseek(fp2, 26, 1);
	}
	for (i = 1; i < 11; i++)
	{
		fseek(fp2, 13 + 37 * (i - 1) + 26, 0);
		ch = fgetc(fp2);
		money2[i - 1][0] = ch;
		ch = fgetc(fp2);
		money2[i - 1][1] = ch;
		ch = fgetc(fp2);
		money2[i - 1][2] = ch;
		ch = fgetc(fp2);
		money2[i - 1][3] = ch;
	}
	fclose(fp2);

	c1 = s1[0];
	c2 = s1[1];
	c3 = s1[2];
	c4 = s2[0];
	c5 = s2[1];
	c6 = s2[2];
	puthz(195, 50, c1, 32, 32, BLUE);
	puthz(212, 100, c2, 32, 32, BLUE);
	puthz(212, 300, c3, 32, 32, BLUE);
	puthz(435, 50, c4, 32, 32, BLUE);
	puthz(452, 100, c5, 32, 32, BLUE);
	puthz(452, 300, c6, 32, 32, BLUE);
	for (i = 0; i < 4; i++)
	{
		draw_num(90 + i * 12, 60, money[i] - 48, 6);
	}
	for (i = 0; i < 4; i++)
	{
		draw_num(150 + i * 12, 113, money1[0][i] - 48, 6);
	}
	for (i = 0; i < 4; i++)
	{
		draw_num(150 + i * 12, 313, money1[1][i] - 48, 6);
	}
	for (i = 0; i < 4; i++)
	{
		draw_num(565 + i * 12, 113, money2[0][i] - 48, 6);
	}
	for (i = 0; i < 4; i++)
	{
		draw_num(565 + i * 12, 313, money2[1][i] - 48, 6);
	}
	while (1)
	{
		Newxy();
		if (change2 == 1 && change4 == 1)
		{
			color1 = 0;
			color2 = 0;
			color3 = 0;
			color4 = 0;
			bool = 1;
			setfillstyle(1, GREEN);
			bar(136, 140, 365, 290);
			bar(380, 140, 609, 290);
			bar(136, 340, 365, 490);
			bar(380, 340, 609, 490);

			bar(212, 100, 308, 132);
			bar(212, 300, 308, 332);
			bar(452, 100, 548, 132);
			bar(452, 300, 548, 332);
			setcolor(BLUE);
			rectangle(212, 100, 308, 132);
			rectangle(212, 300, 308, 332);
			rectangle(452, 100, 548, 132);
			rectangle(452, 300, 548, 332);
			puthz(212, 100, c2, 32, 32, BLUE);
			puthz(212, 300, c3, 32, 32, BLUE);
			puthz(452, 100, c5, 32, 32, BLUE);
			puthz(452, 300, c6, 32, 32, BLUE);
			setfillstyle(1, LIGHTCYAN);
			bar(308, 140, 452, 290);
			setcolor(BLUE);
			rectangle(340, 210, 372, 242);
			rectangle(390, 210, 422, 242);
			puthz(350, 160, "交换", 32, 32, BLUE);
			puthz(340, 210, "是", 32, 32, BLUE);
			puthz(390, 210, "否", 32, 32, BLUE);
			while (bool)
			{
				Newxy();
				if (Mouse_press(390, 210, 422, 242))
				{
					NewBK();
					setcolor(BLUE);
					circle(330, 316, 10);
					circle(430, 316, 10);
					setfillstyle(1, GREEN);
					floodfill(330, 316, BLUE);
					floodfill(430, 316, BLUE);
					bar(308, 140, 452, 290);
					change2 = 0;
					change4 = 0;
					bool = 0;
				}
				if (Mouse_press(340, 210, 372, 242))
				{
					NewBK();
					setcolor(BLUE);
					circle(330, 316, 10);
					circle(430, 316, 10);
					setfillstyle(1, GREEN);
					floodfill(330, 316, BLUE);
					floodfill(430, 316, BLUE);
					bar(308, 140, 452, 290);

					for (i = 1; i < 11; i++)
					{
						if (strcmp(c3, s1[i]) == 0)
							break;
					}
					for (j = 1; j < 11; j++)
					{
						if (strcmp(c6, s2[j]) == 0)
							break;
					}
					if ((fp1 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					fseek(fp1, 13 + 37 * (i - 1), 0);
					for (k = 0; k < 36; k++)
					{
						ch = fgetc(fp1);
						a1[k] = ch;
					}
					fclose(fp1);
					switch (path - 48)
					{
					case 1:
						if ((fp2 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					case 2:
						if ((fp2 = fopen("c:\\mycode\\shop\\2.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					case 3:
						if ((fp2 = fopen("c:\\mycode\\shop\\3.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					case 4:
						if ((fp2 = fopen("c:\\mycode\\shop\\4.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					case 5:
						if ((fp2 = fopen("c:\\mycode\\shop\\5.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					}
					fseek(fp2, 13 + 37 * (j - 1), 0);
					for (k = 0; k < 36; k++)
					{
						ch = fgetc(fp2);
						a2[k] = ch;
					}

					fseek(fp2, 13 + 37 * (j - 1), 0);
					for (k = 0; k < 36; k++)
					{
						ch = a1[k];
						fputc(ch, fp2);
					}

					fseek(fp2, 13 + 37 * (j - 1), 0);
					length = fgetc(fp2);
					for (k = 0; k < 10; k++)
					{
						ch = fgetc(fp2);
						s2[j][k] = ch;
					}
					s2[j][2 * (length - 48)] = '\0';
					for (k = 1; k < 11; k++)
					{
						fseek(fp2, 13 + 37 * (k - 1) + 26, 0);
						ch = fgetc(fp2);
						money2[k - 1][0] = ch;
						ch = fgetc(fp2);
						money2[k - 1][1] = ch;
						ch = fgetc(fp2);
						money2[k - 1][2] = ch;
						ch = fgetc(fp2);
						money2[k - 1][3] = ch;
					}
					fclose(fp2);

					if ((fp1 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					fseek(fp1, 13 + 37 * (i - 1), 0);
					for (k = 0; k < 36; k++)
					{
						ch = a2[k];
						fputc(ch, fp1);
					}
					fseek(fp1, 13 + 37 * (i - 1), 0);
					length = fgetc(fp1);
					for (k = 0; k < 10; k++)
					{
						ch = fgetc(fp1);
						s1[i][k] = ch;
					}
					s1[i][2 * (length - 48)] = '\0';
					for (k = 1; k < 11; k++)
					{
						fseek(fp1, 13 + 37 * (k - 1) + 26, 0);
						ch = fgetc(fp1);
						money1[k - 1][0] = ch;
						ch = fgetc(fp1);
						money1[k - 1][1] = ch;
						ch = fgetc(fp1);
						money1[k - 1][2] = ch;
						ch = fgetc(fp1);
						money1[k - 1][3] = ch;
					}
					fclose(fp1);

					c3 = s1[i];
					c6 = s2[j];
					amount1 = (money2[(choose - 1) * 2 + 1][0] - 48) * 1000 + (money2[(choose - 1) * 2 + 1][1] - 48) * 100 + (money2[(choose - 1) * 2 + 1][2] - 48) * 10 + (money2[(choose - 1) * 2 + 1][3] - 48) * 1;
					amount2 = (money1[(choose - 1) * 2 + 1][0] - 48) * 1000 + (money1[(choose - 1) * 2 + 1][1] - 48) * 100 + (money1[(choose - 1) * 2 + 1][2] - 48) * 10 + (money1[(choose - 1) * 2 + 1][3] - 48) * 1;
					damount = amount1 - amount2;
					amount = (money[0] - 48) * 1000 + (money[1] - 48) * 100 + (money[2] - 48) * 10 + (money[3] - 48) * 1;
					amount += damount;
					for (i = 0; i < 4; i++)
					{
						money[3 - i] = amount % 10 + 48;
						amount = amount / 10;
					}
					if ((fp = fopen("c:\\mycode\\shop\\money.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					for (i = 0; i < 4; i++)
					{
						ch = money[i];
						fputc(ch, fp);
					}
					fclose(fp);
					setfillstyle(1, GREEN);
					setcolor(BLUE);
					bar(150, 113, 198, 125);
					bar(150, 313, 198, 325);
					bar(565, 113, 613, 125);
					bar(565, 313, 613, 325);
					bar(90, 60, 138, 72);
					for (i = 0; i < 4; i++)
					{
						draw_num(90 + i * 12, 60, money[i] - 48, 6);
					}
					for (i = 0; i < 4; i++)
					{
						draw_num(150 + i * 12, 113, money1[(choose - 1) * 2][i] - 48, 6);
					}
					for (i = 0; i < 4; i++)
					{
						draw_num(150 + i * 12, 313, money1[(choose - 1) * 2 + 1][i] - 48, 6);
					}
					for (i = 0; i < 4; i++)
					{
						draw_num(565 + i * 12, 113, money2[(choose - 1) * 2][i] - 48, 6);
					}
					for (i = 0; i < 4; i++)
					{
						draw_num(565 + i * 12, 313, money2[(choose - 1) * 2 + 1][i] - 48, 6);
					}

					setfillstyle(1, GREEN);
					bar(212, 300, 308, 332);
					bar(452, 300, 548, 332);
					setcolor(BLUE);
					rectangle(212, 300, 308, 332);
					rectangle(452, 300, 548, 332);
					puthz(212, 300, c3, 32, 32, BLUE);
					puthz(452, 300, c6, 32, 32, BLUE);

					change2 = 0;
					change4 = 0;
					bool = 0;
				}
			}
		}
		if (change2 == 1 && change3 == 1)
		{
			color1 = 0;
			color2 = 0;
			color3 = 0;
			color4 = 0;
			bool = 1;
			setfillstyle(1, GREEN);
			bar(136, 140, 365, 290);
			bar(380, 140, 609, 290);
			bar(136, 340, 365, 490);
			bar(380, 340, 609, 490);

			bar(212, 100, 308, 132);
			bar(212, 300, 308, 332);
			bar(452, 100, 548, 132);
			bar(452, 300, 548, 332);
			setcolor(BLUE);
			rectangle(212, 100, 308, 132);
			rectangle(212, 300, 308, 332);
			rectangle(452, 100, 548, 132);
			rectangle(452, 300, 548, 332);
			puthz(212, 100, c2, 32, 32, BLUE);
			puthz(212, 300, c3, 32, 32, BLUE);
			puthz(452, 100, c5, 32, 32, BLUE);
			puthz(452, 300, c6, 32, 32, BLUE);
			setfillstyle(1, LIGHTCYAN);
			bar(308, 140, 452, 290);
			setcolor(BLUE);
			rectangle(340, 210, 372, 242);
			rectangle(390, 210, 422, 242);
			puthz(350, 160, "交换", 32, 32, BLUE);
			puthz(340, 210, "是", 32, 32, BLUE);
			puthz(390, 210, "否", 32, 32, BLUE);
			while (bool)
			{
				Newxy();
				if (Mouse_press(390, 210, 422, 242))
				{
					NewBK();
					setcolor(BLUE);
					circle(330, 316, 10);
					circle(430, 116, 10);
					setfillstyle(1, GREEN);
					floodfill(330, 316, BLUE);
					floodfill(430, 116, BLUE);
					bar(308, 140, 452, 290);
					change2 = 0;
					change3 = 0;
					bool = 0;
				}
				if (Mouse_press(340, 210, 372, 242))
				{
					NewBK();
					setcolor(BLUE);
					circle(330, 316, 10);
					circle(430, 116, 10);
					setfillstyle(1, GREEN);
					floodfill(330, 316, BLUE);
					floodfill(430, 116, BLUE);
					bar(308, 140, 452, 290);

					for (i = 1; i < 11; i++)
					{
						if (strcmp(c3, s1[i]) == 0)
							break;
					}
					for (j = 1; j < 11; j++)
					{
						if (strcmp(c5, s2[j]) == 0)
							break;
					}
					if ((fp1 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					fseek(fp1, 13 + 37 * (i - 1), 0);
					for (k = 0; k < 36; k++)
					{
						ch = fgetc(fp1);
						a1[k] = ch;
					}
					fclose(fp1);
					switch (path - 48)
					{
					case 1:
						if ((fp2 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					case 2:
						if ((fp2 = fopen("c:\\mycode\\shop\\2.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					case 3:
						if ((fp2 = fopen("c:\\mycode\\shop\\3.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					case 4:
						if ((fp2 = fopen("c:\\mycode\\shop\\4.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					case 5:
						if ((fp2 = fopen("c:\\mycode\\shop\\5.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					}
					fseek(fp2, 13 + 37 * (j - 1), 0);
					for (k = 0; k < 36; k++)
					{
						ch = fgetc(fp2);
						a2[k] = ch;
					}

					fseek(fp2, 13 + 37 * (j - 1), 0);
					for (k = 0; k < 36; k++)
					{
						ch = a1[k];
						fputc(ch, fp2);
					}

					fseek(fp2, 13 + 37 * (j - 1), 0);
					length = fgetc(fp2);
					for (k = 0; k < 10; k++)
					{
						ch = fgetc(fp2);
						s2[j][k] = ch;
					}
					s2[j][2 * (length - 48)] = '\0';
					for (k = 1; k < 11; k++)
					{
						fseek(fp2, 13 + 37 * (k - 1) + 26, 0);
						ch = fgetc(fp2);
						money2[k - 1][0] = ch;
						ch = fgetc(fp2);
						money2[k - 1][1] = ch;
						ch = fgetc(fp2);
						money2[k - 1][2] = ch;
						ch = fgetc(fp2);
						money2[k - 1][3] = ch;
					}
					fclose(fp2);
					if ((fp1 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					fseek(fp1, 13 + 37 * (i - 1), 0);
					for (k = 0; k < 36; k++)
					{
						ch = a2[k];
						fputc(ch, fp1);
					}
					fseek(fp1, 13 + 37 * (i - 1), 0);
					length = fgetc(fp1);
					for (k = 0; k < 10; k++)
					{
						ch = fgetc(fp1);
						s1[i][k] = ch;
					}
					s1[i][2 * (length - 48)] = '\0';
					for (k = 1; k < 11; k++)
					{
						fseek(fp1, 13 + 37 * (k - 1) + 26, 0);
						ch = fgetc(fp1);
						money1[k - 1][0] = ch;
						ch = fgetc(fp1);
						money1[k - 1][1] = ch;
						ch = fgetc(fp1);
						money1[k - 1][2] = ch;
						ch = fgetc(fp1);
						money1[k - 1][3] = ch;
					}
					fclose(fp1);
					c3 = s1[i];
					c5 = s2[j];
					amount1 = (money2[(choose - 1) * 2][0] - 48) * 1000 + (money2[(choose - 1) * 2][1] - 48) * 100 + (money2[(choose - 1) * 2][2] - 48) * 10 + (money2[(choose - 1) * 2][3] - 48) * 1;
					amount2 = (money1[(choose - 1) * 2 + 1][0] - 48) * 1000 + (money1[(choose - 1) * 2 + 1][1] - 48) * 100 + (money1[(choose - 1) * 2 + 1][2] - 48) * 10 + (money1[(choose - 1) * 2 + 1][3] - 48) * 1;
					damount = amount1 - amount2;
					amount = (money[0] - 48) * 1000 + (money[1] - 48) * 100 + (money[2] - 48) * 10 + (money[3] - 48) * 1;
					amount += damount;
					for (i = 0; i < 4; i++)
					{
						money[3 - i] = amount % 10 + 48;
						amount = amount / 10;
					}
					if ((fp = fopen("c:\\mycode\\shop\\money.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					for (i = 0; i < 4; i++)
					{
						ch = money[i];
						fputc(ch, fp);
					}
					fclose(fp);
					setfillstyle(1, GREEN);
					setcolor(BLUE);
					bar(150, 113, 198, 125);
					bar(150, 313, 198, 325);
					bar(565, 113, 613, 125);
					bar(565, 313, 613, 325);
					bar(90, 60, 138, 72);
					for (i = 0; i < 4; i++)
					{
						draw_num(90 + i * 12, 60, money[i] - 48, 6);
					}
					for (i = 0; i < 4; i++)
					{
						draw_num(150 + i * 12, 113, money1[(choose - 1) * 2][i] - 48, 6);
					}
					for (i = 0; i < 4; i++)
					{
						draw_num(150 + i * 12, 313, money1[(choose - 1) * 2 + 1][i] - 48, 6);
					}
					for (i = 0; i < 4; i++)
					{
						draw_num(565 + i * 12, 113, money2[(choose - 1) * 2][i] - 48, 6);
					}
					for (i = 0; i < 4; i++)
					{
						draw_num(565 + i * 12, 313, money2[(choose - 1) * 2 + 1][i] - 48, 6);
					}

					setfillstyle(1, GREEN);
					bar(212, 300, 308, 332);
					bar(452, 100, 548, 132);
					setcolor(BLUE);
					rectangle(212, 300, 308, 332);
					rectangle(452, 100, 548, 132);
					puthz(212, 300, c3, 32, 32, BLUE);
					puthz(452, 100, c5, 32, 32, BLUE);

					change2 = 0;
					change3 = 0;
					bool = 0;
				}
			}
		}
		if (change1 == 1 && change4 == 1)
		{
			color1 = 0;
			color2 = 0;
			color3 = 0;
			color4 = 0;
			bool = 1;
			setfillstyle(1, GREEN);
			bar(136, 140, 365, 290);
			bar(380, 140, 609, 290);
			bar(136, 340, 365, 490);
			bar(380, 340, 609, 490);

			bar(212, 100, 308, 132);
			bar(212, 300, 308, 332);
			bar(452, 100, 548, 132);
			bar(452, 300, 548, 332);
			setcolor(BLUE);
			rectangle(212, 100, 308, 132);
			rectangle(212, 300, 308, 332);
			rectangle(452, 100, 548, 132);
			rectangle(452, 300, 548, 332);
			puthz(212, 100, c2, 32, 32, BLUE);
			puthz(212, 300, c3, 32, 32, BLUE);
			puthz(452, 100, c5, 32, 32, BLUE);
			puthz(452, 300, c6, 32, 32, BLUE);
			setfillstyle(1, LIGHTCYAN);
			bar(308, 140, 452, 290);
			setcolor(BLUE);
			rectangle(340, 210, 372, 242);
			rectangle(390, 210, 422, 242);
			puthz(350, 160, "交换", 32, 32, BLUE);
			puthz(340, 210, "是", 32, 32, BLUE);
			puthz(390, 210, "否", 32, 32, BLUE);
			while (bool)
			{
				Newxy();
				if (Mouse_press(390, 210, 422, 242))
				{
					NewBK();
					setcolor(BLUE);
					circle(330, 116, 10);
					circle(430, 316, 10);
					setfillstyle(1, GREEN);
					floodfill(330, 116, BLUE);
					floodfill(430, 316, BLUE);
					bar(308, 140, 452, 290);
					change1 = 0;
					change4 = 0;
					bool = 0;
				}
				if (Mouse_press(340, 210, 372, 242))
				{
					NewBK();
					setcolor(BLUE);
					circle(330, 116, 10);
					circle(430, 316, 10);
					setfillstyle(1, GREEN);
					floodfill(330, 116, BLUE);
					floodfill(430, 316, BLUE);
					bar(308, 140, 452, 290);

					for (i = 1; i < 11; i++)
					{
						if (strcmp(c2, s1[i]) == 0)
							break;
					}
					for (j = 1; j < 11; j++)
					{
						if (strcmp(c6, s2[j]) == 0)
							break;
					}
					if ((fp1 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					fseek(fp1, 13 + 37 * (i - 1), 0);
					for (k = 0; k < 36; k++)
					{
						ch = fgetc(fp1);
						a1[k] = ch;
					}
					fclose(fp1);
					switch (path - 48)
					{
					case 1:
						if ((fp2 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					case 2:
						if ((fp2 = fopen("c:\\mycode\\shop\\2.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					case 3:
						if ((fp2 = fopen("c:\\mycode\\shop\\3.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					case 4:
						if ((fp2 = fopen("c:\\mycode\\shop\\4.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					case 5:
						if ((fp2 = fopen("c:\\mycode\\shop\\5.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					}
					fseek(fp2, 13 + 37 * (j - 1), 0);
					for (k = 0; k < 36; k++)
					{
						ch = fgetc(fp2);
						a2[k] = ch;
					}

					fseek(fp2, 13 + 37 * (j - 1), 0);
					for (k = 0; k < 36; k++)
					{
						ch = a1[k];
						fputc(ch, fp2);
					}

					fseek(fp2, 13 + 37 * (j - 1), 0);
					length = fgetc(fp2);
					for (k = 0; k < 10; k++)
					{
						ch = fgetc(fp2);
						s2[j][k] = ch;
					}
					s2[j][2 * (length - 48)] = '\0';
					for (k = 1; k < 11; k++)
					{
						fseek(fp2, 13 + 37 * (k - 1) + 26, 0);
						ch = fgetc(fp2);
						money2[k - 1][0] = ch;
						ch = fgetc(fp2);
						money2[k - 1][1] = ch;
						ch = fgetc(fp2);
						money2[k - 1][2] = ch;
						ch = fgetc(fp2);
						money2[k - 1][3] = ch;
					}
					fclose(fp2);
					if ((fp1 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					fseek(fp1, 13 + 37 * (i - 1), 0);
					for (k = 0; k < 36; k++)
					{
						ch = a2[k];
						fputc(ch, fp1);
					}
					fseek(fp1, 13 + 37 * (i - 1), 0);
					length = fgetc(fp1);
					for (k = 0; k < 10; k++)
					{
						ch = fgetc(fp1);
						s1[i][k] = ch;
					}
					s1[i][2 * (length - 48)] = '\0';
					for (k = 1; k < 11; k++)
					{
						fseek(fp1, 13 + 37 * (k - 1) + 26, 0);
						ch = fgetc(fp1);
						money1[k - 1][0] = ch;
						ch = fgetc(fp1);
						money1[k - 1][1] = ch;
						ch = fgetc(fp1);
						money1[k - 1][2] = ch;
						ch = fgetc(fp1);
						money1[k - 1][3] = ch;
					}
					fclose(fp1);
					c2 = s1[i];
					c6 = s2[j];
					amount1 = (money2[(choose - 1) * 2 + 1][0] - 48) * 1000 + (money2[(choose - 1) * 2 + 1][1] - 48) * 100 + (money2[(choose - 1) * 2 + 1][2] - 48) * 10 + (money2[(choose - 1) * 2 + 1][3] - 48) * 1;
					amount2 = (money1[(choose - 1) * 2][0] - 48) * 1000 + (money1[(choose - 1) * 2][1] - 48) * 100 + (money1[(choose - 1) * 2][2] - 48) * 10 + (money1[(choose - 1) * 2][3] - 48) * 1;
					damount = amount1 - amount2;
					amount = (money[0] - 48) * 1000 + (money[1] - 48) * 100 + (money[2] - 48) * 10 + (money[3] - 48) * 1;
					amount += damount;
					for (i = 0; i < 4; i++)
					{
						money[3 - i] = amount % 10 + 48;
						amount = amount / 10;
					}
					if ((fp = fopen("c:\\mycode\\shop\\money.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					for (i = 0; i < 4; i++)
					{
						ch = money[i];
						fputc(ch, fp);
					}
					fclose(fp);
					setfillstyle(1, GREEN);
					setcolor(BLUE);
					bar(150, 113, 198, 125);
					bar(150, 313, 198, 325);
					bar(565, 113, 613, 125);
					bar(565, 313, 613, 325);
					bar(90, 60, 138, 72);
					for (i = 0; i < 4; i++)
					{
						draw_num(90 + i * 12, 60, money[i] - 48, 6);
					}
					for (i = 0; i < 4; i++)
					{
						draw_num(150 + i * 12, 113, money1[(choose - 1) * 2][i] - 48, 6);
					}
					for (i = 0; i < 4; i++)
					{
						draw_num(150 + i * 12, 313, money1[(choose - 1) * 2 + 1][i] - 48, 6);
					}
					for (i = 0; i < 4; i++)
					{
						draw_num(565 + i * 12, 113, money2[(choose - 1) * 2][i] - 48, 6);
					}
					for (i = 0; i < 4; i++)
					{
						draw_num(565 + i * 12, 313, money2[(choose - 1) * 2 + 1][i] - 48, 6);
					}

					setfillstyle(1, GREEN);
					bar(212, 100, 308, 132);
					bar(452, 300, 548, 332);
					setcolor(BLUE);
					rectangle(212, 100, 308, 132);
					rectangle(452, 300, 548, 332);
					puthz(212, 100, c2, 32, 32, BLUE);
					puthz(452, 300, c6, 32, 32, BLUE);

					change1 = 0;
					change4 = 0;
					bool = 0;
				}
			}
		}
		if (change1 == 1 && change3 == 1)
		{
			color1 = 0;
			color2 = 0;
			color3 = 0;
			color4 = 0;
			bool = 1;
			setfillstyle(1, GREEN);
			bar(136, 140, 365, 290);
			bar(380, 140, 609, 290);
			bar(136, 340, 365, 490);
			bar(380, 340, 609, 490);

			bar(212, 100, 308, 132);
			bar(212, 300, 308, 332);
			bar(452, 100, 548, 132);
			bar(452, 300, 548, 332);
			setcolor(BLUE);
			rectangle(212, 100, 308, 132);
			rectangle(212, 300, 308, 332);
			rectangle(452, 100, 548, 132);
			rectangle(452, 300, 548, 332);
			puthz(212, 100, c2, 32, 32, BLUE);
			puthz(212, 300, c3, 32, 32, BLUE);
			puthz(452, 100, c5, 32, 32, BLUE);
			puthz(452, 300, c6, 32, 32, BLUE);
			setfillstyle(1, LIGHTCYAN);
			bar(308, 140, 452, 290);
			setcolor(BLUE);
			rectangle(340, 210, 372, 242);
			rectangle(390, 210, 422, 242);
			puthz(350, 160, "交换", 32, 32, BLUE);
			puthz(340, 210, "是", 32, 32, BLUE);
			puthz(390, 210, "否", 32, 32, BLUE);
			while (bool)
			{
				Newxy();
				if (Mouse_press(390, 210, 422, 242))
				{
					NewBK();
					setcolor(BLUE);
					circle(330, 116, 10);
					circle(430, 116, 10);
					setfillstyle(1, GREEN);
					floodfill(330, 116, BLUE);
					floodfill(430, 116, BLUE);
					bar(308, 140, 452, 290);
					change1 = 0;
					change3 = 0;
					bool = 0;
				}
				if (Mouse_press(340, 210, 372, 242))
				{
					NewBK();
					setcolor(BLUE);
					circle(330, 116, 10);
					circle(430, 116, 10);
					setfillstyle(1, GREEN);
					floodfill(330, 116, BLUE);
					floodfill(430, 116, BLUE);
					bar(308, 140, 452, 290);

					for (i = 1; i < 11; i++)
					{
						if (strcmp(c2, s1[i]) == 0)
							break;
					}
					for (j = 1; j < 11; j++)
					{
						if (strcmp(c5, s2[j]) == 0)
							break;
					}
					if ((fp1 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					fseek(fp1, 13 + 37 * (i - 1), 0);
					for (k = 0; k < 36; k++)
					{
						ch = fgetc(fp1);
						a1[k] = ch;
					}
					fclose(fp1);
					switch (path - 48)
					{
					case 1:
						if ((fp2 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					case 2:
						if ((fp2 = fopen("c:\\mycode\\shop\\2.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					case 3:
						if ((fp2 = fopen("c:\\mycode\\shop\\3.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					case 4:
						if ((fp2 = fopen("c:\\mycode\\shop\\4.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					case 5:
						if ((fp2 = fopen("c:\\mycode\\shop\\5.txt", "r+")) == NULL)
						{
							setlinestyle(0, 0, 1);
							outtextxy(300, 300, "cannot open the file");
							exit(1);
						}
						break;
					}
					fseek(fp2, 13 + 37 * (j - 1), 0);
					for (k = 0; k < 36; k++)
					{
						ch = fgetc(fp2);
						a2[k] = ch;
					}

					fseek(fp2, 13 + 37 * (j - 1), 0);
					for (k = 0; k < 36; k++)
					{
						ch = a1[k];
						fputc(ch, fp2);
					}

					fseek(fp2, 13 + 37 * (j - 1), 0);
					length = fgetc(fp2);
					for (k = 0; k < 10; k++)
					{
						ch = fgetc(fp2);
						s2[j][k] = ch;
					}
					s2[j][2 * (length - 48)] = '\0';
					for (k = 1; k < 11; k++)
					{
						fseek(fp2, 13 + 37 * (k - 1) + 26, 0);
						ch = fgetc(fp2);
						money2[k - 1][0] = ch;
						ch = fgetc(fp2);
						money2[k - 1][1] = ch;
						ch = fgetc(fp2);
						money2[k - 1][2] = ch;
						ch = fgetc(fp2);
						money2[k - 1][3] = ch;
					}
					fclose(fp2);
					if ((fp1 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					fseek(fp1, 13 + 37 * (i - 1), 0);
					for (k = 0; k < 36; k++)
					{
						ch = a2[k];
						fputc(ch, fp1);
					}
					fseek(fp1, 13 + 37 * (i - 1), 0);
					length = fgetc(fp1);
					for (k = 0; k < 10; k++)
					{
						ch = fgetc(fp1);
						s1[i][k] = ch;
					}
					s1[i][2 * (length - 48)] = '\0';
					for (k = 1; k < 11; k++)
					{
						fseek(fp1, 13 + 37 * (k - 1) + 26, 0);
						ch = fgetc(fp1);
						money1[k - 1][0] = ch;
						ch = fgetc(fp1);
						money1[k - 1][1] = ch;
						ch = fgetc(fp1);
						money1[k - 1][2] = ch;
						ch = fgetc(fp1);
						money1[k - 1][3] = ch;
					}
					fclose(fp1);
					c2 = s1[i];
					c5 = s2[j];
					amount1 = (money2[(choose - 1) * 2][0] - 48) * 1000 + (money2[(choose - 1) * 2][1] - 48) * 100 + (money2[(choose - 1) * 2][2] - 48) * 10 + (money2[(choose - 1) * 2][3] - 48) * 1;
					amount2 = (money1[(choose - 1) * 2][0] - 48) * 1000 + (money1[(choose - 1) * 2][1] - 48) * 100 + (money1[(choose - 1) * 2][2] - 48) * 10 + (money1[(choose - 1) * 2][3] - 48) * 1;
					damount = amount1 - amount2;
					amount = (money[0] - 48) * 1000 + (money[1] - 48) * 100 + (money[2] - 48) * 10 + (money[3] - 48) * 1;
					amount += damount;
					for (i = 0; i < 4; i++)
					{
						money[3 - i] = amount % 10 + 48;
						amount = amount / 10;
					}
					if ((fp = fopen("c:\\mycode\\shop\\money.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					for (i = 0; i < 4; i++)
					{
						ch = money[i];
						fputc(ch, fp);
					}
					fclose(fp);
					setfillstyle(1, GREEN);
					setcolor(BLUE);
					bar(150, 113, 198, 125);
					bar(150, 313, 198, 325);
					bar(565, 113, 613, 125);
					bar(565, 313, 613, 325);
					bar(90, 60, 138, 72);
					for (i = 0; i < 4; i++)
					{
						draw_num(90 + i * 12, 60, money[i] - 48, 6);
					}
					for (i = 0; i < 4; i++)
					{
						draw_num(150 + i * 12, 113, money1[(choose - 1) * 2][i] - 48, 6);
					}
					for (i = 0; i < 4; i++)
					{
						draw_num(150 + i * 12, 313, money1[(choose - 1) * 2 + 1][i] - 48, 6);
					}
					for (i = 0; i < 4; i++)
					{
						draw_num(565 + i * 12, 113, money2[(choose - 1) * 2][i] - 48, 6);
					}
					for (i = 0; i < 4; i++)
					{
						draw_num(565 + i * 12, 313, money2[(choose - 1) * 2 + 1][i] - 48, 6);
					}

					setfillstyle(1, GREEN);
					bar(212, 100, 308, 132);
					bar(452, 100, 548, 132);
					setcolor(BLUE);
					rectangle(212, 100, 308, 132);
					rectangle(452, 100, 548, 132);
					puthz(212, 100, c2, 32, 32, BLUE);
					puthz(452, 100, c5, 32, 32, BLUE);

					change1 = 0;
					change3 = 0;
					bool = 0;
				}
			}
		}
		if (Mouse_press(420, 306, 440, 326))
		{
			delay(100);
			switch (change4)
			{
			case 0:
				if (change3 == 0)
				{
					NewBK();
					setfillstyle(1, GREEN);
					setcolor(BLUE);
					bar(420, 306, 450, 341);
					circle(430, 316, 10);
					setfillstyle(1, CYAN);
					floodfill(430, 316, BLUE);
					change4 = 1;
				}
				break;
			case 1:
				NewBK();
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(420, 306, 450, 341);
				circle(430, 316, 10);
				setfillstyle(1, GREEN);
				floodfill(430, 316, BLUE);
				change4 = 0;
				break;
			}
		}
		if (Mouse_press(420, 106, 440, 126))
		{
			delay(100);
			switch (change3)
			{
			case 0:
				if (change4 == 0)
				{
					NewBK();
					setfillstyle(1, GREEN);
					setcolor(BLUE);
					bar(420, 106, 450, 141);
					circle(430, 116, 10);
					setfillstyle(1, CYAN);
					floodfill(430, 116, BLUE);
					change3 = 1;
				}
				break;
			case 1:
				NewBK();
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(420, 106, 450, 141);
				circle(430, 116, 10);
				setfillstyle(1, GREEN);
				floodfill(430, 116, BLUE);
				change3 = 0;
				break;
			}
		}
		if (Mouse_press(320, 306, 340, 326))
		{
			delay(100);
			switch (change2)
			{
			case 0:
				if (change1 == 0)
				{
					NewBK();
					setfillstyle(1, GREEN);
					setcolor(BLUE);
					bar(320, 306, 350, 341);
					circle(330, 316, 10);
					setfillstyle(1, CYAN);
					floodfill(330, 316, BLUE);
					change2 = 1;
				}
				break;
			case 1:
				NewBK();
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(320, 306, 350, 341);
				circle(330, 316, 10);
				setfillstyle(1, GREEN);
				floodfill(330, 316, BLUE);
				change2 = 0;
				break;
			}
		}
		if (Mouse_press(320, 106, 340, 126))
		{
			delay(100);
			switch (change1)
			{
			case 0:
				if (change2 == 0)
				{
					NewBK();
					setfillstyle(1, GREEN);
					setcolor(BLUE);
					bar(320, 106, 350, 141);
					circle(330, 116, 10);
					setfillstyle(1, CYAN);
					floodfill(330, 116, BLUE);
					change1 = 1;
				}
				break;
			case 1:
				NewBK();
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(320, 106, 350, 141);
				circle(330, 116, 10);
				setfillstyle(1, GREEN);
				floodfill(330, 116, BLUE);
				change1 = 0;
				break;
			}
		}

		if (Mouse_press(452, 300, 548, 332))
		{
			delay(100);
			switch (color4)
			{
			case 0:
				NewBK();
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(452, 300, 558, 347);
				setfillstyle(1, YELLOW);
				bar(452, 300, 548, 332);
				rectangle(452, 300, 548, 332);
				puthz(452, 300, c6, 32, 32, BLUE);

				bar(380, 340, 609, 490);
				rectangle(380, 340, 609, 490);
				puthz(414, 340, "速度", 32, 32, BLUE);
				puthz(414, 372, "力量", 32, 32, BLUE);
				puthz(414, 404, "断球", 32, 32, BLUE);
				puthz(414, 436, "抢球", 32, 32, BLUE);
				puthz(429, 468, "CD", 16, 16, BLUE);

				for (i = 1; i < 11; i++)
				{
					if (strcmp(c6, s2[i]) == 0)
						break;
				}

				switch (path - 48)
				{
				case 1:
					if ((fp2 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					break;
				case 2:
					if ((fp2 = fopen("c:\\mycode\\shop\\2.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					break;
				case 3:
					if ((fp2 = fopen("c:\\mycode\\shop\\3.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					break;
				case 4:
					if ((fp2 = fopen("c:\\mycode\\shop\\4.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					break;
				case 5:
					if ((fp2 = fopen("c:\\mycode\\shop\\5.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					break;
				}
				fseek(fp2, 13 + 37 * (i - 1) + 11, 0);
				for (j = 0; j < 5; j++)
				{
					for (i = 0; i < 3; i++)
					{
						ch = fgetc(fp2);
						ability4[j][i] = ch;
					}
					ability4[j][i] = '\0';
				}
				fclose(fp2);
				for (j = 0; j < 5; j++)
					for (i = 0; i < 3; i++)
					{
						ability = ability4[j][i] - 48;
						if (j < 4)
							draw_num(499 + i * 15, 350 + j * 32, ability, 6);
						else
							draw_num(499 + i * 15, 350 + j * 32 - 10, ability, 5);
					}
				color4 = 1;
				break;
			case 1:
				NewBK();
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(452, 300, 558, 347);
				bar(380, 340, 609, 490);
				rectangle(452, 300, 548, 332);
				puthz(452, 300, c6, 32, 32, BLUE);
				color4 = 0;
				break;
			}
		}

		if (Mouse_press(452, 100, 548, 132))
		{
			delay(100);
			switch (color3)
			{
			case 0:
				NewBK();
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(452, 100, 558, 147);
				setfillstyle(1, YELLOW);
				bar(452, 100, 548, 132);
				rectangle(452, 100, 548, 132);
				puthz(452, 100, c5, 32, 32, BLUE);

				bar(380, 140, 609, 290);
				rectangle(380, 140, 609, 290);
				puthz(414, 140, "速度", 32, 32, BLUE);
				puthz(414, 172, "力量", 32, 32, BLUE);
				puthz(414, 204, "断球", 32, 32, BLUE);
				puthz(414, 236, "抢球", 32, 32, BLUE);
				puthz(429, 275, "CD", 16, 16, BLUE);

				for (i = 1; i < 11; i++)
				{
					if (strcmp(c5, s2[i]) == 0)
						break;
				}

				switch (path - 48)
				{
				case 1:
					if ((fp2 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					break;
				case 2:
					if ((fp2 = fopen("c:\\mycode\\shop\\2.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					break;
				case 3:
					if ((fp2 = fopen("c:\\mycode\\shop\\3.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					break;
				case 4:
					if ((fp2 = fopen("c:\\mycode\\shop\\4.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					break;
				case 5:
					if ((fp2 = fopen("c:\\mycode\\shop\\5.txt", "r+")) == NULL)
					{
						setlinestyle(0, 0, 1);
						outtextxy(300, 300, "cannot open the file");
						exit(1);
					}
					break;
				}
				fseek(fp2, 13 + 37 * (i - 1) + 11, 0);
				for (j = 0; j < 5; j++)
				{
					for (i = 0; i < 3; i++)
					{
						ch = fgetc(fp2);
						ability3[j][i] = ch;
					}
					ability3[j][i] = '\0';
				}
				fclose(fp2);
				for (j = 0; j < 5; j++)
					for (i = 0; i < 3; i++)
					{
						ability = ability3[j][i] - 48;
						if (j < 4)
							draw_num(499 + i * 15, 150 + j * 32, ability, 6);
						else
							draw_num(499 + i * 15, 150 + j * 32 - 5, ability, 6);
					}
				color3 = 1;
				break;
			case 1:
				NewBK();
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(452, 100, 558, 147);
				bar(380, 140, 609, 290);
				rectangle(452, 100, 548, 132);
				puthz(452, 100, c5, 32, 32, BLUE);
				color3 = 0;
				break;
			}
		}

		if (Mouse_press(212, 300, 308, 332))
		{
			delay(100);
			switch (color2)
			{
			case 0:
				NewBK();
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(212, 300, 318, 347);
				setfillstyle(1, YELLOW);
				bar(212, 300, 308, 332);
				rectangle(212, 300, 308, 332);
				puthz(212, 300, c3, 32, 32, BLUE);
				bar(136, 340, 365, 479);
				rectangle(136, 340, 365, 479);
				puthz(170, 340, "速度", 32, 32, BLUE);
				puthz(170, 372, "力量", 32, 32, BLUE);
				puthz(170, 404, "断球", 32, 32, BLUE);
				puthz(170, 436, "抢球", 32, 32, BLUE);
				puthz(185, 468, "CD", 16, 16, BLUE);

				for (i = 1; i < 11; i++)
				{
					if (strcmp(c3, s1[i]) == 0)
						break;
				}
				if ((fp1 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
				{
					setlinestyle(0, 0, 1);
					outtextxy(300, 300, "cannot open the file");
					exit(1);
				}
				fseek(fp1, 13 + 37 * (i - 1) + 11, 0);
				for (j = 0; j < 5; j++)
				{
					for (i = 0; i < 3; i++)
					{
						ch = fgetc(fp1);
						ability2[j][i] = ch;
					}
					ability2[j][i] = '\0';
				}
				fclose(fp1);
				for (j = 0; j < 5; j++)
					for (i = 0; i < 3; i++)
					{
						ability = ability2[j][i] - 48;
						if (j < 4)
							draw_num(250 + i * 15, 350 + j * 32, ability, 6);
						else
							draw_num(250 + i * 15, 350 + j * 32 - 10, ability, 5);
					}
				color2 = 1;
				break;
			case 1:
				NewBK();
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(212, 300, 318, 347);
				bar(136, 340, 365, 490);
				rectangle(212, 300, 308, 332);
				puthz(212, 300, c3, 32, 32, BLUE);
				color2 = 0;
				break;
			}
		}

		if (Mouse_press(212, 100, 308, 132))
		{
			delay(100);
			switch (color1)
			{
			case 0:
				NewBK();
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(212, 100, 318, 147);
				setfillstyle(1, YELLOW);
				bar(212, 100, 308, 132);
				rectangle(212, 100, 308, 132);
				puthz(212, 100, c2, 32, 32, BLUE);

				bar(136, 140, 365, 290);
				rectangle(136, 140, 365, 290);
				puthz(170, 140, "速度", 32, 32, BLUE);
				puthz(170, 172, "力量", 32, 32, BLUE);
				puthz(170, 204, "断球", 32, 32, BLUE);
				puthz(170, 236, "抢球", 32, 32, BLUE);
				puthz(185, 275, "CD", 16, 16, BLUE);

				for (i = 1; i < 11; i++)
				{
					if (strcmp(c2, s1[i]) == 0)
						break;
				}
				if ((fp1 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
				{
					setlinestyle(0, 0, 1);
					outtextxy(300, 300, "cannot open the file");
					exit(1);
				}
				fseek(fp1, 13 + 37 * (i - 1) + 11, 0);
				for (j = 0; j < 5; j++)
				{
					for (i = 0; i < 3; i++)
					{
						ch = fgetc(fp1);
						ability1[j][i] = ch;
					}
					ability1[j][i] = '\0';
				}
				fclose(fp1);
				for (j = 0; j < 5; j++)
					for (i = 0; i < 3; i++)
					{
						ability = ability1[j][i] - 48;
						if (j < 4)
							draw_num(250 + i * 15, 150 + j * 32, ability, 6);
						else
							draw_num(250 + i * 15, 150 + j * 32 - 5, ability, 6);
					}
				color1 = 1;
				break;
			case 1:
				NewBK();
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(212, 100, 318, 147);
				bar(136, 140, 365, 290);
				rectangle(212, 100, 308, 132);
				puthz(212, 100, c2, 32, 32, BLUE);
				color1 = 0;
				break;
			}
		}

		if (Mouse_press(400, 50, 410, 82))
		{
			color1 = 0;
			color2 = 0;
			color3 = 0;
			color4 = 0;

			setfillstyle(1, GREEN);
			bar(136, 140, 365, 290);
			bar(136, 340, 365, 490);
			bar(380, 140, 609, 290);
			bar(380, 340, 609, 490);

			switch (path_)
			{

			case 1:
				path -= 1;
				if (path - 48 == 1)
				{
					path = 53;
				}
				break;
			case 2:
				path -= 1;
				switch (path - 48)
				{
				case 2:
					path = 49;
					break;
				case 0:
					path = 53;
					break;
				}
				break;
			case 3:
				path -= 1;
				switch (path - 48)
				{
				case 3:
					path = 50;
					break;
				case 0:
					path = 53;
					break;
				}
				break;
			case 4:
				path -= 1;
				switch (path - 48)
				{
				case 4:
					path = 51;
					break;
				case 0:
					path = 53;
					break;
				}
				break;
			case 5:
				path -= 1;
				switch (path - 48)
				{
				case 0:
					path = 52;
					break;
				}
				break;
			}

			switch (path - 48)
			{
			case 1:
				if ((fp2 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
				{
					setlinestyle(0, 0, 1);
					outtextxy(300, 300, "cannot open the file");
					exit(1);
				}
				break;
			case 2:
				if ((fp2 = fopen("c:\\mycode\\shop\\2.txt", "r+")) == NULL)
				{
					setlinestyle(0, 0, 1);
					outtextxy(300, 300, "cannot open the file");
					exit(1);
				}
				break;
			case 3:
				if ((fp2 = fopen("c:\\mycode\\shop\\3.txt", "r+")) == NULL)
				{
					setlinestyle(0, 0, 1);
					outtextxy(300, 300, "cannot open the file");
					exit(1);
				}
				break;
			case 4:
				if ((fp2 = fopen("c:\\mycode\\shop\\4.txt", "r+")) == NULL)
				{
					setlinestyle(0, 0, 1);
					outtextxy(300, 300, "cannot open the file");
					exit(1);
				}
				break;
			case 5:
				if ((fp2 = fopen("c:\\mycode\\shop\\5.txt", "r+")) == NULL)
				{
					setlinestyle(0, 0, 1);
					outtextxy(300, 300, "cannot open the file");
					exit(1);
				}
				break;
			}
			length = fgetc(fp2);
			for (i = 0; i < 10; i++)
			{
				ch = fgetc(fp2);
				s2[0][i] = ch;
			}
			s2[0][2 * (length - 48)] = '\0';
			ch = fgetc(fp2);

			for (j = 1; j < 11; j++)
			{
				length = fgetc(fp2);
				for (i = 0; i < 10; i++)
				{
					ch = fgetc(fp2);
					s2[j][i] = ch;
				}
				s2[j][2 * (length - 48)] = '\0';
				if (j < 10)
					fseek(fp2, 26, 1);
			}
			fclose(fp2);
			switch (choose)
			{
			case 1:
				c4 = s2[0];
				c5 = s2[1];
				c6 = s2[2];
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(180, 50, 340, 82);
				rectangle(180, 50, 340, 82);
				puthz(195, 50, c1, 32, 32, BLUE);
				bar(212, 100, 308, 132);
				rectangle(212, 100, 308, 132);
				puthz(212, 100, c2, 32, 32, BLUE);
				bar(212, 300, 308, 332);
				rectangle(212, 300, 308, 332);
				puthz(212, 300, c3, 32, 32, BLUE);
				bar(420, 50, 580, 82);
				rectangle(420, 50, 580, 82);
				puthz(435, 50, c4, 32, 32, BLUE);
				bar(452, 100, 548, 132);
				rectangle(452, 100, 548, 132);
				puthz(452, 100, c5, 32, 32, BLUE);
				bar(452, 300, 548, 332);
				rectangle(452, 300, 548, 332);
				puthz(452, 300, c6, 32, 32, BLUE);
				break;

			case 2:
				c4 = s2[0];
				c5 = s2[3];
				c6 = s2[4];
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(180, 50, 340, 82);
				rectangle(180, 50, 340, 82);
				puthz(195, 50, c1, 32, 32, BLUE);
				bar(212, 100, 308, 132);
				rectangle(212, 100, 308, 132);
				puthz(212, 100, c2, 32, 32, BLUE);
				bar(212, 300, 308, 332);
				rectangle(212, 300, 308, 332);
				puthz(212, 300, c3, 32, 32, BLUE);
				bar(420, 50, 580, 82);
				rectangle(420, 50, 580, 82);
				puthz(435, 50, c4, 32, 32, BLUE);
				bar(452, 100, 548, 132);
				rectangle(452, 100, 548, 132);
				puthz(452, 100, c5, 32, 32, BLUE);
				bar(452, 300, 548, 332);
				rectangle(452, 300, 548, 332);
				puthz(452, 300, c6, 32, 32, BLUE);
				break;

			case 3:
				c4 = s2[0];
				c5 = s2[5];
				c6 = s2[6];
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(180, 50, 340, 82);
				rectangle(180, 50, 340, 82);
				puthz(195, 50, c1, 32, 32, BLUE);
				bar(212, 100, 308, 132);
				rectangle(212, 100, 308, 132);
				puthz(212, 100, c2, 32, 32, BLUE);
				bar(212, 300, 308, 332);
				rectangle(212, 300, 308, 332);
				puthz(212, 300, c3, 32, 32, BLUE);
				bar(420, 50, 580, 82);
				rectangle(420, 50, 580, 82);
				puthz(435, 50, c4, 32, 32, BLUE);
				bar(452, 100, 548, 132);
				rectangle(452, 100, 548, 132);
				puthz(452, 100, c5, 32, 32, BLUE);
				bar(452, 300, 548, 332);
				rectangle(452, 300, 548, 332);
				puthz(452, 300, c6, 32, 32, BLUE);
				break;

			case 4:
				c4 = s2[0];
				c5 = s2[7];
				c6 = s2[8];
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(180, 50, 340, 82);
				rectangle(180, 50, 340, 82);
				puthz(195, 50, c1, 32, 32, BLUE);
				bar(212, 100, 308, 132);
				rectangle(212, 100, 308, 132);
				puthz(212, 100, c2, 32, 32, BLUE);
				bar(212, 300, 308, 332);
				rectangle(212, 300, 308, 332);
				puthz(212, 300, c3, 32, 32, BLUE);
				bar(420, 50, 580, 82);
				rectangle(420, 50, 580, 82);
				puthz(435, 50, c4, 32, 32, BLUE);
				bar(452, 100, 548, 132);
				rectangle(452, 100, 548, 132);
				puthz(452, 100, c5, 32, 32, BLUE);
				bar(452, 300, 548, 332);
				rectangle(452, 300, 548, 332);
				puthz(452, 300, c6, 32, 32, BLUE);
				break;

			case 5:
				c4 = s2[0];
				c5 = s2[9];
				c6 = s2[10];
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(180, 50, 340, 82);
				rectangle(180, 50, 340, 82);
				puthz(195, 50, c1, 32, 32, BLUE);
				bar(212, 100, 308, 132);
				rectangle(212, 100, 308, 132);
				puthz(212, 100, c2, 32, 32, BLUE);
				bar(212, 300, 308, 332);
				rectangle(212, 300, 308, 332);
				puthz(212, 300, c3, 32, 32, BLUE);
				bar(420, 50, 580, 82);
				rectangle(420, 50, 580, 82);
				puthz(435, 50, c4, 32, 32, BLUE);
				bar(452, 100, 548, 132);
				rectangle(452, 100, 548, 132);
				puthz(452, 100, c5, 32, 32, BLUE);
				bar(452, 300, 548, 332);
				rectangle(452, 300, 548, 332);
				puthz(452, 300, c6, 32, 32, BLUE);
				break;
			}

			if ((fp = fopen("c:\\mycode\\shop\\path.txt", "r+")) == NULL)
			{
				setlinestyle(0, 0, 1);
				outtextxy(300, 300, "cannot open the file");
				exit(1);
			}
			fputc(path, fp);
			fclose(fp);
		}

		if (Mouse_press(590, 50, 600, 82))
		{
			color1 = 0;
			color2 = 0;
			color3 = 0;
			color4 = 0;
			setfillstyle(1, GREEN);
			bar(136, 140, 365, 290);
			bar(136, 340, 365, 490);
			bar(380, 140, 609, 290);
			bar(380, 340, 609, 490);

			switch (path_)
			{

			case 1:
				path += 1;
				switch (path - 48)
				{
				case 6:
					path = 50;
					break;
				}
				break;
			case 2:
				path += 1;
				switch (path - 48)
				{
				case 2:
					path = 51;
					break;
				case 6:
					path = 49;
					break;
				}
				break;
			case 3:
				path += 1;
				switch (path - 48)
				{
				case 3:
					path = 52;
					break;
				case 6:
					path = 49;
					break;
				}
				break;
			case 4:
				path += 1;
				switch (path - 48)
				{
				case 4:
					path = 53;
					break;
				case 6:
					path = 49;
					break;
				}
				break;
			case 5:
				path += 1;
				switch (path - 48)
				{
				case 5:
					path = 49;
					break;
				}
				break;
			}

			switch (path - 48)
			{
			case 1:
				if ((fp2 = fopen("c:\\mycode\\shop\\1.txt", "r+")) == NULL)
				{
					setlinestyle(0, 0, 1);
					outtextxy(300, 300, "cannot open the file");
					exit(1);
				}
				break;
			case 2:
				if ((fp2 = fopen("c:\\mycode\\shop\\2.txt", "r+")) == NULL)
				{
					setlinestyle(0, 0, 1);
					outtextxy(300, 300, "cannot open the file");
					exit(1);
				}
				break;
			case 3:
				if ((fp2 = fopen("c:\\mycode\\shop\\3.txt", "r+")) == NULL)
				{
					setlinestyle(0, 0, 1);
					outtextxy(300, 300, "cannot open the file");
					exit(1);
				}
				break;
			case 4:
				if ((fp2 = fopen("c:\\mycode\\shop\\4.txt", "r+")) == NULL)
				{
					setlinestyle(0, 0, 1);
					outtextxy(300, 300, "cannot open the file");
					exit(1);
				}
				break;
			case 5:
				if ((fp2 = fopen("c:\\mycode\\shop\\5.txt", "r+")) == NULL)
				{
					setlinestyle(0, 0, 1);
					outtextxy(300, 300, "cannot open the file");
					exit(1);
				}
				break;
			}
			length = fgetc(fp2);
			for (i = 0; i < 10; i++)
			{
				ch = fgetc(fp2);
				s2[0][i] = ch;
			}
			s2[0][2 * (length - 48)] = '\0';
			ch = fgetc(fp2);

			for (j = 1; j < 11; j++)
			{
				length = fgetc(fp2);
				for (i = 0; i < 10; i++)
				{
					ch = fgetc(fp2);
					s2[j][i] = ch;
				}
				s2[j][2 * (length - 48)] = '\0';
				if (j < 10)
					fseek(fp2, 26, 1);
			}
			fclose(fp2);
			switch (choose)
			{
			case 1:
				c4 = s2[0];
				c5 = s2[1];
				c6 = s2[2];
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(180, 50, 340, 82);
				rectangle(180, 50, 340, 82);
				puthz(195, 50, c1, 32, 32, BLUE);
				bar(212, 100, 308, 132);
				rectangle(212, 100, 308, 132);
				puthz(212, 100, c2, 32, 32, BLUE);
				bar(212, 300, 308, 332);
				rectangle(212, 300, 308, 332);
				puthz(212, 300, c3, 32, 32, BLUE);
				bar(420, 50, 580, 82);
				rectangle(420, 50, 580, 82);
				puthz(435, 50, c4, 32, 32, BLUE);
				bar(452, 100, 548, 132);
				rectangle(452, 100, 548, 132);
				puthz(452, 100, c5, 32, 32, BLUE);
				bar(452, 300, 548, 332);
				rectangle(452, 300, 548, 332);
				puthz(452, 300, c6, 32, 32, BLUE);
				break;

			case 2:
				c4 = s2[0];
				c5 = s2[3];
				c6 = s2[4];
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(180, 50, 340, 82);
				rectangle(180, 50, 340, 82);
				puthz(195, 50, c1, 32, 32, BLUE);
				bar(212, 100, 308, 132);
				rectangle(212, 100, 308, 132);
				puthz(212, 100, c2, 32, 32, BLUE);
				bar(212, 300, 308, 332);
				rectangle(212, 300, 308, 332);
				puthz(212, 300, c3, 32, 32, BLUE);
				bar(420, 50, 580, 82);
				rectangle(420, 50, 580, 82);
				puthz(435, 50, c4, 32, 32, BLUE);
				bar(452, 100, 548, 132);
				rectangle(452, 100, 548, 132);
				puthz(452, 100, c5, 32, 32, BLUE);
				bar(452, 300, 548, 332);
				rectangle(452, 300, 548, 332);
				puthz(452, 300, c6, 32, 32, BLUE);
				break;

			case 3:
				c4 = s2[0];
				c5 = s2[5];
				c6 = s2[6];
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(180, 50, 340, 82);
				rectangle(180, 50, 340, 82);
				puthz(195, 50, c1, 32, 32, BLUE);
				bar(212, 100, 308, 132);
				rectangle(212, 100, 308, 132);
				puthz(212, 100, c2, 32, 32, BLUE);
				bar(212, 300, 308, 332);
				rectangle(212, 300, 308, 332);
				puthz(212, 300, c3, 32, 32, BLUE);
				bar(420, 50, 580, 82);
				rectangle(420, 50, 580, 82);
				puthz(435, 50, c4, 32, 32, BLUE);
				bar(452, 100, 548, 132);
				rectangle(452, 100, 548, 132);
				puthz(452, 100, c5, 32, 32, BLUE);
				bar(452, 300, 548, 332);
				rectangle(452, 300, 548, 332);
				puthz(452, 300, c6, 32, 32, BLUE);
				break;

			case 4:
				c4 = s2[0];
				c5 = s2[7];
				c6 = s2[8];
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(180, 50, 340, 82);
				rectangle(180, 50, 340, 82);
				puthz(195, 50, c1, 32, 32, BLUE);
				bar(212, 100, 308, 132);
				rectangle(212, 100, 308, 132);
				puthz(212, 100, c2, 32, 32, BLUE);
				bar(212, 300, 308, 332);
				rectangle(212, 300, 308, 332);
				puthz(212, 300, c3, 32, 32, BLUE);
				bar(420, 50, 580, 82);
				rectangle(420, 50, 580, 82);
				puthz(435, 50, c4, 32, 32, BLUE);
				bar(452, 100, 548, 132);
				rectangle(452, 100, 548, 132);
				puthz(452, 100, c5, 32, 32, BLUE);
				bar(452, 300, 548, 332);
				rectangle(452, 300, 548, 332);
				puthz(452, 300, c6, 32, 32, BLUE);
				break;

			case 5:
				c4 = s2[0];
				c5 = s2[9];
				c6 = s2[10];
				setfillstyle(1, GREEN);
				setcolor(BLUE);
				bar(180, 50, 340, 82);
				rectangle(180, 50, 340, 82);
				puthz(195, 50, c1, 32, 32, BLUE);
				bar(212, 100, 308, 132);
				rectangle(212, 100, 308, 132);
				puthz(212, 100, c2, 32, 32, BLUE);
				bar(212, 300, 308, 332);
				rectangle(212, 300, 308, 332);
				puthz(212, 300, c3, 32, 32, BLUE);
				bar(420, 50, 580, 82);
				rectangle(420, 50, 580, 82);
				puthz(435, 50, c4, 32, 32, BLUE);
				bar(452, 100, 548, 132);
				rectangle(452, 100, 548, 132);
				puthz(452, 100, c5, 32, 32, BLUE);
				bar(452, 300, 548, 332);
				rectangle(452, 300, 548, 332);
				puthz(452, 300, c6, 32, 32, BLUE);
				break;
			}

			if ((fp = fopen("c:\\mycode\\shop\\path.txt", "r+")) == NULL)
			{
				setlinestyle(0, 0, 1);
				outtextxy(300, 300, "cannot open the file");
				exit(1);
			}
			fputc(path, fp);
			fclose(fp);
		}

		if (Mouse_press(30, 100, 126, 132))
		{
			color1 = 0;
			color2 = 0;
			color3 = 0;
			color4 = 0;
			choose = 1;
			c2 = s1[1];
			c3 = s1[2];
			c5 = s2[1];
			c6 = s2[2];
			setfillstyle(1, GREEN);
			setcolor(BLUE);
			bar(150, 113, 198, 125);
			bar(150, 313, 198, 325);
			bar(565, 113, 613, 125);
			bar(565, 313, 613, 325);
			for (i = 0; i < 4; i++)
			{
				draw_num(150 + i * 12, 113, money1[0][i] - 48, 6);
			}
			for (i = 0; i < 4; i++)
			{
				draw_num(150 + i * 12, 313, money1[1][i] - 48, 6);
			}
			for (i = 0; i < 4; i++)
			{
				draw_num(565 + i * 12, 113, money2[0][i] - 48, 6);
			}
			for (i = 0; i < 4; i++)
			{
				draw_num(565 + i * 12, 313, money2[1][i] - 48, 6);
			}

			bar(1, 100, 21, 132);
			bar(1, 150, 21, 182);
			bar(1, 200, 21, 232);
			bar(1, 250, 21, 282);
			bar(1, 300, 21, 332);
			line(1, 116, 11, 132);
			line(11, 132, 21, 100);

			bar(136, 140, 365, 290);
			bar(136, 340, 365, 490);
			bar(380, 140, 609, 290);
			bar(380, 340, 609, 490);

			bar(180, 50, 340, 82);
			rectangle(180, 50, 340, 82);
			puthz(195, 50, c1, 32, 32, BLUE);
			bar(212, 100, 308, 132);
			rectangle(212, 100, 308, 132);
			puthz(212, 100, c2, 32, 32, BLUE);
			bar(212, 300, 308, 332);
			rectangle(212, 300, 308, 332);
			puthz(212, 300, c3, 32, 32, BLUE);
			bar(420, 50, 580, 82);
			rectangle(420, 50, 580, 82);
			puthz(435, 50, c4, 32, 32, BLUE);
			bar(452, 100, 548, 132);
			rectangle(452, 100, 548, 132);
			puthz(452, 100, c5, 32, 32, BLUE);
			bar(452, 300, 548, 332);
			rectangle(452, 300, 548, 332);
			puthz(452, 300, c6, 32, 32, BLUE);
		}
		if (Mouse_press(30, 150, 126, 182))
		{
			color1 = 0;
			color2 = 0;
			color3 = 0;
			color4 = 0;
			choose = 2;
			c2 = s1[3];
			c3 = s1[4];
			c5 = s2[3];
			c6 = s2[4];
			setfillstyle(1, GREEN);
			setcolor(BLUE);
			bar(150, 113, 198, 125);
			bar(150, 313, 198, 325);
			bar(565, 113, 613, 125);
			bar(565, 313, 613, 325);
			for (i = 0; i < 4; i++)
			{
				draw_num(150 + i * 12, 113, money1[2][i] - 48, 6);
			}
			for (i = 0; i < 4; i++)
			{
				draw_num(150 + i * 12, 313, money1[3][i] - 48, 6);
			}
			for (i = 0; i < 4; i++)
			{
				draw_num(565 + i * 12, 113, money2[2][i] - 48, 6);
			}
			for (i = 0; i < 4; i++)
			{
				draw_num(565 + i * 12, 313, money2[3][i] - 48, 6);
			}

			bar(1, 100, 21, 132);
			bar(1, 150, 21, 182);
			bar(1, 200, 21, 232);
			bar(1, 250, 21, 282);
			bar(1, 300, 21, 332);
			line(1, 166, 11, 182);
			line(11, 182, 21, 150);

			bar(136, 140, 365, 290);
			bar(136, 340, 365, 490);
			bar(380, 140, 609, 290);
			bar(380, 340, 609, 490);

			bar(180, 50, 340, 82);
			rectangle(180, 50, 340, 82);
			puthz(195, 50, c1, 32, 32, BLUE);
			bar(212, 100, 308, 132);
			rectangle(212, 100, 308, 132);
			puthz(212, 100, c2, 32, 32, BLUE);
			bar(212, 300, 308, 332);
			rectangle(212, 300, 308, 332);
			puthz(212, 300, c3, 32, 32, BLUE);
			bar(420, 50, 580, 82);
			rectangle(420, 50, 580, 82);
			puthz(435, 50, c4, 32, 32, BLUE);
			bar(452, 100, 548, 132);
			rectangle(452, 100, 548, 132);
			puthz(452, 100, c5, 32, 32, BLUE);
			bar(452, 300, 548, 332);
			rectangle(452, 300, 548, 332);
			puthz(452, 300, c6, 32, 32, BLUE);
		}
		if (Mouse_press(30, 200, 126, 232))
		{
			color1 = 0;
			color2 = 0;
			color3 = 0;
			color4 = 0;
			choose = 3;
			c2 = s1[5];
			c3 = s1[6];
			c5 = s2[5];
			c6 = s2[6];
			setfillstyle(1, GREEN);
			setcolor(BLUE);
			bar(150, 113, 198, 125);
			bar(150, 313, 198, 325);
			bar(565, 113, 613, 125);
			bar(565, 313, 613, 325);
			for (i = 0; i < 4; i++)
			{
				draw_num(150 + i * 12, 113, money1[4][i] - 48, 6);
			}
			for (i = 0; i < 4; i++)
			{
				draw_num(150 + i * 12, 313, money1[5][i] - 48, 6);
			}
			for (i = 0; i < 4; i++)
			{
				draw_num(565 + i * 12, 113, money2[4][i] - 48, 6);
			}
			for (i = 0; i < 4; i++)
			{
				draw_num(565 + i * 12, 313, money2[5][i] - 48, 6);
			}

			bar(1, 100, 21, 132);
			bar(1, 150, 21, 182);
			bar(1, 200, 21, 232);
			bar(1, 250, 21, 282);
			bar(1, 300, 21, 332);
			line(1, 216, 11, 232);
			line(11, 232, 21, 200);

			bar(136, 140, 365, 290);
			bar(136, 340, 365, 490);
			bar(380, 140, 609, 290);
			bar(380, 340, 609, 490);

			bar(180, 50, 340, 82);
			rectangle(180, 50, 340, 82);
			puthz(195, 50, c1, 32, 32, BLUE);
			bar(212, 100, 308, 132);
			rectangle(212, 100, 308, 132);
			puthz(212, 100, c2, 32, 32, BLUE);
			bar(212, 300, 308, 332);
			rectangle(212, 300, 308, 332);
			puthz(212, 300, c3, 32, 32, BLUE);
			bar(420, 50, 580, 82);
			rectangle(420, 50, 580, 82);
			puthz(435, 50, c4, 32, 32, BLUE);
			bar(452, 100, 548, 132);
			rectangle(452, 100, 548, 132);
			puthz(452, 100, c5, 32, 32, BLUE);
			bar(452, 300, 548, 332);
			rectangle(452, 300, 548, 332);
			puthz(452, 300, c6, 32, 32, BLUE);
		}
		if (Mouse_press(30, 250, 126, 282))
		{
			color1 = 0;
			color2 = 0;
			color3 = 0;
			color4 = 0;
			choose = 4;
			c2 = s1[7];
			c3 = s1[8];
			c5 = s2[7];
			c6 = s2[8];
			setfillstyle(1, GREEN);
			setcolor(BLUE);
			bar(150, 113, 198, 125);
			bar(150, 313, 198, 325);
			bar(565, 113, 613, 125);
			bar(565, 313, 613, 325);
			for (i = 0; i < 4; i++)
			{
				draw_num(150 + i * 12, 113, money1[6][i] - 48, 6);
			}
			for (i = 0; i < 4; i++)
			{
				draw_num(150 + i * 12, 313, money1[7][i] - 48, 6);
			}
			for (i = 0; i < 4; i++)
			{
				draw_num(565 + i * 12, 113, money2[6][i] - 48, 6);
			}
			for (i = 0; i < 4; i++)
			{
				draw_num(565 + i * 12, 313, money2[7][i] - 48, 6);
			}

			bar(1, 100, 21, 132);
			bar(1, 150, 21, 182);
			bar(1, 200, 21, 232);
			bar(1, 250, 21, 282);
			bar(1, 300, 21, 332);
			line(1, 266, 11, 282);
			line(11, 282, 21, 250);

			bar(136, 140, 365, 290);
			bar(136, 340, 365, 490);
			bar(380, 140, 609, 290);
			bar(380, 340, 609, 490);

			bar(180, 50, 340, 82);
			rectangle(180, 50, 340, 82);
			puthz(195, 50, c1, 32, 32, BLUE);
			bar(212, 100, 308, 132);
			rectangle(212, 100, 308, 132);
			puthz(212, 100, c2, 32, 32, BLUE);
			bar(212, 300, 308, 332);
			rectangle(212, 300, 308, 332);
			puthz(212, 300, c3, 32, 32, BLUE);
			bar(420, 50, 580, 82);
			rectangle(420, 50, 580, 82);
			puthz(435, 50, c4, 32, 32, BLUE);
			bar(452, 100, 548, 132);
			rectangle(452, 100, 548, 132);
			puthz(452, 100, c5, 32, 32, BLUE);
			bar(452, 300, 548, 332);
			rectangle(452, 300, 548, 332);
			puthz(452, 300, c6, 32, 32, BLUE);
		}
		if (Mouse_press(30, 300, 126, 332))
		{
			color1 = 0;
			color2 = 0;
			color3 = 0;
			color4 = 0;
			choose = 5;
			c2 = s1[9];
			c3 = s1[10];
			c5 = s2[9];
			c6 = s2[10];
			setfillstyle(1, GREEN);
			setcolor(BLUE);
			bar(150, 113, 198, 125);
			bar(150, 313, 198, 325);
			bar(565, 113, 613, 125);
			bar(565, 313, 613, 325);
			for (i = 0; i < 4; i++)
			{
				draw_num(150 + i * 12, 113, money1[8][i] - 48, 6);
			}
			for (i = 0; i < 4; i++)
			{
				draw_num(150 + i * 12, 313, money1[9][i] - 48, 6);
			}
			for (i = 0; i < 4; i++)
			{
				draw_num(565 + i * 12, 113, money2[8][i] - 48, 6);
			}
			for (i = 0; i < 4; i++)
			{
				draw_num(565 + i * 12, 313, money2[9][i] - 48, 6);
			}

			bar(1, 100, 21, 132);
			bar(1, 150, 21, 182);
			bar(1, 200, 21, 232);
			bar(1, 250, 21, 282);
			bar(1, 300, 21, 332);
			line(1, 316, 11, 332);
			line(11, 332, 21, 300);

			bar(136, 140, 365, 290);
			bar(136, 340, 365, 490);
			bar(380, 140, 609, 290);
			bar(380, 340, 609, 490);

			bar(180, 50, 340, 82);
			rectangle(180, 50, 340, 82);
			puthz(195, 50, c1, 32, 32, BLUE);
			bar(212, 100, 308, 132);
			rectangle(212, 100, 308, 132);
			puthz(212, 100, c2, 32, 32, BLUE);
			bar(212, 300, 308, 332);
			rectangle(212, 300, 308, 332);
			puthz(212, 300, c3, 32, 32, BLUE);
			bar(420, 50, 580, 82);
			rectangle(420, 50, 580, 82);
			puthz(435, 50, c4, 32, 32, BLUE);
			bar(452, 100, 548, 132);
			rectangle(452, 100, 548, 132);
			puthz(452, 100, c5, 32, 32, BLUE);
			bar(452, 300, 548, 332);
			rectangle(452, 300, 548, 332);
			puthz(452, 300, c6, 32, 32, BLUE);
		}
		if (KeyPress(KEY_ESC))
		{
			NewBK();
			return;
			
		}
	}
}