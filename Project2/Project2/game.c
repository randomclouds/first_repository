#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include "game.h"

//初始化
void set(char board[ROWS][COLS], int rows, int cols, char str) {
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			board[i][j] = str;
		}
	}
}

void print(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	int j = 0;
	printf("------------扫雷游戏------------\n");
	for (i = 0; i <= row; i++) {
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		printf("%d ", i);
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------------\n");
}

void boom(char board[ROWS][COLS], int row, int col) {
	int booms = EASY;
	while (booms) {
		int i = rand() % 9 + 1;
		int j = rand() % 9 + 1;
		if (board[i][j] != '1') {
			board[i][j] = '1';
			booms--;
		}
	}
}
//计算
char cal(char mineboard[ROWS][COLS], int x, int y) {
	return mineboard[x - 1][y - 1] + mineboard[x - 1][y] + mineboard[x - 1][y + 1] +
		mineboard[x][y - 1] + mineboard[x][y + 1] + mineboard[x + 1][y - 1] +
		mineboard[x + 1][y] + mineboard[x + 1][y + 1] - 7 * '0';
}

int find(char mineboard[ROWS][COLS], char showboard[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	printf("输入坐标:");
	scanf("%d %d", &x, &y);
	if (x <= row && x >= 1 && y <= col && y >= 1) {
		if (mineboard[x][y] == '1') {
			return 0;
		}
		else {
			showboard[x][y] = cal(mineboard, x, y);
			return 1;
		}
	}
	else {
		printf("坐标非法\n");
		return 2;
	}
}