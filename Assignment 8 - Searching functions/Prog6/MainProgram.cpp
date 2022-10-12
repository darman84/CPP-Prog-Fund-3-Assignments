
//i.e. Data:  34 27 62 12 8 37 55 42 11 88 27 -999
/*
Demonstrate the performance of function removeOrd that removes an item from an array - based
ordered list.The item to be removed is passed as a parameter to this function.
After removing the item, the resulting list must be ordered with no empty
array positions between the elements. Test the function's performance as it removes all elements one at a time.

void removeOrd(const elemType&);

Write your observations/conclusions to cout(use random value filled large arrays for your tests)
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


	int num;



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
		intList.insertOrd(n); //store the generated number in the array
	}


	cout << "The list will not be printed due to it's size" << endl;



	cout << endl;

	auto t1 = std::chrono::high_resolution_clock::now(); //start the timer
	intList.removeOrd(50);
	intList.removeOrd(60);
	intList.removeOrd(100);
	intList.removeOrd(300);
	intList.removeOrd(400);
	intList.removeOrd(900);
	intList.removeOrd(950);
	intList.removeOrd(980);
	auto t2 = std::chrono::high_resolution_clock::now(); //stop the timer
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	cout.precision(17);
	cout << duration << " microseconds elapsed while deleting nums" << endl;



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