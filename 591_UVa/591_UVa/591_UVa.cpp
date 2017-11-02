// 591_UVa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

void quickSort(int arr[], int left, int right);
int evenOut(int arr[], int height, int n);

int main()
{
	int n = 1;
	int currentSet = 0;
	cin >> n; //Nr of towers in firt case
	while (n != 0) //Finish when given 0
	{
		int sum = 0;
		int * arr = new int[n];
		int tmp = 0;

		for (size_t i = 0; i < n; i++) //Read in all towers of case
		{
			cin >> tmp;
			arr[i] = tmp;
			sum += arr[i];
		}

		quickSort(arr, 0, n - 1); //Sort the towers by height

		int height = sum / n; //Calculate what size the numbers should be to be of even height

		currentSet++; //To know what case we are reading next

		printf("Set #%d\nThe minimum number of moves is %d.\n\n", currentSet, evenOut(arr, height, n - 1));
		cin >> n; //Continue reading cases
	}

    return 0;
}

void quickSort(int arr[], int left, int right)
{
	int i = left, j = right;
	int temp;
	int pivot = arr[(left + right) / 2]; //Set pivot to mid array

	/*Partition*/
	while (i <= j)
	{
		/*Wander until we find something on the wrong side of pivot on left side*/
		while (arr[i] < pivot)
		{
			i++;
		}
		/*Wander unil we find something on the wrong side of pivot on the right side*/
		while (arr[j] > pivot)
		{
			j--;
		}
		/*Swap*/
		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	/*Sort right hand side first*/
	if (left < j)
	{
		quickSort(arr, left, j);
	}
	/*Then left hand side*/
	if (i < right)
	{
		quickSort(arr, i, right);
	}
}

int evenOut(int arr[], int height, int n)
{
	int * min = arr; //Pointer to first plase of array
	int * max = arr + n;	//Pointer to last place of array 

	int nrOfChanges = 0; 

	/*Keep checking if we need to change until the pointers are pointing at the same location of the array.
	When this happens we know that we are finished*/
	while (min != max)
	{
		if (*min < height) //True if we need to add blocks to what min is pointing to
		{
			if (*max > height) //Check if we can collect bricks from what max is pointing to. True if we can, otherwise we let the pointer wander one step backwards
			{
				*max -= 1; //subtract one from max
				*min += 1; //add one to min
				nrOfChanges++; //We now made one change
			}
			else if(*max <= height) //wander max backwards
				max--;
		}
		else if (*min >= height) //Wander min one step up
		{
			min++; 
		} 
	}
	return nrOfChanges;
}

