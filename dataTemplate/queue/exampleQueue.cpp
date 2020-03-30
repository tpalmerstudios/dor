#include <iostream>
#include "intQueue.h"
using namespace std;

int main ()
{
		int queueSize;
		int input;
		cout << "Enter max size: ";
		cin >> queueSize;

		intQueue newQueue (queueSize);
		
		cout << "Enqueuing " << queueSize << " items...\n";
		for (int x = 0; x < queueSize; x ++)
		{
				cout << "Enter a number please: ";
				cin >> input;
				newQueue.enqueue (input);
		}
		cout << "Attempting to enqueue again...\n";
		newQueue.enqueue (queueSize);

		cout << "The values in the queue are:\n";
		while (!newQueue.isEmpty ())
		{
				int value;
				newQueue.dequeue (value);
				cout << value << endl;
		}
		return 0;
}
