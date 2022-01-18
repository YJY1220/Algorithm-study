#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 40 //27�ε� ���� 20���� ���ٹ��� �Ѥ�

int map[MAX_SIZE][MAX_SIZE];
int count;

int check(int x, int y, int n);
void Fence(int x, int y, int n);

int main(void)
{
    int n;
    char file_name[10];

    printf("Enter File Name?");
    scanf("%s", &file_name);

    FILE* fp;
    fp = fopen(file_name, "r");
    fscanf(fp, " %d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &map[i][j]); //input ���� ���� �迭�� �Է¹���
        }
    }
    Fence(0, 0, n); //�̰� fence�� �Լ� ������ count�� ������Ŵ
    printf("%d", count); //count ���

    return 0;
}

void Fence(int x, int y, int n) //count++�� fence����� ��(�칰 ���� �����)
{
    //if (n < 3) return; 
    if ((!check(x,y,n))) //1�� ���ϵ��� �ʴ´�, �� 0�� ���ϵǸ� �̶�� ���̴ϱ� find!=map[i][j] ��� ��
    {
        count++; //���� �ʴٸ� count�� 1 ������Ų��
            for (int i = x; i < x + n; i += n / 3) //�迭 x��, �� check���� �ɷȴ� �κ��� x���� �ٽ� ������,  
                                                   //�� ������ �����ϳĸ� ���� check���� �޾Ҵ� n�� �� 9���� ������ 3�� �� 3������ŭ �� Ž����
                                                   //�׷��� ���� ���� 3��ŭ������ �� ���ԵǹǷ� x�� �ε��� 2�� ��� 5������ Ž����
                                                   //�ֳĸ� �칰���� ������� fence�� �����Ƿ� �� �̻��� Ž���ϸ� �ȵ�
            {
                for (int j = y; j < y + n; j += n / 3) //�굵 ���� x�� ���� ������
                {
                    Fence(i, j, n / 3); //�ϰ��� �ٽ� ��ͷ� ������ �� �� �� Ž��
                }
            }
    }
    return 0; //������ ��
}


int check(int x, int y, int n) //Ž���ϴٰ� �ٸ� �� �ִ� �� Ȯ���ϴ� ��
{
    int find = map[x][y]; //find=pivot, �迭�� find���ٰ� �����ؼ� ����ٰ� �����ְڴ�, �ٵ� �ִ�� 20,20�̴�. �̼Ҹ���

    for (int i = x; i < x + n; i++) //������ �κ��� Ž������ �Ұǵ�, �� �� ���� �κ��� x�κ� �����̴ϱ� ������ �����ϰڴ�. 
                                    //+n�� ��쿣 ����ŭ ����� �� ����� ���߿� �� ������ ����ŭ Ž����.
    {
        for (int j = y; j < y + n; j++) //������ �κ� Ž�� �����Ұǵ� ���ۺκ��� y�ϱ� ������ �����ϰڴ�,
                                        //���࿡ y�� 3��° �ε������ �ű⼭ ��� ������
                                        //�� ������ �ϳĸ� y�ε����� �Է¹��� �ſ��� �������� ũ���� n��ŭ�� �÷����ؼ� ����ؾ���
        {
            if (find != map[i][j]) //pivot�� Ž���Ǵ� map�� �迭 ���ڰ� ���� �ʴٸ� return 0 ���Ѽ� �� �Լ��� ������������
                return 0;
        }
    }
    return 1; //���ٸ� 1 ���
}

