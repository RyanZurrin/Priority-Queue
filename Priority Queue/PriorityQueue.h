#pragma once
#include <iostream>
#include "HeapType.h"

template<class ItemType>
class PriorityQueue
{
	int length;
	HeapType<ItemType> items;
	int maxItems;
public:
	/// <summary>
	/// constructs a PriorityQueue object with a the maximum number of items set.
	/// </summary>
	/// <param name="max"></param>
	PriorityQueue(int max);

	/// <summary>
	/// empties the PQ setting the length to 0.
	/// </summary>
	void MakeEmpty();

	/// <summary>
	/// checks if the PQ is empty.
	/// </summary>
	/// <returns>ture if PQ is empty else false</returns>
	bool IsEmpty() const;

	/// <summary>
	/// checks if the PQ is full.
	/// </summary>
	/// <returns>true if the PQ is full else false</returns>
	bool IsFull() const;

	/// <summary>
	/// add a new item to the PQ.
	/// </summary>
	/// <param name="newItem"></param>
	void Enqueue(ItemType newItem);

	/// <summary>
	/// removes the highest priority item from the PQ.
	/// </summary>
	/// <param name="item"></param>
	void Dequeue(ItemType& item);

	int getLength() const;


	/// <summary>
	/// dispaly the priority queue
	/// </summary>
	void ShowPQ();

	/// destructor
	~PriorityQueue();


};

template<class ItemType>
inline PriorityQueue<ItemType>::PriorityQueue(int max)
{
	this->maxItems = max;
	this->items.elements = new ItemType[max];
	this->length = 0;
}

template<class ItemType>
inline void PriorityQueue<ItemType>::MakeEmpty()
{
	length = 0;
}

template<class ItemType>
inline bool PriorityQueue<ItemType>::IsEmpty() const
{
	return length == 0;
}

template<class ItemType>
inline bool PriorityQueue<ItemType>::IsFull() const
{
	return length >= maxItems;
}

template<class ItemType>
inline void PriorityQueue<ItemType>::Enqueue(ItemType newItem)
{
	if (length == maxItems)
	{
		std::cout << "the priority queue is full" << std::endl;
	}
	else {
		length++;
		items.elements[length - 1] = newItem;
		items.swim(0, length - 1);
	}
}

template<class ItemType>
inline void PriorityQueue<ItemType>::Dequeue(ItemType& item)
{
	if (length == 0)
	{
		std::cout << "the priority queue is empty" << std::endl;
	}
	else {
		item = items.elements[0];
		items.elements[0] = items.elements[length - 1];
		length--;
		items.sink(0, length - 1);
	}
}

template<class ItemType>
inline int PriorityQueue<ItemType>::getLength() const
{
	return length;
}

template<class ItemType>
inline void PriorityQueue<ItemType>::ShowPQ()
{
	for (size_t i = 0; i < length - 1; i++)
	{
		std::cout << items.elements[i] << " ";
	}
	std::cout << items.elements[length -1] << std::endl;
}

template<class ItemType>
inline PriorityQueue<ItemType>::~PriorityQueue()
{
	delete[] items.elements;
}
