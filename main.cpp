#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "BatalhaNaval.h"
#include "Board.h"

int main(int argc, char const *argv[])
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Batalha Naval", sf::Style::Close);
	window.setVerticalSyncEnabled(true);

	int rows, cols;
	string player;
	cout<<"nome"<<endl;
	cin>>player>>rows>>cols;
	BatalhaNaval jogo(player);
	Board jogador(rows,cols);
	cout<<"criei"<<endl;
	Board IA(rows,cols);
	cout<<"criei"<<endl;

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


		window.display();
	}

	return 0;
}