#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "GameLib.h"
#include "ProcessMainMenu.h"
#include "NamePassword.h"
#include "ReadInfo.h"
#include "InfoInput.h"
#include "RankingQuery.h"

extern int count;  //引用外部全局变量，即学生有效数量

char key;  //用户在菜单的选择

int main()
{
    ReadInfo();  //将文件已有学生信息录入数组当中
    //system("mode con cols=500 lines=500");
    SetTitle("学生信息管理系统");
    system("color 8E");  //改变背景色
    ShowWelcome();
    ShowInfomation();
    //while(Login() == 0);
    ShowMainMenu();
    while(1)
    {
        fflush(stdin);
        key = getch();
        fflush(stdin);
        if(key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7')
        {
            ProcessMainMenu(key);
        }
        ShowMainMenu();
    }

    system("pause");
}
