#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "BatalhaNaval.h"
#include "Board.h"
#include "Menu.h"
#include "Jogo.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Batalha Naval", sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	GameState estado = MENU;

	Menu menu(window);
	Jogo jogo(window);

	while (window.isOpen()) {

		// Manipulação de eventos
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			else {
				switch (estado) {
					case MENU:
						menu.eventHandle(event, estado);
						break;
				}
			}
		}

		// Desenhos
		window.clear(sf::Color(201, 108, 55));

		switch (estado) {
			case MENU:
				menu.draw();
				break;
			case JOGO:
				jogo.draw();
				break;
		}

		window.display();
	}

	return 0;
}