/**
 * @file ep4.cpp
 * @author Clara Yuki Sano - 11809920
 * @date 10/12/2022
 *
 * Este arquivo contém a main do jogo do Pac-Man (junto com os testes). Feito para 
 * o EP4 da matéria MAC0216 - Técnicas de Programação I no curso de Bacharelado de Ciência da 
 * Computação do Instituto de Matemática e Estatística da Universidade de São Paulo.
 */

#include <iostream>
#include "Partida.h"
#include <gtest/gtest.h>

/*************************
 * Main
 *************************/

int main (int argc, char ** argv)
{   

    if (strcmp(argv[1], "jogo") == 0) {
        Partida partida = Partida(argv[2]);  // Cria um objeto partida a partir do arquivo dado na linha de comando
        partida.iniciar_partida();  // Inicia a partida
    }

    else if (strcmp(argv[1], "testes") == 0) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();  // Roda todos os testes 
    }

    return 0;
}

/*************************
 * Testando os métodos de Personagem.h
 *************************/

/**
 * Testa os métodos get_pos() e move()
*/
TEST(PersonagemSuite, PersonagemMove) {
    int x = 19;
    int y = 15;
    Personagem ptest = Personagem(x, y, 'E');
    Posicao pos_antiga;
    Posicao pos_nova;
    pos_antiga = ptest.get_pos();
    ptest.move(1, 0, 30, 30);
    pos_nova = ptest.get_pos();
    ASSERT_EQ(pos_antiga.x - pos_nova.x, -1);
    ASSERT_EQ(pos_antiga.y - pos_nova.y, 0);
}

TEST(PersonagemSuite, PersonagemSetPos) {
    int x = 19;
    int y = 15;
    Posicao pos_aux;
    Personagem ptest = Personagem(x, y, 'E');
    ptest.set_pos(16, 12);
    pos_aux = ptest.get_pos();
    ASSERT_EQ(pos_aux.x, 16);
    ASSERT_EQ(pos_aux.y, 12);
}

TEST(PersonagemSuite, PersonagemSprite) {
    int x = 15;
    int y = 22;
    Personagem ptest = Personagem(x, y, 'E');
    char c = ptest.get_sprite();
    ASSERT_EQ(c, 'E');
}


/*************************
 * Testando os métodos de Fantasma.h
 *************************/

/**
 * Testa os métodos move() e get_pos()
*/
TEST(FantasmaSuite, FantasmaMove) {
    int x = 2;
    int y = 2;
    Fantasma Ftest = Fantasma(x, y);
    Posicao pos_antiga;
    Posicao pos_nova;
    pos_antiga = Ftest.get_pos();
    Ftest.move(1, 0, 10, 10);
    pos_nova = Ftest.get_pos();
    ASSERT_EQ(pos_antiga.x - pos_nova.x, -1);
    ASSERT_EQ(pos_antiga.y - pos_nova.y, 0);
}

/** 
 * Testa o método get_move(): com uma possível direção a ser tomada (cima)
*/
TEST(FantasmaSuite, FantasmaGetMove) {
    int x = 2;
    int y = 2;
    Fantasma Ftest = Fantasma(x, y);
    bool dir1, esq2, baixo3 = false;
    bool cima4 = true;
    Posicao move;
    move = Ftest.get_move(dir1, esq2, baixo3, cima4);
    ASSERT_EQ(move.x, 0);
    ASSERT_EQ(move.y, -1);
}

/** 
 * Testa o método get_move(): com uma possível direção a ser tomada (baixo)
*/
TEST(FantasmaSuite, FantasmaGetMove2) {
    int x = 2;
    int y = 2;
    Fantasma Ftest = Fantasma(x, y);
    bool dir1, esq2, cima4 = false;
    bool baixo3 = true;
    Posicao move;
    move = Ftest.get_move(dir1, esq2, baixo3, cima4);
    ASSERT_EQ(move.x, 0);
    ASSERT_EQ(move.y, 1);
}

/** 
 * Testa o método get_move(): com uma possível direção a ser tomada (esquerda)
*/
TEST(FantasmaSuite, FantasmaGetMove3) {
    int x = 2;
    int y = 2;
    Fantasma Ftest = Fantasma(x, y);
    bool dir1, cima4, baixo3 = false;
    bool esq2 = true;
    Posicao move;
    move = Ftest.get_move(dir1, esq2, baixo3, cima4);
    ASSERT_EQ(move.x, -1);
    ASSERT_EQ(move.y, 0);
}

/** 
 * Testa o método get_move(): com uma possível direção a ser tomada (direita)
*/
TEST(FantasmaSuite, FantasmaGetMove4) {
    int x = 2;
    int y = 2;
    Fantasma Ftest = Fantasma(x, y);
    bool cima4, esq2, baixo3 = false;
    bool dir1 = true;
    Posicao move;
    move = Ftest.get_move(dir1, esq2, baixo3, cima4);
    ASSERT_EQ(move.x, 1);
    ASSERT_EQ(move.y, 0);
}

/**
 * Testa o método get_sprite() do fantasma
*/
TEST(FantasmaSuite, FantasmaSprite) {
    Fantasma Ftest;
    char c;
    c = Ftest.get_sprite();
    ASSERT_EQ(c, 'F');
}

/*************************
 * Testando os métodos de Pacman.h
 *************************/

/**
 * Testa o método move()
*/
TEST(PacmanSuite, PacmanMove) {
    int x = 9;
    int y = 3;
    Pacman Ptest = Pacman(x, y);
    Posicao pos_antiga;
    Posicao pos_nova;
    pos_antiga = Ptest.get_pos();
    Ptest.move(1, 0, 10, 10); // nesse caso o pacman apareceria do outro lado do tabuleiro
    pos_nova = Ptest.get_pos();
    ASSERT_EQ(pos_antiga.x - pos_nova.x, 9);
    ASSERT_EQ(pos_antiga.y - pos_nova.y, 0);
}

/**
 * Testa o método get_sprite() do pacman
*/
TEST(PacmanSuite, PacmanSprite) {
    Pacman Ptest;
    char c;
    c = Ptest.get_sprite();
    ASSERT_EQ(c, 'C');
}

/*************************
 * Testando os métodos de Arquivo.h
 *************************/

/**
 * Testa o método get_lin(): verifica se a quantidade de linhas do arquivo é de fato 31 (no caso o arquivo 
 * utilizado é o labirinto1, que está neste diretório)
*/
TEST(ArquivoSuite, ArquivoLinhas) {
    Arquivo arqtest = Arquivo("labirinto1");
    int linhas = arqtest.get_lin();
    ASSERT_EQ(linhas, 31); // já sabe-se de antemão que o labirinto1 possui 31 linhas.
}

/**
 * Testa o método get_col(): verifica se a quantidade de colunas do arquivo é de fato 27 (no caso o arquivo 
 * utilizado é o labirinto1, que está neste diretório)
*/
TEST(ArquivoSuite, ArquivoColunas) {
    Arquivo arqtest = Arquivo("labirinto1");
    int colunas = arqtest.get_col();
    ASSERT_EQ(colunas, 27); // já sabe-se de antemão que o labirinto1 possui 27 colunas.
}

/**
 * Testa o método get_posicao(): verifica se a posição do meio do labirinto do arquivo equivale a ' ' 
 * (estamos usando o arquivo labirinto1 como entrada)
*/
TEST(ArquivoSuite, ArquivoPos) {
    Arquivo arqtest = Arquivo("labirinto1");
    int x = 31 / 2;
    int y = 27 / 2;
    char cel = arqtest.get_posicao(x, y);
    ASSERT_EQ(cel, ' '); // já sabe-se de antemão que a posição do meio no labirinto1 é um espaço vazio.
}

/*************************
 * Testando os métodos de Labirinto.h
 *************************/

/**
 * Testa o método get_linhas(): verifica se a quantidade de linhas do labirinto é de fato 31 (no caso o arquivo 
 * utilizado é o labirinto1, que está neste diretório)
*/
TEST(LabirintoSuite, LabirintoLinhas) {
    Arquivo arq = Arquivo("labirinto1");
    Labirinto labtest = Labirinto(&arq);
    int linhas = labtest.get_linhas();
    ASSERT_EQ(linhas, 31);
}

/**
 * Testa o método get_colunas(): verifica se a quantidade de colunas do labirinto é de fato 27 (no caso o arquivo 
 * utilizado é o labirinto1, que está neste diretório)
*/
TEST(LabirintoSuite, LabirintoColunas) {
    Arquivo arq = Arquivo("labirinto1");
    Labirinto labtest = Labirinto(&arq);
    int colunas = labtest.get_colunas();
    ASSERT_EQ(colunas, 27);
}

/**
 * Testa o método get_celula(): verifica se a posição (0,9) do tabuleiro de inteiros é um 2 (o que é de esperar
 * do arquivo labirinto1)
*/
TEST(LabirintoSuite, LabirintoPos) {
    Arquivo arq = Arquivo("labirinto1");
    Labirinto labtest = Labirinto(&arq);
    int x = labtest.get_celula(0, 9); // sabe-se que na posição (0,9) do labirinto1 existe uma parede ('*'), valor 2 no tabuleiro de inteiros
    ASSERT_EQ(x, 2);
}

/**
 * Testa os métodos set_pac_dots() e get_pac_dots()
*/
TEST(LabirintoSuite, LabirintoSetPacDots) {
    Arquivo arq = Arquivo("labirinto1");
    Labirinto labtest = Labirinto(&arq);
    int x = 32;
    labtest.set_pac_dots(x);
    int y = labtest.get_pac_dots();
    ASSERT_EQ(y, x);
}

/**
 * Testa o método come_pac_dot()
*/
TEST(LabirintoSuite, LabirintoComePacDot) {
    Arquivo arq = Arquivo("labirinto1");
    Labirinto labtest = Labirinto(&arq);
    bool cel1 = labtest.come_pac_dot(9,1); // Na posição (9,1) do labirinto1 existe um pac-dot (tem que retornar true)
    bool cel2 = labtest.come_pac_dot(7, 0); // Na posição (7,0) do labirinto1 existe uma parede (tem que retornar false)
    ASSERT_EQ(cel1, true);
    ASSERT_EQ(cel2, false);
}

/**
 * Testa método verifica_pos(): verifica se posição (2,5) é válida (ela não é válida, pois tem parede lá)
 * e se posição (1,9) é válida (ela é válida, pois tem um pac-dot lá)
*/
TEST(LabirintoSuite, LabirintoVerificaPos) {
    Arquivo arq = Arquivo("labirinto1");
    Labirinto labtest = Labirinto(&arq);
    int x = 2;
    int y = 5;
    int w = 1;
    int z = 9;
    bool cel1 = labtest.verifica_pos(x, y); // existe uma parede nessa posição
    bool cel2 = labtest.verifica_pos(w, z); // existe um pac-dot nessa posição
    ASSERT_EQ(cel1, false); 
    ASSERT_EQ(cel2, true);
}

/**
 * Testa os métodos verifica_direcao_dir(), verifica_direcao_esq(), verifica_direcao_baixo() e
 * verifica_direcao_cima() a partir do labirinto de que já temos informações (labirinto1)
*/
TEST(LabirintoSuite, LabirintoVerificaDirecao) {
    Arquivo arq = Arquivo("labirinto1");
    Labirinto labtest = Labirinto(&arq);
    int x = 12;
    int y = 3;
    // Na posição (12, 3) do labirinto1, é possível andar para cima e para baixo, mas não para a direita
    // e para a esquerda
    bool dir = labtest.verifica_direcao_dir(x, y);
    bool esq = labtest.verifica_direcao_esq(x, y);
    bool baixo = labtest.verifica_direcao_baixo(x, y);
    bool cima = labtest.verifica_direcao_cima(x, y);
    ASSERT_EQ(dir, false); 
    ASSERT_EQ(esq, false);
    ASSERT_EQ(baixo, true);
    ASSERT_EQ(cima, true);
}


