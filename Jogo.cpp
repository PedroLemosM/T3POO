#include "Jogo.h"

Jogo::Jogo(sf::RenderWindow& window) : Cena(window) {}

Jogo::~Jogo() {}

void Jogo::draw() {
    this->window.clear(sf::Color(0, 0, 255));
}