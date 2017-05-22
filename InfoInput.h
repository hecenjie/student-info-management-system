#ifndef INFOINPUT_H_INCLUDED
#define INFOINPUT_H_INCLUDED

/*********************************************
 * 文件名：InfoInput.h
 * 描  述：完整实现了学生信息录入模块（包括学生信息的录入、删除以及返回主菜单）
 * 创建人：CANJIE
 * 日  期：2017-5-22
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "GameLib.h"
#include "NamePassword.h"
#include "ReadInfo.h"
#define A "----------------------------------------------"
#define B "--------------------------------------------"

/* 显示录入信息功能界面并进行选择 */
void ShowInfoInput();
/* 功能选择的实现 */
void ProcessInfoInput(char);
/* 学生信息录入函数 */
void InfoInput();
/* 选项1的界面 */
void ShowOne();
/* 学生信息删除函数 */
void InfoDel();
/* 选项2的界面 */
void ShowTwo();

#endif // INFOINPUT_H_INCLUDED
