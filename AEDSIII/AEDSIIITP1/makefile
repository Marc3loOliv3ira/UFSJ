all: executavel clean

executavel: arquivofinal.o LerArquivo.h xulambs.h
	gcc arquivofinal.o -o executavel -lm

arquivofinal.o: arquivofinal.c LerArquivo.h xulambs.h
	gcc -c arquivofinal.c -o arquivofinal.o

clean:
	rm -rf *.o *~ printy
