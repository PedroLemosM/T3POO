#ifndef BATALHANAVAL_H
#define BATALHANAVAL_H
#include <iostream>
#include <string>

#include "Board.h"

using namespace std;
class BatalhaNaval
{
public:
	BatalhaNaval(string player);
	~BatalhaNaval();
	void setPlayer(string player);
	string getlayer();
	bool finish();
	void setHighScore(double score);
	double getHighScore();

private:
	string player;
	double highScore;

};
#endif