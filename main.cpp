#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "BatalhaNaval.h"
#include "Board.h"
#include "Menu.h"

int main(int argc, char const *argv[])
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Batalha Naval", sf::Style::Close);
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

	return 0;
}