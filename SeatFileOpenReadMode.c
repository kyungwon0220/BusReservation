#include "main.h"

void SeatFileOpenReadMode(char* Bus_fileName, int Seats, char* p) {
    FILE* fp; // fopen 위한 변수

    
    fp = fopen(Bus_fileName, "r");

    if (fp == NULL) { // 선택한 버스의 파일이 없을시
        fp = fopen(Bus_fileName, "w"); // 파일 생성
        for (int i = 0; i < Seats; i++) putc('0', fp);
        fclose(fp);
        fp = fopen(Bus_fileName, "r"); // 읽기(Read 모드로 파일 open
    }

    fgets(p, Seats + 1, fp);
    fclose(fp); // fopen 용무 종료 
}