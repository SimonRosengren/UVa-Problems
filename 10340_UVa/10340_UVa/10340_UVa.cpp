// 10340_UVa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string a;
	string b; 

	while (cin >> a >> b)
	{
		int wanderer = 0;
		for (size_t i = 0; i < b.length(); i++)
		{
			if (a[wanderer] == b[i])
			{
				wanderer++;
			}
		}
		if (wanderer == a.length())
		{
			cout << "Yes" << endl;
		}
		else
			cout << "No" << endl;
		wanderer = 0;
	}
    return 0;
}

