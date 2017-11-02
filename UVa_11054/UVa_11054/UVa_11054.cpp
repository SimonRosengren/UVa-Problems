// UVa_11054.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include<cmath>
#include<iostream>
#include <algorithm>
using namespace std;


int main()
{
	long long n;
	cin >> n;
	while (n)
	{
		long long temp = 0, x = 0, ans = 0;
		for (int i = 0; i<n; i++)
		{
			cin >> x;
			temp += x;
			ans += abs(temp);
		}
		cout << ans << endl;
		cin >> n;
	}


	return 0;
}
