#include "Menu.h"

Menu::Menu(sf::RenderWindow& window) : Cena(window) {
    font.loadFromFile("Fonts/arial.ttf");

    titulo.setFont(font);
    titulo.setString("Batalha Naval");
    titulo.setCharacterSize(50);
    titulo.setFillColor(sf::Color::Red);
    titulo.setPosition((window.getSize().x - titulo.getGlobalBounds().width) / 2, 50);

    jogar.setFont(font);
    jogar.setString("Jogar");
    jogar.setCharacterSize(40);
    jogar.setFillColor(sf::Color::Black);
    jogar.setPosition((window.getSize().x - jogar.getGlobalBounds().width) / 2, 300);
}

Menu::~Menu() {}

void Menu::draw() {
    this->window.clear(sf::Color(173, 216, 230));
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