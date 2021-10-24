#include "PriorityQueue.h"


int main()
{
	int removed;
	PriorityQueue<int> tq = PriorityQueue<int>(15);
	tq.Enqueue(5);
	tq.Enqueue(11);
	tq.Enqueue(3);
	tq.Enqueue(15);
	tq.Enqueue(1);
	tq.Enqueue(7);
	tq.Enqueue(6);
	tq.Enqueue(12);
	tq.Enqueue(19);
	tq.Enqueue(9);
	tq.Enqueue(10);
	tq.Enqueue(16);
	std::cout << "length: " << tq.getLength() << std::endl;
	tq.ShowPQ();
	tq.Dequeue(removed);
	std::cout << "dequeued: " << removed << std::endl;
	tq.ShowPQ();
	tq.Dequeue(removed);
	std::cout << "dequeued: " << removed << std::endl;
	tq.ShowPQ();
	tq.Dequeue(removed);
	std::cout << "dequeued: " << removed << std::endl;
	tq.ShowPQ();
	tq.Dequeue(removed);
	std::cout << "dequeued: " << removed << std::endl;
	tq.ShowPQ();
	tq.Dequeue(removed);
	std::cout << "dequeued: " << removed << std::endl;
	tq.ShowPQ();
	tq.Dequeue(removed);
	std::cout << "dequeued: " << removed << std::endl;
	tq.ShowPQ();
	tq.Dequeue(removed);
	std::cout << "dequeued: " << removed << std::endl;
	tq.ShowPQ();
	tq.Dequeue(removed);
	std::cout << "dequeued: " << removed << std::endl;
	tq.ShowPQ();
	std::cout << "length: " << tq.getLength() << std::endl;

	return EXIT_SUCCESS;
}