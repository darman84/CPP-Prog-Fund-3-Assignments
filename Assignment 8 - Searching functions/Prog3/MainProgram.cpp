
//Data:  7 12 18 20 23 27 30 32 38 45 66 68 72 85 -999
/*
The sequential search algorithm does not assume that the
list is in order.Therefore, it usually works the same for both sorted and unsorted
lists.However, if the elements of the list are sorted, you can somewhat improve
the performance of the sequential search algorithm.For example, if the search
item is not in the list, you can stop the search as soon as you find an element in
the list that is larger than the search item.In this example I implemented the seqOrdSearch, the 
sequential search algorithm for sorted lists.Modify this driver program to test the performance 
difference of seqOrdSearch vs. seqSearch methods on the same array.

Write your observations/conclusions to cout ( use random value filled large arrays for your tests )
*/

#include <iostream>
#include <chrono>
#include <time.h>
#include "orderedArrayListType.h"

using namespace std;

void printListInfo(orderedArrayListType<int>& listInfo);

int main()
{
	orderedArrayListType<int> intList(1200);

	int num;
	int loc;
	int lastNum;
	int n; //variable to store the number in


	// I got stack overflow error when using array sizes over 1000, so I had to use 1000
	for (int i = 0; i < 1000; i++)
	{
		bool check; //variable to check or number is already used
		do
		{
			n = rand() % 1000;
			//check or number is already used:
			check = true;
			for (int j = 0; j < i; j++)
				if (intList.isItemAtEqual(j, n)) //if number is already used
				{
					check = false; //set check to false
					break; //no need to check the other elements of value[]
				}
		} while (!check); //loop until new, unique number is found
		intList.insertAt(i, n); //store the generated number in the array
	}
	lastNum = n;

	cout << "The list wll not be printed due to it's length " << endl;

	cout << "Enter search item: ";
	cin>>num;
	cout << endl;

	

	auto t1 = std::chrono::high_resolution_clock::now(); //start the timer
	cout << "Seq Ord Search test" << endl;
	loc = intList.seqOrdSearch(num);
	if (loc != -1)
		cout << "Item found at position " << loc << endl;
	else
		cout << "Item not in the list" << endl;
	loc = -1;
	auto t2 = std::chrono::high_resolution_clock::now(); //stop the timer
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	cout.precision(17);
	cout << duration << " microseconds elapsed" << endl;


	auto t3 = std::chrono::high_resolution_clock::now(); //start the timer
	cout << "Seq Search test" << endl;
	loc = intList.seqSearch(num);
	if (loc != -1)
		cout << "Item found at position " << loc << endl;
	else
		cout << "Item not in the list" << endl;
	loc = -1;
	auto t4 = std::chrono::high_resolution_clock::now(); //stop the timer
	auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
	cout << duration2 << " microseconds elapsed" << endl;


	//searching for the last value
	auto t5 = std::chrono::high_resolution_clock::now(); //start the timer
	cout << "Seq Ord Search Test - last value" << endl;
	loc = intList.seqOrdSearch(lastNum);
	if (loc != -1)
		cout << "Item found at position " << loc << endl;
	else
		cout << "Item not in the list" << endl;
	loc = -1;
	auto t6 = std::chrono::high_resolution_clock::now(); //stop the timer
	auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5).count();
	cout.precision(17);
	cout << duration << " microseconds elapsed" << endl;


	auto t7 = std::chrono::high_resolution_clock::now(); //start the timer
	cout << "Seq Search test - last value" << endl;
	loc = intList.seqSearch(lastNum);
	if (loc != -1)
		cout << "Item found at position " << loc << endl;
	else
		cout << "Item not in the list" << endl;
	loc = -1;
	auto t8 = std::chrono::high_resolution_clock::now(); //stop the timer
	auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(t8 - t7).count();
	cout << duration2 << " microseconds elapsed" << endl;
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