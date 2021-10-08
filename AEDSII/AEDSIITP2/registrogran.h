#include<stdio.h>
#include<stdlib.h>
// Criando um registro grande
struct Registrogrande
{
	int Chave;
	char dados[50][50]; //50 campos com strings de 50 caracteres al�m da chave
}; // Declara��o das Fun��es
void selecaogran(struct Registrogrande *item, int count);
void insercaogran(struct Registrogrande *item, int count);
void quicksortgran(struct Registrogrande *item , int count);
void qs(struct Registrogrande *item , int left , int right);
void constroiHeap(struct Registrogrande *item, int count, int indice_raiz );
void HeapSortgran( struct Registrogrande *item, int count );
void mergeSortgran(struct Registrogrande *vetor, int posicaoInicio, int posicaoFim);
/*Fun��o que utiliza o algortimo de ordena��o por sele��o que consiste em
selecionar o menor item e colocar na primeira posi��o, selecionar o segundo
menor item e colocar na segunda posi��o, seguindo esses passos at� que reste
apenas um elemento*/
void selecaogran(struct Registrogrande *item, int count)
{
	// define um ponteiro para struct Registrogrande
	int a, b , min, contmove = 0, contcomp = 0;
	struct Registrogrande c;
	for (a = 0; a <= count - 1; ++a)
	{
		min = a;
		for(b = a + 1; b < count; ++b)
		{
			if(item[b].Chave < item[min].Chave)
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
void insercaogran(struct Registrogrande *item, int count)
{
	//Define um ponteiro para RegistroGrande
	int a , b, contmove = 0, contcomp = 0;
	struct Registrogrande t;
	for (a = 1; a < count; ++a)
	{
		t = item[a];
		for (b = a - 1; b >= 0 && t.Chave < item[b].Chave; b--)
		{
			contcomp += 1;
			item [b + 1] =  item[b];
		}
		contmove += 1;
		item [b + 1] = t;
	}
	/* Em cada passo, a partir do segundo elemento seleciona o pr�ximo item
	da sequ�ncia e o coloca no local apropriado de acordo com o crit�rio de
	ordena��o */
	printf("\nN�mero de compara��es: %d\n", contcomp);
	printf("\nN�mero de movimenta��es: %d\n", contmove);
}
/* Fun��o que utiliza o algoritmo de ordena��o ShellSort que consiste em,
basicamente um tipo de inser��o, por�m, separando em grupos menores e os
ordenando, para no fim, ordenar todo o vetor*/
void shellgran (struct Registrogrande *item, int count)
{
	// define um ponteiro para struct Registrogrande
	int i , j , gap = 1, contmove = 0, contcomp = 0;
	struct Registrogrande k;
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
			while (j >= 0 && k.Chave < item[j].Chave)
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
void quicksortgran(struct Registrogrande *item , int count)
{
	qs(item, 0, count - 1);
}
// define um ponteiro para struct Registrogrande
void qs(struct Registrogrande *item, int left , int right)
{
	int i, j, contmove = 0, contcomp = 0;
	struct Registrogrande x , y;
	i = left;
	j = right;
	x = item[(left + right) / 2];
	do
	{
		while (item[i].Chave < x.Chave && i < right) i++;
		while (x.Chave < item[j].Chave && j > left) j--;
		if (i <= j)
		{
			contcomp += 1;
			y = item[i];
			item[i] = item[j];
			item[j] = y;
			i++;
			j--;
			contmove += 1;

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
void constroiHeap(struct Registrogrande *item, int count, int indice_raiz )
{
	int ramificacao;
	struct Registrogrande valor;
	valor = item[indice_raiz];

	while(indice_raiz <= count / 2)
	{

		ramificacao = 2 * indice_raiz;

		if(ramificacao < count && item[ ramificacao ].Chave < item[ramificacao + 1].Chave)

			ramificacao++;

		if( valor.Chave >= item[ramificacao].Chave )

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
void HeapSortgran( struct Registrogrande *item, int count )
{

	int indice, contmove = 0, contcomp = 0;
	struct Registrogrande troca;

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
void mergeSortgran(struct Registrogrande *vetor, int posicaoInicio, int posicaoFim)
{
	int i, j, k, metadeTamanho, contmove = 0, contcomp = 0;
	struct Registrogrande *vetorTemp;
	if(posicaoInicio == posicaoFim) return;
	metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

	mergeSortgran(vetor, posicaoInicio, metadeTamanho);
	mergeSortgran(vetor, metadeTamanho + 1, posicaoFim);

	i = posicaoInicio;
	j = metadeTamanho + 1;
	k = 0;
	vetorTemp = malloc(sizeof(vetor) * (posicaoFim - posicaoInicio + 1));

	while(i < metadeTamanho + 1 || j  < posicaoFim + 1)
	{
		contcomp += 1;
		if (i == metadeTamanho + 1 )
		{
			vetorTemp[k].Chave = vetor[j].Chave;
			j++;
			k++;
			contmove += 1;
		}
		else
		{
			if (j == posicaoFim + 1)
			{
				vetorTemp[k].Chave = vetor[i].Chave;
				i++;
				k++;
				contmove += 1;
			}
			else
			{
				if (vetor[i].Chave < vetor[j].Chave)
				{
					vetorTemp[k].Chave = vetor[i].Chave;
					i++;
					k++;
					contmove += 1;
				}
				else
				{
					vetorTemp[k].Chave = vetor[j].Chave;
					j++;
					k++;
					contmove += 1;
				}
			}
		}

	}
	/*Para juntar as partes ordenadas os dois elementos de cada parte s�o separados
		   e o menor deles � selecionado e retirado de sua parte. Em seguida, os menores
		   entre os restantes s�o comparados e assim prossegue at� juntar todas as partes*/
	for(i = posicaoInicio; i <= posicaoFim; i++)
	{
		vetor[i] = vetorTemp[i - posicaoInicio];
		contcomp += 1;
		contmove += 1;
	}
	free(vetorTemp);
	
}
