all:
	@g++ -I. ep4.cpp Arquivo.cpp Partida.cpp Pacman.cpp Fantasma.cpp Personagem.cpp Labirinto.cpp -o main -lgtest -lpthread
	@./main $(MODO) $(LABIRINTO)

doc:
	@doxygen -g Doxyfile
	@doxygen Doxyfile

clean:
	@rm main Doxyfile
	@rm -r html latex

tests:
	@g++ -I. ep4.cpp Arquivo.cpp Partida.cpp Pacman.cpp Fantasma.cpp Personagem.cpp Labirinto.cpp -o main -lgtest -lpthread
	@./main $(MODO)