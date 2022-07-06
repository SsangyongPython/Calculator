#include <stdio.h>
#include <windows.h>

#include "definition.h"

void gotoxy(int x, int y)
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
COORD getxy()
{
	CONSOLE_SCREEN_BUFFER_INFO cs;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cs);
	return cs.dwCursorPosition;
}

/*
 * �����ϸ�
 *
 * ~�ε��� ��� �� Ŀ�� ��ġ�� ó������ �Űܼ�
 * ~~�ε��� ���, �� Ŀ�� ��ġ�� ó������ �Űܼ�
 * ~~~�ε��� ���
 *
 * ���Ṯ�� �ϳ��� �þ�鼭 ���� Ƚ����ŭ �ݺ�(10��)
 */
void loading()
{
    COORD Pos = getxy();
    gotoxy(Pos.X, Pos.Y);
    for(int i = 0;i < 10;i++) // ����ǥ ��� Ƚ�� 10��
    {
        for(int j = 0;j < 5;j++) // ��� 1ȸ�� ����ǥ 5�� ���
        { 
			// ��� Ƚ���� ������ ���� �����̴� �پ��� ����(��� �ӵ� ����)
            Sleep((-20 * i + 200) / 5); // 1ȸ�� 5�� ����̹Ƿ� �����̵� 1/5�� �Ǿ����

			// ~~~~�ε��� ���
            for(int k = 0;k < i * 5 + j;k++)
                putchar('~');

            printf("�ε���");

			// ~~~~�ε��� ������ ���� ����� ���� Ŀ���� ó�� ��ġ�� �̵�
            gotoxy(Pos.X, Pos.Y);
        }
    }

	// ~~~�ε��� ��µȰ� �������� �����
    printf("                                                                 ");
    gotoxy(Pos.X, Pos.Y);
}
int main()
{
    char selector;
    int num1, num2;

    while(1)
    {
        system("cls");
        printf("�ѤѤѤ����� ������ ������ ����ѤѤѤ�\n\n");

        printf("1. ����\n");
        printf("2. ����\n");
        printf("3. ����\n");
        printf("4. ������\n\n");

        Sleep(1400);
        printf("�޴� �ֹ� ���͵帱�Կ�~ : ");

        // �޴� ��ȣ�� ������ ����ų� �Է°� ������ �߸��� ���
        while(scanf_s("%d", &selector) == 0 || (selector < 1 || 4 < selector))
        {
            printf("����� �Է����ּ���! : ");
            rewind(stdin);
        }

        printf("\n�ǿ����ڴ� ��� �ص帱���? : ");
        while(scanf_s("%d", &num1) == 0)
        {
            printf("����� �Է����ּ���! : ");
            rewind(stdin);
        }

        printf("�ϳ� ��! : ");
        while(scanf_s("%d", &num2) == 0)
        {
            printf("����� �Է����ּ���! : ");
            rewind(stdin);
        }

        printf("\n");
        loading();

        switch(selector)
        {
        case 1 :
            printf("�ֹ��Ͻ� ���� ���Խ��ϴ�~\n");
            Sleep(1000);
            printf("%d + %d = %d\n", num1, num2, add(num1, num2));
            break;

        case 2 :
            printf("�ֹ��Ͻ� ���� ���Խ��ϴ�~\n");
            Sleep(1000);
            printf("%d - %d = %d\n", num1, num2, sub(num1, num2));
            break;

        case 3 :
            printf("�ֹ��Ͻ� ���� ���Խ��ϴ�~\n");
            Sleep(1000);
            printf("%d * %d = %d\n", num1, num2, mul(num1, num2));
            break;

        case 4 :
            printf("�ֹ��Ͻ� ������ ���Խ��ϴ�~\n");
            Sleep(1000);
            printf("%d / %d = %d\n", num1, num2, divi(num1, num2));
            break;
        }
        Sleep(400);
        printf("���ִ� ���� �ð� �Ǽ���\n\n");
        Sleep(900);
        system("PAUSE");
    }
}
