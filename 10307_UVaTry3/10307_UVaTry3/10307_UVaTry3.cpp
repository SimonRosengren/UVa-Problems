// 10307_UVaTry3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include<vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

int const INF = 99;
int const MAX_SIZE = 51;

struct edge {
public:
	edge(int U, int V, int weight) { this->U = U; this->V = V; this->weight = weight; }
	int U;
	int V;
	int weight;
};

char ** maze;
int sizeX, sizeY;

vector<pair<int, int>> nodesToSearchFrom;
vector<edge> edges;


void ReadMaze();
void BFS(int start);
int Kruskals();




int main()
{
	int nrOfCases = 0;
	cin >> nrOfCases;
	for (size_t i = 0; i < nrOfCases; i++)
	{
		ReadMaze();
		for (size_t j = 0; j < nodesToSearchFrom.size(); j++)
		{
			BFS(j);
		}
		cout << Kruskals();
	}

	return 0;
}

void ReadMaze()
{
	cin >> sizeX >> sizeY;

	/*Create the matrix*/
	maze = new char*[sizeY];
	for (size_t i = 0; i < sizeY; i++)
	{
		maze[i] = new char[sizeX];
	}

	string line;
	getline(cin, line); //WHat? //Reading in a weird ""
	for (size_t i = 0; i < sizeY; i++)
	{
		getline(cin, line);
		for (size_t j = 0; j < sizeX; j++)
		{
			maze[i][j] = line[j];
			if (line[j] == 'A' || line[j] == 'S')
			{
				nodesToSearchFrom.push_back(pair<int, int>(i, j));
			}
		}
	}
}

void BFS(int start)
{
	int distMatrix[51][51];

	for (size_t i = 0; i < 50; i++)
	{
		for (size_t j = 0; j < 50; j++)
		{
			distMatrix[i][j] = INF;
		}
	}

	distMatrix[nodesToSearchFrom.at(start).first][nodesToSearchFrom.at(start).second] = 0;

	queue<pair<int, int>> nodes;
	nodes.push(nodesToSearchFrom.at(start));

	queue<int> distQueue;
	distQueue.push(1);

	int distanceTraveled = 0;

	while (!nodes.empty())
	{
		distanceTraveled++;
		pair<int, int> const& v = nodes.front();

		int const& currentDistance = distQueue.front();

		if (v.second + 1 <= sizeY - 1) /*Ok to go right?*/
		{
			if (maze[v.first][v.second + 1] != '#' && currentDistance + 1 < distMatrix[v.first][v.second + 1]) { /*Right*/
				distMatrix[v.first][v.second + 1] = currentDistance;
				nodes.push(pair<int, int>(v.first, v.second + 1));
				distQueue.push(distMatrix[v.first][v.second + 1] + 1);
				if (maze[v.first][v.second + 1] == 'A' || maze[v.first][v.second + 1] == 'S')
				{
					edges.push_back(edge(start, edges.size(), currentDistance));
				}
			}
		}
		if (v.second - 1 >= 0) /*Ok to go Left?*/
		{
			if (maze[v.first][v.second - 1] != '#' && currentDistance + 1 < distMatrix[v.first][v.second - 1]) { /*Left*/
				distMatrix[v.first][v.second - 1] = currentDistance;
				nodes.push(pair<int, int>(v.first, v.second - 1));
				distQueue.push(distMatrix[v.first][v.second - 1] + 1);
				if (maze[v.first][v.second - 1] == 'A' || maze[v.first][v.second - 1] == 'S')
				{
					edges.push_back(edge(start, edges.size(), currentDistance));
				}
			}
		}
		if (v.first + 1 <= sizeX - 1) /*Ok to go right?*/
		{
			if (maze[v.first + 1][v.second] != '#' && currentDistance + 1 < distMatrix[v.first + 1][v.second]) { /*Down*/
				distMatrix[v.first + 1][v.second] = currentDistance;
				nodes.push(pair<int, int>(v.first + 1, v.second));
				distQueue.push(distMatrix[v.first + 1][v.second] + 1);
				if (maze[v.first + 1][v.second] == 'A' || maze[v.first + 1][v.second] == 'S')
				{
					edges.push_back(edge(start, edges.size(), currentDistance));
				}
			}
		}
		if (v.first - 1 >= 0) /*Ok to go left?*/
		{
			if (maze[v.first - 1][v.second] != '#' && currentDistance + 1 < distMatrix[v.first - 1][v.second])
			{ /*Up*/
				distMatrix[v.first - 1][v.second] = currentDistance;
				nodes.push(pair<int, int>(v.first - 1, v.second));
				distQueue.push(distMatrix[v.first - 1][v.second] + 1);
				if (maze[v.first - 1][v.second] == 'A' || maze[v.first - 1][v.second] == 'S')
				{
					edges.push_back(edge(start, edges.size(), currentDistance));
				}
			}
		}
		distQueue.pop();
		nodes.pop();
	}
}


bool wcomp(edge const &a, edge const &b)
{
	return a.weight < b.weight;
}

int set[MAX_SIZE];
void MakeSet(int index)
{
	set[index] = index;
}
int Find(int index)
{
	if (set[index] == index)
	{
		return index;
	}
	return Find(set[index]);
}

bool Union(int X, int Y)
{
	int rX = Find(X);
	int rY = Find(Y);
	if (rX == rY)
	{
		return false;
	}
	else
		set[rX] = rY;
	return true;
}

int Kruskals()
{
	int nrOfSteps = 0;
	sort(edges.begin(), edges.end(), &wcomp);
	for (size_t i = 0; i < nodesToSearchFrom.size(); i++)
	{
		MakeSet(i);
	}
	for (size_t i = 0; i < edges.size(); i++)
	{
		if (Union(edges.at(i).U, edges.at(i).V))
		{
			nrOfSteps += edges.at(i).weight;
		}
	}
	return nrOfSteps;
}

//1
//6 5
//#####
//#A#A##
//# # A#
//#S ##
//#####