# # Path: Makefile
# g++ input.cpp -o output -std=c++11

input: src/input.cpp
	g++ src/input.cpp -o input -std=c++11