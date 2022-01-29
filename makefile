all: quicksort

quicksort: Lee_Christopher_QuickSort.cpp
	g++ -O2 -std=c++11 -lm -Wall -Wpedantic -o quicksort Lee_Christopher_QuickSort.cpp
