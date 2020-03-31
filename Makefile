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
	$(CXX) exampleQueue.cpp intQueue.cpp -o exampleQueue; \
	cd ../../wordManips; \
	$(CC) charCount.c -o charCount; \
	$(CC) charCount2.c -o charCount2; \
	$(CC) digitCounter.c -o digitCounter; \
	$(CC) i2o.c -o i2o; \
	$(CC) lineCount.c -o lineCount; \
	$(CC) noBlank.c -o noBlank; \
	$(CC) visiEscapes.c -o visiEscapes; \
	$(CC) whitespace.c -o whitespace; \
	$(CC) wordCount.c -o wordCount; \
	$(CC) wordLengthGraph.c -o wordLengthGraph;

clean:
	-rm basicMath/tempConversion;
	-rm basicMath/circle;
	-rm basicMath/rectangle/getRect;
	-rm wordManips/charCount;
	-rm wordManips/charCount2;
	-rm wordManips/digitCounter;
	-rm wordManips/i2o;
	-rm wordManips/lineCount
	-rm wordManips/noBlank
	-rm wordManips/visiEscapes
	-rm wordManips/whitespace
	-rm wordManips/wordCount
	-rm wordManips/wordLengthGraph
	-rm dataTemplate/dataStructs
	-rm dataTemplate/example
	-rm dataTemplate/employee
	-rm dataTemplate/people
	-rm dataTemplate/queue/exampleQueue

