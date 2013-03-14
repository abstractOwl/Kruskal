# Makefile for CS130a PA3
PACKAGE	=	Kruskal

all:
	g++ -std=c++0x src/*.cpp -o prog3

clean:
	rm prog3

run:
	./prog3 < ~cs130a/PA3/testcase
