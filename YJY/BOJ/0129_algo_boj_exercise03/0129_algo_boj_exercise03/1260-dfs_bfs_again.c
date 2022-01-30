#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1001
int graph[MAX_SIZE][MAX_SIZE] = { 0, }; //입력받은 간선과 정점을 인접행렬로 나타낼 수 있게 하는 것
int visited[MAX_SIZE] = { 0, }; //방문한 곳 표시
int que_dec[MAX_SIZE]; //bfs에서 enqueue, dequeue등 bfs의 수 돌아가는 곳
int N, M, V, row, col; //N은 정점 개수, M은 간선개수, V는 시작 정점 수
void dfs(int V);
void bfs(int V);

int main(void)
{
	scanf("%d %d %d", &N, &M, &V);
	
	for (int i = 0; i < M; i++) //입력받은 간선 개수만큼 양방향 정점 간을 입력받음
	{
		scanf("%d %d", &row, &col);
		graph[row][col] = 1; //양방향
		graph[col][row] = 1;
	}

	visited[V] = 1; //방문한 곳, 즉 처음 시작하는 정점을 나타내는 V는 무조건 1임
	dfs(V);

	for (int i = 1; i <= N; i++) //bfs로 돌기 전에 방문한 곳 모두 초기화 작업
	{
		visited[i] = 0;
	}

	visited[V] = 1; //dfs와 마찬가지로 방문한 곳(시작 정점) 1로 해놓고 시작
	printf("\n");
	bfs(V);

	return 0;
}

void dfs(int V)
{
	visited[V] = 1; //위와 동일
	printf("%d\t", V); //지났으니까 출력
	
	for (int i = 1; i <= N; i++) //정점 개수 만큼 돈다, 1부터 시작하니까 1부터 마지막 정점 N까지 
	{
		if (graph[V][i] && visited[i] == 0) //인접행렬에서 V에서 i까지갔는데 i가 아직 방문하지 않은 곳이었다면
			dfs(i); //dfs를 재귀로 돌림 -> 후에 visited[i] = 1이 되고 출력 후 이게 i==N이 될 때 까지 반복됨 
	}
}

void bfs(int V)
{
	int front = 0, rear = 1, pop;
	visited[V] = 1;
	printf("%d\t", V);

	que_dec[0] = V;//첫 인덱스 == 시작 정점

	while (1)
	{ 
		if (front >= rear) break; //빠지는 애가 삽입되는 애보다 같거나 크면 반복 종료

		pop = que_dec[front++]; //V는 이미 끝났으니까 front++로 하나씩 pop해줌
		
		for (int i = 1; i <= N; i++) //총 정점수만큼 돌림
		{
			if (graph[pop][i] && visited[i] == 0) //front++되서 que_dec[1]의 수에서 i까지 갔는데 그 i가 방문하지 않은 곳이었다면
			{
				visited[i] = 1; //1로 바꿈
				printf("%d\t", i); //그 방문하지 않았던 곳 출력

				que_dec[rear++] = i; //새로운 노드넣고 그걸 i로 둔다
			}
		}
	}
}