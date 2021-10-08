// Tradutor Codigo Morse
#include "ArvoreMorse.h"
int main()
{
	FILE *fp, *fp2, *fp3, *fp4;
	char ch, ch2;
	int num;
	num = 0;
	if((fp = fopen("DicionarioMorse.txt", "r")) == NULL)
	{
		exit(0);

	} //abre o arquivo com os elementos a serem inseridos na arvore
	Arv* apont;//cria um ponteiro para a estrutura Arvore
	Arv* item = iniciaArvore(item);//cria um ponteiro item
	item = criaArvore(item, 'm', 'm'); //inicializa uma arvore com um item null e dois caracteres para passar de parametro na funçao
	ch = fgetc(fp);

	while (ch != EOF)
	{
		apont = item;//a variavel apont recebe o valor da raiz da arvore
		while (ch != '\n')//no arquivo a quebra de linha representa uma nova letra a ser inserida
		{

			if(num != 0)
			{
				if ((ch == '.') & (apont->esq == NULL))//se o simbolo for o . e o proximo no a esqueda for vazio
				{
					apont->esq = criaArvore(apont->esq, ch, 'm');//insere no no
					apont = apont ->esq; // apont recebe o valor do apontador a esqueda

				}
				if ((ch == '.') & (apont->esq != NULL))//se o simbolo for o . e o apont a esquerda nao for vazio
				{
					apont = apont ->esq;//apont recebe o valor  do apont a esquerda

				}
				if ((ch == '-') & (apont->dir == NULL))//se o simbolo for o . e o proximo no a direita for vazio
				{
					apont->dir = criaArvore(apont->dir, ch, 'm');//insere no no
					apont = apont->dir;// apont recebe o valor do apontador a esqueda

				}
				if ((ch == '-') & (apont->dir != NULL))//se o simbolo for o . e o proximo no a direita nao for vazio
				{
					apont = apont->dir;//apont recebe o valor  do apont a esquerda

				}

			}
			else
				ch2 = ch;//ch2 recebe a letra que estava armazenada em ch
			num++;
			ch = fgetc(fp);//ch recebe uma nova letra do arquivo


		}
		apont->letra = ch2;//o apont->letra recebe a letra armazenada em ch2
		num = 0;
		ch = fgetc(fp);//ch recebe uma nova letra do arquivo
		// insere e aqui imprime a arvore pré ordem


	}
	//ate aqui ele le o arquivo arvore morsee insere os elementos na arvore

	int op;
	printf("Menu de Conversão\n");
	printf("1 Código Morse Para Letra\n");
	printf("2 De Letra Para Código Morse\n");
	printf("3 Imprime a árvore\n");
	printf("Opção: ");
	scanf("%d", &op);
	if(op == 1)
	{
		printf("A frase Informada Foi:\n");
		char c;
		fp3 = fopen("msg.txt", "r");
		do
		{
			//faz a leitura do caracter no arquivo apontado por pont_arq
			c = getc(fp3);

			//exibe o caracter lido na tela
			printf("%c" , c);

		}
		while (c != EOF);
		printf("Frase Traduzida:\n");
		if ((fp2 = fopen("msg.txt", "r"))  == NULL)//aqui ele abre o da msg
		{
			exit(0);
		}

		apont = item;
		do
		{
			ch = fgetc(fp2);
			if ((ch == '.'))// se for um . na msg o apont recebe o valor do apont a esquerda
			{
				apont = apont->esq;
			}
			if ((ch == '-'))// se for um - na msg o apont recebe o valor do apont a direita
			{
				apont = apont->dir;
			}
			if ((ch == '/'))
			{
				printf(" ");
			}
			if ((ch == ' ') || (ch == EOF))
			{
				if (apont->letra != 'm')
					printf("%c", apont->letra);
				apont = item;
			}
		}
		while(ch != EOF);

	}
	else if(op == 2)
	{
		printf("A frase Informada Foi:\n");
		char c;
		fp4 = fopen("msg2.txt", "r");
		do
		{
			//faz a leitura do caracter no arquivo apontado por pont_arq
			c = getc(fp4);

			//exibe o caracter lido na tela
			printf("%c" , c);

		}
		while (c != EOF);
		printf("Frase Traduzida de texto para morse:\n");
		if ((fp2 = fopen("msg2.txt", "r"))  == NULL)//aqui ele abre o da msg em texto pra transformar em morse
		{
			exit(0);
		}

		apont = item;
		do
		{
			ch = fgetc(fp2);

			if ((ch == ' '))
			{
				printf("/");
			}
			else
			{
				percorre(item, ch);


			}
			printf(" ");
			if(ch == EOF)
				printf("\n");

		}
		while(ch != EOF);


	}
	else if(op == 3)
	{
		imprime(item);
	}
	else
	{
		printf ("Informe uma opção válida\n");
		main();
	}
	return 0;
}
