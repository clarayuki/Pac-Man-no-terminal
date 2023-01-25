/**
 * @file Partida.cpp
 * @author Clara Yuki Sano - 11809920
 * @date 10/12/2022
 *
 * Este arquivo contém as definições dos métodos da classe Partida.
 * Feito para o EP4 da matéria MAC0216 - Técnicas de Programação I no curso de Bacharelado de Ciência da 
 * Computação do Instituto de Matemática e Estatística da Universidade de São Paulo.
 */

#include "Partida.h"

/**************************************
 * Definição dos métodos.
 **************************************/

void Partida::imprime_tabuleiro () {

    char ** icones_tabuleiro = new char*[this->labirinto->get_linhas()];

    for (int i = 0; i < this->labirinto->get_linhas(); i++)
        icones_tabuleiro[i] = new char[this->labirinto->get_colunas()];

    // Coloca caracteres ' ', '.' e '*' no tabuleiro.
    for (int i = 0; i < this->labirinto->get_linhas(); i++) 
        for (int j = 0; j < this->labirinto->get_colunas(); j++)
            icones_tabuleiro[i][j] = Labirinto::icones_celulas[this->labirinto->get_celula(i, j)];
    
    // Coloca caracter 'F' nas posições onde existem fantasmas.
    for (int i = 0; i < this->numero_fantasmas; i++) {
        Posicao pos_fantasma = this->fantasmas[i].get_pos();
        icones_tabuleiro[pos_fantasma.y][pos_fantasma.x] = this->fantasmas[i].get_sprite();
    }

    Posicao pos_pacman = this->pacman->get_pos();
    icones_tabuleiro[pos_pacman.y][pos_pacman.x] = this->pacman->get_sprite();  // Coloca caracter 'C' onde o Pacman está.
    
    // Se o jogo acabar e o usuário perder, colocar um 'X' onde ocorreu a colisão entre Pacman e fantasma.
    if (this->jogo_acabou and this->perdeu)
        icones_tabuleiro[pos_pacman.y][pos_pacman.x] = 'X';

    // Imprimir o tabuleiro do labirinto.
    for (int i = 0; i < this->labirinto->get_linhas(); i++) {
        for (int j = 0; j < this->labirinto->get_colunas(); j++) {
            std::cout << icones_tabuleiro[i][j];
        }
        std::cout << std::endl;
    }
    
    // Liberar memória.
    for (int i = 0; i < this->labirinto->get_linhas(); i++)
        delete[] icones_tabuleiro[i];
    delete[] icones_tabuleiro;
}

bool Partida::verifica_colisao () {

    Posicao pos_pacman = this->pacman->get_pos();
    for (int i = 0; i < this->numero_fantasmas; i++) {
        Posicao pos_fantasma = this->fantasmas[i].get_pos();
        if (pos_pacman.x == pos_fantasma.x and pos_pacman.y == pos_fantasma.y)
            return true;
    }
    return false;
}

void Partida::turnos () {

    int total_pac_dots = this->labirinto->get_pac_dots(); // Guardar o total de pac-dots no início do jogo.
    bool dir1, esq2, baixo3, cima4 = false;  // Setar booleanos de direção como falsos (serão usados na movimentação dos fantasmas).

    // Enquanto o jogo não terminar
    while (not this->jogo_acabou) {

        this->imprime_tabuleiro(); // Imprime tabuleiro na condição atual do jogo.

        // Movimenta fantasmas aleatoriamente.
        for (int i = 0; i < this->numero_fantasmas; i++) { 
            Posicao pos_atual = this->fantasmas[i].get_pos();
            // Verifica quais direções o fantasma pode seguir.
            dir1 = this->labirinto->verifica_direcao_dir(pos_atual.x, pos_atual.y);
            esq2 = this->labirinto->verifica_direcao_esq(pos_atual.x, pos_atual.y);
            baixo3 = this->labirinto->verifica_direcao_baixo(pos_atual.x, pos_atual.y);
            cima4 = this->labirinto->verifica_direcao_cima(pos_atual.x, pos_atual.y);
            Posicao direcao = this->fantasmas[i].get_move(dir1, esq2, baixo3, cima4);  // Pega uma movimentação do fantasma.
            this->fantasmas[i].move(direcao.x, direcao.y, this->labirinto->get_colunas(), this->labirinto->get_linhas());  // Move o fantasma.
        }

        Posicao direcao = this->pacman->get_move();  // Pega a movimentação do Pacman de acordo com o input do usuário.
        Posicao pos_atual = this->pacman->get_pos(); // Pega a posição atual do Pacman.

        // Enquanto a movimentação for inválida, continuar pedindo movimentação para o usuário.
        while (not this->labirinto->verifica_pos(pos_atual.y + direcao.y, pos_atual.x + direcao.x)) 
            direcao = this->pacman->get_move();
        this->pacman->move(direcao.x, direcao.y, this->labirinto->get_colunas(), this->labirinto->get_linhas());  // Move o Pacman.

        // Verifica se pacman colidiu com a algum fantasma 
        if (this->verifica_colisao()) {  
            this->jogo_acabou = true;
            this->perdeu = true;
            continue;
        } 
        
        pos_atual = this->pacman->get_pos();  // Pega a posição nova do Pacman.

        if (this->labirinto->come_pac_dot(pos_atual.y, pos_atual.x)) {  // Se o Pacman comeu um pac-dot.
            this->pac_dots++;  // Incrementa a quantidade de pac-dots comidos nesta partida.
            this->labirinto->set_pac_dots(this->labirinto->get_pac_dots() - 1);  // Diminui a quantidade de pac-dots existentes no labirinto em 1.
        }

        if (this->ganhou_partida())
            this->jogo_acabou = true;
        
        std::cout << std::endl;
            
    }

    this->imprime_tabuleiro();

    if (this->perdeu)
        std::cout << "Game over! Pontos = " << this->pac_dots << std::endl;
    else
        std::cout << "Congratulations! Pontos = " << total_pac_dots << std::endl;
}

bool Partida::ganhou_partida () {
    if (this->labirinto->get_pac_dots() == 0)
        return true;
    return false;
}    

Partida::Partida (std::string nome_arquivo) {

    Arquivo arquivo = Arquivo(nome_arquivo);
    this->labirinto = new Labirinto(&arquivo);
    int linhas = this->labirinto->get_linhas();
    int colunas = this->labirinto->get_colunas();
    int x_ini_pacman = colunas / 2;
    int y_ini_pacman = linhas / 2;
    this->pacman = new Pacman(x_ini_pacman, y_ini_pacman);  // Posição inicial do Pacman: no meio do tabuleiro.
    int conta_fantasmas = 0;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (arquivo.get_posicao(i, j) == 'F')
                conta_fantasmas++;
        }
    }

    this->numero_fantasmas = conta_fantasmas;
    this->fantasmas = new Fantasma[conta_fantasmas];  // Array de fantasmas.
    int indice_fantasmas = 0;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (arquivo.get_posicao(i, j) == 'F') {
                this->fantasmas[indice_fantasmas] = Fantasma (j, i);
                indice_fantasmas++;
            }
        }
    }
}

Partida::~Partida () {
    delete this->labirinto;
    delete this->pacman;
    delete[] this->fantasmas;
}

void Partida::iniciar_partida () {
    this->turnos();
}

