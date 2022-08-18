#include "main.h"

main() {
    char* p = (char*)malloc(sizeof(char) * Seats);

    int i; // for문 연산 변수
    int* check = (int*)malloc(sizeof(int) * Seats); // 좌석 현황 체크 위한 변수
    int full; // 버스 만석 체크 위한 변수

    int ChoseService;
    int Cho_BusNum;
    int bookingSeats;



    
 //   // 로그인 form
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
        // 첫 화면
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

                        
            SeatFileOpenReadMode(Cho_BusNum, p); // 선택한 버스의 파일 內 좌석 현황 문자열 == *p;


            {// 버스 좌석 현황 체킹
                full = 0; // 만석 체킹 前 초기화

                for (i = 0; i < Seats; i++) {
                    check[i] = 0; // 좌석 체킹 前 ' 0 ' 으로 초기화

                    if (p[i] == '1') {
                        full++;
                        check[i] = 1;
                    }                    
                }

                if (full == Seats) { // 만석시
                    ViewBusSeats(Cho_BusNum, check); // 현재 좌석 현황 form
                    printf("\nThere is no blank seat in this bus ");
                    printf("\n\n\n\t\t\t\tPress any key to Move back..."); 
                    break; // switch case2 end
                }
            }

            ViewBusSeats(Cho_BusNum, check); // 현재 좌석 현황 form
            printf("\n\n\t\t\t\tEnter the seat number:--->");
            scanf("%d", &bookingSeats); // 예약할 좌석 번호


            if (check[bookingSeats - 1] == 1) {
                printf("\n\n\t\t\t\t\t\t\t\t이미 예약된 좌석으로, 예약이 불가합니다.");
                printf("\n\t\t\t\tPress any key to Move back...\n\t\t\t\t\tPlease Retry...");
            }
            else if (check[bookingSeats - 1] == 0) {
                check[bookingSeats - 1] = 1; // check[선택한 좌석] = (int)1;

                SeatFileWriteAddMode(Cho_BusNum, bookingSeats, check);

                ViewBusSeats(Cho_BusNum, check); // 예약 완료(갱신 된 form
                printf("\n\n\n\t\t\t\t\t\t\t\t%d번 좌석 Booking Success\n\t\t\t\tPress any key to Move back...", bookingSeats);
            }
            
            break; // switch case2 end




        case 3: // Cancleing
            system("cls");
            printf("\n\n\n");
            printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
            ViewBusList();
            printf("Enter the Bus \" Only NUMBER \" :--->");
            scanf("%d", &Cho_BusNum); //for entering bus number


            SeatFileOpenReadMode(Cho_BusNum, p); // 선택한 버스의 파일 內 좌석 현황 문자열 == *p;


            {// 버스 좌석 현황 체킹
                full = Seats; // 만석 체킹 前 초기화

                for (i = 0; i < Seats; i++) {
                    check[i] = 0; // 좌석 체킹 前 ' 0 ' 으로 초기화

                    if (p[i] == '1') {
                        full--;
                        check[i] = 1;
                    }
                }

                if (full == Seats) { // 예약되어 있는 좌석이 없을시
                    ViewBusSeats(Cho_BusNum, check); // 현재 좌석 현황 form
                    printf("\n예약된 좌석이 없어, 취소할 내용이 없습니다.");
                    printf("\n\n\n\t\t\t\tPress any key to Move back...");
                    break; // switch case3 end
                }
            }

            ViewBusSeats(Cho_BusNum, check); // 현재 좌석 현황 form
            printf("\n\n\t\t\t\tEnter the seat number:--->");
            scanf("%d", &bookingSeats); // 예약 취소할 좌석 번호


            if (check[bookingSeats - 1] == 0) {
                printf("\n\n\t\t\t\t\t\t\t\t예약 내역이 없는 좌석으로, 예약 취소가 불가합니다.");
                printf("\n\t\t\t\tPress any key to Move back...\n\t\t\t\t\tPlease Retry...");
            }
            else if (check[bookingSeats - 1] == 1) {
                check[bookingSeats - 1] = 0; // check[선택한 좌석] = (int)0;

                SeatFileWriteAddMode(Cho_BusNum, bookingSeats, check);

                ViewBusSeats(Cho_BusNum, check); // 취소 완료(갱신 된 form
                printf("\n\n\n\t\t\t\t\t\t\t\t%d번 좌석 Cancleing Success\n\t\t\t\tPress any key to Move back...", bookingSeats);
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

    } while (ChoseService != 5);
} //main end

