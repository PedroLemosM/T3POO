#ifndef JOGO_H
#define JOGO_H

#include "Cena.h"
#include <SFML/Graphics.hpp>

class Jogo : public Cena {
    private:

    public:
        Jogo(sf::RenderWindow&);
        ~Jogo();

        void draw();

};

#endif 