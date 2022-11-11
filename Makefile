
darkzone: DarkZone.o Queue.o Stack.o
	g++ -o darkzone DarkZone.o Queue.o Stack.o

DarkZone.o: DarkZone.cpp
	g++ -c -std=c++11 DarkZone.cpp

Queue.o: Queue.cpp Queue.h
	g++ -c -std=c++11 Queue.cpp

Stack.o: Stack.cpp Stack.h
	g++ -c -std=c++11 Stack.cpp
