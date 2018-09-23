#ifndef _TOOL_H
#define _TOOL_H

#define Right 1001
#define Left 1002

typedef struct _POS2d
{
    double x,y;
}Pos2d;
typedef struct PLAYER_STATE
{
    void (*Enter)(struct _TEAM *pteam1,struct _TEAM *pteam2,struct _BALL *pball);
    void (*Execute)(struct _TEAM *pteam1,struct _TEAM *pteam2,struct _BALL *pball);
    void (*Exit)(struct _TEAM *pteam1,struct _TEAM *pteam2,struct _BALL *pball);
}player_state;
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
    player_state *pnowstate;
    player_state TendGoal,ReturnHome;
}_goalkeeper;
typedef struct _BALL
{
    Pos2d velocity;
    Pos2d now_pos; 
    Pos2d old_pos;
    int control;
    int owner;
    enum TEAM_NAME team_name;
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
    _player player[4];
    _goalkeeper goalkeeper;
    enum TEAM_NAME team_name;
}_team;

enum TEAM_NAME
{
    Blue,
    Red
};
void shoot(_team *team,_ball *pball);
void pass(struct _BALL *pball,struct _TEAM *team);
double distance(double x1,double y1,double x2,double y2);
Pos2d get_dir(Pos2d pos_from,Pos2d pos_to);
void action(_team *team,_ball *pball);

void draw_player(int x,int y,int dir,int control,int ID,enum TEAM_NAME team_name);
void draw_judge(int x,int y);
void draw_ground();
void draw_ball(int x,int y);

#endif