#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include"vetor.h"


void main(void)
{
	int tam, m; /* m varivável que recebe o tamanho do vetor para contar de forma
	decrescente */
	int *vet, n, opcao, i, aux, cont; // n é o indice do vetor.
	srand(time(NULL));
	double ti, tf, tempo; // ti = tempo inicial // tf = tempo final
	ti = tf = tempo = 0;
	struct timeval tempo_inicio, tempo_fim;


	int op;
	printf("\n MENU \n");
	printf("\n 1 - Ordenação por Seleção\n");
	printf("\n 2 - Ordenação por Inserção \n");
	printf("\n 3 - Shellsort \n");
	printf("\n 4 - QuickSort \n");
	printf("\n 5 - HeapSort\n");
	printf("\n 6 - MergeSort \n");
	printf("Opção: ");
	scanf("%d", &op);
	system("clear");
	printf("\nInforme o Tamanho do Vetor\n");
	printf("20\n");
	printf("500\n");
	printf("5000\n");
	printf("10000\n");
	printf("200000\n");
	scanf("%d", &tam);
	system("clear");
	vet = (int *) malloc(tam * sizeof(int));
	printf("\nInforme como deseja que o vetor esteja\n");
	printf("1-Aleatório\n");
	printf("2-Ordem Crescente\n");
	printf("3-Ordem Decrescente\n");
	scanf("%d", &opcao);
	switch(opcao)
	{
	case 1:
		for(n = 0; n < tam; n++)
		{
			vet[n] = (int) rand() % tam;
		}
		break;
	case 2:
		for(n = 0; n < tam; n++)
		{
			vet[n] = n;
		}
		break;
	case 3:
		for((m = tam - 1) && (n = 0); (m >= 0) && (n < tam); (m--) && (n++))
		{
			vet[n] = m;
		}
		break;
	default:
		break;

	}
	system("clear");
	switch(op)
	{
	case 1:
		gettimeofday(&tempo_inicio, NULL);/*Função que retorna o tempo em
		segundos e microsegundos */
		selecao(vet, tam);
		gettimeofday(&tempo_fim, NULL);

		free(vet);
		break;
	case 2:
		gettimeofday(&tempo_inicio, NULL);
		insercao(vet, tam);
		gettimeofday(&tempo_fim, NULL);
		free(vet);
		break;
	case 3:
		gettimeofday(&tempo_inicio, NULL);
		shell(vet, tam);
		gettimeofday(&tempo_fim, NULL);

		free(vet);
		break;
	case 4:
		gettimeofday(&tempo_inicio, NULL);
		quicksort(vet, tam);
		gettimeofday(&tempo_fim, NULL);
		free(vet);
		break;
	case 5:
		gettimeofday(&tempo_inicio, NULL);
		HeapSort(vet, tam);
		gettimeofday(&tempo_fim, NULL);

		free(vet);

		break;
	case 6:
		gettimeofday(&tempo_inicio, NULL);
		mergeSort(vet, 0, tam - 1);
		gettimeofday(&tempo_fim, NULL);
		free(vet);
		break;
	default:
		break;
	}
	// tempo de  início subtraído do tempo final
	tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
	ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));
	tempo = (tf - ti) / 1000;

	printf("\nTempo de execução: %.3f milisegundos\n\n", tempo);
	main();
}
