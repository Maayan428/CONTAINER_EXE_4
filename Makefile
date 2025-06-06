
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra

INCLUDES = -Iheaders -Itests

main: main.o
	$(CXX) $(CXXFLAGS) -o main main.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c main.cpp

test: tests/Test.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o test tests/Test.cpp
	./test

valgrind: test
	valgrind --leak-check=full --track-origins=yes ./test

clean:
	rm -f *.o main test