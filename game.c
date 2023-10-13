#include "game.h"

extern char index;
int move[HANG * LIE][1];//��ſո����������
//��ʼ������

void initQipan(char qipan[HANG][LIE], int hang, int lie) {
    int i, j = 0;
    for (i = 0; i < hang; i++) {
        for (j = 0; j < lie; j++) {
            qipan[i][j] = ' '; // ʹ�ÿո��ַ� ' ' ��ʼ��ÿ���ո�
        }
    }
}

//��ӡ����

void printQipan(char qipan[HANG][LIE], int hang, int lie) {
    int i, j;

    printf("  "); // ��ӡ�кŵĿհ�����
    for (j = 0; j < lie; j++) {
        printf("  %2d  ", j + 1); // ��ӡ�кţ����Ͽհ�����Ա��ֶ���
    }
    printf("\n");

    for (i = 0; i < hang; i++) {
        printf("  ");
        for (j = 0; j < lie; j++) {
            printf("��������������"); // ��ӡ�����Ϸ��ĺ���
        }
        printf("\n");

        printf("%-2d", i + 1); // ��ӡ�кţ����Ͽհ�����Ա��ֶ���
        for (j = 0; j < lie; j++) {
            printf("��  %c  ��", qipan[i][j]); // �����ڵ��ַ�������
        }
        printf("  %-2d\n", i + 1); // ��ӡ�кţ���ײ����߶���
        printf("  ");
        for (j = 0; j < lie; j++) {
            printf("��������������"); // ��ӡ�����·��ĺ���
        }
        printf("\n");
    }

    printf("  "); // ��ӡ�ײ��հ�����
    for (j = 0; j < lie; j++) {
        printf("  %2d  ", j + 1); // ��ӡ�кţ����Ͽհ�����Ա��ֶ���
    }
    printf("\n");
}

//AI�����Ĵ�ӡ����

void printQipan2(char qipan[HANG][LIE], int hang, int lie) {
    printQipan(qipan,hang,lie);

    printf("�˻��Ѿ�������ͼ��ʾ�G��!!!!!\n\n");
}


//�ж��Ⱥ���

void isPlayerTurn(char currentPlayer) {
    if (currentPlayer == 'O') {
        printf("������Ϸ������֣�����ΪO,�˻�ΪX\ntip:��д��OŶ\n");
            
    }
    else if (currentPlayer == 'X') {
        printf("������Ϸ��Һ��֣�����ΪX���˻�ΪO\ntip:��д��XŶ\n");
       
    }
    else {
        printf("δ֪��ң���������Ч���Ⱥ��ַ��š�\n");
    }
}

//�������ӷ���

char determinePlayerOrder() {//�������������
  
    int randomNumber = rand() % 2; // ����0��1�������

    if (randomNumber == 0) {
        printf("\n");
        return 'O';
    }
    else {
        printf("\n");
        return 'X';
    }
}

//�������

void playerMove(char qipan[HANG][LIE], int hang, int lie, char currentplayer) {
    int x, y = 0;
    char index = currentplayer;
   // system("cls");
    while (1) {
        printf("\ntip1:������û��׼��ע��һ�G�ף�\ntip2:��������һ��Ҫ�ö��Ÿ����G��!\n�������㼴������λ�õĺ�������:\n\n\n");
        scanf_s("%d,%d", &x, &y);
        if (x >= 1 && x <= lie && y >= 1 && y <= hang) {
            if (qipan[x - 1][y - 1] == ' ') {
                qipan[x - 1][y - 1] = index;
                break;
            }
            else {
                printf("û�����������������Ϲ�����Ļ�л��\n");
            }
        }
        else {
            printf("�ǲ�����Ϲѽ������ע���ˣ����ˣ�����\n");
        }

    }
}

//�ж���һ�����ӣ��������AI�����ӣ�������ҵ�����
char isindex(char currentplayer) {
     index = '0';
    if (currentplayer == 'O') {
         return index = 'X';
    }
    else if (currentplayer == 'X') {
        return index = 'O';
    }
}

//AI����

void computerMove(char qipan[HANG][LIE], int hang, int lie, char currentplayer) {
    printf("AI����ing...\n\n");
    index = isindex(currentplayer);//����AI�����ӷ���
    int x, y = 0;//AI��������
    while (1) {
        x = rand() % hang;//�������x����
        y = rand() % lie;//�������y����
        if (qipan[x][y] == ' ') {
            qipan[x][y] = index;
            break;
        }
    }
}

//�ж������Ӯ

int checkWin(char qipan[HANG][LIE], int hang, int lie, int win_positions[5][2]) {//�������һ����Ϊ2����Ϊ��Ķ�ά����
    int i, j = 0;

    // ���ˮƽ����
    for (i = 0; i < hang; i++)
    {
        for (j = 0; j <= lie - 5; j++) {
            if (qipan[i][j] == qipan[i][j + 1] == qipan[i][j + 2] == qipan[i][j + 3] == qipan[i][j + 4]) {
                for (int k = 0; k < 5; k++) {
                    win_positions[k][0] = i;     // ��¼ʤ��λ�õ�����
                    win_positions[k][1] = j + k; // ��¼ʤ��λ�õ�����
                }
                return 1; // �ҵ�������������ӣ�����ʤ��
            }
        }
    }

    // ��鴹ֱ����
    for (i = 0; i <= hang - 5; i++) {
        for (j = 0; j < lie; j++) {
            if (qipan[i][j] == qipan[i + 1][j] == qipan[i + 2][j] == qipan[i + 3][j] == qipan[i + 4][j]) {
                for (int k = 0; k < 5; k++) {
                    win_positions[k][0] = i + k; // ��¼ʤ��λ�õ�����
                    win_positions[k][1] = j;     // ��¼ʤ��λ�õ�����
                }
                return 1;
            }
        }
    }

    // ���Խ��߷������ϵ����£�
    for (i = 0; i <= hang - 5; i++) {
        for (j = 0; j <= lie - 5; j++) {
            if (qipan[i][j] == qipan[i + 1][j + 1] == qipan[i + 2][j + 2] == qipan[i + 3][j + 3] == qipan[i + 4][j + 4]) {
                for (int k = 0; k < 5; k++) {
                    win_positions[k][0] = i + k; // ��¼ʤ��λ�õ�����
                    win_positions[k][1] = j + k; // ��¼ʤ��λ�õ�����
                }
                return 1;
            }
        }
    }

    // ���Խ��߷������ϵ����£�
    for (i = 0; i <= hang - 5; i++) {
        for (j = 4; j < lie; j++) {
            if (qipan[i][j] == qipan[i + 1][j - 1] == qipan[i + 2][j - 2] == qipan[i + 3][j - 3] == qipan[i + 4][j - 4]) {
                for (int k = 0; k < 5; k++) {
                    win_positions[k][0] = i + k; // ��¼ʤ��λ�õ�����
                    win_positions[k][1] = j - k; // ��¼ʤ��λ�õ�����
                }
                return 1;
            }
        }
    }

    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < lie; j++) {
            if (qipan[i][j] == ' ') {
                return 0; // û���ҵ��������������
            }
            else {
                return -1;//ƽ��
            }
        }
    }
}


//mvp���㻭�����
    void mvp(char qipan[HANG][LIE], int hang, int lie, char currentplayer, int win_positions[5][2]) {
        int i, j = 0;
        // �����������
        for (int i = 0; i < HANG; i++) {
            for (int j = 0; j < LIE; j++) {
                qipan[i][j] = ' ';
            }
        }
        // ��ʤ��λ�ø��Ƶ���������
        for (int i = 0; i < 5; i++) {
            int row = win_positions[i][0];
            int col = win_positions[i][1];
            qipan[row][col] = currentplayer;// ���ʤ��λ��
        }
    }
  


    //��ȡ�ո�λ�ò��ҷ��ص�ǰ�ո���

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

    //��ȡ�ո������
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
    //�ڸÿո�����
    void make_move(char qipan[HANG][LIE],char currentplayer,int move [HANG * LIE][1],int k) {

        int row = move[k][0];
        int col = move[k][1];
        qipan[row][col] = currentplayer;
    }

    //����Ŀǰ����״̬,����һ����ʱ����
    void ctrl_s(char qipan [HANG][LIE],int hang,int lie) {
        int i, j, k = 0;
        char temp_qipan[HANG][LIE];
        for (int i = 0; i < hang; i++) {
            for (int j = 0; j < lie; j++) {
                 temp_qipan[i][j] = qipan[i][j];
            }
        }
    
    }

    //�����������
    void undo_move(char qipan[HANG][LIE], int hang, int lie) {
        ctrl_s(qipan,hang,lie);//�ָ�����һ��״̬
    }
    
