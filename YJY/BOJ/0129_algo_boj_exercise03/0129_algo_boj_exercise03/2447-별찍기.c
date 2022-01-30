#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int n;
	bool check;

	scanf("%d", &n); //3의 거듭제곱을 입력받음

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) //가로 세로 n*n
		{
			check = true; //일단 싹 다 별임
			for (int k = n; k > 1; k = k / 3) //3으로 나누었을 때, 여기선 27/3 이니까 9*9가 되었을 때
			{
				if(i % k >= (k / 3) && i % k <(k / 3) * 2) //처음엔 27, 이때 가로가 9이상 18미만, 세로가 9이상 18미만이면 모조리 ' '이거임
					if (j % k >= (k / 3) && j % k < (k / 3) * 2) //위와 동일
					{
						check = false; //그러면 false인데 이게 ' '이거임
						break; //k == 1이 되는 순간 for문 나옴
						       //check 쓰는 이유는, 싹 다 *이었다가 ' '이게 된다는 걸 바로 출력하면 안되기 때문에 저장하기 위해서임
					}
			}
			if (check == false)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}