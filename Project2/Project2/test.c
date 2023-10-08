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
	//��������
	char mineboard[ROWS][COLS] = { 0 };
	char showboard[ROWS][COLS] = { 0 };
	//��ʼ��
	set(mineboard, ROWS, COLS, '0');
	set(showboard, ROWS, COLS, '*');
	//������,��������Լ������ 1 ����,�����׵ļ���
	boom(mineboard, ROW, COL);
	//��ӡ
	print(mineboard, ROW, COL);
	print(showboard, ROW, COL);
	//��ʼ��Ϸ
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
			printf("������\n");
			break;
		}
		if (act == 0) {
			printf("��ϲʤ��\n");
			break;
		}
	}
}

int main() {
	int i = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("������������������һ��:>");
		scanf("%d", &i);
		switch (i) {
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("�Ƿ�����");
			break;
		}
	} while (i);
	return 0;
}