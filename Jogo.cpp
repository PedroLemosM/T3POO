#include "Jogo.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Jogo::Jogo(sf::RenderWindow& window, Board& jogador, Board& computador) : Cena(window), jogador(jogador), computador(computador) {
    const float tam = 350.f;
    const float tamBorda = 4.f;
    const int rows = jogador.getrows();
    const int cols = jogador.getCols();
    srand(time(NULL));

    
    agua.loadFromFile("img/agua.png");
    fogo.loadFromFile("img/fogo.png");
    barco.loadFromFile("img/barco.png");
    splash.loadFromFile("img/splash.png");

    font.loadFromFile("Fonts/arial.ttf");
    
    texto.setFont(font);
    texto.setString(L"Posicione seus barcos!\n(aperte espaço para rotacionar)");
    texto.setCharacterSize(30);
    texto.setFillColor(sf::Color::Black);
    texto.setPosition((window.getSize().x - texto.getGlobalBounds().width) / 2, 45);

    voltar.setFont(font);
    voltar.setString("Voltar");
    voltar.setCharacterSize(30);
    voltar.setFillColor(sf::Color::Black);
    voltar.setPosition((window.getSize().x - voltar.getGlobalBounds().width) / 2, 500);

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
}

Jogo::~Jogo() {}

void Jogo::draw() {
    this->window.clear(sf::Color(173, 216, 230));
    this->window.draw(tabuleiroC);
    this->window.draw(tabuleiroJ);
    this->window.draw(texto);
    if (momento == VITORIA || momento == DERROTA)
        this->window.draw(voltar);

    for (sf::Sprite& quad : quadsJ)
        this->window.draw(quad);
    for (sf::Sprite& quad : quadsC)
        this->window.draw(quad);
}

void Jogo::eventHandle(sf::Event& event, GameState& gs) {
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
        
        case JOGANDO:
            switch (event.type) {
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        for (int i = 0; i < computador.getrows(); i++) 
                            for (int j = 0; j < computador.getCols(); j++) {
                                sf::Sprite quadrante = quadsC[i*jogador.getCols() + j];
                                if (quadrante.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && computador.validPos(i, j)) {
                                    computador.hitPos(i, j);
                                    updateBoardC();

                                    int iaX = rand() % jogador.getrows();
                                    int iaY = rand() % jogador.getCols();
                                    while (!jogador.validPos(iaX, iaY)) {
                                        iaX = rand() % jogador.getrows();
                                        iaY = rand() % jogador.getCols();
                                    }
                                    jogador.hitPos(iaX, iaY);
                                    updateBoardJ();
                                }
                            }
                    }
                    break;
            }
            break;

        case VITORIA:
        case DERROTA:
            if (event.type == sf::Event::MouseButtonPressed)
                if (event.mouseButton.button == sf::Mouse::Left)
                    if (voltar.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        this->reset();
                        gs = MENU;
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

    if (jogador.checkVitoria()) updateMomento(DERROTA);
}

void Jogo::updateBoardC() {
    for (int i = 0; i < computador.getrows(); i++)
        for (int j = 0; j < computador.getCols(); j++) {
            switch (computador.getQuadrante(i, j)) {
                case WATER:
                    quadsC[i*computador.getCols() + j].setTexture(agua);
                    break;
                case BOAT:
                    quadsC[i*computador.getCols() + j].setTexture(agua);
                    break;
                case BOAT_H:
                    quadsC[i*computador.getCols() + j].setTexture(fogo);
                    break;
                case WATER_H:
                    quadsC[i*computador.getCols() + j].setTexture(splash);
                    break;
            }
        }

    if (computador.checkVitoria()) updateMomento(VITORIA);
}

void Jogo::updateMomento(Momento m) {
    if (m == JOGANDO) {
        texto.setString("Batalha!");
        texto.setPosition((window.getSize().x - texto.getGlobalBounds().width) / 2, 45);
        int barcosIA = 0;
        int tamanhos[] = {4, 3, 2, 2, 1};
        bool verticalIA;

        while (barcosIA < 5) {
            float rand_f = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            if (rand_f >= 0.5) verticalIA = true;
            else verticalIA = false;

            int posX = rand() % this->computador.getrows();
            int posY = rand() % this->computador.getCols();

            if (verticalIA) {
                if (!computador.achaConflito(posX, posY, posX + tamanhos[barcosIA], posY)) {
                    computador.addBarco(posX, posY, posX + tamanhos[barcosIA], posY);
                    barcosIA++;
                }
            } else {
                if (!computador.achaConflito(posX, posY, posX, posY + tamanhos[barcosIA])) {
                    computador.addBarco(posX, posY, posX, posY + tamanhos[barcosIA]);
                    barcosIA++;
                }
            }
        }
    } else if (m == VITORIA) {
        texto.setString(L"Vitória!");
        texto.setPosition((window.getSize().x - texto.getGlobalBounds().width) / 2, 45);
    } else if (m == DERROTA) {
        texto.setString(L"Derrota!");
        texto.setPosition((window.getSize().x - texto.getGlobalBounds().width) / 2, 45);
    }
    momento = m;
}

void Jogo::reset() {
    texto.setString(L"Posicione seus barcos!\n(aperte espaço para rotacionar)");
    texto.setPosition((window.getSize().x - texto.getGlobalBounds().width) / 2, 45);
    momento = POSICIONANDO;
    barcos = 0;
    vertical = false;

    jogador.reset();
    computador.reset();
    
    for (int i = 0; i < jogador.getrows(); i++)
        for (int j = 0; j < jogador.getCols(); j++) {
            quadsC[i*jogador.getCols() + j].setTexture(agua);
            quadsJ[i*jogador.getCols() + j].setTexture(agua);
        }
}