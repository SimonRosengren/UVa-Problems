// 10300_UVa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
	int n, f, s, a, e;
	scanf_s("%d", &n);
	int score = 0;

	for (size_t i = 0; i < n; i++)
	{
		scanf_s("%d", &f);
		score = 0;
		for (size_t i = 0; i < f; i++)
		{
			scanf_s("%d %d %d", &s, &a, &e);
			score += s*e; //Vi kan förkorta bort * och / med antal djur
		}
		printf("%d\n", score);
	}

	return 0;
}

