#ifndef _MOUSE_H_
#define _MOUSE_H_


void Cursor(int x,int y);
int Initmouse(int xmi,int xma,int ymi,int yma);
int Readmouse();
void Newxy(void);
void Mouse_savebk(int x,int y);
void Mouse_putbk(int x,int y);
int Mouse_press(int x1,int y1,int x2,int y2);
int Mouse_above(int x1,int y1,int x2,int y2);


#endif