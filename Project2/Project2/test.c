#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include "game.h"

void menu() {
	printf("***************************\n");
	printf("***********1.play**********\n");
	printf("***********0.exit**********\n");
	printf("***************************\n");
}

void game() {
	//创建数组
	char mineboard[ROWS][COLS] = { 0 };
	char showboard[ROWS][COLS] = { 0 };
	//初始化
	set(mineboard, ROWS, COLS, '0');
	set(showboard, ROWS, COLS, '*');
	//设置雷,这里我们约定数字 1 是雷,方便雷的计算
	boom(mineboard, ROW, COL);
	//打印
	print(mineboard, ROW, COL);
	print(showboard, ROW, COL);
	//开始游戏
	int flag = 1;
	int act = ROW*COL - EASY;
	while (flag) {
		flag = find(mineboard, showboard, ROW, COL);
		print(showboard, ROW, COL);
		if (flag == 1) {
			act--;
		}
		else if (flag == 2) {
			continue;
		}
		else {
			printf("你输了\n");
			break;
		}
		if (act == 0) {
			printf("恭喜胜利\n");
			break;
		}
	}
}

int main() {
	int i = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请输入数组来进行下一步:>");
		scanf("%d", &i);
		switch (i) {
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("非法输入");
			break;
		}
	} while (i);
	return 0;
}