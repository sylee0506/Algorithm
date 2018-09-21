/*
9개의 서로 다른 자연수가 주어질 때, 이들 중 최댓값을 찾고 그 값이 몇 번째 수
인지를 구하는 프로그램을 작성하시오.
예를 들어, 서로 다른 9개의 자연수가 각각
3, 29, 38, 12, 57, 74, 40, 85, 61
라면, 이 중 최댓값은 85이고, 이 값은 8번째 수이다.
입력
첫째 줄부터 아홉째 줄까지 한 줄에 하나의 자연수가 주어진다. 주어지는 자연수
는 100보다 작다.
출력
첫째 줄에 최댓값을 출력하고, 둘째 줄에 최댓값이 몇 번째 수인지를 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a[10];
	int i, temp, index;

	for (i = 0; i < 9; i++)
	{
		scanf("%d", &a[i]);
	}

	temp = a[0];

	for (i = 0; i < 9; i++)
	{
		if (temp <= a[i])
		{
			temp = a[i];
			index = i;
		}
	}

	printf("%d\n%d\n", temp, index+1);
}