	#include <stdio.h>
	#include <math.h>
	
	int xubs (unsigned long long num)
	{
	
		unsigned long long numero; // Define uma variavel do tipo long long int
		unsigned long long xulambs, aux,aux2;// define mais 2 variaveis long long int
	  // uma pra fatorar , outra para auxiliar e a outra para contar quantos xulambs o número de xulambs
	//printf("Informe Um numero\n");
		//scanf("%llu", &numero);
	  numero = num;
		aux = 2; // a aux começa em 2 porque é o primeiro número a ser fatorado
		xulambs = 0; // A variável xulambs recebe o valor zero por ainda não possuir nenhum numero xulamb
		while (aux * aux <= numero) //verifica se o meu numero é maior que 2*2, pois caso o numero for < 3 nao precisa fatorar
	  // Dessa forma, um processo é poupado. 
		{
			if (numero % aux == 0)// Condição para analisar se o numero é divisivel por aux
				//aux até o momento, possui valor 2. 
			{
				xulambs++;//Acrescenta um ao xulambs 
				while (numero % aux == 0)//O número será dividido até que ele não seja mais divisivel por 2.
					numero /= aux;//dividindo o numero...
			} //Quando ele nao é mais divisivel por 2 é somado mais um. 
	    // Retorno para a condição de cima e meu aux passa a valer 3
			aux++;
		}
	  // é acrescentado +1 ao aux do numero que saiu da fatoração caso ele seja diferente de um.
		if (numero != 1){
			xulambs++;
		}
	aux2 =  ((1l  << xulambs)- xulambs -1);// Após fazer a tabela verdade é possivel encontrar a formula numero de xulambs = 2^n-n-1
	// na qual n é o numero de Primos diferentes que foram encontrados na fatoração;
	return aux2;
		//printf("%llu\n", (1l << xulambs) - xulambs - 1);
	  // Operação feita pra retornar a quantidade de xulambs
	}
