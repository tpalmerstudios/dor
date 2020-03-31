CXX = g++
CC = gcc
PWD = /home/user/networkProjects


all:
	cd $(PWD)/basicMath/; \
	$(CC) tempConversion.c -o tempConversion; \
	$(CXX) circle.cpp -o circle; \
	cd rectangle; \
	$(CXX) getRect.cpp Rectangle.cpp -o getRect; \
	cd ../../dataTemplate/; \
	$(CXX) example.cpp -o example; \
	$(CXX) people.cpp -o people; \
	$(CXX) employee.cpp -o employee; \
	cd queue/; \
	$(CXX) exampleQueue.cpp intQueue.cpp -o exampleQueue;

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
