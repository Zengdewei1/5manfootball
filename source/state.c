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

void PlayerChangestate(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball,player_state *pnewstate)//pteam是相对而言的
{
	// if(pplayer->pnowstate->Exit!=NULL)
	// {
	// 	pplayer->pnowstate->Exit(pmyteam,popteam,pplayer,pball);
	// }
	pplayer->pnowstate=pnewstate;
	if(pplayer->pnowstate->Enter!=NULL)
	{
		pplayer->pnowstate->Enter(pmyteam,popteam,pplayer,pball);
	}
}

void KeeperChangestate(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball,keeper_state *pnewstate)
{
	// if(pgoalkeeper->pnowstate->Exit!=NULL)
	// {
	// 	pgoalkeeper->pnowstate->Exit(pmyteam,popteam,pgoalkeeper,pball);
	// }
	pgoalkeeper->pnowstate=pnewstate;
	if(pgoalkeeper->pnowstate->Enter!=NULL)
	{
		pgoalkeeper->pnowstate->Enter(pmyteam,popteam,pgoalkeeper,pball);
	}
}

void BallChangestate(_team *pmyteam,_team *popteam,_ball *pball,ball_state *pnewstate)
{
	// if(pball->pnowstate->Exit!=NULL)
	// {
		// pball->pnowstate->Exit(pmyteam,popteam,pball);
	// }
	pball->pnowstate=pnewstate;
	if(pball->pnowstate->Enter!=NULL)
	{
		pball->pnowstate->Enter(pmyteam,popteam,pball);
	}
}
	
//球队状态
// void AttackExecute(_team *pmyteam,_team *popteam,_ball *pball)
// {
// 	int k=0;
// }



//球员状态
void ChasingBallExecute(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball)
{
	// if(pplayer->name==pmyteam->name)
	// {	
		action(pmyteam,popteam,pball);
		if(distance(pmyteam->player[pmyteam->controlplayer].now_pos.x+6,pmyteam->player[pmyteam->controlplayer].now_pos.y+17,pball->now_pos.x+6,pball->now_pos.y+6)<30.0)
		{
			pplayer->control=1;
			pmyteam->control=pplayer->ID;
			pball->control=pplayer->ID;
			BallChangestate(pmyteam,popteam,pball,&pball->Control);
			PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Dribble);
		}
	// }
	// else
	// {

	// }
	// pplayer->control=0;
	// pball->control=-1;
}
void DribbleExecute(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball)//pteam是相对而言的
{
	if(pplayer->name==Player)
		action(pmyteam,popteam,pball);
	else
		pplayer->velocity.y*=(-1);
}
void WaitExecute(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball)//pteam是相对而言的
{
	int k=0;
	// if(i%100==0)
	// 	auto_move(pmyteam,popteam,pplayer,pball);
	// switch(pmyteam)
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
// 			pball->name=team->name;
// 			pball->control=team->controlplayer;
// 			team->player[team->controlplayer].pnowstate=&team->player[team->controlplayer].Dribble;
// 			// PlayerChangeState();
// 		}
// }
// //守门员的状态
// void TendGoalExecute(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball)
// {
// 	if(pgoalkeeper->now_pos.y>=306.0)
// 		pgoalkeeper->velocity.y*=(-1.0);
// 	else if(pgoalkeeper->now_pos.y<=220.0)
// 		pgoalkeeper->velocity.y*=(-1.0);
// 	if(distance(pmyteam->goalkeeper.now_pos.x+6,pmyteam->goalkeeper.now_pos.y+17,pball->now_pos.x+4,pball->now_pos.y+4)<30.0)
// 		{
// 			popteam->control=0;
// 			popteam->player[popteam->controlplayer].pnowstate=&popteam->player[popteam->controlplayer].Wait;
// 			popteam->controlplayer=-1;
// 			pmyteam->control=1;
// 			pmyteam->goalkeeper.control=1;
// 			pmyteam->controlplayer=4;
// 			pball->control=1;
// 			pball->name=pmyteam->name;
// 			pmyteam->goalkeeper.pnowstate=&pmyteam->goalkeeper.Control;
// 			pgoalkeeper->velocity.x=0;
// 			pgoalkeeper->velocity.y=0;
// 			// PlayerChangeState();
// 		}
// }
// void ControlExecute(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball)
// {
// 	Pos2d pass_dir;
// 	// if(popteam->player[2].now_pos.x<=320.0&&popteam->player[3].now_pos.x<=320.0)
// 	// {
// 	// 	pmyteam->player[0].pnowstate=&pmyteam->player[0].ChasingBall;
// 	// 	pball->control=0;
// 	// 	pmyteam->goalkeeper.control=0;
// 	// 	pass_dir=get_dir(pball->now_pos,pmyteam->player[0].now_pos);
// 	// 	pball->velocity.x=4.0*pass_dir.x;
// 	// 	pball->velocity.y=4.0*pass_dir.y;
// 	// 	pgoalkeeper->pnowstate=&pgoalkeeper->TendGoal;
// 	// 	pgoalkeeper->velocity.y=4.0;
// 	// 	pmyteam->controlplayer=-1;
// 	// }
// }
//守门员的状态
void TendGoalExecute(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball)//pteam是相对而言的
{
	if(pgoalkeeper->now_pos.y>=276.0)
		pgoalkeeper->velocity.y*=(-1.0);
	else if(pgoalkeeper->now_pos.y<=250.0)
		pgoalkeeper->velocity.y*=(-1.0);
}
void PounceEnter(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball)
{
	if(pgoalkeeper->now_pos.y+17.0>280.0)
                {
                            pgoalkeeper->velocity.y=-2.0;
                }
    else
                {
                            pgoalkeeper->velocity.y=2.0;  
                }
}
void PounceExecute(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball)
{
            //   if(pball->now_pos.x>610.0)
			//   {
			// 	  init_team(pmyteam);
			// 	  init_team(popteam);
			// 	  pball->control=3;
			// 	  popteam
			//   }
              if(distance(pball->now_pos.x+6,pball->now_pos.y+6,pgoalkeeper->now_pos.x+6,pgoalkeeper->now_pos.y+17)<30.0)
                {
                     pgoalkeeper->pnowstate=&pgoalkeeper->ControlBall;
					 pgoalkeeper->control=1;
					 pball->control=4;
                }

}
void ControlBallExecute(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball)
{
	Pos2d pass_dir;
	// if(popteam->player[2].now_pos.x<=320.0&&popteam->player[3].now_pos.x<=320.0)
	//  {
	// 	pmyteam->player[0].pnowstate=&pmyteam->player[0].ChasingBall;
	// 	pball->control=0;
	// 	pmyteam->goalkeeper.control=0;
	// 	pass_dir=get_dir(pball->now_pos,pmyteam->player[0].now_pos);
	//                 pball->velocity.x=4.0*pass_dir.x;
	// 	pball->velocity.y=4.0*pass_dir.y;
	// 	pgoalkeeper->pnowstate=&pgoalkeeper->TendGoal;
	// 	pgoalkeeper->velocity.y=4.0;
	// 	pmyteam->controlplayer=-1;
	//  }
}

// void Long_passExecute(_team *pmyteam,_team *popteam,_ball *pball)//pmyteam为控球球队
// {
// 	double radio,x,y;
// 	x=team->player[team->controlplayer].now_pos.x-pball->now_pos.x;
// 	radio=(team->player[team->controlplayer].now_pos.y-pball->now_pos.y)/abs(x)/abs(x);
// 	if(x>0)
// 		pball->velocity.x=10.0;
// 	else
// 		pball->velocity.x=-10.0;
// 	pball->velocity.y=10.0*2*radio*abs(pball->now_pos.x-pball->start_pos.x);
// }

//足球状态

void Short_passEnter(_team *pmyteam,_team *popteam,_ball *pball)//pmyteam为控球球队
{
	Pos2d pass_dir;
	pass_dir=get_dir(pball->now_pos,pball->end_pos);
    pball->velocity.x=16.0*pass_dir.x;
    pball->velocity.y=16.0*pass_dir.y;
	
}

void Short_shootEnter(_team *pmyteam,_team *popteam,_ball *pball)//pmyteam为控球球队
{
	Pos2d gate,shoot_dir;
	gate.x=600.0;
	if(popteam->goalkeeper.now_pos.y+17>280)
    	gate.y=220.0;
    else
		gate.y=340.0-12.0;
	shoot_dir=get_dir(pball->now_pos,gate);
    pball->velocity.x=18.0*shoot_dir.x;
    pball->velocity.y=18.0*shoot_dir.y;
}

void ControlExecute(_team *pmyteam,_team *popteam,_ball *pball)
{
	pball->velocity.x=0.0;
	pball->velocity.y=0.0;
	if(pmyteam->player[pmyteam->controlplayer].dir==Left)
	{
		pball->now_pos.x=pmyteam->player[pmyteam->controlplayer].now_pos.x-16.0;
		pball->now_pos.y=pmyteam->player[pmyteam->controlplayer].now_pos.y+18.0;
	}
	else
	{
		pball->now_pos.x=pmyteam->player[pmyteam->controlplayer].now_pos.x+12.0;
		pball->now_pos.y=pmyteam->player[pmyteam->controlplayer].now_pos.y+18.0;
		
	}
}