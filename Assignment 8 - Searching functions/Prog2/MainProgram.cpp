
//Data:  7 12 18 20 23 27 30 32 38 45 66 68 72 85 -999

/*Modify the driver program that tests the
performance difference of the two search algorithms in orderedArrayListType.h
Fill the array(s) with random values at least 100000 and test searching for a random value
and also for searching for the last value in the array.  
Print out the results of your tests.

Sequential search
 int binarySearch(const elemType& item) const;

Recursive sequential search
 int recursiveBinarySearch(const elemType& item) const;
	

	
*/

#include <iostream>
#include <chrono>
#include "orderedArrayListType.h"
#include <time.h>       /* time */
 
using namespace std;

void printListInfo(orderedArrayListType<int>& listInfo);

int main()
{
	srand(time(NULL));
	orderedArrayListType<int> intList(1200);

	int num = 0;
	int loc;
	int randNum;
	int lastNum;

	/*
	cout << "Enter positive integers, in the ascending order,"
         <<  "ending with -999" << endl;
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
		// filling the list with random, increasing integers
		randNum = rand() % 5 + 1;
			num = num + randNum;
			intList.insert(num);
	}
	lastNum = num;

	/*
	cout << "The list you entered is: " << endl;
	printListInfo(intList);

	*/
	
	cout << "The list will not be printed due to it's length" << endl;
	cout << "The list's last value is " << lastNum << endl;
	cout << "Enter search item: ";
	cin >> num;
	cout << endl;


	

	auto t1 = std::chrono::high_resolution_clock::now(); //start the timer
	cout << "Binary Search test" << endl;
	loc = intList.binarySearch(num);
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
	cout << "Recursive Binary Search test" << endl;
	loc = intList.recursiveBinarySearch(num);
	if (loc != -1)
		cout << "Item found at position " << loc << endl;
	else
		cout << "Item not in the list" << endl;
	auto t4 = std::chrono::high_resolution_clock::now(); //stop the timer
	auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
	cout << duration2 << " microseconds elapsed" << endl;

	
	//searching for the last value
	auto t5 = std::chrono::high_resolution_clock::now(); //start the timer
	cout << "Binary Search test - last value" << endl;
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
	cout << "Recursive Binary Search test - last value" << endl;
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
}

void printListInfo(orderedArrayListType<int>& listInfo)
{
	cout << "List: ";
	listInfo.print();

	cout << "List Size: " << listInfo.listSize() << endl;
	cout << "Max List Size: " << listInfo.maxListSize() << endl;

}