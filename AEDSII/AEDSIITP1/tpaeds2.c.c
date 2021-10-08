	//Trabalho Organizado por: Marcella Netto e Marcelo Oliveira \n");
	//Orientador: Rafael Sachetto\n");
	//***********************Nao Aceite Copias****************************
	//Usuario n�o se esque�a de colocar os comandos no Arquivo de texto
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
// STRUCT QUE TEM COMO OBJETIVO CRIAR UM TIPO EMAIL PARA IDENTIFICAR O USU�RIO 
 struct Email{
	int Prioridade; //Ordem em que os emails ser�o mostrados 
	int Id; //N�mero de cadastro do usu�rio 
	char Conteudo[500]; // Conte�do do email 
	struct Email *proximo; 
};
// STRUCT QUE TEM COMO OBJETIVO CRIAR UM USU�RIO PARA ADI��O, CONSULTA E REMO��O
struct Usuario
{
	int Id;
	struct Usuario *prox; // PONTEIRO QUE AUXILIA NA CRIA��O DE UMA LISTA DE USU�RIOS
};
typedef struct Email email; //DEFINI��O DE VARI�VEL 
typedef struct Usuario user; //DEFINI��O DE VARI�VEL 
// DECLARA��O DE FUN��ES 
void Cadastrar(user *CriaUsuario, FILE *LIST);
void Remover(user *CriaUsuario, FILE *LISTA);
int Enviar(FILE *LISTA, user *CriaUsuario, email *CriaEmail);
void Consultar(FILE *LISTA, user *CriaUsuario, email *CriaEmail);
// FUN��O QUE TEM COMO OBJETIVO ALOCAR DINAMICAMENTE A LISTA DE USU�RIO, CRIANDO A CABE�A DA LISTA E A RETORNANDO 
user *NovoUsuario(){
	user *CriaUsuario = (user*) calloc(sizeof(user),1);
	return CriaUsuario;
}
//FUN��O QUE TEM COMO OBJETIVO ALOCAR DINAMICAMENTE O ESPA�O DE MEM�RIA PARA A LISTA DE EMAILS, CRIANDO A CABE�A DA LISTA
email *constroimsg(){
	email *CriaEmail=(email*) calloc(sizeof(email),1);
	return CriaEmail;
}

int main()
{
	user *CriaUsuario; // CRIA UMA VARI�VEL DO TIPO USU�RIO PARA UTILIZA��O NA LISTA DE EMAILS
	email *CriaEmail; // CRIA UMA VARI�VEL DO TIPO EMAIL PARA A LISTA DE EMAILS 
	FILE *LISTA ; // UTILIZADO PARA ABRIR OS ARQUIVOS 
	CriaUsuario= NovoUsuario(); // CHAMA A FUN��O QUE IR� ALOCAR A CABE�A DA LISTA DE USU�RIOS 
	CriaEmail= constroimsg(); // CHAMA A FUN��O QUE IR� ALOCAR A CABE�A DA LISTA DE EMAILS 
	char alternativa[20]; // VETOR DE CHAR PARA ARMAZENAR A OP��O DO USU�RIO CONTIDA NO ARQUIVO 
	setlocale(LC_ALL, "Portuguese"); // MANTER OS CARACTERES ESPECIAIS (ACENTOS) 
if ((LISTA=fopen("opcao.txt","r"))== NULL){
		printf(" o Arquivo nao pode ser lido\n");
		exit(1);//IF PARA CASO O ARQUIVO NAO EXISTA DIZER QUE ELE NAO PODE SER LIDO
	}
	while(!feof(LISTA)){ //ENQUANTO NAO CHEGAR NO FINAL DO ARQUIVO CONTINUE NO LA�O(END-OF-FILE)
		fscanf(LISTA,"%s",alternativa);
		if(strcmp(alternativa,"CADASTRA") == 0) // SE O COMANDO NO ARQUIVO FOR CADASTRA,CHAMA A FUNCAO CADASTRAR
			Cadastrar(CriaUsuario,LISTA);
		if(strcmp(alternativa,"REMOVE") == 0)// SE A FUNCAO NO ARQUIVO FOR REMOVE CHAMA A FUNCAO REMOVER
			Remover(CriaUsuario,LISTA);
		if(strcmp(alternativa,"ENTREGA") == 0) // SE AnFUNCAO DO ARQUIVO FOR ENTREGA CHAMA A FUN�AO ENVIAR
			Enviar(LISTA,CriaUsuario,CriaEmail);
		if(strcmp(alternativa,"CONSULTA") == 0)
			Consultar(LISTA,CriaUsuario,CriaEmail); // SE A FUN�AO DO ARQUIVO FOR CONSULTA CHAMA A FUNCAO CONSULTAR
			getchar();//FAZER O PROGRAMA RODAR COM A PESSOA APERTANDO ENTER PARA CADA LINHA DE COMANDO

	}
	
	fclose(LISTA);//FECHA A LISTA
	return 0;
}
// FUN��O QUE TEM COMO OBJETIVO ADICIONAR USU�RIO
void Cadastrar(user *CriaUsuario, FILE *LISTA){
	int n=0; // RECEBE O NUMERO DE ID 
	user *NewUser,*auxperc; //PONTEIRO AUXILIAR PARA ADICIONAR USU�RIO 
	auxperc = CriaUsuario; // PONTEIRO AUXILIAR QUE PERCORRE A LISTA 
	NewUser = (user*) malloc(sizeof(user)); //ALOCA��O DINAMICA DE UM NEWUSER PARA ADICIONAR UM NOVO USU�RIO 
	fscanf(LISTA,"%d",&n);
	while(auxperc->prox != NULL){ //ENQUANTO O USUARIO ESTIVER CONTIDO NA LISTA EXECUTE O COMANDO ABAIXO
		if(auxperc->prox->Id == n){ // CASO UMA CONTA J� EXISTA COM O MESMO ID QUE PRETENE CADASTRAR
			printf("\nERRO:CONTA %d JA EXISTENTE\n",n);
		}
		auxperc = auxperc->prox;
	}
	
	NewUser->Id = n;//CASO NAO EXISTA O USUARIO ADICIONA ELE NA LISTA E APONTA PRO PROXIMO ELENTO
	NewUser->prox = NULL;//FAZ O PROXIMO ELEMENTO SER IGUAL A NULL
	if(CriaUsuario->prox == NULL){ //CASO O PROXIMO USUARIO SEJA IGUAL A NULO,IGUALA ELE AO NOVO ADICIONANDO-O NA LISTA
		CriaUsuario->prox = NewUser;
	}
	else{
		user *aux = CriaUsuario;
		while(aux->prox !=NULL){
			aux=aux->prox;//CASO NAO SEJA NULO PERCORRE A LISTA E ADICIONO ELE NO FINAL
		}
		aux->prox =NewUser;
	}
	printf("\nOK:CONTA %d CADASTRADA COM SUCESSO\n",n);
}
//FUN��O QUE TEM COMO OBJTIVO REMOVER USU�RIO
void Remover(user *CriaUsuario, FILE *LISTA){
	int n=0; // VARI�VEL QUE IR� RECEBER O ID DO USU�RIO QUE SER� REMOVIDO 
	fscanf(LISTA,"%d",&n);
	user *auxiliar = CriaUsuario,*auxiliar1; // PONTEIRO AUXILIAR QUE IR� PERCORRER A LISTA, E O OUTRO REMOVE O USU�RIO 
	//ENQUANTO A AUXILIAR DE PERCORRER A LISTA N�O CHEGAR NO FINAL, EXECUTA OS COMANDOS ABAIXO
	while(auxiliar->prox != NULL){ 
		//SE A AULIXIAR QUE PERCORRE A LISTA E APONTA PARA O ID FOR IGUAL AO ID DO ARQUIVO 
		//IR� IGUALAR A AUXILIAR QUE REMOVE O USU�RIO AO AUXILIAR QUE PERCORRE O USU�RIO 

		if(auxiliar->prox->Id == n){
			auxiliar1 = auxiliar->prox;
			if(auxiliar1->prox  == NULL){
				auxiliar1 = NULL;
				auxiliar->prox = auxiliar1;
			}
			else
			auxiliar->prox = auxiliar->prox->prox;	//O PROXIMO DO MEU AUXILIAR IR� APONTAR PARA O PR�XIMO DELE E EXCLUI MINHA AUXILIAR PARA EXCLUS�O
			//EXCLUINDO UM USU�RIO
			free(auxiliar1);
			printf("\nOK:CONTA %d REMOVIDA\n",n);
		
		}
		auxiliar = auxiliar->prox;//ENQUANTO O USUARIO COM O ID QUE O ARQUIVO ME PASSOU NAO FOR ENCONTRADO, EU VOU PASSANDO PARA A PROXIMA CELULA DA LISTA
	}
	printf("\nERRO: CONTA %d NAO EXISTE\n",n);
	
}
//FUN��O DE CADASTRO DE MENSAGEM NO SISTEMA
int Enviar(FILE *LISTA, user *CriaUsuario, email *CriaEmail){
	char conteudo[500];//VETOR DE CHAR QUE SALVA O CONTEUDO DE CADA EMAIL
	int id=0, prioridade=0;//ID E PRIORIDADE NA HORA QUE FOR ENTREGAR O EMAIL
	user *auxperc = CriaUsuario;//VARIAVEL PARA PERCORRER A LISTA DE USUARIOS

    fscanf(LISTA,"%d %d",&id,&prioridade); //LE DO ARQUIVO O ID E A PRIORIDADE
	fgets(conteudo,500,LISTA);//LE DO ARQUIVO O CONTEUDO DO EMAIL 
        
	char *pont = strstr(conteudo,"FIM");//PONTEIRO PARA SABER ONDE TERMINA A MENSAGEM
        
	if(pont != NULL){    
	strncpy(pont, "\0", 1);//A POSI��O QUE O PONTEIRO APONTA NA MENSAGEM VIRA \0 PARA O PROGRAMA RECONHECER O FINAL DA MENSAGEM NO VETOR.
        }
        
    email *NewEmail;//CRIAR UMA VARIAVEL NOVA DO TIPO EMAIL
	email *auxperc1 = CriaEmail; //CRIA UMA VARIAVEL DO TIPO EMAIL PARA PERCORRER A LISTA 
	NewEmail = (email*) calloc(sizeof(email),1);//ALOCAR ESPA�O NA MEMORIA PARA PODER SALVAR O EMAIL INDIRETAMENTE NA LISTA
	

	strcpy(NewEmail->Conteudo,conteudo);//COPIAR A MENSAGEM DO ARQUIVO PARA A LISTA DE EMAIL
	
	while(auxperc->prox != NULL){//PERCORRE A LISTA E VE SE TEM O USUARIO(SE ELE EXISTE)
		if(auxperc->prox->Id == id){//CASO ELE EXISTA//SE A MINHA LISTA FOR VAZIA 
			if(CriaEmail->proximo == NULL){//E A PRIMEIRA CELULA FOR VAZIA, QUE E A PROXIMA DA CECULA CABE�A
									
										
				CriaEmail->proximo = NewEmail;	//ADICIONO O EMAIL DIRETO
				CriaEmail->proximo->Id = id;
				CriaEmail->proximo->Prioridade = prioridade;
			}
			else{
				while(auxperc1->proximo != NULL){
					auxperc1 = auxperc1->proximo;//SE A MINHA LISTA N�O ESTIVER VAZIA EU PERCORRO ELA TODA COM UMA AUXILIAR
				}
				auxperc1->proximo = NewEmail; //PARA ADICIONAR O EMAIL NO FINAL
				auxperc1->proximo->Id = id;
				auxperc1->proximo->Prioridade= prioridade;
			}
			printf("\n OK: MENSAGEM PARA %d ENTREGUE\n",auxperc->prox->Id);
			return 1;    
		}
		auxperc = auxperc->prox;
	}
	printf("\nERRO: CONTA %d NAO EXISTE\n",id);
	return 0;
}
//FUN��O PRA CONSUTAR O USUARIO
void Consultar(FILE *LISTA, user *CriaUsuario, email *CriaEmail){
	user *auxperc;//VARIAVEL PARA PERCORRER A LISTA
	auxperc = CriaUsuario;
	int id=0, prioridade=0, cont=0;//PARA VER O ID E A PRIORIDADE UTILIZO DUAS VARIAVEIS MAIS UM CONTADOR
	
	fscanf(LISTA,"%d %d",&id,&prioridade);//LEITURA PARA VER O ID DO USUARIO E A PRIORIDADE DO EMAIL
	
	while(auxperc->prox != NULL){//VERIFICO SE O USUARIO EXISTE NO ARQUIVO
		if(auxperc->prox->Id == id){
			//SE EXISTIR ADICIONO 1 AO MEU CONTADOR
			cont++;
		}
		auxperc = auxperc->prox;
	}
	
	if(cont==0){
				
		printf("\nERRO: CONTA %d NAO EXISTE\n",id);
	}
	int auxpri = 0;
	email *auxmail= CriaEmail, *auxarmazena, *auxmail1 = CriaEmail;//3 VARIAVEIS DO TIPO EMAIL PARA,PERCORRER,ARMAZENAR O EMAIL,E PERCORRER APOS A EXCLUSAO DE UM EMAIL
	auxarmazena = (email*) malloc(sizeof(email));//ALOCA��O PARA GUARDAR O EMAIL, PARA TER GARANTIA DE TER ESPA�O PARA A MENSAGEM
	
	while(auxmail->proximo != NULL){//PERCORRO A LISTA PRA VER SE EXISTE MENSAGENS NA CAIXA DE ENTRADA
		if(auxmail->proximo->Id == id){//PARA PODER GARANTIR QUE O EMAIL MOSTRADO VAI SER O DE MAIOR PRIORIDADE
			if(auxmail->proximo->Prioridade > auxpri){	//FA�O UMA CONDI��O DA PRIORIDADE SER MAIOR QUE 0 OU MAIOR QUE A MENSAGEM GUARDADA ANTERIORMENTE
													
												
				auxarmazena = auxmail->proximo;
				auxpri = auxmail->proximo->Prioridade;
			}
		}
		auxmail = auxmail->proximo;
	}
	
	if(auxpri == 0){// SE FOR IGUAL A 0 A CAIXA DE ENTRADA TA VAZIA
				
		printf("\nCONSULTA %d: CAIXA DE ENTRADA VAZIA\n",id);
	}
	else{
		printf("\nCONSULTA %d:%s\n",id,auxarmazena->Conteudo);
		
		while(auxmail1->proximo != auxarmazena ){//PERCORRE A LISTA ATE O EMAIL QUE FOI MOSTRADO
			auxmail1 = auxmail1->proximo;
		}
		if(auxarmazena->proximo == NULL)//SE FOR A ULTIMA A ANTERIOR VAI VIRAR A ULTIMA, E A QUE ERA A ULTIMA VAI SER APAGADA
		auxmail1 = NULL;
		else//SE N�O FOR A ULTIMA, A ANTERIOR DELA COME�A A PONTAR PARA PROXIMA QUE ERA A QUE ELA APONTAVA
											
		auxmail1->proximo = auxarmazena->proximo;
		free(auxarmazena);
		// EXCLUI A MENSAGEM QUE JA FOI VISUALIZADA :)
		auxpri=0;
	}
}

