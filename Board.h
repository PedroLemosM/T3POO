#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>

#define BOAT 1
#define BOAT_H 3
#define WATER 0
#define WATER_H 2

using namespace std;
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
	bool addBarco(int row, int col);
	
private:
	int rows, cols;
	int** table;
	double scoreAtual;
	
};
#endif