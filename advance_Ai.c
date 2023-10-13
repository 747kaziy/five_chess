#include "game.h"

//判断水平评估得分的函数
int levelScore(char qipan[HANG][LIE], int hang, int lie, char compucurrent) {
    int i, j,k = 0;//分别是行，列，移动的索引
    int score = 0;//初始化得分
    int dthings[4][2] = { (0,1),(1,0),(-1,1),(1,1) };//初始化增量数组分别对应向右，向下，向右上，向右下平移一格

    for (int i = 0; i < hang; i++) 
    {
        for (int j = 0; j < lie; j++) {
            if (qipan[i][j] != compucurrent) {
                continue;
            }
            for (int k = 0; k < 4; k++)//遍历增量数组,遍历棋子往一个方向走几步，直到五子成型
            {
               int  dx = dthings[k][0];//初始化x列的增量，由于设置棋盘x对应的是第x行
                int dy = dthings[k][1];//初始化y列的增量
                int x = i;
                int y= j;
                int x2 = i;
                int y2 = j;//一个是正方向，一个是反方向
                int count = 1;//用类型的棋子
                int empty = 0;//空格
                int blocked = 0;//边界，一旦等于1则不能构成活棋
                x2 -= dx;
                y2 -= dy;
                if (qipan[x2][y2] == ' ') {
                
                    empty++;//判断反方向是不是空格
                }
                while (count < 5)
                {

                    //刷新往一个方向的坐标
                    x += dx;
                    y+= dy;
                   
                    //判断边界,如果有边界这个方向已经没有遍历需要了
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
                        //已经构成活棋，没有遍历的需要
                            break;
                        }
                    }
                    else if (qipan[x][y] == isindex(compucurrent)) {//如果是对方的棋子则没有遍历的需要了,这里没有考虑1白1黑后三白的例子
                        blocked = 1;
                        break;
                    }
                }
                if (!blocked) {
                    if (count == 4 && empty == 2) {
                        score += 10000;  // 活四
                    }
                    else if (count == 4 && empty == 1) {
                        score += 1000;  // 冲四
                    }
                    else if (count == 3 && empty == 2) {
                        score += 500;  // 活三
                    }
                    else if (count == 3 && empty == 1) {
                        score += 100;  // 冲三
                    }
                    else if (count == 2 && empty == 2) {
                        score += 50;  // 活二
                    }
                    else if (count == 2 && empty == 1) {
                        score += 10 ;//冲二
                    }
                    else if (empty == 0) {
                    //死棋
                        score += 1;
                    }
                }
            }

        }
    }
    return score;
}

//极大极小搜索算法
int minimax(char qipan[HANG][LIE], int hang, int lie, int depth,char currentplayer,char win_positions[5][2],int maximizingPlayer) {//疑问传入的到底是什么参数
    if (depth == 0 || checkWin(qipan, HANG, LIE, win_positions) == 1|| checkWin(qipan, HANG, LIE, win_positions)==-1) {
        return levelScore(qipan,HANG,LIE,currentplayer);
    }
    int index = isindex(currentplayer);
    int k = 0;
    

    if (maximizingPlayer) {//传入1
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
// 找到最佳行动
void findBestMove(char qipan[HANG][LIE],int hang,int lie,int move[HANG*LIE][1],char currentplayer,  char win_positions[5][2]) {
    int maxEval = INT_MIN;
        char index = isindex(currentplayer);
    for (int k = 0; k < HANG * LIE; k++) {
        make_move(qipan, index, move, k);
            int eval = minimax(qipan, hang, lie, 10, index, win_positions, 1);  // 设置适当的深度
            if (eval > maxEval) {
                maxEval = eval;
                make_move(qipan, index, move, k);  // 下子
        }
    }
}
