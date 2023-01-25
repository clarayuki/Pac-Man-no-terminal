/**
 * @file Pacman.cpp
 * @author Clara Yuki Sano 
 * @date 10/12/2022
 *
 * Este arquivo contém as definições dos métodos da classe Pacman.
 */

#include "Personagem.h"
#include "Pacman.h"

/**************************************
 * Definição dos métodos.
 **************************************/

Pacman::Pacman ()
:Personagem(0, 0, 'C') {}

Pacman::Pacman (int x, int y)
:Personagem(x, y, 'C') {}

Pacman::~Pacman () {}

Posicao Pacman::get_move () {
    
    char input;
    Posicao p = {0, 0};
    std::cout << "Direção (a - esquerda, d - direita, w - cima, s - baixo):" << std::endl;
    std::cin >> input;  // Usuário escreve a direção para qual deseja levar o Pacman.
    switch(input) {
        case 'a':
            p.x = -1;
            break;
        case 'd':
            p.x = 1;
            break;
        case 'w':
            p.y = -1;
            break;
        case 's':
            p.y = 1;
            break;
    }
    return p;
}
