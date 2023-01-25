/**
 * @file Personagem.cpp
 * @author Clara Yuki Sano - 11809920
 * @date 10/12/2022
 *
 * Este arquivo contém as definições dos métodos da classe Personagem.
 * Feito para o EP4 da matéria MAC0216 - Técnicas de Programação I no curso de Bacharelado de Ciência da 
 * Computação do Instituto de Matemática e Estatística da Universidade de São Paulo.
 */

#include "Personagem.h"

/**************************************
 * Definição dos métodos.
 **************************************/


Personagem::Personagem (int x, int y, char sprite) {
    this->pos = {x, y};
    this->sprite = sprite;
}

Personagem::~Personagem() {}

void Personagem::set_pos (int x, int y) {
    this->pos.x = x;
    this->pos.y = y;
}

Posicao Personagem::get_pos () {
    return this->pos;
}

char Personagem::get_sprite() {
    return this->sprite;
}

void Personagem::move(int dx, int dy, int max_x, int max_y) {

    if (abs(dx) + abs(dy) != 1) { // Ocorrência de um movimento inválido
        std::cout << "Movimento inválido!" << std::endl;
        return;
    }
    this->pos.x += dx;
    this->pos.y += dy;

    // Tratamento da ciclicidade do tabuleiro
    if (this->pos.x < 0) this->pos.x = max_x - 1; 
    else if (this->pos.x >= max_x) this->pos.x = 0;

    if (this->pos.y < 0) this->pos.y = max_y - 1;
    else if (this->pos.y >= max_y) this->pos.y = 0;
}

Posicao Personagem::get_move () {
    return {0,0};
}
