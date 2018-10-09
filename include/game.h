#ifndef _GAME_H_
#define _GAME_H_

#define FPS 40

void game(int position1,int position2,int color1,int color2);
void init_ball(struct _BALL *pball);
void init_judge(struct _JUDGE *pjudge);
void init_player(_player *pplayer,int position,int ID,int name);
void init_team(struct _TEAM *team);
void init_goalkeeper(_goalkeeper *pgoalkeeper,int position);

void PlayerChangestate(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball,player_state *pnewstate);
void KeeperChangestate(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball,keeper_state *pnewstate);
void BallChangestate(_team *pmyteam,_team *popteam,_ball *pball,ball_state *pnewstate);

void AttackExecute(_team *pmyteam,_team *popteam,_ball *pball);
void DefendExecute(_team *pmyteam,_team *popteam,_ball *pball);

void ChasingBallExecute(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball);
void DribbleExecute(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball);
void WaitExecute(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball);
// void SupportingExecute(_team *team,_ball *pball);
// void ReceivingBallExecute(_team *team,_ball *pball);

void TendGoalExecute(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball);
void PounceEnter(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball);
void PounceExecute(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball);
void ControlBallExecute(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball);

void Short_passEnter(_team *pmyteam,_team *popteam,_ball *pball);
void Short_shootEnter(_team *pmyteam,_team *popteam,_ball *pball);
void ControlExecute(_team *pmyteam,_team *popteam,_ball *pball);

void BallUpdate(_team *pmyteam,_team *popteam,_ball *pball);
void PlayerUpdate(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball);
void GoalkeeperUpdate(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball);
#endif