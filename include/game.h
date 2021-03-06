#ifndef _GAME_H_
#define _GAME_H_

#define FPS 10

void game(int position1,int position2,int color1,int color2,int match);
void init_ball(_team *popteam,_team *pmyteam,_ball *pball);
void init_judge(struct _JUDGE *pjudge);
void init_player(_player *pplayer,int position,int ID,int name);
void init_team(_team *team,_ball *pball);
void init_goalkeeper(_goalkeeper *pgoalkeeper,int position,int name);
void playerPower(_team *pteam);

void TeamChangestate(_team *pmyteam,_team *popteam,_ball *pball,team_state *pnewstate_my,team_state *pnewstate_op);
void PlayerChangestate(_team *popteam,_team *pmopeam,_player *pplayer,_ball *pball,player_state *pnewstate);
void KeeperChangestate(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball,keeper_state *pnewstate);
void BallChangestate(_team *pmyteam,_team *popteam,_ball *pball,ball_state *pnewstate);

void AttackEnter(_team *pmyteam,_team *popteam,_ball *pball);
void AttackExecute(_team *pmyteam,_team *popteam,_ball *pball);
void DefendExecute(_team *pmyteam,_team *popteam,_ball *pball);

void ChasingBallExecute(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball);
void DribbleEnter(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball);
void DribbleExecute(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball);
void WaitEnter(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball);
void WaitExecute(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball);
void ActioningEnter(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball);
void ActioningExecute(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball);
void DownEnter(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball);
void DownExecute(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball);

void TendGoalExecute(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball);
void PounceEnter(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball);
void PounceExecute(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball);
void ControlBallExecute(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball);

void Short_passEnter(_team *popteam,_team *pmyteam,_ball *pball);
void Short_shootEnter(_team *popteam,_team *pmyteam,_ball *pball);
void Long_passExecute(_team *popteam,_team *pmyteam,_ball *pball);
void Long_shootExecute(_team *popteam,_team *pmyteam,_ball *pball);
void ControlExecute(_team *popteam,_team *pmyteam,_ball *pball);

void TeamUpdate(_team *pmyteam,_team *popteam,_ball *pball);
void BallUpdate(_team *popteam,_team *pmyteam,_ball *pball);
void PlayerUpdate(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball);
void GoalkeeperUpdate(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball);
#endif