//// 10245_UVa.cpp : Defines the entry point for the console application.
////
//
//#include "stdafx.h"
//// A divide and conquer program in C/C++ to find the smallest distance from a
//// given set of points.
//
//#include <stdio.h>
//#include <float.h>
//#include <vector>
//#include <stdlib.h>
//#include <math.h>
//#include <iostream>
//
//using namespace std;
//
//// A structure to represent a Point in 2D plane
//struct Point
//{
//	int x, y;
//};
//
///* Following two functions are needed for library function qsort().
//Refer: http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
//
//// Needed to sort array of points according to X coordinate
//int compareX(const void* a, const void* b)
//{
//	Point *p1 = (Point *)a, *p2 = (Point *)b;
//	return (p1->x - p2->x);
//}
//// Needed to sort array of points according to Y coordinate
//int compareY(const void* a, const void* b)
//{
//	Point *p1 = (Point *)a, *p2 = (Point *)b;
//	return (p1->y - p2->y);
//}
//
//// A utility function to find the distance between two points
//float dist(const Point& a, const Point& b) {
//	float x = a.x - b.x, y = a.y - b.y;
//	return x*x + y*y;
//}
//
//// A Brute Force method to return the smallest distance between two points
//// in P[] of size n
//float bruteForce(Point P[], int n)
//{
//	float min = 10000;
//	for (int i = 0; i < n; ++i)
//		for (int j = i + 1; j < n; ++j)
//			if (dist(P[i], P[j]) < min)
//				min = dist(P[i], P[j]);
//	return min;
//}
//
//// A utility function to find minimum of two float values
//float min(float x, float y)
//{
//	return (x < y) ? x : y;
//}
//
//
//// A utility function to find the distance beween the closest points of
//// strip of given size. All points in strip[] are sorted accordint to
//// y coordinate. They all have an upper bound on minimum distance as d.
//// Note that this method seems to be a O(n^2) method, but it's a O(n)
//// method as the inner loop runs at most 6 times
//float stripClosest(Point strip[], int size, float d)
//{
//	float min = d;  // Initialize the minimum distance as d
//
//	qsort(strip, size, sizeof(Point), compareY);
//
//	// Pick all points one by one and try the next points till the difference
//	// between y coordinates is smaller than d.
//	// This is a proven fact that this loop runs at most 6 times
//	for (int i = 0; i < size; ++i)
//		for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
//			if (dist(strip[i], strip[j]) < min)
//				min = dist(strip[i], strip[j]);
//
//	return min;
//}
//
//// A recursive function to find the smallest distance. The array P contains
//// all points sorted according to x coordinate
//float closestUtil(Point P[], int n)
//{
//	// If there are 2 or 3 points, then use brute force
//	if (n <= 3)
//		return bruteForce(P, n);
//
//	// Find the middle point
//	int mid = n / 2;
//	Point midPoint = P[mid];
//
//	// Consider the vertical line passing through the middle point
//	// calculate the smallest distance dl on left of middle point and
//	// dr on right side
//	float dl = closestUtil(P, mid);
//	float dr = closestUtil(P + mid, n - mid);
//
//	// Find the smaller of two distances
//	float d = min(dl, dr);
//
//	// Build an array strip[] that contains points close (closer than d)
//	// to the line passing through the middle point
//	Point strip[10000];
//	int j = 0;
//	for (int i = 0; i < n; i++)
//		if (abs(P[i].x - midPoint.x) < d)
//			strip[j] = P[i], j++;
//
//	// Find the closest points in strip.  Return the minimum of d and closest
//	// distance is strip[]
//	return min(d, stripClosest(strip, j, d));
//}
//
//// The main functin that finds the smallest distance
//// This method mainly uses closestUtil()
//float closest(Point P[], int n)
//{
//	qsort(P, n, sizeof(Point), compareX);
//
//	// Use recursive function closestUtil() to find the smallest distance
//	return closestUtil(P, n);
//}
//
//// Driver program to test above functions
//int main()
//{
//	int n;
//	Point P[1000];
//	cin >> n;
//	while (n)
//	{
//		int x, y;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> x >> y;
//			P[i] = { x, y };
//		}
//		float ans = closest(P, n);
//		if (ans < 10000)
//		{
//			cout << sqrt(ans);
//		}
//		else
//			cout << "INFINITY";
//
//		cin >> n;
//	}
//	return 0;
//}
#include "stdafx.h"
#include<iostream>
#include<cmath>
using namespace std;
typedef pair<float, float> Point;
float Dist(const Point& a, const Point& b) {
	float x = a.first - b.first, y = a.second - b.second;
	return x*x + y*y;
}
int main() {
	cout.precision(4);
	cout << fixed;
	int n;
	float dist;
	Point x[10005];
	while (cin >> n, n) {
		dist = 10000;
		for (int i = 0; i<n; i++)
			cin >> x[i].first >> x[i].second;
		for (int i = 0; i<n; i++) {
			for (int j = i + 1; j<n; j++) {
				if (Dist(x[i], x[j]) < dist)
				{
					dist = Dist(x[i], x[j]);
				}
			}
		}
		if (dist == 10000) cout << "INFINITY" << endl;
		else cout << sqrt(dist) << endl;
	}
	return 0;
}