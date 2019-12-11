#include "Board.h"

	Board::Board(int rows,int cols):rows(rows),cols(cols){
		scoreAtual = 0;

		table=new Posicoes*[rows];
		for (int i = 0; i < rows; ++i)
			table[i]=new Posicoes[cols];
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
				if(table[i][j]==BOAT)
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


	bool Board::addBarco(int xi, int yi, int xf ,int yf) {
		if(achaConflito(xi,yi,xf,yf))
				return false;
		if(xi==xf)
			for (int i = yi; i < yi-yf; ++i)
				table[xi][i] = BOAT;
		else 
			for (int i = xi; i < yi-yf; ++i)
				table[i][yi] = BOAT;			
		return true;
	}
	bool Board::achaConflito(int xi, int yi, int xf ,int yf){
		if(xi==xf)
			for (int i = yi; i < yi-yf; ++i)
				if(i>rows||i>cols||table[xi][i] == BOAT)
					return true;
		else if(yi==yf)
			for (int i = xi; i < yi-yf; ++i)
				if(i>rows||i>cols|table[i][yi] == BOAT)
					return true;
		else
			return true;
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

	double Board::getScore(int **OutroTable) {
		double score=0;
		for (int i = 0; i < rows; ++i){
			for (int j = 0; j < cols; ++j){
				if(OutroTable[i][j] == BOAT_H){
					score += 50;
				}
				
				if(table[i][j] == BOAT_H){
					score -= 20;
				}
			}
		}
		return score;
	}
	
	Posicoes Board::getQuadrante(int row, int col) {
		return table[row][col];
	}