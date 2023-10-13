#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#define HANG 10//棋盘的行
#define LIE 10//棋盘的列
//extern char currentplayer;//玩家下棋的符号
//初始化棋盘
void initQipan(char qipan[HANG ][LIE ], int hang, int lie);

//打印棋盘
void printQipan(char qipan[HANG ][LIE ], int hang, int lie);
void printQipan2(char qipan[HANG][LIE], int hang, int lie);//AI下棋后提示玩家

//生成随机数判断先后手
char  determinePlayerOrder();

//提示先后手信息
void isPlayerTurn(char currentplayer);

//玩家下棋
 void playerMove(char qipan[HANG][LIE], int hang, int lie,char currentplayer);

 //初级Ai下棋
 void computerMove(char qipan[HANG][LIE], int hang, int lie, char currentplayer);
 
 //高级Ai下棋
 void findBestMove(char qipan[HANG][LIE], int hang, int lie, int move[HANG * LIE][1], char currentplayer, char win_positions[5][2]);
 
 //判断玩家输赢
 int checkWin(char qipan[HANG][LIE], int hang, int lie, int win_positions[5][2]);

 //mvp结算画面函数
 void mvp(char qipan[HANG][LIE], int hang, int lie, char currentplayer, int win_posutions[5][2]);
 
 //判断游戏结束
 void game_over(char qipan[HANG][LIE], int win_positions[5][2], char currentplayer);
 
 //评估得分函数
 int levelScore(char qipan[HANG][LIE], int hang, int lie, char compucurrent);

 //极大极小搜索
 int minimax(char qipan[HANG][LIE], int hang, int lie, int depth, char currentplayer, char win_positions[5][2], int maximizingPlayer);

 //AI下棋后的打印棋盘
 void printQipan2(char qipan[HANG][LIE], int hang, int lie);

 //判断另一方棋子，传入的是AI的棋子，返回玩家的棋子
 char isindex(char currentplayer);

 //获取空格位置并且返回当前空格数
 int getvailcount(char qipan[HANG][LIE], int hang, int lie);

 //获取空格的坐标
 void getvailMove(char qipan[HANG][LIE], int hang, int lie, int move[HANG * LIE][1]);

 //在该空格下子
 void make_move(char qipan[HANG][LIE], char currentplayer, int move[HANG * LIE][1], int k);

 //保存目前棋盘状态,存入一个临时数组
 void ctrl_s(char qipan[HANG][LIE], int hang, int lie);


 //撤销下棋操作
 void undo_move(char qipan[HANG][LIE], int hang, int lie);