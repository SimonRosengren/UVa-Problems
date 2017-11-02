// UVa_374.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

double ModeExp(long x, long y, long N);
int main()
{
	int B, P, M = 0;
	while (cin >> B >> P >> M)
	{
		cout << ModeExp(B, P, M) << endl;
	}
    return 0;
}

double ModeExp(long x, long y, long N)
{
	if (y == 0)
		return 1;
	long z = ModeExp(x, y / 2, N);
	if (y % 2 == 0)
		return (z * z) % N;
	else
		return (x * (z * z)) % N;
}



