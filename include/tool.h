#ifndef _TOOL_H
#define _TOOL_H

#define Right 1001
#define Left 1002
#define Red 1003
#define Blue 1004
#define Player 1005
#define Computer 1006

typedef struct _POS2d
{
    double x,y;
}Pos2d;
typedef struct PLAYER_STATE
{
    void (*Enter)(struct _TEAM *pteam1,struct _TEAM *pteam2,struct _PLAYER *pplayer,struct _BALL *pball);
    void (*Execute)(struct _TEAM *pteam1,struct _TEAM *pteam2,struct _PLAYER *pplayer,struct _BALL *pball);
    void (*Exit)(struct _TEAM *pteam1,struct _TEAM *pteam2,struct _PLAYER *pplayer,struct _BALL *pball);
}player_state;
typedef struct KEEPER_STATE
{
    void (*Enter)(struct _TEAM *pteam1,struct _TEAM *pteam2,struct _GOALKEEPER *pgoalkeeper,struct _BALL *pball);
    void (*Execute)(struct _TEAM *pteam1,struct _TEAM *pteam2,struct _GOALKEEPER *pgoalkeeper,struct _BALL *pball);
    void (*Exit)(struct _TEAM *pteam1,struct _TEAM *pteam2,struct _GOALKEEPER *pgoalkeeper,struct _BALL *pball);
}keeper_state;
typedef struct _PLAYER
{
    Pos2d velocity;
    Pos2d now_pos; 
    Pos2d old_pos;
    int ID;
    int dir;
    int control;
    player_state *pnowstate;
    player_state Dribble,ReceivingBall,Wait,ChasingBall,Supporting;
}_player;
typedef struct _GOALKEEPER
{
    Pos2d velocity;
    Pos2d now_pos; 
    Pos2d old_pos;
    int ID;
    int dir;
    int control;
    keeper_state *pnowstate;
    keeper_state TendGoal,ReturnHome;
}_goalkeeper;
typedef struct _BALL
{
    Pos2d velocity;
    Pos2d now_pos; 
    Pos2d old_pos;
    int control;
    int owner;
    int name;
    int timecount;
}_ball;
typedef struct _JUDGE
{
    Pos2d velocity;
    Pos2d pos; 
}_judge;
typedef struct TEAM_STATE
{
    void (*Enter)(struct _TEAM *team,struct _BALL *pball);
    void (*Execute)(struct _TEAM *team,struct _BALL *pball);
    void (*Exit)(struct _TEAM *team,struct _BALL *pball);
}team_state;
typedef struct _TEAM
{
    int controlplayer;
    int iscontrol;
    int name;
    int color;
    int position;
    _player player[4];
    _goalkeeper goalkeeper;
}_team;

void shoot(_team *team,_ball *pball);
void pass(struct _BALL *pball,struct _TEAM *team);

double distance(double x1,double y1,double x2,double y2);
Pos2d get_dir(Pos2d pos_from,Pos2d pos_to);

void action(_team *team,_ball *pball);
void move_dir(_player *pplayer,_ball *pball);
void move_area(_team *pteam1,_team *pteam2,_player *pplayer,_ball *pball);
// void move_renctangle(_player *pplayer,int type);
void arrive(_player *pplayer,double _x,double _y);

void draw_player(int x,int y,int dir,int control,int ID,int color);
void draw_judge(int x,int y);
void draw_ground();
void draw_ball(int x,int y);

#endif