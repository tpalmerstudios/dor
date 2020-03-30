#include <iostream>
#include <string>
#include "dataStructs.h"
using namespace std;

const int QUEUE_SIZE = 7;

int main ()
{
		string name;
		int age;
		Queue<string> names (QUEUE_SIZE);
		Queue<int> ages (QUEUE_SIZE);

		for (int i = 0; i < QUEUE_SIZE; i ++)
		{
				cout << "Enter a name: ";
				getline (cin, name);
				cout << "Enter birth year: ";
				cin >> age;
				names.enqueue (name);
				ages.enqueue (age);
		}

		cout << "\nHere are the names and years:\n";
		for (int i = 0; i < QUEUE_SIZE; i ++)
		{
				names.dequeue (name);
				ages.dequeue (age);
				cout << name << "\t\t" << age << endl;
		}
		return 0;
}

