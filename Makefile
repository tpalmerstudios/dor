CXX = g++
CC = gcc
PWD = /home/user/networkProjects


all:
	$(CC) $(PWD)/basicMath/tempConversion.c -o $(PWD)/basicMath/tempConversion
	$(CXX) $(PWD)/basicMath/circle.cpp -o $(PWD)/basicMath/circle
	$(CXX) $(PWD)/basicMath/rectangle/getRect.cpp $(PWD)/basicMath/rectangle/Rectangle.cpp -o $(PWD)/basicMath/rectangle/getRect
	cd ../../dataTemplate/
	$(CXX) example.cpp -o example
	cd employee/
	$(CXX) employee.cpp -o employee
	cd ../people/
	$(CXX) people.cpp -o people
	cd ../queue/
	$(CXX) exampleQueue.cpp intQueue.cpp -o exampleQueue

clean:
	-rm basicMath/tempConversion
	-rm basicMath/circle
	-rm rectangle/rectangle/getRect
	-rm wordManips/charCount
	-rm wordManips/charCount2
	-rm wordManips/digitCounter
	-rm wordManips/i2o
	-rm wordManips/lineCount
	-rm wordManips/noBlank
	-rm wordManips/visiEscapes
	-rm wordManips/whitespace
	-rm wordManips/wordCount
	-rm wordManips/wordLengthGraph
	-rm dataTemplate/dataStructs
	-rm dataTemplate/example
	-rm dataTemplate/employee/employee
	-rm dataTemplate/people/people
	-rm dataTemplate/queue/exampleQueue
