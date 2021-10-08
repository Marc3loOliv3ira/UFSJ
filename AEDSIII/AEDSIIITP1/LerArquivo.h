	#include <stdio.h>
	#include <stdlib.h>
	
	int NumLinha()
	{
	FILE *arqXulambs;
	int numLinhas=0;
	char x;
	arqXulambs = fopen("series.txt","rt");
	if(arqXulambs == NULL){
	  printf("O Arquivo de Texto Esta Vazio\n");
	  return 1;
	}
	  while (!feof(arqXulambs))
	  {
	x = fgetc(arqXulambs);
	if (x == '\n'){
	  numLinhas++;
	}
	  }
	  fclose(arqXulambs);
	  return numLinhas;
	}
