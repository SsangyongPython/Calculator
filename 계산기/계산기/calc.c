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
 * 정리하면
 *
 * ~로딩중 출력 후 커서 위치를 처음으로 옮겨서
 * ~~로딩중 출력, 후 커서 위치를 처음으로 옮겨서
 * ~~~로딩중 출력
 *
 * 물결문자 하나씩 늘어나면서 정한 횟수만큼 반복(10번)
 */
void loading()
{
    COORD Pos = getxy();
    gotoxy(Pos.X, Pos.Y);
    for(int i = 0;i < 10;i++) // 물결표 출력 횟수 10번
    {
        for(int j = 0;j < 5;j++) // 출력 1회에 물결표 5개 출력
        { 
			// 출력 횟수가 증가할 수록 딜레이는 줄어들게 설계(출력 속도 증가)
            Sleep((-20 * i + 200) / 5); // 1회에 5번 출력이므로 딜레이도 1/5이 되어야함

			// ~~~~로딩중 출력
            for(int k = 0;k < i * 5 + j;k++)
                putchar('~');

            printf("로딩중");

			// ~~~~로딩중 문장을 새로 덮어쓰기 위해 커서를 처음 위치로 이동
            gotoxy(Pos.X, Pos.Y);
        }
    }

	// ~~~로딩중 출력된거 공백으로 지우기
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
        printf("ㅡㅡㅡㅡ협업 연습용 간단한 계산기ㅡㅡㅡㅡ\n\n");

        printf("1. 덧셈\n");
        printf("2. 뺄셈\n");
        printf("3. 곱셈\n");
        printf("4. 나눗셈\n\n");

        Sleep(1400);
        printf("메뉴 주문 도와드릴게요~ : ");

        // 메뉴 번호가 범위를 벗어났거나 입력값 형식이 잘못된 경우
        while(scanf_s("%d", &selector) == 0 || (selector < 1 || 4 < selector))
        {
            printf("제대로 입력해주세요! : ");
            rewind(stdin);
        }

        printf("\n피연산자는 어떻게 해드릴까요? : ");
        while(scanf_s("%d", &num1) == 0)
        {
            printf("제대로 입력해주세요! : ");
            rewind(stdin);
        }

        printf("하나 더! : ");
        while(scanf_s("%d", &num2) == 0)
        {
            printf("제대로 입력해주세요! : ");
            rewind(stdin);
        }

        printf("\n");
        loading();

        switch(selector)
        {
        case 1 :
            printf("주문하신 덧셈 나왔습니다~\n");
            Sleep(1000);
            printf("%d + %d = %d\n", num1, num2, add(num1, num2));
            break;

        case 2 :
            printf("주문하신 뺄셈 나왔습니다~\n");
            Sleep(1000);
            printf("%d - %d = %d\n", num1, num2, sub(num1, num2));
            break;

        case 3 :
            printf("주문하신 곱셈 나왔습니다~\n");
            Sleep(1000);
            printf("%d * %d = %d\n", num1, num2, mul(num1, num2));
            break;

        case 4 :
            printf("주문하신 나눗셈 나왔습니다~\n");
            Sleep(1000);
            printf("%d / %d = %d\n", num1, num2, divi(num1, num2));
            break;
        }
        Sleep(400);
        printf("맛있는 수학 시간 되세여\n\n");
        Sleep(900);
        system("PAUSE");
    }
}
