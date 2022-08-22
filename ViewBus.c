#include "main.h"

void ViewBusList(int HowManyBus, char** Bus_to, char** Bus_price) {
    system("cls");
    printf("\n\n\n");
    printf("=========================================== KOSTA BUS RESERVATION SYSTEM ============================================\n\n\n");
    
    for (int i = 0; i < HowManyBus; i++)
        printf("\t\t\t\t[No.%d번 BUS]    KOSTA -> %s    %s\n\n", i+1, Bus_to[i], Bus_price[i]);
}


void ViewBusSeats(int Cho_BusNum, char** Bus_to, int Seats, int* check) {
    system("CLS");
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.No   %d번     %s                                                            \n", Cho_BusNum, Bus_to[Cho_BusNum - 1]);
    printf("\t\t\t* 1번 ~ 10번 좌석은 교통 약자를 위해 배려해 주세요 :)\n");
    printf("____________________________________________________________________________________________________________________");
    for (int i = 0; i < Seats; i++) {
        if (i % 2 == 0) printf("\n"); // form 줄내림(시각 효과
        if (i == 10 || i % 30 == 0) printf("\n"); // form 줄내림(시각 효과
        
        if (check[i] == 0) printf("\t%2d.Empty\t",i+1); // 예약 가능 좌석
        else if (check[i] == 1) printf("\t%2d.Full\t\t",i+1); // 예약 불가 좌석
    }
}