#include"game.h"
#define OPTION_PLAY 1//开始
#define OPTION_EXIT 2//退出
extern int move[HANG * LIE][1];

int win_positions[5][2] = { 0 };//定义一个数组存放胜利棋子的位置
char qipan[HANG][LIE] = { 0 };//初始化棋盘二维数组
char index ;//对方的棋子
//打印主菜单函数

void menu() {
	//system("cls"); // 清屏
	printf("|————————主菜单————————|\n");
	printf("|——————————————————————|\n");
	printf("|————————1.play————————|\n");
	printf("|————————2.退出————————|\n");
	printf("|——————————————————————|\n\n");
	printf("请输入选项：\n");

}


//判断游戏结束


void game_over(char qipan[HANG][LIE],int win_positions[5][2],char currentplayer) {
	if (checkWin(qipan, HANG, LIE, win_positions)) {
		int row = win_positions[0][0];
		int col = win_positions[0][1];//将胜利的棋子坐标存进去
		if ( currentplayer == '0') {//玩家先手
			if (qipan[row][col] == 'O') {
				mvp(qipan, HANG, LIE, currentplayer, win_positions);//结算画面
				printf("\n\n恭喜你胜利了！\n\n");
			}
			else if (qipan[row][col] == 'X') {
				mvp(qipan, HANG, LIE, currentplayer, win_positions);//结算画面
				printf("\n\n真滴捞，这都能输！\n\n");
			}
		}
		else if (currentplayer == 'X')//玩家后手
		{
			if (qipan[row][col] == 'X') {
				mvp(qipan, HANG, LIE, currentplayer, win_positions);//结算画面
				printf("\n\n恭喜你胜利了！\n\n");
			}else if (qipan[row][col] == 'X') {
				mvp(qipan, HANG, LIE, currentplayer, win_positions);//结算画面
				printf("\n\n真滴捞，这都能输！\n\n");
			}
	}
	}
	else if (checkWin(qipan, HANG, LIE, win_positions) == -1) {
		printf("\n\n游戏结束，双方战平！！\n\n");
		printQipan(qipan, HANG, LIE); // 打印棋盘
	}
	printf("\n\n游戏结束!!!\n\n");
}

//game1的函数,实现初级人机难度

void game1() {
	initQipan(qipan, HANG, LIE);//初始化棋盘制作棋盘10 X 10棋盘
	char currentplayer = determinePlayerOrder();//接收返回的符号并且拿来执行下面的判断语句
	//下棋具体操作

	printQipan(qipan, HANG, LIE); // 打印棋盘
	while (1) {
		if (currentplayer == 'O') { // 玩家先手
			isPlayerTurn(currentplayer); // 判断玩家与人机先后手
			
			playerMove(qipan, HANG, LIE, currentplayer); // 玩家下棋

			game_over(qipan,win_positions,currentplayer);//判断输赢

			system("cls"); // 清屏操作

			computerMove(qipan, HANG, LIE, currentplayer); // AI下棋

			printQipan2(qipan, HANG, LIE); // 打印棋盘

			game_over(qipan, win_positions, currentplayer);//判断输赢
		}
		else if (currentplayer == 'X') {//玩家后手
			isPlayerTurn(currentplayer); // 判断玩家与人机先后手

			computerMove(qipan, HANG, LIE, currentplayer); // AI下棋	

			printQipan(qipan, HANG, LIE);//打印棋盘

			game_over(qipan, win_positions, currentplayer);//判断输赢

			playerMove(qipan, HANG, LIE, currentplayer); // 玩家下棋		

			game_over(qipan, win_positions, currentplayer);//判断输赢

			system("cls"); // 清屏操作
		}
	}
}

//高级人机

void game2() {
	initQipan(qipan, HANG, LIE);//初始化棋盘制作棋盘10 X 10棋盘
	char currentplayer = determinePlayerOrder();//接收返回的符号并且拿来执行下面的判断语句
	printQipan(qipan, HANG, LIE); // 打印棋盘
	while (1) {
		if (currentplayer == 'O') { // 玩家先手
			isPlayerTurn(currentplayer); // 判断玩家与人机先后手

			playerMove(qipan, HANG, LIE, currentplayer); // 玩家下棋

			game_over(qipan, win_positions, currentplayer);//判断输赢

			system("cls"); // 清屏操作

			findBestMove(qipan,HANG,LIE,move,currentplayer,win_positions);//高级AI下棋

			printQipan2(qipan, HANG, LIE); // 打印棋盘

			game_over(qipan, win_positions, currentplayer);//判断输赢
			
		}
		else if (currentplayer == 'X') {//玩家后手
			isPlayerTurn(currentplayer); // 判断玩家与人机先后手
		
			 findBestMove(qipan, HANG, LIE, move, currentplayer, win_positions);//高级AI下棋

			printQipan(qipan, HANG, LIE);//打印棋盘

			game_over(qipan, win_positions, currentplayer);//判断输赢

			playerMove(qipan, HANG, LIE, currentplayer); // 玩家下棋

			game_over(qipan, win_positions, currentplayer);//判断输赢

			system("cls"); // 清屏操作
		}
	}
}


//选择人机

void isLV() {
	int choice = 0;//定义玩家的选项
	do {
		printf("请选择人机难度：\n");
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
		default:printf("输入错误，请重新输入。\n");
			break;
		}
	} while (choice != 3 && choice != 2 && choice != 1);//只要输入不是123，就不断循环
}

//打印play界面

void printfplay() {
	system("cls"); // 清屏

	printf("|——————————————————————|\n");
	printf("|—————1.vs初级人机—————|\n");
	printf("|—————2.vs高级人机—————|\n");
	printf("|—————3.返回主菜单—————|\n");
	printf("|——————————————————————|\n");
	isLV();//选择哪种人机
}


int main() {
	srand((unsigned int)time(NULL));
	int select = 0;//玩家的选项
	do {
		menu();//打印主菜单界面
		scanf_s("%d", & select);
		switch (select) {
		case 1 :printfplay();//打印play界面
			break;
		case 2:printf("退出成功！欢迎你下次再来呀，亲！\n");
			break;
		default:printf("输入错误，请重新输入。\n");
			break;
		}
	}while (select != OPTION_EXIT);//循环条件
		return 0;
}