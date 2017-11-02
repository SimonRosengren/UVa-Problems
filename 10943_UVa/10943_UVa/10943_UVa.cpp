// 10943_UVa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int graph[100][100];

	for (size_t i = 0; i < 100; i++)
	{
		graph[0][i] = i + 1;
		graph[i][0] = 1;
	}

	for (size_t i = 0; i < 100; i++)
	{
		graph[i][i] = 1;
	}

	for (size_t i = 1; i < 100; i++)
	{
		for (size_t j = 1; j < 100; j++)
		{
			graph[i][j] = (graph[i - 1][j] + graph[i][j - 1]) % 1000000; //?????????????? NÄRA
		}
	}

	for (size_t i = 0; i < 100; i++)
	{
		graph[i][i] = 1;
	}

	int a, b = 0;
	while (cin >> a >> b)
	{
		if (a && b != 0)
		{
			cout << graph[a - 1][b - 1] << endl;
		}
		else break;
	}


	//for (size_t i = 0; i < 100; i++)
	//{
	//	for (size_t j = 0; j < 100; j++)
	//	{
	//		cout << graph[i][j] << "  ";
	//	}
	//	cout << endl;
	//}
    return 0;
}

