#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 1001

int VertexAmount, EdgeAmount;
bool BidrectionMatrix[MAX][MAX] = { 0, }; // define 2d matrix for Bidrection Access
bool DoVisit[MAX] = { false, }; // stack memory space >> Limited 1~8MB, so declare in Data Memory

void DFS(int _input);

int main()
{
	int Result = 0;
	scanf("%d %d", &VertexAmount, &EdgeAmount);

	for (int i = 0; i < EdgeAmount; i++) // �� input Edge and translate it for BidrectionMatrix
	{
		int u, v;
		scanf("%d %d", &u,&v); // �� input
		BidrectionMatrix[u][v] = 1; // �� translate
		BidrectionMatrix[v][u] = 1;
	}

	for (int i = 1; i <= VertexAmount; i++) // �� Search for DFS except Visited Vertexes(Nodes)
	{
		if (!DoVisit[i])
		{
			DFS(i);
			Result++;
		}
	}

	printf("%d", Result); // print Result(Connected Component)
	return 0;
}

void DFS(int _vRoot)
{
	DoVisit[_vRoot] = true; // Check DoVisit
	for (int i = 1; i <= VertexAmount; i++)
	{
		if (BidrectionMatrix[_vRoot][i] && !DoVisit[i]) // ����� ��尡 �湮�� �� ���� ����Ͻ�, �ش� ��忡 ���� dfs Ž��
		{
			DFS(i);
		}
	}
}