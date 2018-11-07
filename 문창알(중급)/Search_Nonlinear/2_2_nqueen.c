/*
전산학에서 백트래킹 문제로 n - queen problem이 유명하다.
이 문제는 n*n체스 보드판에 n개의 queen을 서로 공격하지 못하도록 배치하는 방법
을 찾아내는 문제이다.
아래 그림은 n이 4일 경우 queen을 서로 공격하지 못하게 배치한 한 예를 나타낸
다.
체스판 크기 및 queen의 수를 나타내는 n을 입력받아서 서로 공격하지 못하도록
배치하는 총 방법의 수를 구하는 프로그램을 작성하시오.
입력
정수 n이 입력으로 들어온다.(3 <= n <= 9)
출력
서로 다른 총 경우의 수를 출력한다.
*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int visited[10][10];//체스판, 값이 1로 바뀌는 부분에는 말을 못 놓는다
int copy[10][10];//visited의 이전 상태를 저장할 복사본
int num = 0;//총 경우의 수
int top = -1;
typedef struct Stack{
	int i, j;
}Stack;
Stack stack[10];

void copy_visited()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			copy[i][j] = visited[i][j];
	}
}

void push(int i, int j)
{
	top++;
	stack[top].i = i;
	stack[top].j = j;
}

void pop(int i, int j)
{
	stack[top].i = 0;
	stack[top].j = 0;
	top--;

	for (int k = 0; k < 10; k++)
	{
		for (int h = 0; h < 10; h++)
			visited[k][h] = copy[k][h];
	}//이전 visited 상태로 돌려놓음
}

void ban(int i, int j)
{
	//queen의 현재 위치 (i,j)를 받아서 이동할 수 있는 곳, 즉 다른 queen이 올 수 없는 자리를 1로 표시한다

	int k;
	
	visited[i][j] = 1;

	for (k = 1; ; k++)
	{
		if (i - k < 0 || j - k < 0)
			break;

		visited[i - k][j - k] = 1;
	}//NW방향

	for (k = 1; ; k++)
	{
		if (i - k < 0)
			break;

		visited[i - k][j] = 1;
	}//N방향

	for (k = 1; ; k++)
	{
		if (i - k < 0 || j + k >= n)
			break;

		visited[i - k][j + k] = 1;
	}//NE 방향

	for (k = 1; ; k++)
	{
		if (j + k >= n)
			break;

		visited[i][j + k] = 1;
	}//E방향

	for (k = 1; ; k++)
	{
		if (i + k >= n || j + k >= n)
			break;

		visited[i + k][j + k] = 1;
	}//SE방향

	for (k = 1; ; k++)
	{
		if (i + k >= n)
			break;

		visited[i + k][j] = 1;
	}//S방향

	for (k = 1; ; k++)
	{
		if (i + k >= n || j - k < 0)
			break;

		visited[i + k][j - k] = 1;
	}//SW방향

	for (k = 1; ; k++)
	{
		if (j - k < 0)
			break;

		visited[i][j - k] = 1;
	}//W방향
}

void main(void)
{
	int i = 0, j = 0;
	int pop_flag = 0;
	int break_flag = 0;

	scanf("%d", &n);

	while ((i < n) && (j < n))
	{
		copy_visited();

		if (pop_flag != 1)
		{
			ban(i, j);
			push(i, j);
		}

		if (top == n - 1)
		{
			num++;//경우의 수가 하나 추가
			break;
		}
				
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (visited[i][j] == 0)
				{
					pop_flag = 0;
					break_flag = 1;
					break;
				}
				else
					pop_flag = 1;
			}
			if (break_flag == 1)
			{
				break_flag = 0; //원상태로 돌려놓음
				break;
			}
		}

		if (pop_flag == 1)
		{
			i = stack[top].i;
			j = stack[top].j;
			pop(i, j);
			visited[i][j] = 1;
		}
	}

	printf("%d\n", num);
}
*/
////////////////////////////여기까지 알고리즘 공부 전 삽질///////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 9

int n;
int col[MAX], inc[MAX+MAX], dec[MAX+MAX]; //알고리즘에 사용할 배열들
int num = 0; //전체 경우의 수

void dfs(int k)
{
	if (k >= n)
	{
		num++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (col[i] == 0 && inc[k + i] == 0 && dec[k - i + (n - 1)] == 0)
		{
			col[i] = inc[k + i] = dec[k - i + (n - 1)] = 1;
			dfs(k + 1);
			col[i] = inc[k + i] = dec[k - i + (n - 1)] = 0;//백트랙
		}
	}
}

void main(void)
{
	scanf("%d", &n);
	dfs(0);
	printf("%d\n", num);
}

//queen은 하나의 행에 반드시 하나씩 위치해야 하므로 행은 내버려두고 열로 반복문을 돌린다.
//배열에서 같은 대각선에 위치한 행과 열의 합, 차가 일정한 특성을 이용한다.
//재귀로 돌릴 구간이 어디인지 잘 생각해야 한다.
//백트랙 조건 잘 설정하기.