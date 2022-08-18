#include "main.h"

char* Buss[] = {"������", "������", "�뱸��", "�λ���", "������"}; // �༱�� ���� �迭
char* price[] = {"5,000\\ - 10,000\\", "10,000\\ - 15,000\\", "15,000\\ - 20,000\\", "20,000\\ - 25,000\\", "25,000\\ - 30,000\\"}; // ���� ���� �迭
HowManyBus = sizeof(Buss) / sizeof(Buss[0]); // ���� �� ���
    /*
        ������ �� ���(2���� �迭���� ��(row ����
        �迭�� �����ϴ� ��ü ������ ���� �� ���� ũ��� ������
    */

void ViewBusList() {
    system("cls");
    printf("\n\n\n");
    printf("=========================================== KOSTA BUS RESERVATION SYSTEM ============================================\n\n\n");
    
    for (int i = 0; i < HowManyBus; i++)
        printf("\t\t\t\t[No.%d�� BUS]    KOSTA -> %s    %s\n\n", i+1, Buss[i], price[i]);
}


void ViewBusSeats(int BusNumber, int* check) {
    system("CLS");
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.No   %d��     %s                                                            \n", BusNumber,Buss[BusNumber - 1]);
    printf("\t\t\t* 1�� ~ 10�� �¼��� ���� ���ڸ� ���� ����� �ּ��� :)\n");
    printf("____________________________________________________________________________________________________________________");
    for (int i = 0; i < Seats; i++) {
        if (i % 2 == 0) printf("\n"); // form �ٳ���(�ð� ȿ��
        if (i == 10 || i % 30 == 0) printf("\n"); // form �ٳ���(�ð� ȿ��
        
        if (check[i] == 0) printf("\t%2d.Empty\t",i+1); // ���� ���� �¼�
        else if (check[i] == 1) printf("\t%2d.Full\t\t",i+1); // ���� �Ұ� �¼�
    }
}