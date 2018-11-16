#include "main.h"

int history(int *resultID)
{
	FILE *fp;
	int i, j, k;
	int game_amount = 10;
	int game_realamount; //game_realamount代表总的游戏场数
	int slider_dy = 0;
	int mouse_oldy;
	int mouse_newy;
	int page;
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
	delay(100);
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
				*resultID=k+i;
				// page=result(k + i);
				return 4;
			}
		if (KeyPress(KEY_ESC))
		{
			NewBK();
			return 0;
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

int result(int historyMatch) //historyMatch表示倒数第几场比赛
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
	puthz(410,350,"按键",32,32,RED);
	outtextxy(480,370,"Enter");
;	puthz(400,400,"返回主菜单",32,32,RED);
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
			return 8;
		}
        if(KeyPress(KEY_ENTER))
        {
            return 0;
        }
	}
}