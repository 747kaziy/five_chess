#include"game.h"
#define OPTION_PLAY 1//��ʼ
#define OPTION_EXIT 2//�˳�
extern int move[HANG * LIE][1];

int win_positions[5][2] = { 0 };//����һ��������ʤ�����ӵ�λ��
char qipan[HANG][LIE] = { 0 };//��ʼ�����̶�ά����
char index ;//�Է�������
//��ӡ���˵�����

void menu() {
	//system("cls"); // ����
	printf("|�������������������˵�����������������|\n");
	printf("|��������������������������������������������|\n");
	printf("|����������������1.play����������������|\n");
	printf("|����������������2.�˳�����������������|\n");
	printf("|��������������������������������������������|\n\n");
	printf("������ѡ�\n");

}


//�ж���Ϸ����


void game_over(char qipan[HANG][LIE],int win_positions[5][2],char currentplayer) {
	if (checkWin(qipan, HANG, LIE, win_positions)) {
		int row = win_positions[0][0];
		int col = win_positions[0][1];//��ʤ��������������ȥ
		if ( currentplayer == '0') {//�������
			if (qipan[row][col] == 'O') {
				mvp(qipan, HANG, LIE, currentplayer, win_positions);//���㻭��
				printf("\n\n��ϲ��ʤ���ˣ�\n\n");
			}
			else if (qipan[row][col] == 'X') {
				mvp(qipan, HANG, LIE, currentplayer, win_positions);//���㻭��
				printf("\n\n����̣��ⶼ���䣡\n\n");
			}
		}
		else if (currentplayer == 'X')//��Һ���
		{
			if (qipan[row][col] == 'X') {
				mvp(qipan, HANG, LIE, currentplayer, win_positions);//���㻭��
				printf("\n\n��ϲ��ʤ���ˣ�\n\n");
			}else if (qipan[row][col] == 'X') {
				mvp(qipan, HANG, LIE, currentplayer, win_positions);//���㻭��
				printf("\n\n����̣��ⶼ���䣡\n\n");
			}
	}
	}
	else if (checkWin(qipan, HANG, LIE, win_positions) == -1) {
		printf("\n\n��Ϸ������˫��սƽ����\n\n");
		printQipan(qipan, HANG, LIE); // ��ӡ����
	}
	printf("\n\n��Ϸ����!!!\n\n");
}

//game1�ĺ���,ʵ�ֳ����˻��Ѷ�

void game1() {
	initQipan(qipan, HANG, LIE);//��ʼ��������������10 X 10����
	char currentplayer = determinePlayerOrder();//���շ��صķ��Ų�������ִ��������ж����
	//����������

	printQipan(qipan, HANG, LIE); // ��ӡ����
	while (1) {
		if (currentplayer == 'O') { // �������
			isPlayerTurn(currentplayer); // �ж�������˻��Ⱥ���
			
			playerMove(qipan, HANG, LIE, currentplayer); // �������

			game_over(qipan,win_positions,currentplayer);//�ж���Ӯ

			system("cls"); // ��������

			computerMove(qipan, HANG, LIE, currentplayer); // AI����

			printQipan2(qipan, HANG, LIE); // ��ӡ����

			game_over(qipan, win_positions, currentplayer);//�ж���Ӯ
		}
		else if (currentplayer == 'X') {//��Һ���
			isPlayerTurn(currentplayer); // �ж�������˻��Ⱥ���

			computerMove(qipan, HANG, LIE, currentplayer); // AI����	

			printQipan(qipan, HANG, LIE);//��ӡ����

			game_over(qipan, win_positions, currentplayer);//�ж���Ӯ

			playerMove(qipan, HANG, LIE, currentplayer); // �������		

			game_over(qipan, win_positions, currentplayer);//�ж���Ӯ

			system("cls"); // ��������
		}
	}
}

//�߼��˻�

void game2() {
	initQipan(qipan, HANG, LIE);//��ʼ��������������10 X 10����
	char currentplayer = determinePlayerOrder();//���շ��صķ��Ų�������ִ��������ж����
	printQipan(qipan, HANG, LIE); // ��ӡ����
	while (1) {
		if (currentplayer == 'O') { // �������
			isPlayerTurn(currentplayer); // �ж�������˻��Ⱥ���

			playerMove(qipan, HANG, LIE, currentplayer); // �������

			game_over(qipan, win_positions, currentplayer);//�ж���Ӯ

			system("cls"); // ��������

			findBestMove(qipan,HANG,LIE,move,currentplayer,win_positions);//�߼�AI����

			printQipan2(qipan, HANG, LIE); // ��ӡ����

			game_over(qipan, win_positions, currentplayer);//�ж���Ӯ
			
		}
		else if (currentplayer == 'X') {//��Һ���
			isPlayerTurn(currentplayer); // �ж�������˻��Ⱥ���
		
			 findBestMove(qipan, HANG, LIE, move, currentplayer, win_positions);//�߼�AI����

			printQipan(qipan, HANG, LIE);//��ӡ����

			game_over(qipan, win_positions, currentplayer);//�ж���Ӯ

			playerMove(qipan, HANG, LIE, currentplayer); // �������

			game_over(qipan, win_positions, currentplayer);//�ж���Ӯ

			system("cls"); // ��������
		}
	}
}


//ѡ���˻�

void isLV() {
	int choice = 0;//������ҵ�ѡ��
	do {
		printf("��ѡ���˻��Ѷȣ�\n");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			game1();
			break;
		case 2:
			game2();
			break;
		case 3:
			return;
		default:printf("����������������롣\n");
			break;
		}
	} while (choice != 3 && choice != 2 && choice != 1);//ֻҪ���벻��123���Ͳ���ѭ��
}

//��ӡplay����

void printfplay() {
	system("cls"); // ����

	printf("|��������������������������������������������|\n");
	printf("|����������1.vs�����˻�����������|\n");
	printf("|����������2.vs�߼��˻�����������|\n");
	printf("|����������3.�������˵�����������|\n");
	printf("|��������������������������������������������|\n");
	isLV();//ѡ�������˻�
}


int main() {
	srand((unsigned int)time(NULL));
	int select = 0;//��ҵ�ѡ��
	do {
		menu();//��ӡ���˵�����
		scanf_s("%d", & select);
		switch (select) {
		case 1 :printfplay();//��ӡplay����
			break;
		case 2:printf("�˳��ɹ�����ӭ���´�����ѽ���ף�\n");
			break;
		default:printf("����������������롣\n");
			break;
		}
	}while (select != OPTION_EXIT);//ѭ������
		return 0;
}