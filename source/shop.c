#include "main.h"

int shop(int path_)
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
			switch (path_)
			{
			case 1:
				if ((fp = fopen("c:\\mycode\\shop\\1.txt", "r")) == NULL)
				{
					settextstyle(1, 0, 3);
					outtextxy(200, 200, "cannot open the file");
					exit(1);
				}
				break;
			case 2:
				if ((fp = fopen("c:\\mycode\\shop\\2.txt", "r")) == NULL)
				{
					settextstyle(1, 0, 3);
					outtextxy(200, 200, "cannot open the file");
					exit(1);
				}
				break;
			case 3:
				if ((fp = fopen("c:\\mycode\\shop\\3.txt", "r")) == NULL)
				{
					settextstyle(1, 0, 3);
					outtextxy(200, 200, "cannot open the file");
					exit(1);
				}
				break;
			case 4:
				if ((fp = fopen("c:\\mycode\\shop\\4.txt", "r")) == NULL)
				{
					settextstyle(1, 0, 3);
					outtextxy(200, 200, "cannot open the file");
					exit(1);
				}
				break;
			case 5:
				if ((fp = fopen("c:\\mycode\\shop\\5.txt", "r")) == NULL)
				{
					settextstyle(1, 0, 3);
					outtextxy(200, 200, "cannot open the file");
					exit(1);
				}
				break;
			}
			for (i = 0; i < 10; i++)
			{
				fseek(fp, 13 + 37 * i, 0);
				length = fgetc(fp);
				for (j = 0; j < 10; j++)
				{
					ch = fgetc(fp);
					s[i][j] = ch;
				}
				s[i][2 * (length - 48)] = '\0';
			}
			// choose_player(s, path_);
            return 6;
		}
	}
}