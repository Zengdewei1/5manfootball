#ifndef _GAME_H_
#define _GAME_H_

#define FPS 40

void game(int position1,int position2,int color1,int color2);
void init_team(_team *team);
void init_ball(_ball *pball);
void init_judge(_judge *pjudge);
void init_player(_player *pplayer,int position,int ID,int name);
void init_goalkeeper(_goalkeeper *pgoalkeeper,int position,int name);


// void TeamUpdate(_team *pmyteam,_team *popteam,_ball *pball);//pteam是相对而言的
void BallUpdate(_team *pmyteam,_team *popteam,_ball *pball);
void PlayerUpdate(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball,int teamname);
void GoalkeeperUpdate(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball,int teamname);
#endif