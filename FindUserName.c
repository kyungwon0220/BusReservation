#include "main.h"

#define loginLen 21

int FindUserName() {
	FILE* fp = fopen("memberList.txt", "r"); // ȸ�� ������ �б� ���� fopen

	char* tmpName = (char*)malloc(sizeof(char) * loginLen); // üŷ�� ����, ������ �о�ͼ� ������ ����
	char* tmpPtr;
	char* SearchName = (char*)malloc(sizeof(char) * loginLen); // �˻��� ���� ����




	system("cls");
	printf("\n\n\n");
	printf("\n\t\t\t=================  FIND USERNAME FORM  =================\n");
	printf("\n\t\t\t\t\tINSERT USERNAME:\t");
	scanf("%s", SearchName); // �˻��� USERNAME

	while (!feof(fp)) {
		tmpPtr = fgets(tmpName, loginLen + 1, fp);
		tmpPtr = strtok(tmpName, " ");

		if (strcmp(tmpPtr, SearchName) == 0) {
			printf("\n\n\n\t\t\tWELCOME TO OUR SYSTEM !!!!\n\n\n\t\t\tUSERNAME \" %s \" ȸ���� �½��ϴ�.", SearchName);
			printf("\n\n\n\t\t\t\t\tPress any key to continue...");
			_getch(); //holds the screen

			//free(tmpName); // Ȱ����, ���α׷� HEAP ���� ������ �ּ� ó��(���� �𸣰���
			free(SearchName);
			fclose(fp); // fopen �빫 ����
			return 0;
		}
	} // while end


	{// while���� �����µ� return ���� ���Ͽ��ٸ�,
		printf("\n\n\n\t\t\tSORRY !!!!");
		printf("\n\n\t\t\t�Է��� USERNAME ' %s '���δ�, ȸ���� �ƴմϴ�. ȸ�� ������ ������ �ּ���.", SearchName);
		printf("\n\t\t\t--------------------------------------------------\n");
		printf("\n\n\n\t\t\t\t\tPress any key to Retry...");
		_getch(); //holds the screen
	}

	//free(tmpName); // Ȱ����, ���α׷� HEAP ���� ������ �ּ� ó��(���� �𸣰���
	free(SearchName);
	fclose(fp); // fopen �빫 ����
	return 1;
}