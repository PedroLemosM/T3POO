#include "Menu.h"

Menu::Menu(sf::RenderWindow& window) : Cena(window) {
    font.loadFromFile("Fonts/arial.ttf");

    titulo.setFont(font);
    titulo.setString("batalha naval kkkkk");
    titulo.setCharacterSize(24);
    titulo.setFillColor(sf::Color::Red);

    jogar.setFont(font);
    jogar.setString("jogar");
    jogar.setCharacterSize(24);
    jogar.setFillColor(sf::Color::Black);
    jogar.setPosition(250, 300);
}

Menu::~Menu() {}

void Menu::draw() {
    this->window.clear(sf::Color(255, 255, 255));
    this->window.draw(this->titulo);
    this->window.draw(this->jogar);
}

void Menu::eventHandle(sf::Event& event, GameState& gs) {
    switch (event.type) {
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left && jogar.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                gs = JOGO;
            break;
    }
}