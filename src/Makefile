CXX		=	g++
CXXFLAGS=	-Wall
OBJECTS	=	validation.o deletePerson.o editPerson.o newPerson.o selectPerson.o main.o savePerson.o Person.o searchPerson.o 

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<
.cpp:
	$(CXX) $(CXXFLAGS) $@.cpp -o $@

basic: $(OBJECTS) Person.h
	$(CXX) $(OBJECTS) -o $@

#basic: main.cpp savePerson.cpp Person.cpp
#		$(CXX) $(CXXFLAGS) $? -o $@

clean:
	-rm *.o basic

temporary:
	-rm *.o

install:
	@echo Project does not support installation
	@echo Read Readme!

