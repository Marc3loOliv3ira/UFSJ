
#include<stdio.h>
#include <stdlib.h>
#include<math.h>
void Ordena(float *a, int left, int right);
int Nave_Zork(int Capacidade, int Peso[], int Habilidade[], int Num_Itens);
int Nave_Zork(int Capacidade, int Peso[], int Habilidade[], int Num_Itens)
{
	int valor = 0, i, aux4;
	float *aux, aux1, aux2, aux3;
// Aqui Divide A capacidade Pelo Peso e multiplico o valor pela Habilidade
//Depois ordena do menor pro maior valor e retorna para a funcao
	aux = calloc(Num_Itens, sizeof(float));
	for (i = 0; i < Num_Itens ; i++)
	{
		aux1 = Capacidade;
		aux2 = Peso[i];
		aux3 = Habilidade[i];
		aux4 = aux1 / aux2;
		round(aux4);
		aux[i] = aux4 * aux3;
	}
	Ordena(aux, 0, Num_Itens);
	valor = aux[Num_Itens];
	return valor;
}
void Ordena(float *a, int left, int right)  //funçao Para Ordenar os valores que a Mochila Inteira retorna
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
		Ordena(a, left, j);
	}
	if(i < right)
	{
		Ordena(a, i, right);
	}
}
