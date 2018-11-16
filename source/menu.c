#include "main.h"

int menu()
{
	setlinestyle(0, 0, 1);
	cleardevice();
	menu_page();
	while (1)
	{
		Newxy();
		if (Mouse_press(320, 90, 600, 150))
		{
			NewBK();
			return 1;
		}
		if (Mouse_press(320, 170, 600, 230))
		{
			NewBK();
			return 2;
		}
		if (Mouse_press(320, 250, 600, 310))
		{
			NewBK();
			return 5;
		}
		if (Mouse_press(50, 150, 200, 250))
		{
			NewBK();
			return 8;
		}
		// if(Mouse_press(50,300,200,350))
		// {
		// 	NewBK();
		//                                             result(1);
		// }
		// if(KeyPress(KEY_ESC))
		// 	exit(0);
	}
}

void menu_page()
{
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
int changci(int *matchtype)
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
		if (Mouse_press(20, 160, 220, 320))
		{
			*matchtype=1;
			return 9;
		}
		if (Mouse_press(420, 160, 620, 320))
		{
			*matchtype=2;
			return 9;
		}
		if (KeyPress(KEY_ESC))
		{
			NewBK();
			return 0;
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
			menu();
		}
	}
}

//选择球队界面
int choose_team(char (*s)[10],int path)
{
	int path;
	int x = 240;
	int i = 0;
	int j = 0;
	char number;
	// char **s;
	char ch = '\0';
	FILE *fp;
	int y = 100;
	// s=(char**)malloc(sizeof(char*)*10);
	// for(i=0;i<10;i++)
	// {
	// 	s[i]=(char*)malloc(sizeof(char)*10);
	// }
	// i=0;
	// if(s==NULL)
	// {
	// 	printf("malloc wrong");
	// 	getch();
	// 	exit(0);
	// }
	cleardevice();
	setfillstyle(1, GREEN);
	bar(1, 1, 640, 480);

	setcolor(MAGENTA);
	x = 250;
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

	while (1)
	{
		Newxy();
		if (KeyPress(KEY_ESC))
		{
			NewBK();
			return 0;
		}
		if (Mouse_press(x, y, x + 128, y + 40))
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
			// choose_player(s, path);
			return 6;
		}

		if (Mouse_press(x - 128, y + 100, x, y + 100 + 40))
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
			// choose_player(s, path);
			return 6;
		}

		if (Mouse_press(x + 128, y + 100, x + 128 + 128, y + 100 + 40))
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
			// choose_player(s, path);
			return 6;
		}

		if (Mouse_press(x - 95, y + 100 * 2, x - 95 + 128, y + 100 * 2 + 40))
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
			// choose_player(s, path);
			return 6;
		}

		if (Mouse_press(x + 95, y + 100 * 2, x + 95 + 128, y + 100 * 2 + 40))
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
			// choose_player(s, path);
			return 6;
		}
	}
	// free(s);
}

//选择球员界面
int choose_player(char (*s)[10], int path)
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

	// playerID(path); //记录选择球员的球员ID
	return 11;
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

	while (1)
	{
		if (KeyPress(KEY_ENTER))
		{
			break;
		}
	}
}