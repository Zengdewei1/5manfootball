#ifndef _STATE_H
#define _STATE_H


void PlayerChangestate(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball,player_state *pnewstate);
void KeeperChangestate(_team *pmyteam,_team *popteam,_goalkeeper *pgoalkeeper,_ball *pball,keeper_state *pnewstate);
void BallChangestate(_team *pmyteam,_team *popteam,_ball *pball,ball_state *pnewstate);

// void AttackExecute(_team *pmyteam,_team *popteam,_ball *pball);

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

#endif 