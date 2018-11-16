#include "main.h"

void draw_player(int x, int y, int dir, int control, int action, int ID, int color, int name)
{
	setlinestyle(0, 0, 1);
	// setcolor(RED);
	if (color == Blue)
	{
		setcolor(BLUE);
	}
	else
	{
		setcolor(RED);
	}
	if (name == Player)
		draw_num(x + 4, y + 2, ID, 4);
	circle(x + 6, y + 6, 6);
	line(x + 6, y + 12, x + 6, y + 28);
	if (dir == Right)
	{
		line(x + 6, y + 20, x + 12, y + 14);
		line(x + 6, y + 20, x + 12, y + 26);
	}
	else
	{
		line(x + 6, y + 20, x, y + 14);
		line(x + 6, y + 20, x, y + 26);
	}
	if (control)
	{
		setfillstyle(1, YELLOW);
		pieslice(x + 6, y + 15, 0, 360, 2);
	}
	if (action)
	{
		setfillstyle(1, BLACK);
		pieslice(x + 6, y + 25, 0, 360, 3);
	}
	line(x + 6, y + 28, x, y + 34);
	line(x + 6, y + 28, x + 12, y + 34);
}

void draw_judge(int x, int y)
{
	setlinestyle(0, 0, 1);
	setcolor(BLACK);
	circle(x + 6, y + 6, 6);
	line(x + 6, y + 12, x + 6, y + 22);
	line(x + 6, y + 17, x, y + 23);
	line(x + 6, y + 17, x + 12, y + 23);
	line(x + 6, y + 22, x, y + 28);
	line(x + 6, y + 22, x + 12, y + 28);
	setfillstyle(1, RED);
	bar(x - 6, y + 19, x, y + 23);
	setfillstyle(1, YELLOW);
	bar(x + 12, y + 19, x + 18, y + 23);
}

void draw_ground()
{
	setlinestyle(0, 0, 3);
	setcolor(WHITE);
	rectangle(40, 80, 600, 478);
	rectangle(0, 220, 40, 340);
	rectangle(600, 220, 638, 340);
	line(320, 80, 320, 474);
	circle(320, 280, 60);
	arc(40, 280, 0, 90, 120);
	arc(40, 280, 270, 360, 120);
	arc(600, 280, 90, 270, 120);
	arc(40, 80, 270, 360, 20);
	arc(40, 474, 0, 90, 20);
	arc(600, 80, 180, 270, 20);
	arc(600, 474, 90, 180, 20);
}

void draw_ball(int x, int y, _ball *pball)
{
	if (pball->pnowstate == &pball->Long_pass || pball->pnowstate == &pball->Long_shoot)
	{
		setcolor(RED);
	}
	else
	{
		setcolor(BLACK);
	}
	setfillstyle(1, WHITE);
	pieslice(x + 6, y + 6, 0, 360, 6);
	setfillstyle(1, BLACK);
	pieslice(x + 6, y + 6, 0, 360, 1);
	pieslice(x + 6, y + 3, 0, 360, 1);
	pieslice(x + 3, y + 6, 0, 360, 1);
	pieslice(x + 9, y + 6, 0, 360, 1);
	pieslice(x + 6, y + 9, 0, 360, 1);
}

void draw_num(int x, int y, int num, int size)
{
	// setcolor(BLUE);
	// setlinestyle(0,0,1);
	switch (num)
	{
	case (0):
		line(x, y, x + size, y);
		line(x + size, y, x + size, y + 2 * size);
		line(x + size, y + 2 * size, x, y + 2 * size);
		line(x, y + 2 * size, x, y);
		break;

	case (1):
		line(x + size, y, x + size, y + 2 * size);
		break;
	case (2):
		line(x, y, x + size, y);
		line(x + size, y, x + size, y + size);
		line(x + size, y + size, x, y + size);
		line(x, y + size, x, y + 2 * size);
		line(x, y + 2 * size, x + size, y + 2 * size);
		break;
	case (3):
		line(x, y, x + size, y);
		line(x + size, y, x + size, y + size);
		line(x + size, y + size, x, y + size);
		line(x + size, y + size, x + size, y + 2 * size);
		line(x + size, y + 2 * size, x, y + 2 * size);
		break;
	case (4):
		line(x + size, y, x, y + size);
		line(x, y + size, x + size, y + size);
		line(x + size, y, x + size, y + 2 * size);
		break;
	case (5):
		line(x + size, y, x, y);
		line(x, y, x, y + size);
		line(x, y + size, x + size, y + size);
		line(x + size, y + size, x + size, y + 2 * size);
		line(x + size, y + 2 * size, x, y + 2 * size);
		break;
	case (6):
		line(x + size, y, x, y);
		line(x, y, x, y + size);
		line(x, y + size, x + size, y + size);
		line(x + size, y + size, x + size, y + 2 * size);
		line(x + size, y + 2 * size, x, y + 2 * size);
		line(x, y + 2 * size, x, y + size);
		break;
	case (7):
		line(x, y, x + size, y);
		line(x + size, y, x + size, y + 2 * size);
		break;
	case (8):
		line(x, y, x + size, y);
		line(x + size, y, x + size, y + 2 * size);
		line(x + size, y + 2 * size, x, y + 2 * size);
		line(x, y + 2 * size, x, y);
		line(x + size, y + size, x, y + size);
		break;
	case (9):
		line(x, y, x + size, y);
		line(x + size, y, x + size, y + 2 * size);
		line(x, y, x, y + size);
		line(x + size, y + size, x, y + size);
		break;
	case (10):
		line(x, y, x, y + 2 * size);
		x += size;
		line(x, y, x + size, y);
		line(x + size, y, x + size, y + 2 * size);
		line(x + size, y + 2 * size, x, y + 2 * size);
		line(x, y + 2 * size, x, y);
		break;
	case (11):
		line(x, y, x, y + 2 * size);
		line(x + size, y, x + size, y + size * 2);
		break;
	case (12):
		line(x, y, x, y + 2 * size);
		x += size;
		line(x, y, x + size, y);
		line(x + size, y, x + size, y + size);
		line(x + size, y + size, x, y + size);
		line(x, y + size, x, y + 2 * size);
		line(x, y + 2 * size, x + size, y + 2 * size);
		break;
	case (13):
		line(x, y, x, y + 2 * size);
		x += size;
		line(x, y, x + size, y);
		line(x + size, y, x + size, y + size);
		line(x + size, y + size, x, y + size);
		line(x + size, y + size, x + size, y + 2 * size);
		line(x + size, y + 2 * size, x, y + 2 * size);
		break;
	case (14):
		line(x, y, x, y + 2 * size);
		x += size;
		line(x + size, y, x, y + size);
		line(x, y + size, x + size, y + size);
		line(x + size, y, x + size, y + 2 * size);
		break;
	case (15):
		line(x, y, x, y + 2 * size);
		x += size;
		line(x + size, y, x, y);
		line(x, y, x, y + size);
		line(x, y + size, x + size, y + size);
		line(x + size, y + size, x + size, y + 2 * size);
		line(x + size, y + 2 * size, x, y + 2 * size);
		break;
	case (16):
		line(x, y, x, y + 2 * size);
		x += size;
		line(x + size, y, x, y);
		line(x, y, x, y + size);
		line(x, y + size, x + size, y + size);
		line(x + size, y + size, x + size, y + 2 * size);
		line(x + size, y + 2 * size, x, y + 2 * size);
		line(x, y + 2 * size, x, y + size);
		break;
	case (17):
		line(x, y, x, y + 2 * size);
		x += size;
		line(x, y, x + size, y);
		line(x + size, y, x + size, y + 2 * size);
		break;
	case (18):
		line(x, y, x, y + 2 * size);
		x += size;
		line(x, y, x + size, y);
		line(x + size, y, x + size, y + 2 * size);
		line(x + size, y + 2 * size, x, y + 2 * size);
		line(x, y + 2 * size, x, y);
		line(x + size, y + size, x, y + size);
		break;
	case (19):
		line(x, y, x, y + 2 * size);
		x += size;
		line(x, y, x + size, y);
		line(x + size, y, x + size, y + 2 * size);
		line(x, y, x, y + size);
		line(x + size, y + size, x, y + size);
		break;
	case (20):
		line(x, y, x + size, y);
		line(x + size, y, x + size, y + size);
		line(x + size, y + size, x, y + size);
		line(x, y + size, x, y + 2 * size);
		line(x, y + 2 * size, x + size, y + 2 * size);
		x = x + size + 2;
		line(x, y, x + size, y);
		line(x + size, y, x + size, y + 2 * size);
		line(x + size, y + 2 * size, x, y + 2 * size);
		line(x, y + 2 * size, x, y);
		break;
	}
}

void draw_time(int time)
{
	int minute, second, ten, single;
	minute = time / 60;
	second = time % 60;
	ten = second / 10;
	single = second % 10;
	setlinestyle(0, 0, 3);
	setcolor(BLACK);
	rectangle(210, 5, 310, 45);
	setfillstyle(1, WHITE);
	bar(213, 8, 307, 42);
	setcolor(RED);
	draw_num(215, 10, minute, 15);
	setfillstyle(1, RED);
	pieslice(245, 15, 0, 360, 3);
	pieslice(245, 35, 0, 360, 3);
	draw_num(260, 10, ten, 15);
	draw_num(290, 10, single, 15);
}

void draw_score(int score_my, int score_op)
{
	setlinestyle(0, 0, 3);
	setcolor(BLACK);
	rectangle(320, 5, 450, 45);
	setfillstyle(1, WHITE);
	bar(323, 8, 447, 42);
	setcolor(RED);
	draw_num(325, 10, score_my / 10, 15);
	draw_num(355, 10, score_my % 10, 15);
	setfillstyle(1, BLUE);
	pieslice(385, 15, 0, 360, 3);
	pieslice(385, 35, 0, 360, 3);
	setcolor(BLUE);
	draw_num(400, 10, score_op / 10, 15);
	draw_num(430, 10, score_op % 10, 15);
}

void draw_control(_team *pmyteam, _team *popteam)
{
	setlinestyle(0, 0, 3);
	setfillstyle(1, RED);
	setcolor(BLACK);
	rectangle(5, 5, 50, 30);
	bar(8, 8, 47, 27);
	draw_num(20, 10, 0, 5);

	rectangle(5, 35, 50, 60);
	bar(8, 38, 47, 57);
	draw_num(20, 40, 1, 5);

	rectangle(95, 5, 140, 30);
	bar(98, 8, 137, 27);
	draw_num(110, 10, 2, 5);

	rectangle(95, 35, 140, 60);
	bar(98, 38, 137, 57);
	draw_num(110, 40, 3, 5);
	setfillstyle(1, BLUE);
	rectangle(640 - 5 - 40, 5, 640 - 50 - 40, 30);
	bar(640 - 8 - 40, 8, 640 - 47 - 40, 27);
	draw_num(640 - 20 - 40, 10, 2, 5);

	rectangle(640 - 5 - 40, 35, 640 - 50 - 40, 60);
	bar(640 - 8 - 40, 38, 640 - 47 - 40, 57);
	draw_num(640 - 20 - 40, 40, 3, 5);

	rectangle(640 - 95 - 50, 5, 640 - 140 - 50, 30);
	bar(640 - 98 - 50, 8, 640 - 137 - 50, 27);
	draw_num(640 - 110 - 50, 10, 0, 5);

	rectangle(640 - 95 - 50, 35, 640 - 140 - 50, 60);
	bar(640 - 98 - 50, 38, 640 - 137 - 50, 57);
	draw_num(640 - 110 - 50, 40, 1, 5);
	setfillstyle(1, GREEN);
	bar(52, 5, 92, 65);
	bar(142, 5, 180, 65);
	bar(497, 5, 537, 65);
	bar(597, 5, 640, 65);
	setcolor(YELLOW);
	if (pmyteam->pnowstate == &pmyteam->Attack)
	{
		switch (pmyteam->controlplayer)
		{
		case (0):
			line(60, 15, 70, 30);
			line(70, 30, 90, 15);
			break;
		case (2):
			line(60 + 90, 15, 70 + 90, 30);
			line(70 + 90, 30, 90 + 90, 15);
			break;
		case (1):
			line(60, 15 + 30, 70, 30 + 30);
			line(70, 30 + 30, 90, 15 + 30);
			break;
		case (3):
			line(60 + 90, 15 + 30, 70 + 90, 30 + 30);
			line(70 + 90, 30 + 30, 90 + 90, 15 + 30);
			break;
		}
	}
	else if (popteam->pnowstate == &popteam->Attack)
	{
		switch (popteam->controlplayer)
		{
		case (0):
			line(640 - 95 - 40, 15, 640 - 125, 30);
			line(640 - 125, 30, 640 - 105, 15);
			break;
		case (2):
			line(640 - 95 - 40 + 90, 15, 640 - 125 + 90, 30);
			line(640 - 125 + 90, 30, 640 - 105 + 90, 15);
			break;
		case (1):
			line(640 - 95 - 40, 15 + 30, 640 - 125, 30 + 30);
			line(640 - 125, 30 + 30, 640 - 105, 15 + 30);
			break;
		case (3):
			line(640 - 95 - 40 + 90, 15 + 30, 640 - 125 + 90, 30 + 30);
			line(640 - 125 + 90, 30 + 30, 640 - 105 + 90, 15 + 30);
			break;
		}
	}
}