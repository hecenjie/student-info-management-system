#include "ShowPoints.h"

extern StuInfo student[N];
extern int count;

//界面
void IDfind()
{
    char choice;
	int i;
	for(i = 0; i < 7; i++)
    {
        SetPosition(MARGIN_X, 21 + i);
        printf("                             ");
    }
    while(1)
    {
        ClearTotal();
        SetPosition(MARGIN_X + 27, 8);
        printf("请选择您要进行的操作：");
        SetPosition(MARGIN_X + 27, 10);
        printf("1、输入学号");
        SetPosition(MARGIN_X + 27, 11);
        printf("2、返回主菜单");
        if((choice = getch()) == '2')
            break;
        IDmenu(choice);//引用界面选择功能的函数
    }
}

//查找成绩的函数
void IDfind0()
{
    char choice;
    ReadInfo();
    int i, index = -1;
	int total;
    int num;
    StuInfo *p = student;
    for(i = 0; i < 7; i++)
    {
        SetPosition(MARGIN_X  +6, 6 + i);
        printf("                                                 ");
    }
    SetPosition(MARGIN_X + 26, 9);
    printf("   请输入学生学号:");
	scanf("%d", &num);
	for(i = 0; i < count; i++, p++)
    {
		if(num == p->num)
        {
			index = i;
			break;
		}

    }
	if(index<0)
    {
        SetPosition(MARGIN_X + 25, 9);
        printf("                   ");
        SetPosition(MARGIN_X + 25, 9);
        printf("    对不起，没有找到该学生信息！               ");
        SetPosition(MARGIN_X + 35, 10);
        printf("请按任意键返回...");
        getch();

	}
	else
	{
        while(1)
        {


        ClearTotal();
		total = p->math_score + p->Eng_score;
        SetPosition(MARGIN_X + 6, 6);
		printf("-----------------------------------------------------------------------");
        SetPosition(MARGIN_X + 6,7);
		printf("专业:%s", p->prof);
        SetPosition(MARGIN_X + 6,8);
		printf("姓名:%s", p->name);
        SetPosition(MARGIN_X + 6,9);
        printf("性别:%s", p->sex);
        SetPosition(MARGIN_X + 6,10);
        printf("班级:%d", p->clas);
        SetPosition(MARGIN_X + 6,11);
        printf("学号:%.0ld", p->num);
        SetPosition(MARGIN_X + 6,12);
        printf("数学成绩:%d", p->math_score);
        SetPosition(MARGIN_X + 6,13);
        printf("英语成绩:%d", p->Eng_score);
        SetPosition(MARGIN_X + 6,14);
        printf("总分:%d", total );
		SetPosition(MARGIN_X + 6,15);
		printf("-----------------------------------------------------------------------");
		SetPosition(MARGIN_X + 6,16);
		printf("按0返回菜单");
		if((choice = getch()) == '0')
           {
             break;
           }

        IDfind();//引用界面选择功能的函数

	}
	}


	for(i = 0; i < 7; i++)
    {
        SetPosition(MARGIN_X  +6, 6 + i);
        printf("                                                                          ");
    }
}


//界面选择功能函数
void IDmenu(char choice)
{
    int i;

    switch(choice)
    {
    case '1':  //查找学生的函数
        IDfind0();
        break;
    case '2':
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

