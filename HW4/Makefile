CXX = g++
CXXFLAGS = -std=c++11

SEARCH_TARGET = PA4

LIB = prim.o

all: $(SEARCH_TARGET) 

$(SEARCH_TARGET): PA4.o $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f *.o && rm -f $(SEARCH_TARGET) 

