#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//#define MAX_SIZE 101
//#define MAX_QUE 10001

int map[101][101] = { 0, }; //미로임
int q[10001][2] = { 0, }; //현재 방문한 좌표를 q에 저장함 - bfs이니까
int n = 0, m = 0; //미로크기 전역 변수 선언
int move_row[4] = { -1,1,0,0 }; //상하좌우로 미로 이동해아함
                                //(-1,0), (1,0), (0,-1), (0,1) 이동
int move_col[4] = { 0,0,-1,1 };

int bfs()
{
    int front = 0, rear = 0;
    //q에 맨 처음엔 1,1 좌표부터 넣음
    q[front][0] = 1;
    q[front][1] = 1;
    rear++;

    while (front < rear) //q가 다 pop되서 없어질 때 까지
    {
        int row = q[front][0];
        int col = q[front][1];
        front++;

        //상하좌우 살펴보고 이동해야함
        for (int i = 0; i < 4; i++)
        {
            int next_row = row + move_row[i];
            int next_col = col + move_col[i];

            //만약 해당 map에서의 범위를 벗어나는 경우
            if (next_row < 1 || next_col < 1 || next_row > n || next_col > m)
                continue;

            //갈 수 있는 길이 아니라면,
            //==0으로 두면 돌아가지 않음!!! 이거 땜에 개고생함
            //>n이나 <m 인 범위가 있기 때문!!!! (내 생각)
            if (map[next_row][next_col] != 1)
                continue;

            map[next_row][next_col] = map[row][col] + 1;

            //큐에 이동한 좌표를 삽입해야함
            q[rear][0] = next_row;
            q[rear][1] = next_col;
            rear++;
        }
    }
    return map[n][m];
}

int main()
{
    //int n, m; 전역으로 받는게 편함
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    int res = bfs();
    printf("%d", res);

    return 0;
}