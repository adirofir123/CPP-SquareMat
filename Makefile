# adirofir123@gmail.com

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRC = SquareMat.cpp main.cpp
TARGET = Main

Main: $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

test: tests/test.cpp SquareMat.cpp
	$(CXX) $(CXXFLAGS) -o test tests/test.cpp SquareMat.cpp

valgrind: Main
	valgrind --leak-check=full ./Main

clean:
	rm -f Main test *.o
