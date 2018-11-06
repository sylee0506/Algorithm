/*
n개로 이루어진 정수 집합에서 원하는 수의 위치를 찾으시오.
단, 입력되는 집합은 오름차순으로 정렬되어 있으며, 같은 수는 없다.
입력
첫 줄에 한 정수 n이 입력된다.
둘째 줄에 n개의 정수가 공백으로 구분되어 입력된다.
셋째 줄에는 찾고자 하는 수가 입력된다.
(단, 2 <= n <= 1,000,000 , 각 원소의 크기는 100,000,000을 넘지 않는다.)
출력
찾고자 하는 원소의 위치를 출력한다. 없으면 -1을 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, num;
int A[1000001];
//num은 전역으로 쓰는게 좋다. 그래야 넘겨주지 않아도 되니까.

void find_seq(int n, int num)
{
	int i;
	int flag = 0;
	for (i = 0; i < n; i++)
	{
		if (num == A[i])
		{
			printf("seq, %d\n", i+1);
			flag = 1;
			break;
		}
	}

	if (flag == 0)
		printf("seq, -1\n");
}

void find_bin(int left, int right, int num)
{
	int middle = (left + right) / 2;

	if ((middle == left - 1) || (middle == right + 1))
	{
		printf("bin, -1\n");
		return;
	}//base 처리인데 이것보다는 if(left>right) return;이 깔끔 //추가 ; if(left>=right) 이어야 한다.

	if (A[middle] == num)
	{
		printf("bin, %d\n", middle+1);//print 바로 하지말고 middle+1 값을 리턴하는 쪽으로 하면 위에 base에서도 -1 리턴하면 된다. void에서 return;은 불안정
		return;
	}
	else if (A[middle] > num)
		find_bin(left, middle-1, num);
	else if (A[middle] < num)
		find_bin(middle+1, right, num);
}
void main(void)
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	scanf("%d", &num);

	find_seq(n, num);
	find_bin(0, n-1, num);
}
