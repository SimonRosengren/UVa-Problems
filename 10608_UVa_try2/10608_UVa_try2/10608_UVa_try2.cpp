// 10608_UVa_try2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

/*Represents one citizen and a ligt of all his direct friends*/
class Citizen
{
public: 
	bool visited;
	vector<Citizen*> friends;
	Citizen()
	{
		visited = false;
	}
	void addFriend(Citizen* c)
	{
		friends.push_back(c);
	}
	Citizen* getFriendAt(int index)
	{
		return friends.at(index);
	}
};

void Explore(Citizen* c, int &counter);

int testCases = 0;
int nrOfCitizens = 0;
int nrOfFriendships = 0;

int main()
{
	scanf_s("%d", &testCases);

	for (size_t i = 0; i < testCases; i++) //Loop through all the test cases
	{
		scanf_s("%d %d", &nrOfCitizens, &nrOfFriendships);
		vector<Citizen*> citizens;
		for (size_t j = 0; j < nrOfCitizens; j++)	/*Create each of the citizens*/
		{
			citizens.push_back(new Citizen());
		}
		while (nrOfFriendships--)
		{
			int f1 = 0;
			int f2 = 0;
			scanf_s("%d %d", &f1, &f2);
			citizens.at(f1 - 1)->addFriend(citizens.at(f2 - 1));
			citizens.at(f2 - 1)->addFriend(citizens.at(f1 - 1));
		}
		int counter = 0;
		int largestGroup = 0;
		for (size_t k = 0; k < nrOfCitizens; k++)
		{
			counter = 0;
			Explore(citizens.at(k), counter);
			if (largestGroup < counter)
			{
				largestGroup = counter;
			}
		}
		cout << largestGroup << endl;
	}

    return 0;
}

//Return the size of the largest group of friends. Send in 0 as start
void Explore(Citizen* c, int &counter)
{
	counter++; //Everytime we get here we know that we can add one to group. 
	c->visited = true; //And set the citizens visited status to true
	for (size_t i = 0; i < c->friends.size(); i++) //Go through each of the citizens friends and call Explore on each one of them recursivley
	{
		/*Check if friend has already been visited*/
		if (!c->friends.at(i)->visited)
		{
			Explore(c->getFriendAt(i), counter);
		}
	}
}

