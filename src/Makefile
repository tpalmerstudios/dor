CXX		=	g++
CXXFLAGS=	-Wall

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

basic: main.cpp Person.cpp savePerson.cpp
	$(CXX) $(CXXFLAGS) $? -o $@

clean:
	-rm *.o *~ basic
