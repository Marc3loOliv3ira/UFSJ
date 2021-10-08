#include "Grafo.h"
int ConjuntoVerticesIndependentes(Grafo* gr){
  int i,j,aux;
  int* conjunto;//vetor para um conjunto de numeros independentes
  gr->CVI_Max = 0;//armazena o maximo de vertices independentes no grafo
  conjunto = malloc(gr->nro_vertices*sizeof(int));
  for(i=0;i<gr->nro_vertices;i++){
    CriaConjunto(gr,i,1,conjunto);//chama a funaco que ira criar o Conjunto
  }
  free(conjunto);
}
int CriaConjunto(Grafo* gr, int vertice,int cont,int* conjunto){
  int j,i,flag;

  if(cont>gr->nro_vertices){//condicao de parada
    return 0;
  }
  conjunto[cont-1] = vertice;//conjunto na posicao cont - 1 recebe o vertice
  if(TestaIndependentes(gr,conjunto,cont)){//se o vertice for independente
    gr->CVI_Max = max(gr->CVI_Max,cont);//testo qual é maior o valor que tinha no CVI_Max ou a nova quantidae de vertices independentes
  }
  for (j=0;j<gr->nro_vertices;j++){
    flag = 0;// coloca uma bandeira para testar os vertices
    for (i=0;i<cont;i++){
      if(conjunto[i] == j){//testa se vertice que esta contido no conjunto na posicao i e igual a j
        flag =1;//se for a bandeira sera igual a um (o vertice ja esta contido no conjunto)
      }
    }
    if(!flag)//onde a bandeira for igual a zero vejo se o vertice nao é adjacente se nao for adiciono no meu conjunto
    if(gr->arestas[vertice][j] == 0){//se o vertice na posicao [vertice] nao for adjacente ao vertice na posicao [j]
      CriaConjunto(gr,j,cont+1,conjunto);//adiciono mais um vertice no meu conjun to de numeros independentes
    }

  }

}
int TestaIndependentes(Grafo* gr,int* conjunto,int TAM){//testa o conjunto para ver se os vertices sao independentes
  int i,j;
  for(i=0;i<TAM;i++){
    for(j=i;j<TAM;j++){
      if (gr->arestas[conjunto[i]][conjunto[j]]){//Testa se Existe aresta entre vertices
        return FALSE;// se existe retorna 0
      }
    }
  }
  return TRUE;//se nao existe retorna 1
}
