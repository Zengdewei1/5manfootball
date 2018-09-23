/**********************************************************
Copyright (C) 2017 郭裕祺 黄杰豪.
File name:      MultiKey.c
Author:         郭裕祺
Version：        1.1
Date：           2017/9/23
Description：    多按键检测模块源文件。

                对本文件的修改请及时按如下格式记录在下面（每个修改单独列出）！

Function List：
    1.void ShutDownKeyboard(void); 
        恢复9H之前的中断函数

    2.void far interrupt NewInt9(void); 
        新的中断函数

    3.void InstallKeyboard(void);
        将新的中断写入新的向量表，并保存旧的中断。
		
	4.int GetKey(int ScanCode);
		检测给定按键是否按下过
	
	5.int KeyPress(int ScanCode); 
		检测给定按键当前是否处于按下状态


	
History：        对本文件的修改请及时按如下格式记录在下面（每个修改单独列出）！
    Example：    Date：
                Author：
                Version：
                Modification：

1.  Date：2017/9/23
        Author：郭裕祺
        Version：1.0
        Modification：此前注释并未形成规范，此次重新梳理了一遍，将版本号定为1.0

**********************************************************/


#include<dos.h>
#include"MultiKey.h"

char key_state[128],key_pressed[128];            //全局变量，用于储存128个按键的状态

void interrupt far (*OldInt9Handler)();          //用于保存旧的中断




/**********************************************************
Function：      ShutDownKeyboard

Description：   恢复9H之前的中断函数

Input：      None
Output：     None
Return：     None
Others：     None
**********************************************************/
void ShutDownKeyboard(void)
{
    setvect(9,OldInt9Handler);
}


/**********************************************************
Function：      NewInt9

Description：   新的中断函数

Input：      None
Output：     None
Return：     None
Others：     None
**********************************************************/   
void far interrupt NewInt9(void)
{
    unsigned char ScanCode,temp;
    ScanCode=inportb(0x60);
    temp=inportb(0x61);
    outportb(0x61,temp | 0x80);
    outportb(0x61,temp & 0x7f);
    if(ScanCode&0x80)
    {
        ScanCode&=0x7f;
        key_state[ScanCode]=0;
    }
    else
    {
        key_state[ScanCode]=1;
        key_pressed[ScanCode]=1;
    }
    outportb(0x20,0x20);
}

/**********************************************************
Function：      InstallKeyboard

Description：   将新中断写入向量表，并保存旧的中断

Input：      None
Output：     None
Return：     None
Others：     None
**********************************************************/ 
void InstallKeyboard(void)
{
    int i;
    for(i=0;i<128;i++)
        key_state[i]=key_pressed[i]=0;
    OldInt9Handler=getvect(9);
    setvect(9,NewInt9);
}

/**********************************************************
Function：      GetKey

Description：   检测给定按键是否按下过

Input：      int ScanCode         给定按键键值，见文件开头的宏定义  

Output：     None
Return：     None
Others：     None
**********************************************************/ 
int GetKey(int ScanCode)
{
    int res;
    res=key_pressed[ScanCode];
    key_pressed[ScanCode]=0;
    return res;
}


/**********************************************************
Function：     KeyPress

Description：   检测给定按键当前是否处于按下状态

Input：      int ScanCode         给定按键键值，见文件开头的宏定义  

Output：     None
Return：     None
Others：     None
**********************************************************/ 
int KeyPress(int ScanCode)
{

    return key_state[ScanCode];
}
