#include <stdio.h>
#include <stdlib.h>
#include "TraduzLetra.h"
struct ArvoreMorse
{
	char letra;
	char simbolo;
	struct ArvoreMorse* esq;
	struct ArvoreMorse* dir;
};
typedef struct ArvoreMorse Arv;
Arv* iniciaArvore();
Arv* criaArvore (Arv* item, char simbolo, char letra);
Arv* insereElemento (Arv* item, char simbolo, char letra);
void imprime (Arv* item);
Arv* iniciaArvore()
{
	return  NULL;
}
Arv* criaArvore(Arv* item, char simbolo, char letra)
{
	item = (Arv*)malloc(sizeof(Arv));//cria a arvore;
	item->simbolo = simbolo;
	item->letra = letra;
	item->esq = NULL;
	item->dir = NULL;
	return item;
}
void percorre(Arv* item,char palavra)//percorre a arvore 
{
	if (item != NULL)
	{ 
		percorre(item->esq,palavra);
		percorre(item->dir,palavra);
		if(palavra==item->letra){
			TraduzLetra(palavra);
		}
		
	
	}

}
Arv* insereElemento(Arv* item, char simbolo, char letra)//insere os elementos na arvore
//entretanto colocamos a inserçao direto na main
{
	if ((item->simbolo == '.') && (item->esq != NULL))
	{
		item->esq = criaArvore(item->esq, simbolo, letra);
		return item->esq;
	}
	if ((item->simbolo == '-') && (item->dir != NULL))
	{
		item->dir = criaArvore(item->dir, simbolo, letra);
		return item->dir;
	}
	return 0;
}

void imprime(Arv* item)//imprime a arvore 
{
	if (item != NULL)
	{
		if (item->letra != 'm'){
			printf("%c : ", item->letra);
			TraduzLetra(item->letra);
			printf("\n");
		}
		//else{
		//	printf("%c : ", item->letra);
		//	TraduzLetra(item->letra);
		//	printf("\n");
		//}
		imprime( item->dir);
		imprime( item->esq);
	}
}
