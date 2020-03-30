#include <iostream>
#include "Rectangle.h"
using namespace std;

int main()
{
		double width;
		double length;

		Rectangle newRectangle;

		cout << "Enter the rectangle's width: ";
		cin >> width;
		cout << "Enter the rectangle's length: ";
		cin >> length;

		try
		{
				newRectangle.setWidth (width);
				newRectangle.setLength (length);
				cout << "The area of the rectangle is " << newRectangle.getArea () << endl;
		}
		catch (Rectangle::negativeWidth)
		{
				cout << "Error: A negative value was given for the rectangle's width.\n";
		}
		catch (Rectangle::negativeLength)
		{
				cout << "Error: A negative value was given for the rectangle's length.\n";
		}

		cout << "Program Complete.\n";
		return 0;
}

