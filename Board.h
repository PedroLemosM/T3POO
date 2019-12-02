#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>

using namespace std;
//				0    1       2          3
enum Posicoes {WATER, BOAT, WATER_H, BOAT_H};
//			      0          1      2
enum Direcoes {NEUTRO,VERTICAL, HORIZONTAL};
//			        2  3  4
enum Barcos {A = 1, B, C, D};

class Board
{
public:
	Board(int rows,int cols);
	~Board();
	bool checkVitoria();
	void setRows(int rows);
	int getrows();
	void setCols(int cols);
	int getCols();
	bool validPos(int row, int col);
	void hitPos(int row, int col);
	double getScoreAtual();
	bool addBarco(int, int);
	bool addBarcoFULL(int, int, Direcoes, Barcos);
	
private:
	int rows, cols;
	int** table;
	double scoreAtual;
	
};
#endif