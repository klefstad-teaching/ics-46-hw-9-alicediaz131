CXX = g++
CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic
all: main ladder_main
main: src/dijkstras_main.cpp lib/dijkstras.o
	$(CXX) $(CXXFLAGS) src/dijkstras_main.cpp lib/dijkstras.o -o main
lib/dijkstras.o: src/dijkstras.cpp src/dijkstras.h
	$(CXX) -std=c++20 -c src/dijkstras.cpp -o lib/dijkstras.o
ladder_main: src/ladder_main.cpp lib/ladder.o
	$(CXX) $(CXXFLAGS) src/ladder_main.cpp lib/ladder.o -o ladder_main
lib/ladder.o: src/ladder.cpp src/ladder.h
	$(CXX) -std=c++20 -c src/ladder.cpp -o lib/ladder.o

clean:
	rm -f lib/*.o main