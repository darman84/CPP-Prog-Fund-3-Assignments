//Name: Zachary Williams
//Class: 2019 S70 - COSC 2336.S70
//Project #: Assignment 7
//Revision: 1.0.0
//Date: 11/24/19
//Description: This project makes minor annotations to the prim algorithm


#include <iostream>
#include "minimumSpanTreeType.h"

using namespace std;
 
int main()
{
	msTreeType spanTree(70);

	cout << "******* Using Prim2 Algorithm *********" << endl;

	spanTree.createSpanningGraph();
	spanTree.prim2(0); 
	spanTree.printTreeAndWeight();

	system("pause");
	return 0;
}