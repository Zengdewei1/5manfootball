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

/*游戏界面*/
void game()
{
	_ball ball;
	_judge judge;
	_team myteam;
	_team opteam;
	int i;
	cleardevice();
	InstallKeyboard();
	// setfillstyle(1,BLACK);
	// circle(10,10,5);
	setfillstyle(1,GREEN);
    bar(0,0,640,480);
	init_team(&myteam,Red);
	init_team(&opteam,Blue);
	
	// for(i=0;i<4;i++)
	// {
	// 	init_player(&Rplayer[i],i);
	// 	init_player(&Bplayer[i],i);
	// }
	init_ball(&ball);
	init_judge(&judge);
	for(i=0;i<4;i++)
	{
		draw_player((int)(opteam.player[i].now_pos.x),(int)(opteam.player[i].now_pos.y),opteam.player[i].dir,0,opteam.player[i].ID,opteam.team_name);
	}
	draw_player((int)(opteam.goalkeeper.now_pos.x),(int)(opteam.goalkeeper.now_pos.y),opteam.goalkeeper.dir,0,4,opteam.team_name);
	for(i=0;i<4;i++)
	{
		draw_player((int)(myteam.player[i].now_pos.x),(int)(myteam.player[i].now_pos.y),myteam.player[i].dir,0,myteam.player[i].ID,opteam.team_name);
	}
	draw_player((int)(myteam.goalkeeper.now_pos.x),(int)(myteam.goalkeeper.now_pos.y),myteam.goalkeeper.dir,0,4,myteam.team_name);
	draw_ground();
	draw_judge((int)(judge.pos.x),(int)(judge.pos.y));
	draw_ball((int)(ball.now_pos.x),(int)(ball.now_pos.y));
	delay(400);
	while(1)
	{
		draw_ground();
		action(&myteam,&ball);
		if(KeyPress(KEY_ESC))
		{
			exit(0);
		}
		for(i=0;i<4;i++)
		{
			PlayerUpdate(&myteam,&opteam,&myteam.player[i],&ball);
		}
		for(i=0;i<4;i++)
		{
			PlayerUpdate(&opteam,&myteam,&opteam.player[i],&ball);
		}
		GoalkeeperUpdate(&myteam,&opteam,&myteam.goalkeeper,&ball);
		GoalkeeperUpdate(&opteam,&myteam,&opteam.goalkeeper,&ball);
		if(myteam.iscontrol==1)
			BallUpdate(&ball,&myteam.player[myteam.controlplayer]);
		else
			BallUpdate(&ball,&opteam.player[opteam.controlplayer]);
	}
}

// void PlayerChangestate(_player *pplayer,player_state *pnewstate,_team *pmyteam,_team *popteam)
// {
// 	if(pplayer->pnowstate->Exit!=NULL)
// 	{
// 		pplayer->pnowstate->Exit(pplayer,pmyteam,popteam);
// 	}pplayer->pnowstate=pnewstate;
// 	if(pplayer->pnowstate->Enter!=NULL)
// 	{
// 		pplayer->pnowstate->Enter(pplayer,pmyteam,popteam);
// 	}
// }
void ChasingBallExecute(_team *pteam1,_team *pteam2,_player *pplayer,_ball *pball)//pteam是相对而言的
{
	pteam1->player[pteam1->controlplayer].control=0;
	pball->control=0;
	if(distance(pteam1->player[pteam1->controlplayer].now_pos.x+6,pteam1->player[pteam1->controlplayer].now_pos.y+17,pball->now_pos.x+4,pball->now_pos.y+4)<30.0)
	{
			pteam1->player[pteam1->controlplayer].control=1;
			pteam1->iscontrol=1;
			pball->control=1;
			pball->team_name=pteam1->team_name;
			pteam1->player[pteam1->controlplayer].pnowstate=&pteam1->player[pteam1->controlplayer].Dribble;
			// PlayerChangeState();
	}
}
void DribbleExecute(_team *pteam1,_team *pteam2,_player *pplayer,_ball *pball)
{
	int k=0;
}
void WaitExecute(_team *pteam1,_team *pteam2,_player *pplayer,_ball *pball)
{
	int slow_rate=0.5,i=0;
	pplayer->velocity.x*=slow_rate;
	pplayer->velocity.y*=slow_rate;
	if(i%10==0)
		move_area(pteam1,pteam2,pplayer,pball);
	i++;
	// switch(pteam1)
	// team->player[team->controlplayer].control=0;
	// pball->control=0;
}
// void SupportingExecute(_team *team,_ball *pball)
// {
// 	int n=0;
// }
// void ReceivingBallExecute(_team *team,_ball *pball)
// {
// 	if(distance(team->player[team->controlplayer].now_pos.x+6,team->player[team->controlplayer].now_pos.y+17,pball->now_pos.x+4,pball->now_pos.y+4)<25.0)
// 		{
// 			team->player[team->controlplayer].control=1;
// 			pball->control=1;
// 			pball->team_name=team->team_name;
// 			pball->owner=team->controlplayer;
// 			team->player[team->controlplayer].pnowstate=&team->player[team->controlplayer].Dribble;
// 			// PlayerChangeState();
// 		}
// }
//守门员的状态
void TendGoalExecute(_team *pteam1,_team *pteam2,_goalkeeper *pgoalkeeper,_ball *pball)
{
	if(distance(pteam1->goalkeeper.now_pos.x+6,pteam1->goalkeeper.now_pos.y+17,pball->now_pos.x+4,pball->now_pos.y+4)<30.0)
		{
			pteam2->iscontrol=0;
			pteam1->iscontrol=1;
			pteam1->goalkeeper.control=1;
			pteam1->controlplayer=4;
			pball->control=1;
			pball->team_name=pteam1->team_name;
			pteam1->goalkeeper.pnowstate=&pteam1->goalkeeper.ReturnHome;
			// PlayerChangeState();
		}
}
void ReturnHomeExecute(_team *pteam1,_team *pteam2,_goalkeeper *pgoalkeeper,_ball *pball)
{
	int i=0;
}
void init_team(struct _TEAM *team,enum TeamName team_name)
{
	int i=0;
	team->team_name=team_name;
	team->iscontrol=0;
	team->controlplayer=-1;
	if(team_name==Red)
		team->controlplayer=3;
	for(;i<4;i++)
		init_player(&team->player[i],team->team_name,i);
	init_goalkeeper(&team->goalkeeper,team->team_name); 
}

//初始化球员位置信息
void init_player(_player *pplayer,enum TEAM_NAME team_name,int ID)
{	
	pplayer->ID=ID;
	pplayer->pnowstate=NULL;
	// pplayer->pnowstate = &pplayer->Wait;
	// // pplayer->Wait.Enter = WaitEnter;
    pplayer->Wait.Execute = WaitExecute;
    // pplayer->Wait.Exit = NULL;

    // pplayer->ReceivingBall.Enter = NULL;
    // pplayer->ReceivingBall.Execute = ReceivingBallExecute;
    // // pplayer->ReceivingBall.Exit = ReceivingBallExit;

    // pplayer->Dribble.Enter = NULL;
    pplayer->Dribble.Execute = DribbleExecute;
    // pplayer->Dribble.Exit = NULL;

    // pplayer->ChasingBall.Enter = NULL;
    pplayer->ChasingBall.Execute = ChasingBallExecute;
    // pplayer->ChasingBall.Exit = NULL;

    // pplayer->Supporting.Enter = NULL;
    // pplayer->Supporting.Execute = SupportingExecute;
    // // pplayer->Supporting.Exit = SupportingExit;

	if(team_name==Red)
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
				pplayer->pnowstate = &pplayer->ChasingBall;
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

void init_goalkeeper(_goalkeeper *pgoalkeeper,enum TEAM_NAME team_name)
{
	srand((unsigned)time(NULL));
	pgoalkeeper->TendGoal.Execute=TendGoalExecute;
	pgoalkeeper->ReturnHome.Execute=ReturnHomeExecute;
	if(team_name==Red)
	{
		pgoalkeeper->now_pos.x=40;
		pgoalkeeper->now_pos.y=305-rand()%86;
		pgoalkeeper->velocity.x=0;
		pgoalkeeper->velocity.y=5;
		pgoalkeeper->dir=Right;
		pgoalkeeper->pnowstate=&pgoalkeeper->TendGoal;
		pgoalkeeper->control=0;
	}
	else
	{
		pgoalkeeper->now_pos.x=600;
		pgoalkeeper->now_pos.y=221+rand()%86;
		pgoalkeeper->velocity.x=0;
		pgoalkeeper->velocity.y=5;
		pgoalkeeper->dir=Left;
		pgoalkeeper->pnowstate=&pgoalkeeper->TendGoal;
		pgoalkeeper->control=0;
	}
}
//初始化足球和裁判
void init_ball(struct _BALL *pball)
{
	pball->now_pos.x=320;
	pball->now_pos.y=280;
	pball->velocity.x=0.0;
	pball->velocity.y=0.0;
	pball->control=0;
	pball->timecount=0;
}
void init_judge(struct _JUDGE *pjudge)
{
	pjudge->pos.x=320.0;
	pjudge->pos.y=57.0;
}

void PlayerUpdate(_team *pteam1,_team *pteam2,_player *pplayer,_ball *pball)
{
	if(pplayer->pnowstate!=NULL)
	{
		// if(pplayer->ID==0)
		// {
		// 	setfillstyle(1,BLACK);
		// circle(20,20,5);
		// }
		pplayer->pnowstate->Execute(pteam1,pteam2,pplayer,pball);
	}
	pplayer->old_pos.x=pplayer->now_pos.x;
	pplayer->old_pos.y=pplayer->now_pos.y;
	pplayer->now_pos.x+=pplayer->velocity.x;
	pplayer->now_pos.y+=pplayer->velocity.y;
	setfillstyle(1,GREEN);
	bar((int)(pplayer->old_pos.x),(int)(pplayer->old_pos.y),(int)(pplayer->old_pos.x)+12,(int)(pplayer->old_pos.y)+34);
	draw_player((int)(pplayer->now_pos.x),(int)(pplayer->now_pos.y),pplayer->dir,pplayer->control,pplayer->ID,pteam1->team_name);
    if(pteam1->team_name==Red)
	{
		if(pplayer->ID==pteam1->controlplayer)
		{
			pplayer->velocity.x=0;
    		pplayer->velocity.y=0;
		}
	}
	delay(5);
}

void GoalkeeperUpdate(_team *pteam1,_team *pteam2,_goalkeeper *pgoalkeeper,_ball *pball)
{
	if(pgoalkeeper->pnowstate!=NULL)
	{
		pgoalkeeper->pnowstate->Execute(pteam1,pteam2,pgoalkeeper,pball);
	}
	pgoalkeeper->old_pos=pgoalkeeper->now_pos;
	pgoalkeeper->now_pos.y+=pgoalkeeper->velocity.y;
	pgoalkeeper->now_pos.x+=pgoalkeeper->velocity.x;
	if(pgoalkeeper->now_pos.y>=306.0)
		pgoalkeeper->velocity.y*=(-1.0);
	else if(pgoalkeeper->now_pos.y<=220.0)
		pgoalkeeper->velocity.y*=(-1.0);
	setfillstyle(1,GREEN);
	bar((int)(pgoalkeeper->old_pos.x),(int)(pgoalkeeper->old_pos.y),(int)(pgoalkeeper->old_pos.x)+12,(int)(pgoalkeeper->old_pos.y)+34);
	draw_player((int)(pgoalkeeper->now_pos.x),(int)(pgoalkeeper->now_pos.y),pgoalkeeper->dir,pgoalkeeper->control,4,pteam1->team_name);
}
void BallUpdate(struct _BALL *pball,struct _PLAYER *pplayer)
{
	float slow_rate=0.95;//减速率
	pball->old_pos.x=pball->now_pos.x;
	pball->old_pos.y=pball->now_pos.y;
	if (pball->control==1)
	{
		pball->velocity.x=0.0;
		pball->velocity.y=0.0;
		if(pplayer->dir==Left)
		{
			pball->now_pos.x=pplayer->now_pos.x-16.0;
			pball->now_pos.y=pplayer->now_pos.y+18.0;
		}
		else
		{
			pball->now_pos.x=pplayer->now_pos.x+12.0;
			pball->now_pos.y=pplayer->now_pos.y+18.0;
			
		}
		
	}
	else
	{
		pball->now_pos.x+=pball->velocity.x;
		pball->now_pos.y+=pball->velocity.y;
		pball->velocity.x*=slow_rate;
		pball->velocity.y*=slow_rate;
	}
	setfillstyle(1,GREEN);
		
	bar((int)(pball->old_pos.x),(int)(pball->old_pos.y),(int)(pball->old_pos.x)+16,(int)(pball->old_pos.y)+16);
	draw_ball((int)(pball->now_pos.x),(int)(pball->now_pos.y));
	pball->timecount++;
	if(pball->timecount>2500)
	{
		pball->timecount%=FPS;
	}
	delay(20);
}