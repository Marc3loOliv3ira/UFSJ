#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "registropeq.h" // Arquivo que contém as ordenações 

int main()
{
	int i, n, opcao, m;
	srand(time(NULL));
	int tam ;
	struct RegistroPequeno *vet;
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
	printf("\n 0 - Sair \n");
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
	vet = (struct RegistroPequeno*)malloc(tam * sizeof(struct RegistroPequeno));
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
			vet[n].Chave = (int) rand() % tam;
		}
		break;
	case 2:
		for(n = 0; n < tam; n++)
		{
			vet[n].Chave = n;
		}
		break;
	case 3:
		for((m = tam - 1) && (n = 0); (m >= 0) && (n < tam); (m--) && (n++))
		{
			vet[n].Chave = m;
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
		selecaopeq(vet, tam);
		gettimeofday(&tempo_fim, NULL);

		break;
	case 2:
		gettimeofday(&tempo_inicio, NULL);
		insercaopeq(vet, tam);
		gettimeofday(&tempo_fim, NULL);

		free(vet);
		break;
	case 3:
		gettimeofday(&tempo_inicio, NULL);
		shellpeq(vet, tam);
		gettimeofday(&tempo_fim, NULL);

		free(vet);
		break;
	case 4:
		gettimeofday(&tempo_inicio, NULL);
		quicksortpeq(vet, tam);
		gettimeofday(&tempo_fim, NULL);

		free(vet);
		break;
	case 5:
		gettimeofday(&tempo_inicio, NULL);
		HeapSortpeq(vet, tam);
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
