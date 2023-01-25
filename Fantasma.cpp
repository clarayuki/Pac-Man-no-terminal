/**
 * @file Fantasma.cpp
 * @author Clara Yuki Sano 
 * @date 10/12/2022
 *
 * Este arquivo contém as definições dos métodos da classe Fantasma.
 */

#include "Personagem.h"
#include "Fantasma.h"

/**************************************
 * Definição dos métodos.
 **************************************/

Fantasma::Fantasma ()
:Personagem(0, 0,'F') {}

Fantasma::Fantasma (int x, int y)
:Personagem(x, y, 'F') {}

Fantasma::~Fantasma () {}

Posicao Fantasma::get_move (bool dir1, bool esq2, bool baixo3, bool cima4) {

    Posicao p = {0, 0};
    int conta_true = 0; // Conta quantas direções são validas

    if (dir1 == true)
        conta_true++;
    if (esq2 == true)
        conta_true++;
    if (baixo3 == true)
        conta_true++;
    if (cima4 == true)
        conta_true++;

    // Gera número aleatório entre 1 e conta_true
    int seed = time(0);
    std::mt19937 e { (long unsigned int) seed };
    std::uniform_int_distribution<int> dist {1, conta_true};
    int r = dist(e); // Número aleatório

    // Dentre direções válidas, escolhe-se a r-ésima
    if (dir1 == true) {
        r--;
        if (r == 0) {
            p.x = 1;
            return p;
        }     
    }

    if (esq2 == true) {
        r--;
        if (r == 0) {
            p.x = -1;
            return p;
        }     
    }

    if (baixo3 == true) {
        r--;
        if (r == 0) {
            p.y = 1;
            return p;
        }     
    }

    if (cima4 == true) {
        r--;
        if (r == 0) {
            p.y = -1;
            return p;
        }     
    }

    p = {-1, -1}; 
    return p;
}
