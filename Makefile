all : pisqworky clear

CC = g++ -std=c++1y

pisqworky.o: pisqworky.cpp
	$(CC) $^ -c

game.o: game.cpp
	$(CC) $^ -c

pisqworky: pisqworky.o game.o
	$(CC) pisqworky.o game.o -o $@

clear: 
	rm *.o
	