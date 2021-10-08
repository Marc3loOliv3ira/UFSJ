#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "Grafo.h"
#include "Heuristica.h"
#include "GrafoMundo.h"
#include "tempo_Execucao.h"

int main(int argc, char *argv[])
{
	Grafo *gr; //variavel ponteiro para o grafo
	int *vetpeso, *vethab, *vetPrint; // um vetor Para o Peso dos Povos e a habilidade dos povos
	int eh_digrafo = 0;
	int *auxiliar;
	char auxiliar1[256]; //variavel auxiliar para salvar o nome do arquivo que ser? aberto.
	char auxiliar2[256];
	int k, l, opcao, habilit, habilit1;
	int Vertices, i, x, y, Caminhos, Dist, instancias, Peso_Nave, id;
	float Distancia;

	char *nomefileEntrada = NULL;// variavel que recebe o nome do arquivo.txt no getopt
	char *nomefileSaida = NULL;
	opterr = 0;//// Desativa as mensagens de erro da funcao getopt
	while ((opcao = getopt (argc, argv, "i:o:")) != -1)
	{
		switch (opcao)
		{
		case 'i':
			nomefileEntrada = optarg;
			habilit = 1;
			break;
		case 'o':
			nomefileSaida = optarg;
			habilit1 = 1;
			break;

		case '?':
			printf("erro nos argumentos passados para o getopt\n");
			break;
		}
	}
	if (habilit + habilit1 == 2)
	{
		double tempo_ini, tempo_fim; //varivel q armazena o inicio e o fim do tempo em que o codigo foi executado
		sprintf(auxiliar1, nomefileEntrada, atoi(argv[1]));// a variavel auxiliar recebe o nome do arquivo de entrada passado no getopt
		sprintf(auxiliar2, nomefileSaida, atoi(argv[1]));
		FILE *fp = fopen(auxiliar1, "rt");
		if(fp == NULL)
			return EXIT_FAILURE;
		tempo_ini = tempo_Execucao();// chama da funcao tempo de execucao.
		fscanf(fp, "%d\n", &instancias);
		vetPrint = calloc(instancias, sizeof(int));
		for(k = 0; k < instancias; k++)
		{
			fscanf(fp, "%d %f %d %d\n", &Vertices, &Distancia, &Peso_Nave, &Caminhos);
			vetpeso = malloc(Vertices * sizeof(int));//aloca espaco um vetor para ler o Peso do Povo
			vethab = malloc(Vertices * sizeof(int));//aloca um espaco vetor para ler o habilidade do Povo
			auxiliar = malloc(Vertices * sizeof(int));//aloca espaco para um Vetor para receber os valores da mochila

			for(i = 0; i < Vertices; i++)
			{
				fscanf(fp, "%d %d %d \n", &id, &vetpeso[i], &vethab[i]);
				gr = cria_Grafo(Vertices, Vertices);
			}
			for(i = 0; i < Caminhos; i++)
			{
				fscanf(fp, "%d %d %d\n", &x, &y, &Dist);
				insereAresta(gr, x - 1, y - 1, eh_digrafo, Dist);
			}

			int vis[Vertices];
			for(i = 0; i < Vertices; i++)
			{
				l = 0;
				buscaProfundidade_Grafo(gr, i, vis, Caminhos, Distancia, Peso_Nave, vetpeso, vethab, l);
				auxiliar[i] = Nave_Zork(Peso_Nave, gr->Peso_Povo, gr->Hab_Povo, Vertices);
			}
			quick_sort(auxiliar, 0, Vertices);
			vetPrint[k] = auxiliar[Vertices];
			printf("%d\n", vetPrint[k]);
		}
		fclose(fp);
		tempo_fim = tempo_Execucao();
		fp = fopen(auxiliar2, "a");
		for(i = 0; i < instancias; i++)
		{
			fprintf(fp, "%d\n", vetPrint[i]);
		}
		fclose(fp);
		tempo_sistema_usuario();
		printf("Tempo de execucao : %lf segundos(GATTIMEOFDAY)\n", tempo_fim - tempo_ini);
		free(auxiliar);
		free(vetPrint);
	}
	else
	{
		printf("Leia as instrucoes e compile novamente\n");
	}
	libera_Grafo(gr);
	free(vetpeso);
	free(vethab);
	return 0;
}
