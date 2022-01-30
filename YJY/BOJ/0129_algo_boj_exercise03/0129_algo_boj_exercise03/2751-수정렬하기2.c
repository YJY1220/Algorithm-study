#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n;
void merge(int arr[], int m, int middle, int n);
void mergeSort(int arr[], int m, int n);

int main(void)
{
	int base_arr[1000001];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &base_arr[i]);
	}
	mergeSort(base_arr, 0, n - 1); //반복하는 걸 인덱스 0부터 n-1까지 해줌
	
	for (int i = 0; i < n; i++) //이 반복해서 나온 과정을 기존 원래 배열에다가 모두 출력할 수 있게 인덱스 개수만큼 반복함
	{
		printf("%d ", base_arr[i]); //인덱스 0일때 무슨 값, 1일때 무슨 값, 최종적으로 n-1일 때 무슨 값
	}
	
	return 0;
}

void merge(int arr[], int m, int middle, int n) //합병정렬
{
	int sorted[1000001]; //
	int i = m; //2개로 나눌 때 첫번째 박스의 첫번째 인덱스 지점
	int j = middle + 1; //두번째 박스의 첫번째 인덱스 지점 시작점
	int k = m; //사실상 위치가 i와 동일함, 그러니 m을 집어넣음
	//작은 순서대로 배열에 삽입함
	while (i <= middle && j <= n) //i가 middle이하이고 j가 n이하일 때 계속 돌림
		                          //초과 시, 무조건 중단, i가 middle보다 크면 그 박스는 이미 정렬이 끝난 거기 때문에
	{
		if(arr[i] < arr[j]) //첫번째 박스의 첫번째 인덱스가 두번째 박스의 첫번째 인덱스보다 작으면
		{
			sorted[k] = arr[i]; //i를 먼저 정렬박스에 집어넣고
			i++; //인덱스를 다음으로 이동시킴
		}
		else //반대면 j를 i처럼 해줌
		{
			sorted[k] = arr[j];
			j++;
		}
		k++;
	}
	//남은 데이터 모두 삽입, i나 j 둘 중 하나가 먼저 끝났을 경우
	if (i > middle) //i가 더 크기 때문에 i가 먼저 끝난 거임
	{
		for (int t = j; t <= n; t++) //j를 그냥 n까지 돌림, 하나씩 플러스해서
		{
			sorted[k] = arr[t]; //남은 거 모조리 다 집어넣음
			k++; //n될때까지 ++해줌
		}
	}
	else //j가 먼저끝나면 i처럼 해줌
	{
		for (int t = i; t <= middle; t++)
		{
			sorted[k] = arr[t];
			k++;
		}
	}
	//정렬된 배열을 삽입해야 함 -> 실제 배열로 옮겨줘야함
	for (int t = m; t <= n; t++) //sorted에 넣은 배열을 이제 m부터 n까지 정렬된 전체배열을 arr에 넣어주어야함
	{
		arr[t] = sorted[t]; //합쳐서 집어넣기~
	}
}

void mergeSort(int arr[], int m, int n)
{
	//크기가 1보다 큰 경우
	//박스로 나누어질 수 있도록 배열 수는 2개이상, 1개면 정렬할 필요 x
	if (m < n)
	{
		int middle = (m + n) / 2; //나누고
		mergeSort(arr, m, middle); //왼쪽
		mergeSort(arr, middle + 1, n); //오른쪽
		merge(arr, m, middle, n); //let's 합치기~
	}
}

