#include "main.h"

#define loginLen 21 // login.c ���Ͽ����� define���� ' ���� ' define

void SignUp() {
	unsigned short SignUserName = 1; // USERNAME ������, while ����
	unsigned short SignPW = 1; // PW ������, while ����
	FILE* fp;
	char* tmpName = (char*)malloc(sizeof(char) * loginLen); // üŷ�� ����, ������ �о�ͼ� ������ ����
	char* tmpPtr;

	char* tmpID = (char*)malloc(sizeof(char) * loginLen);
	char* tmpPW = (char*)malloc(sizeof(char) * loginLen);
	char* tmpPW2 = (char*)malloc(sizeof(char) * loginLen); // PW üŷ�� ���� ����

	int PWLevel[3] = { 0, }; // PW ���� ������ �����ϱ� ���� �迭
	



	// USERNAME � ����
	do {
		system("cls");
		printf("\n\n\n");
		printf("\n\t\t\t===================  SignUp FORM  ===================\n");
		printf("\n\t\t\t* USERNAME, PASSWORD �ִ� ���̴� %d �Դϴ�. (�ѱ� �Է½� %d\n", loginLen, loginLen / 2);
		printf("\n\t\t\t_____________________________________________________");
		printf("\n\t\t\t\t\tINSERT USERNAME:\t");

		scanf("%s", tmpID);

		if (strlen(tmpID) < 5) {
			printf("\n\t\t\t\t\tUSERNAME Error : strlen(USERNAME) < 5\t���� ����\n");
			printf("\n\t\t\t--------------------------------------------------\n");
			printf("\t\t\t\t\tUSERNAME �ٽ� �Է��� �ּ���\n");

			_getch(); //holds the screen
			continue;
		}

		{// USERNAME �ߺ� üŷ			
			FILE* fp = fopen("memberList.txt", "r"); // ȸ�� ������ �б� ���� fopen

			while (!feof(fp)) {
				tmpPtr = fgets(tmpName, loginLen + 1, fp);
				tmpPtr = strtok(tmpName, " ");

				if (strcmp(tmpPtr, tmpID) == 0) { // USERNAME �ߺ���
					printf("\n\n\n\t\t\tSORRY !!!!");
					printf("\n\t\t\t\t\tUSERNAME Error : �ߺ��� USERNAME\t���� ����\n");
					printf("\n\t\t\t--------------------------------------------------\n");
					printf("\t\t\t\t\tUSERNAME �ٽ� �Է��� �ּ���\n");

					_getch(); //holds the screen
					break;
				}
			}

			if (strcmp(tmpPtr, tmpID) != 0) { // USERNAME �ߺ� ������
				SignUserName = 0; // while end

				free(tmpName);
				fclose(fp);
			}
		}
	} while (SignUserName); // USERNAME ���� ����


	// PASSWORD ����
	do {
		do {
			system("cls");
			printf("\n\n\n");
			printf("\n\t\t\t===================  SignUp FORM  ===================\n");
			printf("\n\t\t\t* USERNAME, PASSWORD �ִ� ���̴� %d �Դϴ�. (�ѱ� �Է½� %d\n", loginLen, loginLen / 2);
			printf("\n\t\t\t_____________________________________________________");
			printf("\n\t\t\t\t\tINSERT USERNAME:\t%s", tmpID);
			printf("\n\t\t\t\t\tINSERT PASSWORD:\t");


			for (int i = 0; i < sizeof(PWLevel) / sizeof(PWLevel[0]); i++) PWLevel[i] = 0; // �Է� ��, ' 0 ' ���� �ʱ�ȭ
			
			// ��й�ȣ �Է�
			for (int i = 0; i < loginLen; i++) {
				tmpPW[i] = _getch();
				if (tmpPW[i] == 13) { // Enter �����ڸ� �Է½�
					tmpPW[i] = '\0'; // ���ڿ� ��ó��
					SignPW = 0; // PW �Է� end

					if (i < 5) {
						printf("\n\t\t\t\t\tPASSWORD Error : strlen(PASSWORD) < 5\t���� ����\n");
						printf("\n\t\t\t--------------------------------------------------\n");
						printf("\t\t\t\t\tPASSWORD �ٽ� �Է��� �ּ���\n");

						_getch(); //holds the screen
						SignPW = 1; // ��й�ȣ �Է� while
						break;
					}
					break;
				}
				else {
					printf("*");

					{// PW ���� ���� ������ ���� ī��Ʈ
						if (tmpPW[i] >= 'A' && tmpPW[i] <= 'Z') PWLevel[0]++; // PW[i] == �빮�� ���
						else if (tmpPW[i] >= 'a' && tmpPW[i] <= 'z') PWLevel[1]++; // PW[i] == �ҹ��� ���
						else if (tmpPW[i] >= '0' && tmpPW[i] <= '9') PWLevel[1]++; // PW[i] == ���� ���
						else if ((tmpPW[i] >= 33 && tmpPW[i] <= 47) || (tmpPW[i] >= 58 && tmpPW[i] <= 64) || (tmpPW[i] >= 91 && tmpPW[i] <= 96) || (tmpPW[i] >= 123 && tmpPW[i] <= 126)) PWLevel[2]++; // PW[i] == Ư�� ���� ���
					}

					{// PW ���� ����
						//printf("%d, %d, %d,\n", PWLevel[0], PWLevel[1], PWLevel[2]);
					}
				}
			}
		} while (SignPW); // PW ���� ����


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