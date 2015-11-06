CXX = g++
CXXFLAGS = -std=c++11

SEARCH_TARGET = PA3

LIB = min_tree.o min_heap.o

all: $(SEARCH_TARGET) 

$(SEARCH_TARGET): PA3.o $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f *.o && rm -f $(SEARCH_TARGET) 