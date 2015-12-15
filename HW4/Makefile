CXX = g++
CXXFLAGS = -std=c++11 -g 

SEARCH_TARGET = PA4

LIB = prim.o kruskal.o sollin.o

all: $(SEARCH_TARGET) 

$(SEARCH_TARGET): PA4.o $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f *.o && rm -f $(SEARCH_TARGET) 

