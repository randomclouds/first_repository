#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define EASY 80

//��ʼ��
void set(char board[ROWS][COLS], int rows, int cols, char str);

//����
void boom(char board[ROWS][COLS], int row, int col);

//ɨ��
int find(char mineboard[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//��ӡ
void print(char board[ROWS][COLS], int row, int col);
