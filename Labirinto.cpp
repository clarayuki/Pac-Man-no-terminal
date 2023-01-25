/**
 * @file Labirinto.cpp
 * @author Clara Yuki Sano - 11809920
 * @date 10/12/2022
 *
 * Este arquivo contém as definições dos métodos da classe Labirinto.
 * Feito para o EP4 da matéria MAC0216 - Técnicas de Programação I no curso de Bacharelado de Ciência da 
 * Computação do Instituto de Matemática e Estatística da Universidade de São Paulo.
 */

#include "Labirinto.h"
#include "Arquivo.h"

/**************************************
 * Definição dos métodos.
 **************************************/

const char Labirinto::icones_celulas[3] = { ' ', '.', '*' }; /** Vetor com caracteres presentes no tabuleiro */

Labirinto::Labirinto () {}

Labirinto::Labirinto (Arquivo * arquivo) {

    this->colunas = arquivo->get_col();
    this->linhas = arquivo->get_lin();

    this->tabuleiro = new int * [this->linhas]; // Aloca memória para o tabuleiro de inteiros.
    for (int i = 0; i < this->linhas; i++)
        this->tabuleiro[i] = new int[this->colunas];

    // Copia as informações do conteúdo do arquivo para o tabuleiro de inteiros.
    for (int i = 0; i < this->linhas; i++) {
        for (int j = 0; j < this->colunas; j++) {
            if (arquivo->get_posicao(i, j) == '.') {
                this->tabuleiro[i][j] = PAC_DOT;
                this->pac_dots++;
            }
            else if (arquivo->get_posicao(i, j) == '*')
                this->tabuleiro[i][j] = PAREDE;
            else
                this->tabuleiro[i][j] = VAZIO;
        }
    }
}

Labirinto::~Labirinto () {
    
    if (this->tabuleiro == nullptr) return;

    // Liberação de memória
    for (int i  = 0; i < this->linhas; i++) 
        delete[] this->tabuleiro[i];
    delete[] this->tabuleiro;
}

int Labirinto::get_linhas () {
    return this->linhas;
}

int Labirinto::get_colunas () {
    return this->colunas;
}

int Labirinto::get_celula (int x, int y) {
    return this->tabuleiro[x][y];
}

int Labirinto::get_pac_dots () {
    return this->pac_dots;
}

void Labirinto::set_pac_dots (int x) {
    this->pac_dots = x;
}

bool Labirinto::come_pac_dot (int x, int y) {
    if (this->tabuleiro[x][y] == PAC_DOT) {
        this->tabuleiro[x][y] = VAZIO;
        return true;
    }
    return false;
}

bool Labirinto::verifica_pos (int x, int y) {
    if (this->tabuleiro[x][y] == PAREDE)
        return false;
    return true;
}

bool Labirinto::verifica_direcao_esq (int x, int y) {
    int x_check = x - 1;
    if (x_check < 0)  // Se o x_check for negativo, quer dizer que eu tenho que verificar o x 
        x_check = this->get_colunas() - 1;  //do outro lado do tabuleiro (cíclico, x = cols - 1).
        
    return this->verifica_pos(y, x_check);
}

bool Labirinto::verifica_direcao_dir (int x, int y) {
    int x_check = x + 1;
    if (x_check > this->get_colunas() - 1) // Se o x_check for maior que o limite de colunas, quer dizer que eu 
        x_check = 0;                       //tenho que verificar o x do início do tabuleiro (cíclico, x = 0).
    return this->verifica_pos(y, x_check);
}

bool Labirinto::verifica_direcao_cima (int x, int y) {
    int y_check = y - 1;
    if (y_check < 0)  // Se o y_check for negativo, quer dizer que eu tenho que verificar o y
        y_check = this->get_linhas() - 1;  //mais embaixo do tabuleiro (cíclico, y = linhas - 1).
    return this->verifica_pos(y_check, x);
}

bool Labirinto::verifica_direcao_baixo (int x, int y) {
    int y_check = y + 1;
    if (y_check > this->get_linhas() - 1)  // Se o y_check for maior que o limite de linhas, quer dizer que eu 
        y_check = 0;                       // tenho que verificar o y mais acima (cíclico, y = 0).
    return this->verifica_pos(y_check, x);
}