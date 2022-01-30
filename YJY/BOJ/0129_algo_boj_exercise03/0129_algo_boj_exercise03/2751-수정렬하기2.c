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
	mergeSort(base_arr, 0, n - 1); //�ݺ��ϴ� �� �ε��� 0���� n-1���� ����
	
	for (int i = 0; i < n; i++) //�� �ݺ��ؼ� ���� ������ ���� ���� �迭���ٰ� ��� ����� �� �ְ� �ε��� ������ŭ �ݺ���
	{
		printf("%d ", base_arr[i]); //�ε��� 0�϶� ���� ��, 1�϶� ���� ��, ���������� n-1�� �� ���� ��
	}
	
	return 0;
}

void merge(int arr[], int m, int middle, int n) //�պ�����
{
	int sorted[1000001]; //
	int i = m; //2���� ���� �� ù��° �ڽ��� ù��° �ε��� ����
	int j = middle + 1; //�ι�° �ڽ��� ù��° �ε��� ���� ������
	int k = m; //��ǻ� ��ġ�� i�� ������, �׷��� m�� �������
	//���� ������� �迭�� ������
	while (i <= middle && j <= n) //i�� middle�����̰� j�� n������ �� ��� ����
		                          //�ʰ� ��, ������ �ߴ�, i�� middle���� ũ�� �� �ڽ��� �̹� ������ ���� �ű� ������
	{
		if(arr[i] < arr[j]) //ù��° �ڽ��� ù��° �ε����� �ι�° �ڽ��� ù��° �ε������� ������
		{
			sorted[k] = arr[i]; //i�� ���� ���Ĺڽ��� ����ְ�
			i++; //�ε����� �������� �̵���Ŵ
		}
		else //�ݴ�� j�� ió�� ����
		{
			sorted[k] = arr[j];
			j++;
		}
		k++;
	}
	//���� ������ ��� ����, i�� j �� �� �ϳ��� ���� ������ ���
	if (i > middle) //i�� �� ũ�� ������ i�� ���� ���� ����
	{
		for (int t = j; t <= n; t++) //j�� �׳� n���� ����, �ϳ��� �÷����ؼ�
		{
			sorted[k] = arr[t]; //���� �� ������ �� �������
			k++; //n�ɶ����� ++����
		}
	}
	else //j�� ���������� ió�� ����
	{
		for (int t = i; t <= middle; t++)
		{
			sorted[k] = arr[t];
			k++;
		}
	}
	//���ĵ� �迭�� �����ؾ� �� -> ���� �迭�� �Ű������
	for (int t = m; t <= n; t++) //sorted�� ���� �迭�� ���� m���� n���� ���ĵ� ��ü�迭�� arr�� �־��־����
	{
		arr[t] = sorted[t]; //���ļ� ����ֱ�~
	}
}

void mergeSort(int arr[], int m, int n)
{
	//ũ�Ⱑ 1���� ū ���
	//�ڽ��� �������� �� �ֵ��� �迭 ���� 2���̻�, 1���� ������ �ʿ� x
	if (m < n)
	{
		int middle = (m + n) / 2; //������
		mergeSort(arr, m, middle); //����
		mergeSort(arr, middle + 1, n); //������
		merge(arr, m, middle, n); //let's ��ġ��~
	}
}

