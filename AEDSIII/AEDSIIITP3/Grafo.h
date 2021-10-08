#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define INICIAL 0
#define IS 1
#define NIS 2
struct grafo//estrutura que armazena os dados do Grafo;
{
	int nro_vertices;
	int Max_Arestas;
	int CVI_Max;
	int** arestas;
	int* grau;
	int num_arestas;
};
typedef struct grafo Grafo;

Grafo* cria_Grafo(int nro_vertices, int Max_Arestas);//Funcao cria um grafo com o Numero de Vertices e arestas Informados

void libera_Grafo(Grafo* gr);//Funcao que libera os espacos das esturturas utilizados para criar o grafo

void imprime_Grafo(Grafo *gr);//Funcao utilizada Para verificar se o Grafo esta correto(Printa Grafico na Tela)

int insereAresta(Grafo* gr, int orig, int dest);//Funcao que insere as arestas nos pontos que possuem ligacao de um vertice a outro

int ConjuntoVerticesIndependentes(Grafo* gr);//Funcao que inicia o CVI utilizado no ForcaBruta

int CriaConjunto(Grafo* gr, int vertice,int cont,int* conjunto);//Funcao que Cria o conjunto de vertices Para o CVI e retorna a maior quantidade de Vertices independentes

int TestaIndependentes(Grafo* gr,int* conjunto,int TAM);//Funcao que Testa se os Vertices do Conjunto sao independentes

int max(int a,int b);//Funcao que testa qual é o maior entre dois numeros

int Heuristica_CVI(Grafo* gr);//Heuristica Baseada em um vetro de Estados que define o estado de cada vertice e retorna o CVI

int Heuristica2_CVI(Grafo* gr);//Heuristica Baseada no Grau do vertice e ordem de prioridade

void Remove_Vertice(Grafo* gr,int posicao);//Funcao que remove um vertice do grafo(retira linha e coluna dos vertices)
