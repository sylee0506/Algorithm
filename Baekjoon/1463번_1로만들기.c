//1463번 문제 : 1로 만들기 (백준 다이나믹 프로그래밍 항목 맨 위에 있는 기초 문제)
/*
<다이나믹 프로그래밍>
중간 결과 값을 저장하여 재귀 호출 전에 불러오는것 ; 시간복잡도 감소, 공간복잡도 증가
step1) 점화식 세우기
step2) 초기값 채우기
step3) 예외 처리하기
*/

/*
<문제>
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
- X가 3으로 나누어 떨어지면, 3으로 나눈다.
- X가 2로 나누어 떨어지면, 2로 나눈다.
- 1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다.연산을 사용하는 횟수의 최솟값을 출력하시오.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(x,y) ((x) < (y) ? (x) : (y))

int arr[1000001]; //입력값이 n일때, 결과값이 arr[n]이 되게끔 할것
int n;

int main(void)
{
	scanf("%d", &n);

	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0)
			arr[i] = min(arr[i], arr[i / 2] + 1);
		if (i % 3 == 0)
			arr[i] = min(arr[i], arr[i / 3] + 1);
	}

	printf("%d", arr[n]);
	return 0;
}