/*
n개로 이루어진 정수 집합에서 원하는 수 k 이상인 수가 처음으로 등장하는 위치
를 찾으시오.
단, 입력되는 집합은 오름차순으로 정렬되어 있으며, 같은 수가 여러 개 존재할 수
있다.
입력
첫째 줄에 한 정수 n이 입력된다.
둘째 줄에 n개의 정수가 공백으로 구분되어 입력된다.
셋째 줄에는 찾고자 하는 값 k가 입력된다.
(단, 2 <= n <= 1,000,000 , 각 원소의 크기는 100,000,000을 넘지 않는다.)
출력
찾고자 하는 원소의 위치를 출력한다. 만약 모든 원소가 k보다 작으면 n+1을 출력
한다.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[1000001];

void find(int n, int k)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] >= k)
		{
			printf("%d\n", i+1);
			return;
		}
		else if (a[0] > k)
		{
			printf("1\n");
			return;
		}
	}
	printf("%d\n", n + 1);
}

void find_binary(int left, int right, int k)
{
	int middle = (left + right) / 2;

	if (left >= right)//= 이 있어야 한다. 꼭!
	{
		printf("%d\n", middle + 1);
		return;
	}

	if (k > a[middle])
		find_binary(middle + 1, right, k);
	else if (k < a[middle])
		find_binary(left, middle, k); //하한선이므로 k가 더 작을 때는 middle 값을 포함하여 다시 탐색해야한다.
}

void main(void)
{
	int n, k;
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	scanf("%d", &k);
	find(n, k);
	find_binary(0, n, k);
}
