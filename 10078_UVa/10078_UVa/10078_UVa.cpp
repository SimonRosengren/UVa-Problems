// 10078_UVa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//Point in 2D Space
struct Point
{
	int x, y;
	bool operator < (const Point &p) {
		return x < p.x || (x == p.x && y == p.y);
	}
};
//Cross product
//Negative if oab makes a right turn, positive if left and zero if they're colinear
int cross(Point &o, Point &a, Point &b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

/*If polygon is convex, there are no critical points. We can then see everything from anywhere
In other words, if we walk along the outer lines of the polygon and we only make the same turn, it is convex.
This can be check through the cross product*/
int main()
{
	int n;

	cin >> n;
	while (n)
	{
		int i;
		vector<Point> points;
		for (int j = 0; j < n; j++)
		{
			Point p;
			cin >> p.x >> p.y;
			points.push_back(p);
		}
		//We need to add the two first points also to the back of the vector so we can go a full circle
		points.push_back(points[0]);
		points.push_back(points[1]);
		//Now we "walk" along the walls and check if we only make the same turn.
		//Check if first turn is left left
		if (cross(points[0], points[1], points[2]) >= 0)
		{
			//then we check if the rest of the turns are lefts. If not we say 'NO' and break
			for (i = 0; i < n; i++) //Note that we are using i which is pre-defined
			{
				if (cross(points[i], points[i + 1], points[i + 2]) < 0)
				{
					break;
				}
			}
		}
		//Else check for right turns
		else
			for (i = 0; i < n; i++)
			{
				if (cross(points[i], points[i + 1], points[i + 2]) > 0)
				{
					break;
				}
			}

		//If i != n we called "break" somewhere which means that there is a critical point
		if (i != n)
		{
			cout << "Yes\n";
		}
		else
			cout << "No\n";
		cin >> n;
	}




    return 0;
}


