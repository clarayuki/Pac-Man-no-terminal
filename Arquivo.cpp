/**
 * @file Arquivo.cpp
 * @author Clara Yuki Sano - 11809920
 * @date 10/12/2022
 *
 * Este arquivo contém as definições dos métodos da classe Arquivo.
 * Feito para o EP4 da matéria MAC0216 - Técnicas de Programação I no curso de Bacharelado de Ciência da 
 * Computação do Instituto de Matemática e Estatística da Universidade de São Paulo.
 */

#include "Arquivo.h"

/**************************************
 * Definição dos métodos.
 **************************************/

Arquivo::Arquivo (std::string nome_arq) {
    
    std::ifstream arquivo_cont (nome_arq);
    std::string linha;

    // Esta parte do código conta o número de linhas e o número de colunas do tabuleiro no arquivo
    if (arquivo_cont.is_open()) {
        while (arquivo_cont.good()) {
            std::getline(arquivo_cont, linha); 
            this->cont_lin++;
            if (this->cont_col == 0)
                this->cont_col = linha.length();
        }
    }
    arquivo_cont.close(); // Fecha o arquivo
    
    this->conteudo = new std::string[this->cont_lin];
    
    int i = 0;
    std::ifstream arquivo (nome_arq);
    if (arquivo.is_open()) {
        while (arquivo.good()) {  // Copia o tabuleiro do arquivo para o array de strings "conteudo"
            std::getline(arquivo, linha);
            this->conteudo[i] = std::string(linha);
            i++;
        }
    }
    arquivo.close();
}

Arquivo::~Arquivo () {
    delete[] this->conteudo;
}

int Arquivo::get_lin () {
    return this->cont_lin;
}

int Arquivo::get_col () {
    return this->cont_col;
}

char Arquivo::get_posicao (int x, int y) {
    return this->conteudo[x].at(y);
}