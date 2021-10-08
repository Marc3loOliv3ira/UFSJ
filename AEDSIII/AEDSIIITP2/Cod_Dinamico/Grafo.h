//Arquivo Grafo.h

typedef struct grafo Grafo;
Grafo* cria_Grafo(int nro_vertices, int Max_Arestas);
void libera_Grafo(Grafo* gr);
void quick_sort(int *a, int left, int right);
int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso);
//void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont);
void buscaProfundidade_Grafo(Grafo *gr, int ini, int *visitado,int Caminhos,float Distancia,int Capacidade,int *P_Povo,int *H_Povo,int j);
void imprime_Grafo(Grafo *gr);
