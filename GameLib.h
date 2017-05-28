#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED

/*********************************************
 * 文件名：GameLib.h
 * 描  述：用来定义学生信息管理系统中常用的系统操作（更改文字颜色、清屏等）
 * 创建人：CANJIE
 * 日  期：2017-4-27
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define SEP "-----------------------------------------------------------------------------------"
#define MARGIN_X 20  //左边距

/* 设置控制台窗口的标题 */
void SetTitle(char *title);
/* 设置文字的前景色和背景色 */
void SetColor(int foreColor, int backColor);
/* 设置光标的位置 */
void SetPosition(int x, int y);
/* 显示系统的欢迎信息 */
void ShowWelcome();
/* 显示欢迎界面下方信息 */
void ShowInfomation();
/* 显示用户菜单 */
void ShowMainMenu();
/* 完整清屏 */
void ClearTotal();
/* 部分清屏 */
void ClearPart();

#endif // GAMELIB_H_INCLUDED
