#include "ReadInfo.h"

/*********************************************
 * 文件名：ReadInfo.h
 * 描  述：用来定义系统对文件的读取、写入，并定义了学生信息结构体StuInfo，数组student长度为N（即50），
 * 以及记录学生有效数量的全局变量count。
 * 创建人：CANJIE
 * 日  期：2017-5-17
 *
 *********************************************/

StuInfo student[N];  //给N（也就是50）个空间存放学生数量
int count;  //学生有效数量

/* 用于测试学生信息能否写入文件
StuInfo student[N] = {
    {"电子信息科学与技术", "小明", "男", 164, 32316415, 84, 85},
    {"电子信息科学与技术", "小兰", "男", 164, 32316415, 84, 85},
    {"电子信息科学与技术", "小环", "男", 164, 32316415, 84, 85},
};
*/

void ReadInfo()
{
    FILE *fp;
    int i;
    count = 0;
    StuInfo *p = student;  //之后可对p操作，p地址移动后通过student恢复即可

    if((fp = fopen("student_info.dat", "r")) == NULL)  //如果打开文件失败
    {
        printf("打开文件失败，请按任意键退出！");
        getch();
        exit(1);
    }

    for(i = 0; i < N; i++, p++)
    {
        fscanf(fp, "%s %s %s %d %ld %d %d", p->prof, p->name, p->sex, &(p->clas), &(p->num), &(p->math_score), &(p->Eng_score));
        if(p->clas != 0)  //如果班级号码不为0
            count++;      //学生有效数量+1
        else
            break;        //跳出循环，停止录入
    }
    p = student;  //将p恢复
    fclose(fp);  //关闭文件

    /*以下代码用于测试文件信息录入是否成功
    for(i = 0; i < count; i++, p++)
    {
        printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\n", p->prof, p->name, p->sex, p->clas, p->num, p->math_score, p->Eng_score);
    }
    */
}

void WriteInfo()
{
    FILE *fp;
    int i;
    StuInfo *p = student;

    if((fp = fopen("student_info.dat", "w+")) == NULL)  //如果打开文件失败
    {
        printf("打开文件失败，请按任意键退出！");
        getch();
        exit(1);
    }

    for(i = 0; i < count; i++, p++)
    {
        fprintf(fp, "%s %s %s %d %ld %d %d\n", p->prof, p->name, p->sex, p->clas, p->num, p->math_score, p->Eng_score);
    }

    fclose(fp);  //关闭文件
}

















