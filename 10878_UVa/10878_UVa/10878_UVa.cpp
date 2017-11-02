// 10878_UVa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string line = "";
	int letter = 0;
	string answer = "";
	getline(cin, line); //Get rid of first line

	line = ""; //reset first line
	while (line[0] != 95)
	{
		getline(cin, line);
		letter = 0;
		if (line[0] == 124) /*We want to skip first and last line*/ /*124 == |*/
		{
			int exponent = 0;
			for (size_t i = line.length() - 2; i > 0; i--) /*Skip first two rows, either beginning of líne or "1 exception"*/
			{
				if (line[i] == 111) //"o"
				{
					letter += pow(2, exponent); //Add 2^index without period to letter BINARY
				}
				if (line[i] != 46) //If period we dont up the exponent
				{
					exponent++;
				}
			}
			exponent = 0; //Reset exp
		}
		answer += (char)letter;
		letter = 0;
	}
	cout << answer;
    return 0;
}

/*

___________
| o . o|
| o . |
| ooo . o|
| ooo .o o|
| oo o. o|
| oo . oo|
| oo o. oo|
| o . |
| oo . o |
| ooo . o |
| oo o.ooo|
| ooo .ooo|
| oo o.oo |
| o . |
| oo .oo |
| oo o.ooo|
| oooo. |
| o . |
| oo o. o |
| ooo .o o|
| oo o.o o|
| ooo . |
| ooo . oo|
| o . |
| oo o.ooo|
| ooo .oo |
| oo .o o|
| ooo . o |
| o . |
| ooo .o |
| oo o. |
| oo .o o|
| o . |
| oo o.o |
| oo . o|
| oooo. o |
| oooo. o|
| o . |
| oo .o |
| oo o.ooo|
| oo .ooo|
| o o.oo |
| o. o |
___________

*/

