#include "main.h"

main() {
    int ChoseService;




	//// 로그인 form
	//for (int i = 0; i < 3; i++) {
	//	
	//	if (login() == 0) break; // 로그인 성공시 break;
	//	
 //       // 로그인 3회 실패시
 //       if (i == 2) {
 //           printf("\nSorry you have entered the wrong username and password for %d times!!!\n", i+1);
 //           printf("\n\n\n\t\t\t\tPress any key to continue...");
 //           _getch(); //holds the screen
 //       }
	//}



    
    do {
        system("cls");
        printf("\n\n\n");
        printf("====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n");
        printf("\t\t\t\t\t[1]=> View Bus List\n");
        printf("\n");
        printf("\t\t\t\t\t[2]=> Book Tickets\n");
        printf("\n");
        printf("\t\t\t\t\t[3]=> Cancle Booking\n");
        printf("\n");
        printf("\t\t\t\t\t[4]=> Bus Status Board\n");
        printf("\n");
        printf("\t\t\t\t\t[5]=> Exit\n\n");
        printf("===============================================================================================================\n\n");
        printf("\t\t\tEnter Your Choice:: ");
        scanf("%d", &ChoseService);

        switch (ChoseService) {
        case 1:
            ViewBusList();
            break;
        case 2:
            //BookTickets();
            break;
        case 3:
            //CancleBooking();
            break;
        case 5:
            system("CLS");
            printf("\t----------------------------------------------------------------------------------------------------------\n");
            printf("\t\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n");
            printf("\t----------------------------------------------------------------------------------------------------------\n");
            printf("\t\t\t Brought To You By Lee_kyungwon");
            printf("\n\n\n\t\t\t\tPress any key to Exit...");
            break;
        } //switch end

        _getch(); //holds the screen

    } while (ChoseService != 5);
} //main end

