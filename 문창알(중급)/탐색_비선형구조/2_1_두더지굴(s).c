/*
정올이는 땅속의 굴이 모두 연결되어 있으면 이 굴은 한 마리의 두더지가 사는 집
이라는 사실을 발견하였다.
정올이는 뒷산에 사는 두더지가 모두 몇 마리인지 궁금해졌다. 정올이는 특수 장
비를 이용하여 뒷산의 두더지 굴을 모두 나타낸 지도를 만들 수 있었다.
이 지도는 직사각형이고 가로 세로 영역을 0 또는 1로 표현한다. 0은 땅이고 1은
두더지 굴을 나타낸다. 1이 상하좌우로 연결되어 있으면 한 마리의 두더지가 사는
집으로 정의할 수 있다.
[그림 2]는 [그림 1]을 두더지 굴로 번호를 붙인 것이다. 특수촬영 사진 데이터를 입
력받아 두더지 굴의 수를 출력하고, 각 두더지 굴의 크기를 내림차순으로 정렬하여
출력하는 프로그램을 작성하시오.
입력
첫 번째 줄에 가로, 세로의 크기를 나타내는 n이 입력된다.(n은 30이하의 자연수)
두 번째 줄부터 n줄에 걸쳐서 n개의 0과 1이 공백으로 구분되어 입력된다.
출력
첫째 줄에 두더지 굴의 수를 출력한다. 둘째 줄부터 각 두더지 굴의 크기를 내림
차순으로 한 줄에 하나씩 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 30

int n;
int arr[MAX][MAX];
int top = -1;
int visited[MAX][MAX];
int num = 0; //두더지 굴 수
int size = 0; //두더지 굴 크기
int size_arr[(MAX*MAX)/2]; //두더지 굴 크기들 저장할 배열
int index = 0; //size_arr 전용 인덱스 변수
int flag = 0; //굴 하나를 다 돌았을때마다 1로 표시

typedef struct Stack{
	int i, j;
}Stack;

Stack stack[MAX];

void push(int i, int j)
{
	if (top == MAX * MAX)
		printf("The stack is full!\n");
	else
	{
		top++;
		stack[top].i = i;
		stack[top].j = j;
	}
}

Stack pop(int i, int j)
{
	if (top == -1)
	{
		num++; //굴 하나 전부 돌았음
		flag = 1;
		size_arr[index++] = size;
		size = 0; //굴 크기 초기화
	}
	else
	{
		size++;
		return stack[top--];
	}
}

void dfs(int i, int j)
{
	if (visited[i - 1][j] == 0 && arr[i - 1][j] == 1)//위
	{
		i = i - 1;
		visited[i][j] = 1;
		push(i , j);
		dfs(i , j);
	}
	else if (visited[i + 1][j] == 0 && arr[i + 1][j] == 1)//아래
	{
		i = i + 1;
		visited[i][j] = 1;
		push(i, j);
		dfs(i, j);
	}
	else if (visited[i][j - 1] == 0 && arr[i][j - 1] == 1)//왼쪽
	{
		j = j - 1;
		visited[i][j] = 1;
		push(i, j);
		dfs(i, j);
	}
	else if (visited[i][j + 1] == 0 && arr[i][j + 1] == 1)//오른쪽
	{
		j = j + 1;
		visited[i][j] = 1;
		push(i, j);
		dfs(i, j);
	}
	else
	{
		pop(i, j);
		i = stack[top].i;
		j = stack[top].j;
		if (flag == 1)
		{
			flag = 0;
			return;
		}
		else
			dfs(i, j);
	}
}

int compare(void *first, void *second)
{
	if (*(int*)first < *(int*)second)
		return 1;
	else if (*(int*)first > *(int*)second)
		return -1;
	else
		return 0;
}//내림차순 정렬을 위함

void main(void)
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == 0 && arr[i][j] == 1)
			{
				visited[i][j] = 1;
				push(i, j);
				dfs(i, j);
			}
		}
	}

	printf("%d\n", num);
	qsort(size_arr, index, sizeof(int), compare);//내림차순 정렬; 퀵소트 라이브러리 사용함

	for (int i = 0; i < index; i++)
		printf("%d\n", size_arr[i]);
}

//내가 이용한 방법 : 예전에 미로찾기 프로그램에서 이용한 dfs를 사용함. 그런데 더 쉽게 푸는 방법이 있음. dfs에서 elseif 말고 if를 쓰면 스택 필요없이 재귀만으로 가능하다 ; 밑의 알고리즘 참고
//추가 : 재귀말고 while(1) break;를 쓰기!! 재귀는 시간,공간 많이 잡아먹음. 미로때 dfs에서도 재귀 아닌 반복문 사용함
/*
flood fill : 이러한 문제 외에도 자주 사용되는 알고리즘; 하나의 세트(묶음)를 돌 때 숫자를 통일해서 바꿔서 배열을 채우는 방법.
예를 들어 첫번째 굴을 dfs로 돌면서 배열의 1을 2로 바꿔주는 것임. 이때 dfs에서 else if를 쓰지 말고 if를 써서 4방향을 모두 채운다. 다시 돌아와서 탐색할 필요 없게! -> 스택 필요없고 재귀만으로 가능
하나의 굴을 모두 2로 채우고 나면 그 다음 1인곳으로 가서 그 다음 숫자인 3으로 채워나가며 진행할 수 있다.
또한 이 숫자들을 index로 활용하여 2번째 굴의 크기를 size_arr[2]에 저장하는 식으로 갈 수 있다.
*/