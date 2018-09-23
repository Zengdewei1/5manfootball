#ifndef _GAME_H_
#define _GAME_H_

#define FPS 40

void game();
void init_ball(struct _BALL *pball);
void init_judge(struct _JUDGE *pjudge);
void init_player(_player *pplayer,enum TEAM_NAME team_name,int ID);
void init_team(struct _TEAM *team,enum TeamName team_name);
void init_goalkeeper(_goalkeeper *pgoalkeeper,enum TEAM_NAME team_name);

// void PlayerChangestate(_player *pplayer,player_state *pnewstate,_team *pmyteam,_team *popteam);

void ChasingBallExecute(_team *pteam1,_team *pteam2,_ball *pball);
void DribbleExecute(_team *pteam1,_team *pteam2,_ball *pball);
void WaitExecute(_team *pteam1,_team *pteam2,_ball *pball);
// void SupportingExecute(_team *team,_ball *pball);
// void ReceivingBallExecute(_team *team,_ball *pball);

void TendGoalExecute(_team *pteam1,_team *pteam2,_ball *pball);
void ReturnHomeExecute(_team *pteam1,_team *pteam2,_ball *pball);

void BallUpdate(struct _BALL *pball,struct _PLAYER *pplayer);
void PlayerUpdate(_team *pteam1,_team *pteam2,_player *pplayer,_ball *pball);
void GoalkeeperUpdate(_team *pteam1,_team *pteam2,_goalkeeper *pgoalkeeper,_ball *pball);
#endif