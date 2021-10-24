#pragma once
/**
* author: Ryan Zurrin
* description: priority queue implimentation
*/
#include <algorithm>

template<class ItemType>
struct HeapType 
{
	void sink(int root, int bottom);
	void swim(int root, int bottom);
	ItemType* elements;
	int numElements;
};

template<class ItemType>
inline void HeapType<ItemType>::sink(int root, int bottom)
{
	int maxChild;
	int rightChild;
	int leftChild;
	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;

	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
		{
			maxChild = leftChild;
		}
		else {
			if (elements[leftChild] <= elements[rightChild])
			{
				maxChild = rightChild;
			}
			else {
				maxChild = leftChild;
			}
		}
		if (elements[root] < elements[maxChild])
		{
			std::swap(elements[root], elements[maxChild]);
			sink(maxChild, bottom);
		}
	}
}

template<class ItemType>
inline void HeapType<ItemType>::swim(int root, int bottom)
{
	int parent;
	if (bottom > root)
	{
		parent = (bottom - 1) / 2;
		if (elements[parent] < elements[bottom])
		{
			std::swap(elements[parent], elements[bottom]);
			swim(root, parent);
		}
	}
}
