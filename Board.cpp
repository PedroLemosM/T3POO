#include "Board.h"

	Board::Board(int rows,int cols):rows(rows),cols(cols){
		table=new int*[rows];
		for (int i = 0; i < rows; ++i)
			table[i]=new int[cols];
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				table[i][j]=Water;
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
				if(table[i][j]==Boat)
					return false;
			}
		}
		return true;
	}
	int Board::getrows(){
		return rows;
	}
	int Board::getCols(){
		return cols;
	}
	bool Board::validPos(int row, int col){
		if(table[row][col]==Boat||table[row][col]==Water)
			return true;
		return false;
	}
	void Board::hitPos(int row, int col){
		if(table[row][col]==Water)
			table[row][col]=WaterH;
		else
			table[row][col]=BoatH;
	}