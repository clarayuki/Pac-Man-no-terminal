/**
 * @file Fantasma.h
 * @author Clara Yuki Sano - 11809920
 * @date 10/12/2022
 *
 * Este arquivo define uma classe Fantasma que representa personagens fantasmas
 * que estarão presentes no jogo do Pac-Man. Feito para o EP4 da matéria 
 * MAC0216 - Técnicas de Programação I no curso de Bacharelado de Ciência da 
 * Computação do Instituto de Matemática e Estatística da Universidade de São Paulo.
 */

#ifndef FANTASMA_H
#define FANTASMA_H

#include <iostream>
#include <random>
#include "Personagem.h"

/**
 * Classe utilizada para armazenar dados sobre um objeto Fantasma.
 */
class Fantasma : public Personagem
{
    public:

        /**
        * \brief Construtor 'default' de um fantasma.
        */
        Fantasma ();

        /**
        * \brief Construtor de um fantasma.
        * 
        * \param x Posição no eixo x do fantasma.
        * \param y Posição no eixo y do fantasma.
        */
        Fantasma (int x, int y);

        /**
        * \brief Destrutor de um fantasma.
        */
        ~Fantasma ();

        /**
        * \brief Recebe 4 booleanos relacionados às possibilidades de se mover
        * à direita, à esquerda, para baixo e para cima e retorna um movimento aleatório
        * possível que pode ser efetuado pelo fantasma.
        * 
        * \param dir1 True se for possível ir para a direita, false caso contrário.
        * \param esq2 True se for possível ir para a esquerda, false caso contrário.
        * \param baixo3 True se for possível ir para baixo, false caso contrário.
        * \param cima4 True se for possível ir para cima, false caso contrário.
        * 
        * \return O movimento que será efetuado pelo fantasma (na forma de um struct Posicao).
        */
        Posicao get_move (bool dir1, bool esq2, bool baixo3, bool cima4);
};

#endif