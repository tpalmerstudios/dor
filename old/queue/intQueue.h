#ifndef INTQUEUE_H
#define INTQUEUE_H

class intQueue
{
private:
		int *queueArray;	// Points to the queue array
		int queueSize;		// Queue size
		int front;			// Number of the front
		int rear;			// Number of the rear
		int numItems;		// Items in queue
public:
		// Constructor
		intQueue(int);
		// Copy constructor
		intQueue(const intQueue &);
		// Destructor
		~intQueue();
		// Queue operations
		void enqueue(int);
		void dequeue(int &);
		bool isEmpty() const;
		bool isFull() const;
		void clear();
};
#endif
