#ifndef JOGO_H
#define JOGO_H

#include "Cena.h"
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <vector>

enum Momento { POSICIONANDO, JOGANDO, VITORIA, DERROTA };

class Jogo : public Cena {
    private:
        Momento momento;
        int barcos;
        bool vertical;
        Board& jogador;
        Board& computador;
        sf::RectangleShape tabuleiroJ, tabuleiroC;
        sf::Texture agua, fogo, barco, splash;
        std::vector<sf::Sprite> quadsJ, quadsC;

        sf::Font font;
        sf::Text texto;
        sf::Text voltar;

    public:
        Jogo(sf::RenderWindow&, Board&, Board&);
        ~Jogo();

        void draw();
        void eventHandle(sf::Event&, GameState&);
        void updateMomento(Momento);
        void updateBoardJ();
        void updateBoardC();
        void reset();

};

#endif 