#include "main.h"

void SeatFileOpenReadMode(int Cho_BusNum, char* p) {
    FILE* fp; // fopen ���� ����

    
    switch (Cho_BusNum) { // �� ���� No. (��ȣ�� case
    case 1:
        fp = fopen("bus1.txt", "r");

        if (fp == NULL) { // ������ ������ ������ ������
            fp = fopen("bus1.txt", "w"); // ���� ����
            fputs("0000000000000000000000000000000000000000", fp); // 40�¼�
            fclose(fp);
            fp = fopen("bus1.txt", "r"); // �б�(Read ���� ���� open
        }

        fgets(p, 41, fp);
        fclose(fp); // fopen �빫 ���� 
        break; // switch case 1 end


    case 2:
        fp = fopen("bus2.txt", "r");

        if (fp == NULL) { // ������ ������ ������ ������
            fp = fopen("bus2.txt", "w"); // ���� ����
            fputs("0000000000000000000000000000000000000000", fp); // 40�¼�
            fclose(fp);
            fp = fopen("bus2.txt", "r"); // �б�(Read ���� ���� open
        }

        fgets(p, 41, fp);
        fclose(fp); // fopen �빫 ���� 
        break; // switch case 2 end

    case 3:
        fp = fopen("bus3.txt", "r");

        if (fp == NULL) { // ������ ������ ������ ������
            fp = fopen("bus3.txt", "w"); // ���� ����
            fputs("0000000000000000000000000000000000000000", fp); // 40�¼�
            fclose(fp);
            fp = fopen("bus3.txt", "r"); // �б�(Read ���� ���� open
        }

        fgets(p, 41, fp);
        fclose(fp); // fopen �빫 ���� 
        break; // switch case 3 end

    case 4:
        fp = fopen("bus4.txt", "r");

        if (fp == NULL) { // ������ ������ ������ ������
            fp = fopen("bus4.txt", "w"); // ���� ����
            fputs("0000000000000000000000000000000000000000", fp); // 40�¼�
            fclose(fp);
            fp = fopen("bus4.txt", "r"); // �б�(Read ���� ���� open
        }

        fgets(p, 41, fp);
        fclose(fp); // fopen �빫 ���� 
        break; // switch case 4 end

    case 5:
        fp = fopen("bus5.txt", "r");

        if (fp == NULL) { // ������ ������ ������ ������
            fp = fopen("bus5.txt", "w"); // ���� ����
            fputs("0000000000000000000000000000000000000000", fp); // 40�¼�
            fclose(fp);
            fp = fopen("bus5.txt", "r"); // �б�(Read ���� ���� open
        }

        fgets(p, 41, fp);
        fclose(fp); // fopen �빫 ���� 
        break; // switch case 5 end

    }
}