/**
 * @file Pacman.h
 * @author Clara Yuki Sano - 11809920
 * @date 10/12/2022
 *
 * Este arquivo define uma classe Pacman que representa o personagem Pac-Man
 * que estará presentes no jogo. Feito para o EP4 da matéria 
 * MAC0216 - Técnicas de Programação I no curso de Bacharelado de Ciência da 
 * Computação do Instituto de Matemática e Estatística da Universidade de São Paulo.
 */

#ifndef PACMAN_H
#define PACMAN_H

#include <iostream>

/**
 * Classe utilizada para armazenar dados sobre um objeto Pacman.
 */
class Pacman : public Personagem
{
    public:

        /**
        * \brief Construtor 'default' de um Pacman.
        */
        Pacman ();

        /**
        * \brief Construtor de um Pacman.
        * 
        * \param x Posição no eixo x do Pacman.
        * \param y Posição no eixo y do Pacman.
        * 
        */
        Pacman (int x, int y);

        /**
        * \brief Destrutor de um Pacman.
        */
        ~Pacman ();

        /**
        * \brief A partir do input do usuário, retorna uma movimentação para o Pacman.
        * 
        * \return O movimento que será efetuado pelo Pacman (na forma de um struct Posicao).
        */
        Posicao get_move ();
};

#endif