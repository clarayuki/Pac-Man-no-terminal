# Pac-Man no terminal

<p> <b> Este programa tem como objetivo principal implementar uma versão mais simplificada do jogo Pac-Man baseando-se
em princípios de orientação a objetos (OO). Além disso, a compilação e a geração de documentação serão efetuadas
de forma automatizada por meio de um Makefile, e haverá testes unitários do jogo realizados com GoogleTest. </b> </p>


COMO COMPILAR E EXECUTAR:
-> Para compilar e executar o programa (sem os testes), é preciso rodar o seguinte comando:

$ make all MODO=jogo LABIRINTO=<nome_do_arquivo_do_labirinto> 

Exemplo-> $ make all MODO=jogo LABIRINTO=labirinto1
OBS-> Existem 3 tabuleiros diferentes para jogar



TESTES:
-> Para compilar e executar o programa com os testes, é preciso escrever o seguinte comando:

$ make tests MODO=testes 



DETALHES À PARTE: 
-> Para gerar a documentação, é preciso rodar o seguinte comando:

$ make doc 

-> Para limpar todos os arquivos gerados na compilação e na geração da documentação, é 
preciso rodar o seguinte comando:

$ make clean



DEPENDÊNCIAS:
-> Versão do g++: (GCC) 12.2.1 20221121 (Red Hat 12.2.1-4).
-> Sistema Operacional -> Linux, sendo a distribuição utilizada "Nobara Linux versão 36 (KDE Plasma)".

