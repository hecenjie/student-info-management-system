#ifndef RANKINGQUERY_H_INCLUDED
#define RANKINGQUERY_H_INCLUDED

/*********************************************
 * 文件名：RankingQuery.h
 * 描  述：实现了学生成绩排行榜的查看（包括总成绩排行榜、单科成绩排行榜）
 * 创建人：CANJIE
 * 日  期：2017-5-30
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "GameLib.h"
#include "ReadInfo.h"

/* 选择总排行、单科排行界面 */
void RankingShowOne();
/* 功能选择的实现 */
void ProcessRankingQuery(char);
/* 总成绩排行榜 */
void RankingTotal();
/* 分割线、科目名称等的界面元素 */
void RankingShowTwo();
/* 数学排名、英语排名选项 */
void RankingPart();
/* 功能选择的实现 */
void ProcessRankingPart(char choice);
/* 数学成绩排行榜 */
void RankingMath();
/* 英语成绩排行榜 */
void RankingEng();


#endif // RANKINGQUERY_H_INCLUDED
