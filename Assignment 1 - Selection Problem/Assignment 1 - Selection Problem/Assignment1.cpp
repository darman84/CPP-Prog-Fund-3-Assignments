//Name: Zachary Williams
//Class: 2019 S70 - COSC 2336.S70
//Project #: Assignment 1
//Revision: 1.0.0
//Date: 9/5/19
//Description: Solves the selection problem via bubble sort using n=9, n=20, n=50 for data
//Performance data is logged in PerformanceFinal.xml

#include <iterator>
#include <iostream>


using namespace std;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

int Largest(int nums [], int n )
{
	int k = n / 2; // the kth largest
	int kthLargest = 0; // kth Largest number in the array

	bubbleSort(nums, n);
	kthLargest = nums[k-1];

	int num = 0;

	cout << "Sorted Array:" << endl;
	for (int parse = 0; parse < n; parse++)
	{
		num = nums[parse];
		cout << num << " ";

	}
	cout << endl;

	return kthLargest;
}

int main()
{
	int numKthLargest;
	int n;
	int k;
	
	n = 9;
	k = n / 2;
	static int testOne [] = {0,1,12,95,45,25,1000,192,9};
	numKthLargest = Largest(testOne,n);
	cout << "The "<< k << "th largest number is: " << numKthLargest << endl << endl;

	
	n = 20;
	k = n / 2;
	static int testTwo[] = { 9538, 4278, 1367, 128, 8313, 5801, 5600, 8510, 5167, 654, 2397, 4290, 9531, 3020, 1025, 3290, 3147, 3819, 9947, 2130 };
	numKthLargest = Largest(testTwo, n);
	cout << "The " << k << "th largest number is: " << numKthLargest << endl << endl;
	
	n = 50;
	k = n / 2;
	static int testThree[] = { 9295, 5191, 1577, 8935, 7691, 8542, 2584, 4227, 2888, 9910, 7023, 6676, 4209, 815, 1769, 4938, 2943, 8298, 5446, 6119, 2715, 8050, 1121, 9565, 8040, 6637, 1668, 3738, 9892, 107, 9131, 4152, 147, 2767, 8625, 2677, 8089, 792, 7928, 8098, 341, 1187, 601, 8507, 1550, 539, 4176, 4260, 2666, 7433 };
	numKthLargest = Largest(testThree, n);
	cout << "The " << k << "th largest number is: " << numKthLargest << endl << endl;
	
	return 0;
}