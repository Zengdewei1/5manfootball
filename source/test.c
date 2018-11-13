#include "main.h"

void main()
{
	FILE *fpGame;
	int match;
	if(fpGame=fopen("c:\\mycode\\result\\game.txt","r")==NULL)
	{
		printf("cant not open");
		getch();
		exit(1);
	}
	match=fgetc(fpGame);
	printf("%d",match);
}