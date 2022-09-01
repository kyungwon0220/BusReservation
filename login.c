#include "main.h"

#define loginLen 21

int login() {
	FILE* fp;
	char* Fusername = (char*)malloc(sizeof(char) * loginLen); // 파일에서 username 읽어올 변수
	char* Fpassword = (char*)malloc(sizeof(char) * loginLen); // 파일에서 password 읽어올 변수

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




	// 회원 파일 open
	fp = fopen("memberList.txt", "r");
	if (fp == NULL) { // 파일 부재시
		fp = fopen("memberList.txt", "w"); // 파일 생성
		fclose(fp);
		fp = fopen("memberList.txt", "r"); // 읽기(Read 모드로 파일 open
	}


	// root 로그인 성공시
	if ( strcmp(username, "root") == 0 && strcmp(password, "pass") == 0 ) {
		printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
		printf("\n\n\n\t\t\t\tPress any key to continue...");
		_getch(); //holds the screen
		system("cls");
		return 0;
	}
	//else { // 로그인 실패시 break;
	//	printf("\n\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
	//	printf("\n\n\n\t\t\t\tPress any key to Retry...");
	//	_getch(); //holds the screen
	//	system("cls");
	//	return 1;
	//}


	// 회원 확인(login
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
				fclose(fp); // fopen 용무 종료
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
				fclose(fp); // fopen 용무 종료
				return 1;
			}
		}
	} // while문 end

	{// while문이 끝났는데 return 하지 못하였다면,
		printf("\n\n\n\t\t\tSORRY !!!!  LOGIN IS UNSUCESSFUL");
		printf("\n\n\t\t\t입력한 USERNAME 으로는, 회원이 아닙니다.");
		printf("\n\n\n\t\t\t\t\tPress any key to Retry...");
		_getch(); //holds the screen

		free(username);
		free(password);
		free(Fusername);
		free(Fpassword);
		fclose(fp); // fopen 용무 종료
		return 1;
	}
}