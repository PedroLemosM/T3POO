#ifndef CENA_H
#define CENA_H

#include <SFML/Graphics.hpp>

// Pensei numa classe abstrata assim pra poder
// controlar as cenas depois: as classes filhas
// vão ser menu, jogo, fim de jogo etc etc etc
class Cena {
    protected:
        sf::RenderWindow& window;
    public:
        Cena(sf::RenderWindow&);
        virtual ~Cena();

        virtual void draw() = 0;
};

#endif 