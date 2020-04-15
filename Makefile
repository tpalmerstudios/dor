CXX		=	g++
CXXFLAGS=	-Wall -I /home/user/networkProjects/libs
OBJECTS	=	src/IDtoPerson.o src/dor.o src/validation.o src/deletePerson.o src/editPerson.o src/newPerson.o src/selectPerson.o src/savePerson.o src/Person.o src/searchPerson.o 
CLASSES =	libs/Person.h libs/dorSettings.h libs/Terminal.h

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@
.cpp:
	$(CXX) $(CXXFLAGS) $@.cpp -o $@

dor: $(OBJECTS) $(CLASSES)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@
	doxygen Doxyfile

clean:
	-rm src/*.o src/dor

temp:
	-rm src/*.o

install:
	@echo Project does not support installation
	@echo Read Readme!

