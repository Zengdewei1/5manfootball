#ifndef _TOOL_H
#define _TOOL_H

#define Right 1001
#define Left 1002
#define Red 1003
#define Blue 1004
#define Player 1005
#define Computer 1006
#define Direct 999
#define Circle 1000


typedef struct _POS2d
{
    double x,y;
}Pos2d;
typedef struct PLAYER_STATE
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
    void (*Enter)(struct _TEAM *pmyteam,struct _TEAM *popteam,struct _BALL *pball);
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
    int control; 
    int score;
    int help;                       //��Ա�Ƿ����
    int rate;                           //�Ǽ���״̬���ٶ�
    // int accelerate;                 //�����ٶȣ����ڰ��Ѷ���ʱ�Ĳ��� 
    int power;                         // �������������������ʱ������ٶ�
    // int capability_grabball;        // ����������������ͬ������ʱ�˲�������ж�Ϊ������
    // double accelerate_CD;         // �������ƣ�ÿ�μ������ֻ�е�����·�̴ﵽһ��ֵʱ�ſ��ٴ�ʹ�ü���
    // double capability_breakball;    //�����������˲��������ڶ��Χ���ж�Ϊ������
    player_state *pnowstate;
    player_state ChasingBall,Dribble,Wait,Actioning,Down;
}_player;
typedef struct _GOALKEEPER
{
    Pos2d velocity;
    Pos2d now_pos; 
    Pos2d old_pos;
    int ID;
    int name;
    int dir;
    int control;     //����Ա�Ƿ����
    int rate;
    int power;
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
    int flag;
    int control;//��������ˣ�-1���ܿ���
    int last_control;
    int score_my;
    int score_op;
    int time;
    int timecount;
    int downtime;
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
    int controlplayer;//��ҿ��Ƶ���ԱID
    int lastcontrol;
    int passman;
    int receivingman;
    int name;
    int color;
    int position;
    int control;//��ӿ����ˣ�-1������
    _player player[4];
    _goalkeeper goalkeeper;
    team_state *pnowstate;
    team_state Attack,Defend;
}_team;

void pass(_team *pmyteam,_team *popteam,_ball *pball,int type);
int findPass(_team *pmyteam,_team *popteam,_ball *pball);
float nearDist(_team *pmyteam,_team *popteam,_ball *pball,_player *pplayer);

double distance(double x1,double y1,double x2,double y2);
Pos2d get_dir(Pos2d pos_from,Pos2d pos_to);

void action(_team *pmyteam,_team *popteam,_ball *pball);
void move_dir(_player *pplayer,_ball *pball);
void auto_act(_team *pmyteam,_team *popteam,_player *pplayer,_ball *pball);
// void move_renctangle(_player *pplayer,int type);
void arrive(_player *pplayer,double _x,double _y);

void draw_player(int x,int y,int dir,int control,int action,int ID,int color,int name);
void draw_judge(int x,int y);
void draw_ground();
void draw_ball(int x,int y,_ball *pball);
void draw_num(int x,int y,int num,int size);
void draw_time(int time);
void draw_score(int score_my,int score_op);
void draw_control(_team *pmyteam,_team *popteam);
// void draw_stop();
// void draw_start();
void playerID(int path);
void xiuxi();

void player_border(_player *pplayer);
void ball_border(_team *popteam,_team *pmyteam,_ball *pball);
#endif