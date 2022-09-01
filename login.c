#include "main.h"

#define loginLen 21

int login() {
	FILE* fp;
	char* Fusername = (char*)malloc(sizeof(char) * loginLen); // ���Ͽ��� username �о�� ����
	char* Fpassword = (char*)malloc(sizeof(char) * loginLen); // ���Ͽ��� password �о�� ����

	// �˳� 20���� �Է� ���� ����
	char* username = (char*)malloc(sizeof(char) * loginLen);
	char* password = (char*)malloc(sizeof(char) * loginLen);

	printf("\n  =========================  LOGIN FORM  =========================  ");
	printf(" \n                       ENTER USERNAME:-");
	scanf("%s", username);
	printf(" \n                       ENTER PASSWORD:-");


	// ��й�ȣ �Է�
	for (int i = 0; i < loginLen; i++) {
		password[i] = _getch();
		
		if (password[i] == 13) // Enter �����ڸ� �Է½�
		{
			password[i] = '\0'; // ���ڿ� ��ó��
			break; // ��й�ȣ �Է� break;
		} else printf("*");
	}




	// ȸ�� ���� open
	fp = fopen("memberList.txt", "r");
	if (fp == NULL) { // ���� �����
		fp = fopen("memberList.txt", "w"); // ���� ����
		fclose(fp);
		fp = fopen("memberList.txt", "r"); // �б�(Read ���� ���� open
	}


	// root �α��� ������
	if ( strcmp(username, "root") == 0 && strcmp(password, "pass") == 0 ) {
		printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
		printf("\n\n\n\t\t\t\tPress any key to continue...");
		_getch(); //holds the screen
		system("cls");
		return 0;
	}
	//else { // �α��� ���н� break;
	//	printf("\n\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
	//	printf("\n\n\n\t\t\t\tPress any key to Retry...");
	//	_getch(); //holds the screen
	//	system("cls");
	//	return 1;
	//}


	// ȸ�� Ȯ��(login
	while (fscanf(fp, "%s %s", Fusername, Fpassword) != EOF) {
		if (strcmp(Fusername, username) == 0) { // ID clear
			if (strcmp(Fpassword, password) == 0) { // PW clear
				printf("\n\n\n\t\t\tWELCOME TO OUR SYSTEM !!!! \" %s \" LOGIN IS SUCCESSFUL", username);
				printf("\n\n\n\t\t\t\t\tPress any key to continue...");
				_getch(); //holds the screen

				free(username);
				free(password);
				free(Fusername);
				free(Fpassword);
				fclose(fp); // fopen �빫 ����
				return 0;
			}
			else { // PW ERROR
				printf("\n\n\n\t\t\tSORRY !!!!  LOGIN IS UNSUCESSFUL");
				printf("\n\n\t\t\tPASSWORD ERROR");
				printf("\n\n\n\t\t\t\t\tPress any key to Retry...");
				_getch(); //holds the screen

				free(username);
				free(password);
				free(Fusername);
				free(Fpassword);
				fclose(fp); // fopen �빫 ����
				return 1;
			}
		}
	} // while�� end

	{// while���� �����µ� return ���� ���Ͽ��ٸ�,
		printf("\n\n\n\t\t\tSORRY !!!!  LOGIN IS UNSUCESSFUL");
		printf("\n\n\t\t\t�Է��� USERNAME ���δ�, ȸ���� �ƴմϴ�.");
		printf("\n\n\n\t\t\t\t\tPress any key to Retry...");
		_getch(); //holds the screen

		free(username);
		free(password);
		free(Fusername);
		free(Fpassword);
		fclose(fp); // fopen �빫 ����
		return 1;
	}
}