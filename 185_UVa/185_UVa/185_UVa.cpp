// 185_UVa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int RomanValue(char r)
{
	if (r == 'I')
		return 1;
	if (r == 'V')
		return 5;
	if (r == 'X')
		return 10;
	if (r == 'L')
		return 50;
	if (r == 'C')
		return 100;
	if (r == 'D')
		return 500;
	if (r == 'M')
		return 1000;

	return -1;
}

int RomanToArabic(string str)
{
	int res = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		//Send str[i] to RomanValue to get the arabic value
		int s1 = RomanValue(str[i]);

		//Check so str is not finished after current
		if (i + 1 < str.length())
		{
			int s2 = RomanValue(str[i + 1]);
			//If we find addition we have to keep looking towards the next one and perhaps add it in I.E II to III
			if (s1 >= s2)
			{
				res = res + s1;
			}
			//If we find a "subtraction" we can move on I.E I to IV
			else
			{
				res = res + s2 - s1;
				i++;
			}
		}
		//EOS
		else 
		{
			res = res + s1;
			i++;
		}
	}
	return res;
}

string CheckIfSumCorrect(string str)
{
	string as, bs, cs;
	int plus = str.find('+');
	int eq = str.find('=');
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i < plus)
		{
			as += str[i];
		}
		else if (i > plus && i < eq)
		{
			bs += str[i];
		}
		else if(i > eq)
			cs += str[i];
	}
	if (RomanToArabic(as) + RomanToArabic(bs) == RomanToArabic(cs))
	{
		return "Correct";
	}
	else
		return "Incorrect";


}

int main()
{
	string input;
	while (cin >> input)
	{
		if (input == "#")	 
			break;
		cout << CheckIfSumCorrect(input) << endl;

	}
    return 0;
}



