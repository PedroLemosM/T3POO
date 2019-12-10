#ifndef MENU_H
#define MENU_H

#include "Cena.h"

#include <SFML/Graphics.hpp>

class Menu : public Cena {
    public:
        Menu(sf::RenderWindow&);
        ~Menu();

        void draw();
        
    private:
        sf::Font font;
        sf::Text titulo;
        sf::Text jogar;
};

#endif 