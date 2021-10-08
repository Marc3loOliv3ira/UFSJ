#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
struct grafo
{
	int *Peso_Povo;
	int *Hab_Povo;
	int nro_vertices;
	int Max_Arestas;
	int** arestas;
	float** Distancia;
	int* grau;
};

Grafo* cria_Grafo(int nro_vertices, int Max_Arestas)
{
	Grafo *gr;
	gr = (Grafo*) malloc(sizeof(struct grafo)); //Aloca a Estrutura Grafo dentro de Um novo Ponteiro
	if(gr != NULL) // se nao Houver erro na alocacao
	{
		int i;
		gr->Peso_Povo = (int*) calloc(Max_Arestas, sizeof(int));
		gr->Hab_Povo = (int*) calloc(Max_Arestas, sizeof(int));
		gr->nro_vertices = nro_vertices;//Recebe o Numero de Vertices do grafo e guarda na estrutura
		gr->Max_Arestas = Max_Arestas;//Recebe o Grau Maximo ou seja o numero maxim o de arestas
		gr->grau = (int*) calloc(nro_vertices, sizeof(int)); //cria o vetor grau
//Aqui Armazena se esta Conectado ao vertice ou nao
		gr->arestas = (int**) malloc(nro_vertices * sizeof(int*));//cria a matriz d arestas
		for(i = 0; i < nro_vertices; i++)
			gr->arestas[i] = (int*) malloc(Max_Arestas * sizeof(int));//pada cada vertice vejo quantar arestas ele vai poder ter
		//Aqui Armazena o Peso
		gr->Distancia = (float**) malloc(nro_vertices * sizeof(float*));
		for(i = 0; i < nro_vertices; i++)
			gr->Distancia[i] = (float*) malloc(Max_Arestas * sizeof(float));
	}

	return gr;//retorna o grafo criado
}
void libera_Grafo(Grafo* gr)
{
	if(gr != NULL)  //verifica se tem ou nao erro na alocacao
	{
		int i;
		//basicamente aqui libera as estruturas alocadas
		//tanto a matriz conectados
		for(i = 0; i < gr->nro_vertices; i++)
			free(gr->arestas[i]);
		free(gr->arestas);

		//quanto a matriz Distancia
		for(i = 0; i < gr->nro_vertices; i++)
			free(gr->Distancia[i]);
		free(gr->Distancia);
		free(gr->grau);
		free(gr);
	}
}
//funcao para inserir arestas
int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso)
{
	// informo o ponto de origem e o ponto de destino se é ou nao digrafo e o peso
	if(gr == NULL)//verifica se tem ou nao erro na alocacao e nao for valido retorna 0
		return 0;
	if(orig < 0 || orig >= gr->nro_vertices)//verifica se a origem eh um vertice valido
		return 0;//se nao for retorna 0
	if(dest < 0 || dest >= gr->nro_vertices)//verifica se o destino é um vertice valido
		return 0;//se nao retorna 0

	gr->arestas[orig][gr->grau[orig]] = dest;//adiciono o destino no ponto[origem][destino]
	gr->Distancia[orig][gr->grau[orig]] = peso;//adiciona o peso no ponto
	gr->grau[orig]++;//somo mais um no grau da origem

	if(eh_digrafo == 0)
		insereAresta(gr, dest, orig, 1, peso); //insere a aresta de volta se nao for digrafo
	return 1;
}

void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont, int Caminhos, float aux, float Distancia, int Capacidade, int *P_Povo, int *H_Povo, int j)
{
	int i;
	visitado[ini] = cont;//meu vertice inicial foi visitado
	for(i = 0; i < gr->grau[ini]; i++) //percorre todas as arestas q partendo do vertice
	{
		if(!visitado[gr->arestas[ini][i]]) //verifica se o vertice proximo ao vertice inicial foi ou nao visitado
		{
			aux = aux + gr->Distancia[ini][i];
			if(aux <= Distancia)
			{
				//  printf("(%.0f) ",aux);
				gr->Peso_Povo[j] = P_Povo[gr->arestas[ini][i]];
				gr->Hab_Povo[j] = H_Povo[gr->arestas[ini][i]];
				//  printf("%d-> ",gr->arestas[ini][i]+1);
				buscaProfundidade(gr, gr->arestas[ini][i], visitado, cont + 1, Caminhos, aux, Distancia, Capacidade, P_Povo, H_Povo, j + 1); //chamo a busca em profundidade
			}
			else
			{
				buscaProfundidade(gr, gr->arestas[ini][i], visitado, cont + 1, Caminhos, aux, Distancia, Capacidade, P_Povo, H_Povo, j + 1); //chamo a busca em profundidade
			}
		}
		else
		{
			break;
		}
	}
}

void buscaProfundidade_Grafo(Grafo *gr, int ini, int *visitado, int Caminhos, float Distancia, int Capacidade, int *P_Povo, int *H_Povo, int j)
{
	int auxiliar;
	int i, cont = 1;
	float aux = 0;
	for(i = 0; i < gr->nro_vertices; i++)
		visitado[i] = 0;//Marca Todos Os vertices como nao visitados
	gr->Peso_Povo[j] = P_Povo[ini];
	gr->Hab_Povo[j] = H_Povo[ini];
	buscaProfundidade(gr, ini, visitado, cont, Caminhos, aux, Distancia, Capacidade, P_Povo, H_Povo, j + 1);

}
void quick_sort(int *a, int left, int right)  //funçao Para Ordenar os valores que a Mochila Inteira retorna
{
	//Para saber qual é o Maior
	int i, j;
	float x, y;
	i = left;
	j = right;
	x = a[(left + right) / 2];
	while(i <= j)
	{
		while(a[i] < x && i < right)
		{
			i++;
		}
		while(a[j] > x && j > left)
		{
			j--;
		}
		if(i <= j)
		{
			y = a[i];
			a[i] = a[j];
			a[j] = y;
			i++;
			j--;
		}
	}
	if(j > left)
	{
		quick_sort(a, left, j);
	}
	if(i < right)
	{
		quick_sort(a, i, right);
	}
}
