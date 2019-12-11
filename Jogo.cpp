#include "Jogo.h"
#include <iostream>

Jogo::Jogo(sf::RenderWindow& window, Board& jogador, Board& computador) : Cena(window), jogador(jogador), computador(computador) {
    const float tam = 350.f;
    const float tamBorda = 4.f;
    const int rows = jogador.getrows();
    const int cols = jogador.getCols();
    
    agua.loadFromFile("img/agua.png");
    fogo.loadFromFile("img/fogo.png");
    barco.loadFromFile("img/barco.png");
    splash.loadFromFile("img/splash.png");

    // Centralizando verticalmente e colocando os dois tabuleiros
    // centralizados horizontalmente
    tabuleiroJ.setFillColor(sf::Color::Black);
    tabuleiroJ.setSize(sf::Vector2f(tam, tam));
    tabuleiroJ.setPosition((window.getSize().x / 2) - tam - 5, (window.getSize().y - tam) / 2);

    tabuleiroC.setFillColor(sf::Color::Black);
    tabuleiroC.setSize(sf::Vector2f(tam, tam));
    tabuleiroC.setPosition((window.getSize().x / 2) + 5, (window.getSize().y - tam) / 2);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Eu fiz umas contas com o tamanho da lacuna, o tamanho de
            // cada quadrante e sei la mais o que. se quiser mudar
            // o tamanho, mexe nos const float ali em cima
            sf::Sprite quadranteJ, quadranteC;
            if (jogador.getQuadrante(i, j) == BOAT)
                quadranteJ.setTexture(barco);
            else
                quadranteJ.setTexture(agua);

            float sizeX = (tam - (cols+1)*tamBorda)/cols;
            float sizeY = (tam - (rows+1)*tamBorda)/rows;


            quadranteJ.setScale( sizeX / agua.getSize().x, sizeY / agua.getSize().y );

            float posX = tabuleiroJ.getPosition().x + tamBorda*(j+1) + sizeX * j;
            float posY = tabuleiroJ.getPosition().y + tamBorda*(i+1) + sizeY * i;

            quadranteJ.setPosition(posX, posY);

            quadranteC.setTexture(agua);
            quadranteC.setScale( sizeX / agua.getSize().x, sizeY / agua.getSize().y );

            posX = tabuleiroC.getPosition().x + tamBorda*(j+1) + sizeX * j;
            posY = tabuleiroC.getPosition().y + tamBorda*(i+1) + sizeY * i;

            quadranteC.setPosition(posX, posY);

            quadsJ.push_back(quadranteJ);
            quadsC.push_back(quadranteC);
        }
    }
}

Jogo::~Jogo() {}

void Jogo::draw() {
    this->window.clear(sf::Color(173, 216, 230));
    this->window.draw(tabuleiroC);
    this->window.draw(tabuleiroJ);

    for (sf::Sprite& quad : quadsJ)
        this->window.draw(quad);
    for (sf::Sprite& quad : quadsC)
        this->window.draw(quad);
}