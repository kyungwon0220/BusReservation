#include "main.h"

void SeatFileWriteAddMode(char* Bus_fileName, int Seats, int* check) {
	FILE* fp; // fopen ���� ����

	// ���� ���� ��ü ����
	fp = fopen(Bus_fileName, "w");
	fclose(fp);

	// ���� ���� ���� �Է�
	fp = fopen(Bus_fileName, "a");
	for (int i = 0; i < Seats; i++) {
		if (check[i] == 0) putc('0', fp);
		else if (check[i] == 1) putc('1', fp);			
	}

	fclose(fp); // fopen �빫 ����
}