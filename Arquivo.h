/**
 * @file Arquivo.h
 * @author Clara Yuki Sano - 11809920
 * @date 10/12/2022
 *
 * Este arquivo define uma classe Arquivo que representa o arquivo do tabuleiro a ser manipulado.
 * Feito para o EP4 da matéria MAC0216 - Técnicas de Programação I no curso de Bacharelado de Ciência da 
 * Computação do Instituto de Matemática e Estatística da Universidade de São Paulo.
 */

#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <iostream>
#include <fstream>

/**
 * Classe utilizada para armazenar dados sobre um objeto arquivo.
*/
class Arquivo
{
    private:
        std::string * conteudo; /** Conteúdo do arquivo. */
        int cont_lin = 0; /** Contador do número de linhas do arquivo. */
        int cont_col = 0; /** Contador do número de colunas do tabuleiro. */

    public:

        /**
         * \brief Construtor de um arquivo.
         * 
         * \param nome_arq Nome do arquivo a ser carregado.
        */
        Arquivo (std::string nome_arq);

        /** 
         * \brief Destrutor de um arquivo. Responsável por liberar a memória da matriz de
         * conteúdo.
        */
        ~Arquivo ();

        /**
         * \brief Retorna o número de linhas do tabuleiro no arquivo.
         * 
         * \return Número de linhas.
        */
        int get_lin ();

        /**
         * \brief Retorna o número de colunas do tabuleiro no arquivo.
         * 
         * \return Número de colunas.
        */
        int get_col ();

        /**
         * \brief Retorna o caracter presente na posição (x,y) do conteúdo
         * do arquivo.
         * 
         * \return Caracter que está na posição (x, y)
        */
        char get_posicao (int x, int y);
};

#endif