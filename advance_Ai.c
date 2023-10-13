#include "game.h"

//�ж�ˮƽ�����÷ֵĺ���
int levelScore(char qipan[HANG][LIE], int hang, int lie, char compucurrent) {
    int i, j,k = 0;//�ֱ����У��У��ƶ�������
    int score = 0;//��ʼ���÷�
    int dthings[4][2] = { (0,1),(1,0),(-1,1),(1,1) };//��ʼ����������ֱ��Ӧ���ң����£������ϣ�������ƽ��һ��

    for (int i = 0; i < hang; i++) 
    {
        for (int j = 0; j < lie; j++) {
            if (qipan[i][j] != compucurrent) {
                continue;
            }
            for (int k = 0; k < 4; k++)//������������,����������һ�������߼�����ֱ�����ӳ���
            {
               int  dx = dthings[k][0];//��ʼ��x�е�������������������x��Ӧ���ǵ�x��
                int dy = dthings[k][1];//��ʼ��y�е�����
                int x = i;
                int y= j;
                int x2 = i;
                int y2 = j;//һ����������һ���Ƿ�����
                int count = 1;//�����͵�����
                int empty = 0;//�ո�
                int blocked = 0;//�߽磬һ������1���ܹ��ɻ���
                x2 -= dx;
                y2 -= dy;
                if (qipan[x2][y2] == ' ') {
                
                    empty++;//�жϷ������ǲ��ǿո�
                }
                while (count < 5)
                {

                    //ˢ����һ�����������
                    x += dx;
                    y+= dy;
                   
                    //�жϱ߽�,����б߽���������Ѿ�û�б�����Ҫ��
                    if (x < 0 && x >= hang || y < 0 && y >= lie) {
                        blocked = 1;
                        break;
                    }
                    if (qipan[x][y] == compucurrent) {
                        count++;
                    }
                    else if (qipan[x][y] == ' ') {
                        empty++;
                        if (empty > 1) {
                        //�Ѿ����ɻ��壬û�б�������Ҫ
                            break;
                        }
                    }
                    else if (qipan[x][y] == isindex(compucurrent)) {//����ǶԷ���������û�б�������Ҫ��,����û�п���1��1�ں����׵�����
                        blocked = 1;
                        break;
                    }
                }
                if (!blocked) {
                    if (count == 4 && empty == 2) {
                        score += 10000;  // ����
                    }
                    else if (count == 4 && empty == 1) {
                        score += 1000;  // ����
                    }
                    else if (count == 3 && empty == 2) {
                        score += 500;  // ����
                    }
                    else if (count == 3 && empty == 1) {
                        score += 100;  // ����
                    }
                    else if (count == 2 && empty == 2) {
                        score += 50;  // ���
                    }
                    else if (count == 2 && empty == 1) {
                        score += 10 ;//���
                    }
                    else if (empty == 0) {
                    //����
                        score += 1;
                    }
                }
            }

        }
    }
    return score;
}

//����С�����㷨
int minimax(char qipan[HANG][LIE], int hang, int lie, int depth,char currentplayer,char win_positions[5][2],int maximizingPlayer) {//���ʴ���ĵ�����ʲô����
    if (depth == 0 || checkWin(qipan, HANG, LIE, win_positions) == 1|| checkWin(qipan, HANG, LIE, win_positions)==-1) {
        return levelScore(qipan,HANG,LIE,currentplayer);
    }
    int index = isindex(currentplayer);
    int k = 0;
    

    if (maximizingPlayer) {//����1
        int maxEval = INT_MIN;
        for (int move = 0; move < getvailcount(qipan,hang,lie); move++) {
            make_move(qipan, index,move,k);
            k++;
            int eval = minimax(qipan, hang, lie,depth-1,index,win_positions,0);
            undo_move(qipan, hang,lie);
            maxEval = (eval > maxEval) ? eval : maxEval;
        }
        return maxEval;
    }
    else {
        int minEval = INT_MAX;
        for (int move = 0; move < getvailcount(qipan, hang, lie); move++) {
            make_move(qipan, index, move, k);
            int eval = minimax(qipan, hang, lie, depth - 1, index, win_positions, 1);
            undo_move(qipan, hang, lie);
            minEval = (eval < minEval) ? eval : minEval;
        }
        return minEval;
    }
}
// �ҵ�����ж�
void findBestMove(char qipan[HANG][LIE],int hang,int lie,int move[HANG*LIE][1],char currentplayer,  char win_positions[5][2]) {
    int maxEval = INT_MIN;
        char index = isindex(currentplayer);
    for (int k = 0; k < HANG * LIE; k++) {
        make_move(qipan, index, move, k);
            int eval = minimax(qipan, hang, lie, 10, index, win_positions, 1);  // �����ʵ������
            if (eval > maxEval) {
                maxEval = eval;
                make_move(qipan, index, move, k);  // ����
        }
    }
}
