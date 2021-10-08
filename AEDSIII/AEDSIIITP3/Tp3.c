#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "Grafo.h"
#include "Tempo_Execucao.h"
#include "QTD_Caminhos.h"
int main(int argc, char *argv[]){

	Grafo *gr;//Ponteiro para um grafo
	int aux,aux1,h=0;//Salva os retornos das Heuristicas 1 e 2
	int k,opcao, habilit, habilit1;
	int Vertices, i, x, y, Caminhos;
	char *nomefileEntrada = NULL;// variavel que recebe o nome do arquivo.txt no getopt
	char *nomefileSaida = NULL;
	FILE *fp;
	opterr = 0;// Desativa as mensagens de erro da funcao getopt

	while ((opcao = getopt (argc, argv, "i:o:a b c")) != -1){
		switch (opcao){
			case 'i':// -i para passar o arquivo de entrada
			nomefileEntrada = optarg;// armazena nome do arquivo de entrada
			habilit = 1;//flag para o if de erro
			break;
			case 'o'://-o para passar o arquivo de saida
			nomefileSaida = optarg;//recebe o nome do arquivo de saida
			habilit1 = 1;
			break;
			case 'a'://-a para rodar o força bruta
			h=0;
			break;
			case 'b'://-b para rodar a 1ª heuristica
			h=1;
			break;
			case 'c'://-c para rodar a 2ª heuristica
			h=2;
			 break;
			case '?':
			printf("Erro nos argumentos passados para o getopt\n");
			break;
		}
	}

	if (habilit + habilit1 == 2){//Entra se as opções do -i"..." -o"..." estiverem da forma correta 

		double tempo_ini1, tempo_fim1,tempo_ini2, tempo_fim2,tempo_ini3, tempo_fim3;//variveis que armazenam o tempo que cada algoritmo inicia e é finalizado
		fp = fopen(nomefileEntrada, "rt");//Abre o arquivo passado pelo usuário apenas para leitura
		if(fp == NULL){//Verifica se o arquivo não está vazio
			printf("Arquivo vazio\n\n");
			return EXIT_FAILURE;
		}


		fscanf(fp, "%d ",&Vertices);//Primeiro número do arquivo = Numero maximo de vertices
		gr = cria_Grafo(Vertices,Vertices);//Número de vertices e numero maximo de arestas que cada vertice poderá ter
		Caminhos=NumLinha(nomefileEntrada);//Verifica quantas arestas serão criadas

		for(i = 0; i < Caminhos; i++){//Le o arquivo e cria o grafo inserindo cada aresta
			fscanf(fp,"%d %d\n", &x, &y);
			insereAresta(gr,x,y);
		}
		fclose(fp);
		//imprime_Grafo(gr);//verificar se o grafo está correto (caso necessário)
		fp = fopen(nomefileSaida, "a");
		if(h==0){
			tempo_ini1 = tempo_Execucao();//inicia a contagem do tempo de execucao(GETTIMEOFDAY)
					ConjuntoVerticesIndependentes(gr);
			tempo_fim1 = tempo_Execucao();//Tempo Final da execucao(GETTIMEOFDAY)
			fprintf(fp, "%d\n",gr->CVI_Max);
			printf("Forca_Bruta :   %lf segundos(GETTIMEOFDAY)\n", tempo_fim1 - tempo_ini1);
			}
		if(h==1){
			tempo_ini2 = tempo_Execucao();
				aux = Heuristica_CVI(gr);
			tempo_fim2 = tempo_Execucao();
			fprintf(fp, "Heuristica1_CVI : %d\n",aux);
			printf("1°-Heuristica : %lf segundos(GETTIMEOFDAY)\n", tempo_fim2 - tempo_ini2);
		}
		if(h==2){
			tempo_ini3 = tempo_Execucao();
				aux1 =Heuristica2_CVI(gr);
			tempo_fim3 = tempo_Execucao();
			fprintf(fp, "Heuristica2_CVI : %d\n",aux1);
			printf("2°-Heuristica : %lf segundos(GETTIMEOFDAY)\n", tempo_fim3 - tempo_ini3);

		}
		fclose(fp);//Fecha o arquivo
		tempo_sistema_usuario();
	}

	else{	//No caso de as instruções do -i"..." -o"..." estiverem incorretas
		printf("Leia as instrucoes e compile novamente\n");
	}

	libera_Grafo(gr);
	return 0;
}
