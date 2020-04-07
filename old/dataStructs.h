#ifndef DATASTRUCTS_H
#define DATASTRUCTS_H
#include <iostream>
using namespace std;

template <class queueStruct>
class Queue
{
private:
		queueStruct *queueArray;
		int queueSize;
		int first;
		int last;
		int numItems;
public:
		Queue (int);			// Constructor
		Queue (const Queue &);	// Copy Constructor
		~Queue ();				// Destructor

		void enqueue (queueStruct);		// Add item to queue
		void dequeue (queueStruct &);	// Remove item
		bool isEmpty () const;			// Check if empty
		bool isFull () const;			// Check if full
		void clear ();					// Empty the queue
};

/*******************************************************
  * Class constructor. Initializes the right variables *
  *****************************************************/
template <class queueStruct>
Queue<queueStruct>::Queue (int size)
{
		queueArray = new queueStruct [size];
		queueSize = size;
		first = -1;
		last = -1;
		numItems = 0;
}

/**********************************************************
  * Class copy constructor. Copies variables to new class *
  ********************************************************/
template <class queueStruct>
Queue<queueStruct>::Queue (const Queue &obj)
{
		queueArray = new queueStruct(obj.queueSize);

		queueSize = obj.queueSize;
		first = obj.first;
		last = obj.last;
		numItems = obj.numItems;

		for (int count = 0; count < obj.queueSize; count ++)
				queueArray [count] = obj.queueArray [count];
}

/***************************************
  * Class destructor. Destroys a class *
  *************************************/
template <class queueStruct>
Queue<queueStruct>::~Queue ()
{
		delete [] queueArray;
}
/**********************************************
  * Adds an item to the end of the queue
  ********************************************/
template <class queueStruct>
void Queue<queueStruct>::enqueue (queueStruct item)
{
		if (isFull ())
				cout << "The queue is full.\n";
		else
		{
				last = (last + 1) % queueSize; // Last+=1 mod incase it goes over?
				queueArray [last] = item;
				numItems ++;
		}
}

template <class queueStruct>
void Queue<queueStruct>::dequeue (queueStruct &item)
{
		if (isEmpty ())
				cout << "The queue is empty.\n";
		else
		{
				first = (first + 1) % queueSize;
				item = queueArray [first];
				numItems --;
		}
}

template <class queueStruct>
bool Queue<queueStruct>::isEmpty () const
{
		bool status;

		if (numItems)
				status = false;
		else
				status = true;
		return status;
}

template <class queueStruct>
bool Queue<queueStruct>::isFull () const
{
		bool status;

		if (numItems < queueSize)
				status = false;
		else
				status = true;
		return status;
}

template <class queueStruct>
void Queue<queueStruct>::clear ()
{
		first = queueSize - 1;
		last = queueSize - 1;
		numItems = 0;
}
#endif

