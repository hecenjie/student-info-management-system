#include "NamePassword.h"

/*********************************************
 * 文件名：NamePassword.c
 * 描  述：用来定义学生信息管理系统用户登陆
 * 创建人：CANJIE
 * 日  期：2017-4-27
 *********************************************/
int ok;
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
    int x = 0;
    char c;
    int i = 0;
    char name[20];
    char password1[20];

    ClearTotal();
    ShowLogin();

    SetPosition(MARGIN_X + 25, 9);
    printf("用户名：");
    SetPosition(MARGIN_X + 25, 10);
    printf("密  码：");
    SetPosition(MARGIN_X + 33, 9);

    fflush(stdin);
    MyFgets(name, 20);

    fflush(stdin);
    SetPosition(MARGIN_X + 33, 10);
    while ((c=getch())!='\r')
    {
        if (i<19 && isprint(c))
        {
            password1[i++] = c;
            putchar('*');
        }
        else if (i>0 && c=='\b')
        {
            --i;
            putchar('\b');
            putchar(' ');
            putchar('\b');
        }
    }
    password1[i] = '\0';
    fflush(stdin);

    if(veriLogin(name, password1) == 1)  //用户名和密码验证
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
        ok = 1;

        //return veriLogin(name, password1);

    }

    else
    {
        SetPosition(MARGIN_X + 25, 9);
        printf("                         ");  //清空屏幕
        SetPosition(MARGIN_X + 25, 10);
        printf("                         ");  //清空屏幕
        SetPosition(MARGIN_X + 26, 9);
        printf("用户名或密码错误，请重新输入！");
        Sleep(1000);
        ok = 0;

       //return veriLogin(name, password1);

    }

}

int veriLogin(char name[], char password1[])  //用户名与密码输入验证
{
    ReadPass();
    Password *p = password;
    int result = 0;
    int i;
    int index = -1;
    for(i = 0; i < countpass; i++, p++)
    {
        if(strcmp(name, p->account) == 0 && strcmp(password1, p->password) == 0)
        {
            index = i;
            break;
        }
    }


    if(index != -1)
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


int ShowMenu()
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

        ok = 0;
        for(i = 0; i < 13; i++)
        {
            SetPosition(MARGIN_X + 19, 4 + i);
            printf("                                                    ");
        }
        SetPosition(MARGIN_X + 34, 9);
        printf("1.登陆");
        SetPosition(MARGIN_X + 34, 10);
        printf("2.注册账户");
        SetPosition(MARGIN_X + 34, 11);
        printf("3.退出系统");
        if((choice = getch()) == '3')
           {
            ClearTotal();
            system("cls");
            exit(1);

           }
        InputChoice(choice);
        if(ok == 1)
        return ok;


    }
}

void InputChoice(char choice)
{
    int i;
    switch(choice)
    {
    case '1':
        Login();

        break;
    case '2':
        PassMenu();
        break;
    case '3':
        break;
        default:  //输入验证
        for(i = 0; i < 5; i++)
        {
            SetPosition(MARGIN_X + 27, 8 + i);
            printf("                       ");
        }
        SetPosition(MARGIN_X + 20, 9);
        printf("对不起，只能输入1~3之间的数字，请您重新输入！");
        Sleep(1500);
    }
}


