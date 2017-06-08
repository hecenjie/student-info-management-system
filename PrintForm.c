#include "PrintForm.h"
/*********************************************
 * 文件名：PrintForm.h
 * 描  述：用来显示学生所打印的表报所有信息
 * 创建人：ZHOU
 * 日  期：2017-5-22
 *********************************************/


 extern StuInfo student[N] ;
 extern int count;
 int n ; //记录所查学生信息

 /* 输入所打印学生报表的学号并查询该学生信息*/
void  InputSearch()
{
   int i, j, num, a , b, c ;
   char name[50] ,choice;
   ReadInfo();
   StuInfo *p = student;
   StuInfo temp;
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
                printf("                                                    ");//清屏
            }
            SetPosition(MARGIN_X + 31, 9);
            printf("请输入您的姓名与学号");
            SetPosition(MARGIN_X + 31, 11);
            printf("姓名：");
            SetPosition(MARGIN_X + 31, 13);
            printf("学号：");
            SetPosition(MARGIN_X + 37, 11);
            fflush(stdin);
            gets( name );
            SetPosition(MARGIN_X + 37, 13);
            fflush(stdin);
            scanf( "%d" , & num );
            for( i = 0 ; i < count ; i++)
            {
                if(student[i].num == num && strcmp(student[i].name,name)==0 )
                {
                   n = i ;
                   a = student[n].math_score ;
                   b = student[n].Eng_score  ;
                   c = student[n].math_score + student[n].Eng_score ;
                   SetPosition(MARGIN_X + 28, 9);
                   printf("                                     ");
                   SetPosition(MARGIN_X + 28, 11);
                   printf("                                     ");
                   SetPosition(MARGIN_X + 28, 13);
                   printf("                                     ");//清屏
                   Sleep(100);
                   SetPosition(MARGIN_X + 27, 5);
                   printf("***************************");
                   SetPosition(MARGIN_X + 29, 6);
                   printf("您 的 数学成绩 为 ：");
                   SetPosition(MARGIN_X + 27, 7);
                   printf("***************************");
                   SetPosition(MARGIN_X + 29, 8);
                   printf("您 的 英语成绩 为 ： ");
                   SetPosition(MARGIN_X + 27, 9);
                   printf("***************************");
                   SetPosition(MARGIN_X + 29, 10);
                   printf("您 的 总 成 绩 为 ： ");
                   SetPosition(MARGIN_X + 27, 11);
                   printf("***************************");
                   SetPosition(MARGIN_X + 29, 12);
                   printf("您的数学成绩排名为： ");
                   SetPosition(MARGIN_X + 27, 13);
                   printf("***************************");
                   SetPosition(MARGIN_X + 29, 14);
                   printf("你的英语成绩排名为： ");
                   SetPosition(MARGIN_X + 27, 15);
                   printf("***************************");
                   SetPosition(MARGIN_X + 29, 16);
                   printf("你的 总成绩 排名为：");
                   SetPosition(MARGIN_X + 27, 17);
                   printf("***************************");
                   fflush(stdin);
                   SetPosition(MARGIN_X + 49, 6);
                   printf("%d",student[n].math_score);
                   SetPosition(MARGIN_X + 49, 8);
                   printf("%d",student[n].Eng_score);
                   SetPosition(MARGIN_X + 49, 10);
                   printf("%d",(student[n].math_score + student[n].Eng_score));

                   SetPosition(MARGIN_X + 49, 12);
                   for(i = 0; i < count - 1; i++)  //冒泡排序
                   {
                      p = student;
                      for(j = 0; j < count - 1 - i; j++, p++)
                      {
                         if((p->math_score) < ((p+1)->math_score))
                         {
                           temp = *p;
                           *p = *(p+1);
                           *(p+1) = temp;
                         }
                      }
                   }
                   p = student;  //将p指回数组起始
                   printf("%d",Search(num));

                   SetPosition(MARGIN_X + 49, 14);
                    for(i = 0; i < count - 1; i++)  //冒泡排序
                   {
                      p = student;
                      for(j = 0; j < count - 1 - i; j++, p++)
                      {
                         if((p->Eng_score) < ((p+1)->Eng_score))
                         {
                           temp = *p;
                           *p = *(p+1);
                           *(p+1) = temp;
                         }
                      }
                   }
                   p = student;  //将p指回数组起始
                   printf("%d",Search(num));

                   SetPosition(MARGIN_X + 49, 16);
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
                   printf("%d",Search(num));

                   SetPosition(MARGIN_X + 50, 19);
                   printf("按z返回主菜单");
                   choice = getch();
                   while(1)//按z退出系统
                   {
                       if(choice=='z')
                      {
                          for(j = 0; j < 13; j++)
                         {
                             SetPosition(MARGIN_X + 19, 4 + i);
                             printf("                                                     ");
                         }
                          break;
                      }
                      else
                      {
                          SetPosition(MARGIN_X + 63, 19);
                          printf("         ");
                          SetPosition(MARGIN_X + 63, 19);
                          choice = getch();
                      }

                  } break;
                }
            }
            if ( i >= count )//学生信息输入错误，重新返回输入界面。
                {
                   SetPosition(MARGIN_X + 28, 9);
                   printf("                                     ");
                   SetPosition(MARGIN_X + 28, 11);
                   printf("                                     ");
                   SetPosition(MARGIN_X + 28, 13);
                   printf("                                     ");//清屏
                   Sleep(300);
                   SetPosition(MARGIN_X + 24, 11);
                   printf("您所查找的信息错误，请重新输入！");
                   Sleep(1000);
                   SetPosition(MARGIN_X + 20, 11);
                   printf("                                              ");
            }
            break;


        }
}



int Search(int a)//查找排名
{
    int i ;
    for(i=0 ; i < count ;i++)
      if(student[i].num == a)
        return (i+1);
}














