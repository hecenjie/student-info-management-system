#include "NamePassword.h"

/*********************************************
 * 文件名：NamePassword.c
 * 描  述：用来定义学生信息管理系统用户登陆
 * 创建人：CANJIE
 * 日  期：2017-4-27
 *********************************************/

void ShowLogin()  //登陆界面
{
    int i;
    SetPosition(MARGIN_X + 21, 5);
    printf("-------------------------------------");
    SetPosition(MARGIN_X + 20, 6);
    printf("|");
    SetPosition(MARGIN_X + 58, 6);
    printf("|");
    SetPosition(MARGIN_X + 22, 6);
    printf("************* 登陆界面 ************");
    SetPosition(MARGIN_X + 21, 7);
    printf("-------------------------------------");
    for(i = 0; i < 5; i++)
    {
        SetPosition(MARGIN_X + 20, 7 + i);
        printf("|");
        SetPosition(MARGIN_X + 58, 7 + i);
        printf("|");
    }
    SetPosition(MARGIN_X + 20, 12);
    printf("---------------------------------------");
}

int Login()  //用户名与密码的输入
{
    char name[50];
    char password[50];
    int i;

    ShowLogin();
    SetPosition(MARGIN_X + 21, 9);
    printf("                                    ");  //清空屏幕
    SetPosition(MARGIN_X + 21, 10);
    printf("                                    ");  //清空屏幕
    SetPosition(MARGIN_X + 25, 9);
    printf("用户名：");
    SetPosition(MARGIN_X + 25, 10);
    printf("密  码：");
    SetPosition(MARGIN_X + 33, 9);

    fflush(stdin);
    MyFgets(name, 50);
    fflush(stdin);
    SetPosition(MARGIN_X + 33, 10);
    MyFgets(password, 50);
    fflush(stdin);

    if(veriLogin(name, password) == 1)  //用户名和密码验证
    {
        SetPosition(MARGIN_X + 26, 9);
        printf("密码输入正确，登陆成功！");
        SetPosition(MARGIN_X + 26, 10);
        printf("正在进入系统，请稍后...");
        Sleep(1000);
        for(i = 0; i < 8; i++)
        {
            SetPosition(MARGIN_X + 20, 5 + i);
            printf("                                             ");
        }
        return veriLogin(name, password);
    }
    else
    {
        SetPosition(MARGIN_X + 25, 9);
        printf("                         ");  //清空屏幕
        SetPosition(MARGIN_X + 25, 10);
        printf("                         ");  //清空屏幕
        SetPosition(MARGIN_X + 26, 9);
        printf("密码输入错误，请重新输入！");
        Sleep(1000);
        return veriLogin(name, password);
    }
}

int veriLogin(char name[], char password[])  //用户名与密码输入验证
{
    int result = 0;
    if(strcmp(name, USER_NAME) == 0 && strcmp(password, PASSWORD) == 0)
    {
        result = 1;  //密码输入正确返回1
    }
    return result;  //密码输入错误返回0
}

void MyFgets(char *name, int maxLen)  //接受输入的用户名和密码
{
    int i;

    fgets(name, maxLen, stdin);
    for(i = 0; name[i] != '\0'; i++)
    {
        if(name[i] == '\n')
        {
            name[i] = '\0';
            break;
        }
    }
}
