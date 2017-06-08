
/*********************************************
 * 文件名：InfoInput.c
 * 描  述：完整实现了学生信息录入模块（包括学生信息的录入、删除以及返回主菜单）
 * 创建人：CANJIE
 * 日  期：2017-5-22
 *********************************************/

#include "InfoInput.h"

extern StuInfo student[N];
extern int count;


/* 显示录入信息功能界面并进行选择 */
void ShowInfoInput()
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
        printf("1、学生信息录入");
        SetPosition(MARGIN_X + 27, 11);
        printf("2、学生信息删除");
        SetPosition(MARGIN_X + 27, 12);
        printf("3、返回主菜单");
        if((choice = getch()) == '3')
            break;
        ProcessInfoInput(choice);
    }
}

/* 学生信息录入函数 */
void InfoInput()
{
    int i;
    ReadInfo();
    StuInfo *p = student + count;  //指针指向数组末尾，即将新增信息添加到数组最后一个学生信息的后面
    ShowOne();

    fflush(stdin);
    SetPosition(MARGIN_X + 35, 8);
    MyFgets(p->prof, 50);                  //专业输入
    SetPosition(MARGIN_X + 35, 9);
    MyFgets(p->name, 50);                  //姓名输入
    SetPosition(MARGIN_X + 35, 10);
    MyFgets(p->sex, 50);                   //性别输入
    SetPosition(MARGIN_X + 35, 11);
    scanf("%d", &(p->clas));               //班级输入
    SetPosition(MARGIN_X + 35, 12);
    scanf("%ld", &(p->num));                //学号输入
    SetPosition(MARGIN_X + 37, 13);
    scanf("%d", &(p->math_score));         //数学成绩输入
    SetPosition(MARGIN_X + 37, 14);
    scanf("%d", &(p->Eng_score));          //英语成绩输入
    fflush(stdin);

    for(i = 0; i < 8; i++)
    {
        SetPosition(MARGIN_X + 28, 8 + i);
        printf("                              ");
    }
    SetPosition(MARGIN_X + 24, 10);
    printf("恭喜，《%s》同学的个人信息录入成功！", p->name);
    count++;  //学生有效数量+1
    WriteInfo();  //将学生信息写入文件中
    SetPosition(MARGIN_X + 26, 11);
    printf("    目前数据库中有%d位学生的信息", count);  //测试代码
    p = student;
    Sleep(1000);
}

/* 学生信息删除函数 */
void InfoDel()
{
    int i, j, k;
    ReadInfo();
    ShowTwo();
    StuInfo *p = student;  //指针指向数组中第一名学生的信息
    int num;  //要删除的学号
    char name[50];  //要删除的姓名

    SetPosition(MARGIN_X + 38, 11);
    fflush(stdin);
    scanf("%ld", &num);  //学号的输入
    fflush(stdin);  //输入后清空缓存，防止回车键录入字符串
    SetPosition(MARGIN_X + 38, 12);
    MyFgets(name, 50);    //姓名的输入
    fflush(stdin);

    for(i = 0; i < count; i++, p++)
    {
        if((num == p->num) && (strcmp(name, p->name) == 0))  //如果姓名与学号都输入正确
        {
            if(i == count - 1)  //要删除的学生为最后一位
            {
                break;
            }
            else  //要删除的学生不为最后一位，则将后一位取代前一位
            {
                for(j = i; j < count - 1; j++)
                {
                    student[j] = student[j + 1];
                }
                break;
            }
        }
    }
    for(k = 0; k < 8; k++)  //清屏
    {
        SetPosition(MARGIN_X + 28, 8 + k);
        printf("                              ");
    }

    if(i == count)  //没有找到这个人
    {
        //printf("%d", count);  //测试代码
        SetPosition(MARGIN_X + 32, 11);
        printf("删除失败，没有找到这个人！");
    }
    else  //找到了
    {
        SetPosition(MARGIN_X + 36, 11);
        printf("恭喜，删除成功！");
        count--;  //学生有效数量-1
        //printf("%d", count);  //测试代码
    }
    WriteInfo();  //将删除后的学生信息写入文件中
    p = student;
    Sleep(1000);
}

/* 功能选择的实现 */
void ProcessInfoInput(char choice)
{
    int i;

    switch(choice)
    {
    case '1':  //学生信息的录入
        InfoInput();
        break;
    case '2':  //学生信息删除
        InfoDel();
        break;
    case '3':  //返回主菜单
        break;
    default:  //输入验证
        for(i = 0; i < 5; i++)
        {
            SetPosition(MARGIN_X + 27, 8 + i);
            printf("                       ");
        }
        SetPosition(MARGIN_X + 25, 9);
        printf("对不起，只能输入1~3之间的数字！");
        SetPosition(MARGIN_X + 32, 10);
        printf("请按任意键返回...");
        getch();
    }
}

/* 选项1的界面 */
void ShowOne()
{
    int i;
    for(i = 0; i < 5; i++)
    {
        SetPosition(MARGIN_X + 27, 8 + i);
        printf("                      ");
    }
    SetPosition(MARGIN_X + 20, 4);
    printf("%s", A);
    SetPosition(MARGIN_X + 20, 6);
    printf("%s", A);
    for(i = 0; i < 12; i++)
    {
        SetPosition(MARGIN_X + 20, 5 + i);
        printf("|");
        SetPosition(MARGIN_X + 65, 5 + i);
        printf("|");
    }
    SetPosition(MARGIN_X + 20, 16);
    printf("%s", A);
    SetPosition(MARGIN_X + 36, 5);
    printf("学生信息录入");
    SetPosition(MARGIN_X + 27, 8);
    printf("专  业：");
    SetPosition(MARGIN_X + 27, 9);
    printf("姓  名：");
    SetPosition(MARGIN_X + 27, 10);
    printf("性  别：");
    SetPosition(MARGIN_X + 27, 11);
    printf("班  级：");
    SetPosition(MARGIN_X + 27, 12);
    printf("学  号：");
    SetPosition(MARGIN_X + 27, 13);
    printf("数学成绩：");
    SetPosition(MARGIN_X + 27, 14);
    printf("英语成绩：");
}

/* 选项2的界面 */
void ShowTwo()
{
    int i;
    for(i = 0; i < 5; i++)
    {
        SetPosition(MARGIN_X + 27, 8 + i);
        printf("                      ");
    }
    SetPosition(MARGIN_X + 20, 4);
    printf("%s", A);
    SetPosition(MARGIN_X + 20, 6);
    printf("%s", A);
    for(i = 0; i < 12; i++)
    {
        SetPosition(MARGIN_X + 20, 5 + i);
        printf("|");
        SetPosition(MARGIN_X + 65, 5 + i);
        printf("|");
    }
    SetPosition(MARGIN_X + 20, 16);
    printf("%s", A);
    SetPosition(MARGIN_X + 36, 5);
    printf("学生信息删除");
    SetPosition(MARGIN_X + 30, 8);
    printf("请输入您要删除的姓名与学号");
    SetPosition(MARGIN_X + 32, 11);
    printf("学号：");
    SetPosition(MARGIN_X + 32, 12);
    printf("姓名：");
}

