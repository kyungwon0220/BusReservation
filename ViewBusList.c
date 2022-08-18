#include "main.h"

char* Buss[] = {"辑匡青", "措傈青", "措备青", "何魂青", "力林青"};

void ViewBusList() {
    system("cls");
    printf("\n\n\n");
    printf("=========================================== KOSTA BUS RESERVATION SYSTEM ============================================\n\n\n");
    
    for (int i = 0; i < strlen(Buss) - 1; i++)
        printf("\t\t\t\t\t[No.%d锅 BUS]    KOSTA -> %s\n\n", i+1, Buss[i]);

    printf("\n\n\n\t\t\t\tPress any key to Return...");
}