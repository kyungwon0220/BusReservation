#include "main.h"

void SeatFileWriteAddMode(int Cho_BusNum, int bookingSeats, int* check) {
	FILE* fp; // fopen ���� ����

	switch (Cho_BusNum) { // �� ���� No. (��ȣ�� case
	case 1:
		// ���� ���� ��ü ����
		fp = fopen("Bus1.txt", "w");
		fclose(fp);

		// ���� ���� ���� �Է�
		fp = fopen("Bus1.txt", "a");
		for (int i = 0; i < Seats; i++) {
			if (check[i] == 0) putc('0', fp);
			else if (check[i] == 1) putc('1', fp);			
		}

		fclose(fp); // fopen �빫 ����
		
		break; // switch case1 end


	case 2:
		// ���� ���� ��ü ����
		fp = fopen("Bus2.txt", "w");
		fclose(fp);

		// ���� ���� ���� �Է�
		fp = fopen("Bus2.txt", "a");
		for (int i = 0; i < Seats; i++) {
			if (check[i] == 0) putc('0', fp);
			else if (check[i] == 1) putc('1', fp);
		}

		fclose(fp); // fopen �빫 ����

		break; // switch case2 end


	case 3:
		// ���� ���� ��ü ����
		fp = fopen("Bus3.txt", "w");
		fclose(fp);

		// ���� ���� ���� �Է�
		fp = fopen("Bus3.txt", "a");
		for (int i = 0; i < Seats; i++) {
			if (check[i] == 0) putc('0', fp);
			else if (check[i] == 1) putc('1', fp);
		}

		fclose(fp); // fopen �빫 ����

		break; // switch case3 end


	case 4:
		// ���� ���� ��ü ����
		fp = fopen("Bus4.txt", "w");
		fclose(fp);

		// ���� ���� ���� �Է�
		fp = fopen("Bus4.txt", "a");
		for (int i = 0; i < Seats; i++) {
			if (check[i] == 0) putc('0', fp);
			else if (check[i] == 1) putc('1', fp);
		}

		fclose(fp); // fopen �빫 ����

		break; // switch case4 end


	case 5:
		// ���� ���� ��ü ����
		fp = fopen("Bus5.txt", "w");
		fclose(fp);

		// ���� ���� ���� �Է�
		fp = fopen("Bus5.txt", "a");
		for (int i = 0; i < Seats; i++) {
			if (check[i] == 0) putc('0', fp);
			else if (check[i] == 1) putc('1', fp);
		}

		fclose(fp); // fopen �빫 ����

		break; // switch case5 end
	}
}