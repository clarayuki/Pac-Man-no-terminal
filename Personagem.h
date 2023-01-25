/**
 * @file Personagem.h
 * @author Clara Yuki Sano - 11809920
 * @date 10/12/2022
 *
 * Este arquivo define uma classe Personagem que representa os personagens que 
 * estarão presentes no jogo do Pac-Man. Feito para o EP4 da disciplina 
 * MAC0216 - Técnicas de Programação I no curso de Bacharelado de Ciência da 
 * Computação do Instituto de Matemática e Estatística da Universidade de São Paulo.
 */

#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <iostream>

/**
 * Struct criado para armazenar coordenadas da posição de um personagem.
*/
struct Posicao {
    int x;
    int y;
};

/**
 * Classe utilizada para armazenar dados sobre um objeto Personagem.
 */
class Personagem
{
    protected:
        Posicao pos; /** Posição do personagem. */
        char sprite; /** Caracter que representa o personagem. */
    
    public:

        /**
        * \brief Constrói um personagem.
        * 
        * \param x Posição no eixo x do personagem.
        * \param y Posição no eixo y do personagem.
        */
        Personagem(int x, int y, char sprite);

        /**
         * Destrutor de um personagem.
        */
        ~Personagem();

        /**
        * \brief Seta valores para a posição do personagem.
        * 
        * \param x Posição no eixo x do personagem.
        * \param y Posição no eixo y do personagem.
        */
        void set_pos(int x, int y);

        /**
        * \brief Getter da posição do personagem.
        * 
        * \return Posição do personagem.
        */
        Posicao get_pos();

        /**
        * \brief Getter do caracter que representa o personagem.
        * 
        * \return Caracter que representa o personagem.
        */
        char get_sprite();

        /**
        * \brief Altera posição do personagem (faz ele se mover).
        * 
        * \param dx Deslocamento no eixo x do personagem.
        * \param dy Deslocamento no eixo y do personagem.
        * \param max_x Valor máximo do eixo x.
        * \param max_y Valor máximo do eixo y.
        */
        void move(int dx, int dy, int max_x, int max_y);

        /**
         * \brief Retorna uma movimentação de um personagem 
         * (haverá implementações específicas nas sub-classes).
         * 
         * \return Uma movimentação do personagem.
        */
        virtual Posicao get_move ();
};

#endif
