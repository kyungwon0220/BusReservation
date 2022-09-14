#include "main.h"

#define loginLen 21 // login.c 파일에서의 define과는 ' 별개 ' define

void SignUp() {
	FILE* fp;
	char* tmpID = (char*)malloc(sizeof(char) * loginLen);
	char* tmpPW = (char*)malloc(sizeof(char) * loginLen);
	char* tmpPW2 = (char*)malloc(sizeof(char) * loginLen); // PW 체킹위한 변수




	// USERNAME 先 생성
	do {
		system("cls");
		printf("\n\n\n");
		printf("\n\t\t\t===================  SignUp FORM  ===================\n");
		printf("\n\t\t\t\t\tINSERT USERNAME:\t");

		scanf("%s", tmpID);

		if (strlen(tmpID) < 5) {
			printf("\n\t\t\t\t\tUSERNAME Error : strlen(USERNAME) < 5\t가입 실패\n");
			printf("\n\t\t\t--------------------------------------------------\n");
			printf("\t\t\t\t\tUSERNAME 다시 입력해 주세요\n");
			_getch(); //holds the screen
		}
	} while (strlen(tmpID) < 5); // USERNAME 생성 조건
	

	do {
		system("cls");
		printf("\n\n\n");
		printf("\n\t\t\t===================  SignUp FORM  ===================\n");
		printf("\n\t\t\t\t\tINSERT USERNAME:\t%s", tmpID);
		printf("\n\t\t\t\t\tINSERT PASSWORD:\t");


		// 비밀번호 입력
		for (int i = 0; i < loginLen; i++) {
			tmpPW[i] = _getch();
			if (tmpPW[i] == 13) { // Enter 개행자를 입력시
				tmpPW[i] = '\0'; // 문자열 끝처리
				break;
			}
			else printf("*");
		}


		printf("\n\n\t\t\t\t\tPASSWORD Check :\t");
		for (int i = 0; i < loginLen; i++) {
			tmpPW2[i] = _getch();
			if (tmpPW2[i] == 13) { // Enter 개행자를 입력시
				tmpPW2[i] = '\0'; // 문자열 끝처리
				break;
			}
			else printf("*");
		}


		if (strcmp(tmpPW, tmpPW2) != 0) { // PASSWORD ERROR시
			printf("\n\t\t\t\t\tPASSWORD Error : 가입 실패\n");
			printf("\n\t\t\t--------------------------------------------------\n");
			printf("\t\t\t\t\tPASSWORD 다시 입력해 주세요\n");
			_getch(); //holds the screen
		}
		else {
			printf("\n\n\n\t\t\t\t\t가입 완료!\n");
			printf("\n로그인으로 이동합니다.\n");
			printf("===============================================================================================================\n\n");
			_getch(); //holds the screen
		}
	} while (strcmp(tmpPW, tmpPW2) != 0);
	free(tmpPW2);




	fp = fopen("memberList.txt", "a");
	if (fp == NULL) { // 파일 부재시
		//fp = fopen("memberList.txt", "w"); // 파일 생성
	}

	fprintf(fp, "%s %s\n", tmpID, tmpPW); // 회원 파일에 저장
	free(tmpID);
	free(tmpPW);
	fclose(fp); // fopen 용무 종료
}