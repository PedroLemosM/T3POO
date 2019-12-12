#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <iostream>

#include "BatalhaNaval.h"
#include "Board.h"
#include "Menu.h"
#include "Jogo.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Batalha Naval", sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	GameState estado = MENU;

	Board jog(8, 8);
	Board cop(8, 8);

	Menu menu(window);
	Jogo jogo(window, jog, cop);

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
					case JOGO:
						jogo.eventHandle(event);
						break;
				}
			}
		}
		// Desenhos
		
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