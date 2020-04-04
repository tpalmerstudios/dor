CXX		=	g++
CC		=	gcc
CXXFLAGS=	-Wall
CFLAGS	=	-Wall
MATH	=	basicMath/
DATA	=	dataTemplate/
CXXSOURCE	=	$(MATH)circle.cpp $(DATA)employee.cpp $(DATA)people.cpp $(DATA)example.cpp
CSOURCE	=	$(MATH)tempConversion.c

basic: src/main.o src/savePerson.o src/Person.o
	$(CXX) src/main.o src/savePerson.o src/Person.o -o src/$@

#basic: main.cpp savePerson.cpp Person.cpp
#		$(CXX) $(CXXFLAGS) $? -o $@

clean:
	-rm *.o basic

temporary:
	-rm *.o

install:
	@echo Project does not support installation
	@echo Read Readme!

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<
.cpp:
	$(CXX) $(CXXFLAGS) $@.cpp -o $@
	
.c.o:
	$(CC) $(CFLAGS) -c $<

.c:
	$(CC) $(CFLAGS) $@.cpp -o $@

