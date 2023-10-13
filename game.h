#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#define HANG 10//���̵���
#define LIE 10//���̵���
//extern char currentplayer;//�������ķ���
//��ʼ������
void initQipan(char qipan[HANG ][LIE ], int hang, int lie);

//��ӡ����
void printQipan(char qipan[HANG ][LIE ], int hang, int lie);
void printQipan2(char qipan[HANG][LIE], int hang, int lie);//AI�������ʾ���

//����������ж��Ⱥ���
char  determinePlayerOrder();

//��ʾ�Ⱥ�����Ϣ
void isPlayerTurn(char currentplayer);

//�������
 void playerMove(char qipan[HANG][LIE], int hang, int lie,char currentplayer);

 //����Ai����
 void computerMove(char qipan[HANG][LIE], int hang, int lie, char currentplayer);
 
 //�߼�Ai����
 void findBestMove(char qipan[HANG][LIE], int hang, int lie, int move[HANG * LIE][1], char currentplayer, char win_positions[5][2]);
 
 //�ж������Ӯ
 int checkWin(char qipan[HANG][LIE], int hang, int lie, int win_positions[5][2]);

 //mvp���㻭�溯��
 void mvp(char qipan[HANG][LIE], int hang, int lie, char currentplayer, int win_posutions[5][2]);
 
 //�ж���Ϸ����
 void game_over(char qipan[HANG][LIE], int win_positions[5][2], char currentplayer);
 
 //�����÷ֺ���
 int levelScore(char qipan[HANG][LIE], int hang, int lie, char compucurrent);

 //����С����
 int minimax(char qipan[HANG][LIE], int hang, int lie, int depth, char currentplayer, char win_positions[5][2], int maximizingPlayer);

 //AI�����Ĵ�ӡ����
 void printQipan2(char qipan[HANG][LIE], int hang, int lie);

 //�ж���һ�����ӣ��������AI�����ӣ�������ҵ�����
 char isindex(char currentplayer);

 //��ȡ�ո�λ�ò��ҷ��ص�ǰ�ո���
 int getvailcount(char qipan[HANG][LIE], int hang, int lie);

 //��ȡ�ո������
 void getvailMove(char qipan[HANG][LIE], int hang, int lie, int move[HANG * LIE][1]);

 //�ڸÿո�����
 void make_move(char qipan[HANG][LIE], char currentplayer, int move[HANG * LIE][1], int k);

 //����Ŀǰ����״̬,����һ����ʱ����
 void ctrl_s(char qipan[HANG][LIE], int hang, int lie);


 //�����������
 void undo_move(char qipan[HANG][LIE], int hang, int lie);