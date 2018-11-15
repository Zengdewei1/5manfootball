#include "main.h"

void main()
{
    int driver,mode,i=0;
	// FILE *fpGame;
	// int match;
	driver=VGA;
	mode=VGAHI;
	initgraph(&driver,&mode,"C:\\BORLANDC\\BGI");
	Initmouse(0,639,0,479);
	InstallKeyboard();
	// if((fpGame=fopen("c:\\mycode\\result\\game.txt","r"))==NULL)
	// {
	// 	printf("cant not open");
	// 	getch();
	// 	exit(1);
	// }
	// // match=fgetc(fpGame);
	// fscanf(fpGame,"%d",&match);
	// // match-=48;
	// printf("%d",match);
	// fclose(fpGame);
	// game(Left,Right,Red,Blue,match);
	// // xiuxi();
	// while(1)
	// {
	// 	if(KeyPress(KEY_ENTER))
	// 	{
	// 		break;
	// 	}
	// }
	// game(Right,Left,Red,Blue,match);
	// match++;
	// printf("%d",match);
	// if((fpGame=fopen("c:\\mycode\\result\\game.txt","w"))==NULL)
	// {
	// 	printf("cant not open");
	// 	getch();
	// 	exit(1);
	// }
	// if(match<10)
	// {
	// 	fprintf(fpGame,"%d",i);
	// }
	// fprintf(fpGame,"%d",match);
	// fclose(fpGame);
	// // result();
	// while(1)
	// {
	// 	if(KeyPress(KEY_ENTER))
	// 	{
	// 		menu();
	// 	}
	// }
	menu();
}