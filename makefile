a6: assignment6.o
	g++ -o a6 assignment6.o

assignment6.o: assignment6.cpp Graph.h GraphFunctionality.h GraphInterface.h
	g++ -c assignment6.cpp -std=c++11