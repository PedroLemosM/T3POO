#include "Menu.h"

Menu::Menu(sf::RenderWindow& window) : window(window) {
    font.loadFromFile("Fonts/arial.ttf");

    titulo.setFont(font);
    titulo.setString("batalha naval kkkkk");
    titulo.setCharacterSize(24);
    titulo.setFillColor(sf::Color::Red);

}

Menu::~Menu() {}

void Menu::draw() {
    this->window.clear(sf::Color(255, 255, 255));
    this->window.draw(this->titulo);
}