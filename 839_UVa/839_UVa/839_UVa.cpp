// 839_UVa.cpp : Defines the entry point for the console application.
//


/*I recursivley go down the tree to add all the sums for both side.
Then I check if the sum of weights with the top layers distances 
make the tree in equiblrium. */

#include "stdafx.h"
#include <iostream>

using namespace std;

int traverseMobile();


bool balanced = true;

int main()
{
	int cases;
	scanf_s("%d", &cases);

	while (cases--)
	{
		traverseMobile();
		if (balanced)
		{
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
		//if (cases)puts("");
	}
    return 0;
}



/*This method recursivley reads the lines and decieds whater it should
continue to read the next line or if we have a line with weights that we need to return and
so that we can add them to the sum of weights for each side*/
int traverseMobile()
{
	int wl, d1, wr, d2; /*To store the weights and distances*/
	scanf_s("%d %d %d %d", &wl, &d1, &wr, &d2); //Read in the distance and weights
	
	if (wl == 0)		//If w1 == 0 we have a new one on the left
	{
		wl = traverseMobile();	//Assign the weaight from previous ones to w1. Like this we eventually get the total weight of the side
	}

	if (wr == 0)	//w2 == 0 means new on right
	{
		wr = traverseMobile();
	}
	balanced = (wl * d1 == wr * d2); //Check if balanced every recursion. At last we will check the balance of the entire tree
	return wl + wr; //Return the sum of weaights
}



