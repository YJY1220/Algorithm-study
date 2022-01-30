#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1001
int graph[MAX_SIZE][MAX_SIZE] = { 0, }; //�Է¹��� ������ ������ ������ķ� ��Ÿ�� �� �ְ� �ϴ� ��
int visited[MAX_SIZE] = { 0, }; //�湮�� �� ǥ��
int que_dec[MAX_SIZE]; //bfs���� enqueue, dequeue�� bfs�� �� ���ư��� ��
int N, M, V, row, col; //N�� ���� ����, M�� ��������, V�� ���� ���� ��
void dfs(int V);
void bfs(int V);

int main(void)
{
	scanf("%d %d %d", &N, &M, &V);
	
	for (int i = 0; i < M; i++) //�Է¹��� ���� ������ŭ ����� ���� ���� �Է¹���
	{
		scanf("%d %d", &row, &col);
		graph[row][col] = 1; //�����
		graph[col][row] = 1;
	}

	visited[V] = 1; //�湮�� ��, �� ó�� �����ϴ� ������ ��Ÿ���� V�� ������ 1��
	dfs(V);

	for (int i = 1; i <= N; i++) //bfs�� ���� ���� �湮�� �� ��� �ʱ�ȭ �۾�
	{
		visited[i] = 0;
	}

	visited[V] = 1; //dfs�� ���������� �湮�� ��(���� ����) 1�� �س��� ����
	printf("\n");
	bfs(V);

	return 0;
}

void dfs(int V)
{
	visited[V] = 1; //���� ����
	printf("%d\t", V); //�������ϱ� ���
	
	for (int i = 1; i <= N; i++) //���� ���� ��ŭ ����, 1���� �����ϴϱ� 1���� ������ ���� N���� 
	{
		if (graph[V][i] && visited[i] == 0) //������Ŀ��� V���� i�������µ� i�� ���� �湮���� ���� ���̾��ٸ�
			dfs(i); //dfs�� ��ͷ� ���� -> �Ŀ� visited[i] = 1�� �ǰ� ��� �� �̰� i==N�� �� �� ���� �ݺ��� 
	}
}

void bfs(int V)
{
	int front = 0, rear = 1, pop;
	visited[V] = 1;
	printf("%d\t", V);

	que_dec[0] = V;//ù �ε��� == ���� ����

	while (1)
	{ 
		if (front >= rear) break; //������ �ְ� ���ԵǴ� �ֺ��� ���ų� ũ�� �ݺ� ����

		pop = que_dec[front++]; //V�� �̹� �������ϱ� front++�� �ϳ��� pop����
		
		for (int i = 1; i <= N; i++) //�� ��������ŭ ����
		{
			if (graph[pop][i] && visited[i] == 0) //front++�Ǽ� que_dec[1]�� ������ i���� ���µ� �� i�� �湮���� ���� ���̾��ٸ�
			{
				visited[i] = 1; //1�� �ٲ�
				printf("%d\t", i); //�� �湮���� �ʾҴ� �� ���

				que_dec[rear++] = i; //���ο� ���ְ� �װ� i�� �д�
			}
		}
	}
}