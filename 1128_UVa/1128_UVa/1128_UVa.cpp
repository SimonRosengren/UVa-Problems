// 1128_UVa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

unsigned long long fibo(long n)
{
	if (n == 0)
	{
		return 0;
	}
	vector<unsigned long long> arr;
	arr.push_back(0);
	arr.push_back(1);
	for (size_t i = 2; i < n + 1; i++)
	{
		arr.push_back(arr.at(i - 1) + arr.at(i - 2));
	}
	return arr.at(n);
}

int main()
{
	int a;
	while (cin >> a)
	{
		cout << fibo(a * 2) << endl;
	}
	return 0;
}

