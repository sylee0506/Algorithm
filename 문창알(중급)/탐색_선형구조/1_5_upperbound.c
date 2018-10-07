/*
n개로 이루어진 정수 집합에서 원하는 수 k보다 큰 수가 처음으로 등장하는 위치
를 찾으시오.
단, 입력되는 집합은 오름차순으로 정렬되어 있으며, 같은 수가 여러 개 존재할 수
있다.
입력
첫째 줄에 한 정수 n, 둘째 줄에 n개의 정수가 공백으로 구분되어 입력된다. 셋째
줄에는 찾고자 하는 값 k가 입력된다.
(단, 2 <= n <= 1,000,000, 각 원소의 크기는 100,000,000을 넘지 않는다.)
출력
찾고자 하는 원소의 위치를 출력한다. 만약 모든 원소가 k보다 작으면 n+1을 출력
한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, k;
int arr[1000001];

void find_upper(int left, int right)
{
	int middle = (left + right) / 2;

	if (left >= right)
	{
		printf("%d\n", middle + 1);
		return;
	}

	if (k >= arr[middle])//배열에 같은 수가 있을 수 있으므로 등호 필요. 상한선이므로 여기에 넣었음.
		find_upper(middle + 1, right);
	else if (k < arr[middle])
		find_upper(left, middle);
}

void main(void)
{
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &k);
	find_upper(0, n);
}