/**
 * @file Partida.h
 * @author Clara Yuki Sano - 11809920
 * @date 10/12/2022
 *
 * Este arquivo define uma classe Partida que representa o andamento de uma partida
 * de Pac-Man. Feito para o EP4 da disciplina MAC0216 - Técnicas de Programação I 
 * no curso de Bacharelado de Ciência da Computação do Instituto de Matemática e 
 * Estatística da Universidade de São Paulo.
 */

#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include "Personagem.h"
#include "Fantasma.h"
#include "Pacman.h"
#include "Labirinto.h"
#include "Arquivo.h"

/**
 * Classe utilizada para armazenar dados sobre uma partida.
*/
class Partida
{
    private:
        Pacman * pacman; /** Ponteiro para o pacman da partida. */
        Labirinto * labirinto; /** Ponteiro para o labirinto da partida. */
        Fantasma * fantasmas; /** Fantasmas presentes na partida (array de fantasmas). */
        int numero_fantasmas; /** Número de fantasmas na partida. */
        int pac_dots = 0; /** Número de pac-dots na partida (inicia em zero). */
        bool jogo_acabou = false; /** Booleano que define o término de uma partida. */
        bool perdeu = false; /** Booleano que define se o usuário perdeu a partida. */

        /**
         * \brief Função que imprime o tabuleiro.
        */
        void imprime_tabuleiro ();

        /**
         * \brief Função que verifica se ocorreu uma colisão entre o Pacman e algum fantasma.
         * 
         * \return True se ocorreu a colisão, false caso contrário.
        */
        bool verifica_colisao ();

        /**
         * \brief Configura o que ocorre nos turnos do jogo. Imprime o tabuleiro para o usuário,
         * movimenta os fantasmas, pede direção do Pacman para o usuário, verifica se houve colisão
         * e verifica se ganhou o jogo.
        */
        void turnos ();

        /**
         * \brief Verifica se o usuário ganhou a partida (isto é, se todos os pac-dots foram comidos).
         * 
         * \return True se ganhou, false caso contrário.
        */
        bool ganhou_partida ();

    public:

        /**
         * \brief Constrói uma partida a partir de um arquivo.
         * 
         * \param nome_arquivo Nome de um arquivo.
        */
        Partida (std::string nome_arquivo);

        /**
         * \brief Destrói o labirinto, o Pacman e os fantasmas.
        */
        ~Partida ();

        /**
         * \brief Convoca o método turnos() para efetuar uma partida.
        */
        void iniciar_partida ();
};

#endif