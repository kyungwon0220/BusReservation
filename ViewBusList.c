#include "main.h"

char* Buss[] = {"������", "������", "�뱸��", "�λ���", "������"};

void ViewBusList() {
    system("cls");
    printf("\n\n\n");
    printf("=========================================== KOSTA BUS RESERVATION SYSTEM ============================================\n\n\n");
    
    for (int i = 0; i < strlen(Buss) - 1; i++)
        printf("\t\t\t\t\t[No.%d�� BUS]    KOSTA -> %s\n\n", i+1, Buss[i]);

    printf("\n\n\n\t\t\t\tPress any key to Return...");
}