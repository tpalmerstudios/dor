CXX		=	g++
CXXFLAGS=	-Wall -std=c++17 -g -I /home/user/networkProjects/libs
OBJECTS	=	src/IDtoPerson.o src/dor.o src/validation.o src/deletePerson.o src/editPerson.o src/newPerson.o src/selectPerson.o src/savePerson.o src/Person.o src/searchPerson.o 
CLASSES =	libs/Person.h libs/dorSettings.h libs/Terminal.h

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@
.cpp:
	$(CXX) $(CXXFLAGS) $@.cpp -o $@

dor: $(OBJECTS) $(CLASSES) 
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

docs: $(OBJECTS) $(CLASSES)
	doxygen Doxyfile

clean:
	-rm src/*.o dor
	-rm -r docs/*

temp:
	-rm src/*.o

install:
	@echo Project does not support installation
	@echo Read Readme!

