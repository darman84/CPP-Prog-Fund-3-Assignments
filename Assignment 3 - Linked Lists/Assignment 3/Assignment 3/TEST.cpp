//Name: Zachary Williams
//Class: 2019 Spring - COSC 2336.S70
//Project #: Assignment 3
//Revision: 1.0.0
//Date: 9/26/19
//Description: The purpose of this assignment is to create two functions that allow you to delete the smallest info from a linked list, 
//and delete all occurrences of info from a linked list, the implementation is template based so you may use any type of data

//This program tests various operation of a linked list
//34 62 21 90 66 53 88 24 10 -999 

#include <iostream>
#include "unorderedLinkedList.h"

using namespace std;

int main()
{

	
	unorderedLinkedList<int> list1, list2;          //Line 1
	int num;                                        //Line 2

	cout << "Line 3: Enter integers ending "
		<< "with -999" << endl;                    //Line 3
	cin >> num;                                     //Line 4

	while (num != -999)                             //Line 5
	{
		list1.insertLast(num);                      //Line 6
		cin >> num;                                 //Line 7
	}

	
	cout << endl;                                   //Line 8

	cout << "Line 9: list1: ";                      //Line 9
	list1.print();                                  //Line 10
	cout << endl;                                   //Line 11
	cout << "Line 12: Length of list1: "
		<< list1.length() << endl;                 //Line 12

	list2 = list1;	   //test the assignment operator Line 13
	
	cout << "Line 16: list2: ";                     //Line 14
	list2.print();                                  //Line 15
	cout << endl;                                   //Line 16
	cout << "Line 17: Length of list2: "
		<< list2.length() << endl;                 //Line 17

	cout << "Line 18: Enter the number to be "
		<< "deleted: ";                            //Line 18
	cin >> num;                                     //Line 19
	cout << endl;                                   //Line 20

	list2.deleteNode(num);                          //Line 21

	cout << "Line 22: After deleting " << num
		<< " list2: " << endl;                     //Line 22
	list2.print();                                  //Line 23
	cout << endl;                                   //Line 24
	
	cout << "Line 25: Length of list2: "
		<< list2.length() << endl;                 //Line 25

	cout << endl << "Line 26: Output list1 "
		<< "using an iterator" << endl;            //LIne 26

	linkedListIterator<int> it;                     //Line 27

	for (it = list1.begin(); it != list1.end();
		++it)                  //Line 28
		cout << *it << " ";                         //Line 29
	cout << endl;                                   //Line 30

	list1.deleteSmallestInfo();
	cout <<endl << "After deleting the smallest piece of info in list1 " << endl;
	list1.print();

	cout << endl << "Enter the piece of data that you would like to have deleted from the entire list " << endl;
	cin >> num;
	list1.deleteSelectedInfo(num);
	list1.print();

	system("pause");
	return 0;
}



