/*********************************************
 * 文件名：RankingQuery.c
 * 描  述：实现了学生成绩排行榜的查看（包括总成绩排行榜、单科成绩排行榜）
 * 创建人：CANJIE
 * 日  期：2017-5-30
 *********************************************/

#include "RankingQuery.h"

extern StuInfo student[N];
extern int count;

/* 选择总排行、单科排行界面 */
void RankingShowOne()
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
        ClearPart();
        SetPosition(MARGIN_X + 27, 8);
        printf("请选择您要查看的内容：");
        SetPosition(MARGIN_X + 27, 10);
        printf("1、总成绩排行榜");
        SetPosition(MARGIN_X + 27, 11);
        printf("2、单科成绩排行榜");
        SetPosition(MARGIN_X + 27, 12);
        printf("3、返回主菜单");
        if((choice = getch()) == '3')
            break;
        ProcessRankingQuery(choice);
    }
}

/* 功能选择的实现 */
void ProcessRankingQuery(char choice)
{
    switch(choice)
    {
    case '1':  //总成绩排行榜
        RankingTotal();
        break;
    case '2':  //单科成绩排行榜
        RankingPart();
        break;
    case '3':  //返回主菜单
        break;
    default:  //输入验证
        ClearPart();
        SetPosition(MARGIN_X + 25, 9);
        printf("对不起，只能输入1~3之间的数字！");
        SetPosition(MARGIN_X + 32, 10);
        printf("请按任意键返回...");
        getch();
    }
}

/* 总成绩排行榜的实现 */
void RankingTotal()
{
    int i, j;
    int rank = 1;  //排名
    int page = 1;  //页数
    int page_max = count / 28 + 1;  //最大页数
    char key;  //用户按的左右按键

    ReadInfo();  //读取学生信息到数组中
    StuInfo *p = student;
    StuInfo temp;

    for(i = 0; i < 5; i++)
    {
        SetPosition(MARGIN_X + 27, 8 + i);
        printf("                       ");
    }
    for(i = 0; i < count - 1; i++)  //冒泡排序
    {
        p = student;
        for(j = 0; j < count - 1 - i; j++, p++)
        {
            if(((p->Eng_score)+(p->math_score)) < (((p+1)->Eng_score)+((p+1)->math_score)))
            {
                temp = *p;
                *p = *(p+1);
                *(p+1) = temp;
            }
        }
    }
    p = student;  //将p指回数组起始

    while(1)
    {
        RankingShowTwo();  //显示分割线、科目名称等的界面元素
        rank = 1 + (page-1) * 28;  //设置每一页的起始排名
        if(page != page_max)  //不为最后一页的情况
        {
            for(i = 0, j = 1; i < 28; i++, p++, j++)
            {
                if(i < 14)
                {
                    SetPosition(MARGIN_X + 4, 4 + j);  //前半部分
                }
                else
                {
                    if(i == 14)
                        j = 1;
                    SetPosition(MARGIN_X + 45, 4 + j);  //后半部分
                }
                printf("%-6d%-10s%-6d%-7d%-6d", rank++, p->name, p->Eng_score, p->math_score, (p->Eng_score) + (p->math_score));
            }
            p = student + (page-1) * 28;  //置回指针p的指向
        }
        else  //如果为最后一页
        {
            for(i = 0, j = 1; i < count - (page-1) * 28; i++, p++, j++)  //i设置为只能打印到已有的学生数量
            {
                if(i < 14)
                {
                    SetPosition(MARGIN_X + 4, 4 + j);
                }
                else
                {
                    if(i == 14)
                        j = 1;
                    SetPosition(MARGIN_X + 45, 4 + j);
                }
                printf("%-6d%-10s%-6d%-7d%-6d", rank++, p->name, p->Eng_score, p->math_score, (p->Eng_score) + (p->math_score));
            }
            for( ; i < 28; i++, j++)  //将前一页留下的垃圾信息清除
            {
                if(i < 14)
                {
                    SetPosition(MARGIN_X + 4, 4 + j);
                }
                else
                {
                    if(i == 14)
                        j = 1;
                    SetPosition(MARGIN_X + 45, 4 + j);
                }
                printf("                                   ");
            }
            p = student + (page-1) * 28;  //置回指针p的指向
        }
        SetPosition(MARGIN_X + 72, 21);
        printf("页数：%d/%d\n", page, page_max);
        SetPosition(MARGIN_X + 67, 22);
        printf("(按z键返回菜单)");
        //printf("学生总数：%d", count);
        key = getch();
        if(key == 75)  //左键
        {
            page--;
            if(page < 1)
            {
                page = 1;  //如果在第一页按左键则无效
            }
            p = student + (page-1) * 28;
        }
        else if(key == 77)  //右键
        {
            page++;
            if(page > page_max)
            {
                page = page_max;  //如果在最后一页按右键则无效
            }
            p = student + (page-1) * 28;
        }
        else if(key == 'z')
        {
            ClearTotal();
            break;
        }
        ClearTotal();
    }
    for(i = 0; i < 2; i++)
    {
        SetPosition(MARGIN_X + 64, 21 + i);
        printf("                  ");
    }
}

/* 分割线、科目名称等的界面元素显示 */
void RankingShowTwo()
{
    int i;

    for(i = 0; i < 17; i++)
    {
        SetPosition(MARGIN_X + 40, 3 + i);
        printf("|");
    }
    SetPosition(MARGIN_X + 4, 3);
    printf("排名   姓名\t英语  数学  总成绩");
    SetPosition(MARGIN_X + 45, 3);
    printf("排名   姓名\t英语  数学  总成绩");
}

/* 选择英语排行、数学排行界面 */
void RankingPart()
{
    char choice;

    while(1)
    {
        ClearPart();
        SetPosition(MARGIN_X + 27, 8);
        printf("请选择您要查看的内容：");
        SetPosition(MARGIN_X + 27, 10);
        printf("1、数学成绩排行榜");
        SetPosition(MARGIN_X + 27, 11);
        printf("2、英语成绩排行榜");
        SetPosition(MARGIN_X + 27, 12);
        printf("3、返回上级菜单");
        if((choice = getch()) == '3')
            break;
        ProcessRankingPart(choice);
    }
}

/* 功能选择的实现 */
void ProcessRankingPart(char choice)
{
    switch(choice)
    {
    case '1':  //数学成绩排行榜
        RankingMath();
        break;
    case '2':  //英语成绩排行榜
        RankingEng();
        break;
    case '3':  //返回主菜单
        break;
    default:  //输入验证
        ClearPart();
        SetPosition(MARGIN_X + 25, 9);
        printf("对不起，只能输入1~3之间的数字！");
        SetPosition(MARGIN_X + 32, 10);
        printf("请按任意键返回...");
        getch();
    }
}

/* 数学成绩排行榜的实现 */
void RankingMath()
{
    int i, j;
    int rank = 1;  //排名
    int page = 1;  //页数
    int page_max = count / 28 + 1;  //最大页数
    char key;  //用户按的左右按键

    ReadInfo();  //读取学生信息到数组中
    StuInfo *p = student;
    StuInfo temp;

    for(i = 0; i < 5; i++)
    {
        SetPosition(MARGIN_X + 27, 8 + i);
        printf("                       ");
    }
    for(i = 0; i < count - 1; i++)  //冒泡排序
    {
        p = student;
        for(j = 0; j < count - 1 - i; j++, p++)
        {
            if(p->math_score < (p+1)->math_score)
            {
                temp = *p;
                *p = *(p+1);
                *(p+1) = temp;
            }
        }
    }
    p = student;  //将p指回数组起始

    while(1)
    {
        RankingShowTwo();  //显示分割线、科目名称等的界面元素
        rank = 1 + (page-1) * 28;  //设置每一页的起始排名
        if(page != page_max)  //不为最后一页的情况
        {
            for(i = 0, j = 1; i < 28; i++, p++, j++)
            {
                if(i < 14)
                {
                    SetPosition(MARGIN_X + 4, 4 + j);  //前半部分
                }
                else
                {
                    if(i == 14)
                        j = 1;
                    SetPosition(MARGIN_X + 45, 4 + j);  //后半部分
                }
                printf("%-6d%-10s%-6d%-7d%-6d", rank++, p->name, p->Eng_score, p->math_score, (p->Eng_score) + (p->math_score));
            }
            p = student + (page-1) * 28;  //置回指针p的指向
        }
        else  //如果为最后一页
        {
            for(i = 0, j = 1; i < count - (page-1) * 28; i++, p++, j++)  //i设置为只能打印到已有的学生数量
            {
                if(i < 14)
                {
                    SetPosition(MARGIN_X + 4, 4 + j);
                }
                else
                {
                    if(i == 14)
                        j = 1;
                    SetPosition(MARGIN_X + 45, 4 + j);
                }
                printf("%-6d%-10s%-6d%-7d%-6d", rank++, p->name, p->Eng_score, p->math_score, (p->Eng_score) + (p->math_score));
            }
            for( ; i < 28; i++, j++)  //将前一页留下的垃圾信息清除
            {
                if(i < 14)
                {
                    SetPosition(MARGIN_X + 4, 4 + j);
                }
                else
                {
                    if(i == 14)
                        j = 1;
                    SetPosition(MARGIN_X + 45, 4 + j);
                }
                printf("                                   ");
            }
            p = student + (page-1) * 28;  //置回指针p的指向
        }
        SetPosition(MARGIN_X + 72, 21);
        printf("页数：%d/%d\n", page, page_max);
        SetPosition(MARGIN_X + 67, 22);
        printf("(按z键返回菜单)");
        //printf("学生总数：%d", count);
        key = getch();
        if(key == 75)  //左键
        {
            page--;
            if(page < 1)
            {
                page = 1;  //如果在第一页按左键则无效
            }
            p = student + (page-1) * 28;
        }
        else if(key == 77)  //右键
        {
            page++;
            if(page > page_max)
            {
                page = page_max;  //如果在最后一页按右键则无效
            }
            p = student + (page-1) * 28;
        }
        else if(key == 'z')
        {
            ClearTotal();
            break;
        }
        ClearTotal();
    }
    for(i = 0; i < 2; i++)
    {
        SetPosition(MARGIN_X + 64, 21 + i);
        printf("                  ");
    }
}

/* 英语成绩排行榜的实现 */
void RankingEng()
{
    int i, j;
    int rank = 1;  //排名
    int page = 1;  //页数
    int page_max = count / 28 + 1;  //最大页数
    char key;  //用户按的左右按键

    ReadInfo();  //读取学生信息到数组中
    StuInfo *p = student;
    StuInfo temp;

    for(i = 0; i < 5; i++)
    {
        SetPosition(MARGIN_X + 27, 8 + i);
        printf("                       ");
    }
    for(i = 0; i < count - 1; i++)  //冒泡排序
    {
        p = student;
        for(j = 0; j < count - 1 - i; j++, p++)
        {
            if(p->Eng_score < (p+1)->Eng_score)
            {
                temp = *p;
                *p = *(p+1);
                *(p+1) = temp;
            }
        }
    }
    p = student;  //将p指回数组起始

    while(1)
    {
        RankingShowTwo();  //显示分割线、科目名称等的界面元素
        rank = 1 + (page-1) * 28;  //设置每一页的起始排名
        if(page != page_max)  //不为最后一页的情况
        {
            for(i = 0, j = 1; i < 28; i++, p++, j++)
            {
                if(i < 14)
                {
                    SetPosition(MARGIN_X + 4, 4 + j);  //前半部分
                }
                else
                {
                    if(i == 14)
                        j = 1;
                    SetPosition(MARGIN_X + 45, 4 + j);  //后半部分
                }
                printf("%-6d%-10s%-6d%-7d%-6d", rank++, p->name, p->Eng_score, p->math_score, (p->Eng_score) + (p->math_score));
            }
            p = student + (page-1) * 28;  //置回指针p的指向
        }
        else  //如果为最后一页
        {
            for(i = 0, j = 1; i < count - (page-1) * 28; i++, p++, j++)  //i设置为只能打印到已有的学生数量
            {
                if(i < 14)
                {
                    SetPosition(MARGIN_X + 4, 4 + j);
                }
                else
                {
                    if(i == 14)
                        j = 1;
                    SetPosition(MARGIN_X + 45, 4 + j);
                }
                printf("%-6d%-10s%-6d%-7d%-6d", rank++, p->name, p->Eng_score, p->math_score, (p->Eng_score) + (p->math_score));
            }
            for( ; i < 28; i++, j++)  //将前一页留下的垃圾信息清除
            {
                if(i < 14)
                {
                    SetPosition(MARGIN_X + 4, 4 + j);
                }
                else
                {
                    if(i == 14)
                        j = 1;
                    SetPosition(MARGIN_X + 45, 4 + j);
                }
                printf("                                   ");
            }
            p = student + (page-1) * 28;  //置回指针p的指向
        }
        SetPosition(MARGIN_X + 72, 21);
        printf("页数：%d/%d\n", page, page_max);
        SetPosition(MARGIN_X + 67, 22);
        printf("(按z键返回菜单)");
        //printf("学生总数：%d", count);
        key = getch();
        if(key == 75)  //左键
        {
            page--;
            if(page < 1)
            {
                page = 1;  //如果在第一页按左键则无效
            }
            p = student + (page-1) * 28;
        }
        else if(key == 77)  //右键
        {
            page++;
            if(page > page_max)
            {
                page = page_max;  //如果在最后一页按右键则无效
            }
            p = student + (page-1) * 28;
        }
        else if(key == 'z')
        {
            ClearTotal();
            break;
        }
        ClearTotal();
    }
    for(i = 0; i < 2; i++)
    {
        SetPosition(MARGIN_X + 64, 21 + i);
        printf("                  ");
    }
}


