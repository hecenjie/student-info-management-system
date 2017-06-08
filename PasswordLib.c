#include "PasswordLib.h"

extern Password password[30];
extern int countpass;

/*
void Register()
{

    Password password[30] = {};
    Password *p = password;
    SetPosition(MARGIN_X + 35, 10);
    printf("输入你要创建账号:");
    MyFgets(p->account, 20);
    SetPosition(MARGIN_X + 35, 11);
    printf("输入你的密码:");
    MyFgets(p->password, 20);
    ClearTotal();
    SetPosition(MARGIN_X + 37, 9);
    printf("注册成功");
    Sleep(3000);

}
*/
void PassMenu()
{
    int i;
    char choice;
    for(i = 0; i < 7; i++)
    {
        SetPosition(MARGIN_X, 21 + i);
        printf("                             ");
    }
    while(1)
    {
        for(i = 0; i < 13; i++)
        {
            SetPosition(MARGIN_X + 19, 4 + i);
            printf("                                                    ");
        }
        SetPosition(MARGIN_X + 27, 8);
        printf("请选择您要进行的操作：");
        SetPosition(MARGIN_X + 27, 10);
        printf("1、注册账户");
        SetPosition(MARGIN_X + 27, 11);
        printf("2、返回菜单");
        if((choice = getch()) == '2')
           break;
        PassChoice(choice);
    }

}

void PassInput()
{
    ReadPass();
    int i;
    Password *p = password + countpass;
    PassOne();

    fflush(stdin);
    SetPosition(MARGIN_X + 35, 8);
    MyFgets(p->account, 30);
    SetPosition(MARGIN_X + 35, 9);
    MyFgets(p->password, 30);

    fflush(stdin);

    for(i = 0; i < 8; i++)
    {
        SetPosition(MARGIN_X + 28, 8 + i);
        printf("                              ");
    }
    SetPosition(MARGIN_X + 36, 10);
    printf("注册成功！");
    countpass++;  //密码有效数量+1

    WritePass();  //将账户写入文件中

    SetPosition(MARGIN_X + 26, 11);

    p = password;
    Sleep(1000);
}




void PassChoice(char choice)
{
    int i;

    switch(choice)
    {
    case '1':  //账户注册
        PassInput();
        break;
    case '2':  //返回主菜单
        break;
    default:
        for(i = 0; i < 5; i++)
        {
            SetPosition(MARGIN_X + 27, 8 + i);
            printf("                       ");
        }
        SetPosition(MARGIN_X + 20, 9);
        printf("对不起，只能输入1~2之间的数字，请您重新输入！");
        Sleep(1500);
    }

}


void PassOne()
{
    int i;
    for(i = 0; i < 5; i++)
    {
        SetPosition(MARGIN_X + 27, 8 + i);
        printf("                      ");
    }
    SetPosition(MARGIN_X + 20, 4);
    printf("--------------------------------------------");
    SetPosition(MARGIN_X + 20, 6);
    printf("--------------------------------------------");
    for(i = 0; i < 12; i++)
    {
        SetPosition(MARGIN_X + 20, 5 + i);
        printf("|");
        SetPosition(MARGIN_X + 65, 5 + i);
        printf("|");
    }
    SetPosition(MARGIN_X + 20, 16);
    printf("--------------------------------------------");
    SetPosition(MARGIN_X + 36, 5);
    printf("账号注册");
    SetPosition(MARGIN_X + 27, 8);
    printf("账  号：");
    SetPosition(MARGIN_X + 27, 9);
    printf("密  码：");
}


