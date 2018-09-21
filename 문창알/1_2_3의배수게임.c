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