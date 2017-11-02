// 920_uva.cpp : defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

class node{
public: 
	int x, y;
	node(int x, int y) { this->x = x; this->y = y; }
};

double nodedistance(node a, node b)
{
	return sqrt((double)(a.x - b.x) * (a.x - b.x)
		+ (a.y - b.y) * (a.y - b.y));
}
bool comp(const node &a, const node &b)
{
	return b.x < a.x;
}

int main()
{
	int c = 0;
	vector<node> nodes;
	
	cin >> c;

	while (c--)
	{
		int n = 0;
		nodes.clear();
		cin >> n;
		for (size_t i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			nodes.push_back(node(x, y));
		}
		//nodes not given in order so we need to sort them, by decreasing order of x (x(0) is at the end)
		sort(nodes.begin(), nodes.end(), comp);

		//i then loop through the points, saving what is the current highest node that ive found.
		//for every new maxheight i add te distance between this and the last maxheight to the sum.

		int currentmaxheight = 0;
		double total = 0;
		for (size_t i = 1; i < nodes.size(); i++) //start at i = 1 because this is the first wall. first node is the starting point
		{
			if (nodes[i].y > currentmaxheight)
			{
				total += nodedistance(nodes[i], nodes[i - 1])
					* (nodes[i].y - currentmaxheight) / (nodes[i].y - nodes[i - 1].y);
				currentmaxheight = nodes[i].y;
			}
		}
		// Print with two decimal digits.
		// Print with two decimal digits.
		cout << setprecision(2)
			<< setiosflags(ios::fixed)
			<< total << endl;

		
	}
	
    return 0;
}

