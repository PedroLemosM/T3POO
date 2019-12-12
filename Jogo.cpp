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

    momento = POSICIONANDO;
    barcos = 0;
    vertical = false;

    font.loadFromFile("Fonts/arial.ttf");
    texto.setFont(font);
    texto.setString(L"Posicione seus barcos!\n(aperte espaço para rotacionar)");
    texto.setCharacterSize(30);
    texto.setFillColor(sf::Color::Black);
    texto.setPosition((window.getSize().x - texto.getGlobalBounds().width) / 2, 45);
}

Jogo::~Jogo() {}

void Jogo::draw() {
    this->window.clear(sf::Color(173, 216, 230));
    this->window.draw(tabuleiroC);
    this->window.draw(tabuleiroJ);
    this->window.draw(texto);

    for (sf::Sprite& quad : quadsJ)
        this->window.draw(quad);
    for (sf::Sprite& quad : quadsC)
        this->window.draw(quad);
}

void Jogo::eventHandle(sf::Event& event) {
    switch (momento) {
        case POSICIONANDO:
            switch (event.type) {
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        for (int i = 0; i < jogador.getrows(); i++) 
                            for (int j = 0; j < jogador.getCols(); j++) {
                                sf::Sprite quadrante = quadsJ[i*jogador.getCols() + j];
                                if (quadrante.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                                    if (vertical) {
                                        switch (barcos) {
                                            case 0: // Carrier (size 5)
                                                if (!jogador.achaConflito(i, j, i + 4, j)) {
                                                    jogador.addBarco(i, j, i + 4, j);
                                                    barcos++;
                                                    this->updateBoardJ();
                                                }
                                                break;
                                            case 1: // Battleship (size 4)
                                                if (!jogador.achaConflito(i, j, i + 3, j)) {
                                                    jogador.addBarco(i, j, i + 3, j);
                                                    barcos++;
                                                    this->updateBoardJ();
                                                }
                                                break;
                                            case 2: // Cruiser (size 3)
                                            case 3: // Submarine (size 3)
                                                if (!jogador.achaConflito(i, j, i + 2, j)) {
                                                    jogador.addBarco(i, j, i + 2, j);
                                                    barcos++;
                                                    this->updateBoardJ();
                                                }
                                                break;
                                            case 4: // Destroyer (size 2)
                                                if (!jogador.achaConflito(i, j, i + 1, j)) {
                                                    jogador.addBarco(i, j, i + 1, j);
                                                    barcos++;
                                                    this->updateBoardJ();
                                                    this->updateMomento(JOGANDO);
                                                }
                                                break;
                                        }
                                    } else {
                                        switch (barcos) {
                                            case 0: // Carrier (size 5)
                                                if (!jogador.achaConflito(i, j, i, j + 4)) {
                                                    jogador.addBarco(i, j, i, j + 4);
                                                    barcos++;
                                                    this->updateBoardJ();
                                                }
                                                break;
                                            case 1: // Battleship (size 4)
                                                if (!jogador.achaConflito(i, j, i, j + 3)) {
                                                    jogador.addBarco(i, j, i, j + 3);
                                                    barcos++;
                                                    this->updateBoardJ();
                                                }
                                                break;
                                            case 2: // Cruiser (size 3)
                                            case 3: // Submarine (size 3)
                                                if (!jogador.achaConflito(i, j, i, j + 2)) {
                                                    jogador.addBarco(i, j, i, j + 2);
                                                    barcos++;
                                                    this->updateBoardJ();
                                                }
                                                break;
                                            case 4: // Destroyer (size 2)
                                                if (!jogador.achaConflito(i, j, i, j + 1)) {
                                                    jogador.addBarco(i, j, i, j + 1);
                                                    barcos++;
                                                    this->updateBoardJ();
                                                    this->updateMomento(JOGANDO);
                                                }
                                                break;
                                        }
                                    }
                                }
                        }
                    }
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Space)
                        vertical = !vertical;
                    break;
            }
            break;
    }
}

void Jogo::updateBoardJ() {
    for (int i = 0; i < jogador.getrows(); i++)
        for (int j = 0; j < jogador.getCols(); j++) {
            switch (jogador.getQuadrante(i, j)) {
                case WATER:
                    quadsJ[i*jogador.getCols() + j].setTexture(agua);
                    break;
                case BOAT:
                    quadsJ[i*jogador.getCols() + j].setTexture(barco);
                    break;
                case BOAT_H:
                    quadsJ[i*jogador.getCols() + j].setTexture(fogo);
                    break;
                case WATER_H:
                    quadsJ[i*jogador.getCols() + j].setTexture(splash);
                    break;
            }
        }
}

void Jogo::updateMomento(Momento m) {
    if (m == JOGANDO) {
        texto.setString("Batalha!");
        texto.setPosition((window.getSize().x - texto.getGlobalBounds().width) / 2, 45);
    }
    momento = m;
}