all:
	g++ teste.cpp -o teste -lfann -lm -Wall -O2
	g++ treinamento.cpp -o treinamento -lfann -lm -Wall -O2
