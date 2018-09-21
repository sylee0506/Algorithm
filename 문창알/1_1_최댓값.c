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