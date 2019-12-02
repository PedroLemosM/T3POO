#include "Board.h"

	Board::Board(int rows,int cols):rows(rows),cols(cols){
		table=new int*[rows];
		for (int i = 0; i < rows; ++i)
			table[i]=new int[cols];
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				table[i][j]=WATER;
	}

	Board::~Board(){
		for(int i = 0; i < rows; ++i) 
        	delete[] table[i];
    	delete[] table;
	}

	bool Board::checkVitoria(){
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				cout<<table[i][j]<<endl;
				if(table[i][j]==BOAT)
					return false;
			}
		}
		scoreAtual = 100;
		return true;
	}
	int Board::getrows(){
		return rows;
	}
	int Board::getCols(){
		return cols;
	}
	bool Board::validPos(int row, int col){
		if(table[row][col]==BOAT||table[row][col]==WATER)
			return true;
		return false;
	}
	void Board::hitPos(int row, int col){
		if(table[row][col]==WATER){
			table[row][col]=WATER_H;
			scoreAtual = 50;
		}
		else{
			table[row][col]=BOAT_H;
			scoreAtual = 50;
		}
	}

	double Board::getScoreAtual() {
		return scoreAtual;
	}

	bool Board::addBarco(int row, int col) {
		if(table[row][col] == WATER){
			table[row][col] = BOAT;
			return true;
		}
		return false;
	}