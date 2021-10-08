all: tp3 clean

tp3: Tp3.o Matriz_Adjacencia.o Forca_Bruta.o Heuristica1_CVI.o Heuristica2_CVI.o Grafo.h Tempo_Execucao.h 
	gcc -o tp3 Tp3.o Matriz_Adjacencia.o Forca_Bruta.o Heuristica1_CVI.o Heuristica2_CVI.o -lm

Matriz_Adjacencia.o: Matriz_Adjacencia.c
	gcc -c Matriz_Adjacencia.c

Forca_Bruta.o:Forca_Bruta.c
	gcc -c Forca_Bruta.c

Heuristica1_CVI.o: Heuristica1_CVI.c
	gcc -c Heuristica1_CVI.c

Heuristica2_CVI.o: Heuristica2_CVI.c
	gcc -c Heuristica2_CVI.c

Tp3.o: Tp3.c Grafo.h Tempo_Execucao.h 
	gcc -g -c Tp3.c -o Tp3.o

clean:
	rm -rf *.o
rmproper: clean
	rm -rf tp3

run: tp3
	./tp3
