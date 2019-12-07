#include "Board.h"

	Board::Board(int rows,int cols):rows(rows),cols(cols){
		scoreAtual = 0;

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
		}
		else{
			table[row][col]=BOAT_H;
		}
	}


	bool Board::addBarco(int r, int c) {
		if(table[r][c] == WATER){
			table[r][c] = BOAT;
			return true;
		}
		return false;
	}

	/*bool Board::addBarcoFULL(int l, int c, Direcoes dir, Barcos bar) {
		bool flag = true;
		switch(bar){
			case A:
				return addBarco(l, c);
				break;
			case B:
				if(dir == VERTICAL)
					if((l + B - 1) < rows)
						for (int i = l; i < B; ++i){
							addBarco(i, c);
						}
					else if(abs(l - B + 1) < rows)
						for (int i = l; i > B; --i){
							addBarco(i, c);
						}
				else
					if((c + B - 1) < cols)
						for (int i = c; i < B; ++i){
							addBarco(l, i);
						}
					else if(abs(c - B + 1) < rows)
						for (int i = c; i > B; --i){
							addBarco(l, i);
						}


					for (int i = l; i < cols && i <= B; ++i){
						flag = addBarco(i, c);
						if(!flag)
							return flag;
					}
				break;
			case C:
				if(dir == VERTICAL)
					for (int i = c; i < rows && i <= C; ++i){
						flag = addBarco(i, c);
						if(!flag)
							return flag;
					}
				else
					for (int i = l; i < cols && i <= C; ++i){
						flag = addBarco(i, c);
						if(!flag)
							return flag;
					}
				break;
			case D:
				if(dir == VERTICAL)
					for (int i = c; i < rows && i <= D; ++i){
						flag = addBarco(i, c);
						if(!flag)
							return flag;
					}
				else
					for (int i = l; i < cols && i <= D; ++i){
						flag = addBarco(i, c);
						if(!flag)
							return flag;
					}
				break;
		}
		return flag;
	}*/

	double Board::getScoreAtual(int **OutroTable) {
		for (int i = 0; i < rows; ++i){
			for (int j = 0; j < cols; ++j){
				if(OutroTable[i][j] == BOAT_H)
					scoreAtual += 50;
				if(table[i][j] == BOAT_H)
					scoreAtual -= 20;
			}
		}
		return scoreAtual;
	}
	