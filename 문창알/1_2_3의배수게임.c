/*
3의 배수 게임을 하던 정올이는 3의 배수 게임에서 잦은 실수로 계속해서 벌칙을
받게 되었다.
3의 배수 게임의 왕이 되기 위한 마스터 프로그램을 작성해 보자.
** 3의 배수 게임이란?
여러 사람이 순서를 정해 순서대로 수를 부르는 게임이다.
만약 3의 배수를 불러야 하는 상황이라면, 그 수 대신 "박수" 를 친다.
입력
첫 째 줄에 하나의 정수 이 입력된다(n은 10미만의 자연수이다.).
출력
1부터 그 수까지 순서대로 공백을 두고 수를 출력하는데, 3 또는 6 또는 9인 경우
그 수 대신 영문 대문자 X 를 출력한다.
*/




#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void solve(int num)
{
	int i;
	for (i = 1; i <= num; i++)
	{
		if (i % 3 == 0)
			printf("X");
		else
			printf("%d", i);

		if (i == num)
			printf("\n");
		else
			printf(" ");
	}
}

void main(void)
{
	int num;
	scanf("%d", &num);
	solve(num);
}