	#include "LerArquivo.h" // Biblioteca criada para contar o número de linhas no arquivo.
	#include "xulambs.h" // Biblioteca com o código para o cálculo dos xulambs.
	#include "tempoexecucao.h" /*Biblioteca criada para calcular o tempo de execução do programa,
	tempo de sistema e tempoo de usuário. */
	int main(int argc, char *argv[])
	{
	  FILE *arqXulambs; //ponteiro para abrir o arquivo
	  char auxiliar[256]; //variável auxiliar para salvar o nome do arquivo que será aberto. 
	  char auxiliar1[256];
	  int i,j=0,*vetNumeros,opcao,habilit,habilit1; /*variável habillit ultilizada para verificar se os parâmetros
	  passados no get opt estavam corretos*/
	  char *nomefileEntrada = NULL;// variável que recebe o nome do arquivo.txt no getopt
	  char *nomefileSaida = NULL;
	  opterr = 0;//// Desativa as mensagens de erro da função getopt
	  while ((opcao = getopt (argc, argv, "i:o:")) != -1)
	  {
	    switch (opcao)
	    {
	      case 'i':
	      nomefileEntrada = optarg;
	      habilit = 1;
	        break;
	      case 'o':
	      nomefileSaida = optarg;
	      habilit1 = 1;
	        break;
	
	      case '?':
	      printf("erro nos argumentos passados para o getopt\n");
	      break;
	    }
	  }
	if (habilit+habilit1 == 2){
	  double tempo_ini,tempo_fim;//variável q armazena o inicio e o fim do tempo em que o codigo foi executado
	  unsigned long long numero;
	int numero_de_Linhas;
	numero_de_Linhas = NumLinha();/* armazena o numero de linhas contido no arquivo para criar um vetor dinamico
	que ira receber os numeros contidos no arquivo */
	 sprintf(auxiliar, nomefileEntrada, atoi(argv[1]));// a variavel auxiliar recebe o nome do arquivo de entrada passado no getopt
	  sprintf(auxiliar1, nomefileSaida, atoi(argv[1]));
	  arqXulambs = fopen(auxiliar,"rt");
	  vetNumeros = (int *)malloc(numero_de_Linhas * sizeof(int));/* cria um vetor dinamico para receber quantos divisores
	  xulambs o numero possui*/
	
	  tempo_ini = tempo_Execucao();// chama da funçaõ tempo de execução.
	    while (!feof(arqXulambs))
	    {
	fscanf(arqXulambs,"%llu",&numero) ;
	vetNumeros[j]=xubs(numero);
	j++;
	    }
	    fclose(arqXulambs);
	    arqXulambs = fopen(auxiliar1,"a");
	    tempo_fim = tempo_Execucao();
	    for ( i = 0; i < numero_de_Linhas - 1; i++) {
	  fprintf(arqXulambs,"%d\n",vetNumeros[i]);
	    }
	    fclose(arqXulambs);
	    free(vetNumeros);
	    tempo_sistema_usuario();
	    printf("Tempo de execução : %lf segundos\n",tempo_fim-tempo_ini);
	
	}
	else{
	  printf("Leia as instruções e compile novamente\n");
	}
	}
