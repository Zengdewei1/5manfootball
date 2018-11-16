#include "main.h"

void match()
{
	FILE *fpGame;
	int match = 0;
	int i = 10;
	if ((fpGame = fopen("c:\\mycode\\result\\game.txt", "r")) == NULL)
	{
		printf("cant not open");
		getch();
		exit(1);
	}
	// match=fgetc(fpGame);
	fscanf(fpGame, "%d", &match);
	// match-=48;
	printf("%d", match);
	fclose(fpGame);
	game(Left, Right, Red, Blue, match);
	// printf("yes");
	// xiuxi();
	while (1)
	{
		if (KeyPress(KEY_ENTER))
		{
			break;
		}
	}
	game(Right, Left, Red, Blue, match);
	match++;
	printf("%d", match);
	if ((fpGame = fopen("c:\\mycode\\result\\game.txt", "w")) == NULL)
	{
		printf("cant not open");
		getch();
		exit(1);
	}
	if (match < 10)
	{
		fprintf(fpGame, "%d", i);
	}
	fprintf(fpGame, "%d", match);
	fclose(fpGame);
	// result();
	while (1)
	{
		if (KeyPress(KEY_ENTER))
		{
			menu();
		}
	}
}

void pass(_team *pmyteam, _team *popteam, _ball *pball, int type)
{
	int flag = 0;
	pball->control = -1;
	while (flag == 0)
	{
		if (KeyPress(KEY_0))
		{
			if (pmyteam->controlplayer != 0)
			{
				pmyteam->passman = pmyteam->control;
				pmyteam->player[pmyteam->controlplayer].control = 0;
				PlayerChangestate(pmyteam, popteam, &pmyteam->player[pmyteam->controlplayer], pball, &pmyteam->player[pmyteam->controlplayer].Wait);
				pmyteam->controlplayer = 0;
				flag = 1;
			}
			else
			{
				flag = -1;
			}
		}
		else if (KeyPress(KEY_1))
		{
			if (pmyteam->controlplayer != 1)
			{
				pmyteam->passman = pmyteam->control;
				pmyteam->player[pmyteam->controlplayer].control = 0;
				PlayerChangestate(pmyteam, popteam, &pmyteam->player[pmyteam->controlplayer], pball, &pmyteam->player[pmyteam->controlplayer].Wait);
				pmyteam->controlplayer = 1;
				flag = 1;
			}
			else
			{
				flag = -1;
			}
		}
		else if (KeyPress(KEY_2))
		{
			if (pmyteam->controlplayer != 2)
			{
				pmyteam->passman = pmyteam->control;
				pmyteam->player[pmyteam->controlplayer].control = 0;
				PlayerChangestate(pmyteam, popteam, &pmyteam->player[pmyteam->controlplayer], pball, &pmyteam->player[pmyteam->controlplayer].Wait);
				pmyteam->controlplayer = 2;
				flag = 1;
			}
			else
			{
				flag = -1;
			}
		}
		else if (KeyPress(KEY_3))
		{
			if (pmyteam->controlplayer != 3)
			{
				pmyteam->passman = pmyteam->control;
				pmyteam->player[pmyteam->controlplayer].control = 0;
				PlayerChangestate(pmyteam, popteam, &pmyteam->player[pmyteam->controlplayer], pball, &pmyteam->player[pmyteam->controlplayer].Wait);
				pmyteam->controlplayer = 3;
				flag = 1;
			}
			else
			{
				flag = -1;
			}
		}
	}
	// if((pball->now_pos.x-team->player[team->controlplayer].now_pos.x)*(pball->now_pos.x-team->player[team->controlplayer].now_pos.x)+(pball->now_pos.y-team->player[team->controlplayer].now_pos.y)*(pball->now_pos.y-team->player[team->controlplayer].now_pos.y)<=10000.0)
	// {
	if (flag == 1)
	{
		pball->end_pos.x = pmyteam->player[pmyteam->controlplayer].now_pos.x;
		pball->end_pos.y = pmyteam->player[pmyteam->controlplayer].now_pos.y;
		PlayerChangestate(pmyteam, popteam, &pmyteam->player[pmyteam->controlplayer], pball, &pmyteam->player[pmyteam->controlplayer].ChasingBall);
		if (type == Direct)
		{
			BallChangestate(popteam, pmyteam, pball, &pball->Short_pass);
		}
		else
		{
			pball->start_pos.x = pball->now_pos.x;
			pball->start_pos.y = pball->now_pos.y;
			BallChangestate(popteam, pmyteam, pball, &pball->Long_pass);
			// printf("%s","yes");
		}
	}
	// else if(flag==4)
	// {
	// 	pass_dir=get_dir(pball->now_pos,team->goalkeeper.now_pos);
	//     pball->velocity.x=8.0*pass_dir.x;
	//     pball->velocity.y=8.0*pass_dir.y;
	// 	team->goalkeeper.pnowstate=&team->goalkeeper.Control;
	// }
	// }
	// else
	// {
	// 	pball->end_pos.x=team->player[team->controlplayer].now_pos.x;
	// 	pball->end_pos.y=team->player[team->controlplayer].now_pos.y;
	// 	pball->start_pos.x=pball->now_pos.x;
	// 	pball->start_pos.y=pball->now_pos.y;
	// 	pball->pnowstate=&pball->Short_pass;
	// 	team->player[team->controlplayer].pnowstate=&team->player[team->controlplayer].ChasingBall;
	// }
}

int findPass(_team *pmyteam, _team *popteam, _ball *pball)
{
	float nearDistance[4];
	int receivingman;
	nearDistance[0] = nearDist(pmyteam, popteam, pball, &popteam->player[0]);
	nearDistance[1] = nearDist(pmyteam, popteam, pball, &popteam->player[1]);
	nearDistance[2] = nearDist(pmyteam, popteam, pball, &popteam->player[2]);
	nearDistance[3] = nearDist(pmyteam, popteam, pball, &popteam->player[3]);
	if (nearDistance[0] < nearDistance[1])
	{
		receivingman = 1;
	}
	if (nearDistance[receivingman] < nearDistance[2])
	{
		receivingman = 2;
	}
	if (nearDistance[receivingman] < nearDistance[3])
	{
		receivingman = 3;
	}
	return receivingman;
}

float nearDist(_team *pmyteam, _team *popteam, _ball *pball, _player *pplayer)
{
	float nearDistance;
	float dist[4];
	dist[0] = distance(pplayer->now_pos.x, pplayer->now_pos.y, pmyteam->player[0].now_pos.x, pmyteam->player[0].now_pos.y);
	dist[1] = distance(pplayer->now_pos.x, pplayer->now_pos.y, pmyteam->player[1].now_pos.x, pmyteam->player[1].now_pos.y);
	dist[2] = distance(pplayer->now_pos.x, pplayer->now_pos.y, pmyteam->player[2].now_pos.x, pmyteam->player[2].now_pos.y);
	dist[3] = distance(pplayer->now_pos.x, pplayer->now_pos.y, pmyteam->player[3].now_pos.x, pmyteam->player[3].now_pos.y);
	nearDistance = (dist[0] <= dist[1]) ? dist[0] : dist[1];
	nearDistance = (nearDistance <= dist[2]) ? nearDistance : dist[2];
	nearDistance = (nearDistance <= dist[3]) ? nearDistance : dist[3];
	return nearDistance;
}

void action(_team *pmyteam, _team *popteam, _ball *pball)
{
	if (KeyPress(KEY_A))
	{
		pmyteam->player[pmyteam->controlplayer].velocity.x = -pmyteam->player[pmyteam->controlplayer].rate;
		pmyteam->player[pmyteam->controlplayer].velocity.y = 0;
		pmyteam->player[pmyteam->controlplayer].dir = Left;
	}
	if (KeyPress(KEY_D))
	{
		pmyteam->player[pmyteam->controlplayer].velocity.x = pmyteam->player[pmyteam->controlplayer].rate;
		pmyteam->player[pmyteam->controlplayer].velocity.y = 0;
		pmyteam->player[pmyteam->controlplayer].dir = Right;
	}
	if (KeyPress(KEY_S))
	{
		pmyteam->player[pmyteam->controlplayer].velocity.x = 0;
		pmyteam->player[pmyteam->controlplayer].velocity.y = pmyteam->player[pmyteam->controlplayer].rate;
	}
	if (KeyPress(KEY_W))
	{
		pmyteam->player[pmyteam->controlplayer].velocity.x = 0;
		pmyteam->player[pmyteam->controlplayer].velocity.y = -pmyteam->player[pmyteam->controlplayer].rate;
	}
	if (pmyteam->player[pmyteam->controlplayer].pnowstate == &pmyteam->player[pmyteam->controlplayer].Dribble)
	{
		if (KeyPress(KEY_J))
		{
			pmyteam->player[pmyteam->controlplayer].control = 0;
			KeeperChangestate(pmyteam, popteam, &popteam->goalkeeper, pball, &popteam->goalkeeper.Pounce);
			BallChangestate(popteam, pmyteam, pball, &pball->Short_shoot);
			PlayerChangestate(pmyteam, popteam, &pmyteam->player[pmyteam->controlplayer], pball, &pmyteam->player[pmyteam->controlplayer].ChasingBall);
		}
		if (KeyPress(KEY_K))
		{
			pass(pmyteam, popteam, pball, Direct);
		}
		if (KeyPress(KEY_M))
		{
			pass(pmyteam, popteam, pball, Circle);
		}
		if (KeyPress(KEY_N))
		{
			pball->control = -1;
			if (popteam->control != -1)
				popteam->control = -1;
			else
				pmyteam->control = -1;
			pball->start_pos = pball->now_pos;
			if (pmyteam->position == Left)
			{
				pball->end_pos.x = 600.0;
			}
			else
			{
				pball->end_pos.x = 40.0;
			}
			if (pball->now_pos.y > 340.0)
			{
				pball->end_pos.y = 340.0;
			}
			else if (pball->now_pos.y < 220.0)
			{
				pball->end_pos.y = 220.0;
			}
			else
			{
				pball->end_pos.y = 280.0;
			}
			pmyteam->player[pmyteam->controlplayer].control = 0;
			KeeperChangestate(pmyteam, popteam, &popteam->goalkeeper, pball, &popteam->goalkeeper.Pounce);
			BallChangestate(popteam, pmyteam, pball, &pball->Long_shoot);
			PlayerChangestate(pmyteam, popteam, &pmyteam->player[pmyteam->controlplayer], pball, &pmyteam->player[pmyteam->controlplayer].ChasingBall);
		}
	}
}
void arrive(_player *pplayer, double _x, double _y)
{
	Pos2d destination, dir;
	destination.x = _x;
	destination.y = _y;
	dir = get_dir(pplayer->now_pos, destination);
	pplayer->velocity.x = pplayer->rate * dir.x;
	pplayer->velocity.y = pplayer->rate * dir.y;
}

void auto_act(_team *pmyteam, _team *popteam, _player *pplayer, _ball *pball)
{
	Pos2d far_dir, near_dir;
	double dy;
	if (pmyteam->name == Player)
	{
		if (pmyteam->pnowstate = &pmyteam->Attack)
		{
			switch (pplayer->ID)
			{
			case (0):
				dy = abs(pplayer->now_pos.y - pball->now_pos.y);
				if (pplayer->now_pos.x <= 120.0 || pplayer->now_pos.x >= 200.0)
				{
					arrive(pplayer, 160.0, pball->now_pos.y);
				}
				else if (dy >= 20.0)
				{
					pplayer->velocity.y = 4.0 * (pball->now_pos.y - pplayer->now_pos.y) / dy;
				}
				break;
			case (1):
				if (pplayer->now_pos.x <= 280.0 || pplayer->now_pos.x >= 360.0)
				{
					arrive(pplayer, 320.0, pball->now_pos.y);
				}
				else if (distance(pplayer->now_pos.x, pplayer->now_pos.y, popteam->player[3].now_pos.x, popteam->player[3].now_pos.y) <= 100.0) //ï¿½ï¿½Î»ï¿½ï¿½ï¿½Êµï¿½Ô¶ï¿½ï¿½Ô·ï¿½Ç°ï¿½ï¿?3
				{
					far_dir = get_dir(pplayer->now_pos, popteam->player[3].now_pos);
					pplayer->velocity.x = -4.0 * far_dir.x;
					pplayer->velocity.y = -4.0 * far_dir.y;
				}
				// else
				// {
				// 	move_renctangle(pplayer,2);
				// 	move_dir(pplayer,pball);
				// }
				break;
			case (2):
				if (pplayer->now_pos.x <= 440.0 || pplayer->now_pos.x >= 520.0)
				{
					arrive(pplayer, 480.0, pplayer->now_pos.y);
				}
				else if (distance(pplayer->now_pos.x, pplayer->now_pos.y, pmyteam->player[3].now_pos.x, pmyteam->player[3].now_pos.y) <= 100.0) //ï¿½ï¿½Î»ï¿½ï¿½ï¿½Êµï¿½Ô¶ï¿½ï¿½ï¿½Ò·ï¿½Ç°ï¿½ï¿½
				{
					far_dir = get_dir(pplayer->now_pos, pmyteam->player[3].now_pos);
					pplayer->velocity.x = -4.0 * far_dir.x;
					pplayer->velocity.y = -4.0 * far_dir.y;
				}
				else if (distance(pplayer->now_pos.x, pplayer->now_pos.y, popteam->player[0].now_pos.x, popteam->player[0].now_pos.y) <= 50.0) //ï¿½ï¿½Î»ï¿½ï¿½Ô¶ï¿½ï¿½Ô·ï¿½ï¿½ï¿½ï¿½ï¿?0
				{
					far_dir = get_dir(pplayer->now_pos, pmyteam->player[3].now_pos);
					pplayer->velocity.x = -4.0 * far_dir.x;
					pplayer->velocity.y = -4.0 * far_dir.y;
				}
				else if (distance(pplayer->now_pos.x, pplayer->now_pos.y, popteam->player[1].now_pos.x, popteam->player[1].now_pos.y) <= 50.0) //ï¿½ï¿½Î»ï¿½ï¿½Ô¶ï¿½ï¿½Ô·ï¿½ï¿½ï¿½ï¿½ï¿?1
				{
					far_dir = get_dir(pplayer->now_pos, pmyteam->player[3].now_pos);
					pplayer->velocity.x = -4.0 * far_dir.x;
					pplayer->velocity.y = -4.0 * far_dir.y;
				}
				// else
				// {
				// 	move_renctangle(pplayer,3);
				// 	move_dir(pplayer,pball);
				// }
				break;
			case (3):
				if (pplayer->now_pos.x <= 440.0 || pplayer->now_pos.x >= 520.0)
				{
					arrive(pplayer, 480.0, pplayer->now_pos.y);
				}
				else if (distance(pplayer->now_pos.x, pplayer->now_pos.y, pmyteam->player[2].now_pos.x, pmyteam->player[2].now_pos.y) <= 100.0) //ï¿½ï¿½Î»ï¿½ï¿½ï¿½Êµï¿½Ô¶ï¿½ï¿½ï¿½Ò·ï¿½Ç°ï¿½ï¿½
				{
					far_dir = get_dir(pplayer->now_pos, pmyteam->player[2].now_pos);
					pplayer->velocity.x = -4.0 * far_dir.x;
					pplayer->velocity.y = -4.0 * far_dir.y;
				}
				else if (distance(pplayer->now_pos.x, pplayer->now_pos.y, popteam->player[0].now_pos.x, popteam->player[0].now_pos.y) <= 50.0) //ï¿½ï¿½Î»ï¿½ï¿½Ô¶ï¿½ï¿½Ô·ï¿½ï¿½ï¿½ï¿½ï¿?0
				{
					far_dir = get_dir(pplayer->now_pos, pmyteam->player[2].now_pos);
					pplayer->velocity.x = -4.0 * far_dir.x;
					pplayer->velocity.y = -4.0 * far_dir.y;
				}
				else if (distance(pplayer->now_pos.x, pplayer->now_pos.y, popteam->player[1].now_pos.x, popteam->player[1].now_pos.y) <= 50.0) //ï¿½ï¿½Î»ï¿½ï¿½Ô¶ï¿½ï¿½Ô·ï¿½ï¿½ï¿½ï¿½ï¿?1
				{
					far_dir = get_dir(pplayer->now_pos, pmyteam->player[2].now_pos);
					pplayer->velocity.x = -4.0 * far_dir.x;
					pplayer->velocity.y = -4.0 * far_dir.y;
				}
				// else
				// {
				// 	move_renctangle(pplayer,4);
				// 	move_dir(pplayer,pball);
				// }
				break;
			}
		}
		else
		{
			switch (pplayer->ID)
			{
			case (0):
				dy = abs(pplayer->now_pos.y - pball->now_pos.y);
				if (pplayer->now_pos.x <= 120.0 || pplayer->now_pos.x >= 200.0 || pplayer->now_pos.y <= 80.0 || pplayer->now_pos.y >= 280.0) //ï¿½ï¿½ï¿½ï¿½ï¿?
				{
					arrive(pplayer, 160.0, 200.0);
				}
				else if (dy >= 20.0)
				{
					pplayer->velocity.y = 4.0 * (pball->now_pos.y - pplayer->now_pos.y) / dy;
				}
				// else
				// {
				// 	move_renctangle(pplayer,5);
				// 	move_dir(pplayer,pball);
				// }
				break;
			case (1):
				if (pplayer->now_pos.x <= 120.0 || pplayer->now_pos.x >= 200.0 || pplayer->now_pos.y <= 280.0 || pplayer->now_pos.y >= 480.0)
				{

					arrive(pplayer, 120.0, 360.0);
				}
				else if (popteam->controlplayer == 3)
				{
					near_dir = get_dir(pplayer->now_pos, popteam->player[2].now_pos);
					pplayer->velocity.x = 4.0 * near_dir.x;
					pplayer->velocity.y = 4.0 * near_dir.y;
				}
				else if (popteam->controlplayer == 2)
				{
					near_dir = get_dir(pplayer->now_pos, popteam->player[3].now_pos);
					pplayer->velocity.x = 4.0 * near_dir.x;
					pplayer->velocity.y = 4.0 * near_dir.y;
				}
				// else
				// {
				// 	move_renctangle(pplayer,6);
				// 	move_dir(pplayer,pball);
				// }
				break;
			case (2):
				dy = abs(pplayer->now_pos.y - pball->now_pos.y);
				if (pplayer->now_pos.x <= 200.0 || pplayer->now_pos.x >= 280.0)
				{
					arrive(pplayer, 240.0, pball->now_pos.y);
				}
				else if (dy >= 20.0)
				{
					pplayer->velocity.y = 4.0 * (pball->now_pos.y - pplayer->now_pos.y) / dy;
				}
				// else
				// {
				// 	move_renctangle(pplayer,1);
				// 	move_dir(pplayer,pball);
				// }
				break;
			case (3):
				if (pplayer->now_pos.x <= 200.0 || pplayer->now_pos.x >= 280.0)
				{
					arrive(pplayer, 240.0, 380.0);
				}
				else if (dy >= 20.0)
				{
					pplayer->velocity.y = 4.0 * (pball->now_pos.y - pplayer->now_pos.y) / dy;
				}
				// else
				// {
				// 	move_renctangle(pplayer,2);
				// 	move_dir(pplayer,pball);
				// }
				break;
			}
		}
	}

	else
	{
		if (popteam->pnowstate = &popteam->Attack)
		{
			switch (pplayer->ID)
			{
			case (0):
				if (pplayer->now_pos.x <= 440.0 || pplayer->now_pos.x >= 520.0)
				{
					arrive(pplayer, 480.0, pball->now_pos.y);
				}
				// else
				// {
				// 	move_renctangle(pplayer,1);
				// 	move_dir(pplayer,pball);
				// }
				break;
			case (1):
				if (pplayer->now_pos.x <= 280.0 || pplayer->now_pos.x >= 360.0)
				{
					arrive(pplayer, 320.0, pball->now_pos.y);
				}
				// else
				// {
				// 	move_renctangle(pplayer,2);
				// 	move_dir(pplayer,pball);
				// }
				break;
			case (2):
				if (pplayer->now_pos.x <= 120.0 || pplayer->now_pos.x >= 200.0)
				{
					arrive(pplayer, 160.0, pplayer->now_pos.y);
				}
				// else
				// {
				// 	move_renctangle(pplayer,5);
				// 	move_dir(pplayer,pball);
				// }
				break;
			case (3):
				if (pplayer->now_pos.x <= 120.0 || pplayer->now_pos.x >= 200.0)
				{
					arrive(pplayer, 160.0, pplayer->now_pos.y);
				}
				// else
				// {
				// 	move_renctangle(pplayer,6);
				// 	move_dir(pplayer,pball);
				// }
				break;
			}
		}
		else //ï¿½ï¿½ï¿½Ô·ï¿½ï¿½ï¿½Ê±
		{
			switch (pplayer->ID)
			{
			case (0):
				if (pplayer->now_pos.x <= 440.0 || pplayer->now_pos.x >= 520.0 || pplayer->now_pos.y <= 80.0 || pplayer->now_pos.y >= 280.0)
				{
					arrive(pplayer, 480.0, 200.0);
				}
				// else
				// {
				// 	move_renctangle(pplayer,3);
				// 	move_dir(pplayer,pball);
				// }
				break;
			case (1):
				if (pplayer->now_pos.x <= 440.0 || pplayer->now_pos.x >= 520.0 || pplayer->now_pos.y <= 280.0 || pplayer->now_pos.y >= 480.0)
				{
					arrive(pplayer, 480.0, 360.0);
				}
				// else
				// {
				// 	move_renctangle(pplayer,4);
				// 	move_dir(pplayer,pball);
				// }
				break;
			case (2):
				if (pplayer->now_pos.x <= 360.0 || pplayer->now_pos.x >= 440.0)
				{
					arrive(pplayer, 400.0, pball->now_pos.y);
				}
				// else
				// {
				// 	move_renctangle(pplayer,1);
				// 	move_dir(pplayer,pball);
				// }
				break;
			case (3):
				if (pplayer->now_pos.x <= 280.0 || pplayer->now_pos.x >= 360.0)
				{
					arrive(pplayer, 320.0, pball->now_pos.y);
				}
				// else
				// {
				// 	move_renctangle(pplayer,2);
				// 	move_dir(pplayer,pball);
				// }
				break;
			}
		}
	}
}

void move_dir(_player *pplayer, _ball *pball)
{
	Pos2d dir;
	dir = get_dir(pplayer->now_pos, pball->now_pos);
	pplayer->velocity.x = pplayer->power * dir.x;
	pplayer->velocity.y = pplayer->power * dir.y;
}
double distance(double x1, double y1, double x2, double y2)
{
	double x, y, dist;
	double distance = 0.0;
	x = x1 - x2;
	y = y1 - y2;
	dist = x * x + y * y;
	distance = sqrt(dist);
	return distance;
}
Pos2d get_dir(Pos2d pos_from, Pos2d pos_to)
{
	double length, x, y;
	Pos2d dir;
	x = pos_to.x - pos_from.x;
	y = pos_to.y - pos_from.y;
	length = distance(pos_from.x, pos_from.y, pos_to.x, pos_to.y);
	dir.x = x / length;
	dir.y = y / length;
	return dir;
}



//???








// void draw_stop()
// {
// 	// setfillstyle(1,GREEN);
// 	// bar(620,0,640,20);
// 	puthz(620,20,"°´¼üPÔÝÍ£",32,32,RED);
// }

// void draw_start()
// {
// 	setfillstyle(1,GREEN);
// 	bar(620,0,640,20);
// 	puthz(620,0,"°´¼üY¼ÌÐø",32,32,RED);
// }

int playerID(int path)
{
	int *ID;
	int i = 0;
	int myteam = 0, opteam = 0;
	FILE *fpGame;
	FILE *fpplayer, *fpmyteam, *fpopteam;
	ID = (int *)malloc(sizeof(int) * 10);
	if (ID == NULL)
	{
		printf("id error");
		exit(0);
	}
	while (1)
	{
		Newxy();
		if (Mouse_press(130, 100, 226, 130))
		{
			ID[0] = 1;
			ID[1] = 0;
		}
		else if (Mouse_press(238, 100, 334, 130))
		{
			ID[1] = 1;
			ID[0] = 0;
		}
		if (Mouse_press(346, 100, 442, 130))
		{
			ID[2] = 1;
			ID[3] = 0;
		}
		else if (Mouse_press(454, 100, 550, 130))
		{
			ID[3] = 1;
			ID[2] = 0;
		}
		if (Mouse_press(130, 200, 226, 230))
		{
			ID[4] = 1;
			ID[5] = 0;
		}
		else if (Mouse_press(238, 200, 334, 230))
		{
			ID[5] = 1;
			ID[4] = 0;
		}
		if (Mouse_press(346, 200, 442, 230))
		{
			ID[6] = 1;
			ID[7] = 0;
		}
		else if (Mouse_press(454, 200, 550, 230))
		{
			ID[7] = 1;
			ID[6] = 0;
		}
		if (Mouse_press(238, 300, 334, 330))
		{
			ID[8] = 1;
			ID[9] = 0;
		}
		else if (Mouse_press(346, 300, 442, 330))
		{
			ID[9] = 1;
			ID[8] = 0;
		}
		if (ID[0] == 1)
		{
			setcolor(RED);
			rectangle(130, 100, 226, 130);
		}
		else
		{
			setcolor(WHITE);
			rectangle(130, 100, 226, 130);
		}
		if (ID[1] == 1)
		{
			setcolor(RED);
			rectangle(238, 100, 334, 130);
		}
		else
		{
			setcolor(WHITE);
			rectangle(238, 100, 334, 130);
		}
		if (ID[2] == 1)
		{
			setcolor(RED);
			rectangle(346, 100, 442, 130);
		}
		else
		{
			setcolor(WHITE);
			rectangle(346, 100, 442, 130);
		}
		if (ID[3] == 1)
		{
			setcolor(RED);
			rectangle(454, 100, 550, 130);
		}
		else
		{
			setcolor(WHITE);
			rectangle(454, 100, 550, 130);
		}
		if (ID[4] == 1)
		{
			setcolor(RED);
			rectangle(130, 200, 226, 230);
		}
		else
		{
			setcolor(WHITE);
			rectangle(130, 200, 226, 230);
		}
		if (ID[5] == 1)
		{
			setcolor(RED);
			rectangle(238, 200, 334, 230);
		}
		else
		{
			setcolor(WHITE);
			rectangle(238, 200, 334, 230);
		}
		if (ID[6] == 1)
		{
			setcolor(RED);
			rectangle(346, 200, 442, 230);
		}
		else
		{
			setcolor(WHITE);
			rectangle(346, 200, 442, 230);
		}
		if (ID[7] == 1)
		{
			setcolor(RED);
			rectangle(454, 200, 550, 230);
		}
		else
		{
			setcolor(WHITE);
			rectangle(454, 200, 550, 230);
		}
		if (ID[8] == 1)
		{
			setcolor(RED);
			rectangle(238, 300, 334, 330);
		}
		else
		{
			setcolor(WHITE);
			rectangle(238, 300, 334, 330);
		}
		if (ID[9] == 1)
		{
			setcolor(RED);
			rectangle(346, 300, 442, 330);
		}
		else
		{
			setcolor(WHITE);
			rectangle(346, 300, 442, 330);
		}
		if ((ID[0] + ID[1] + ID[2] + ID[3] + ID[4] + ID[5] + ID[6] + ID[7] + ID[8] + ID[9]) == 5 && Mouse_press(250, 375, 400, 425)) //10???5??????????????
		{
			NewBK();
			if ((fpplayer = fopen("c:\\mycode\\shop\\player.txt", "w")) == NULL)
			{
				printf("can not open");
				getch();
				exit(1);
			}
			for (i = 0; i < 9; i++)
			{
				if (ID[i])
				{
					fprintf(fpplayer, "%d\n", i + 1);
				}
			}
			fclose(fpplayer);
			free(ID);
			myteam = path;
			srand((unsigned)time(NULL));
			opteam = rand() % 5;
			opteam++;
			if (opteam == myteam)
			{
				opteam++;
			}
			opteam %= 5;
			if (opteam == 0)
			{
				opteam++;
			}
			if ((fpopteam = fopen("c:\\mycode\\shop\\opteam.txt", "w")) == NULL)
			{
				setlinestyle(0, 0, 1);
				outtextxy(300, 300, "cannot open the file");
				getch();
				exit(1);
			}
			fprintf(fpopteam, "%d", opteam);
			fclose(fpopteam);
			// getch();
			Vs(myteam);
			return 10;
		}
		if (KeyPress(KEY_ESC))
		{
			NewBK();
			return 5;
		}
		if (Mouse_press(50, 300, 180, 400))
		{
			NewBK();
			return 7;
		}
	}
}

void xiuxi()
{
	cleardevice();
	setfillstyle(1, GREEN);
	bar(0, 0, 640, 480);
	puthz(240, 50, "ÖÐ³¡ÐÝÏ¢", 32, 32, BLUE);
	puthz(120, 120, "Á½Ö»Çò¶Ó½»»»×óÓÒ³¡µØ", 32, 32, BLUE);
	puthz(160, 200, "°´¼ü", 32, 32, BLUE);
	outtextxy(240, 200, "Enter");
	puthz(320, 200, "½øÈëÏÂ°ë³¡", 32, 32, BLUE);
}

void player_border(_player *pplayer)
{
	if (pplayer->now_pos.x < 40)
	{
		pplayer->now_pos.x = 40;
	}

	if (pplayer->now_pos.x > 588)
	{
		pplayer->now_pos.x = 588;
	}

	if (pplayer->now_pos.y < 80)
	{
		pplayer->now_pos.y = 80;
	}

	if (pplayer->now_pos.y > 440)
	{
		pplayer->now_pos.y = 440;
	}
}

void ball_border(_team *popteam, _team *pmyteam, _ball *pball)
{
	if ((pball->now_pos.x > 588 && pball->now_pos.y >= 194 && pball->now_pos.y <= 366 && pmyteam->position == Left) || (pball->now_pos.x < 30 && pball->now_pos.y >= 194 && pball->now_pos.y <= 366 && pmyteam->position == Right))
	{
		pball->score_my++;
		pmyteam->player[pmyteam->controlplayer].score++;
		if (pmyteam->passman != -1)
			pmyteam->player[pmyteam->passman].help++;
		pmyteam->passman = -1;
		init_team(pmyteam, pball);
		init_team(popteam, pball);
		setfillstyle(1, GREEN);
		bar((int)(pball->now_pos.x), (int)(pball->now_pos.y), (int)(pball->now_pos.x) + 12, (int)(pball->now_pos.y) + 12);
		BallChangestate(popteam, pmyteam, pball, &pball->Control);
		pball->control = 3;
		popteam->player[3].control = 1;
		PlayerChangestate(pmyteam, popteam, &popteam->player[3], pball, &popteam->player[3].Dribble);
		popteam->control = 3;
		popteam->controlplayer = 3;
		TeamChangestate(pmyteam, popteam, pball, &pmyteam->Defend, &popteam->Attack);
	}
	if ((pball->now_pos.x > 588 && pball->now_pos.y >= 194 && pball->now_pos.y <= 366 && pmyteam->position == Right) || (pball->now_pos.x < 30 && pball->now_pos.y >= 194 && pball->now_pos.y <= 366 && pmyteam->position == Left))
	{
		// printf("%d",popteam->controlplayer);
		pball->score_op++;
		popteam->player[popteam->controlplayer].score++;
		if (popteam->passman != -1)
		{
			popteam->player[popteam->passman].help++;
		}
		popteam->passman = -1;
		// printf("%d",pball->score_op);
		init_team(pmyteam, pball);
		init_team(popteam, pball);
		setfillstyle(1, GREEN);
		bar((int)(pball->now_pos.x), (int)(pball->now_pos.y), (int)(pball->now_pos.x) + 12, (int)(pball->now_pos.y) + 12);
		BallChangestate(popteam, pmyteam, pball, &pball->Control);
		pmyteam->player[3].control = 1;
		PlayerChangestate(pmyteam, popteam, &pmyteam->player[3], pball, &pmyteam->player[3].Dribble);
		pmyteam->control = 3;
		pmyteam->controlplayer = 3;
		TeamChangestate(pmyteam, popteam, pball, &pmyteam->Attack, &popteam->Defend);
		pball->control = 3;
	}
	else if (pball->now_pos.x < 30 || pball->now_pos.x > 588 || pball->now_pos.y < 80 || pball->now_pos.y > 466)
	{
		if (pmyteam->pnowstate == &pmyteam->Attack)
		{
			init_team(pmyteam, pball);
			init_team(popteam, pball);
			setfillstyle(1, GREEN);
			bar((int)(pball->now_pos.x), (int)(pball->now_pos.y), (int)(pball->now_pos.x) + 12, (int)(pball->now_pos.y) + 12);
			BallChangestate(popteam, pmyteam, pball, &pball->Control);
			popteam->player[3].control = 1;
			PlayerChangestate(pmyteam, popteam, &popteam->player[3], pball, &popteam->player[3].Dribble);
			popteam->control = 3;
			popteam->controlplayer = 3;
			TeamChangestate(pmyteam, popteam, pball, &pmyteam->Defend, &popteam->Attack);
			pball->control = 3;
		}
		else
		{
			init_team(pmyteam, pball);
			init_team(popteam, pball);
			setfillstyle(1, GREEN);
			bar((int)(pball->now_pos.x), (int)(pball->now_pos.y), (int)(pball->now_pos.x) + 12, (int)(pball->now_pos.y) + 12);
			BallChangestate(popteam, pmyteam, pball, &pball->Control);
			pmyteam->player[3].control = 1;
			PlayerChangestate(pmyteam, popteam, &pmyteam->player[3], pball, &pmyteam->player[3].Dribble);
			pmyteam->control = 3;
			pmyteam->controlplayer = 3;
			TeamChangestate(pmyteam, popteam, pball, &popteam->Defend, &pmyteam->Attack);
			pball->control = 3;
		}
	}

	// if(pball->now_pos.x>588&&pball->now_pos.y>=220&&pball->now_pos.y<=328)
	// {
	// 	if(pmyteam->position==Left)
	// 		pball->score_my++;
	// 	else
	// 		pball->score_op++;
	// }
	// if(pball->now_pos.x<30&&pball->now_pos.y>=220&&pball->now_pos.y<=328)
	// {
	// 	if(pmyteam->position==Left)
	// 		pball->score_op++;
	// 	else
	// 		pball->score_my++;
	// }
	// }
	// else
	// {

	// }
	// }
}

int fastMatch(int matchType)
{
	if(matchType==1)
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
				return 0;
			}
		}
	}
	else
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
				menu();
			}
		}
	}
}

int teamMatch()
{

}