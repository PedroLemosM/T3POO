main.o: main.cpp
	g++ -c main.cpp -o main.o

BatalhaNaval.o: BatalhaNaval.cpp BatalhaNaval.h
	g++ -c BatalhaNaval.cpp -o BatalhaNaval.o

Board.o: Board.cpp Board.h
	g++ -c Board.cpp -o Board.o

Menu.o: Menu.cpp Menu.h
	g++ -c Menu.cpp -o Menu.o

all: Board.o main.o BatalhaNaval.o Menu.o
	g++ main.o BatalhaNaval.o Board.o Menu.o -o jogo -lsfml-graphics -lsfml-window -lsfml-system