#include "main.h"

void SeatFileOpenReadMode(int Cho_BusNum, char* p) {
    FILE* fp; // fopen 위한 변수

    
    switch (Cho_BusNum) { // 각 버스 No. (번호별 case
    case 1:
        fp = fopen("bus1.txt", "r");

        if (fp == NULL) { // 선택한 버스의 파일이 없을시
            fp = fopen("bus1.txt", "w"); // 파일 생성
            fputs("0000000000000000000000000000000000000000", fp); // 40좌석
            fclose(fp);
            fp = fopen("bus1.txt", "r"); // 읽기(Read 모드로 파일 open
        }

        fgets(p, 41, fp);
        fclose(fp); // fopen 용무 종료 
        break; // switch case 1 end


    case 2:
        fp = fopen("bus2.txt", "r");

        if (fp == NULL) { // 선택한 버스의 파일이 없을시
            fp = fopen("bus2.txt", "w"); // 파일 생성
            fputs("0000000000000000000000000000000000000000", fp); // 40좌석
            fclose(fp);
            fp = fopen("bus2.txt", "r"); // 읽기(Read 모드로 파일 open
        }

        fgets(p, 41, fp);
        fclose(fp); // fopen 용무 종료 
        break; // switch case 2 end

    case 3:
        fp = fopen("bus3.txt", "r");

        if (fp == NULL) { // 선택한 버스의 파일이 없을시
            fp = fopen("bus3.txt", "w"); // 파일 생성
            fputs("0000000000000000000000000000000000000000", fp); // 40좌석
            fclose(fp);
            fp = fopen("bus3.txt", "r"); // 읽기(Read 모드로 파일 open
        }

        fgets(p, 41, fp);
        fclose(fp); // fopen 용무 종료 
        break; // switch case 3 end

    case 4:
        fp = fopen("bus4.txt", "r");

        if (fp == NULL) { // 선택한 버스의 파일이 없을시
            fp = fopen("bus4.txt", "w"); // 파일 생성
            fputs("0000000000000000000000000000000000000000", fp); // 40좌석
            fclose(fp);
            fp = fopen("bus4.txt", "r"); // 읽기(Read 모드로 파일 open
        }

        fgets(p, 41, fp);
        fclose(fp); // fopen 용무 종료 
        break; // switch case 4 end

    case 5:
        fp = fopen("bus5.txt", "r");

        if (fp == NULL) { // 선택한 버스의 파일이 없을시
            fp = fopen("bus5.txt", "w"); // 파일 생성
            fputs("0000000000000000000000000000000000000000", fp); // 40좌석
            fclose(fp);
            fp = fopen("bus5.txt", "r"); // 읽기(Read 모드로 파일 open
        }

        fgets(p, 41, fp);
        fclose(fp); // fopen 용무 종료 
        break; // switch case 5 end

    }
}