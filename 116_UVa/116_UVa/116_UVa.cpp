// 116_UVa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const int INF = 10000;

const int Y_MAX = 10;
const int X_MAX = 100;

int graph[X_MAX][Y_MAX];
int cost[X_MAX][Y_MAX];
int path[X_MAX][Y_MAX];

int ySize, xSize;

int findPathDP(int i, int j)
{
	if (j >= xSize)
	{
		return 0;
	}
	if (cost[i][j] != INF)
	{
		//This cost is already calculated
		return cost[i][j];
	}

	int paths[3]{ i - 1, i, i + 1 };//possible paths from current node
	if (i == 0)
		paths[0] = ySize - 1;	//Exeptions when we can go to "other side" of graph since it's wrapped
	if (i == ySize - 1)
		paths[2] = 0;

	for (size_t k = 0; k < 3; k++) //Loop through the possible paths to go from current node
	{
		int value = graph[i][j] + findPathDP(paths[k], j + 1);
		if (cost[i][j] > value || (cost[i][j] == value && path[i][j] > paths[k])) //Here we also keep output lexicographical if there are more then one best path
		{
			cost[i][j] = value;
			//Save the path by saving where to go from current node in path[][]. We have the best way to take from paths' kth element
			path[i][j] = paths[k];
		}
	}
	return cost[i][j];
}

int main()
{
	while (cin >> ySize >> xSize)
	{
		for (size_t i = 0; i < ySize; i++)
		{
			for (size_t j = 0; j < xSize; j++)
			{
				cin >> graph[i][j];
				cost[i][j] = INF;
			}
		}


		int lowestCost = INF;
		int r = 0;
		for (size_t i = 0; i < ySize; i++)
		{
			findPathDP(i, 0);
			if (cost[i][0] < lowestCost)
			{
				lowestCost = cost[i][0];
				r = i;
			}
		}

		//cout << "PATH" << endl;
		//for (size_t i = 0; i < ySize; i++)
		//{
		//	for (size_t j = 0; j < xSize; j++)
		//	{
		//		cout << path[i][j];
		//	}
		//	cout << endl;
		//}

		// Print path.
		for (int j = 0; j < xSize; j++) {
			if (j == 0)
			{
				cout << 1 << " ";
			}
			else cout <<  r + 1 << " ";
			r = path[r][j];
		}
		cout << endl << lowestCost << endl;
	}
    return 0;
}

