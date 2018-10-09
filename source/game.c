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
#include"state.h"

/*��һ�δ���£�
�����ϰ볡���°볡���������������ɫ����������������Ʊ���
*/

/*AI��һ�θ��£�
��ҿ���ʱ��
	����ң�һ��ǰ����ҿ��ƣ���һǰ��ǰ���󳡽�Ӧ��Զ����һǰ�棬Զ��Է���Ա����һ��ǰ����·��һ��ǰ����·��һ���������ں󳡣����������һ�£���һ�����������г�����Զ��з�ǰ�棩����Ϊ��Ӧ��Ա
	�Ե��ԣ�
���Կ���ʱ��
	����ң�2���������ڽ����ſڣ�һ����������һ��Ա������һǰ�棩��һ��ǰ��ط��󳡣���Զ��2������������һ�ߣ�����һǰ���г��ǻ������������һ�£����ȴ�����
	�Ե��ԣ�
*/

/*��Ϸ����*/
void game(int position1,int position2,int color1,int color2)
{
	int i;
	_ball ball;
	_judge judge;
	_team myteam;
	_team opteam;
	myteam.name=Player;
	myteam.position=position1;
	myteam.color=color1;
	opteam.name=Computer;
	opteam.position=position2;
	opteam.color=color2;
	cleardevice();
	InstallKeyboard();
	setfillstyle(1,GREEN);
    bar(0,0,640,480);
	init_team(&myteam);
	init_team(&opteam);
	init_ball(&ball);
	init_judge(&judge);
	for(i=0;i<4;i++)
	{
		draw_player((int)(myteam.player[i].now_pos.x),(int)(myteam.player[i].now_pos.y),myteam.player[i].dir,0,myteam.player[i].ID,myteam.color,myteam.name);
	}
	draw_player((int)(myteam.goalkeeper.now_pos.x),(int)(myteam.goalkeeper.now_pos.y),myteam.goalkeeper.dir,0,4,myteam.color,myteam.name);
	for(i=0;i<4;i++)
	{
		draw_player((int)(opteam.player[i].now_pos.x),(int)(opteam.player[i].now_pos.y),opteam.player[i].dir,0,opteam.player[i].ID,opteam.color,opteam.name);
	}
	draw_player((int)(opteam.goalkeeper.now_pos.x),(int)(opteam.goalkeeper.now_pos.y),opteam.goalkeeper.dir,0,4,opteam.color,opteam.name);
	draw_ground();
	draw_judge((int)(judge.pos.x),(int)(judge.pos.y));
	draw_ball((int)(ball.now_pos.x),(int)(ball.now_pos.y));
	delay(400);
	while(1)
	{
		if(KeyPress(KEY_ESC))
		{
			exit(0);
		}
		for(i=0;i<4;i++)
		{
			PlayerUpdate(&myteam,&opteam,&opteam.player[i],&ball,opteam.name);
		}
		GoalkeeperUpdate(&myteam,&opteam,&myteam.goalkeeper,&ball,myteam.name);
		GoalkeeperUpdate(&myteam,&opteam,&opteam.goalkeeper,&ball,opteam.name);
		BallUpdate(&myteam,&opteam,&ball);
		// TeamUpdate(&myteam,&opteam,&ball);
		for(i=0;i<4;i++)
		{
			PlayerUpdate(&myteam,&opteam,&myteam.player[i],&ball,myteam.name);
		}
		draw_ground();
	}
}



void init_team(_team *team)
{
	int i=0;
	// team->pnowstate=NULL;
	// team->Attack.Execute=AttackExecute;
	team->control=-1;
	team->controlplayer=-1;
	for(;i<4;i++)
		init_player(&team->player[i],team->position,i,team->name);
	init_goalkeeper(&team->goalkeeper,team->position,team->name); 
	if(team->name==Player)
	{
		team->controlplayer=3;
		team->player[3].pnowstate=&team->player[3].ChasingBall;
	}
}

//��ʼ����Աλ����Ϣ
void init_player(_player *pplayer,int position,int ID,int name)
{	
	pplayer->ID=ID;
	pplayer->name=name;
	// pplayer->pnowstate = &pplayer->Wait;
	pplayer->Wait.Enter = NULL;
    pplayer->Wait.Execute = WaitExecute;
    // pplayer->Wait.Exit = NULL;

    // pplayer->ReceivingBall.Enter = NULL;
    // pplayer->ReceivingBall.Execute = ReceivingBallExecute;
    // // pplayer->ReceivingBall.Exit = ReceivingBallExit;

    pplayer->Dribble.Enter = NULL;
    pplayer->Dribble.Execute = DribbleExecute;
    // pplayer->Dribble.Exit = NULL;

    pplayer->ChasingBall.Enter = NULL;
    pplayer->ChasingBall.Execute = ChasingBallExecute;
    // pplayer->ChasingBall.Exit = NULL;

    // pplayer->Supporting.Enter = NULL;
    // pplayer->Supporting.Execute = SupportingExecute;
    // // pplayer->Supporting.Exit =SupportingExit;
	pplayer->pnowstate=&pplayer->Wait;
	if(position==Left)
	{
		switch(ID)
		{
			case 0:	pplayer->now_pos.x=160;
				pplayer->now_pos.y=220;
				pplayer->velocity.x=0;
				pplayer->velocity.y=0;
				pplayer->dir=Right;
				break;
			case 1:	pplayer->now_pos.x=160;
				pplayer->now_pos.y=340;
				pplayer->velocity.x=0;
				pplayer->velocity.y=0;
				pplayer->dir=Right;
				break;
			case 2:	pplayer->now_pos.x=240;
				pplayer->now_pos.y=220;
				pplayer->velocity.x=0;
				pplayer->velocity.y=0;
				pplayer->dir=Right;
				break;
			case 3:	pplayer->now_pos.x=240;
				pplayer->now_pos.y=340;
				pplayer->velocity.x=0;
				pplayer->velocity.y=0;
				pplayer->dir=Right;
				break;
		}
	}
	else
	{
		switch(ID)
		{
			
			case 2:	pplayer->now_pos.x=400;
				pplayer->now_pos.y=220;
				pplayer->velocity.x=0;
				pplayer->velocity.y=0;
				pplayer->dir=Left;
				break;
			case 3:	pplayer->now_pos.x=400;
				pplayer->now_pos.y=340;
				pplayer->velocity.x=0;
				pplayer->velocity.y=0;
				pplayer->dir=Left;
				break;
			case 0:	pplayer->now_pos.x=480;
				pplayer->now_pos.y=220;
				pplayer->velocity.x=0;
				pplayer->velocity.y=0;
				pplayer->dir=Left;
				break;
			case 1:	pplayer->now_pos.x=480;
				pplayer->now_pos.y=340;
				pplayer->velocity.x=0;
				pplayer->velocity.y=0;
				pplayer->dir=Left;
				break;
		}
	}
}
void init_goalkeeper(_goalkeeper *pgoalkeeper,int position,int name)
{
	srand((unsigned)time(NULL));
	pgoalkeeper->name=name;
	pgoalkeeper->TendGoal.Enter=NULL;
	pgoalkeeper->TendGoal.Execute=TendGoalExecute;
	// pgoalkeeper->TendGoal.Exit=NULL;
	pgoalkeeper->ControlBall.Enter=NULL;
	pgoalkeeper->ControlBall.Execute=ControlBallExecute;
	// pgoalkeeper->ControlBall.Exit=NULL;
	pgoalkeeper->Pounce.Enter=PounceEnter;
	pgoalkeeper->Pounce.Execute=PounceExecute;
	// pgoalkeeper->Pounce.Exit=NULL;
	pgoalkeeper->control=0;
	if(position==Left)
	{
		pgoalkeeper->now_pos.x=42;
		pgoalkeeper->now_pos.y=276-rand()%26;
		pgoalkeeper->velocity.x=0;
		pgoalkeeper->velocity.y=1.2;
		pgoalkeeper->dir=Right;
		pgoalkeeper->pnowstate=&pgoalkeeper->TendGoal;
	}
	else
	{
		pgoalkeeper->now_pos.x=602;
		pgoalkeeper->now_pos.y=250+rand()%26;
		pgoalkeeper->velocity.x=0;
		pgoalkeeper->velocity.y=1.2;
		pgoalkeeper->dir=Left;
		pgoalkeeper->pnowstate=&pgoalkeeper->TendGoal;
	}
}
//��ʼ������Ͳ���
void init_ball(_ball *pball)
{
	pball->now_pos.x=322;
	pball->now_pos.y=280;
	pball->velocity.x=0.0;
	pball->velocity.y=0.0;
	pball->control=-1;
	pball->timecount=0;
	pball->pnowstate=NULL;
	pball->Control.Enter=NULL;
	pball->Control.Execute=ControlExecute;
	pball->Short_pass.Enter=Short_passEnter;
	pball->Short_pass.Execute=NULL;
	// pball->Long_pass.Execute=Long_passExecute;
	pball->Short_shoot.Enter=Short_shootEnter;
	pball->Short_shoot.Execute=NULL;
	// pball->Long_shoot.Execute=Long_shootExecute;
}
void init_judge(_judge *pjudge)
{
	pjudge->pos.x=320.0;
	pjudge->pos.y=57.0;
}

// void TeamUpdate(_team *pmyteam,_team *popteam,_ball *pball)//pteam����Զ��Ե�
// {
// 	if(pmyteam->pnowstate!=NULL)
// 		pmyteam->pnowstate->Execute(pmyteam,popteam,pball);
// }

void PlayerUpdate(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball,int teamname)
{
	if(pplayer->pnowstate!=NULL)
	{
		pplayer->pnowstate->Execute(pmyteam,popteam,pplayer,pball);
	}
	if(pplayer->velocity.x>0.0)
		pplayer->dir=Right;
	if(pplayer->velocity.x<0.0)
		pplayer->dir=Left;
	pplayer->old_pos.x=pplayer->now_pos.x;
	pplayer->old_pos.y=pplayer->now_pos.y;
	pplayer->now_pos.x+=pplayer->velocity.x;
	pplayer->now_pos.y+=pplayer->velocity.y;
	setfillstyle(1,GREEN);
	bar((int)(pplayer->old_pos.x),(int)(pplayer->old_pos.y),(int)(pplayer->old_pos.x)+12,(int)(pplayer->old_pos.y)+34);
	if(teamname==pmyteam->name)
		draw_player((int)(pplayer->now_pos.x),(int)(pplayer->now_pos.y),pplayer->dir,pplayer->control,pplayer->ID,pmyteam->color,pmyteam->name);
	else
		draw_player((int)(pplayer->now_pos.x),(int)(pplayer->now_pos.y),pplayer->dir,pplayer->control,pplayer->ID,popteam->color,popteam->name);
	pplayer->velocity.x=0.0;
    pplayer->velocity.y=0.0;
	delay(5);
}

void GoalkeeperUpdate(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball,int teamname)
{
	if(pgoalkeeper->pnowstate!=NULL)
	{
		pgoalkeeper->pnowstate->Execute(pmyteam,popteam,pgoalkeeper,pball);
	}
	pgoalkeeper->old_pos=pgoalkeeper->now_pos;
	pgoalkeeper->now_pos.y+=pgoalkeeper->velocity.y;
	pgoalkeeper->now_pos.x+=pgoalkeeper->velocity.x;
	setfillstyle(1,GREEN);
	bar((int)(pgoalkeeper->old_pos.x),(int)(pgoalkeeper->old_pos.y),(int)(pgoalkeeper->old_pos.x)+12,(int)(pgoalkeeper->old_pos.y)+34);
	if(teamname==pmyteam->name)
		draw_player((int)(pgoalkeeper->now_pos.x),(int)(pgoalkeeper->now_pos.y),pgoalkeeper->dir,pgoalkeeper->control,4,pmyteam->color,pmyteam->name);
	else
		draw_player((int)(pgoalkeeper->now_pos.x),(int)(pgoalkeeper->now_pos.y),pgoalkeeper->dir,pgoalkeeper->control,4,popteam->color,popteam->name);
}

void BallUpdate(_team *pmyteam,_team *popteam,_ball *pball)//pmyteamΪ�������
{
	float slow_rate=0.99;//������
	pball->old_pos.x=pball->now_pos.x;
	pball->old_pos.y=pball->now_pos.y;
	if(pball->pnowstate->Execute!=NULL)
		pball->pnowstate->Execute(pmyteam,popteam,pball);
	if (pball->control==-1)
	{
		pball->now_pos.x+=pball->velocity.x;
		pball->now_pos.y+=pball->velocity.y;
		pball->velocity.x*=slow_rate;
		pball->velocity.y*=slow_rate;
	}	
	bar((int)(pball->old_pos.x),(int)(pball->old_pos.y),(int)(pball->old_pos.x)+12,(int)(pball->old_pos.y)+12);
	draw_ball((int)(pball->now_pos.x),(int)(pball->now_pos.y));
	// pball->timecount++;
	// if(pball->timecount>2500)
	// {
	// 	pball->timecount%=FPS;
	// }
	// delay(10);
	// if(pball->old_pos.x!=pball->now_pos.x&&pball->old_pos.y!=pball->now_pos.y)
	// 	reback(pball->old_pos.x,pball->old_pos.y,16,16);
}