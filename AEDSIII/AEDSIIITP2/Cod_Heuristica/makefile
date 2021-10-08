all: tp2 clean

tp2: Dinamico.o Grafo.h GrafoMundo.h Heuristica.h Tempo_Execucao.h
	gcc Dinamico.o -o tp2 -lm

Dinamico.o: Dinamico.c Grafo.h GrafoMundo.h Heuristica.h Tempo_Execucao.h
	gcc -c Dinamico.c -o Dinamico.o

clean:
	rm -rf *.o *~ printy
