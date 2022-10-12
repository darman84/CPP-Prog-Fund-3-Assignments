/*Modify the driver program that tests the 
performance difference of the two search algorithms in arrayListType.h
Fill the array(s) with random values at least 100000 and test searching for a random value 
and also for searching for the last value in the array.  You can also try to fill the array(s) with
sequencial valuel ( sorted order ) and see if the performance changes at all.
Print out the results of your tests.

Sequential search
 int seqSearch(const elemType& item) const;

Recursive sequential search
 int recursiveSeqSearch(const elemType& item) const;

*/

#include <iostream> 
#include <time.h>       /* time */
#include "arrayListType.h"
#include <chrono>

using namespace std;


void printListInfo(arrayListType<int>& listInfo);

int main()
{
	srand(time(NULL));

	arrayListType<int> intList(1200);

	int num = 0;
	int loc;
	int oldNum = 0;
	
	
/*cout << "Enter numbers ending with -999" << endl;
	cin >> num;

	while (num != -999)
	{
		intList.insert(num);
		cin >> num;
	}
*/

	// I got stack overflow error when using array sizes over 1000, so I had to use 1000
	for (int i = 0; i < 1000; i++)
	{
		bool check; //variable to check or number is already used
		int n; //variable to store the number in
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


/*
	cout << "The list you entered is: " << endl;
	printListInfo(intList);
*/
	cout << "The list has 1000 random items, which will not be printed to the console" << endl;
	
	cout << "Enter search item: ";
	cin >> num;
	cout << endl;

	
	auto t1 = std::chrono::high_resolution_clock::now(); //start the timer
	loc = intList.recursiveSeqSearch(num);
	cout << "Recursive sequential search result:" << endl;
	if (loc != -1)
		cout << "Item found at " << loc + 1 << endl;
	else
		cout << "Item not in the list" << endl;
	auto t2 = std::chrono::high_resolution_clock::now(); //stop the timer
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	cout.precision(17);
	cout << duration << " microseconds elapsed" << endl;


	auto t3 = std::chrono::high_resolution_clock::now(); //start the timer
	cout << "Sequential search result:" << endl;
loc = intList.seqSearch(num);

	if (loc != -1)
		cout << "Item found at " << loc + 1 << endl;
	else
		cout << "Item not in the list" << endl;
	auto t4 = std::chrono::high_resolution_clock::now(); //stop the timer
	auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
	cout << duration2 <<" microseconds elapsed" << endl;

	//searching for the last value
	auto t5 = std::chrono::high_resolution_clock::now(); //start the timer
	cout << "Reucursive Sequential Search Test - last value" << endl;
	loc = intList.binarySearch(lastNum);
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
	cout << "Sequential Search test - last value" << endl;
	loc = intList.recursiveBinarySearch(lastNum);
	if (loc != -1)
		cout << "Item found at position " << loc << endl;
	else
		cout << "Item not in the list" << endl;
	auto t8 = std::chrono::high_resolution_clock::now(); //stop the timer
	auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(t8 - t7).count();
	cout << duration2 << " microseconds elapsed" << endl;
	system("pause");
	return 0;

	
	system("Pause");
	return 0;
}

void printListInfo(arrayListType<int>& listInfo)
{
	cout << "List: ";
	listInfo.print();
	cout << "List Size: " << listInfo.listSize() << endl;
}