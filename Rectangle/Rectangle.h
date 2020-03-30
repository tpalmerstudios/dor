#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
	private:
			double width;
			double length;
	public:
			// Negative width
			class negativeWidth
					{ };

			// Negative length
			class negativeLength
					{ };

			// Default constructor
			Rectangle ()
					{ width = 0.0; length = 0.0; }

			void setWidth (double);
			void setLength (double);

			double getWidth() const
					{ return width; }

			double getLength() const
					{ return length; }
			
			double getArea() const
					{ return width * length; }
};
#endif

