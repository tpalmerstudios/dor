#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
	private:
			double width, length;
	public:
			class negativeWidth
					{ };

			class negativeLength
					{ };

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

