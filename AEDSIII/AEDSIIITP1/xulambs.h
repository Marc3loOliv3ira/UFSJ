	#include <stdio.h>
	#include <math.h>
	
	int xubs (unsigned long long num)
	{
	
		unsigned long long numero; // Define uma variavel do tipo long long int
		unsigned long long xulambs, aux,aux2;// define mais 2 variaveis long long int
	  // uma pra fatorar , outra para auxiliar e a outra para contar quantos xulambs o n�mero de xulambs
	//printf("Informe Um numero\n");
		//scanf("%llu", &numero);
	  numero = num;
		aux = 2; // a aux come�a em 2 porque � o primeiro n�mero a ser fatorado
		xulambs = 0; // A vari�vel xulambs recebe o valor zero por ainda n�o possuir nenhum numero xulamb
		while (aux * aux <= numero) //verifica se o meu numero � maior que 2*2, pois caso o numero for < 3 nao precisa fatorar
	  // Dessa forma, um processo � poupado. 
		{
			if (numero % aux == 0)// Condi��o para analisar se o numero � divisivel por aux
				//aux at� o momento, possui valor 2. 
			{
				xulambs++;//Acrescenta um ao xulambs 
				while (numero % aux == 0)//O n�mero ser� dividido at� que ele n�o seja mais divisivel por 2.
					numero /= aux;//dividindo o numero...
			} //Quando ele nao � mais divisivel por 2 � somado mais um. 
	    // Retorno para a condi��o de cima e meu aux passa a valer 3
			aux++;
		}
	  // � acrescentado +1 ao aux do numero que saiu da fatora��o caso ele seja diferente de um.
		if (numero != 1){
			xulambs++;
		}
	aux2 =  ((1l  << xulambs)- xulambs -1);// Ap�s fazer a tabela verdade � possivel encontrar a formula numero de xulambs = 2^n-n-1
	// na qual n � o numero de Primos diferentes que foram encontrados na fatora��o;
	return aux2;
		//printf("%llu\n", (1l << xulambs) - xulambs - 1);
	  // Opera��o feita pra retornar a quantidade de xulambs
	}
