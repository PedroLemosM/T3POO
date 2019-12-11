#ifndef JOGO_H
#define JOGO_H

#include "Cena.h"
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Jogo : public Cena {
    private:
        Board& jogador, computador;
        sf::RectangleShape tabuleiroJ, tabuleiroC;
        std::vector<sf::RectangleShape> quadsJ, quadsC;

    public:
        Jogo(sf::RenderWindow&, Board&, Board&);
        ~Jogo();

        void draw();

};

#endif 