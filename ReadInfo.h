#ifndef READINFO_H_INCLUDED
#define READINFO_H_INCLUDED

/*********************************************
 * 文件名：ReadInfo.h
 * 描  述：用来定义系统对文件的读取、写入，并定义了学生信息结构体StuInfo，数组student长度为N（即50），
 * 以及记录学生有效数量的全局变量count。
 * 创建人：CANJIE
 * 日  期：2017-5-17
 *
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "GameLib.h"
#define N 100  //学生有50个

typedef struct _stuinfo{
    char prof[50];  //专业
    char name[50];  //姓名
    char sex[10];   //性别
    int clas;       //班级
    long int num;        //学号
    int math_score; //数学成绩
    int Eng_score;  //英语成绩
}StuInfo;

/* 写入学生信息进入文件函数 */
void WriteInfo();
/* 从文件录入学生信息函数 */
void ReadInfo();


#endif // READINFO_H_INCLUDED
