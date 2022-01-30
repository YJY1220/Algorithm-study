#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//n��°������ �������� �ִ��� ���Ϸ���
//���� i��°���� ������ �� ������� i+1��°���� �� ������ �ٽ� ����
//���������� i-1��°������ �������� ���� ����ص�
//�̶� i���� n���� ���� �� ������ i-1��°������ �����պ��� ũ�� �� ���� i���� n��°���� ���� ���� �ɷ� ��ü
//��, ������ ����ص� �ִ밪�� max�� �ϰ� �� �Ŀ� ��� ���ϴ� �������� sum�̶�� ���� ��
//max�� sum�� ���ؼ� �� ū �� ���� �ִ밪���� ����ϰ� �ű⿡ n��° �� ����

#define MAX_SIZE 100000
#define compare(x,y) x > y ? x : y

int main(void)
{
	int n;
	int arr[MAX_SIZE];
	int dp[MAX_SIZE];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int sum = arr[0];
	dp[0] = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (dp[i - 1] + arr[i] > arr[i]) //�����հ� �ش� i��° ���� ���ؼ� �� ū �� ����
		{
			dp[i] = dp[i - 1] + arr[i];
			if (dp[i] > sum) // �ֽ� �������� �ִ밪�� ���� �ִ밪 ��
			{
				sum = dp[i];
			}
			else
			{
				sum = sum;
			}
		}
		else
		{
			dp[i] = arr[i];
			if (dp[i] > sum)
			{
				sum = dp[i];
			}
			else
			{
				sum = sum;
			}
		}
	}

	printf("%d", sum);

	return 0;
}