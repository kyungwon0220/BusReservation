#include "main.h"

#define loginLen 21 // login.c ���Ͽ����� define���� ' ���� ' define

void SignUp() {
	FILE* fp;
	char* tmpID = (char*)malloc(sizeof(char) * loginLen);
	char* tmpPW = (char*)malloc(sizeof(char) * loginLen);
	char* tmpPW2 = (char*)malloc(sizeof(char) * loginLen); // PW üŷ���� ����




	// USERNAME � ����
	do {
		system("cls");
		printf("\n\n\n");
		printf("\n\t\t\t===================  SignUp FORM  ===================\n");
		printf("\n\t\t\t\t\tINSERT USERNAME:\t");

		scanf("%s", tmpID);

		if (strlen(tmpID) < 5) {
			printf("\n\t\t\t\t\tUSERNAME Error : strlen(USERNAME) < 5\t���� ����\n");
			printf("\n\t\t\t--------------------------------------------------\n");
			printf("\t\t\t\t\tUSERNAME �ٽ� �Է��� �ּ���\n");
			_getch(); //holds the screen
		}
	} while (strlen(tmpID) < 5); // USERNAME ���� ����
	

	do {
		system("cls");
		printf("\n\n\n");
		printf("\n\t\t\t===================  SignUp FORM  ===================\n");
		printf("\n\t\t\t\t\tINSERT USERNAME:\t%s", tmpID);
		printf("\n\t\t\t\t\tINSERT PASSWORD:\t");


		// ��й�ȣ �Է�
		for (int i = 0; i < loginLen; i++) {
			tmpPW[i] = _getch();
			if (tmpPW[i] == 13) { // Enter �����ڸ� �Է½�
				tmpPW[i] = '\0'; // ���ڿ� ��ó��
				break;
			}
			else printf("*");
		}


		printf("\n\n\t\t\t\t\tPASSWORD Check :\t");
		for (int i = 0; i < loginLen; i++) {
			tmpPW2[i] = _getch();
			if (tmpPW2[i] == 13) { // Enter �����ڸ� �Է½�
				tmpPW2[i] = '\0'; // ���ڿ� ��ó��
				break;
			}
			else printf("*");
		}


		if (strcmp(tmpPW, tmpPW2) != 0) { // PASSWORD ERROR��
			printf("\n\t\t\t\t\tPASSWORD Error : ���� ����\n");
			printf("\n\t\t\t--------------------------------------------------\n");
			printf("\t\t\t\t\tPASSWORD �ٽ� �Է��� �ּ���\n");
			_getch(); //holds the screen
		}
		else {
			printf("\n\n\n\t\t\t\t\t���� �Ϸ�!\n");
			printf("\n�α������� �̵��մϴ�.\n");
			printf("===============================================================================================================\n\n");
			_getch(); //holds the screen
		}
	} while (strcmp(tmpPW, tmpPW2) != 0);
	free(tmpPW2);




	fp = fopen("memberList.txt", "a");
	if (fp == NULL) { // ���� �����
		//fp = fopen("memberList.txt", "w"); // ���� ����
	}

	fprintf(fp, "%s %s\n", tmpID, tmpPW); // ȸ�� ���Ͽ� ����
	free(tmpID);
	free(tmpPW);
	fclose(fp); // fopen �빫 ����
}