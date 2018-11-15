#include "main.h"

/*????δ?????
??????????°?????????????????????????????????????
*/

/*AI????θ????
?????????
	??????????????????????????????????????????棬????????????????????·??????????·??????????????????????????????????????????г????????з???棩???????????
	??????
??????????
	??????2???????????????????????????????????????棩??????????????????2?????????????????????????г????????????????????????????
	??????
*/

/*???????*/
void game(int position1,int position2,int color1,int color2,int match)
{
	int i=0,award=0,money=0;
	FILE *fp,*fpmoney;
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
	ball.flag=0;
	ball.timecount=0;
	init_ball(&opteam,&myteam,&ball);
	init_team(&myteam,&ball);
	init_team(&opteam,&ball);
	init_judge(&judge);
	playerPower(&myteam);
	playerPower(&opteam);
	for(i=0;i<4;i++)
	{
		draw_player((int)(myteam.player[i].now_pos.x),(int)(myteam.player[i].now_pos.y),myteam.player[i].dir,0,0,myteam.player[i].ID,myteam.color,myteam.name);
		if(myteam.position==Left)
		{
			myteam.player[i].score=0;
			myteam.player[i].help=0;
		}
	}
	draw_player((int)(myteam.goalkeeper.now_pos.x),(int)(myteam.goalkeeper.now_pos.y),myteam.goalkeeper.dir,0,0,4,myteam.color,myteam.name);
	for(i=0;i<4;i++)
	{
		draw_player((int)(opteam.player[i].now_pos.x),(int)(opteam.player[i].now_pos.y),opteam.player[i].dir,0,0,opteam.player[i].ID,opteam.color,opteam.name);
		if(myteam.position==Left)
		{
			opteam.player[i].score=0;
			opteam.player[i].help=0;
		}
	}
	if(position1==Left)
	{
		ball.time=0;
		ball.score_my=0;
		ball.score_op=0;
	}
	else
	{
		ball.time=150;
		if(match!=0)
		{
			switch(match%20)
			{
				case 1:fp=fopen("c:\\mycode\\result\\result1.txt","r");
						break;
				case 2:fp=fopen("c:\\mycode\\result\\result2.txt","r");
						break;
				case 3:fp=fopen("c:\\mycode\\result\\result3.txt","r");
						break;
				case 4:fp=fopen("c:\\mycode\\result\\result4.txt","r");
						break;
				case 5:fp=fopen("c:\\mycode\\result\\result5.txt","r");
						break;
				case 6:fp=fopen("c:\\mycode\\result\\result6.txt","r");
						break;
				case 7:fp=fopen("c:\\mycode\\result\\result7.txt","r");
						break;
				case 8:fp=fopen("c:\\mycode\\result\\result8.txt","r");
						break;
				case 9:fp=fopen("c:\\mycode\\result\\result9.txt","r");
						break;
				case 10:fp=fopen("c:\\mycode\\result\\esult10.txt","r");
						break;
				case 11:fp=fopen("c:\\mycode\\result\\result11.txt","r");
						break;
				case 12:fp=fopen("c:\\mycode\\result\\result12.txt","r");
						break;
				case 13:fp=fopen("c:\\mycode\\result\\rresult13.txt","r");
						break;
				case 14:fp=fopen("c:\\mycode\\result\\result14.txt","r");
						break;
				case 15:fp=fopen("c:\\mycode\\result\\result15.txt","r");
						break;
				case 16:fp=fopen("c:\\mycode\\result\\result16.txt","r");
						break;
				case 17:fp=fopen("c:\\mycode\\result\\result17.txt","r");
						break;
				case 18:fp=fopen("c:\\mycode\\result\\result18.txt","r");
						break;
				case 19:fp=fopen("c:\\mycode\\result\\result19.txt","r");
						break;
				case 0:fp=fopen("c:\\mycode\\result\\result20.txt","r");
						break;
			}
			if(fp==NULL)
			{
				printf("can not open");
				getch();
				exit(1);
			}
			fscanf(fp,"%d\n%d\n",&ball.score_my,&ball.score_op);
			for(i=0;i<4;i++)
			{
				fscanf(fp,"%d\n",&myteam.player[i].score);
			}
			for(i=0;i<4;i++)
			{
				fscanf(fp,"%d\n",&opteam.player[i].score);
			}
			for(i=0;i<4;i++)
			{
				fscanf(fp,"%d\n",&myteam.player[i].help);
			}
			for(i=0;i<4;i++)
			{
				fscanf(fp,"%d\n",&opteam.player[i].help);
			}
			fclose(fp);
		}
		else
		{
			fp=fopen("c:\\mycode\\result\\result.txt","r");
			if(fp==NULL)
			{
				printf("can not open");
				getch();
				exit(1);
			}
			fscanf(fp,"%d\n%d\n",&ball.score_my,&ball.score_op);
			for(i=0;i<4;i++)
			{
				fscanf(fp,"%d\n",&myteam.player[i].score);
			}
			for(i=0;i<4;i++)
			{
				fscanf(fp,"%d\n",&opteam.player[i].score);
			}
			for(i=0;i<4;i++)
			{
				fscanf(fp,"%d\n",&myteam.player[i].help);
			}
			for(i=0;i<4;i++)
			{
				fscanf(fp,"%d\n",&opteam.player[i].help);
			}
			fclose(fp);
		}
		// fp=fopen("c:\\mycode\\result\\one.txt","r");
		// fp=fopen("c:\\mycode\\name\\result.txt","r");
		// fp=fopen("c:\\mycode\\name\\result2.txt","w");
	}
	draw_player((int)(opteam.goalkeeper.now_pos.x),(int)(opteam.goalkeeper.now_pos.y),opteam.goalkeeper.dir,0,0,4,opteam.color,opteam.name);
	draw_ground();
	draw_judge((int)(judge.pos.x),(int)(judge.pos.y));
	draw_ball((int)(ball.now_pos.x),(int)(ball.now_pos.y));
	draw_time(ball.time);
	draw_score(ball.score_my,ball.score_op);
	while(ball.flag==0)
	{
		TeamUpdate(&myteam,&opteam,&ball);
		if(KeyPress(KEY_ESC))
		{
			exit(0);
		}
		if(KeyPress(KEY_P))
		{
			while(1)
			{
				if(KeyPress(KEY_Y))
				{
					break;
				}
			}
		}
		for(i=0;i<4;i++)
		{
			PlayerUpdate(&myteam,&opteam,&myteam.player[i],&ball);
		}
		for(i=0;i<4;i++)
		{
			PlayerUpdate(&myteam,&opteam,&opteam.player[i],&ball);
		}
		GoalkeeperUpdate(&myteam,&opteam,&myteam.goalkeeper,&ball);
		GoalkeeperUpdate(&myteam,&opteam,&opteam.goalkeeper,&ball);
		BallUpdate(&opteam,&myteam,&ball);
		draw_ground();
		// if(myteam.passman!=-1&&ball.time%10==0)
		// 	printf("%d\n",myteam.passman);
		// if(opteam.passman!=-1&&ball.time%10==0)
		// 	printf("%d\n",opteam.passman);
	}
	// printf("%d",match);
	if(match!=0)
	{
		switch(match%20)
		{
			case 1:fp=fopen("c:\\mycode\\result\\result1.txt","w");
					break;
			case 2:fp=fopen("c:\\mycode\\result\\result2.txt","w");
					break;
			case 3:fp=fopen("c:\\mycode\\result\\result3.txt","w");
					break;
			case 4:fp=fopen("c:\\mycode\\result\\result4.txt","w");
					break;
			case 5:fp=fopen("c:\\mycode\\result\\result5.txt","w");
					break;
			case 6:fp=fopen("c:\\mycode\\result\\result6.txt","w");
					break;
			case 7:fp=fopen("c:\\mycode\\result\\result7.txt","w");
					break;
			case 8:fp=fopen("c:\\mycode\\result\\result8.txt","w");
					break;
			case 9:fp=fopen("c:\\mycode\\result\\result9.txt","w");
					break;
			case 10:fp=fopen("c:\\mycode\\result\\result10.txt","w");
					break;
			case 11:fp=fopen("c:\\mycode\\result\\result11.txt","w");
					break;
			case 12:fp=fopen("c:\\mycode\\result\\result12.txt","w");
					break;
			case 13:fp=fopen("c:\\mycode\\result\\result13.txt","w");
					break;
			case 14:fp=fopen("c:\\mycode\\result\\result14.txt","w");
					break;
			case 15:fp=fopen("c:\\mycode\\result\\result15.txt","w");
					break;
			case 16:fp=fopen("c:\\mycode\\result\\result16.txt","w");
					break;
			case 17:fp=fopen("c:\\mycode\\result\\result17.txt","w");
					break;
			case 18:fp=fopen("c:\\mycode\\result\\result18.txt","w");
					break;
			case 19:fp=fopen("c:\\mycode\\result\\result19.txt","w");
					break;
			case 0:fp=fopen("c:\\mycode\\result\\result20.txt","w");
					break;
		}
		if(fp==NULL)
		{
			printf("end not open");
			getch();
			exit(1);
		}
		// fp=fopen("c:\\mycode\\name\\result.txt","w");
		fprintf(fp,"%d\n%d\n",ball.score_my,ball.score_op);
		for(i=0;i<4;i++)
		{
			fprintf(fp,"%d\n",myteam.player[i].score);
		}
		for(i=0;i<4;i++)
		{
			fprintf(fp,"%d\n",opteam.player[i].score);
		}
		for(i=0;i<4;i++)
		{
			fprintf(fp,"%d\n",myteam.player[i].help);
		}
		for(i=0;i<4;i++)
		{
			fprintf(fp,"%d\n",opteam.player[i].help);
		}
		fclose(fp);
	}
	else
	{
		fp=fopen("c:\\mycode\\result\\result.txt","w");
		if(fp==NULL)
		{
			printf("can not open");
			getch();
			exit(1);
		}
		fprintf(fp,"%d\n%d\n",ball.score_my,ball.score_op);
		for(i=0;i<4;i++)
		{
			fprintf(fp,"%d\n",myteam.player[i].score);
		}
		for(i=0;i<4;i++)
		{
			fprintf(fp,"%d\n",opteam.player[i].score);
		}
		for(i=0;i<4;i++)
		{
			fprintf(fp,"%d\n",myteam.player[i].help);
		}
		for(i=0;i<4;i++)
		{
			fprintf(fp,"%d\n",opteam.player[i].help);
		}
		fclose(fp);
	}
	if(position1==Right)
	{
		award=(ball.score_my-ball.score_op)*100;
		if(ball.score_my>ball.score_op)
		{
			award+=100;
		}
		else if(ball.score_my==ball.score_op)
		{
			award+=50;
		}
		else
		{
			award-=50;
		}
		if((fpmoney=fopen("c:\\mycode\\shop\\money.txt","r"))==NULL)
		{
			printf("can not open");
			getch();
			exit(1);
		}
		fscanf(fpmoney,"%d",&money);
		// printf("%d",money);
		fclose(fpmoney);
		money=money+award;
		// printf("%d",award);
		// printf("%d",money);
		if((fpmoney=fopen("c:\\mycode\\shop\\money.txt","w"))==NULL)
		{
			printf("can not open");
			getch();
			exit(1);
		}
		i=0;
		if(money<10)
		{
			fprintf(fpmoney,"%d",i);
			fprintf(fpmoney,"%d",i);
			fprintf(fpmoney,"%d",i);
		}
		else if(money<100)
		{
			fprintf(fpmoney,"%d",i);
			fprintf(fpmoney,"%d",i);
		}
		else if(money<1000)
		{
			fprintf(fpmoney,"%d",i);
		}
		fprintf(fpmoney,"%d",money);
		fclose(fpmoney);
	}
}

void TeamChangestate(_team *pmyteam,_team *popteam,_ball *pball,team_state *pnewstate_my,team_state *pnewstate_op)
{
	pmyteam->pnowstate=pnewstate_my;
	popteam->pnowstate=pnewstate_op;
	if(pmyteam->pnowstate->Enter!=NULL)
	{
		pmyteam->pnowstate->Enter(pmyteam,popteam,pball);
	}
	if(popteam->pnowstate->Enter!=NULL)
	{
		popteam->pnowstate->Enter(pmyteam,popteam,pball);
	}
}

void PlayerChangestate(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball,player_state *pnewstate)
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

void BallChangestate(_team *popteam,_team *pmyteam,_ball *pball,ball_state *pnewstate)
{
	// if(pball->pnowstate->Exit!=NULL)
	// {
		// pball->pnowstate->Exit(pmyteam,popteam,pball);
	// }
	pball->pnowstate=pnewstate;
	if(pball->pnowstate->Enter!=NULL)
	{
		pball->pnowstate->Enter(popteam,pmyteam,pball);
	}
}
	
//?????

void AttackEnter(_team *pmyteam,_team *popteam,_ball *pball)
{
	int i;
	pmyteam->passman=-1;
	popteam->passman=-1;
	for(i=0;i<4;i++)
	{
		if(pmyteam->player[i].pnowstate==&pmyteam->player[i].Actioning||pmyteam->player[i].pnowstate==&pmyteam->player[i].Wait)
		{
		// 	setfillstyle(1,BLACK);
		// circle(10,10,10);
			PlayerChangestate(pmyteam,popteam,&pmyteam->player[i],pball,&pmyteam->player[i].Wait);
		}
		if(popteam->player[i].pnowstate==&popteam->player[i].Actioning||popteam->player[i].pnowstate==&popteam->player[i].Wait)
			PlayerChangestate(pmyteam,popteam,&popteam->player[i],pball,&popteam->player[i].Wait);
		// PlayerChangestate(pmyteam,popteam,&popteam->player[3],pball,&popteam->player[3].Wait);
	}
}

void AttackExecute(_team *pmyteam,_team *popteam,_ball *pball)
{
	double x,y;
	int i=0;
	// int receivingman;
	if(popteam->control==3)
	{
		if(pmyteam->position==Left)
		{
			x=160.0;
			y=400.0;
		}
		else
		{
			x=480.0;
			y=400.0;
		}
	}
	if(popteam->control==2)
	{
		if(pmyteam->position==Left)
		{
			x=160.0;
			y=160.0;
		}
		else
		{
			x=480.0;
			y=160.0;
		}
	}
	if(popteam->pnowstate==&popteam->Attack)
	{
		setfillstyle(1,BLACK);
		circle(10,10,10);
		// if(nearDist(pmyteam,popteam,pball,&popteam->player[popteam->controlplayer])<60.0)
		// {
		// 	int receivingman=findPass(pmyteam,popteam,pball);
		// 	pball->end_pos.x=popteam->player[receivingman].now_pos.x+6;
		// 	pball->end_pos.y=popteam->player[receivingman].now_pos.y+17;
		// 	BallChangestate(popteam,pmyteam,pball,&pball->Short_pass);
		// 	PlayerChangestate(pmyteam,popteam,&popteam->player[popteam->controlplayer],pball,&popteam->player[popteam->controlplayer].Wait);
		// 	popteam->passman=popteam->control;
		// 	popteam->player[popteam->controlplayer].control=0;
		// 	popteam->control=-1;
		// 	popteam->controlplayer=receivingman;
		// 	PlayerChangestate(pmyteam,popteam,&popteam->player[receivingman],pball,&popteam->player[receivingman].ChasingBall);
		// 	// printf("%d\n",receivingman);
		// }
		if(popteam->control==0&&pball->timecount%5==0)
		{
			pball->end_pos.x=popteam->player[1].now_pos.x+6;
			pball->end_pos.y=popteam->player[1].now_pos.y+17;
			BallChangestate(popteam,pmyteam,pball,&pball->Short_pass);
			PlayerChangestate(pmyteam,popteam,&popteam->player[0],pball,&popteam->player[0].Wait);
			popteam->passman=popteam->control;
			popteam->player[0].control=0;
			popteam->control=-1;
			PlayerChangestate(pmyteam,popteam,&popteam->player[1],pball,&popteam->player[1].ChasingBall);
			popteam->controlplayer=1;
		}
		if(popteam->control==1&&popteam->player[3].pnowstate==&popteam->player[3].Actioning&&pball->timecount%5==0)
		{
			pball->end_pos.x=popteam->player[3].now_pos.x+6;
			pball->end_pos.y=popteam->player[3].now_pos.y+17;
			BallChangestate(popteam,pmyteam,pball,&pball->Short_pass);
			PlayerChangestate(pmyteam,popteam,&popteam->player[1],pball,&popteam->player[1].Wait);
			popteam->passman=popteam->control;
			popteam->player[1].control=0;
			popteam->control=-1;
			PlayerChangestate(pmyteam,popteam,&popteam->player[3],pball,&popteam->player[3].ChasingBall);
			popteam->controlplayer=3;
		}
		if(popteam->control==3&&distance(popteam->player[3].now_pos.x,popteam->player[3].now_pos.y,x,y)<10.0&&pball->timecount%5==0)
		{
			KeeperChangestate(pmyteam,popteam,&pmyteam->goalkeeper,pball,&pmyteam->goalkeeper.Pounce);
			if(pball->timecount%3==0)
			{
				BallChangestate(popteam,pmyteam,pball,&pball->Short_shoot);
			}
			else
			{
				pball->control=-1;
				if(popteam->control!=-1)
					popteam->control=-1;
				else
					pmyteam->control=-1;
				pball->start_pos=pball->now_pos;
				if(pmyteam->position==Left)
				{
					pball->end_pos.x=40.0;
				}
				else
				{
					pball->end_pos.x=600.0;
				}
				if(pball->now_pos.y>340.0)
				{
					pball->end_pos.y=340.0;
				}
				else if(pball->now_pos.y<220.0)
				{
					pball->end_pos.y=220.0;
				}
				else
				{
					pball->end_pos.y=280.0;
				}
				popteam->player[popteam->controlplayer].control=0;
				KeeperChangestate(pmyteam,popteam,&pmyteam->goalkeeper,pball,&pmyteam->goalkeeper.Pounce);
				BallChangestate(popteam,pmyteam,pball,&pball->Long_shoot);
				PlayerChangestate(pmyteam,popteam,&popteam->player[popteam->controlplayer],pball,&popteam->player[popteam->controlplayer].ChasingBall);
			}
			PlayerChangestate(pmyteam,popteam,&popteam->player[3],pball,&popteam->player[3].Wait);
			popteam->passman=popteam->control;
			popteam->player[3].control=0;
			popteam->control=-1;
			popteam->controlplayer=2;
		}
		if(popteam->control==2&&distance(popteam->player[2].now_pos.x,popteam->player[2].now_pos.y,x,y)<10.0&&pball->timecount%5==0)
		{
			KeeperChangestate(pmyteam,popteam,&pmyteam->goalkeeper,pball,&pmyteam->goalkeeper.Pounce);
			if(pball->timecount%3==0)
			{
				BallChangestate(popteam,pmyteam,pball,&pball->Short_shoot);
			}
			else
			{
				pball->control=-1;
				if(popteam->control!=-1)
					popteam->control=-1;
				else
					pmyteam->control=-1;
				pball->start_pos=pball->now_pos;
				if(pmyteam->position==Left)
				{
					pball->end_pos.x=40.0;
				}
				else
				{
					pball->end_pos.x=600.0;
				}
				if(pball->now_pos.y>340.0)
				{
					pball->end_pos.y=340.0;
				}
				else if(pball->now_pos.y<220.0)
				{
					pball->end_pos.y=220.0;
				}
				else
				{
					pball->end_pos.y=280.0;
				}
				popteam->player[popteam->controlplayer].control=0;
				KeeperChangestate(pmyteam,popteam,&pmyteam->goalkeeper,pball,&pmyteam->goalkeeper.Pounce);
				BallChangestate(popteam,pmyteam,pball,&pball->Long_shoot);
				PlayerChangestate(pmyteam,popteam,&popteam->player[popteam->controlplayer],pball,&popteam->player[popteam->controlplayer].ChasingBall);
			}
			PlayerChangestate(pmyteam,popteam,&popteam->player[2],pball,&popteam->player[2].Wait);
			popteam->passman=popteam->control;
			popteam->player[2].control=0;
			popteam->control=-1;
			popteam->controlplayer=3;
		}
	}
}

void DefendExecute(_team *pmyteam,_team *popteam,_ball *pball)
{
	if(popteam->pnowstate==&popteam->Attack)
	{
		if(distance(pmyteam->player[pmyteam->controlplayer].now_pos.x,pmyteam->player[pmyteam->controlplayer].now_pos.y,pball->now_pos.x,pball->now_pos.y)>distance(pmyteam->player[0].now_pos.x,pmyteam->player[0].now_pos.y,pball->now_pos.x,pball->now_pos.y))
		{
			pmyteam->lastcontrol=pmyteam->controlplayer;
			pmyteam->controlplayer=0;
			PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->lastcontrol],pball,&pmyteam->player[pmyteam->lastcontrol].Wait);
			PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->controlplayer],pball,&pmyteam->player[pmyteam->controlplayer].ChasingBall);
		}
		if(distance(pmyteam->player[pmyteam->controlplayer].now_pos.x,pmyteam->player[pmyteam->controlplayer].now_pos.y,pball->now_pos.x,pball->now_pos.y)>distance(pmyteam->player[1].now_pos.x,pmyteam->player[1].now_pos.y,pball->now_pos.x,pball->now_pos.y))
		{
			pmyteam->lastcontrol=pmyteam->controlplayer;
			pmyteam->controlplayer=1;
			PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->lastcontrol],pball,&pmyteam->player[pmyteam->lastcontrol].Wait);
			PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->controlplayer],pball,&pmyteam->player[pmyteam->controlplayer].ChasingBall);
		}
		if(distance(pmyteam->player[pmyteam->controlplayer].now_pos.x,pmyteam->player[pmyteam->controlplayer].now_pos.y,pball->now_pos.x,pball->now_pos.y)>distance(pmyteam->player[2].now_pos.x,pmyteam->player[2].now_pos.y,pball->now_pos.x,pball->now_pos.y))
		{
			pmyteam->lastcontrol=pmyteam->controlplayer;
			pmyteam->controlplayer=2;
			PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->lastcontrol],pball,&pmyteam->player[pmyteam->lastcontrol].Wait);
			PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->controlplayer],pball,&pmyteam->player[pmyteam->controlplayer].ChasingBall);
		}
		if(distance(pmyteam->player[pmyteam->controlplayer].now_pos.x,pmyteam->player[pmyteam->controlplayer].now_pos.y,pball->now_pos.x,pball->now_pos.y)>distance(pmyteam->player[3].now_pos.x,pmyteam->player[3].now_pos.y,pball->now_pos.x,pball->now_pos.y))
		{
			pmyteam->lastcontrol=pmyteam->controlplayer;
			pmyteam->controlplayer=3;
			PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->lastcontrol],pball,&pmyteam->player[pmyteam->lastcontrol].Wait);
			PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->controlplayer],pball,&pmyteam->player[pmyteam->controlplayer].ChasingBall);
		}
	}
	// if(popteam->pnowstate==&popteam->Attack)
	// {

	// }
}


//?????
void ChasingBallExecute(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball)
{
	Pos2d near_dir;
	if(pplayer->name==Player)
	{
		action(pmyteam,popteam,pball);
		if(distance(pmyteam->player[pmyteam->controlplayer].now_pos.x+6,pmyteam->player[pmyteam->controlplayer].now_pos.y+17,pball->now_pos.x+4,pball->now_pos.y+4)<20.0)
		{
		// 	setfillstyle(1,BLACK);
		// circle(10,10,10);
			if(popteam->control!=-1)
			{
		// 							setfillstyle(1,BLACK);
		// circle(10,10,10);
				PlayerChangestate(pmyteam,popteam,&popteam->player[popteam->control],pball,&popteam->player[popteam->control].Down);
				popteam->player[popteam->control].control=0;
				popteam->control=-1;
			}
				pplayer->control=1;
				pmyteam->control=pplayer->ID;
				TeamChangestate(pmyteam,popteam,pball,&pmyteam->Attack,&popteam->Defend);
				pball->control=pplayer->ID;
				BallChangestate(popteam,pmyteam,pball,&pball->Control);
				PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Dribble);
				// PlayerChangestate(pmyteam,popteam,&popteam->player[3],pball,&popteam->player[3].Wait);
		}
	}
	else
	{
		near_dir=get_dir(pplayer->now_pos,pball->now_pos);
				pplayer->velocity.x=5*near_dir.x;
				pplayer->velocity.y=5*near_dir.y;
				if(distance(popteam->player[popteam->controlplayer].now_pos.x+6,popteam->player[popteam->controlplayer].now_pos.y+17,pball->now_pos.x+4,pball->now_pos.y+4)<20.0)
				{
					if(pmyteam->control!=-1)
						{
							PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->control],pball,&pmyteam->player[pmyteam->control].Down);
							pmyteam->player[pmyteam->control].control=0;
							pmyteam->control=-1;
						}
					pplayer->control=1;
					popteam->control=pplayer->ID;
					TeamChangestate(pmyteam,popteam,pball,&pmyteam->Defend,&popteam->Attack);
					pball->control=pplayer->ID;
					BallChangestate(popteam,pmyteam,pball,&pball->Control);
					PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Dribble);
				}
	}
}

void DribbleEnter(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball)
{
	double x[4],y[4];
	if(pmyteam->position==Left)
	{
		x[0]=500.0;
		y[0]=290.0;
		x[1]=320.0;
		y[1]=290.0;
		x[2]=160.0;
		y[2]=160.0;
		x[3]=160.0;
		y[3]=400.0;
	}
	else
	{
		x[0]=140.0;
		y[0]=290.0;
		x[1]=320.0;
		y[1]=290.0;
		x[2]=480.0;
		y[2]=160.0;
		x[3]=480.0;
		y[3]=400.0;
	}
	if(pplayer->name==Computer)
	{
		popteam->controlplayer=pplayer->ID;
		switch(pplayer->ID)
		{
				case(0):arrive(pplayer,x[0],y[0]);
						
						break;
				case(1):arrive(pplayer,x[1],y[1]);
						
						break;
				case(2):arrive(pplayer,x[2],y[2]);
						
						break;
				case(3):arrive(pplayer,x[3],y[3]);
						
						break;
		}
	}
	
}

void DribbleExecute(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball)
{
	double x[4];
	if(pmyteam->position==Left)
	{
		x[0]=500.0;
		x[1]=320.0;
		x[2]=160.0;
		x[3]=160.0;
	}
	else
	{
		x[0]=140.0;
		x[1]=320.0;
		x[2]=480.0;
		x[3]=480.0;
	}
	if(pplayer->name==Player)
	{
	// 	setfillstyle(1,BLACK);
	// 	circle(10,10,10);
		action(pmyteam,popteam,pball);
	}
	else
	{
		if(nearDist(pmyteam,popteam,pball,&popteam->player[popteam->controlplayer])<45.0)
		{
			int receivingman=findPass(pmyteam,popteam,pball);
			pball->end_pos.x=popteam->player[receivingman].now_pos.x+6;
			pball->end_pos.y=popteam->player[receivingman].now_pos.y+17;
			BallChangestate(popteam,pmyteam,pball,&pball->Short_pass);
			PlayerChangestate(pmyteam,popteam,&popteam->player[popteam->controlplayer],pball,&popteam->player[popteam->controlplayer].Wait);
			popteam->passman=popteam->control;
			popteam->player[popteam->controlplayer].control=0;
			popteam->control=-1;
			popteam->controlplayer=receivingman;
			PlayerChangestate(pmyteam,popteam,&popteam->player[receivingman],pball,&popteam->player[receivingman].ChasingBall);
			// printf("%d\n",receivingman);
		}
		switch(pplayer->ID)
		{
				case(0):
						// if(nearDist(pmyteam,popteam,pball,pplayer)<60.0)
						// {
						// 	receivingman=findPass(pmyteam,popteam,pball);
						// 	pball->end_pos.x=popteam->player[receivingman].now_pos.x+6;
						// 	pball->end_pos.y=popteam->player[receivingman].now_pos.y+17;
						// 	BallChangestate(popteam,pmyteam,pball,&pball->Short_pass);
						// 	PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Wait);
						// 	popteam->passman=popteam->control;
						// 	pplayer->control=0;
						// 	popteam->control=-1;
						// 	PlayerChangestate(pmyteam,popteam,&popteam->player[receivingman],pball,&popteam->player[receivingman].ChasingBall);
						// 	printf("%d\n",receivingman);
						// }
						// if(nearDist(pmyteam,popteam,pball,&popteam->player[popteam->controlplayer])<60.0)
						// {
						// 	int receivingman=findPass(pmyteam,popteam,pball);
						// 	pball->end_pos.x=popteam->player[receivingman].now_pos.x+6;
						// 	pball->end_pos.y=popteam->player[receivingman].now_pos.y+17;
						// 	BallChangestate(popteam,pmyteam,pball,&pball->Short_pass);
						// 	PlayerChangestate(pmyteam,popteam,&popteam->player[popteam->controlplayer],pball,&popteam->player[popteam->controlplayer].Wait);
						// 	popteam->passman=popteam->control;
						// 	popteam->player[popteam->controlplayer].control=0;
						// 	popteam->control=-1;
						// 	popteam->controlplayer=receivingman;
						// 	PlayerChangestate(pmyteam,popteam,&popteam->player[receivingman],pball,&popteam->player[receivingman].ChasingBall);
						// 	// printf("%d\n",receivingman);
						// }
						if(distance(pplayer->now_pos.x,pplayer->now_pos.y,x[0],290.0)<5.0)
							PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
						break;
				case(1):
				// if(nearDist(pmyteam,popteam,pball,pplayer)<60.0)
				// 		{
				// 			receivingman=findPass(pmyteam,popteam,pball);
				// 			pball->end_pos.x=popteam->player[receivingman].now_pos.x+6;
				// 			pball->end_pos.y=popteam->player[receivingman].now_pos.y+17;
				// 			BallChangestate(popteam,pmyteam,pball,&pball->Short_pass);
				// 			PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Wait);
				// 			popteam->passman=popteam->control;
				// 			pplayer->control=0;
				// 			popteam->control=-1;
				// 			PlayerChangestate(pmyteam,popteam,&popteam->player[receivingman],pball,&popteam->player[receivingman].ChasingBall);
				// 			printf("%d\n",receivingman);
				// 		}
						if(distance(pplayer->now_pos.x,pplayer->now_pos.y,x[1],290.0)<5.0)
							PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
						break;
				case(2):
				// if(nearDist(pmyteam,popteam,pball,pplayer)<60.0)
				// 		{
				// 			receivingman=findPass(pmyteam,popteam,pball);
				// 			pball->end_pos.x=popteam->player[receivingman].now_pos.x+6;
				// 			pball->end_pos.y=popteam->player[receivingman].now_pos.y+17;
				// 			BallChangestate(popteam,pmyteam,pball,&pball->Short_pass);
				// 			PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Wait);
				// 			popteam->passman=popteam->control;
				// 			pplayer->control=0;
				// 			popteam->control=-1;
				// 			PlayerChangestate(pmyteam,popteam,&popteam->player[receivingman],pball,&popteam->player[receivingman].ChasingBall);
				// 			printf("%d\n",receivingman);
				// 		}
						if(distance(pplayer->now_pos.x,pplayer->now_pos.y,x[2],160.0)<5.0)
							PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
						break;	
				case(3):
				// if(nearDist(pmyteam,popteam,pball,pplayer)<60.0)
				// 		{
				// 			receivingman=findPass(pmyteam,popteam,pball);
				// 			pball->end_pos.x=popteam->player[receivingman].now_pos.x+6;
				// 			pball->end_pos.y=popteam->player[receivingman].now_pos.y+17;
				// 			BallChangestate(popteam,pmyteam,pball,&pball->Short_pass);
				// 			PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Wait);
				// 			popteam->passman=popteam->control;
				// 			pplayer->control=0;
				// 			popteam->control=-1;
				// 			PlayerChangestate(pmyteam,popteam,&popteam->player[receivingman],pball,&popteam->player[receivingman].ChasingBall);
				// 			printf("%d\n",receivingman);
				// 		}
						if(distance(pplayer->now_pos.x,pplayer->now_pos.y,x[3],400.0)<5.0)
							PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
						break;
		}
		// if(pball->timecount%30==0)//?????????sin/cos,??????
		// 	pplayer->velocity.y*=(-1);
	}
}

void WaitEnter(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball)
{
	if(pmyteam->position==Left)
	{
		if(pplayer->name==Player)
		{
			// 	setfillstyle(1,BLACK);
			// circle(10,10,10);
			if(pmyteam->pnowstate==&pmyteam->Attack)
			{
				switch(pplayer->ID)
				{
					case(0):arrive(pplayer,180.0,290.0);
							break;
					case(1):arrive(pplayer,320.0,400.0);
							break;
					case(2):arrive(pplayer,500.0,160.0);
							break;
					case(3):arrive(pplayer,400.0,280.0);
							break;
				}
			}
			else if(pmyteam->pnowstate==&pmyteam->Defend)
			{
				switch(pplayer->ID)
				{
					case(0):arrive(pplayer,100.0,160.0);
							break;
					case(1):arrive(pplayer,100.0,400.0);
							break;
					case(2):arrive(pplayer,200.0,290.0);
							break;
					case(3):arrive(pplayer,400.0,290.0);
							break;
				}
			}
		}
		else
		{
			if(popteam->pnowstate==&popteam->Attack)
			{
				switch(pplayer->ID)
				{
					case(0):arrive(pplayer,500.0,290.0);
							break;
					case(1):arrive(pplayer,320.0,290.0);
							break;
					case(2):arrive(pplayer,160.0,160.0);
							break;
					case(3):arrive(pplayer,160.0,400.0);
							break;
				}
			}
			else if(popteam->pnowstate==&popteam->Defend)
			{
				switch(pplayer->ID)
				{
					case(0):arrive(pplayer,540.0,160.0);
							break;
					case(1):arrive(pplayer,540.0,400.0);
							break;
					case(2):arrive(pplayer,440.0,280.0);
							break;
				}
			}
		}
	}
	else
	{
		if(pplayer->name==Player)
		{
			// 	setfillstyle(1,BLACK);
			// circle(10,10,10);
			if(pmyteam->pnowstate==&pmyteam->Attack)
			{
				switch(pplayer->ID)
				{
					case(0):arrive(pplayer,460.0,290.0);
							break;
					case(1):arrive(pplayer,320.0,400.0);
							break;
					case(2):arrive(pplayer,140.0,160.0);
							break;
					case(3):arrive(pplayer,240.0,280.0);
							break;
				}
			}
			else if(pmyteam->pnowstate==&pmyteam->Defend)
			{
				switch(pplayer->ID)
				{
					case(0):arrive(pplayer,540.0,160.0);
							break;
					case(1):arrive(pplayer,540.0,400.0);
							break;
					case(2):arrive(pplayer,440.0,290.0);
							break;
					case(3):arrive(pplayer,240.0,290.0);
							break;
				}
			}
		}
		else
		{
			if(popteam->pnowstate==&popteam->Attack)
			{
				switch(pplayer->ID)
				{
					case(0):arrive(pplayer,140.0,290.0);
							break;
					case(1):arrive(pplayer,320.0,290.0);
							break;
					case(2):arrive(pplayer,480.0,160.0);
							break;
					case(3):arrive(pplayer,480.0,400.0);
							break;
				}
			}
			else if(popteam->pnowstate==&popteam->Defend)
			{
				switch(pplayer->ID)
				{
					case(0):arrive(pplayer,100.0,160.0);
							break;
					case(1):arrive(pplayer,100.0,400.0);
							break;
					case(2):arrive(pplayer,200.0,280.0);
							break;
				}
			}
		}
	}
}

void WaitExecute(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball)
{
	Pos2d near_dir;
	if(pmyteam->position==Left)
	{
		if(pplayer->name==Player)
		{
			if(pmyteam->pnowstate==&pmyteam->Attack)
			{
				switch(pplayer->ID)
				{
					case(0):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,180.0,290.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(1):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,320.0,400.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(2):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,500.0,160.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(3):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,400.0,280.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
				}
			}
			else if(pmyteam->pnowstate==&pmyteam->Defend)
			{
				switch(pplayer->ID)
				{
					case(0):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,100.0,160.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(1):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,100.0,400.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(2):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,200.0,290.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(3):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,400.0,290.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
				}
			}
		}
		else
		{
			if(popteam->pnowstate==&popteam->Attack)
			{
				switch(pplayer->ID)
				{
					case(0):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,500.0,290.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(1):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,320.0,290.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(2):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,160.0,160.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(3):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,160.0,400.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
				}
			}
			else if(popteam->pnowstate==&popteam->Defend)
			{
				switch(pplayer->ID)
				{
					case(0):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,540.0,160.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(1):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,540.0,400.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(2):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,440.0,280.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(3):PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
				}
			}
			else
			{
				if(pplayer->ID==3)
				{
					near_dir=get_dir(pplayer->now_pos,pball->now_pos);
					pplayer->velocity.x=3*near_dir.x;
					pplayer->velocity.y=3*near_dir.y;
					if(distance(popteam->player[popteam->controlplayer].now_pos.x+6,popteam->player[popteam->controlplayer].now_pos.y+17,pball->now_pos.x+4,pball->now_pos.y+4)<20.0)
					{
						if(pmyteam->control!=-1)
							{
								PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->control],pball,&pmyteam->player[pmyteam->control].Down);
								pmyteam->player[pmyteam->control].control=0;
								pmyteam->control=-1;
							}
						pplayer->control=1;
						popteam->control=pplayer->ID;
						TeamChangestate(pmyteam,popteam,pball,&pmyteam->Defend,&popteam->Attack);
						pball->control=pplayer->ID;
						BallChangestate(popteam,pmyteam,pball,&pball->Control);
						PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Dribble);
					}
				}
			}
		}
	}
	else
	{
		if(pplayer->name==Player)
		{
			if(pmyteam->pnowstate==&pmyteam->Attack)
			{
				switch(pplayer->ID)
				{
					case(0):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,460.0,290.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(1):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,320.0,400.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(2):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,140.0,160.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(3):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,240.0,280.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
				}
			}
			else if(pmyteam->pnowstate==&pmyteam->Defend)
			{
				switch(pplayer->ID)
				{
					case(0):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,540.0,160.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(1):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,540.0,400.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(2):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,440.0,290.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(3):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,240.0,290.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
				}
			}
		}
		else
		{
			if(popteam->pnowstate==&popteam->Attack)
			{
				switch(pplayer->ID)
				{
					case(0):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,140.0,290.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(1):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,320.0,290.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(2):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,480.0,160.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(3):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,480.0,400.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
				}
			}
			else if(popteam->pnowstate==&popteam->Defend)
			{
				switch(pplayer->ID)
				{
					case(0):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,100.0,160.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(1):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,100.0,400.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(2):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,200.0,280.0)<5.0)
								PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
					case(3):PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
							break;
				}
			}
			else
			{
				if(pplayer->ID==3)
				{
					near_dir=get_dir(pplayer->now_pos,pball->now_pos);
					pplayer->velocity.x=3*near_dir.x;
					pplayer->velocity.y=3*near_dir.y;
					if(distance(popteam->player[popteam->controlplayer].now_pos.x+6,popteam->player[popteam->controlplayer].now_pos.y+17,pball->now_pos.x+4,pball->now_pos.y+4)<20.0)
					{
						if(pmyteam->control!=-1)
							{
								PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->control],pball,&pmyteam->player[pmyteam->control].Down);
								pmyteam->player[pmyteam->control].control=0;
								pmyteam->control=-1;
							}
						pplayer->control=1;
						popteam->control=pplayer->ID;
						TeamChangestate(pmyteam,popteam,pball,&pmyteam->Defend,&popteam->Attack);
						pball->control=pplayer->ID;
						BallChangestate(popteam,pmyteam,pball,&pball->Control);
						PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Dribble);
					}
				}
			}
		}
	}
}


void ActioningEnter(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball)
{
	pplayer->velocity.x=0;
	pplayer->velocity.y=0;
}

void ActioningExecute(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball)
{
	Pos2d far_dir,near_dir;
	double dx,dy;
	double x;
	if(pplayer->name==Player)
	{
		if(pmyteam->pnowstate==&pmyteam->Attack)
		{
			switch(pplayer->ID)
			{
				case(0):dy=abs(pplayer->now_pos.y-pball->now_pos.y);
						if(dy>=20.0)
						{
							pplayer->velocity.y=4.0*(pball->now_pos.y-pplayer->now_pos.y)/dy;
						}
						break;
				case(1):
						if((pball->now_pos.x-pplayer->now_pos.x-pplayer->velocity.x)>70)
							pplayer->velocity.x=4.0;
						else if((pball->now_pos.x-pplayer->now_pos.x-pplayer->velocity.x)<-70)
							pplayer->velocity.x=-4.0;
						else
							pplayer->velocity.x=0;
						// if(distance(pplayer->now_pos.x,pplayer->now_pos.y,pball->now_pos.x,pball->now_pos.y)<=50.0)//??λ??????????
						// {
						// 	far_dir=get_dir(pplayer->now_pos,popteam->player[3].now_pos);
						// 	pplayer->velocity.x=-4.0*far_dir.x;
						// 	pplayer->velocity.y=-4.0*far_dir.y;
						// }
						// else if(distance(pplayer->now_pos.x,pplayer->now_pos.y,pball->now_pos.x,pball->now_pos.y)>=150.0)//??λ???????????
						// {
						// 	near_dir=get_dir(pplayer->now_pos,popteam->player[3].now_pos);
						// 	pplayer->velocity.x=4.0*near_dir.x;
						// 	pplayer->velocity.y=4.0*near_dir.y;
						// }
						break;
				case(2):if((pball->now_pos.x-pplayer->now_pos.x-pplayer->velocity.x)>70)
							pplayer->velocity.x=4.0;
						else if((pball->now_pos.x-pplayer->now_pos.x-pplayer->velocity.x)<-70)
							pplayer->velocity.x=-4.0;
						else
							pplayer->velocity.x=0;
				case(3):if((pball->now_pos.x-pplayer->now_pos.x-pplayer->velocity.x)>70)
							pplayer->velocity.x=4.0;
						else if((pball->now_pos.x-pplayer->now_pos.x-pplayer->velocity.x)<-70)
							pplayer->velocity.x=-4.0;
						else
							pplayer->velocity.x=0;
						break;
			}
		}
		// else if(pmyteam->pnowstate==&pmyteam->Defend)
		// {
		// 	switch(pplayer->ID)
		// 	{
		// 		case(0):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,pball->now_pos.x,pball->now_pos.y)<20.0)
		// 					PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
		// 				break;
		// 		case(1):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,pball->now_pos.x,pball->now_pos.y)<20.0)
		// 					PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
		// 				break;
		// 		case(2):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,pball->now_pos.x,pball->now_pos.y)<20.0)
		// 					PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
		// 				break;
		// 		case(3):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,pball->now_pos.x,pball->now_pos.y)<20.0)
		// 					PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
		// 				break;
		// 	}
		// }
	}
	else
	{
		// if(popteam->pnowstate==&popteam->Attack)
		// {
		// 	switch(pplayer->ID)
		// 	{
		// 		case(0):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,500.0,290.0)<5.0)
		// 					PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
		// 				break;
		// 		case(1):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,320.0,290.0)<5.0)
		// 					PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
		// 				break;
		// 		case(2):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,160.0,160.0)<5.0)
		// 					PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
		// 				break;
		// 		case(3):if(distance(pplayer->now_pos.x,pplayer->now_pos.y,160.0,400.0)<5.0)
		// 					PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Actioning);
		// 				break;
		// 	}
		// }
		if(popteam->pnowstate==&popteam->Defend)
		{
			switch(pplayer->ID)
			{
				case(0):if(pmyteam->position==Left)
							x=540.0;
						else
							x=100.0;
						if(distance(x,160.0,pball->now_pos.x,pball->now_pos.y)<100.0)
						{
							near_dir=get_dir(pplayer->now_pos,pball->now_pos);
							pplayer->velocity.x=3*near_dir.x;
							pplayer->velocity.y=3*near_dir.y;
						}
						else if(distance(pplayer->now_pos.x,pplayer->now_pos.y,x,160.0)>5.0)
							PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Wait);
						if(distance(pplayer->now_pos.x,pplayer->now_pos.y,pball->now_pos.x,pball->now_pos.y)<20.0)
						{
						
							if(pmyteam->control!=-1)
							{
		// 													setfillstyle(1,BLACK);
		// circle(10,10,10);
								PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->control],pball,&pmyteam->player[pmyteam->control].Down);
								pmyteam->player[pmyteam->control].control=0;
								pmyteam->control=-1;
							}
							pplayer->control=1;
							popteam->control=pplayer->ID;
							pball->control=pplayer->ID;
							popteam->controlplayer=pplayer->ID;
							PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Dribble);
							TeamChangestate(pmyteam,popteam,pball,&pmyteam->Defend,&popteam->Attack);
							BallChangestate(popteam,pmyteam,pball,&pball->Control);
							
		// 						setfillstyle(1,BLACK);
		// circle(10,10,10);
						}
						break;
				case(1):if(pmyteam->position==Left)
							x=540.0;
						else
							x=100.0;
						if(distance(x,400.0,pball->now_pos.x,pball->now_pos.y)<100.0)
						{
							near_dir=get_dir(pplayer->now_pos,pball->now_pos);
							pplayer->velocity.x=3*near_dir.x;
							pplayer->velocity.y=3*near_dir.y;
						}
						else if(distance(pplayer->now_pos.x,pplayer->now_pos.y,x,400.0)>5.0)
							PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Wait);
						if(distance(pplayer->now_pos.x,pplayer->now_pos.y,pball->now_pos.x,pball->now_pos.y)<20.0)
						{
						
							if(pmyteam->control!=-1)
							{

								PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->control],pball,&pmyteam->player[pmyteam->control].Down);
								pmyteam->player[pmyteam->control].control=0;
								pmyteam->control=-1;
							}
							pplayer->control=1;
							popteam->control=pplayer->ID;
							popteam->controlplayer=pplayer->ID;
							pball->control=pplayer->ID;
							PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Dribble);
							TeamChangestate(pmyteam,popteam,pball,&pmyteam->Defend,&popteam->Attack);
							BallChangestate(popteam,pmyteam,pball,&pball->Control);
							
		// 						setfillstyle(1,BLACK);
		// circle(10,10,10);
						}
						break;
				case(2):if(pmyteam->position==Left)
							x=440.0;
						else
							x=200.0;
						if(distance(x,280.0,pball->now_pos.x,pball->now_pos.y)<100.0)
						{
							near_dir=get_dir(pplayer->now_pos,pball->now_pos);
							pplayer->velocity.x=3*near_dir.x;
							pplayer->velocity.y=3*near_dir.y;
						}
						else if(distance(pplayer->now_pos.x,pplayer->now_pos.y,x,280.0)>5.0)
							PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Wait);
						if(distance(pplayer->now_pos.x,pplayer->now_pos.y,pball->now_pos.x,pball->now_pos.y)<20.0)
						{
						
							if(pmyteam->control!=-1)
							{

								PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->control],pball,&pmyteam->player[pmyteam->control].Down);
								pmyteam->player[pmyteam->control].control=0;
								pmyteam->control=-1;
							}
							pplayer->control=1;
							popteam->control=pplayer->ID;
							pball->control=pplayer->ID;
							popteam->controlplayer=pplayer->ID;
							PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Dribble);
							TeamChangestate(pmyteam,popteam,pball,&pmyteam->Defend,&popteam->Attack);
							BallChangestate(popteam,pmyteam,pball,&pball->Control);
							
		// 						setfillstyle(1,BLACK);
		// circle(10,10,10);
						}
						break;
				case(3):near_dir=get_dir(pplayer->now_pos,pball->now_pos);
						pplayer->velocity.x=3*near_dir.x;
						pplayer->velocity.y=3*near_dir.y;
						if(distance(pplayer->now_pos.x,pplayer->now_pos.y,pball->now_pos.x,pball->now_pos.y)<20.0)
						{
						
							if(pmyteam->control!=-1)
							{

								PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->control],pball,&pmyteam->player[pmyteam->control].Down);
								pmyteam->player[pmyteam->control].control=0;
								pmyteam->control=-1;
							}
							pplayer->control=1;
							popteam->control=pplayer->ID;
							pball->control=pplayer->ID;
							popteam->controlplayer=pplayer->ID;
							PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Dribble);
							TeamChangestate(pmyteam,popteam,pball,&pmyteam->Defend,&popteam->Attack);
							BallChangestate(popteam,pmyteam,pball,&pball->Control);
							
		// 						setfillstyle(1,BLACK);
		// circle(10,10,10);
						}
			}
		}
	}
}

void DownEnter(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball)
{
	pplayer->velocity.x=0;
	pplayer->velocity.y=0;
	pball->downtime=0;
}

void DownExecute(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball)
{
	pball->downtime++;
	if(pball->downtime>10)
	{
		PlayerChangestate(pmyteam,popteam,pplayer,pball,&pplayer->Wait);
	}
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
// //?????????
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
//?????????
void TendGoalExecute(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball)
{
	// double dy;
	if(pgoalkeeper->now_pos.y>=276.0)
		pgoalkeeper->velocity.y*=(-1.0);
	if(pgoalkeeper->now_pos.y<=250.0)
		pgoalkeeper->velocity.y*=(-1.0);
	// if(pgoalkeeper->name==Player)
	// {
	// 	if(pball->now_pos.x<190&&pball->now_pos.y>220&&pball->now_pos.y<328&&pball->timecount%5==0)
	// 	{
	// 		dy=abs(pgoalkeeper->now_pos.y-pball->now_pos.y);
	// 		pgoalkeeper->velocity.y=2*(pball->now_pos.y-pgoalkeeper->now_pos.y)/dy;
	// 	}
	// }
	// else
	// {
	// 	if(pball->now_pos.x>450&&pball->now_pos.y>220&&pball->now_pos.y<328&&pball->timecount%5==0)
	// 	{
	// 		dy=abs(pgoalkeeper->now_pos.y-pball->now_pos.y);
	// 		pgoalkeeper->velocity.y=2*(pball->now_pos.y-pgoalkeeper->now_pos.y)/dy;
	// 	}
	// }


	// case(0):dy=abs(pplayer->now_pos.y-pball->now_pos.y);
	// 					if(dy>=20.0)
	// 					{
	// 						pplayer->velocity.y=4.0*(pball->now_pos.y-pplayer->now_pos.y)/dy;
	// 					}
	// if(pgoalkeeper->now_pos.y>=276.0)
	// 	pgoalkeeper->velocity.y*=(-1.0);
	// if(pgoalkeeper->now_pos.y<=250.0)
	// 	pgoalkeeper->velocity.y*=(-1.0);
}
void PounceEnter(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball)
{
	if(pgoalkeeper->now_pos.y>263.0)
                {
                            pgoalkeeper->velocity.y=-1.0;
                }
    else
                {
                            pgoalkeeper->velocity.y=1.0;  
                }
}
void PounceExecute(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball)
{
	double x;
	int y;
	if(pgoalkeeper->name==Computer)
	{
		// if(pmyteam->position==Left)
		// {
		// 	x=610.0;
		// 	y=1;
		// }
			
		// else
		// {
		// 	x=20.0;
		// 	y=-1;
		// }
		// if((pball->now_pos.x-x)*y>1e-5)
		// 	  {
		// 		  setfillstyle(1,BLACK);
		// 			circle(10,10,10);
		// 		  pball->score_my++;
		// 		  init_team(pmyteam,pball);
		// 		  init_team(popteam,pball);
		// 		  setfillstyle(1,GREEN);	
		// 		  bar((int)(pball->now_pos.x),(int)(pball->now_pos.y),(int)(pball->now_pos.x)+12,(int)(pball->now_pos.y)+12);
		// 		  BallChangestate(popteam,pmyteam,pball,&pball->Control);
		// 		  popteam->player[3].control=1;
		// 		  PlayerChangestate(pmyteam,popteam,&popteam->player[3],pball,&popteam->player[3].Dribble);
		// 		popteam->control=3;
		// 		popteam->controlplayer=3;
		// 		TeamChangestate(pmyteam,popteam,pball,&pmyteam->Defend,&popteam->Attack);
		// 		pball->control=3;
		// 	  }
              if(distance(pball->now_pos.x+6,pball->now_pos.y+6,pgoalkeeper->now_pos.x+6,pgoalkeeper->now_pos.y+17)<30.0)
                {
					TeamChangestate(pmyteam,popteam,pball,&pmyteam->Defend,&popteam->Attack);
					 KeeperChangestate(pmyteam,popteam,pgoalkeeper,pball,&pgoalkeeper->ControlBall);
					 pgoalkeeper->control=1;
					 pball->control=4;
					 BallChangestate(popteam,pmyteam,pball,&pball->Control);
					 pmyteam->control=-1;
					 popteam->control=4;
					 pgoalkeeper->velocity.y=0;
					//  pgoalkeeper->now_pos.x=600.0;
					//  pgoalkeeper->now_pos.y=
                }
				if(pgoalkeeper->now_pos.y<180||pgoalkeeper->now_pos.y>346)
				{
					setfillstyle(1,GREEN);	
				  	bar((int)(pgoalkeeper->now_pos.x),(int)(pgoalkeeper->now_pos.y),(int)(pgoalkeeper->now_pos.x)+12,(int)(pgoalkeeper->now_pos.y)+34);
					pgoalkeeper->velocity.y=0;
					pgoalkeeper->now_pos.y=263;
					KeeperChangestate(pmyteam,popteam,pgoalkeeper,pball,&pgoalkeeper->TendGoal);
				}
	}
	else
	{
		// if(pmyteam->position==Left)
		// {
		// 	x=20.0;
		// 	y=1;
		// }
			
		// else
		// {
		// 	x=610.0;
		// 	y=-1;
		// }
		// if((pball->now_pos.x-x)*y<1e-5)
		// 	  {
		// 		  pball->score_op++;
		// 		  init_team(pmyteam,pball);
		// 		  init_team(popteam,pball);
		// 		  setfillstyle(1,GREEN);	
		// 		  bar((int)(pball->now_pos.x),(int)(pball->now_pos.y),(int)(pball->now_pos.x)+12,(int)(pball->now_pos.y)+12);
		// 		  BallChangestate(popteam,pmyteam,pball,&pball->Control);
		// 		  pmyteam->player[3].control=1;
		// 		  PlayerChangestate(pmyteam,popteam,&pmyteam->player[3],pball,&pmyteam->player[3].Dribble);
		// 		pmyteam->control=3;
		// 		pmyteam->controlplayer=3;
		// 		TeamChangestate(pmyteam,popteam,pball,&pmyteam->Attack,&popteam->Defend);
		// 		pball->control=3;
		// 	  }
              if(distance(pball->now_pos.x+6,pball->now_pos.y+6,pgoalkeeper->now_pos.x+6,pgoalkeeper->now_pos.y+17)<30.0)
                {
					TeamChangestate(pmyteam,popteam,pball,&pmyteam->Attack,&popteam->Defend);
					 KeeperChangestate(pmyteam,popteam,pgoalkeeper,pball,&pgoalkeeper->ControlBall);
					 pgoalkeeper->control=1;
					 pball->control=4;
					 BallChangestate(popteam,pmyteam,pball,&pball->Control);
					 pmyteam->control=4;
					 popteam->control=-1;
					 pgoalkeeper->velocity.y=0;
					//  pgoalkeeper->now_pos.x=600.0;
					//  pgoalkeeper->now_pos.y=
                }
				if(pgoalkeeper->now_pos.y<180||pgoalkeeper->now_pos.y>346)
				{
					setfillstyle(1,GREEN);	
				  	bar((int)(pgoalkeeper->now_pos.x),(int)(pgoalkeeper->now_pos.y),(int)(pgoalkeeper->now_pos.x)+12,(int)(pgoalkeeper->now_pos.y)+34);
					pgoalkeeper->velocity.y=2;
					pgoalkeeper->now_pos.y=263;
					KeeperChangestate(pmyteam,popteam,pgoalkeeper,pball,&pgoalkeeper->TendGoal);
				}
	}
            
}

void ControlBallExecute(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball)
{
	if(popteam->pnowstate==&popteam->Attack&&pball->timecount%15==0)
	{
		pball->end_pos.x=popteam->player[0].now_pos.x+6;
		pball->end_pos.y=popteam->player[0].now_pos.y+17;
		BallChangestate(popteam,pmyteam,pball,&pball->Short_pass);
		popteam->control=-1;
		popteam->controlplayer=0;
		PlayerChangestate(pmyteam,popteam,&popteam->player[0],pball,&popteam->player[0].ChasingBall);
		setfillstyle(1,GREEN);
		bar((int)(pgoalkeeper->now_pos.x),(int)(pgoalkeeper->now_pos.y),(int)(pgoalkeeper->now_pos.x)+12,(int)(pgoalkeeper->now_pos.y)+34);
		pgoalkeeper->control=0;
		pgoalkeeper->velocity.y=1.2;
		pgoalkeeper->now_pos.y=263.0;
		KeeperChangestate(pmyteam,popteam,pgoalkeeper,pball,&pgoalkeeper->TendGoal);
	}
	else if(popteam->pnowstate==&popteam->Defend&&pball->timecount%15==0)
	{
		pball->end_pos.x=pmyteam->player[0].now_pos.x+6;
		pball->end_pos.y=pmyteam->player[0].now_pos.y+17;
		BallChangestate(popteam,pmyteam,pball,&pball->Short_pass);
		PlayerChangestate(pmyteam,popteam,&pmyteam->player[pmyteam->controlplayer],pball,&pmyteam->player[pmyteam->controlplayer].Wait);
		pmyteam->control=-1;
		pmyteam->controlplayer=0;
		PlayerChangestate(pmyteam,popteam,&pmyteam->player[0],pball,&pmyteam->player[0].ChasingBall);
		setfillstyle(1,GREEN);
		bar((int)(pgoalkeeper->now_pos.x),(int)(pgoalkeeper->now_pos.y),(int)(pgoalkeeper->now_pos.x)+12,(int)(pgoalkeeper->now_pos.y)+34);
		pgoalkeeper->control=0;
		pgoalkeeper->velocity.y=1.2;
		pgoalkeeper->now_pos.y=263.0;
		KeeperChangestate(pmyteam,popteam,pgoalkeeper,pball,&pgoalkeeper->TendGoal);
	}
	// init_goalkeeper
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

// void Long_passExecute(_team *pmyteam,_team *popteam,_ball *pball)//pmyteam????????
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

//??????

void Short_passEnter(_team *popteam,_team *pmyteam,_ball *pball)//popteam????????
{
	Pos2d pass_dir;
	pball->control=-1;
	pass_dir=get_dir(pball->now_pos,pball->end_pos);
    pball->velocity.x=16.0*pass_dir.x;
    pball->velocity.y=16.0*pass_dir.y;
}

void Short_shootEnter(_team *popteam,_team *pmyteam,_ball *pball)
{	
	Pos2d gate,shoot_dir;
	// setfillstyle(1,BLACK);
	// 	circle(10,10,10);
	pball->control=-1;
	if(popteam->control!=-1)
		popteam->control=-1;
	else
		pmyteam->control=-1;
	if(popteam->pnowstate==&popteam->Attack)
	{
		if(pmyteam->position==Left)
			gate.x=40.0;
		else
			gate.x=600.0;
		if(pmyteam->goalkeeper.velocity.y>1e-5)
    		gate.y=340.0-12.0;
    	else
			gate.y=220.0;
	}
	else
	{
		if(pmyteam->position==Left)
			gate.x=600.0;
		else
			gate.x=40.0;
		if(popteam->goalkeeper.velocity.y>1e-5)
    		gate.y=340.0-12.0;
    	else
			gate.y=220.0;
	}
	shoot_dir=get_dir(pball->now_pos,gate);
    pball->velocity.x=18.0*shoot_dir.x;
    pball->velocity.y=18.0*shoot_dir.y;
	// setfillstyle(1,BLACK);
	// 	circle(30,30,10);
}

void Long_shootExecute(_team *popteam,_team *pmyteam,_ball *pball)
{
	// Pos2d pass_dir;
	// printf("%d\n",pball->control);
	double finalX,finalY,x,y;
	double a=0;
	finalX=pball->end_pos.x-pball->start_pos.x;
	finalY=pball->end_pos.y-pball->start_pos.y;
	x=pball->now_pos.x-pball->start_pos.x;
	y=pball->now_pos.y-pball->start_pos.y;
	// printf("%d",finalX);
	// if(pmyteam->position==Left)
	// {
		if(popteam->pnowstate==&popteam->Attack)
		{
			if(finalY>1e-5)
			{
				pball->velocity.y=24.0;
			}
			else
			{
				pball->velocity.y=-16.0;
			}
			if(abs(finalY)>1e-5)
			{
				a=2*finalX/finalY/finalY;
			}
			pball->velocity.x=30*a*abs(y)/10.0;
		}
		else
		{
			if(finalX>1e-5)
			{
				pball->velocity.x=15.0;
			}
			else
			{
				pball->velocity.x=-15.0;
			}
			// pball->velocity.y=4.0;
			if(abs(finalX)>1e-5)
			{
				a=2*finalY/finalX/finalX;
			}
			pball->velocity.y=800*a*abs(x)/10.0;
		}
	// }
	// else
	// {
	// 	if(pmyteam->pnowstate==&pmyteam->Attack)
	// 	{
	// 		if(finalY>1e-5)
	// 		{
	// 			pball->velocity.y=24.0;
	// 		}
	// 		else
	// 		{
	// 			pball->velocity.y=-16.0;
	// 		}
	// 		if(abs(finalY)>1e-5)
	// 		{
	// 			a=2*finalX/finalY/finalY;
	// 		}
	// 		pball->velocity.x=30*a*abs(y)/10.0;
	// 	}
	// 	else
	// 	{
	// 		if(finalX>1e-5)
	// 		{
	// 			pball->velocity.x=15.0;
	// 		}
	// 		else
	// 		{
	// 			pball->velocity.x=-15.0;
	// 		}
	// 		// pball->velocity.y=4.0;
	// 		if(abs(finalX)>1e-5)
	// 		{
	// 			a=2*finalY/finalX/finalX;
	// 		}
	// 		pball->velocity.y=800*a*abs(x)/10.0;
	// 	}
	// }
}

void Long_passExecute(_team *popteam,_team *pmyteam,_ball *pball)
{
	// Pos2d pass_dir;
	// printf("%d\n",pball->control);
	double finalX,finalY,x,y;
	double a=0;
	finalX=pball->end_pos.x-pball->start_pos.x;
	finalY=pball->end_pos.y-pball->start_pos.y;
	x=pball->now_pos.x-pball->start_pos.x;
	y=pball->now_pos.y-pball->start_pos.y;
	// printf("%d",finalX);
	if(abs(finalX)>=abs(finalY))
	{
		if(finalX>1e-5)
		{
			pball->velocity.x=15.0;
		}
		else
		{
			pball->velocity.x=-15.0;
		}
		// pball->velocity.y=4.0;
		if(abs(finalX)>1e-5)
		{
			a=2*finalY/finalX/finalX;
		// printf("%d",a);

		}
		// printf("%d",a);
		pball->velocity.y=40*a*abs(x)/10.0;
		// printf("%d",pball->velocity.x);
	}
	else
	{
		if(finalY>1e-5)
		{
			pball->velocity.y=15.0;
		}
		else
		{
			pball->velocity.y=-15.0;
		}
		// pball->velocity.y=4.0;
		if(abs(finalY)>1e-5)
		{
			a=2*finalX/finalY/finalY;
		// printf("%d",a);

		}
		// printf("%d",a);
		pball->velocity.x=40*a*abs(y)/10.0;
		// printf("%d",pball->velocity.x);
	}
}

void ControlExecute(_team *popteam,_team *pmyteam,_ball *pball)
{
	pball->velocity.x=0.0;
	pball->velocity.y=0.0;
	if(popteam->pnowstate==&popteam->Attack)
	{
		if(popteam->control==4)
		{
			if(popteam->goalkeeper.dir==Left)
			{
				pball->now_pos.x=popteam->goalkeeper.now_pos.x-16.0;
				pball->now_pos.y=popteam->goalkeeper.now_pos.y+18.0;
			}
			else
			{
				pball->now_pos.x=popteam->goalkeeper.now_pos.x+12.0;
				pball->now_pos.y=popteam->goalkeeper.now_pos.y+18.0;
			}
		}
		else
		{
		// 	setfillstyle(1,BLACK);
		// circle(10,10,10);
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
	else
	{
		// setfillstyle(1,BLACK);
		// circle(10,10,10);
		if(pmyteam->control==4)
		{
			if(pmyteam->goalkeeper.dir==Left)
			{
				pball->now_pos.x=pmyteam->goalkeeper.now_pos.x-16.0;
				pball->now_pos.y=pmyteam->goalkeeper.now_pos.y+18.0;
			}
			else
			{
				pball->now_pos.x=pmyteam->goalkeeper.now_pos.x+12.0;
				pball->now_pos.y=pmyteam->goalkeeper.now_pos.y+18.0;
			}
		}
		else
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
	}
}

void init_team(_team *team,_ball *pball)
{
	int i=0;
	team->pnowstate=NULL;
	team->Attack.Enter=AttackEnter;
	team->Attack.Execute=AttackExecute;
	team->Defend.Enter=NULL;
	team->Defend.Execute=DefendExecute;
	team->control=-1;
	team->controlplayer=3;
	team->passman=-1;
	setfillstyle(1,GREEN);
	for(;i<4;i++)
	{
		if(pball->timecount>1e-5)
			bar((int)(team->player[i].old_pos.x-5),(int)(team->player[i].old_pos.y-5),(int)(team->player[i].old_pos.x)+12+5,(int)(team->player[i].old_pos.y)+34+5);
		init_player(&team->player[i],team->position,i,team->name);
	}
	init_goalkeeper(&team->goalkeeper,team->position,team->name); 
	if(pball->timecount>1e-5)
		bar((int)(team->goalkeeper.old_pos.x-5),(int)(team->goalkeeper.old_pos.y-5),(int)(team->goalkeeper.old_pos.x)+12+5,(int)(team->goalkeeper.old_pos.y)+34+5);
	if(team->name==Player)
		team->player[3].pnowstate=&team->player[3].ChasingBall;
}

//????????λ?????
void init_player(_player *pplayer,int position,int ID,int name)
{
	pplayer->ID=ID;
	pplayer->name=name;
	// pplayer->pnowstate = &pplayer->Wait;
	pplayer->Wait.Enter = WaitEnter;
    pplayer->Wait.Execute = WaitExecute;
    // pplayer->Wait.Exit = NULL;
	pplayer->Actioning.Enter=ActioningEnter;
	pplayer->Actioning.Execute=ActioningExecute;

    // pplayer->ReceivingBall.Enter = NULL;
    // pplayer->ReceivingBall.Execute = ReceivingBallExecute;
    // // pplayer->ReceivingBall.Exit = ReceivingBallExit;

    pplayer->Dribble.Enter =DribbleEnter;
    pplayer->Dribble.Execute = DribbleExecute;
    // pplayer->Dribble.Exit = NULL;

    pplayer->ChasingBall.Enter = NULL;
    pplayer->ChasingBall.Execute = ChasingBallExecute;
    // pplayer->ChasingBall.Exit = NULL;

    pplayer->Down.Enter=DownEnter;
	pplayer->Down.Execute=DownExecute;
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
	pplayer->control=0;
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
		pgoalkeeper->now_pos.y=275-rand()%25;
		pgoalkeeper->velocity.x=0;
		pgoalkeeper->velocity.y=2;
		pgoalkeeper->dir=Right;
	}
	else
	{
		pgoalkeeper->now_pos.x=602;
		pgoalkeeper->now_pos.y=251+rand()%25;
		pgoalkeeper->velocity.x=0;
		pgoalkeeper->velocity.y=2;
		pgoalkeeper->dir=Left;
	}
	pgoalkeeper->pnowstate=&pgoalkeeper->TendGoal;
}
//?????????????

void playerPower(_team *pteam)
{
	int team,i=0,j=0,k=0,l=0;
	int *ID;
	char *name;
	char *skip;
	char **ability;
	FILE *fpplayer,*fpteam,*fpID;
	ID=(int*)malloc(sizeof(int)*5);
	name=(char*)malloc(sizeof(char)*20);
	skip=(char*)malloc(sizeof(char)*30);
	ability=(char**)malloc(sizeof(char*)*5);
	for(i=0;i<5;i++)
	{
		ability[i]=(char*)malloc(sizeof(char)*30);
	}
	if(name==NULL||ability==NULL||ID==NULL||skip==NULL)
	{
		printf("malloc wrong");
		getch();
		exit(0);
	}
	if(pteam->name==Player)
	{
		if((fpteam=fopen("c:\\mycode\\shop\\path.txt","r"))==NULL)
		{
			setlinestyle(0,0,1);
			outtextxy(300,300,"cannot open myteam");
			getch();
			exit(1);
		}
		fscanf(fpteam,"%d",&team);
		fclose(fpteam);
		printf("%d",team);
		// getch();
		if((fpID=fopen("c:\\mycode\\shop\\player.txt","r"))==NULL)
		{
			setlinestyle(0,0,1);
			outtextxy(300,300,"cannot open player");
			getch();
			exit(1);
		}
		for(i=0;i<5;i++)
		{
			fscanf(fpID,"%d\n",&ID[i]);
		}
		fclose(fpID);
		printf("%d",ID[0]);
		switch(team){
			case 1:fpplayer=fopen("c:\\mycode\\shop\\1.txt","r");
					break;
			case 2:fpplayer=fopen("c:\\mycode\\shop\\2.txt","r");
					break;
			case 3:fpplayer=fopen("c:\\mycode\\shop\\3.txt","r");
					break;
			case 4:fpplayer=fopen("c:\\mycode\\shop\\4.txt","r");
					break;
			case 5:fpplayer=fopen("c:\\mycode\\shop\\5.txt","r");
					break;
		}
		if(fpplayer==NULL)
		{
			printf("can not open 1-5");
			getch();
			exit(0);
		}
		fscanf(fpplayer,"%s\n",name);
		for(i=1;i<12;i++)//i是行数
		{
			for(j=0;j<5;j++)
			{
				if(i==ID[j])
				{
					fscanf(fpplayer,"%s%s\n",name,ability[k]);
					k++;
					l=1;
				}
			}
			if(l!=1)
			{
				fscanf(fpplayer,"%s%s\n",name,skip);
			}
			l=0;
		}
		fclose(fpplayer);
		free(name);
		free(skip);
		free(ID);
		// ability[0][0]-='0';
		// ability[0][1]-='0';
		// ability[0][2]-='0';
		// printf("%c",ability[0][0]);
		// printf("%c",ability[0][1]);
		// printf("%c",ability[0][2]);
		// pteam->player[0].rate=ability[0][0]-'0';
		// printf("%d",pteam->player[0].rate);
		// getch();
		for(i=0;i<5;i++)
		{
			for(j=0;j<6;j++)
			{
				ability[i][j]-='0';
			}
		}
		for(i=0;i<4;i++)
		{
			pteam->player[i].rate=ability[i][0]*100+ability[i][1]*10+ability[i][2];
			pteam->player[i].power=ability[i][3]*100+ability[i][4]*10+ability[i][5];
		}
		pteam->goalkeeper.rate=ability[4][0]*100+ability[4][1]*10+ability[4][2];
		pteam->goalkeeper.power=ability[4][3]*100+ability[4][4]*10+ability[4][5];
		// printf("%d",pteam->goalkeeper.rate);
		// printf("%d",pteam->player[0].rate);
	}
	else
	{
		free(ID);
		if((fpteam=fopen("c:\\mycode\\shop\\opteam.txt","r"))==NULL)
		{
			setlinestyle(0,0,1);
			outtextxy(300,300,"cannot open the file");
			getch();
			exit(1);
		}
		fscanf(fpteam,"%d",&team);
		fclose(fpteam);
		// printf("%d",team);
		switch(team){
			case 1:fpplayer=fopen("c:\\mycode\\shop\\1.txt","r");
					break;
			case 2:fpplayer=fopen("c:\\mycode\\shop\\2.txt","r");
					break;
			case 3:fpplayer=fopen("c:\\mycode\\shop\\3.txt","r");
					break;
			case 4:fpplayer=fopen("c:\\mycode\\shop\\4.txt","r");
					break;
			case 5:fpplayer=fopen("c:\\mycode\\shop\\5.txt","r");
					break;
		}
		if(fpplayer==NULL)
		{
			printf("can not open");
			getch();
			exit(0);
		}
		fscanf(fpplayer,"%s\n",name);
		for(i=1;i<5;i++)//i是行数
		{
			fscanf(fpplayer,"%s%s\n",name,ability[k]);
			k++;
		}
		for(i=5;i<10;i++)
		{
			fscanf(fpplayer,"%s%s\n",name,skip);
		}
		fscanf(fpplayer,"%s%s\n",name,ability[4]);
		fclose(fpplayer);
		free(name);
		free(skip);
		for(i=0;i<5;i++)
		{
			for(j=0;j<6;j++)
			{
				ability[i][j]-='0';
			}
		}
		for(i=0;i<4;i++)
		{
			pteam->player[i].rate=ability[i][0]*100+ability[i][1]*10+ability[i][2];
			pteam->player[i].power=ability[i][3]*100+ability[i][4]*10+ability[i][5];
		}
		pteam->goalkeeper.rate=ability[4][0]*100+ability[4][1]*10+ability[4][2];
		pteam->goalkeeper.power=ability[4][3]*100+ability[4][4]*10+ability[4][5];
		// printf("%d",pteam->player[3].rate);
		// printf("%d",pteam->goalkeeper.rate);
		// getch();
	}
	free(ability);
}

void init_ball(_team *popteam,_team *pmyteam,_ball *pball)
{
	pball->downtime=0;
	pball->now_pos.x=322;
	pball->now_pos.y=280;
	pball->velocity.x=0.0;
	pball->velocity.y=0.0;
	pball->control=-1;
	pball->last_control=-1;
	pball->pnowstate=NULL;
	pball->Control.Enter=NULL;
	pball->Control.Execute=ControlExecute;
	pball->Short_pass.Enter=Short_passEnter;
	pball->Short_pass.Execute=NULL;
	pball->Long_pass.Enter=NULL;
	pball->Long_pass.Execute=Long_passExecute;
	pball->Short_shoot.Enter=Short_shootEnter;
	pball->Short_shoot.Execute=NULL;
	pball->Long_shoot.Enter=NULL;
	pball->Long_shoot.Execute=Long_shootExecute;
}
void init_judge(struct _JUDGE *pjudge)
{
	pjudge->pos.x=320.0;
	pjudge->pos.y=57.0;
}

void TeamUpdate(_team *pmyteam,_team *popteam,_ball *pball)
{
	if(pmyteam->pnowstate!=NULL)
		pmyteam->pnowstate->Execute(pmyteam,popteam,pball);
	if(popteam->pnowstate!=NULL)
		popteam->pnowstate->Execute(pmyteam,popteam,pball);
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
	player_border(pplayer);
	setfillstyle(1,GREEN);
	bar((int)(pplayer->old_pos.x),(int)(pplayer->old_pos.y),(int)(pplayer->old_pos.x)+12,(int)(pplayer->old_pos.y)+34);
	if(pplayer->name==Player)
		draw_player((int)(pplayer->now_pos.x),(int)(pplayer->now_pos.y),pplayer->dir,pplayer->control,pplayer->ID==pmyteam->controlplayer,pplayer->ID,pmyteam->color,pmyteam->name);
	else
		draw_player((int)(pplayer->now_pos.x),(int)(pplayer->now_pos.y),pplayer->dir,pplayer->control,pplayer->ID==popteam->controlplayer,pplayer->ID,popteam->color,popteam->name);
	if(pplayer->name==Player)
	{
		if(pplayer->ID==pmyteam->controlplayer)
		{
			pplayer->velocity.x=0.0;
    		pplayer->velocity.y=0.0;
		}
	}
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
	if(pgoalkeeper->name==Player)
		draw_player((int)(pgoalkeeper->now_pos.x),(int)(pgoalkeeper->now_pos.y),pgoalkeeper->dir,pgoalkeeper->control,0,4,pmyteam->color,pmyteam->name);
	else
		draw_player((int)(pgoalkeeper->now_pos.x),(int)(pgoalkeeper->now_pos.y),pgoalkeeper->dir,pgoalkeeper->control,0,4,popteam->color,popteam->name);
	delay(10);
}
void BallUpdate(_team *popteam,_team *pmyteam,_ball *pball)//pteam1????????
{
	double slow_rate=0.99;//??????
	if(pball->timecount%3==0)
		ball_border(popteam,pmyteam,pball);
	pball->old_pos.x=pball->now_pos.x;
	pball->old_pos.y=pball->now_pos.y;
	if(pball->pnowstate->Execute!=NULL)
		pball->pnowstate->Execute(popteam,pmyteam,pball);
	if (pball->control==-1)
	{
		pball->now_pos.x+=pball->velocity.x;
		pball->now_pos.y+=pball->velocity.y;
		pball->velocity.x*=slow_rate;
		pball->velocity.y*=slow_rate;
	}
	setfillstyle(1,GREEN);	
	bar((int)(pball->old_pos.x),(int)(pball->old_pos.y),(int)(pball->old_pos.x)+12,(int)(pball->old_pos.y)+12);
	draw_ball((int)(pball->now_pos.x),(int)(pball->now_pos.y));
	pball->timecount++;
	// draw_control(pmyteam,popteam);
	if(pball->timecount%FPS==0)
	{
		pball->time++;
		draw_time(pball->time);
	}
	if(pball->timecount%3==0)
		draw_score(pball->score_my,pball->score_op);
	if(pball->time>=30&&pmyteam->position==Left)
	{
		pball->flag=1;
	}
	if(pball->time>=180&&pmyteam->position==Right)
	{
		pball->flag=1;
	}
	// if(pball->old_pos.x!=pball->now_pos.x&&pball->old_pos.y!=pball->now_pos.y)
	// 	reback(pball->old_pos.x,pball->old_pos.y,16,16);
	delay(20);
}