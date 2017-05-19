#include "ReadInfo.h"

/*********************************************
 * �ļ�����ReadInfo.c
 * ��  ������������ϵͳ���ļ��Ķ�ȡ��д��
 * �����ˣ�CANJIE
 * ��  �ڣ�2017-5-17
 *
 *********************************************/

StuInfo student[N];  //��N��Ҳ����50�����ռ���ѧ������
int count;  //ѧ����Ч����

/* ���ڲ���ѧ����Ϣ�ܷ�д���ļ�
StuInfo student[N] = {
    {"������Ϣ��ѧ�뼼��", "С��", "��", 164, 32316415, 84, 85},
    {"������Ϣ��ѧ�뼼��", "С��", "��", 164, 32316415, 84, 85},
    {"������Ϣ��ѧ�뼼��", "С��", "��", 164, 32316415, 84, 85},
};
*/

void ReadInfo()
{
    FILE *fp;
    int i;
    count = 0;
    StuInfo *p = student;  //֮��ɶ�p������p��ַ�ƶ���ͨ��student�ָ�����

    if((fp = fopen("student_info.txt", "r")) == NULL)  //������ļ�ʧ��
    {
        printf("���ļ�ʧ�ܣ��밴������˳���");
        getch();
        exit(1);
    }

    for(i = 0; i < N; i++, p++)
    {
        fscanf(fp, "%s %s %s %d %d %d %d", p->prof, p->name, p->sex, &(p->clas), &(p->num), &(p->math_score), &(p->Eng_score));
        if(p->clas != 0)  //����༶���벻Ϊ0
            count++;      //ѧ����Ч����+1
        else
            break;        //����ѭ����ֹͣ¼��
    }
    p = student;  //��p�ָ�

    /*���´������ڲ����ļ���Ϣ¼���Ƿ�ɹ�
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

    if((fp = fopen("student_info.txt", "w+")) == NULL)  //������ļ�ʧ��
    {
        printf("���ļ�ʧ�ܣ��밴������˳���");
        getch();
        exit(1);
    }

    for(i = 0; i < count; i++, p++)
    {
        fprintf(fp, "%s %s %s %d %d %d %d\n", p->prof, p->name, p->sex, p->clas, p->num, p->math_score, p->Eng_score);
    }
}
















