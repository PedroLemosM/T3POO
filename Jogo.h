#ifndef JOGO_H
#define JOGO_H

#include "Cena.h"
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <vector>

enum Momento { POSICIONANDO, JOGANDO };

class Jogo : public Cena {
    private:
        Momento momento;

        Board& jogador;
        Board& computador;
        sf::RectangleShape tabuleiroJ, tabuleiroC;
        sf::Texture agua, fogo, barco, splash;
        std::vector<sf::Sprite> quadsJ, quadsC;

        sf::Font font;
        sf::Text texto;

    public:
        Jogo(sf::RenderWindow&, Board&, Board&);
        ~Jogo();

        void draw();
        void eventHandle(sf::Event&);

};

#endif 