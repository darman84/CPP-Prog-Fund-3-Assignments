#ifndef H_OrderedListType
#define H_OrderedListType

#include <iostream>
#include "arrayListType.h"

using namespace std;

template<class elemType>
class orderedArrayListType: public arrayListType<elemType>
{
public:
	void insertOrd(const elemType&);
	
	int binarySearch(const elemType& item) const;

	int binSearchEx(const elemType& item);

	int binSeqSearch15(const elemType& item);

	orderedArrayListType(int size = 100);

	int seqSearch15(const elemType& item, int first, int last);

	int noOfComparisons() const;
	void initializeNoOfComparisons();

private:
	int comparisons;
};

template <class elemType>
void orderedArrayListType<elemType>::insertOrd(const elemType& item)
{
    int first = 0;
    int last = this->length - 1;
    int mid=0;

    bool found = false;

    if (this->length == 0)   //the list is empty
    {
		this->list[0] = item;
		this->length++;
    }
    else if (this->length == this->maxSize)
        cerr << "Cannot insert into a full list." << endl;
    else
    {
        while (first <= last && !found)
        {
            mid = (first + last) / 2;

            if (this->list[mid] == item)
                found = true;
            else if (this->list[mid] > item)
                last = mid - 1;
            else
                first = mid + 1;
        }//end while

        if (found)
            cerr << "The insert item is already in the list. "
                 << "Duplicates are not allowed." << endl;
        else
        {
            if (this->list[mid] < item)
                mid++;

            this->insertAt(mid, item);
        }
    }
}//end insertOrd

template<class elemType> int orderedArrayListType<elemType>::binarySearch
                                           (const elemType& item) const
{
    int first = 0;
    int last = this->length - 1;
    int mid;

    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;

        if (this->list[mid] == item)
            found = true;
        else if (this->list[mid] > item)
            last = mid - 1;
        else
            first = mid + 1;
    }

    if (found) 
        return mid;
    else
        return -1;
}//end binarySearch

template<class elemType>
int orderedArrayListType<elemType>::binSearchEx(const elemType& item)
{
	int first = 0;
	int last = this->length - 1;
	int mid;

	bool found = false;

	while (first <= last && !found)
	{
		mid = (first + last) / 2;

		comparisons++;

		if (this->list[mid] == item)
			found = true;
		else
		{
			comparisons++;

			if (this->list[mid] > item)
				last = mid - 1;
			else
				first = mid + 1;
		}
	}

	if (found)
		return mid;
	else 
		return -1;
}

template<class elemType>
int orderedArrayListType<elemType>::binSeqSearch15(const elemType& item)
{
	int first = 0;
	int last = this->length - 1;
	int mid;

	bool found = false;

	while (last - first > 15 && !found)
	{
		mid = (first + last) / 2;

		comparisons++;

		if (this->list[mid] == item)
			found = true;
		else
		{
			comparisons++;

			if (this->list[mid] > item)
				last = mid - 1;
			else
				first = mid + 1;
		}
	}

	if (found)
		return mid;
	else
		return seqSearch15(item,first,last);
}


template<class elemType>
int orderedArrayListType<elemType>::seqSearch15(const elemType& item,
												int first, int last)
{
	bool found = false;
    int loc;

	for (loc = first; loc <= last; loc++)
	{
		comparisons++;

		if (this->list[loc] >= item)
		{
			found = true;
			break;
		}
	}

	if (found)
		if (this->list[loc] == item)
		{
			comparisons++;
			return loc;
		}
		else
			return -1;
	else
		return -1;
}

template<class elemType>
int orderedArrayListType<elemType>::noOfComparisons() const
{
	return comparisons;
}

template<class elemType>
void orderedArrayListType<elemType>::initializeNoOfComparisons()
{
	comparisons = 0;
}


template<class elemType>
orderedArrayListType<elemType>::orderedArrayListType(int size)
   : arrayListType<elemType>(size)
{
}

#endif