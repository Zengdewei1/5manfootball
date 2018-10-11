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
typedef struct PLAYER_STATE//pteam是相对而言的
{
    void (*Enter)(struct _TEAM *pmyteam,struct _TEAM *popteam,struct _PLAYER *pplayer,struct _BALL *pball);
    void (*Execute)(struct _TEAM *pmyteam,struct _TEAM *popteam,struct _PLAYER *pplayer,struct _BALL *pball);
    // void (*Exit)(struct _TEAM *pmyteam,struct _TEAM *popteam,struct _PLAYER *pplayer,struct _BALL *pball);
}player_state;
typedef struct KEEPER_STATE
{
    void (*Enter)(struct _TEAM *pmyteam,struct _TEAM *popteam,struct _GOALKEEPER *pgoalkeeper,struct _BALL *pball);
    void (*Execute)(struct _TEAM *pmyteam,struct _TEAM *popteam,struct _GOALKEEPER *pgoalkeeper,struct _BALL *pball);
    // void (*Exit)(struct _TEAM *pmyteam,struct _TEAM *popteam,struct _GOALKEEPER *pgoalkeeper,struct _BALL *pball);
}keeper_state;
typedef struct BALL_STATE
{
    void (*Enter)(struct _TEAM *popteam,struct _TEAM *pmyteam,struct _BALL *pball);
    void (*Execute)(struct _TEAM *popteam,struct _TEAM *pmyteam,struct _BALL *pball);
	// void (*Exit)(struct _TEAM *pmyteam,struct _TEAM *popteam,struct _BALL *pball);
}ball_state;
typedef struct TEAM_STATE
{
    void (*Execute)(struct _TEAM *pmyteam,struct _TEAM *popteam,struct _BALL *pball);
}team_state;
typedef struct _PLAYER
{
    Pos2d velocity;
    Pos2d now_pos; 
    Pos2d old_pos;
    int ID;
    int name;
    int dir;
    int control;                        //球员是否控球
    int rate;                           //非加速状态的速度
    int accelerate;                 //加速速度，用于摆脱对手时的参数 
    int power;                         // 力量，决定传球和射门时给球的速度
    int capability_grabball;        // 抢球能力，距离球同样距离时此参数大的判定为抢到球
    double accelerate_CD;         // 加速限制，每次加速完后，只有当所走路程达到一定值时才可再次使用加速
    double capability_breakball;    //断球能力，此参数决定在多大范围内判定为抢到球
    player_state *pnowstate;
    player_state Dribble,ReceivingBall,Wait,ChasingBall,Supporting;
}_player;
typedef struct _GOALKEEPER
{
    Pos2d velocity;
    Pos2d now_pos; 
    Pos2d old_pos;
    int ID;
    int name;
    int dir;
    int control;     //守门员是否控球
    keeper_state *pnowstate;
    keeper_state TendGoal,Pounce,ControlBall;
}_goalkeeper;
typedef struct _BALL
{
    Pos2d velocity;
    Pos2d now_pos; 
    Pos2d old_pos;
    Pos2d start_pos;
    Pos2d end_pos;
    int control;//足球控制人，-1不受控制
    int timecount;
    ball_state *pnowstate;
    ball_state Long_pass,Long_shoot,Short_pass,Short_shoot,Control;
}_ball;
typedef struct _JUDGE
{
    Pos2d velocity;
    Pos2d pos; 
}_judge;

typedef struct _TEAM
{
    int controlplayer;//玩家控制的球员ID
    int name;
    int color;
    int position;
    int control;//球队控球人，-1不控球
    _player player[4];
    _goalkeeper goalkeeper;
    team_state *pnowstate;
    team_state Attack,Defend;
}_team;
void pass(_team *pmyteam,_team *popteam,_ball *pball);

double distance(double x1,double y1,double x2,double y2);
Pos2d get_dir(Pos2d pos_from,Pos2d pos_to);

void action(_team *pmyteam,_team *popteam,_ball *pball);
void move_dir(_player *pplayer,_ball *pball);
void auto_move(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball);
// void move_renctangle(_player *pplayer,int type);
void arrive(_player *pplayer,double _x,double _y);

void draw_player(int x,int y,int dir,int control,int ID,int color,int name);
void draw_judge(int x,int y);
void draw_ground();
void draw_ball(int x,int y);
void draw_num(int x,int y,int num,int size);
// void reback(int x,int y,int x_size,int y_size);
#endif