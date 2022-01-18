#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 

typedef struct NodeStruct
{
	struct NodeStruct* left; 
	struct NodeStruct* right; 
	int value; 
}Node;

Node* insert(Node* root, int value) 
{
	if (root == NULL) // root ���� �� ��� ������ ���� ���������������� ��ó� ������ ����
	{
		root = (Node*)malloc(sizeof(Node));
		root->left = root->right = NULL;
		root->value = value; //�� ��쵵 ���������� ��ó� ������ �Ȱ��� ��ó�
		return root;
	}
	else //NULL�� �ƴ� ���
	{
		if (root->value > value) //���� ��庸�� ���� ���� ���
			root->left = insert(root->left, value); //�������� ����
		else //ū ���
			root->right = insert(root->right, value); //������ ����
	}
	return root; 
}

Node* search(Node* root, int value) 
{	
	Node* temp = root;
	
	while (1)
	{
		if (temp == NULL) //temp NULL�̸� NULL return ��Ŵ -> �������� ��ó�
		{
			return NULL;
		}
		if (temp->value == value) //value ���̶� ������ �״�� ����
		{
			return temp;
		}
		else if (temp->value > value) //temp ���� value ���� �� ũ�� temp�� ���ʿ�
		{
			temp = temp->left;
		}
		else // �� �� �ƴϸ� ������ ������ �ۿ� ����. ���������� ������
		{
			temp = temp->right;
		}
	}
}

int main(void) 
{
	Node* root = NULL;
	char file_name[10]; 
	int n, m, num;
	int* find; //ã�����ϴ� ���� �迭
	
	FILE* fp; 

	printf("Enter File Name? ");
	scanf("%s", file_name); //���� �̸� �Է� 

	fp = fopen(file_name, "r"); //���� open
	fscanf(fp, "%d %d", &n, &m); //n, m �� �ҷ�����
	find = malloc(sizeof(int) * n); //n�� ��ŭ �迭�� �����Ҵ� ��Ŵ!!!!!

	for (int i = 0; i < n; i++) //ã�� n����ŭ ���� �б�
	{	
		fscanf(fp, "%d", &find[i]);
	}
	for (int i = 0; i < m; i++) //���� �迭�� Ʈ���� �����Ѵ� 
	{ 
		fscanf(fp, "%d", &num);
		root = insert(root, num); //root�� ����־����������� ��ó�
	}

	for (int i = 0; i < n; i++) //ã�� ���� ã�� 
	{ 
		if (search(root, find[i]))
		{
			printf("Yes "); //������ yes
		}
		else {
			printf("No "); // �ƴϸ� no
		}
	}
	return 0;
}
