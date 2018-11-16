#include "main.h"

void main()
{
    int driver,mode;
	int page=0;
	int matchType=0;
	int path=0;
	char s[10][10];
	driver=VGA;
	mode=VGAHI;
	initgraph(&driver,&mode,"C:\\BORLANDC\\BGI");
	Initmouse(0,639,0,479);
	InstallKeyboard();
	menu();
	while(1)
	{
		switch(page)
		{
			case 0://
				page=menu();
				break;
			case 1://教学界面
				page=jiaoxue();
				break;
				
			case 2://选择场次界面
			    page=changci(&matchType);
				break;
				
			case 3://管理员登录界面
				page = admlogin();
				break;
				
			case 4://主界面
				page = facet(&temp,s);
				break;
				
			case 5://选球队界面
			    page=choose_team(s,&path);
				break;
				
			case 6://选球员界面
				page=choose_player(s,path);
				break;
				
			case 7://商城界面
			    page=shop(path);
				break;
				
            case 8://历史记录界面
			    history();
				break;
				
			case 9://查询时间界面
			    page=fastMatch(matchType);
				break;
			
			case 10://喜爱的球队界面
			    page=teamMatch();
				break;
			case 11://喜爱的球队界面
			    page=playerID(path);
				break;
		}
	}
}