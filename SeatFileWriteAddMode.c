#include "main.h"

void SeatFileWriteAddMode(int Cho_BusNum, int bookingSeats, int* check) {
	FILE* fp; // fopen 위한 변수

	switch (Cho_BusNum) { // 각 버스 No. (번호별 case
	case 1:
		// 파일 내용 전체 삭제
		fp = fopen("Bus1.txt", "w");
		fclose(fp);

		// 파일 내용 새로 입력
		fp = fopen("Bus1.txt", "a");
		for (int i = 0; i < Seats; i++) {
			if (check[i] == 0) putc('0', fp);
			else if (check[i] == 1) putc('1', fp);			
		}

		fclose(fp); // fopen 용무 종료
		
		break; // switch case1 end


	case 2:
		// 파일 내용 전체 삭제
		fp = fopen("Bus2.txt", "w");
		fclose(fp);

		// 파일 내용 새로 입력
		fp = fopen("Bus2.txt", "a");
		for (int i = 0; i < Seats; i++) {
			if (check[i] == 0) putc('0', fp);
			else if (check[i] == 1) putc('1', fp);
		}

		fclose(fp); // fopen 용무 종료

		break; // switch case2 end


	case 3:
		// 파일 내용 전체 삭제
		fp = fopen("Bus3.txt", "w");
		fclose(fp);

		// 파일 내용 새로 입력
		fp = fopen("Bus3.txt", "a");
		for (int i = 0; i < Seats; i++) {
			if (check[i] == 0) putc('0', fp);
			else if (check[i] == 1) putc('1', fp);
		}

		fclose(fp); // fopen 용무 종료

		break; // switch case3 end


	case 4:
		// 파일 내용 전체 삭제
		fp = fopen("Bus4.txt", "w");
		fclose(fp);

		// 파일 내용 새로 입력
		fp = fopen("Bus4.txt", "a");
		for (int i = 0; i < Seats; i++) {
			if (check[i] == 0) putc('0', fp);
			else if (check[i] == 1) putc('1', fp);
		}

		fclose(fp); // fopen 용무 종료

		break; // switch case4 end


	case 5:
		// 파일 내용 전체 삭제
		fp = fopen("Bus5.txt", "w");
		fclose(fp);

		// 파일 내용 새로 입력
		fp = fopen("Bus5.txt", "a");
		for (int i = 0; i < Seats; i++) {
			if (check[i] == 0) putc('0', fp);
			else if (check[i] == 1) putc('1', fp);
		}

		fclose(fp); // fopen 용무 종료

		break; // switch case5 end
	}
}