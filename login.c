#include "main.h"

#define loginLen 21

int login() {
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

	// root �α��� ������
	if ( strcmp(username, "root") == 0 && strcmp(password, "pass") == 0 ) {
		printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
		printf("\n\n\n\t\t\t\tPress any key to continue...");
		_getch(); //holds the screen
		system("cls");
		return 0;
	}
	else { // �α��� ���н� break;
		printf("\n\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		printf("\n\n\n\t\t\t\tPress any key to Retry...");
		_getch(); //holds the screen
		system("cls");
		return 1;
	}
}