#include <stdio.h>
#include <stdlib.h>

int NumLinha(char *arquivo)
{
  FILE *arqXulambs;
  int numLinhas=0;
  char x;//variavel para armazenar caracter por caracter do arquivo
  arqXulambs = fopen(arquivo,"rt");
  if(arqXulambs == NULL){
    printf("O Arquivo de Texto Esta Vazio\n");
    return 1;
  }
  while (!feof(arqXulambs))
  {
      x = fgetc(arqXulambs);
      if (x == '\n'){//se tiver uma quebra de linha no arquivo conta mais um
        numLinhas++;
      }
  }
  fclose(arqXulambs);
  return numLinhas - 1;//retorna o numero de caminhos que é a quantidade de quebra de linhas - a linha contendo o vertice
}
