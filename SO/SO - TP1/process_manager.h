#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAMANHO_TABELAPCB 200
typedef struct {
	char comando;
	char *valor;
}programa;

typedef struct{
	programa *processo;
	char *nome_arquivo;
	int tamanho;
	int chave;
	int contador;
	int tempo_total;
	int tempo_atual;
} CPU;

typedef struct{
	int prioridade;
	int id_filho;
	int id_pai;
	char estado;
	int *contador_programa;
	int tempo_inicio;
	CPU *programa;
} TabelaPcb;

typedef struct {
	TabelaPcb *cauda;
	int tamanho;
	TabelaPcb *cabeca;
}Lista;

typedef struct fila{
	CPU *cpu;
	struct fila *prox;
} fila;

CPU *programa_Execucao;
int tempo = 0;
int contador_tabela = 0;
fila *estado_pronto = NULL;
fila *estado_bloqueado = NULL;
Lista *lista;
CPU cria_processo();
int line_count();
void insere_Tabela(CPU *cpu);
int testaTabela(Lista *lista);
void executa_processo();
