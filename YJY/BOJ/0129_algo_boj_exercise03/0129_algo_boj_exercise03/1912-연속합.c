#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//n번째까지의 연속합의 최댓값을 구하려면
//만약 i번째까지 더했을 때 음수라면 i+1번째부터 그 수부터 다시 시작
//그전까지의 i-1번째까지의 연속합은 따로 기록해둠
//이때 i부터 n까지 더할 때 이전의 i-1번째까지의 연속합보다 크면 그 값을 i부터 n번째까지 값을 더한 걸로 대체
//즉, 직전에 기억해둔 최대값을 max라 하고 그 후에 계속 더하는 연속합을 sum이라고 했을 때
//max와 sum을 비교해서 더 큰 걸 직전 최대값으로 기억하고 거기에 n번째 값 더함

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
		if (dp[i - 1] + arr[i] > arr[i]) //연속합과 해당 i번째 수와 비교해서 더 큰 거 저장
		{
			dp[i] = dp[i - 1] + arr[i];
			if (dp[i] > sum) // 최신 연속합의 최대값과 이전 최대값 비교
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