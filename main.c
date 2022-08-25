#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

//游戏的整个算法实现
void game() {
	char ret = 0;
	//数组-存放棋盘信息
	char board[ROW][COL] = { 0 };

	//初始化棋盘
	InitBoard(board, ROW, COL);

	printf("\n开始游戏\n");
	//打印棋盘
	DisplayBoard(board, ROW, COL);

	while (1) {
		//玩家下棋
		PlayerMove(board, ROW, COL);

		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢
		ret = IsWin(board, ROW, COL);

		if (ret != 'C')
			break;
	}

	if (ret == '*') {
		printf("玩家赢\n");
	}
	else if (ret == '#') {
		printf("电脑赢\n");
	}
	else {
		printf("平局\n");
	}
	printf("\n");
}

void menu() {
	printf("*****************************\n");
	printf("******** 1.play 0.exit *****\n");
	printf("*****************************\n");
}

void test() {
	int input = 0, status;
	char c;

	srand((unsigned int)time(NULL));

	do {
		menu();
		printf("请选择：>");

		status = scanf("%d", &input);
		if (status == 0) {
			input = 2;
		}

		while ((c = getchar()) != '\n' && c != EOF);

		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("\n选择错误，请重新选择！\n");
			break;
		}
	} while (input);
}

int main() {
	test();

	return 0;
}