#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "BatalhaNaval.h"
#include "Board.h"
#include "Menu.h"

int main()
{
<<<<<<< HEAD
	sf::RenderWindow window(sf::VideoMode(800, 600), "Batalha Naval", sf::Style::Close);
	window.setVerticalSyncEnabled(true);

	Menu menu(window);

	while (window.isOpen()) {

		// Manipulação de eventos
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
			}
		}

		// Desenhos
		window.clear(sf::Color(201, 108, 55));

		menu.draw();

		window.display();
	}
=======
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
>>>>>>> master

	return 0;
}