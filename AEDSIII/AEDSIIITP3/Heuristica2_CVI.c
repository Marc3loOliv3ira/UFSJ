#include "Grafo.h"
int Heuristica2_CVI(Grafo*gr){
    int i,j,aux,maximo,t,k,l,cont=0;
    int *Conj_Select,*prioridade;
    Conj_Select = malloc(gr->nro_vertices*sizeof(int));//Guarda os vértices encontrados da Cobertura de Vertices
    prioridade = malloc(gr->nro_vertices*sizeof(int));//Armazena a cada novo grafo a prioridade dos vértices
    while(gr->num_arestas){ //Calcula o grau de cada vértice e o salvando no grafo (gr->grau[k])
        for(k=0;k<gr->nro_vertices;k++){//Calcula a prioridade  de cada vertice
            prioridade[k]=0;//Seta a prioridade de todos como 0
            for(j = 0;j<gr->nro_vertices;j++){
                if(gr->arestas[k][j]){
                  prioridade[k]+=gr->grau[j];//Prioridade  = Soma do grau de todos seus adjacentes
                }
            }
        }
        maximo=prioridade[0];//Pega a prioridade do primeiro vetor, apenas por convenção
        t=0;//Variavel que irá guardar o vertice a ser adicionado no conjunto
        for(j=1;j<gr->nro_vertices;j++){//Escolhe qual o vértice tem maior prioridade
            if(maximo<prioridade[j]){
                t = j;
                maximo = prioridade[j];
            }
            else if(maximo==prioridade[j]){
                if(gr->grau[j]> gr->grau[t]){
                    t = j;
                }
                maximo = prioridade[j];
            }
        }
        Conj_Select[cont++] = t;//Adiciona o vértice de maior prioridade no conjunto
        Remove_Vertice(gr,t);
    }
    free(prioridade);
    free(Conj_Select);
    //Retorna a quantidade de vértices do grafo, menos, o tamanho do conjunto encontrado
    //Numero total de vértices menos a quantidade existente na cobertura de vértices
    return gr->nro_vertices - cont;
}
