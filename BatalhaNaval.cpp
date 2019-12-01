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
void BatalhaNaval::setHighScore(double score){}
double BatalhaNaval::getHighScore(){}