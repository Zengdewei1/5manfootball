#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>
#include<math.h>
#include"mouse.h"
#include"hanzi.h"
#include"multikey.h"
#include"menu.h"
#include"tool.h"
#include"game.h"

void shoot(_team *team,_ball *pball)
{
    Pos2d gate,shoot_dir;
    gate.x=600;
    gate.y=280;
	pball->control=0;
	team->player[team->controlplayer].control=0;
    shoot_dir=get_dir(pball->now_pos,gate);
    pball->velocity.x=16.0*shoot_dir.x;
    pball->velocity.y=16.0*shoot_dir.y;
	// setfillstyle(1,BLACK);
	// 	circle(30,30,5);
}

void pass(struct _BALL *pball,struct _TEAM *team)
{
    int i,flag;
    Pos2d pass_dir;
    flag=0;
    while(flag==0)
    {
        if(KeyPress(KEY_0))
        {
			if(team->controlplayer!=0)
			{
				pball->control=0;
				team->player[team->controlplayer].control=0;
				team->player[team->controlplayer].pnowstate=&team->player[team->controlplayer].Wait;
				team->controlplayer=0;
				flag=1;
			}
            else
			{
				flag=-1;
			}
        }
        else if(KeyPress(KEY_1))
        {
            if(team->controlplayer!=1)
			{
				pball->control=0;
				team->player[team->controlplayer].control=0;
				team->player[team->controlplayer].pnowstate=&team->player[team->controlplayer].Wait;
				team->controlplayer=1;
				flag=1;
			}
            else
			{
				flag=-1;
			}
        }
        else if(KeyPress(KEY_2))
        {
            if(team->controlplayer!=2)
			{
				pball->control=0;
				team->player[team->controlplayer].control=0;
				team->player[team->controlplayer].pnowstate=&team->player[team->controlplayer].Wait;
				team->controlplayer=2;
				flag=1;
			}
            else
			{
				flag=-1;
			}
        }
        else if(KeyPress(KEY_3))
        {
            if(team->controlplayer!=3)
			{
				pball->control=0;
				team->player[team->controlplayer].control=0;
				team->player[team->controlplayer].pnowstate=&team->player[team->controlplayer].Wait;
				team->controlplayer=3;
				flag=1;
			}
            else
			{
				flag=-1;
			}
        }
        // else if(KeyPress(KEY_4))
        // {
        //     if(team->controlplayer!=4)
		// 	{
		// 		pball->control=0;
		// 		team->player[team->controlplayer].control=0;
		// 		// team->player[team->controlplayer].pnowstate=&team->player[team->controlplayer].Wait;
		// 		team->controlplayer=4;
		// 		flag=4;
		// 	}
            // else
			// {
			// 	flag=-1;
			// }
        // }
    }
	if(flag==1)
	{
		pass_dir=get_dir(pball->now_pos,team->player[team->controlplayer].now_pos);
        pball->velocity.x=14.0*pass_dir.x;
        pball->velocity.y=14.0*pass_dir.y;
		team->player[team->controlplayer].pnowstate=&team->player[team->controlplayer].ChasingBall;
		// setfillstyle(1,BLACK);
		// circle(10,10,10);
	}
	else if(flag==4)
	{
		pass_dir=get_dir(pball->now_pos,team->goalkeeper.now_pos);
        pball->velocity.x=8.0*pass_dir.x;
        pball->velocity.y=8.0*pass_dir.y;
		team->player[team->controlplayer].pnowstate=&team->player[team->controlplayer].ChasingBall;
	}
	// setfillstyle(1,BLACK);
	// 	circle(20,20,10);

}
void action(_team *team,_ball *pball)
{
	
        if(KeyPress(KEY_A))
		{
			team->player[team->controlplayer].velocity.x=-12.0;
			team->player[team->controlplayer].velocity.y=0;
			team->player[team->controlplayer].dir=Left;
		}
		if(KeyPress(KEY_D))
		{
			team->player[team->controlplayer].velocity.x=12.0;
			team->player[team->controlplayer].velocity.y=0;	
			team->player[team->controlplayer].dir=Right;
		}
		if(KeyPress(KEY_S))
		{
			team->player[team->controlplayer].velocity.x=0;
			team->player[team->controlplayer].velocity.y=12.0;

		}
		if(KeyPress(KEY_W))
		{
			team->player[team->controlplayer].velocity.x=0;
			team->player[team->controlplayer].velocity.y=-12.0;

		}
        if(team->player[team->controlplayer].pnowstate==&team->player[team->controlplayer].Dribble)
        {
            if(KeyPress(KEY_J))
		    {
			    shoot(team,pball);
		    }
            else if(KeyPress(KEY_K))
		    {
		    	pass(pball,team);
		    }
        }
}
//������Ա�Ļ��Χ��һ����������,type1-6��ʾ6����ͬ�Ļ��Χ
// void move_renctangle(_player *pplayer,int type)
// {
// 	switch(type)
// 	{
// 		case(1):if(pplayer->now_pos.x<=240.0)//�г���
// 				{
// 					pplayer->now_pos.x=240.0;
// 				}
// 				if(pplayer->now_pos.x>=400.0)
// 				{
// 					pplayer->now_pos.x=400.0;
// 				}
// 				if(pplayer->now_pos.y>=280)
// 				{
// 					pplayer->now_pos.y=280.0;
// 				}
// 				if(pplayer->now_pos.y<=80.0)
// 				{
// 					pplayer->now_pos.y=80.0;
// 				}
// 				break;
// 		case(2):if(pplayer->now_pos.x<=240.0)//�г���
// 				{
// 					pplayer->now_pos.x=240.0;
// 				}
// 				if(pplayer->now_pos.x>=400.0)
// 				{
// 					pplayer->now_pos.x=400.0;
// 				}
// 				if(pplayer->now_pos.y>=480.0)
// 				{
// 					pplayer->now_pos.y=480.0;
// 				}
// 				if(pplayer->now_pos.y<=280.0)
// 				{
// 					pplayer->now_pos.y=280.0;
// 				}
// 				break;
// 		case(3):if(pplayer->now_pos.x<=400.0)//�ҳ���
// 				{
// 					pplayer->now_pos.x=400.0;
// 				}
// 				if(pplayer->now_pos.x>=480.0)
// 				{
// 					pplayer->now_pos.x=400.0;
// 				}
// 				if(pplayer->now_pos.y>=280)
// 				{
// 					pplayer->now_pos.y=280.0;
// 				}
// 				if(pplayer->now_pos.y<=80.0)
// 				{
// 					pplayer->now_pos.y=80.0;
// 				}
// 				break;
// 		case(4):if(pplayer->now_pos.x<=400.0)//�ҳ���
// 				{
// 					pplayer->now_pos.x=400.0;
// 				}
// 				if(pplayer->now_pos.x>=480.0)
// 				{
// 					pplayer->now_pos.x=480.0;
// 				}
// 				if(pplayer->now_pos.y>=480.0)
// 				{
// 					pplayer->now_pos.y=480.0;
// 				}
// 				if(pplayer->now_pos.y<=280.0)
// 				{
// 					pplayer->now_pos.y=280.0;
// 				}
// 				break;
// 		case(5):if(pplayer->now_pos.x<=160.0)//����
// 				{
// 					pplayer->now_pos.x=160.0;
// 				}
// 				if(pplayer->now_pos.x>=240.0)
// 				{
// 					pplayer->now_pos.x=240.0;
// 				}
// 				if(pplayer->now_pos.y>=280)
// 				{
// 					pplayer->now_pos.y=280.0;
// 				}
// 				if(pplayer->now_pos.y<=80.0)
// 				{
// 					pplayer->now_pos.y=80.0;
// 				}
// 				break;
// 		case(6):if(pplayer->now_pos.x<=160.0)//����
// 				{
// 					pplayer->now_pos.x=160.0;
// 				}
// 				if(pplayer->now_pos.x>=240.0)
// 				{
// 					pplayer->now_pos.x=240.0;
// 				}
// 				if(pplayer->now_pos.y>=480.0)
// 				{
// 					pplayer->now_pos.y=480.0;
// 				}
// 				if(pplayer->now_pos.y<=280.0)
// 				{
// 					pplayer->now_pos.y=280.0;
// 				}
// 				break;
// 	}
// }

void arrive(_player *pplayer,double _x,double _y)
{
	Pos2d destination,dir;
	destination.x=_x;
	destination.y=_y;
	dir=get_dir(pplayer->now_pos,destination);
	pplayer->velocity.x=4.0*dir.x;
	pplayer->velocity.y=4.0*dir.y;
}
void move_area(_team *pteam1,_team *pteam2,_player *pplayer,_ball *pball)
{
	if(pteam1->name==Player)
	{
		if(pteam1->iscontrol==1)//�ҷ�����ʱ
		{
			switch(pplayer->ID)
			{
				case(0):if(pplayer->now_pos.x<=120.0||pplayer->now_pos.x>=200.0)
						{
							arrive(pplayer,160.0,pball->now_pos.y);
						}
						// else
						// {
						// 	move_renctangle(pplayer,1);
						// 	move_dir(pplayer,pball);
						// }
						break;
				case(1):if(pplayer->now_pos.x<=280.0||pplayer->now_pos.x>=360.0)
						{
							arrive(pplayer,320.0,pball->now_pos.y);
						}
						// else
						// {
						// 	move_renctangle(pplayer,2);
						// 	move_dir(pplayer,pball);
						// }
						break;
				case(2):if(pplayer->now_pos.x<=440.0||pplayer->now_pos.x>=520.0)
						{
							arrive(pplayer,480.0,pplayer->now_pos.y);
						}
						// else
						// {
						// 	move_renctangle(pplayer,3);
						// 	move_dir(pplayer,pball);
						// }
						break;
				case(3):if(pplayer->now_pos.x<=440.0||pplayer->now_pos.x>=520.0)
						{
							arrive(pplayer,480.0,pplayer->now_pos.y);
						}
						// else
						// {
						// 	move_renctangle(pplayer,4);
						// 	move_dir(pplayer,pball);
						// }
						break;
			}
		}
		else//�ҷ�����ʱ
		{
			switch(pplayer->ID)
			{
				case(0):if(pplayer->now_pos.x<=120.0||pplayer->now_pos.x>=200.0||pplayer->now_pos.y<=80.0||pplayer->now_pos.y>=280.0)
						{
							arrive(pplayer,120.0,200.0);
						}
						// else
						// {
						// 	move_renctangle(pplayer,5);
						// 	move_dir(pplayer,pball);
						// }
						break;
				case(1):if(pplayer->now_pos.x<=120.0||pplayer->now_pos.x>=200.0||pplayer->now_pos.y<=280.0||pplayer->now_pos.y>=480.0)
						{
							arrive(pplayer,120.0,360.0);
						}
						// else
						// {
						// 	move_renctangle(pplayer,6);
						// 	move_dir(pplayer,pball);
						// }
						break;
				case(2):if(pplayer->now_pos.x<=200.0||pplayer->now_pos.x>=280.0)
						{
							arrive(pplayer,240.0,pball->now_pos.y);
						}
						// else
						// {
						// 	move_renctangle(pplayer,1);
						// 	move_dir(pplayer,pball);
						// }
						break;
				case(3):if(pplayer->now_pos.x<=200.0||pplayer->now_pos.x>=280.0)
						{
							arrive(pplayer,240.0,380.0);
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
		if(pteam1->iscontrol==1)//���Խ���ʱ
		{
			switch(pplayer->ID)
			{
				case(0):if(pplayer->now_pos.x<=440.0||pplayer->now_pos.x>=520.0)
						{
							arrive(pplayer,480.0,pball->now_pos.y);
						}
						// else
						// {
						// 	move_renctangle(pplayer,1);
						// 	move_dir(pplayer,pball);
						// }
						break;
				case(1):if(pplayer->now_pos.x<=280.0||pplayer->now_pos.x>=360.0)
						{
							arrive(pplayer,320.0,pball->now_pos.y);
						}
						// else
						// {
						// 	move_renctangle(pplayer,2);
						// 	move_dir(pplayer,pball);
						// }
						break;
				case(2):if(pplayer->now_pos.x<=120.0||pplayer->now_pos.x>=200.0)
						{
							arrive(pplayer,160.0,pplayer->now_pos.y);
						}
						// else
						// {
						// 	move_renctangle(pplayer,5);
						// 	move_dir(pplayer,pball);
						// }
						break;
				case(3):if(pplayer->now_pos.x<=120.0||pplayer->now_pos.x>=200.0)
						{
							arrive(pplayer,160.0,pplayer->now_pos.y);
						}
						// else
						// {
						// 	move_renctangle(pplayer,6);
						// 	move_dir(pplayer,pball);
						// }
						break;
			}
		}
		else//���Է���ʱ
		{
			switch(pplayer->ID)
			{
				case(0):if(pplayer->now_pos.x<=440.0||pplayer->now_pos.x>=520.0||pplayer->now_pos.y<=80.0||pplayer->now_pos.y>=280.0)
						{
							arrive(pplayer,480.0,200.0);
						}
						// else
						// {
						// 	move_renctangle(pplayer,3);
						// 	move_dir(pplayer,pball);
						// }
						break;
				case(1):if(pplayer->now_pos.x<=440.0||pplayer->now_pos.x>=520.0||pplayer->now_pos.y<=280.0||pplayer->now_pos.y>=480.0)
						{
							arrive(pplayer,480.0,360.0);
						}
						// else
						// {
						// 	move_renctangle(pplayer,4);
						// 	move_dir(pplayer,pball);
						// }
						break;
				case(2):if(pplayer->now_pos.x<=360.0||pplayer->now_pos.x>=440.0)
						{
							arrive(pplayer,400.0,pball->now_pos.y);
						}
						// else
						// {
						// 	move_renctangle(pplayer,1);
						// 	move_dir(pplayer,pball);
						// }
						break;
				case(3):if(pplayer->now_pos.x<=280.0||pplayer->now_pos.x>=360.0)
						{
							arrive(pplayer,320.0,pball->now_pos.y);
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

void move_dir(_player *pplayer,_ball *pball)
{
	Pos2d dir;
	dir=get_dir(pplayer->now_pos,pball->now_pos);
	pplayer->velocity.x=5.0*dir.x;
	pplayer->velocity.y=5.0*dir.y;
}
double distance(double x1,double y1,double x2,double y2)
{
	double x,y,dist,distance;
	x=x1-x2;
	y=y1-y2;
	dist=x*x+y*y;
    distance=sqrt(dist);
	return distance;
}
Pos2d get_dir(Pos2d pos_from,Pos2d pos_to)
{
    double length,x,y;
    Pos2d dir;
    x=pos_to.x-pos_from.x;
    y=pos_to.y-pos_from.y;
    length=distance(pos_from.x,pos_from.y,pos_to.x,pos_to.y);
    dir.x=x/length;
    dir.y=y/length;
    return dir;
}

void draw_judge(int x,int y)
{
    setlinestyle(0,0,1);
    setcolor(BLACK);
    circle(x+6,y+6,6);
    line(x+6,y+12,x+6,y+22);
    line(x+6,y+17,x,y+23);
    line(x+6,y+17,x+12,y+23);
    line(x+6,y+22,x,y+28);
    line(x+6,y+22,x+12,y+28);
	setfillstyle(1,RED);
	bar(x-6,y+19,x,y+23);
	setfillstyle(1,YELLOW);
	bar(x+12,y+19,x+18,y+23);
}

void draw_player(int x,int y,int dir,int control,int ID,int color)
{
    setlinestyle(0,0,1);
	if (color==Red)
	{
		setcolor(RED);
        // switch(ID)
        // {
        // case(0):outtextxy(x+1,y+3,"0");
        //         break;
        // case(1):outtextxy(x+1,y+3,"1");
        //         break;
        // case(2):outtextxy(x+1,y+3,"2");
        //         break;
        // case(3):outtextxy(x+1,y+3,"3");
        //         break;
        // case(4):outtextxy(x+1,y+3,"4");
        //         break;
        // }
	}
	else
	{
		setcolor(BLUE);
	}

    circle(x+6,y+6,6);
    line(x+6,y+12,x+6,y+28);
	if(dir==Right)
    {
		line(x+6,y+20,x+12,y+14);
    	line(x+6,y+20,x+12,y+26);
	}
	else
	{
		line(x+6,y+20,x,y+14);
    	line(x+6,y+20,x,y+26);
	}
	if(control)
	{
		setfillstyle(1,YELLOW);
		pieslice(x+6,y+2,0,360,2);
	}
	line(x+6,y+28,x,y+34);
    line(x+6,y+28,x+12,y+34);
}

void draw_ball(int x,int y)
{
	setcolor(BLACK);
	setfillstyle(1,WHITE);
	pieslice(x+8,y+8,0,360,6);
	setfillstyle(1,BLACK);
	pieslice(x+8,y+8,0,360,1);
	pieslice(x+8,y+5,0,360,1);
	pieslice(x+5,y+8,0,360,1);
	pieslice(x+11,y+8,0,360,1);
	pieslice(x+8,y+11,0,360,1);
}
void draw_ground()
{
	setlinestyle(0,0,3);
	setcolor(WHITE);
	rectangle(40,80,600,474);
	rectangle(0,220,40,340);
	rectangle(600,220,638,340);
	line(320,80,320,474);
	circle(320,280,60);
	arc(40,280,0,90,120);
	arc(40,280,270,360,120);
	arc(600,280,90,270,120);
	arc(40,80,270,360,20);
	arc(40,474,0,90,20);
	arc(600,80,180,270,20);
	arc(600,474,90,180,20);
}
draw_num(int x,int y,int num,int size)
{
	setlinestyle(0,0,1);
	switch(num)
	{
		case(0):line(x,y,x+size,y);
				lineto(x+size,y+2*size);
				lineto(x,y+2*size);
				lineto(x,y);
		case(1):line(x+size,y,x+size,y+2*size);
		case(2):line(x,y,x+size,y);
				lineto(x+size,y+size);
				lineto(x+size,y+size);
	}
}