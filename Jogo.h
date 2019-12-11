#ifndef JOGO_H
#define JOGO_H

#include "Cena.h"
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Jogo : public Cena {
    private:
        Board& jogador;
        Board& computador;
        sf::RectangleShape tabuleiroJ, tabuleiroC;
        sf::Texture agua, fogo, barco, splash;
        std::vector<sf::Sprite> quadsJ, quadsC;

    public:
        Jogo(sf::RenderWindow&, Board&, Board&);
        ~Jogo();

        void draw();

};

#endif 