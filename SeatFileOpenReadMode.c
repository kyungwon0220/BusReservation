#include "main.h"

void SeatFileOpenReadMode(char* Bus_fileName, int Seats, char* p) {
    FILE* fp; // fopen ���� ����

    
    fp = fopen(Bus_fileName, "r");

    if (fp == NULL) { // ������ ������ ������ ������
        fp = fopen(Bus_fileName, "w"); // ���� ����
        for (int i = 0; i < Seats; i++) putc('0', fp);
        fclose(fp);
        fp = fopen(Bus_fileName, "r"); // �б�(Read ���� ���� open
    }

    fgets(p, Seats + 1, fp);
    fclose(fp); // fopen �빫 ���� 
}