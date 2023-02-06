// HashTablesChaining.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Hash Table code
// Using chaining
#include<iostream> 
#include <list>
#include <cstdlib>
#include <ctime>
using namespace std;

class HT
{
	int numIndexes;
	list<int>* hashT;

public:
	HT(int V); // Constructor 

	void insertItem(int x);
	void deleteItem(int key);

	int hash(int x)
	{
		return (x % 399);
	}

	void displayHash();
};

HT::HT(int b)
{
	this->numIndexes = b;
	hashT = new list<int>[numIndexes];
}

void HT::insertItem(int key)
{
	int index = hash(key);
	hashT[index].push_back(key);
}

void HT::deleteItem(int key)
{
	// get the hash index of key 
	int index = hash(key);

	// find the key in (inex)th list 
	list <int> ::iterator i;
	for (i = hashT[index].begin();
		i != hashT[index].end(); i++) {
		if (*i == key)
			break;
	}

	if (i != hashT[index].end())
		hashT[index].erase(i);
}

void HT::displayHash()
{
	for (int i = 0; i < numIndexes; i++)
	{
		cout << i;
		for (auto x : hashT[i])
			cout << " --> " << x;
		cout << endl;
	}
}

// Driver program 
int main()
{
	int size = 100;
	int* arr = new int[size];
	clock_t start;
	clock_t end;
	start = clock();
	srand(time(NULL));
	for (int j = 0; j < size; j++)
	{
		arr[j] = rand();
	}

	HT h(399);
	for (int i = 0; i < size; i++)
	{
		h.insertItem(arr[i]);
	}
	end = clock();
	cout << "Time it takes to insert " << (end - start) << endl;
	system("pause");
	start = clock();
	h.displayHash();
	end = clock();
	cout << "Time it takes to Retreive " << (end - start) << endl;
	system("pause");
	//h.deleteItem();
	start = clock();
	for (int i = 0; i < size; i++)
	{
		h.deleteItem(arr[i]);
	}
	end = clock();
	cout << "Time it takes to Delete " << (end - start) << endl;
	// display the Hash hashT
	//h.displayHash();
	
	cout << "Complete \n";
	return 0;
}