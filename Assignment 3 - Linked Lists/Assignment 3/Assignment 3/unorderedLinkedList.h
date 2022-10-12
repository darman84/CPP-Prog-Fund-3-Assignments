//Name: Zachary Williams
//Class: 2019 Spring - COSC 2336.S70
//Project #: Assignment 3
//Revision: 1.0.0
//Date: 9/26/19
//Description: The purpose of this assignment is to create two functions that allow you to delete the smallest info from a linked list, 
//and delete all occurrences of info from a linked list, the implementation is template based so you may use any type of data

#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList  

#include "linkedList.h"
 
using namespace std;

template <class Type> 
class unorderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the 
      //               list, otherwise the value false is 
      //               returned.

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //               inserted at the beginning of the list,
      //               last points to the last node in the  
      //               list, and count is incremented by 1.

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem 
      //               is inserted at the end of the list,
      //               last points to the last node in the 
      //               list, and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing 
      //               deleteItem is deleted from the list.
      //               first points to the first node, last
      //               points to the last node of the updated 
      //               list, and count is decremented by 1.
	void deleteSmallestInfo();
	
	void deleteSelectedInfo(const Type& delInfo);
	

	
	
	
	private:
		using linkedListType<Type>::first;
		using linkedListType<Type>::last;
		using linkedListType<Type>::count;
		
};


template <class Type>
void unorderedLinkedList<Type>::deleteSmallestInfo()
{//Find and delete the node with the smallest info in the list. ( Delete only the first occurence and traverse the list only once. )
	nodeType<Type> *current; 
	nodeType<Type> *trailCurrent;     // used for pointing to node just before current

	nodeType<Type> *small;
	nodeType<Type> *trailSmall;

	trailSmall = first;

	if (first == NULL)
		cout << "Cannot delete from an empty list." << endl;
	else
		if (first->link == NULL)
		{
			first = NULL;
			delete last;
			last = NULL;
		}
		else
		{
			small = first;
			trailCurrent = first;
			current = first->link;

			while (current != NULL)
			{
				if (small->info > current->info)
				{
					trailSmall = trailCurrent;
					small = current;
				}

				trailCurrent = current;
				current = current->link;
			}

			if (small == first)
				first = first->link;
			else if (small != first)
			{
				trailSmall->link = small->link;

				if (small == last)
					last = trailSmall;
			}

			delete small;
			count--;
		}


}


template <class Type>
void unorderedLinkedList<Type>::deleteSelectedInfo(const Type& delInfo)
{	//Find and delete all occurrences of a given info from the list. ( Traverse the list only once. )
		// Start from head 
	struct nodeType<Type>** pp = &first;
	while (*pp) 
	{

		struct nodeType<Type>* entry = *pp;

		// If delInfo found, then put 
		// link at the address of pp 
		// delete entry. 
		if (entry->info == delInfo) {
			*pp = entry->link;
			delete (entry);
			count--;
		}

		// Else move to next 
		else
			pp = &(entry->link);
	}
}//end deleteSelectedInfo




template <class Type>
bool unorderedLinkedList<Type>::
                   search(const Type& searchItem) const
{
    nodeType<Type> *current; //pointer to traverse the list
    bool found = false;
    
    current = first; //set current to point to the first 
                     //node in the list

    while (current != nullptr && !found)    //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
                                     //the next node
    return found; 
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;    //store the new item in the node
    newNode->link = first;      //insert newNode before first
    first = newNode;            //make first point to the
                                //actual first node
    count++;                    //increment count

    if (last == nullptr)   //if the list was empty, newNode is also 
                        //the last node in the list
        last = newNode;
}//end insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;  //store the new item in the node
    newNode->link = nullptr;     //set the link field of newNode
                              //to nullptr

    if (first == nullptr)  //if the list is empty, newNode is 
                        //both the first and last node
    {
        first = newNode;
        last = newNode;
        count++;        //increment count
    }
    else    //the list is not empty, insert newNode after last
    {
        last->link = newNode; //insert newNode after last
        last = newNode; //make last point to the actual 
                        //last node in the list
        count++;        //increment count
    }
}//end insertLast


template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (first == nullptr)    //Case 1; the list is empty. 
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (first->info == deleteItem) //Case 2 
        {
            current = first;
            first = first->link;
            count--;
            if (first == nullptr)    //the list has only one node
                last = nullptr;
            delete current;
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = first;  //set trailCurrent to point
                                   //to the first node
            current = first->link; //set current to point to 
                                   //the second node

            while (current != nullptr && !found)
            {
                if (current->info != deleteItem) 
                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                count--;

                if (last == current)   //node to be deleted 
                                       //was the last node
                    last = trailCurrent; //update the value 
                                         //of last
                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode


#endif
