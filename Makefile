all:
	g++ -shared sorting.hpp sorting.cpp -o build/sorting.dll
	g++ -g main.cpp build/sorting.dll -o build/sorting.exe