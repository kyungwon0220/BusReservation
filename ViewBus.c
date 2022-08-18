#include "main.h"

char* Buss[] = {"서울행", "대전행", "대구행", "부산행", "제주행"}; // 행선지 정보 배열
char* price[] = {"5,000\\ - 10,000\\", "10,000\\ - 15,000\\", "15,000\\ - 20,000\\", "20,000\\ - 25,000\\", "25,000\\ - 30,000\\"}; // 가격 정보 배열
HowManyBus = sizeof(Buss) / sizeof(Buss[0]); // 버스 총 대수
    /*
        버스의 총 대수(2차원 배열에서 행(row 값은
        배열이 차지하는 전체 공간을 가로 한 줄의 크기로 나눠줌
    */

void ViewBusList() {
    system("cls");
    printf("\n\n\n");
    printf("=========================================== KOSTA BUS RESERVATION SYSTEM ============================================\n\n\n");
    
    for (int i = 0; i < HowManyBus; i++)
        printf("\t\t\t\t[No.%d번 BUS]    KOSTA -> %s    %s\n\n", i+1, Buss[i], price[i]);
}


void ViewBusSeats(int BusNumber, int* check) {
    system("CLS");
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.No   %d번     %s                                                            \n", BusNumber,Buss[BusNumber - 1]);
    printf("\t\t\t* 1번 ~ 10번 좌석은 교통 약자를 위해 배려해 주세요 :)\n");
    printf("____________________________________________________________________________________________________________________");
    for (int i = 0; i < Seats; i++) {
        if (i % 2 == 0) printf("\n"); // form 줄내림(시각 효과
        if (i == 10 || i % 30 == 0) printf("\n"); // form 줄내림(시각 효과
        
        if (check[i] == 0) printf("\t%2d.Empty\t",i+1); // 예약 가능 좌석
        else if (check[i] == 1) printf("\t%2d.Full\t\t",i+1); // 예약 불가 좌석
    }
}