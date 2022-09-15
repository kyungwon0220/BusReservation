#include "main.h"

#define loginLen 21 // login.c 파일에서의 define과는 ' 별개 ' define

void SignUp() {
	unsigned short SignUserName = 1; // USERNAME 생성시, while 조건
	unsigned short SignPW = 1; // PW 생성시, while 조건
	FILE* fp;
	char* tmpName = (char*)malloc(sizeof(char) * loginLen); // 체킹을 위해, 파일을 읽어와서 저장할 변수
	char* tmpPtr;

	char* tmpID = (char*)malloc(sizeof(char) * loginLen);
	char* tmpPW = (char*)malloc(sizeof(char) * loginLen);
	char* tmpPW2 = (char*)malloc(sizeof(char) * loginLen); // PW 체킹을 위한 변수

	int PWLevel[3] = { 0, }; // PW 보안 수준을 측정하기 위한 배열
	



	// USERNAME 先 생성
	do {
		system("cls");
		printf("\n\n\n");
		printf("\n\t\t\t===================  SignUp FORM  ===================\n");
		printf("\n\t\t\t* USERNAME, PASSWORD 최대 길이는 %d 입니다. (한글 입력시 %d\n", loginLen, loginLen / 2);
		printf("\n\t\t\t_____________________________________________________");
		printf("\n\t\t\t\t\tINSERT USERNAME:\t");

		scanf("%s", tmpID);

		if (strlen(tmpID) < 5) {
			printf("\n\t\t\t\t\tUSERNAME Error : strlen(USERNAME) < 5\t가입 실패\n");
			printf("\n\t\t\t--------------------------------------------------\n");
			printf("\t\t\t\t\tUSERNAME 다시 입력해 주세요\n");

			_getch(); //holds the screen
			continue;
		}

		{// USERNAME 중복 체킹			
			FILE* fp = fopen("memberList.txt", "r"); // 회원 파일을 읽기 모드로 fopen

			while (!feof(fp)) {
				tmpPtr = fgets(tmpName, loginLen + 1, fp);
				tmpPtr = strtok(tmpName, " ");

				if (strcmp(tmpPtr, tmpID) == 0) { // USERNAME 중복시
					printf("\n\n\n\t\t\tSORRY !!!!");
					printf("\n\t\t\t\t\tUSERNAME Error : 중복된 USERNAME\t가입 실패\n");
					printf("\n\t\t\t--------------------------------------------------\n");
					printf("\t\t\t\t\tUSERNAME 다시 입력해 주세요\n");

					_getch(); //holds the screen
					break;
				}
			}

			if (strcmp(tmpPtr, tmpID) != 0) { // USERNAME 중복 없을시
				SignUserName = 0; // while end

				free(tmpName);
				fclose(fp);
			}
		}
	} while (SignUserName); // USERNAME 생성 조건


	// PASSWORD 생성
	do {
		do {
			system("cls");
			printf("\n\n\n");
			printf("\n\t\t\t===================  SignUp FORM  ===================\n");
			printf("\n\t\t\t* USERNAME, PASSWORD 최대 길이는 %d 입니다. (한글 입력시 %d\n", loginLen, loginLen / 2);
			printf("\n\t\t\t_____________________________________________________");
			printf("\n\t\t\t\t\tINSERT USERNAME:\t%s", tmpID);
			printf("\n\t\t\t\t\tINSERT PASSWORD:\t");


			for (int i = 0; i < sizeof(PWLevel) / sizeof(PWLevel[0]); i++) PWLevel[i] = 0; // 입력 前, ' 0 ' 으로 초기화
			
			// 비밀번호 입력
			for (int i = 0; i < loginLen; i++) {
				tmpPW[i] = _getch();
				if (tmpPW[i] == 13) { // Enter 개행자를 입력시
					tmpPW[i] = '\0'; // 문자열 끝처리
					SignPW = 0; // PW 입력 end

					if (i < 5) {
						printf("\n\t\t\t\t\tPASSWORD Error : strlen(PASSWORD) < 5\t가입 실패\n");
						printf("\n\t\t\t--------------------------------------------------\n");
						printf("\t\t\t\t\tPASSWORD 다시 입력해 주세요\n");

						_getch(); //holds the screen
						SignPW = 1; // 비밀번호 입력 while
						break;
					}
					break;
				}
				else {
					printf("*");

					{// PW 보안 수준 측정을 위한 카운트
						if (tmpPW[i] >= 'A' && tmpPW[i] <= 'Z') PWLevel[0]++; // PW[i] == 대문자 경우
						else if (tmpPW[i] >= 'a' && tmpPW[i] <= 'z') PWLevel[1]++; // PW[i] == 소문자 경우
						else if (tmpPW[i] >= '0' && tmpPW[i] <= '9') PWLevel[1]++; // PW[i] == 숫자 경우
						else if ((tmpPW[i] >= 33 && tmpPW[i] <= 47) || (tmpPW[i] >= 58 && tmpPW[i] <= 64) || (tmpPW[i] >= 91 && tmpPW[i] <= 96) || (tmpPW[i] >= 123 && tmpPW[i] <= 126)) PWLevel[2]++; // PW[i] == 특수 문자 경우
					}

					{// PW 보안 수준
						//printf("%d, %d, %d,\n", PWLevel[0], PWLevel[1], PWLevel[2]);
					}
				}
			}
		} while (SignPW); // PW 생성 조건


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