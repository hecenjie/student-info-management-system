#ifndef PLAYMUSIC_H_INCLUDED
#define PLAYMUSIC_H_INCLUDED

/*********************************************
 * 文件名：PlayMusic.h
 * 描  述：实现了单曲播放、停止以及歌词的展现（仅含有校歌）
 * 创建人：CANJIE
 * 日  期：2017-5-30
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#include "GameLib.h"
#pragma comment(lib,"Winmm.lib")

/* 播放音乐 */
void music();
/* 歌词 */
void Lyrics();

#endif // PLAYMUSIC_H_INCLUDED
