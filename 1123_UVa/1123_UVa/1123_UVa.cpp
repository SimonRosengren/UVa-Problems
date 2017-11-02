// 1123_UVa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	int cases = 0;
	int n = 0, nc = 0;
	string input;
	cin >> cases;
	while (cases--)
	{
		cin >> n >> nc;
		getline(cin, input);
		cout << "test: " << input;
	}
    return 0;
}

