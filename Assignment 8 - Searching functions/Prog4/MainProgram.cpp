/*
This program demonstrates the number of comparisons using the binary search
and sequential search algorithms as follows :
List is an array of 1000 elements.
a.It uses a random number generator to fill list.
b.It uses the function insertOrd to initially insert all the elements in the list.
c.Searches the list for some items, as follows :
i.Use the binary search algorithm to search the list. 
	ii.Use the binary search algorithm to search the list, switching to a
	sequential search when the size of the search list reduces to less than
	15. (Use the sequential search algorithm for a sorted list.)
	d.Print the number of comparisons for Steps c.i and c.ii.If the item is
	found in the list, then print its position.

Use differnt array sizes and search for different values ( toward the end of the array ) 
and write your concusion about this implementation of combined searching algorithms.

Write your observations/conclusions to cout ( use random value filled large arrays for your tests )
*/

#include <iostream>

#include "orderedArrayListType.h"

using namespace std;

int size = 1000;

void printListInfo(orderedArrayListType<int>& listInfo);
void fill(orderedArrayListType<int>& listInfo);

int main()
{
	orderedArrayListType<int> intList(::size);

	int num;
	int loc;

	fill(intList);

	cout << "intList: " << endl;
	printListInfo(intList);

	cout << "Enter search item: ";
	cin >> num;
	cout << endl;

	cout << "*****Using binary search*****" << endl;

	intList.initializeNoOfComparisons();

	loc = intList.binSearchEx(num);

	if (loc != -1)
		cout << "Item found at " << loc + 1
			 << ";  Number of comparisons = "
			 << intList.noOfComparisons() << endl;
	else
		cout << "Item not in the list. "
			 << " Number of comparisons = "
			 << intList.noOfComparisons() << endl;

	cout << "*****Using binary and sequential search*****" << endl;

	intList.initializeNoOfComparisons();
	loc = intList.binSeqSearch15(num);

	if (loc != -1)
		cout << "Item found at " << loc + 1
			 << ";  Number of comparisons = "
			 << intList.noOfComparisons() << endl;
	else
		cout << "Item not in the list. "
			 << " Number of comparisons = "
			 << intList.noOfComparisons() << endl;

	system("pause");
	return 0;
}

void printListInfo(orderedArrayListType<int>& listInfo)
{
	cout << "List: ";
	listInfo.print();

	cout << "List Size: " << listInfo.listSize() << endl;
	cout << "Max List Size: " << listInfo.maxListSize() << endl;

}

void fill(orderedArrayListType<int>& listInfo)
{
	int seed = 47;

	int multiplier = 2743;

	int addOn = 5923;

	while (listInfo.listSize() < ::size)
	{
	   listInfo.insertOrd(seed);
	   seed = int((seed * multiplier + addOn) % 100000);
	}

	cout << endl;
}