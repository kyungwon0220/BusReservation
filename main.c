#include "main.h"

// ���� ����
const char* Bus_to[] = { "������", "������", "�뱸��", "�λ���", "������" }; // �༱�� ���� �迭
const char* Bus_price[] = { "5,000\\ - 10,000\\", "10,000\\ - 15,000\\", "15,000\\ - 20,000\\", "20,000\\ - 25,000\\", "25,000\\ - 30,000\\" }; // ���� ���� �迭
const char* Bus_fileName[] = { "bus1.txt", "bus2.txt", "bus3.txt", "bus4.txt", "bus5.txt" }; // �� ������, �¼� ��Ȳ �ؽ�Ʈ ����٣

const int HowManyBus = sizeof(Bus_to) / sizeof(Bus_to[0]); // ���� �� ���
    /*
        ������ �� ���(2���� �迭���� ��(row ����
        �迭�� �����ϴ� ��ü ������, ���� �� ���� ũ��� ������
    */
const int Seats = 40; // ���� �¼� ��




main() {
    char* p = (char*)malloc(sizeof(char) * Seats);

    int i; // for�� ���� ����
    int* check = (int*)malloc(sizeof(int) * Seats); // �¼� ��Ȳ üũ ���� ����
    int vacancy; // ���� ���� üũ ���� ����

    int Cho_Service;
    int Cho_BusNum;
    int Cho_SeatNum;



    
    // ù ȭ��(form
    system("mode con cols=150 lines=50 | title BUS RESERVATION SYSTEM"); // �ܼ� �����, ���� ������ ����
    system("cls");
    printf("\n\n\n");
    printf("====================================== REDY FOR BUS RESERVATION SYSTEM ======================================\n\n\n");
    printf("\t\t\t\t\t[1]=> Login\n");
    printf("\n");
    printf("\t\t\t\t\t[2]=> SignUp\n");
    printf("\n");
    printf("=============================================================================================================\n\n");
    printf("\t\t\tEnter Your Choice:: ");
    scanf("%d", &Cho_Service);

    switch (Cho_Service) {
    case 1: // �α���
        for (int i = 0; i < 3; i++) {
            if (login() == 0) break; // �α��� ������ break;

            // �α��� 3ȸ ���н�
            if (i == 2) {
                system("cls");
                printf("\n\n\n");
                printf("\nSorry you have entered the wrong username and password for %d times!!!\n", i + 1);
                printf("\nȸ�� �������� �̵��մϴ�.\n");
                printf("\n\n\n\t\t\t\t\tPress any key to continue...");
                _getch(); //holds the screen
                SignUp();
            }
        }
        break; // switch case1 end


    case 2: //SignUp
        SignUp();


        {// �α��� (== switch case1
            for (int i = 0; i < 3; i++) {
                if (login() == 0) break; // �α��� ������ break;

                // �α��� 3ȸ ���н�
                if (i == 2) {
                    system("cls");
                    printf("\n\n\n");
                    printf("\nSorry you have entered the wrong username and password for %d times!!!\n", i + 1);
                    printf("\nȸ�� �������� �̵��մϴ�.\n");
                    printf("\n\n\n\t\t\t\t\tPress any key to continue...");
                    _getch(); //holds the screen
                    SignUp();
                }
            }
        }
        break; // switch case2 end
    } // switch end




    do {
        // �α��� ��, ù ȭ��(form
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
        scanf("%d", &Cho_Service);

        switch (Cho_Service) {
        case 1: // View List
            system("cls");
            printf("\n\n\n");
            printf("=========================================== KOSTA BUS RESERVATION SYSTEM ============================================\n\n\n");
            ViewBusList(HowManyBus, Bus_to, Bus_price);
            printf("\n\n\n\t\t\t\tPress any key to Move back...");
            break; // switch case1 end




        case 2: // Booking
            system("cls");
            printf("\n\n\n");
            printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
            ViewBusList(HowManyBus, Bus_to, Bus_price);
            printf("Enter the Bus \" Only NUMBER \" :--->");
            scanf("%d", &Cho_BusNum); //for entering bus number


            SeatFileOpenReadMode(Bus_fileName[Cho_BusNum - 1], Seats, p); // ������ ������ ���� Ү �¼� ��Ȳ ���ڿ� == *p;


            {// ���� �¼� ��Ȳ üŷ
                vacancy = 0; // ���� üŷ �� �ʱ�ȭ

                for (i = 0; i < Seats; i++) {
                    check[i] = 0; // �¼� üŷ �� ' 0 ' ���� �ʱ�ȭ

                    if (p[i] == '1') {
                        vacancy++;
                        check[i] = 1;
                    }                    
                }

                if (vacancy == Seats) { // ������
                    ViewBusSeats(Cho_BusNum, Bus_to, Seats, check); // ���� �¼� ��Ȳ form
                    printf("\nThere is no blank seat in this bus ");
                    printf("\n\n\n\t\t\t\tPress any key to Move back..."); 
                    break; // switch case2 end
                }
            }

            ViewBusSeats(Cho_BusNum, Bus_to, Seats, check); // ���� �¼� ��Ȳ form
            printf("\n\n\t\t\t\tEnter the seat number:--->");
            scanf("%d", &Cho_SeatNum); // ������ �¼� ��ȣ


            if (check[Cho_SeatNum - 1] == 1) {
                printf("\n\n\t\t\t\t\t\t\t\t�̹� ����� �¼�����, ������ �Ұ��մϴ�.");
                printf("\n\t\t\t\tPress any key to Move back...\n\t\t\t\t\tPlease Retry...");
            }
            else if (check[Cho_SeatNum - 1] == 0) {
                check[Cho_SeatNum - 1] = 1; // check[������ �¼�] = (int)1;

                SeatFileWriteAddMode(Bus_fileName[Cho_BusNum - 1], Seats, check);

                ViewBusSeats(Cho_BusNum, Bus_to, Seats, check); // ���� �¼� ��Ȳ form
                printf("\n\n\n\t\t\t\t\t\t\t\t%d�� �¼� Booking Success\n\t\t\t\tPress any key to Move back...", Cho_SeatNum);
            }
            
            break; // switch case2 end




        case 3: // Cancleing
            system("cls");
            printf("\n\n\n");
            printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
            ViewBusList(HowManyBus, Bus_to, Bus_price);
            printf("Enter the Bus \" Only NUMBER \" :--->");
            scanf("%d", &Cho_BusNum); //for entering bus number


            SeatFileOpenReadMode(Bus_fileName[Cho_BusNum - 1], Seats, p); // ������ ������ ���� Ү �¼� ��Ȳ ���ڿ� == *p;


            {// ���� �¼� ��Ȳ üŷ
                vacancy = Seats; // üŷ �� �ʱ�ȭ

                for (i = 0; i < Seats; i++) {
                    check[i] = 0; // �¼� üŷ �� ' 0 ' ���� �ʱ�ȭ

                    if (p[i] == '1') {
                        vacancy--;
                        check[i] = 1;
                    }
                }

                if (vacancy == Seats) { // ����Ǿ� �ִ� �¼��� ������
                    ViewBusSeats(Cho_BusNum, Bus_to, Seats, check); // ���� �¼� ��Ȳ form
                    printf("\n����� �¼��� ����, ����� ������ �����ϴ�.");
                    printf("\n\n\n\t\t\t\tPress any key to Move back...");
                    break; // switch case3 end
                }
            }

            ViewBusSeats(Cho_BusNum, Bus_to, Seats, check); // ���� �¼� ��Ȳ form
            printf("\n\n\t\t\t\tEnter the seat number:--->");
            scanf("%d", &Cho_SeatNum); // ���� ����� �¼� ��ȣ


            if (check[Cho_SeatNum - 1] == 0) {
                printf("\n\n\t\t\t\t\t\t\t\t���� ������ ���� �¼�����, ���� ��Ұ� �Ұ��մϴ�.");
                printf("\n\t\t\t\tPress any key to Move back...\n\t\t\t\t\tPlease Retry...");
            }
            else if (check[Cho_SeatNum - 1] == 1) {
                check[Cho_SeatNum - 1] = 0; // check[������ �¼�] = (int)0;

                SeatFileWriteAddMode(Bus_fileName[Cho_BusNum - 1], Seats, check);

                ViewBusSeats(Cho_BusNum, Bus_to, Seats, check); // ���� �¼� ��Ȳ form
                printf("\n\n\n\t\t\t\t\t\t\t\t%d�� �¼� Cancleing Success\n\t\t\t\tPress any key to Move back...", Cho_SeatNum);
            }
            break; // switch case3 end




        case 5: // Exit
            system("CLS");
            printf("\t----------------------------------------------------------------------------------------------------------\n");
            printf("\t\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n");
            printf("\t----------------------------------------------------------------------------------------------------------\n");
            printf("\t\t\t Brought To You By Lee_kyungwon");
            printf("\n\n\n\t\t\t\tPress any key to Exit...");
            break;
        } //switch case 5 end

        _getch(); //holds the screen

    } while (Cho_Service != 5);
} //main end

