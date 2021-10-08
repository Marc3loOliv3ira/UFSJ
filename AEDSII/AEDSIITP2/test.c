#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include"vetor.h"
int main(){
int i,*vet,*vetb,n,opcao,m;
double soma;
double media;
int tam;
	srand(time(NULL));
	double ti,tf,tempo; // ti = tempo inicial // tf = tempo final
  struct timeval tempo_inicio,tempo_fim;
printf("Informe o tamanho do vetor\n");
scanf("%d",&tam);
vet = (int *) malloc(tam * sizeof(int));
printf("\nInforme como deseja que o vetor esteja\n");
printf("1-Aleatorio\n");
printf("2-Ordem Crescente\n");
printf("3-Ordem Decrescente\n");
scanf("%d",&opcao);
switch(opcao){
case 1:
	for(n = 0; n < tam; n++)
	{
		vet[n] = (int) rand() % tam;
	}
break;
case 2:
for(n=0;n<tam;n++){
vet[n]=n;
}
   break;
case 3:
for((m=tam-1) && (n=0);(m>=0)&&(n<tam);(m--)&&(n++)){
vet[n]=m;
}
  break;
default:
break;
 
}
system("clear");
for(i=0;i<10;i++){
vetb=(int *) malloc(tam * sizeof(int));
for(n = 0; n < tam; n++)
	{
		vetb[n] = vet[n];
	}
ti = tf = tempo = 0;
gettimeofday(&tempo_inicio,NULL);
mergeSort(vet,0,tam-1);
gettimeofday(&tempo_fim,NULL);
tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
  ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));
  tempo = (tf - ti) / 1000;
soma=soma+tempo;
free(vet);
    }
media=soma/10;
printf("\nmedia %.3f milisegundos\n\n", media);
printf("\n##################################\n\n");
main();
}


