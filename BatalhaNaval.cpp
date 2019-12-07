#include "BatalhaNaval.h"

BatalhaNaval::BatalhaNaval(string player){
	this->player=player;
}

BatalhaNaval::~BatalhaNaval(){}

void BatalhaNaval::setPlayer(string player){
	this->player=player;
}

string BatalhaNaval::getlayer(){
	return player;
}

void BatalhaNaval::setHighScore(double scoreCorr){

	ofstream out("Maior_Score.txt");
	if(scoreCorr > highScore)
		out << scoreCorr;

	out.close();
}

double BatalhaNaval::getHighScore(){

	ifstream in("Maior_Score.txt");
	in >> highScore;
	in.close();

	return highScore;
}