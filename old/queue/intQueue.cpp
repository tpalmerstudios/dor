#include <iostream>
#include "intQueue.h"
using namespace std;

intQueue::intQueue(int size)
{
		queueArray = new int [size];
		queueSize = size;
		front = -1;
		rear = -1;
		numItems = 0;
}

intQueue::intQueue(const intQueue &obj)
{
		queueArray = new int [obj.queueSize];

		queueSize = obj.queueSize;
		front = obj.front;
		rear = obj.rear;
		numItems = obj.numItems;

		for (int count = 0; count < obj.queueSize; count ++)
				queueArray [count] = obj.queueArray [count];
}

intQueue::~intQueue()
{
		delete [] queueArray;
}

void intQueue::enqueue(int num)
{
		if (isFull())
				cout << "The queue is full.\n";
		else
		{
				rear = (rear + 1) % queueSize;
				queueArray [rear] = num;
				numItems ++;
		}
}

void intQueue::dequeue(int &num)
{
		if (isEmpty())
				cout << "The queue is empty.\n";
		else
		{
				front = (front + 1) % queueSize;
				num = queueArray [front];
				numItems --;
		}
}

bool intQueue::isEmpty() const
{
		bool status;

		if (numItems)
				status = false;
		else
				status = true;
		return status;
}

bool intQueue::isFull() const
{
		bool status;

		if (numItems < queueSize)
				status = false;
		else
				status = true;

		return status;
}

void intQueue::clear ()
{
		front = queueSize - 1;
		rear = queueSize -1;
		numItems = 0;
}

