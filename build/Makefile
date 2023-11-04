CXX = g++
CXXFLAGS = -std=c++2a -g
NAMEGLAGS = -o

make:
	$(CXX) $(NAMEGLAGS) sistemas_recomendacion.o $(CXXFLAGS) ../src/*.cc ../src/Functions/*.cc -I .

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f sistemas_recomendacion *.o