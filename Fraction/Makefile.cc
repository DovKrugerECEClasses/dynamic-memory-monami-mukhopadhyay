DEBUG	:= -g

fraction: Fraction.o main.o
	g++ $(DEBUG) Fraction.o main.o -o fraction

Fraction.o: Fraction.h Fraction.cc
	g++ $(DEBUG) -c Fraction.cc # creates Fraction.o

main.o: main.cc Fraction.h
	g++ $(DEBUG) -c main.cc # creates main.o
