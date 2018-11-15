#include "main.h"

void main()
{
    int driver,mode,i=0;
	driver=VGA;
	mode=VGAHI;
	initgraph(&driver,&mode,"C:\\BORLANDC\\BGI");
	Initmouse(0,639,0,479);
	InstallKeyboard();
	menu();
}