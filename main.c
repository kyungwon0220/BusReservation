#include "main.h"

main() {
    char* p = (char*)malloc(sizeof(char) * Seats);

    int i; // for�� ���� ����
    int* check = (int*)malloc(sizeof(int) * Seats); // �¼� ��Ȳ üũ ���� ����
    int full; // ���� ���� üũ ���� ����

    int ChoseService;
    int Cho_BusNum;
    int bookingSeats;



    
    //// �α��� form
	//for (int i = 0; i < 3; i++) {
	//	
	//	if (login() == 0) break; // �α��� ������ break;
	//	
 //       // �α��� 3ȸ ���н�
 //       if (i == 2) {
 //           printf("\nSorry you have entered the wrong username and password for %d times!!!\n", i+1);
 //           printf("\n\n\n\t\t\t\tPress any key to continue...");
 //           _getch(); //holds the screen
 //       }
	//}



    
    do {
        // ù ȭ��
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
        case 1: // View List
            system("cls");
            printf("\n\n\n");
            printf("=========================================== KOSTA BUS RESERVATION SYSTEM ============================================\n\n\n");
            ViewBusList();
            printf("\n\n\n\t\t\t\tPress any key to Move back...");
            break; // switch case1 end




        case 2: // Booking
            system("cls");
            printf("\n\n\n");
            printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
            ViewBusList();
            printf("Enter the Bus \" Only NUMBER \" :--->");
            scanf("%d", &Cho_BusNum); //for entering bus number

                        
            SeatFileOpenReadMode(Cho_BusNum, p); // ������ ������ ���� Ү �¼� ��Ȳ ���ڿ� == *p;


            {// ���� �¼� ��Ȳ üŷ
                full = 0; // ���� üŷ �� �ʱ�ȭ

                for (i = 0; i < Seats; i++) {
                    check[i] = 0; // �¼� üŷ �� ' 0 ' ���� �ʱ�ȭ

                    if (p[i] == '1') {
                        full++;
                        check[i] = 1;
                    }                    
                }

                if (full == Seats) { // ������
                    ViewBusSeats(Cho_BusNum, check); // ���� �¼� ��Ȳ form
                    printf("\nThere is no blank seat in this bus ");
                    printf("\n\n\n\t\t\t\tPress any key to Move back..."); 
                    break; // switch case2 end
                }
            }

            ViewBusSeats(Cho_BusNum, check); // ���� �¼� ��Ȳ form
            printf("\n\n\t\t\t\tNumber of Tickets:----->");
            scanf("%d", &bookingSeats); // ������ �¼� ��ȣ


            if (check[bookingSeats - 1] == 1) {
                printf("\n\n\t\t\t\t\t\t\t\t�̹� ����� �¼�����, ������ �Ұ��մϴ�.");
                printf("\n\t\t\t\tPress any key to Move back...\n\t\t\t\t\tPlease Retry...");
            }
            else if (check[bookingSeats - 1] == 0) {
                check[bookingSeats - 1] = 1; // check[������ �¼�] = (int)1;

                SeatFileWriteAddMode(Cho_BusNum, bookingSeats, check);

                ViewBusSeats(Cho_BusNum, check); // ���� �Ϸ�(���� �� form
                printf("\n\n\n\t\t\t\t\t\t\t\t%d�� �¼� Booking Success\n\t\t\t\tPress any key to Move back...", bookingSeats);
            }
            
            break; // switch case2 end




        case 3: // Cancleing
            //CancleBooking();
            break;




        case 5: // Exit
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

