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
			PlayerUpdate(&opteam,&myteam,&opteam.player[i],&ball);
		}
		GoalkeeperUpdate(&myteam,&opteam,&myteam.goalkeeper,&ball);
		GoalkeeperUpdate(&opteam,&myteam,&opteam.goalkeeper,&ball);
		if(myteam.control!=-1)
			BallUpdate(&myteam,&opteam,&ball);
		else
			BallUpdate(&opteam,&myteam,&ball);
		for(i=0;i<4;i++)
		{
			PlayerUpdate(&myteam,&opteam,&myteam.player[i],&ball);
		}
		draw_ground();
	}
}

void PlayerChangestate(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball,player_state *pnewstate)//pteam����Զ��Ե�
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
	
//���״̬
void AttackExecute(_team *pmyteam,_team *popteam,_ball *pball)//pteam����Զ��Ե�
{
	int i=0;
}

void DefendExecute(_team *pmyteam,_team *popteam,_ball *pball)
{
	int i=0;
}


//��Ա״̬
void ChasingBallExecute(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball)//pteam����Զ��Ե�
{
	if(pmyteam->name==Player&&pplayer->ID==pmyteam->controlplayer)
		action(pmyteam,popteam,pball);
	// pplayer->control=0;
	// pball->control=-1;
	if(distance(pmyteam->player[pmyteam->controlplayer].now_pos.x+6,pmyteam->player[pmyteam->controlplayer].now_pos.y+17,pball->now_pos.x+4,pball->now_pos.y+4)<30.0)
	{
			pplayer->control=1;
			pmyteam->control=pplayer->ID;
			pball->control=pplayer->ID;
			BallChangestate(pmyteam,popteam,pball,&pball->Control);
			PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Dribble);
	}
}
void DribbleExecute(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball)//pteam����Զ��Ե�
{
	if(pmyteam->name==Player&&pplayer->ID==pmyteam->controlplayer)
		action(pmyteam,popteam,pball);
	else
		pplayer->velocity.y*=(-1);
}
void WaitExecute(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball)//pteam����Զ��Ե�
{
	int i=0;
	if(i%100==0)
		auto_move(pmyteam,popteam,pplayer,pball);
	i++;
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
// //����Ա��״̬
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
//����Ա��״̬
void TendGoalExecute(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball)//pteam����Զ��Ե�
{
	if(pgoalkeeper->now_pos.y>=276.0)
		pgoalkeeper->velocity.y*=(-1.0);
	else if(pgoalkeeper->now_pos.y<=250.0)
		pgoalkeeper->velocity.y*=(-1.0);
}
void PounceEnter(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball)
{
	if(pgoalkeeper->now_pos.y+17>280)
                {
                            pgoalkeeper->velocity.y=-2;
                }
    else
                {
                            pgoalkeeper->velocity.y=2;  
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

// void Long_passExecute(_team *pmyteam,_team *popteam,_ball *pball)//pmyteamΪ�������
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

//����״̬

void Short_passEnter(_team *pmyteam,_team *popteam,_ball *pball)//pmyteamΪ�������
{
	Pos2d pass_dir;
	pass_dir=get_dir(pball->now_pos,pball->end_pos);
    pball->velocity.x=16.0*pass_dir.x;
    pball->velocity.y=16.0*pass_dir.y;
	
}

void Short_shootEnter(_team *pmyteam,_team *popteam,_ball *pball)//pmyteamΪ�������
{
	Pos2d gate,shoot_dir;
	if(pmyteam->control!=-1)
	{
		gate.x=600.0;
		if(popteam->goalkeeper.now_pos.y+17>280)
    		gate.y=220.0;
    	else
			gate.y=340.0-12.0;
	}
	else
	{
		gate.x=40.0;
		if(pmyteam->goalkeeper.now_pos.y+17>280)
    		gate.y=220.0;
    	else
			gate.y=340.0-12.0;
	}
	shoot_dir=get_dir(pball->now_pos,gate);
    pball->velocity.x=18.0*shoot_dir.x;
    pball->velocity.y=18.0*shoot_dir.y;
}

void ControlExecute(_team *pmyteam,_team *popteam,_ball *pball)
{
	pball->velocity.x=0.0;
	pball->velocity.y=0.0;
	if(pmyteam->control!=-1)
	{
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
	else
	{
		if(popteam->player[popteam->controlplayer].dir==Left)
		{
			pball->now_pos.x=popteam->player[popteam->controlplayer].now_pos.x-16.0;
			pball->now_pos.y=popteam->player[popteam->controlplayer].now_pos.y+18.0;
		}
		else
		{
			pball->now_pos.x=popteam->player[popteam->controlplayer].now_pos.x+12.0;
			pball->now_pos.y=popteam->player[popteam->controlplayer].now_pos.y+18.0;
		
		}
	}
}

void init_team(struct _TEAM *team)
{
	int i=0;
	team->pnowstate=NULL;
	team->Attack.Execute=AttackExecute;
	team->Defend.Execute=DefendExecute;
	team->control=-1;
	team->controlplayer=-1;
	if(team->name==Player)
		team->controlplayer=3;
	for(;i<4;i++)
		init_player(&team->player[i],team->position,i,team->name);
	init_goalkeeper(&team->goalkeeper,team->position); 
}

//��ʼ����Աλ����Ϣ
void init_player(_player *pplayer,int position,int ID,int name)
{	
	pplayer->ID=ID;
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
void init_goalkeeper(_goalkeeper *pgoalkeeper,int position)
{
	srand((unsigned)time(NULL));
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
void init_ball(struct _BALL *pball)
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
void init_judge(struct _JUDGE *pjudge)
{
	pjudge->pos.x=320.0;
	pjudge->pos.y=57.0;
}

void TeamUpdate(_team *pmyteam,_team *popteam,_ball *pball)//pteam����Զ��Ե�
{
	if(pmyteam->pnowstate!=NULL)
		pmyteam->pnowstate->Execute(pmyteam,popteam,pball);
}

void PlayerUpdate(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball)
{
	if(pplayer->pnowstate!=NULL)
	{
		pplayer->pnowstate->Execute(pmyteam,popteam,pplayer,pball);
	}
	if(pplayer->velocity.x>0)
		pplayer->dir=Right;
	if(pplayer->velocity.x<0)
		pplayer->dir=Left;
	pplayer->old_pos.x=pplayer->now_pos.x;
	pplayer->old_pos.y=pplayer->now_pos.y;
	pplayer->now_pos.x+=pplayer->velocity.x;
	pplayer->now_pos.y+=pplayer->velocity.y;
	setfillstyle(1,GREEN);
	bar((int)(pplayer->old_pos.x),(int)(pplayer->old_pos.y),(int)(pplayer->old_pos.x)+12,(int)(pplayer->old_pos.y)+34);
	draw_player((int)(pplayer->now_pos.x),(int)(pplayer->now_pos.y),pplayer->dir,pplayer->control,pplayer->ID,pmyteam->color,pmyteam->name);
	pplayer->velocity.x=0.0;
    pplayer->velocity.y=0.0;
	delay(5);
}

void GoalkeeperUpdate(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball)
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
	draw_player((int)(pgoalkeeper->now_pos.x),(int)(pgoalkeeper->now_pos.y),pgoalkeeper->dir,pgoalkeeper->control,4,pmyteam->color,pmyteam->name);
}
void BallUpdate(_team *pteam1,_team *pteam2,_ball *pball)//pteam1Ϊ�������
{
	float slow_rate=0.99;//������
	pball->old_pos.x=pball->now_pos.x;
	pball->old_pos.y=pball->now_pos.y;
	if(pball->pnowstate->Execute!=NULL)
		pball->pnowstate->Execute(pteam1,pteam2,pball);
	if (pball->control==-1)
	{
		pball->now_pos.x+=pball->velocity.x;
		pball->now_pos.y+=pball->velocity.y;
		pball->velocity.x*=slow_rate;
		pball->velocity.y*=slow_rate;
	}	
	bar((int)(pball->old_pos.x),(int)(pball->old_pos.y),(int)(pball->old_pos.x)+12,(int)(pball->old_pos.y)+12);
	draw_ball((int)(pball->now_pos.x),(int)(pball->now_pos.y));
	pball->timecount++;
	if(pball->timecount>2500)
	{
		pball->timecount%=FPS;
	}
	delay(10);
	// if(pball->old_pos.x!=pball->now_pos.x&&pball->old_pos.y!=pball->now_pos.y)
	// 	reback(pball->old_pos.x,pball->old_pos.y,16,16);
}