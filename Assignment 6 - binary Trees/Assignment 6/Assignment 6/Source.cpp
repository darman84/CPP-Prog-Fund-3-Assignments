//Name: Zachary Williams
//Class: 2019 Fall - COSC 2336.S70
//Project #: Assignment 6
//Revision: 1.0.0
//Date: 11/10/19
//Description: Write a member function for IntBinaryTree class, that counts and returns the number of leaf nodes in the tree.  Demonstrate the function in a driver class.
//
//Note: Use the Node Counter Problem video as your guide to solve this problem.The IntBinaryTree is given in the more_examples zip file in chapter 6 folder.

#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

int main()
{
	IntBinaryTree myBinaryTree;


	
	myBinaryTree.insertNode(52);
	myBinaryTree.insertNode(24);
	myBinaryTree.insertNode(51);
	myBinaryTree.insertNode(12);
	myBinaryTree.insertNode(6662);

	cout << "Displaying the contents of the binary tree" << endl;
	myBinaryTree.displayInOrder();
	myBinaryTree.displayNumLeafs();
	



	system("pause");
	return 0;
}