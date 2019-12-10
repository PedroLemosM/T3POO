#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>

using namespace std;
//				0    	1      2        3
enum Posicoes {WATER, BOAT, WATER_H, BOAT_H};

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
	double getScore(int** OutroTable);
	bool addBarco(int xi, int yi, int xf ,int yf);
	bool achaConflito(int xi, int yi, int xf ,int yf);
	//bool addBarcoFULL(int, int, Direcoes, Barcos);
	
private:
	int rows, cols;
	int** table;
	double scoreAtual;
	
};
#endif