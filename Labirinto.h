/**
 * @file Labirinto.h
 * @author Clara Yuki Sano 
 * @date 10/12/2022
 *
 * Este arquivo define uma classe Labirinto que representa o labirinto (tabuleiro) onde ocorrerá
 * o jogo do Pac-Man. 
 */

#ifndef LABIRINTO_H
#define LABIRINTO_H

#include <iostream>
#include "Arquivo.h"

/**
 * Classe utilizada para armazenar dados sobre um objeto labirinto.
 */
class Labirinto 
{
    private:
        int ** tabuleiro; /** Matriz de inteiros que representa o labirinto. */
        int linhas, colunas; /** Número de linhas e de colunas do labirinto. */
        int pac_dots = 0; /** Número de pac-dots existentes no labirinto. */
        
    public:
        /**
         * Enum que define espaço vazio (VAZIO) como 0, um pac-dot (PAC_DOT) como 1
         * e uma parede (PAREDE) como 2.
        */
        enum Celula {
            VAZIO,
            PAC_DOT,
            PAREDE
        };

        static const char icones_celulas[3]; /** Vetor de caracteres que são os ícones das células do labirinto. */

        /**
         * \brief Construtor 'default' de um labirinto.
        */
        Labirinto ();

        /**
         * \brief Constrói uma matriz de inteiros que representa o tabuleiro do labirinto a partir de um arquivo.
         * 
         * \param arquivo Ponteiro para o arquivo a ser manipulado.
        */
        Labirinto (Arquivo * arquivo);

        /**
         * \brief Destrutor do tabuleiro do labirinto. Responsável por liberar memória da matriz de inteiros
         * que representa o tabuleiro.
        */
        ~Labirinto ();

        /**
         * \brief Getter do número de linhas do tabuleiro.
         * 
         * \return Número de linhas do tabuleiro de inteiros.
        */
        int get_linhas();

        /**
         * \brief Getter do número de colunas do tabuleiro.
         * 
         * \return Número de colunas do tabuleiro de inteiros.
        */
        int get_colunas();

        /**
         * \brief Getter do valor de uma célula do tabuleiro de inteiros.
         * 
         * \param x Posição no eixo x da célula.
         * \param y Posição no eixo y da célula.
         * 
         * \return O valor inteiro da célula na posição (x, y).
        */
        int get_celula (int x, int y);

        /**
         * \brief Getter do número de pac-dots existentes no tabuleiro.
         * 
         * \return Número de pac-dots.
        */
        int get_pac_dots();

        /**
         * \brief Seta o número de pac-dots do tabuleiro.
         * 
         * \param x Número de pac-dots do tabuleiro.
        */
        void set_pac_dots(int x);

        /**
         * \brief Caso a célula da posição (x, y) tenha um pac-dot (valor 1),
         * substitui por um espaço vazio (valor 0).
         * 
         * \param x Posição no eixo x da célula.
         * \param y Posição no eixo y da célula.
         * 
         * \return True se comeu pac-dot, false caso contrário.
        */
        bool come_pac_dot (int x, int y);

        /**
         * \brief Verifica se posição (x, y) do tabuleiro é uma posição válida (não tem parede).
         * 
         * \param x Posição no eixo x da célula.
         * \param y Posição no eixo y da célula.
         * 
         * \return True se não tem parede (é válida), false caso contrário.
        */
        bool verifica_pos (int x, int y);

        /**
         * \brief Verifica se posição na esquerda de (x,y) é válida (não tem parede).
         * 
         * \param x Posição no eixo x da célula.
         * \param y Posição no eixo y da célula.
         * 
         * \return True se for válida, false caso contrário.
        */
        bool verifica_direcao_esq (int x, int y);

        /**
         * \brief Verifica se posição na direita de (x,y) é válida (não tem parede).
         * 
         * \param x Posição no eixo x da célula.
         * \param y Posição no eixo y da célula.
         * 
         * \return True se for válida, false caso contrário.
        */
        bool verifica_direcao_dir (int x, int y);

        /**
         * \brief Verifica se posição para cima de (x,y) é válida (não tem parede).
         * 
         * \param x Posição no eixo x da célula.
         * \param y Posição no eixo y da célula.
         * 
         * \return True se for válida, false caso contrário.
        */
        bool verifica_direcao_cima (int x, int y);

        /**
         * \brief Verifica se posição para baixo de (x,y) é válida (não tem parede).
         * 
         * \param x Posição no eixo x da célula.
         * \param y Posição no eixo y da célula.
         * 
         * \return True se for válida, false caso contrário.
        */
        bool verifica_direcao_baixo (int x, int y);
};

#endif