#include "main.h"

#define loginLen 21

int login() {
	// 넉넉 20문자 입력 가능 제한
	char* username = (char*)malloc(sizeof(char) * loginLen);
	char* password = (char*)malloc(sizeof(char) * loginLen);

	printf("\n  =========================  LOGIN FORM  =========================  ");
	printf(" \n                       ENTER USERNAME:-");
	scanf("%s", username);
	printf(" \n                       ENTER PASSWORD:-");


	// 비밀번호 입력
	for (int i = 0; i < loginLen; i++) {
		password[i] = _getch();
		
		if (password[i] == 13) // Enter 개행자를 입력시
		{
			password[i] = '\0'; // 문자열 끝처리
			break; // 비밀번호 입력 break;
		} else printf("*");
	}

	// root 로그인 성공시
	if ( strcmp(username, "root") == 0 && strcmp(password, "pass") == 0 ) {
		printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
		printf("\n\n\n\t\t\t\tPress any key to continue...");
		_getch(); //holds the screen
		system("cls");
		return 0;
	}
	else { // 로그인 실패시 break;
		printf("\n\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		printf("\n\n\n\t\t\t\tPress any key to Retry...");
		_getch(); //holds the screen
		system("cls");
		return 1;
	}
}