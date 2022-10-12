
//i.e Data:  34 27 62 12 8 37 55 42 11 88 27 -999
/* 
Modify this program to test the performance of the function insertOrd that inserts an item into an
array - based ordered list.

Write your observations/conclusions to cout ( use random value filled large arrays for your tests )
*/

#include <iostream>
#include "orderedArrayListType.h"
#include <chrono>

using namespace std;

void printListInfo(orderedArrayListType<int>& listInfo);

int main()
{
	orderedArrayListType<int> intList;

	int num;

	cout << "Enter numbers ending with -999" << endl;
	cin >> num;

	while(num != -999)
	{
		intList.insertOrd(num);
		cin>>num;
	}

	cout << "The number you entered in ascending order are: " << endl;
	printListInfo(intList);

	auto t1 = std::chrono::high_resolution_clock::now(); //start the timer
	intList.insertOrd(1);
	intList.insertOrd(19);
	intList.insertOrd(29);
	intList.insertOrd(49);
	intList.insertOrd(69);
	intList.insertOrd(79);
	intList.insertOrd(99);
	auto t2 = std::chrono::high_resolution_clock::now(); //stop the timer
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	cout.precision(17);
	cout << duration << " microseconds elapsed inserting nums" << endl;




	cout << "The list is: " << endl;
	printListInfo(intList);

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