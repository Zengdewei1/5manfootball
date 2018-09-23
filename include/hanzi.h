#ifndef _HANZI_H_
#define _HANZI_H_

void printHZ12(int x,int y,char *s,int color,int dx,int dy,int gap,int mode);       /*12*12点阵汉字的显示*/
//void printHZ16(int x,int y,char *s,int color ,int dx,int dy);       /*16*16点阵汉字的显示*/
void printASC(char *s,int x,int y,int dx,int dy,short color);

#endif