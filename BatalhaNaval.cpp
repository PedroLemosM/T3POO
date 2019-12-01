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
void BatalhaNaval::setHighScore(double score){
	ifstream out;
	out.open("Maior_Score.txt");
	double scoreCorrente = Board::getScoreAtual();
	if(scoreCorrente > highScore)
		out << scoreCorrente;

	out.close();
}

double BatalhaNaval::getHighScore(){
	ifstream in;
	in.open("Maior_Score.txt");
	in >> highScore;
	in.close();

	return highScore;
}