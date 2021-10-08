#include "process_manager.h"
#include <stdio.h>
int main(int argc, char const *argv[])
{
	CPU *cpu = (CPU*)malloc(sizeof(CPU));
	*cpu = cria_processo("init");
	programa_Execucao = cpu;
	insere_Tabela(cpu);
	char comando;
	int k, j;
	CPU c;
	do
	{
		scanf("%c", &comando);
		switch(comando)
		{
		case 'Q':
			executa_processo();
			printf("Cheguei no Q\n");
			break;
		case 'U':
			printf("Cheguei no U\n");
			break;
		case 'P':
			printf("Cheguei no P\n");
			break;
		case 'T':
			printf("Cheguei no T\n");
			break;
		}
	}
	while(comando != 'T');
}
CPU cria_processo()
{
	FILE *fp; //arquivo
	char *line = NULL; //recebe uma linha do arquivo
	size_t len = 0; //tamanho da linha
	ssize_t read;

	fp = fopen("init", "r"); //Abre o arquivo no modo de leitura
	if (fp == NULL)
	{
		printf("ERRO: ARQUIVO N?O ENCONTRADO\n");
		exit(EXIT_FAILURE);
	}

	/*Cria a struct para guardar o programa*/
	CPU c;
	int num_linhas = line_count("init");
	c.processo = (programa*)malloc(num_linhas * sizeof(programa));
	c.tamanho = num_linhas;
	c.chave = 0;
	c.contador = 0;
	c.tempo_atual = 0;
	c.tempo_total = 0;
	c.nome_arquivo = "init";


	int j, i = 0;
	/*Coloca o comando no char comando da struct processo e*/
	/*o argumento na string valor */
	while ((read = getline(&line, &len, fp)) != EOF)
	{
		j = 2;
		c.processo[i].comando = line[0];
		if(line[0] == 'B' || line[0] == 'E')
		{
			c.processo[i].valor = NULL;
		}
		else
		{
			/*Calcula o numero de caracteres no argumento*/
			while(line[j + 1] != '\0' && line[j + 1] != '\n')
			{
				j++;
			}
			c.processo[i].valor = (char*)malloc(j * sizeof(char));
			strcpy(c.processo[i].valor, &line[2]);
		}
		i++;
	}
	fclose(fp);
	return c;
}
int line_count()
{
	FILE *fp; //arquivo
	int numLinhas = 0;
	fp = fopen("init", "r"); //Abre o arquivo no modo de leitura
	if (fp == NULL)
	{
		printf("O arquivo nao foi encontrado\n");
		exit(1);
	}

	char chr;
	chr = getc(fp);
	while (chr != EOF)
	{
		if (chr == '\n' || chr == '\0')
		{
			numLinhas++;
		}
		chr = getc(fp);
	}
	return numLinhas;
}

void insere_Tabela(CPU *cpu)
{
	if (testaTabela(lista) == 0)
	{
		lista = (Lista*)malloc(sizeof(Lista));
		lista->cauda = (TabelaPcb*)malloc(sizeof(TabelaPcb) * TAMANHO_TABELAPCB);
		lista->cauda[0].prioridade = 0;
		lista->cauda[0].id_filho = 0;
		lista->cauda[0].id_pai = 0;
		lista->cauda[0].estado = 'E';
		lista->cauda[0].contador_programa = &(cpu->contador);
		lista->cauda[0].tempo_inicio = tempo;
		lista->cauda[0].programa = malloc(cpu->tamanho * sizeof(CPU));
		lista->cauda[0].programa = cpu;
		lista->cabeca = &(lista->cauda[0]);
		lista->tamanho = 1;
		return;
	}
	else
	{
		lista->cauda[lista->tamanho].prioridade = lista->tamanho;
		lista->cauda[lista->tamanho].id_filho = lista->cauda[lista->tamanho].id_filho + 1;
		lista->cauda[lista->tamanho].id_pai = lista->cauda[lista->tamanho].id_filho;
		lista->cauda[lista->tamanho].estado = 'E';
		lista->cauda[lista->tamanho].contador_programa = &(cpu->contador);
		lista->cauda[lista->tamanho].tempo_inicio = tempo;
		lista->cauda[lista->tamanho].programa = malloc(cpu->tamanho * sizeof(CPU));
		lista->cauda[lista->tamanho].programa = cpu;
		lista->cabeca = &(lista->cauda[lista->tamanho]);
		lista->tamanho++;
	}
}
int testaTabela(Lista *lista)
{
	if (lista == NULL)
		return 0;
	return 1;
}
void executa_processo()
{
		printf("Até aqui\n");
	programa_Execucao->tempo_total++;
	tempo++;
	switch(programa_Execucao->processo[programa_Execucao->contador].comando)
	{
	case 'S':
		programa_Execucao->chave = atoi(programa_Execucao->processo[programa_Execucao->contador].valor);
		programa_Execucao->tempo_atual++;
			printf("%d\n",programa_Execucao->chave);
		printf("S\n");
		break;
	case 'A':
		programa_Execucao->chave += atoi(programa_Execucao->processo[programa_Execucao->contador].valor);
		programa_Execucao->tempo_atual++;
			printf("%d\n",programa_Execucao->chave);
		printf("A\n");
		break;
	case 'D':
		programa_Execucao->chave -= atoi(programa_Execucao->processo[programa_Execucao->contador].valor);
		programa_Execucao->tempo_atual++;
			printf("%d\n",programa_Execucao->chave);
		printf("D\n");
		break;
	case 'B':
		printf("B\n");
		return;
	case 'E':
		printf("E\n");
		break;
	case	'F':
		printf("F\n");
		break;
	case	'R':
		printf("R\n");
		return;
	}
	programa_Execucao->contador++;

}
