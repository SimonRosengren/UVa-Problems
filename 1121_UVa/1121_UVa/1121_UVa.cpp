// 1121_UVa.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, S;
	vector<int> numbers;

	while (cin >> N >> S)
	{
		for (size_t i = 0; i < N; i++)
		{
			int a = 0;
			cin >> a;
			numbers.push_back(a);
		}

		int best = 100000;
		for (size_t i = 0; i < numbers.size(); i++)
		{
			int sum = numbers[i];
			int counter = i + 1;
			int steps = 1;
			while (sum < S && counter < numbers.size())
			{
				sum += numbers[counter];
				counter++;
				steps++;
			}
			if (steps < best && sum >= S)
			{
				best = steps;
			}
		}
		if (best == 100000)
			cout << 0 << endl;
		else
			cout << best << endl;
		numbers.clear();
	}


    return 0;
}

