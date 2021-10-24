#pragma once
#include <algorithm>

template<class ItemType>
void HeapSort(ItemType values[], int numValues)
{
	int index;
	for (index = numValues / 2 - 1; index >= 0; index--)
	{
		sink(values, index, numValues);
	}
	for (index = numValues - 1; index >= 1; index--)
	{
		std::swap(values[0], values[index]);
		sink(values, 0, index - 1);

	}
}
template<class ItemType>
void sink(ItemType values[], int index, int last) 
{
	int maxChild;
	int rightChild;
	int leftChild;
	leftChild = values[index] * 2 + 1;
	rightChild = values[index] * 2 + 2;

	if (leftChild <= last)
	{
		if (leftChild == last)
		{
			maxChild = leftChild;
		}
		else {
			if (values[leftChild] <= values[rightChild])
			{
				maxChild = rightChild;
			}
			else {
				maxChild = leftChild;
			}
		}
		if (values[index] < values[maxChild])
		{
			std::swap(values[index], values[maxChild]);
			sink(values, maxChild, last);
		}
	}
}