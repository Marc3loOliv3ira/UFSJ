#include<stdio.h>
#include<stdlib.h>
int Melhor_Povo(int a, int b);//Funcao que retorna qual o maior Habilidadeor;
int Nave_Zork(int Capacidade, int Peso[], int Habilidade[], int Num_Itens);//Funcao Mochila
int Nave_Zork(int Capacidade, int Peso[], int Habilidade[], int Num_Itens)//Mochila Recebe: Capacidade->Capacidade Maxima Da Nave;
//Peso->Peso do Povo;Habilidade->Habilidade do Povo;->Num_Itens->Numero de Povos
{
	int i, j, cont; //variaveis ultilizadas para os laços
	int *aux;//Vetor que armazena o melhor valor Para a Mochila
	aux = calloc(Capacidade + 1, sizeof(int)); //Alocando espaço na Memoria Para Aux
	for (j = 0; j <= Capacidade; j++)  //Do j=0 ate j=Capacidade j recebe j+1
	{
		for (i = 0; i < Num_Itens; i++) //Do i=0 ate i=Num_Itens i recebe i+1
		{
			if(Peso[i] <= j) //Se Peso do meu item for menor do que a Capacidade j
			{
				aux[j] = Melhor_Povo(Habilidade[i] + aux[j - Peso[i]], aux[j]); //aux na posicao j Recebe
				cont++;
//max,verifica qual Maior Valor, habilidade do meu povo i + habilidade anterior ou minha habilidade j;
			}
		}
	}
	//printf("%d\n",aux[Capacidade]);
	return aux[Capacidade];
}
int Melhor_Povo(int a, int b) //Funçao que retorna maior valor
{
	if (a >= b)
	{
		return a;
	}
	else
	{

		return b;
	}


}
