#include "main.h"

#define loginLen 21

int FindUserName() {
	FILE* fp = fopen("memberList.txt", "r"); // 회원 파일을 읽기 모드로 fopen

	char* tmpName = (char*)malloc(sizeof(char) * loginLen); // 체킹을 위해, 파일을 읽어와서 저장할 변수
	char* tmpPtr;
	char* SearchName = (char*)malloc(sizeof(char) * loginLen); // 검색을 위한 변수




	system("cls");
	printf("\n\n\n");
	printf("\n\t\t\t=================  FIND USERNAME FORM  =================\n");
	printf("\n\t\t\t\t\tINSERT USERNAME:\t");
	scanf("%s", SearchName); // 검색할 USERNAME

	while (!feof(fp)) {
		tmpPtr = fgets(tmpName, loginLen + 1, fp);
		tmpPtr = strtok(tmpName, " ");

		if (strcmp(tmpPtr, SearchName) == 0) {
			printf("\n\n\n\t\t\tWELCOME TO OUR SYSTEM !!!!\n\n\n\t\t\tUSERNAME \" %s \" 회원이 맞습니다.", SearchName);
			printf("\n\n\n\t\t\t\t\tPress any key to continue...");
			_getch(); //holds the screen

			//free(tmpName); // 활성시, 프로그램 HEAP 관련 오류로 주석 처리(이유 모르겠음
			free(SearchName);
			fclose(fp); // fopen 용무 종료
			return 0;
		}
	} // while end


	{// while문이 끝났는데 return 하지 못하였다면,
		printf("\n\n\n\t\t\tSORRY !!!!");
		printf("\n\n\t\t\t입력한 USERNAME ' %s '으로는, 회원이 아닙니다. 회원 가입을 진행해 주세요.", SearchName);
		printf("\n\t\t\t--------------------------------------------------\n");
		printf("\n\n\n\t\t\t\t\tPress any key to Retry...");
		_getch(); //holds the screen
	}

	//free(tmpName); // 활성시, 프로그램 HEAP 관련 오류로 주석 처리(이유 모르겠음
	free(SearchName);
	fclose(fp); // fopen 용무 종료
	return 1;
}