all: main

main: main.cpp scheduling_algorithms.cpp
	g++ -o main main.cpp scheduling_algorithms.cpp