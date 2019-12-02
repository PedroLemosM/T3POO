main.o: main.cpp
	g++ -c main.cpp -o main.o

BatalhaNaval.o: BatalhaNaval.cpp BatalhaNaval.h
	g++ -c BatalhaNaval.cpp -o BatalhaNaval.o

Board.o: Board.cpp Board.h
	g++ -c Board.cpp -o Board.o

all: Board.o main.o BatalhaNaval.o
	g++ main.o BatalhaNaval.o Board.o -o jogo -lsfml-graphics -lsfml-window -lsfml-system