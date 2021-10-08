#include "Grafo.h"
int Heuristica_CVI(Grafo* gr){
  int *estados;//vetor que Armazena o estado do vertice
  int i,j,cont=0;
  estados = malloc(gr->nro_vertices * sizeof(int));
  for(i=0;i<gr->nro_vertices;i++){
    estados[i] = INICIAL;//define o estado de todos os vertices como INICIAL=0
  }
  for(i=0;i<gr->nro_vertices;i++){
    if (estados[i] == INICIAL){//se o estado do Vertice estiver como INICIAL=0
      cont++;//aumenta o contador em 1(conta vertices nao adjacentes)
      estados[i] = IS;//vertice na posicao i recebe IS()
      for(j=0;j<gr->nro_vertices;j++){//analisa os outros vertices na posicao j em relacao ao vertice i
        if(gr->arestas[i][j]){// se o vertice for adjacente ao vertice i
          estados[j] = NIS;//vertice na posicao j nao é independente i
        }
      }
    }

  }
  free(estados);
  return cont;//retorna maximo de vertices Independentes
}
