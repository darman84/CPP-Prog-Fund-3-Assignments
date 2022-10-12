/*
Name: Zachary Williams
Class: 2019 Fall - COSC 2336.S70
Project #: Assignment 9 - Hashing
Revision: 1.0.0
Date: 12/4/19

Description:
Modify Problem 2 in chapter 10 to store US president's data ( at least 3 facts should be stored ).
Use website to gather info:
https://en.wikipedia.org/wiki/List_of_presidents_of_the_United_States
Data should be stored in data.txt file in predetermined format by you.

You must modify the driver program to search for existing data, search for non-existing data, modify existing persidential data, and remove a president from the list.

All operations should not require user interaction.


Data file format:///////
President Name
Year of birth of president
Party affiliation
Number of years spent in office
*/

#include <iostream>
#include <fstream>
#include <string>
#include "presData.h"
#include "hashT.h"

using namespace std;

const int HTSize = 101;

int hashFunc(string name);

int main()
{
	hashT<presData> presTable(HTSize);

	ifstream infile;

	presData stData;

	string stName;
	int stYob;
	int key;
	bool found;
	auto swapData = 0;

	cout << "Processing data" << endl;

	infile.open("data.txt");

	for (int i = 1; i <= 6; i++)
	{
		infile>>stData;
		stName = stData.getPresName();
		key = hashFunc(stName);
		presTable.insert(key, stData);
	}

	presTable.print();

	// Search for existing data
	cout << "------------Operating without user input------------" << endl << endl;
	cout << "Searching for Gerald Ford...." << endl;
	stName = "Gerald Ford";
	key = hashFunc(stName);
	stData.setPresInfo(stName, 0, "", 0);
	presTable.search(key, stData, found);
	if (found)
		cout << "Item found in the list." << endl << endl;
	else
		cout << "Item not in the list." << endl << endl;


	// Search for non-existing data
	cout << "Searching for George Washington...." << endl;
	stName = "George Washington";
	key = hashFunc(stName);
	stData.setPresInfo(stName, 0, "", 0);
	presTable.search(key, stData, found);
	if (found)
		cout << "Item found in the list." << endl << endl;
	else
		cout << "Item not in the list." << endl << endl;
	

	// Modifying existing presidential data
	cout << "Modifying Gerald Ford's year of birth to 2019...." << endl;
	stName = "Gerald Ford";
	key = hashFunc(stName);
	stData.setPresInfo(stName, 0, "", 0);
	// Check if the president exists
	presTable.search(key, stData, found);
	// Setting stData to the president that was searched for
	if (found)
		stData=presTable.retrieve(key, stData); // Note that I modified the return type of retrieve()
	else
		cout << "Item not found in the list." << endl << endl;
	
	// Removing the president at the key
	presTable.remove(key, stData);
	// Setting stData to the new data
	stData.setPresInfo(stName, 2019, "Republican", 4);
	// Reinserting stData back into the same place in the hash table
	presTable.insert(key, stData);
	presTable.print();



	// Remove president from the list
	cout << "Removing Bill Clinton from the list...." << endl;
	stName = "Bill Clinton";
	key = hashFunc(stName);
	stData.setPresInfo(stName, 0, "", 0);
	presTable.remove(key, stData);
	presTable.print();





	/*
	cout << "Enter the name of the state to be searched: ";
	getline(cin, stName);
	cout << endl;

	key = hashFunc(stName);
	stData.setPresInfo(stName,0,"",0);
	presTable.search(key, stData, found);

	if (found)
		cout << "Item found in the list" << endl;
	else
		cout << "Item not in the list." << endl;

	cout << "Enter the name of the state to be deleted: ";
	getline(cin, stName);
	cout << endl;

	key = hashFunc(stName);
	stData.setPresInfo(stName, 0, "", 0);
	presTable.remove(key, stData);
	presTable.print();
	*/

	system("pause");
	return 0;
}

int hashFunc(string name)
{
	int i, sum;
	int len;

	i = 0;
	sum = 0;

	len = name.length();

	for (int k = 0; k < 15-len; k++)
	    name = name + ' ';  //increase the length of name to 15 characters

	for (int k = 0; k < 5; k++)
	{
	    sum = sum + static_cast<int>(name[i]) * 128 * 128 
		    + static_cast<int>(name[i + 1]) * 128
		    + static_cast<int>(name[i + 2]);
	    i = i + 3;
	}

	return sum % HTSize;
}
