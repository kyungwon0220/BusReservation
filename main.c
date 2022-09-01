#include "main.h"

// 버스 정보
const char* Bus_to[] = { "서울행", "대전행", "대구행", "부산행", "제주행" }; // 행선지 정보 배열
const char* Bus_price[] = { "5,000\\ - 10,000\\", "10,000\\ - 15,000\\", "15,000\\ - 20,000\\", "20,000\\ - 25,000\\", "25,000\\ - 30,000\\" }; // 가격 정보 배열
const char* Bus_fileName[] = { "bus1.txt", "bus2.txt", "bus3.txt", "bus4.txt", "bus5.txt" }; // 각 버스별, 좌석 현황 텍스트 파일名

const int HowManyBus = sizeof(Bus_to) / sizeof(Bus_to[0]); // 버스 총 대수
    /*
        버스의 총 대수(2차원 배열에서 행(row 값은
        배열이 차지하는 전체 공간을, 가로 한 줄의 크기로 나눠줌
    */
const int Seats = 40; // 버스 좌석 수




main() {
    char* p = (char*)malloc(sizeof(char) * Seats);

    int i; // for문 연산 변수
    int* check = (int*)malloc(sizeof(int) * Seats); // 좌석 현황 체크 위한 변수
    int vacancy; // 버스 만석 체크 위한 변수

    int Cho_Service;
    int Cho_BusNum;
    int Cho_SeatNum;



    
    // 첫 화면(form
    system("mode con cols=150 lines=50 | title BUS RESERVATION SYSTEM"); // 콘솔 실행시, 최초 사이즈 설정
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
    case 1: // 로그인
        for (int i = 0; i < 3; i++) {
            if (login() == 0) break; // 로그인 성공시 break;

            // 로그인 3회 실패시
            if (i == 2) {
                system("cls");
                printf("\n\n\n");
                printf("\nSorry you have entered the wrong username and password for %d times!!!\n", i + 1);
                printf("\n회원 가입으로 이동합니다.\n");
                printf("\n\n\n\t\t\t\t\tPress any key to continue...");
                _getch(); //holds the screen
                SignUp();
            }
        }
        break; // switch case1 end


    case 2: //SignUp
        SignUp();


        {// 로그인 (== switch case1
            for (int i = 0; i < 3; i++) {
                if (login() == 0) break; // 로그인 성공시 break;

                // 로그인 3회 실패시
                if (i == 2) {
                    system("cls");
                    printf("\n\n\n");
                    printf("\nSorry you have entered the wrong username and password for %d times!!!\n", i + 1);
                    printf("\n회원 가입으로 이동합니다.\n");
                    printf("\n\n\n\t\t\t\t\tPress any key to continue...");
                    _getch(); //holds the screen
                    SignUp();
                }
            }
        }
        break; // switch case2 end
    } // switch end




    do {
        // 로그인 후, 첫 화면(form
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
            printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
            ViewBusList(HowManyBus, Bus_to, Bus_price);
            printf("\n\n\n\t\t\t\t\tPress any key to Move back...");
            break; // switch case1 end




        case 2: // Booking
            system("cls");
            printf("\n\n\n");
            printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
            ViewBusList(HowManyBus, Bus_to, Bus_price);
            printf("\n\t\t\tEnter the Bus \" Only NUMBER \" :--->\t");
            scanf("%d", &Cho_BusNum); //for entering bus number


            SeatFileOpenReadMode(Bus_fileName[Cho_BusNum - 1], Seats, p); // 선택한 버스의 파일 內 좌석 현황 문자열 == *p;


            {// 버스 좌석 현황 체킹
                vacancy = 0; // 만석 체킹 前 초기화

                for (i = 0; i < Seats; i++) {
                    check[i] = 0; // 좌석 체킹 前 ' 0 ' 으로 초기화

                    if (p[i] == '1') {
                        vacancy++;
                        check[i] = 1;
                    }                    
                }

                if (vacancy == Seats) { // 만석시
                    ViewBusSeats(Cho_BusNum, Bus_to, Seats, check); // 현재 좌석 현황 form
                    printf("\n\t\t\t\t\tThere is no blank seat in this bus");
                    printf("\n\t--------------------------------------------------\n");
                    printf("\n\n\n\t\t\t\t\tPress any key to Move back...");
                    break; // switch case2 end
                }
            }

            ViewBusSeats(Cho_BusNum, Bus_to, Seats, check); // 현재 좌석 현황 form
            printf("\n\n\n\t\t\t\tEnter the seat number:--->\t");
            scanf("%d", &Cho_SeatNum); // 예약할 좌석 번호


            if (check[Cho_SeatNum - 1] == 1) {
                printf("\n\t\t\t\t\t이미 예약된 좌석으로, 예약이 불가합니다.");
                printf("\n\t--------------------------------------------------\n");
                printf("\n\n\n\t\t\t\t\tPress any key to Move back...");
            }
            else if (check[Cho_SeatNum - 1] == 0) {
                check[Cho_SeatNum - 1] = 1; // check[선택한 좌석] = (int)1;

                SeatFileWriteAddMode(Bus_fileName[Cho_BusNum - 1], Seats, check);

                ViewBusSeats(Cho_BusNum, Bus_to, Seats, check); // 현재 좌석 현황 form
                printf("\n\n\n\t\t\t\t\t%d번 좌석 Booking Success", Cho_SeatNum);
                printf("\n\t--------------------------------------------------\n");
                printf("\n\n\n\t\t\t\t\tPress any key to Move back...");
            }
            
            break; // switch case2 end




        case 3: // Cancleing
            system("cls");
            printf("\n\n\n");
            printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
            ViewBusList(HowManyBus, Bus_to, Bus_price);
            printf("\n\t\t\tEnter the Bus \" Only NUMBER \" :--->\t");
            scanf("%d", &Cho_BusNum); //for entering bus number


            SeatFileOpenReadMode(Bus_fileName[Cho_BusNum - 1], Seats, p); // 선택한 버스의 파일 內 좌석 현황 문자열 == *p;


            {// 버스 좌석 현황 체킹
                vacancy = Seats; // 체킹 前 초기화

                for (i = 0; i < Seats; i++) {
                    check[i] = 0; // 좌석 체킹 前 ' 0 ' 으로 초기화

                    if (p[i] == '1') {
                        vacancy--;
                        check[i] = 1;
                    }
                }

                if (vacancy == Seats) { // 예약되어 있는 좌석이 없을시
                    ViewBusSeats(Cho_BusNum, Bus_to, Seats, check); // 현재 좌석 현황 form
                    printf("\n\t\t\t\t\t예약된 좌석이 없어, 취소할 내용이 없습니다.");
                    printf("\n\t--------------------------------------------------\n");
                    printf("\n\n\n\t\t\t\t\tPress any key to Move back...");
                    break; // switch case3 end
                }
            }

            ViewBusSeats(Cho_BusNum, Bus_to, Seats, check); // 현재 좌석 현황 form
            printf("\n\n\n\t\t\t\tEnter the seat number:--->\t");
            scanf("%d", &Cho_SeatNum); // 예약 취소할 좌석 번호


            if (check[Cho_SeatNum - 1] == 0) {
                printf("\n\t\t\t\t\t예약 내역이 없는 좌석으로, 예약 취소가 불가합니다.");
                printf("\n\t--------------------------------------------------\n");
                printf("\n\n\n\t\t\t\t\tPress any key to Move back...");
            }
            else if (check[Cho_SeatNum - 1] == 1) {
                check[Cho_SeatNum - 1] = 0; // check[선택한 좌석] = (int)0;

                SeatFileWriteAddMode(Bus_fileName[Cho_BusNum - 1], Seats, check);

                ViewBusSeats(Cho_BusNum, Bus_to, Seats, check); // 현재 좌석 현황 form
                printf("\n\n\n\t\t\t\t\t%d번 좌석 Cancleing Success", Cho_SeatNum);
                printf("\n\t--------------------------------------------------\n");
                printf("\n\n\n\t\t\t\t\tPress any key to Move back...");
            }
            break; // switch case3 end




        case 5: // Exit
            system("CLS");
            printf("---------------------------------------------------------------------------------------------------------------\n\n");
            printf("\t\t\t\t\tThank You For Using This System\t\t\t\t\t\n");
            printf("---------------------------------------------------------------------------------------------------------------\n\n");
            printf("\t\t\t\t\t\t\t\t\t\tMade by Lee_kyungwon");
            printf("\n\n\n\t\t\t\t\tPress any key to Exit...\n\n\n");
            break;
        } //switch case 5 end

        _getch(); //holds the screen

    } while (Cho_Service != 5);
} //main end