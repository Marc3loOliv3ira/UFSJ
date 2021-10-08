#include<stdio.h>
#include<stdlib.h>
//Declara��o das fun��es
void selecao(int *item , int count);
void insercao(int *item , int count);
void shell(int *item , int count);
void quicksort(int *item , int count);
void qs(int *item , int left, int right);
void heapsort (int tam, int *item);
void mergeSort(int *vetor, int posicaoInicio, int posicaoFim);
/*Fun��o que utiliza o algoritmo de ordena��o por sele��o que consiste em
selecionar o menor item e colocar na primeira posi��o, selecionar o segundo
menor item e colocar na segunda posi��o, seguindo esses passos at� que reste
apenas um elemento*/
void selecao(int *item , int count)
{
	int a, b , c, min, contmove = 0, contcomp = 0;
	for (a = 0; a <= count - 1; ++a)
	{

		min = a;
		for(b = a + 1; b < count; ++b)
		{

			if(item[b] < item[min])
			{
				contcomp += 1;
				min = b;
			}
		}
		contmove += 1;
		c = item[min];
		item[min] = item[a];
		item[a] = c;
	}
	

}
/*Fun��o que utiliza o algoritmo de ordena��o por inser��o que consiste em
percorrer um vetor de elementos da esquerda para a direita e � medida que avan�a
vai ordenando os elementos � esquerda */
void insercao(int *item, int count)
{
	int a , b, contmove = 0, contcomp = 0;
	int t;
	for (a = 1; a < count; ++a)
	{
		t = item[a];
		for (b = a - 1; b >= 0 && t < item[b]; b--)
		{
			contcomp += 1;

			item [b + 1] =  item[b];
		}
		item [b + 1] = t;
		contmove += 1;
	}

	/* Em cada passo, a partir do segundo elemento seleciona o pr�ximo item
	da sequ�ncia e o coloca no local apropriado de acordo com o crit�rio de
	ordena��o */
	
}
/* Fun��o que utiliza o algoritmo de ordena��o ShellSort que consiste em,
basicamente um tipo de inser��o, por�m, separando em grupos menores e os
ordenando, para no fim, ordenar todo o vetor*/
void shell (int *item , int count)
{
	int i , j, contmove = 0, contcomp = 0 , k, gap = 1;
	while(gap < count)
	{
		gap = 3 * gap + 1;
	}
	while ( gap > 1)
	{
		gap /= 3;
		for(i = gap; i < count; i++)
		{
			k = item[i];
			j = i - gap;
			while (j >= 0 && k < item[j])
			{
				contcomp += 1;
				item [j + gap] = item[j];
				j -= gap;
			}
			contmove += 1;
			item [j + gap] = k;
		}
	}
	/* A ordena��o Shell utiliza a quebra sucessiva da sequ�ncia a ser ordenada
	 e implementa a ordena��o por inser��o na sequ�ncia obtida.*/

}
/* Fun��o que utiliza o m�todo de ordena��o QuickSort que consiste em dividir
o problema de ordenar um conjunto com n itens em dois problemas menores. Dessa
forma, os problemas menores s�o ordenados de forma independente e os resultados
s�o combinados para produzir a solu��o final */
void quicksort(int *item , int count)
{
	qs(item, 0, count - 1);
}
void qs(int *item , int left , int right)
{
	int i, j, contmove = 0, contcomp = 0;
	char x , y;
	i = left;
	j = right;
	x = item[(left + right) / 2];
	do
	{
		while (item[i] < x && i < right) i++;
		while (x < item[j] && j > left) j--;
		if (i <= j)
		{
			contcomp += 1;
			contmove += 1;
			y = item[i];
			item[i] = item[j];
			item[j] = y;
			i++;
			j--;

		}
	}
	while(i <= j);
	if ( left < j)
	{
		contcomp += 1;
		qs(item, left, j);
	}
	if (i < right)
	{
		contcomp += 1;
		qs (item, i, right);
	}
	/* Divide a lista de entrada em duas sub-listas a partir de um piv�, em
	seguida realiza o mesmo procedimento nas duas listas menores at� sobrar
	apenas uma lista unit�ria*/
	
}
//Conjunto de Fun��es que constroem o m�todo de ordena��o HeapSort
/*enquanto o valor de um filho for maior que o de seu pai: troque os valores de
pai e filho e suba um passo em dire��o � raiz */
void constroiHeap( int *item, int count, int indice_raiz )
{
	int ramificacao, valor;
	valor = item[indice_raiz];
	while(indice_raiz <= count / 2)
	{
		ramificacao = 2 * indice_raiz;
		if(ramificacao < count && item[ ramificacao ] < item[ramificacao + 1])
			ramificacao++;
		if( valor >= item[ramificacao] )
//Identifica o max-heap
			break;
		item[indice_raiz] = item[ramificacao];
		indice_raiz = ramificacao;
	}
	item[indice_raiz] = valor;
}
/*Fun��o que utiliza o m�todo de ordena��o HeapSort que enxerga o vetor como
uma �rvores bin�ria, um vetor em que o valor de todo pai � maior ou igual ao
 valor de cada um de seus dois filhos*/
void HeapSort( int *item, int count )
{
	int indice, troca, contmove = 0, contcomp = 0;
	for( indice = count / 2; indice >= 0; indice--)
		constroiHeap( item, count, indice );
	while( count > 0 )
	{
		contcomp += 1;
		contmove += 1;
		troca = item[0];
		item[0] = item[count];
		item[count] = troca;
		constroiHeap(item, --count, 0);
	}
	/*	O algoritmo tem duas fases: a primeira transforma o vetor em heap e a
	segunda rearranja o heap em ordem */

}
/* Fun��o que utiliza o m�todo de ordena��o MergeSort que consiste em dividir
o problema em peda�os menores e depois juntar (merge) os resultados obtidos. O
vetor � divido em duas partes iguais, que ser�o, cada uma, divididas em duas
partes, e assim at� sobrar um ou dois elementos cuja ordena��o � trivial. */
void mergeSort(int *vetor, int posicaoInicio, int posicaoFim)
{
	int i, j, k, metadeTamanho, *vetorTemp, contmove = 0, contcomp = 0;
	if(posicaoInicio == posicaoFim) return;
	metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

	mergeSort(vetor, posicaoInicio, metadeTamanho);
	mergeSort(vetor, metadeTamanho + 1, posicaoFim);

	i = posicaoInicio;
	j = metadeTamanho + 1;
	k = 0;
	vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

	while(i < metadeTamanho + 1 || j  < posicaoFim + 1)
	{
		contcomp += 1;
		if (i == metadeTamanho + 1 )
		{
			contmove += 1;
			vetorTemp[k] = vetor[j];
			j++;
			k++;
		}
		else
		{
			if (j == posicaoFim + 1)
			{
				contmove += 1;
				vetorTemp[k] = vetor[i];
				i++;
				k++;
			}
			else
			{
				contmove += 1;
				if (vetor[i] < vetor[j])
				{
					vetorTemp[k] = vetor[i];
					i++;
					k++;
				}
				else
				{
					contmove += 1;
					vetorTemp[k] = vetor[j];
					j++;
					k++;
				}
			}
		}

	}
	for(i = posicaoInicio; i <= posicaoFim; i++)
	{
		contcomp += 1;
		contmove += 1;
		vetor[i] = vetorTemp[i - posicaoInicio];
	}
	/*Para juntar as partes ordenadas os dois elementos de cada parte s�o separados
	e o menor deles � selecionado e retirado de sua parte. Em seguida, os menores
	entre os restantes s�o comparados e assim prossegue at� juntar todas as partes*/
	free(vetorTemp);
	
}
