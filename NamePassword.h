#ifndef NAMEPASSWORD_H_INCLUDED
#define NAMEPASSWORD_H_INCLUDED

/*********************************************
 * 文件名：NamePassword.h
 * 描  述：用来定义学生信息管理系统用户登陆
 * 创建人：CANJIE
 * 日  期：2017-4-27
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameLib.h"

#define USER_NAME "powerful"
#define PASSWORD "00000000"

void ShowLogin();  //登陆界面
int Login();  //用户名与密码的输入
int veriLogin(char [], char []);  //用户名与密码输入验证
void MyFgets(char *, int);  //接受用户名和密码

#endif // NAMEPASSWORD_H_INCLUDED
