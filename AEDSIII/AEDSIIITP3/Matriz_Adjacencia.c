#include"Grafo.h"
Grafo* cria_Grafo(int nro_vertices, int Max_Arestas)
{
  Grafo *gr;
  gr = (Grafo*) malloc(sizeof(struct grafo));//Aloca a Estrutura Grafo dentro de Um novo Ponteiro
  if(gr != NULL)// se nao Houver erro na alocacao
  {
    int i;
    gr->num_arestas = 0;
    gr->nro_vertices = nro_vertices;//Recebe o Numero de Vertices do grafo e guarda na estrutura
    gr->Max_Arestas = Max_Arestas;//Recebe o Grau Maximo ou seja o numero maximo de arestas
    gr->grau = (int*) calloc(nro_vertices, sizeof(int));//aloca espaco pro vetor grau
    gr->arestas = (int**) malloc(nro_vertices * sizeof(int*));//aloca espaco a matriz de arestas
    for(i = 0; i < nro_vertices; i++)
    gr->arestas[i] = (int*) calloc(Max_Arestas , sizeof(int));//para cada vertice vejo quantar arestas ele vai poder ter e aloco espaco para elas(inicializo-as com 0)
    return gr;//retorna o grafo criado
  }
}
void libera_Grafo(Grafo* gr){
  if(gr != NULL){//verifica se tem ou nao erro na alocacao
    int i;// libera o espaco as estruturas alocadas no grafo
    for(i = 0; i < gr->nro_vertices; i++)
    free(gr->arestas[i]);
    free(gr->arestas);
    free(gr->grau);
    free(gr);
  }
}

int insereAresta(Grafo* gr, int orig, int dest){
// informo o ponto de origem e o ponto de destino se é ou nao digrafo e o peso
  if(gr == NULL)//verifica se tem ou nao erro na alocacao e nao for valido retorna 0
  return 0;
  if(orig < 0 || orig >= gr->nro_vertices)//verifica se a origem eh um vertice valido
  return 0;
  if(dest < 0 || dest >= gr->nro_vertices)//verifica se o destino é um vertice valido
  return 0;
  gr->arestas[orig][dest] = 1;//adiciono o destino no ponto[origem][destino]
  gr->arestas[dest][orig] = 1;//adiciono o destino no ponto[origem][destino]
  gr->num_arestas++;
  gr->grau[orig]++;//a medida que o vertice vai tendo mais arestas vai aumentando o grau dele
  gr->grau[dest]++;//a medida que o vertice vai tendo mais arestas vai aumentando o grau dele
  return 1;
}
void Remove_Vertice(Grafo *gr,int vertice){//Remove o vertice
  for(int i=0; i< gr->nro_vertices; i++){//Remove a linha e a coluna do vertice e remove as arestas ligadas a ele e diminui o numero de arestas
    if(gr->arestas[vertice][i]){
      gr->num_arestas--;
      gr->arestas[vertice][i] = 0;
      gr->arestas[i][vertice] = 0;
    }
  }

}
void imprime_Grafo(Grafo *gr)
{
  if(gr == NULL) //se meu garfo for vazio
  return;//retorno pra funcao
  int i, j;
  for(i = 0; i < gr->nro_vertices; i++)
  {
    printf("%d:\n", i);//Printa o id do vertice
    for(j = 0; j < gr->nro_vertices; j++)
    {
      printf("[%d][%d]:%d\n",i,j,gr->arestas[i][j]);//Printa a aresta e o peso dela
    }
    printf("\n");
  }
  printf("\n");
}
int max(int a,int b){
  if(a>=b){
    return a;
  } else{
    return b;
  }
}
