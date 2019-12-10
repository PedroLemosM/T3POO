#ifndef BATALHANAVAL_H
#define BATALHANAVAL_H
#include <iostream>
#include <string>
#include <fstream>

#include "Board.h"

using namespace std;
class BatalhaNaval
{
public:
	BatalhaNaval(string player, int rows, int cols);
	~BatalhaNaval();
	void setPlayer(string player);
	string getlayer();
	bool finish();
	void setHighScore(double s);
	double getHighScore();
	bool comparaScore(double a, double b);

private:
	string player;
	double highScore;
	Board pBoard,bBoard;

};
#endif