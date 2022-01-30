#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//#define MAX_SIZE 101
//#define MAX_QUE 10001

int map[101][101] = { 0, }; //�̷���
int q[10001][2] = { 0, }; //���� �湮�� ��ǥ�� q�� ������ - bfs�̴ϱ�
int n = 0, m = 0; //�̷�ũ�� ���� ���� ����
int move_row[4] = { -1,1,0,0 }; //�����¿�� �̷� �̵��ؾ���
                                //(-1,0), (1,0), (0,-1), (0,1) �̵�
int move_col[4] = { 0,0,-1,1 };

int bfs()
{
    int front = 0, rear = 0;
    //q�� �� ó���� 1,1 ��ǥ���� ����
    q[front][0] = 1;
    q[front][1] = 1;
    rear++;

    while (front < rear) //q�� �� pop�Ǽ� ������ �� ����
    {
        int row = q[front][0];
        int col = q[front][1];
        front++;

        //�����¿� ���캸�� �̵��ؾ���
        for (int i = 0; i < 4; i++)
        {
            int next_row = row + move_row[i];
            int next_col = col + move_col[i];

            //���� �ش� map������ ������ ����� ���
            if (next_row < 1 || next_col < 1 || next_row > n || next_col > m)
                continue;

            //�� �� �ִ� ���� �ƴ϶��,
            //==0���� �θ� ���ư��� ����!!! �̰� ���� �������
            //>n�̳� <m �� ������ �ֱ� ����!!!! (�� ����)
            if (map[next_row][next_col] != 1)
                continue;

            map[next_row][next_col] = map[row][col] + 1;

            //ť�� �̵��� ��ǥ�� �����ؾ���
            q[rear][0] = next_row;
            q[rear][1] = next_col;
            rear++;
        }
    }
    return map[n][m];
}

int main()
{
    //int n, m; �������� �޴°� ����
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