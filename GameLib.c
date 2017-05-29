#include "GameLib.h"

/*********************************************
 * 文件名：GameLib.c
 * 描  述：实现Game.h中定义的学生信息管理系统中常用的系统操作（更改文字颜色、清屏等）
 * 创建人：CANJIE
 * 日  期：2017-4-27
 *********************************************/

 /* 设置控制台窗口的标题 */
void SetTitle(char *title)
{
    SetConsoleTitle(title);
}
/*
 * 设置文字背景色、前景色
 * 0-黑色，1-蓝色，2-绿色，3-浅绿色，4-红色，5-紫色，6-黄色，7-白色
 * 8-灰色，9-浅蓝色，10-浅绿色，11-淡浅绿色，12-淡红色，13-淡紫色，14-淡黄色
 * 15-亮白色
 */
void SetColor(int foreColor, int backColor)
{
    HANDLE winHandle;  //句柄
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置文字颜色
    SetConsoleTextAttribute(winHandle, foreColor + backColor * 0x10);
}
/* 设置光标的坐标 */
void SetPosition(int x, int y)
{
    HANDLE winHandle;  //句柄
    COORD pos = {x, y};
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置光标的坐标
    SetConsoleCursorPosition(winHandle, pos);
}

/************************************************************************************************/

/* 显示系统欢迎界面 */
void ShowWelcome()
{
    SetPosition(MARGIN_X, 0);
    printf("%s", SEP);
    SetPosition(MARGIN_X, 1);
    printf("|");
    SetPosition(MARGIN_X + 20, 1);
    printf("欢迎来到南京农业大学工学院学生信息管理系统！");
    SetPosition(MARGIN_X + 82, 1);
    printf("|");
    SetPosition(MARGIN_X, 2);
    printf("%s", SEP);
}

/* 显示欢迎界面下方信息 */
void ShowInfomation()
{
    int i;
    for(i = 0; i < 17; i++)
    {
        SetPosition(MARGIN_X, 3 + i);
        printf("|");
        SetPosition(MARGIN_X + 82, 3 + i);
        printf("|");
    }
    SetPosition(MARGIN_X, 20);
    printf("%s", SEP);
}

/* 显示用户菜单 */
void ShowMainMenu()
{
    SetPosition(MARGIN_X, 21);
    printf("1、学生信息录入");
    SetPosition(MARGIN_X, 22);
    printf("2、学生成绩查询");
    SetPosition(MARGIN_X, 23);
    printf("3、打印报表");
    SetPosition(MARGIN_X, 24);
    printf("4、排名查询");
    SetPosition(MARGIN_X, 25);
    printf("5、* 智能人机对话");
    SetPosition(MARGIN_X, 26);
    printf("6、音乐播放");
    SetPosition(MARGIN_X, 27);
    printf("7、退出系统");
}

/* 完整清屏 */
void ClearTotal()
{
    int i, j;  //竖排有17，横排有81
    for(i = 0; i < 17; i++)
    {
        for(j = 0; j < 81; j++)
        {
            SetPosition(MARGIN_X + j + 1, 3 + i);
            printf(" ");
        }
    }
}

/* 部分清屏 */
void ClearPart()
{
    int i;
    for(i = 0; i < 13; i++)
    {
        SetPosition(MARGIN_X + 19, 4 + i);
        printf("                                                    ");
    }
}








