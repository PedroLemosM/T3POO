#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>

#define Boat 1
#define BoatH 3
#define Water 0
#define WaterH 2

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
	double getScoreAtual;
private:
	int rows, cols;
	int** table;
	double scoreAtual;
	
};
#endif