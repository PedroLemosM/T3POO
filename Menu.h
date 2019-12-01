#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu {
    public:
        Menu(sf::RenderWindow&);
        ~Menu();

        void draw();
        
    private:
        sf::RenderWindow& window;
        sf::Font font;
        sf::Text titulo;
        sf::Text jogar;
};

#endif 