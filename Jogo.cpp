#include "Jogo.h"

Jogo::Jogo(sf::RenderWindow& window, Board& jogador, Board& computador) : Cena(window), jogador(jogador), computador(computador) {
    const float tam = 350.f;
    const float tamBorda = 4.f;
    const int rows = jogador.getrows();
    const int cols = jogador.getCols();
    
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

            sf::RectangleShape quadranteJ, quadranteC;
            quadranteJ.setFillColor(sf::Color::Blue);
            quadranteJ.setSize(sf::Vector2f( (tam - (cols+1)*tamBorda)/cols, (tam - (rows+1)*tamBorda)/rows));

            float posX = tabuleiroJ.getPosition().x + tamBorda*(j+1) + quadranteJ.getSize().x * j;
            float posY = tabuleiroJ.getPosition().y + tamBorda*(i+1) + quadranteJ.getSize().y * i;

            quadranteJ.setPosition(posX, posY);

            quadranteC.setFillColor(sf::Color::Blue);
            quadranteC.setSize(sf::Vector2f( (tam - (cols+1)*tamBorda)/cols, (tam - (rows+1)*tamBorda)/rows));

            posX = tabuleiroC.getPosition().x + tamBorda*(j+1) + quadranteC.getSize().x * j;
            posY = tabuleiroC.getPosition().y + tamBorda*(i+1) + quadranteC.getSize().y * i;

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

    for (sf::RectangleShape& quad : quadsJ)
        this->window.draw(quad);
    for (sf::RectangleShape& quad : quadsC)
        this->window.draw(quad);
}