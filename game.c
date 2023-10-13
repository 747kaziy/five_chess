#include "game.h"

extern char index;
int move[HANG * LIE][1];//存放空格坐标的数组
//初始化棋盘

void initQipan(char qipan[HANG][LIE], int hang, int lie) {
    int i, j = 0;
    for (i = 0; i < hang; i++) {
        for (j = 0; j < lie; j++) {
            qipan[i][j] = ' '; // 使用空格字符 ' ' 初始化每个空格
        }
    }
}

//打印棋盘

void printQipan(char qipan[HANG][LIE], int hang, int lie) {
    int i, j;

    printf("  "); // 打印列号的空白区域
    for (j = 0; j < lie; j++) {
        printf("  %2d  ", j + 1); // 打印列号，加上空白填充以保持对齐
    }
    printf("\n");

    for (i = 0; i < hang; i++) {
        printf("  ");
        for (j = 0; j < lie; j++) {
            printf("┌─────┐"); // 打印格子上方的横线
        }
        printf("\n");

        printf("%-2d", i + 1); // 打印行号，加上空白填充以保持对齐
        for (j = 0; j < lie; j++) {
            printf("│  %c  │", qipan[i][j]); // 格子内的字符和竖线
        }
        printf("  %-2d\n", i + 1); // 打印行号，与底部横线对齐
        printf("  ");
        for (j = 0; j < lie; j++) {
            printf("└─────┘"); // 打印格子下方的横线
        }
        printf("\n");
    }

    printf("  "); // 打印底部空白区域
    for (j = 0; j < lie; j++) {
        printf("  %2d  ", j + 1); // 打印列号，加上空白填充以保持对齐
    }
    printf("\n");
}

//AI下棋后的打印棋盘

void printQipan2(char qipan[HANG][LIE], int hang, int lie) {
    printQipan(qipan,hang,lie);

    printf("人机已经落子如图所示欸亲!!!!!\n\n");
}


//判断先后手

void isPlayerTurn(char currentPlayer) {
    if (currentPlayer == 'O') {
        printf("本局游戏玩家先手，符号为O,人机为X\ntip:大写的O哦\n");
            
    }
    else if (currentPlayer == 'X') {
        printf("本局游戏玩家后手，符号为X，人机为O\ntip:大写的X哦\n");
       
    }
    else {
        printf("未知玩家，请输入有效的先后手符号。\n");
    }
}

//生成棋子符号

char determinePlayerOrder() {//生成随机数返回
  
    int randomNumber = rand() % 2; // 生成0或1的随机数

    if (randomNumber == 0) {
        printf("\n");
        return 'O';
    }
    else {
        printf("\n");
        return 'X';
    }
}

//玩家下棋

void playerMove(char qipan[HANG][LIE], int hang, int lie, char currentplayer) {
    int x, y = 0;
    char index = currentplayer;
   // system("cls");
    while (1) {
        printf("\ntip1:横坐标没对准，注意一下欸亲！\ntip2:横纵坐标一定要用逗号隔开欸亲!\n请输入你即将落子位置的横纵坐标:\n\n\n");
        scanf_s("%d,%d", &x, &y);
        if (x >= 1 && x <= lie && y >= 1 && y <= hang) {
            if (qipan[x - 1][y - 1] == ' ') {
                qipan[x - 1][y - 1] = index;
                break;
            }
            else {
                printf("没看到有人下那了嘛，眼瞎嘛，我真的会谢！\n");
            }
        }
        else {
            printf("是不是眼瞎呀都叫你注意了，服了！！！\n");
        }

    }
}

//判断另一方棋子，传入的是AI的棋子，返回玩家的棋子
char isindex(char currentplayer) {
     index = '0';
    if (currentplayer == 'O') {
         return index = 'X';
    }
    else if (currentplayer == 'X') {
        return index = 'O';
    }
}

//AI下棋

void computerMove(char qipan[HANG][LIE], int hang, int lie, char currentplayer) {
    printf("AI下棋ing...\n\n");
    index = isindex(currentplayer);//定义AI的落子符号
    int x, y = 0;//AI落子坐标
    while (1) {
        x = rand() % hang;//随机生成x坐标
        y = rand() % lie;//随机生成y坐标
        if (qipan[x][y] == ' ') {
            qipan[x][y] = index;
            break;
        }
    }
}

//判断玩家输赢

int checkWin(char qipan[HANG][LIE], int hang, int lie, int win_positions[5][2]) {//传入的是一个宽为2，长为五的二维数组
    int i, j = 0;

    // 检查水平方向
    for (i = 0; i < hang; i++)
    {
        for (j = 0; j <= lie - 5; j++) {
            if (qipan[i][j] == qipan[i][j + 1] == qipan[i][j + 2] == qipan[i][j + 3] == qipan[i][j + 4]) {
                for (int k = 0; k < 5; k++) {
                    win_positions[k][0] = i;     // 记录胜利位置的行数
                    win_positions[k][1] = j + k; // 记录胜利位置的列数
                }
                return 1; // 找到连续的五颗棋子，返回胜利
            }
        }
    }

    // 检查垂直方向
    for (i = 0; i <= hang - 5; i++) {
        for (j = 0; j < lie; j++) {
            if (qipan[i][j] == qipan[i + 1][j] == qipan[i + 2][j] == qipan[i + 3][j] == qipan[i + 4][j]) {
                for (int k = 0; k < 5; k++) {
                    win_positions[k][0] = i + k; // 记录胜利位置的行数
                    win_positions[k][1] = j;     // 记录胜利位置的列数
                }
                return 1;
            }
        }
    }

    // 检查对角线方向（左上到右下）
    for (i = 0; i <= hang - 5; i++) {
        for (j = 0; j <= lie - 5; j++) {
            if (qipan[i][j] == qipan[i + 1][j + 1] == qipan[i + 2][j + 2] == qipan[i + 3][j + 3] == qipan[i + 4][j + 4]) {
                for (int k = 0; k < 5; k++) {
                    win_positions[k][0] = i + k; // 记录胜利位置的行数
                    win_positions[k][1] = j + k; // 记录胜利位置的列数
                }
                return 1;
            }
        }
    }

    // 检查对角线方向（右上到左下）
    for (i = 0; i <= hang - 5; i++) {
        for (j = 4; j < lie; j++) {
            if (qipan[i][j] == qipan[i + 1][j - 1] == qipan[i + 2][j - 2] == qipan[i + 3][j - 3] == qipan[i + 4][j - 4]) {
                for (int k = 0; k < 5; k++) {
                    win_positions[k][0] = i + k; // 记录胜利位置的行数
                    win_positions[k][1] = j - k; // 记录胜利位置的列数
                }
                return 1;
            }
        }
    }

    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < lie; j++) {
            if (qipan[i][j] == ' ') {
                return 0; // 没有找到连续的五颗棋子
            }
            else {
                return -1;//平局
            }
        }
    }
}


//mvp结算画面输出
    void mvp(char qipan[HANG][LIE], int hang, int lie, char currentplayer, int win_positions[5][2]) {
        int i, j = 0;
        // 清空棋盘数组
        for (int i = 0; i < HANG; i++) {
            for (int j = 0; j < LIE; j++) {
                qipan[i][j] = ' ';
            }
        }
        // 将胜利位置复制到棋盘数组
        for (int i = 0; i < 5; i++) {
            int row = win_positions[i][0];
            int col = win_positions[i][1];
            qipan[row][col] = currentplayer;// 标记胜利位置
        }
    }
  


    //获取空格位置并且返回当前空格数

    int getvailcount(char qipan[HANG][LIE], int hang, int lie) {
        int i, j = 0;
        int count = 0;
        for (int i = 0; i < hang; i++) {
            for (int j = 0; j < lie; j++) {
                if (qipan[i][j] == ' ') {
                    count++;
                }
            }
        }
    }

    //获取空格的坐标
    void getvailMove(char qipan[HANG][LIE], int hang, int lie,int move[HANG*LIE][1]) {
        int i, j, k = 0;
        for (int i = 0; i < hang; i++) {
            for (int j = 0; j < lie; j++) {
                if (qipan[i][j] == ' ') {
                    move[k][0] = i;
                    move[k][1] = j;

                    k++;
                }
            }
        }
    }
    //在该空格下子
    void make_move(char qipan[HANG][LIE],char currentplayer,int move [HANG * LIE][1],int k) {

        int row = move[k][0];
        int col = move[k][1];
        qipan[row][col] = currentplayer;
    }

    //保存目前棋盘状态,存入一个临时数组
    void ctrl_s(char qipan [HANG][LIE],int hang,int lie) {
        int i, j, k = 0;
        char temp_qipan[HANG][LIE];
        for (int i = 0; i < hang; i++) {
            for (int j = 0; j < lie; j++) {
                 temp_qipan[i][j] = qipan[i][j];
            }
        }
    
    }

    //撤销下棋操作
    void undo_move(char qipan[HANG][LIE], int hang, int lie) {
        ctrl_s(qipan,hang,lie);//恢复到上一步状态
    }
    
