	#include "LerArquivo.h" // Biblioteca criada para contar o n�mero de linhas no arquivo.
	#include "xulambs.h" // Biblioteca com o c�digo para o c�lculo dos xulambs.
	#include "tempoexecucao.h" /*Biblioteca criada para calcular o tempo de execu��o do programa,
	tempo de sistema e tempoo de usu�rio. */
	int main(int argc, char *argv[])
	{
	  FILE *arqXulambs; //ponteiro para abrir o arquivo
	  char auxiliar[256]; //vari�vel auxiliar para salvar o nome do arquivo que ser� aberto. 
	  char auxiliar1[256];
	  int i,j=0,*vetNumeros,opcao,habilit,habilit1; /*vari�vel habillit ultilizada para verificar se os par�metros
	  passados no get opt estavam corretos*/
	  char *nomefileEntrada = NULL;// vari�vel que recebe o nome do arquivo.txt no getopt
	  char *nomefileSaida = NULL;
	  opterr = 0;//// Desativa as mensagens de erro da fun��o getopt
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
	  double tempo_ini,tempo_fim;//vari�vel q armazena o inicio e o fim do tempo em que o codigo foi executado
	  unsigned long long numero;
	int numero_de_Linhas;
	numero_de_Linhas = NumLinha();/* armazena o numero de linhas contido no arquivo para criar um vetor dinamico
	que ira receber os numeros contidos no arquivo */
	 sprintf(auxiliar, nomefileEntrada, atoi(argv[1]));// a variavel auxiliar recebe o nome do arquivo de entrada passado no getopt
	  sprintf(auxiliar1, nomefileSaida, atoi(argv[1]));
	  arqXulambs = fopen(auxiliar,"rt");
	  vetNumeros = (int *)malloc(numero_de_Linhas * sizeof(int));/* cria um vetor dinamico para receber quantos divisores
	  xulambs o numero possui*/
	
	  tempo_ini = tempo_Execucao();// chama da fun�a� tempo de execu��o.
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
	    printf("Tempo de execu��o : %lf segundos\n",tempo_fim-tempo_ini);
	
	}
	else{
	  printf("Leia as instru��es e compile novamente\n");
	}
	}
