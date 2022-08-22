#include "main.h"

void ViewBusList(int HowManyBus, char** Bus_to, char** Bus_price) {
    system("cls");
    printf("\n\n\n");
    printf("=========================================== KOSTA BUS RESERVATION SYSTEM ============================================\n\n\n");
    
    for (int i = 0; i < HowManyBus; i++)
        printf("\t\t\t\t[No.%d�� BUS]    KOSTA -> %s    %s\n\n", i+1, Bus_to[i], Bus_price[i]);
}


void ViewBusSeats(int Cho_BusNum, char** Bus_to, int Seats, int* check) {
    system("CLS");
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.No   %d��     %s                                                            \n", Cho_BusNum, Bus_to[Cho_BusNum - 1]);
    printf("\t\t\t* 1�� ~ 10�� �¼��� ���� ���ڸ� ���� ����� �ּ��� :)\n");
    printf("____________________________________________________________________________________________________________________");
    for (int i = 0; i < Seats; i++) {
        if (i % 2 == 0) printf("\n"); // form �ٳ���(�ð� ȿ��
        if (i == 10 || i % 30 == 0) printf("\n"); // form �ٳ���(�ð� ȿ��
        
        if (check[i] == 0) printf("\t%2d.Empty\t",i+1); // ���� ���� �¼�
        else if (check[i] == 1) printf("\t%2d.Full\t\t",i+1); // ���� �Ұ� �¼�
    }
}