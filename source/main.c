#include "main.h"

void main()
{
    int driver,mode;
	int page=0;
	int matchType=0;
	int path=0;
	int resultID=0;
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
			case 1://��ѧ����
				page=jiaoxue();
				break;
				
			case 2://ѡ�񳡴ν���
			    page=changci(&matchType);
				break;
				
			case 3://����Ա��¼����
				// page = admlogin();
				break;
				
			case 4://������
				page =result(resultID);
				break;
				
			case 5://ѡ��ӽ���
			    page=choose_team(s,&path);
				break;
				
			case 6://ѡ��Ա����
				page=choose_player(s,path);
				break;
				
			case 7://�̳ǽ���
			    page=shop(path);
				break;
				
            case 8://��ʷ��¼����
			    page=history(&resultID);
				break;
				
			case 9://��ѯʱ�����
			    page=fastMatch(matchType);
				break;
			
			case 10://ϲ������ӽ���
			    page=teamMatch();
				break;
			case 11://ϲ������ӽ���
			    page=playerID(path);
				break;
		}
	}
}