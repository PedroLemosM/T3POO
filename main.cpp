#include <iostream>
#include <string>
#include "BatalhaNaval.h"
#include "Board.h"
#include <iostream>
int main(int argc, char const *argv[])
{
	int rows, cols;
	string player;
	cout<<"nome e tamanho tabuleiro(EX:10 10)"<<endl;
	cin>>player>>rows>>cols;
	BatalhaNaval jogo(player, rows, cols);
	Board jogador(rows,cols);
	cout<<"criei"<<endl;
	Board IA(rows,cols);
	cout<<"criei"<<endl;

	int aRow,aCol;
	do{
		cin>>aRow>>aCol;
		jogador.hitPos(aRow,aCol);
		cout<<"hit"<<aRow<<aCol<<endl;
		if(jogador.checkVitoria()==true);
		IA.hitPos(aRow,aCol);
		cout<<"hit"<<aRow<<aCol<<endl;


	}while(!IA.checkVitoria());

	return 0;
}