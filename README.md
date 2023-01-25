# Pac-Man no terminal

<p><b> Este programa tem como objetivo principal implementar uma versão mais simplificada do jogo Pac-Man baseando-se
em princípios de orientação a objetos (OO). Além disso, a compilação e a geração de documentação serão efetuadas
de forma automatizada por meio de um Makefile, e haverá testes unitários do jogo realizados com GoogleTest. </b></p>

## ✔️ Técnicas e tecnologias utilizadas

- ``C++``
- ``Makefile``
- ``Paradigma de orientação a objetos``

## 🔨 Como compilar e executar: 

```bash
make all MODO=jogo LABIRINTO=labirinto1
```
<p> OBS-> Existem 3 tabuleiros diferentes para jogar: labirinto1, labirinto2 e labirinto3. Para testar os outros labirintos, basta substituir sua numeração no comando. </p>



## :computer: Testes 
<p> Para compilar e executar os testes, é preciso escrever o seguinte comando: </p>

```bash
make tests MODO=testes 
```


## :open_file_folder: Gerar documentação e limpar os arquivos
<p> O comando a seguir é responsável por gerar a documentação. </p>

```bash
make doc 
```
<p> Para limpar todos os arquivos gerados na compilação e na geração da documentação, é 
preciso rodar o seguinte comando: </p>

```bash
make clean
```

<p><b> Observação: O jogo é uma versão bem mais simplificada do Pac-man original e a "morte" do Pacman
por um fantasma conta apenas quando o Pacman e o fantasma acabam caindo em uma mesma posição do labirinto.
Ainda é preciso aprimorar o código para que o jogo acabe quando o Pacman e algum fantasma atravessem caminhos.
</b></p>


