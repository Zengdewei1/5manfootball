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

//传球函数
void pass(_team *pmyteam,_team *popteam,_ball *pball)//pmyteam为玩家球队
{
    int flag;
    flag=0;
    while(flag==0)
    {
        if(KeyPress(KEY_0))
        {
			if(pmyteam->controlplayer!=0)
			{
				pmyteam->player[pmyteam->controlplayer].control=0;
				PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->controlplayer],pball,&pmyteam->player[pmyteam->controlplayer].Wait);
				pmyteam->controlplayer=0;
				flag=1;
			}
            else 
			{
				flag=-1;
			}
        }
        else if(KeyPress(KEY_1))
        {
            if(pmyteam->controlplayer!=1)
			{
				pmyteam->player[pmyteam->controlplayer].control=0;
				PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->controlplayer],pball,&pmyteam->player[pmyteam->controlplayer].Wait);
				pmyteam->controlplayer=1;
				flag=1;
			}
            else
			{
				flag=-1;
			}
        }
        else if(KeyPress(KEY_2))
        {
            if(pmyteam->controlplayer!=2)
			{
				pmyteam->player[pmyteam->controlplayer].control=0;
				PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->controlplayer],pball,&pmyteam->player[pmyteam->controlplayer].Wait);
				pmyteam->controlplayer=2;
				flag=1;
			}
            else
			{
				flag=-1;
			}
        }
        else if(KeyPress(KEY_3))
        {
            if(pmyteam->controlplayer!=3)
			{
				pmyteam->player[pmyteam->controlplayer].control=0;
				PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->controlplayer],pball,&pmyteam->player[pmyteam->controlplayer].Wait);
				pmyteam->controlplayer=3;
				flag=1;
			}
            else
			{
				flag=-1;
			}
        }
    }
	// if((pball->now_pos.x-team->player[team->controlplayer].now_pos.x)*(pball->now_pos.x-team->player[team->controlplayer].now_pos.x)+(pball->now_pos.y-team->player[team->controlplayer].now_pos.y)*(pball->now_pos.y-team->player[team->controlplayer].now_pos.y)<=10000.0)
	// {
		if(flag==1)
		{
			pball->end_pos.x=pmyteam->player[pmyteam->controlplayer].now_pos.x;
			pball->end_pos.y=pmyteam->player[pmyteam->controlplayer].now_pos.y;
			PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->controlplayer],pball,&pmyteam->player[pmyteam->controlplayer].ChasingBall);
			BallChangestate(popteam,pmyteam,pball,&pball->Short_pass);
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
//控制球员移动或射门函数
void action(_team *pmyteam,_team *popteam,_ball *pball)//pmyteam玩家球队
{
		if(KeyPress(KEY_A))
		{
			pmyteam->player[pmyteam->controlplayer].velocity.x=-8.0;
			pmyteam->player[pmyteam->controlplayer].velocity.y=0;
			pmyteam->player[pmyteam->controlplayer].dir=Left;
		}
		if(KeyPress(KEY_D))
		{
			pmyteam->player[pmyteam->controlplayer].velocity.x=8.0;
			pmyteam->player[pmyteam->controlplayer].velocity.y=0;	
			pmyteam->player[pmyteam->controlplayer].dir=Right;
		}
		if(KeyPress(KEY_S))
		{
			pmyteam->player[pmyteam->controlplayer].velocity.x=0;
			pmyteam->player[pmyteam->controlplayer].velocity.y=8.0;

		}
		if(KeyPress(KEY_W))
		{
			pmyteam->player[pmyteam->controlplayer].velocity.x=0;
			pmyteam->player[pmyteam->controlplayer].velocity.y=-8.0;

		}
        if(pmyteam->player[pmyteam->controlplayer].pnowstate==&pmyteam->player[pmyteam->controlplayer].Dribble)
        {
            if(KeyPress(KEY_J))
		    {
				pmyteam->player[pmyteam->controlplayer].control=0;
				KeeperChangestate(pmyteam,popteam,&popteam->goalkeeper,pball,&popteam->goalkeeper.Pounce);
				BallChangestate(popteam,pmyteam,pball,&pball->Short_shoot);
				PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->controlplayer],pball,&pmyteam->player[pmyteam->controlplayer].ChasingBall);
		    }
            if(KeyPress(KEY_K))
		    {
		    	pass(pmyteam,popteam,pball);
		    }
        }
	
}
//限制球员的活动范围在一个矩形区域,type1-6表示6个不同的活动范围
// void move_renctangle(_player *pplayer,int type)
// {
// 	switch(type)
// 	{
// 		case(1):if(pplayer->now_pos.x<=240.0)//中场上
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
// 		case(2):if(pplayer->now_pos.x<=240.0)//中场下
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
// 		case(3):if(pplayer->now_pos.x<=400.0)//右场上
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
// 		case(4):if(pplayer->now_pos.x<=400.0)//右场下
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
// 		case(5):if(pplayer->now_pos.x<=160.0)//左场上
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
// 		case(6):if(pplayer->now_pos.x<=160.0)//左场下
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
//球员进入进攻或防守点位
void arrive(_player *pplayer,double _x,double _y)
{
	Pos2d destination,dir;
	destination.x=_x;
	destination.y=_y;
	dir=get_dir(pplayer->now_pos,destination);
	pplayer->velocity.x=6.0*dir.x;
	pplayer->velocity.y=6.0*dir.y;
}

void auto_act(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball)
{
	Pos2d far_dir,near_dir;
	double dy;
	if(pmyteam->name==Player)
	{
		if(pmyteam->pnowstate=&pmyteam->Attack)//我方进攻时
		{
			switch(pplayer->ID)
			{
				case(0):dy=abs(pplayer->now_pos.y-pball->now_pos.y);//跑位，纵坐标和球一致
						if(pplayer->now_pos.x<=120.0||pplayer->now_pos.x>=200.0)
						{
							arrive(pplayer,160.0,pball->now_pos.y);
						}
						else if(dy>=20.0)
						{
							pplayer->velocity.y=4.0*(pball->now_pos.y-pplayer->now_pos.y)/dy;
						}
						break;
				case(1):
						if(pplayer->now_pos.x<=280.0||pplayer->now_pos.x>=360.0)
						{
							arrive(pplayer,320.0,pball->now_pos.y);
						}
						else if(distance(pplayer->now_pos.x,pplayer->now_pos.y,popteam->player[3].now_pos.x,popteam->player[3].now_pos.y)<=100.0)//跑位，适当远离对方前锋3
						{
							far_dir=get_dir(pplayer->now_pos,popteam->player[3].now_pos);
							pplayer->velocity.x=-4.0*far_dir.x;
							pplayer->velocity.y=-4.0*far_dir.y;
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
						else if(distance(pplayer->now_pos.x,pplayer->now_pos.y,pmyteam->player[3].now_pos.x,pmyteam->player[3].now_pos.y)<=100.0)//跑位，适当远离我方前锋
						{
							far_dir=get_dir(pplayer->now_pos,pmyteam->player[3].now_pos);
							pplayer->velocity.x=-4.0*far_dir.x;
							pplayer->velocity.y=-4.0*far_dir.y;
						}
						else if(distance(pplayer->now_pos.x,pplayer->now_pos.y,popteam->player[0].now_pos.x,popteam->player[0].now_pos.y)<=50.0)//跑位，远离对方后卫0
						{
							far_dir=get_dir(pplayer->now_pos,pmyteam->player[3].now_pos);
							pplayer->velocity.x=-4.0*far_dir.x;
							pplayer->velocity.y=-4.0*far_dir.y;
						}
						else if(distance(pplayer->now_pos.x,pplayer->now_pos.y,popteam->player[1].now_pos.x,popteam->player[1].now_pos.y)<=50.0)//跑位，远离对方后卫1
						{
							far_dir=get_dir(pplayer->now_pos,pmyteam->player[3].now_pos);
							pplayer->velocity.x=-4.0*far_dir.x;
							pplayer->velocity.y=-4.0*far_dir.y;
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
						else if(distance(pplayer->now_pos.x,pplayer->now_pos.y,pmyteam->player[2].now_pos.x,pmyteam->player[2].now_pos.y)<=100.0)//跑位，适当远离我方前锋
						{
							far_dir=get_dir(pplayer->now_pos,pmyteam->player[2].now_pos);
							pplayer->velocity.x=-4.0*far_dir.x;
							pplayer->velocity.y=-4.0*far_dir.y;
						}
						else if(distance(pplayer->now_pos.x,pplayer->now_pos.y,popteam->player[0].now_pos.x,popteam->player[0].now_pos.y)<=50.0)//跑位，远离对方后卫0
						{
							far_dir=get_dir(pplayer->now_pos,pmyteam->player[2].now_pos);
							pplayer->velocity.x=-4.0*far_dir.x;
							pplayer->velocity.y=-4.0*far_dir.y;
						}
						else if(distance(pplayer->now_pos.x,pplayer->now_pos.y,popteam->player[1].now_pos.x,popteam->player[1].now_pos.y)<=50.0)//跑位，远离对方后卫1
						{
							far_dir=get_dir(pplayer->now_pos,pmyteam->player[2].now_pos);
							pplayer->velocity.x=-4.0*far_dir.x;
							pplayer->velocity.y=-4.0*far_dir.y;
						}
						// else
						// {
						// 	move_renctangle(pplayer,4);
						// 	move_dir(pplayer,pball);
						// }
						break;
			}
		}
		else//我方防守时
		{
			switch(pplayer->ID)
			{
				case(0):dy=abs(pplayer->now_pos.y-pball->now_pos.y);//跑位，纵坐标和球一致
						if(pplayer->now_pos.x<=120.0||pplayer->now_pos.x>=200.0||pplayer->now_pos.y<=80.0||pplayer->now_pos.y>=280.0)//紧跟球
						{
							arrive(pplayer,160.0,200.0);
						}
						else if(dy>=20.0)
						{
							pplayer->velocity.y=4.0*(pball->now_pos.y-pplayer->now_pos.y)/dy;
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
						else if(popteam->controlplayer==3)//紧跟对方2前锋
						{
							near_dir=get_dir(pplayer->now_pos,popteam->player[2].now_pos);
							pplayer->velocity.x=4.0*near_dir.x;
							pplayer->velocity.y=4.0*near_dir.y;
						}
						else if(popteam->controlplayer==2)//紧跟对方3前锋
						{
							near_dir=get_dir(pplayer->now_pos,popteam->player[3].now_pos);
							pplayer->velocity.x=4.0*near_dir.x;
							pplayer->velocity.y=4.0*near_dir.y;
						}
						// else
						// {
						// 	move_renctangle(pplayer,6);
						// 	move_dir(pplayer,pball);
						// }
						break;
				case(2):dy=abs(pplayer->now_pos.y-pball->now_pos.y);//跑位，纵坐标和球一致
						if(pplayer->now_pos.x<=200.0||pplayer->now_pos.x>=280.0)
						{
							arrive(pplayer,240.0,pball->now_pos.y);
						}
						else if(dy>=20.0)
						{
							pplayer->velocity.y=4.0*(pball->now_pos.y-pplayer->now_pos.y)/dy;
						}
						// else
						// {
						// 	move_renctangle(pplayer,1);
						// 	move_dir(pplayer,pball);
						// }
						break;
				case(3):if(pplayer->now_pos.x<=200.0||pplayer->now_pos.x>=280.0)//跑位，纵坐标和球一致
						{
							arrive(pplayer,240.0,380.0);
						}
						else if(dy>=20.0)
						{
							pplayer->velocity.y=4.0*(pball->now_pos.y-pplayer->now_pos.y)/dy;
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
		if(popteam->pnowstate=&popteam->Attack)//电脑进攻时
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
		else//电脑防守时
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
	double x,y,dist;
	double distance=0.0;
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

void draw_player(int x,int y,int dir,int control,int action,int ID,int color,int name)
{
    setlinestyle(0,0,1);
	if (color==Red)
	{
		setcolor(RED);
	}
	else
	{
		setcolor(BLUE);
	}
	// if(name==Player)
		draw_num(x+4,y+2,ID,4);
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
		pieslice(x+6,y+15,0,360,2);
	}
	if(action)
	{
		setfillstyle(1,BLACK);
		pieslice(x+6,y+25,0,360,3);
	}
	line(x+6,y+28,x,y+34);
    line(x+6,y+28,x+12,y+34);
}

void draw_ball(int x,int y)
{
	setcolor(BLACK);
	setfillstyle(1,WHITE);
	pieslice(x+6,y+6,0,360,6);
	setfillstyle(1,BLACK);
	pieslice(x+6,y+6,0,360,1);
	pieslice(x+6,y+3,0,360,1);
	pieslice(x+3,y+6,0,360,1);
	pieslice(x+9,y+6,0,360,1);
	pieslice(x+6,y+9,0,360,1);
}

void draw_num(int x,int y,int num,int size)
{
	switch(num)
	{
		case(0):line(x,y,x+size,y);
				line(x+size,y,x+size,y+2*size);
				line(x+size,y+2*size,x,y+2*size);
				line(x,y+2*size,x,y);
				break;
		case(1):line(x+size,y,x+size,y+2*size);
				break;
		case(2):line(x,y,x+size,y);
				line(x+size,y,x+size,y+size);
				line(x+size,y+size,x,y+size);
				line(x,y+size,x,y+2*size);
				line(x,y+2*size,x+size,y+2*size);
				break;
		case(3):line(x,y,x+size,y);
				line(x,y+size,x+size,y+size);
				line(x,y+2*size,x+size,y+2*size);
				line(x+size,y,x+size,y+2*size);
				break;
		case(4):line(x,y,x,y+size);
				line(x,y+size,x+size,y+size);
				line(x,y+size,x+size,y+size);
				line(x+size,y,x+size,y+2*size);
				break;
		case(5):line(x+size,y,x,y);
				line(x,y,x,y+size);
				line(x,y+size,x+size,y+size);
				line(x+size,y+size,x+size,y+2*size);
				line(x+size,y+2*size,x,y+2*size);
				break;
		case(6):line(x+size,y,x,y);
				line(x,y,x,y+size);
				line(x,y+size,x+size,y+size);
				line(x+size,y+size,x+size,y+2*size);
				line(x+size,y+2*size,x,y+2*size);
				line(x,y+2*size,x,y+size);
				break;
		case(7):line(x,y,x+size,y);
				line(x+size,y,x+size,y+2*size);
				break;
		case(8):line(x,y,x+size,y);
				line(x+size,y,x+size,y+2*size);
				line(x+size,y+2*size,x,y+2*size);
				line(x,y+2*size,x,y);
				line(x+size,y+size,x,y+size);
				break;
		case(9):line(x,y,x+size,y);
				line(x+size,y,x+size,y+2*size);
				line(x,y,x,y+size);
				line(x+size,y+size,x,y+size);
				line(x,y+2*size,x+size,y+2*size);
				break;
	}
}

void draw_time(int time)
{
	int minute,second,ten,single;
	minute=time/60;
	second=time%60;
	ten=second/10;
	single=second%10;
	setlinestyle(0,0,3);
	setcolor(BLACK);
	rectangle(210,5,310,45);
	setfillstyle(1,WHITE);
	bar(213,8,307,42);
	setcolor(RED);
	draw_num(215,10,minute,15);
	setfillstyle(1,RED);
	pieslice(245,15,0,360,3);
	pieslice(245,35,0,360,3);
	draw_num(260,10,ten,15);
	draw_num(290,10,single,15);
}

void draw_score(int score_my,int score_op)
{
	setlinestyle(0,0,3);
	setcolor(BLACK);
	rectangle(320,5,450,45);
	setfillstyle(1,WHITE);
	bar(323,8,447,42);
	setcolor(BLUE);
	draw_num(325,10,score_my/10,15);
	draw_num(355,10,score_my%10,15);
	setfillstyle(1,BLUE);
	pieslice(385,15,0,360,3);
	pieslice(385,35,0,360,3);
	draw_num(400,10,score_op/10,15);
	draw_num(430,10,score_op%10,15);
}

void draw_ground()
{
	setlinestyle(0,0,3);
	setcolor(WHITE);
	rectangle(40,80,600,478);
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

void draw_control(_team *pmyteam,_team *popteam)
{
	setlinestyle(0,0,3);
	setfillstyle(1,RED);
	setcolor(BLACK);
	rectangle(5,5,50,30);
	bar(8,8,47,27);
	draw_num(20,10,0,5);

	rectangle(5,35,50,60);
	bar(8,38,47,57);
	draw_num(20,40,1,5);

	rectangle(95,5,140,30);
	bar(98,8,137,27);
	draw_num(110,10,2,5);

	rectangle(95,35,140,60);
	bar(98,38,137,57);
	draw_num(110,40,3,5);
	setfillstyle(1,BLUE);
	rectangle(640-5-40,5,640-50-40,30);
	bar(640-8-40,8,640-47-40,27);
	draw_num(640-20-40,10,2,5);

	rectangle(640-5-40,35,640-50-40,60);
	bar(640-8-40,38,640-47-40,57);
	draw_num(640-20-40,40,3,5);

	rectangle(640-95-50,5,640-140-50,30);
	bar(640-98-50,8,640-137-50,27);
	draw_num(640-110-50,10,0,5);

	rectangle(640-95-50,35,640-140-50,60);
	bar(640-98-50,38,640-137-50,57);
	draw_num(640-110-50,40,1,5);
	setfillstyle(1,GREEN);
	bar(52,5,92,65);
	bar(142,5,180,65);
	bar(497,5,537,65);
	bar(597,5,640,65);
	setcolor(YELLOW);
	if(pmyteam->pnowstate==&pmyteam->Attack)
	{
		switch(pmyteam->controlplayer)
		{
			case(0):line(60,15,70,30);
					line(70,30,90,15);
					break;
			case(2):line(60+90,15,70+90,30);
					line(70+90,30,90+90,15);
					break;
			case(1):line(60,15+30,70,30+30);
					line(70,30+30,90,15+30);
					break;
			case(3):line(60+90,15+30,70+90,30+30);
					line(70+90,30+30,90+90,15+30);
					break;
		}
	}
	else if(popteam->pnowstate==&popteam->Attack)
	{
		switch(popteam->controlplayer)
		{
			case(0):line(640-95-40,15,640-125,30);
					line(640-125,30,640-105,15);
					break;
			case(2):line(640-95-40+90,15,640-125+90,30);
					line(640-125+90,30,640-105+90,15);
					break;
			case(1):line(640-95-40,15+30,640-125,30+30);
					line(640-125,30+30,640-105,15+30);
					break;
			case(3):line(640-95-40+90,15+30,640-125+90,30+30);
					line(640-125+90,30+30,640-105+90,15+30);
					break;
		}
	}
}

void player_border(_player *pplayer)
{
	if(pplayer->now_pos.x<40)
				{
				  pplayer->now_pos.x=40;
				}

			              if(pplayer->now_pos.x>588)
				 {
				  pplayer->now_pos.x=588;
				 }

		 	              if(pplayer->now_pos.y<80)
				{
				  pplayer->now_pos.y=80;
				}

			                if(pplayer->now_pos.y>440)
			                  {
			                   pplayer->now_pos.y=440;
				  }
}

void ball_border(_team *popteam,_team *pmyteam,_ball *pball)
{
	if(pball->now_pos.x<40||pball->now_pos.x>588||pball->now_pos.y<80||pball->now_pos.y>466&&pball->pnowstate!=&pball->Short_shoot)
	{
		if(pmyteam->pnowstate==&pmyteam->Attack)
		{
			init_team(pmyteam,pball);
				  init_team(popteam,pball);
				  setfillstyle(1,GREEN);	
				  bar((int)(pball->now_pos.x),(int)(pball->now_pos.y),(int)(pball->now_pos.x)+12,(int)(pball->now_pos.y)+12);
				  BallChangestate(popteam,pmyteam,pball,&pball->Control);
				  popteam->player[3].control=1;
				  PlayerChangestate(pmyteam,popteam,&popteam->player[3],pball,&popteam->player[3].Dribble);
				popteam->control=3;
				popteam->controlplayer=3;
				TeamChangestate(pmyteam,popteam,pball,&pmyteam->Defend,&popteam->Attack);
				pball->control=3;
				if(pball->now_pos.x>588&&pball->now_pos.y>=220&&pball->now_pos.y<=328)
				{
					pball->score_my++;
				}
				if(pball->now_pos.x<40&&pball->now_pos.y>=220&&pball->now_pos.y<=328)
				{
					pball->score_op++;
				}
		}
		// else
		// {

		// }
	}
}

 //画被覆盖的背景,2重循环算法
// void reback(int x,int y,int x_size,int y_size)
// {
// 	int mark=0;
// 	int i,j;
// 	for(i=x;i<=x+x_size;i++)
// 	{
// 		for(j=y;j<=y+y_size;j++)
// 		{
// 			if(((i>=40&&i<=41)||(i>=320&&i<=321)||(i>=600&&i<=601))&&(j>=80&&y<=480))//画3条竖线
// 				mark=1;
// 			else if(((i>=0&&i<=1)||(i>=639&&i<=640))&&(j>=220&&j<=340))
// 				mark=1;
// 			else if(((j>=80&&j<=81)||(j>=479&&j<=480))&&(i>=44&&i<=599))
// 				mark=1;
// 			else if(((j>=220&&j<=221)||(j>=340&&j<=341))&&((i>=4&&i<=39)||(i>=601&&i<=640)))
// 				mark=1;
// 			else if(((long int)(i-320)*(i-320)+(long int)(j-280)*(j-280)<=61*61)&&((long int)(long int)(i-320)*(i-320)+(long int)(j-280)*(j-280)>=60*60))
// 				mark=1;
// 			else if((((long int)(i-40)*(i-40)+(long int)(j-280)*(j-280)<=121*121)&&((long int)(long int)(i-40)*(i-40)+(long int)(j-280)*(j-280)>=120*120))&&(i>=40&&i<=161))
// 				mark=1;
// 			else if((((long int)(i-600)*(i-600)+(long int)(j-280)*(j-280)<=121*121)&&((long int)(long int)(i-600)*(i-600)+(long int)(j-280)*(j-280)>=120*120))&&(i>=479&&i<=600))
// 				mark=1;
            
//             if(mark==1)
//                 putpixel(i,j,WHITE);
//             mark=0;
// 		}
// 	}
// }