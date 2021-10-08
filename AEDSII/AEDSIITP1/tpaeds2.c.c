	//Trabalho Organizado por: Marcella Netto e Marcelo Oliveira \n");
	//Orientador: Rafael Sachetto\n");
	//***********************Nao Aceite Copias****************************
	//Usuario não se esqueça de colocar os comandos no Arquivo de texto
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
// STRUCT QUE TEM COMO OBJETIVO CRIAR UM TIPO EMAIL PARA IDENTIFICAR O USUÁRIO 
 struct Email{
	int Prioridade; //Ordem em que os emails serão mostrados 
	int Id; //Número de cadastro do usuário 
	char Conteudo[500]; // Conteúdo do email 
	struct Email *proximo; 
};
// STRUCT QUE TEM COMO OBJETIVO CRIAR UM USUÁRIO PARA ADIÇÃO, CONSULTA E REMOÇÃO
struct Usuario
{
	int Id;
	struct Usuario *prox; // PONTEIRO QUE AUXILIA NA CRIAÇÃO DE UMA LISTA DE USUÁRIOS
};
typedef struct Email email; //DEFINIÇÃO DE VARIÁVEL 
typedef struct Usuario user; //DEFINIÇÃO DE VARIÁVEL 
// DECLARAÇÃO DE FUNÇÕES 
void Cadastrar(user *CriaUsuario, FILE *LIST);
void Remover(user *CriaUsuario, FILE *LISTA);
int Enviar(FILE *LISTA, user *CriaUsuario, email *CriaEmail);
void Consultar(FILE *LISTA, user *CriaUsuario, email *CriaEmail);
// FUNÇÃO QUE TEM COMO OBJETIVO ALOCAR DINAMICAMENTE A LISTA DE USUÁRIO, CRIANDO A CABEÇA DA LISTA E A RETORNANDO 
user *NovoUsuario(){
	user *CriaUsuario = (user*) calloc(sizeof(user),1);
	return CriaUsuario;
}
//FUNÇÃO QUE TEM COMO OBJETIVO ALOCAR DINAMICAMENTE O ESPAÇO DE MEMÓRIA PARA A LISTA DE EMAILS, CRIANDO A CABEÇA DA LISTA
email *constroimsg(){
	email *CriaEmail=(email*) calloc(sizeof(email),1);
	return CriaEmail;
}

int main()
{
	user *CriaUsuario; // CRIA UMA VARIÁVEL DO TIPO USUÁRIO PARA UTILIZAÇÃO NA LISTA DE EMAILS
	email *CriaEmail; // CRIA UMA VARIÁVEL DO TIPO EMAIL PARA A LISTA DE EMAILS 
	FILE *LISTA ; // UTILIZADO PARA ABRIR OS ARQUIVOS 
	CriaUsuario= NovoUsuario(); // CHAMA A FUNÇÃO QUE IRÁ ALOCAR A CABEÇA DA LISTA DE USUÁRIOS 
	CriaEmail= constroimsg(); // CHAMA A FUNÇÃO QUE IRÁ ALOCAR A CABEÇA DA LISTA DE EMAILS 
	char alternativa[20]; // VETOR DE CHAR PARA ARMAZENAR A OPÇÃO DO USUÁRIO CONTIDA NO ARQUIVO 
	setlocale(LC_ALL, "Portuguese"); // MANTER OS CARACTERES ESPECIAIS (ACENTOS) 
if ((LISTA=fopen("opcao.txt","r"))== NULL){
		printf(" o Arquivo nao pode ser lido\n");
		exit(1);//IF PARA CASO O ARQUIVO NAO EXISTA DIZER QUE ELE NAO PODE SER LIDO
	}
	while(!feof(LISTA)){ //ENQUANTO NAO CHEGAR NO FINAL DO ARQUIVO CONTINUE NO LAÇO(END-OF-FILE)
		fscanf(LISTA,"%s",alternativa);
		if(strcmp(alternativa,"CADASTRA") == 0) // SE O COMANDO NO ARQUIVO FOR CADASTRA,CHAMA A FUNCAO CADASTRAR
			Cadastrar(CriaUsuario,LISTA);
		if(strcmp(alternativa,"REMOVE") == 0)// SE A FUNCAO NO ARQUIVO FOR REMOVE CHAMA A FUNCAO REMOVER
			Remover(CriaUsuario,LISTA);
		if(strcmp(alternativa,"ENTREGA") == 0) // SE AnFUNCAO DO ARQUIVO FOR ENTREGA CHAMA A FUNÇAO ENVIAR
			Enviar(LISTA,CriaUsuario,CriaEmail);
		if(strcmp(alternativa,"CONSULTA") == 0)
			Consultar(LISTA,CriaUsuario,CriaEmail); // SE A FUNÇAO DO ARQUIVO FOR CONSULTA CHAMA A FUNCAO CONSULTAR
			getchar();//FAZER O PROGRAMA RODAR COM A PESSOA APERTANDO ENTER PARA CADA LINHA DE COMANDO

	}
	
	fclose(LISTA);//FECHA A LISTA
	return 0;
}
// FUNÇÃO QUE TEM COMO OBJETIVO ADICIONAR USUÁRIO
void Cadastrar(user *CriaUsuario, FILE *LISTA){
	int n=0; // RECEBE O NUMERO DE ID 
	user *NewUser,*auxperc; //PONTEIRO AUXILIAR PARA ADICIONAR USUÁRIO 
	auxperc = CriaUsuario; // PONTEIRO AUXILIAR QUE PERCORRE A LISTA 
	NewUser = (user*) malloc(sizeof(user)); //ALOCAÇÃO DINAMICA DE UM NEWUSER PARA ADICIONAR UM NOVO USUÁRIO 
	fscanf(LISTA,"%d",&n);
	while(auxperc->prox != NULL){ //ENQUANTO O USUARIO ESTIVER CONTIDO NA LISTA EXECUTE O COMANDO ABAIXO
		if(auxperc->prox->Id == n){ // CASO UMA CONTA JÁ EXISTA COM O MESMO ID QUE PRETENE CADASTRAR
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
//FUNÇÃO QUE TEM COMO OBJTIVO REMOVER USUÁRIO
void Remover(user *CriaUsuario, FILE *LISTA){
	int n=0; // VARIÁVEL QUE IRÁ RECEBER O ID DO USUÁRIO QUE SERÁ REMOVIDO 
	fscanf(LISTA,"%d",&n);
	user *auxiliar = CriaUsuario,*auxiliar1; // PONTEIRO AUXILIAR QUE IRÁ PERCORRER A LISTA, E O OUTRO REMOVE O USUÁRIO 
	//ENQUANTO A AUXILIAR DE PERCORRER A LISTA NÃO CHEGAR NO FINAL, EXECUTA OS COMANDOS ABAIXO
	while(auxiliar->prox != NULL){ 
		//SE A AULIXIAR QUE PERCORRE A LISTA E APONTA PARA O ID FOR IGUAL AO ID DO ARQUIVO 
		//IRÁ IGUALAR A AUXILIAR QUE REMOVE O USUÁRIO AO AUXILIAR QUE PERCORRE O USUÁRIO 

		if(auxiliar->prox->Id == n){
			auxiliar1 = auxiliar->prox;
			if(auxiliar1->prox  == NULL){
				auxiliar1 = NULL;
				auxiliar->prox = auxiliar1;
			}
			else
			auxiliar->prox = auxiliar->prox->prox;	//O PROXIMO DO MEU AUXILIAR IRÁ APONTAR PARA O PRÓXIMO DELE E EXCLUI MINHA AUXILIAR PARA EXCLUSÃO
			//EXCLUINDO UM USUÁRIO
			free(auxiliar1);
			printf("\nOK:CONTA %d REMOVIDA\n",n);
		
		}
		auxiliar = auxiliar->prox;//ENQUANTO O USUARIO COM O ID QUE O ARQUIVO ME PASSOU NAO FOR ENCONTRADO, EU VOU PASSANDO PARA A PROXIMA CELULA DA LISTA
	}
	printf("\nERRO: CONTA %d NAO EXISTE\n",n);
	
}
//FUNÇÃO DE CADASTRO DE MENSAGEM NO SISTEMA
int Enviar(FILE *LISTA, user *CriaUsuario, email *CriaEmail){
	char conteudo[500];//VETOR DE CHAR QUE SALVA O CONTEUDO DE CADA EMAIL
	int id=0, prioridade=0;//ID E PRIORIDADE NA HORA QUE FOR ENTREGAR O EMAIL
	user *auxperc = CriaUsuario;//VARIAVEL PARA PERCORRER A LISTA DE USUARIOS

    fscanf(LISTA,"%d %d",&id,&prioridade); //LE DO ARQUIVO O ID E A PRIORIDADE
	fgets(conteudo,500,LISTA);//LE DO ARQUIVO O CONTEUDO DO EMAIL 
        
	char *pont = strstr(conteudo,"FIM");//PONTEIRO PARA SABER ONDE TERMINA A MENSAGEM
        
	if(pont != NULL){    
	strncpy(pont, "\0", 1);//A POSIÇÃO QUE O PONTEIRO APONTA NA MENSAGEM VIRA \0 PARA O PROGRAMA RECONHECER O FINAL DA MENSAGEM NO VETOR.
        }
        
    email *NewEmail;//CRIAR UMA VARIAVEL NOVA DO TIPO EMAIL
	email *auxperc1 = CriaEmail; //CRIA UMA VARIAVEL DO TIPO EMAIL PARA PERCORRER A LISTA 
	NewEmail = (email*) calloc(sizeof(email),1);//ALOCAR ESPAÇO NA MEMORIA PARA PODER SALVAR O EMAIL INDIRETAMENTE NA LISTA
	

	strcpy(NewEmail->Conteudo,conteudo);//COPIAR A MENSAGEM DO ARQUIVO PARA A LISTA DE EMAIL
	
	while(auxperc->prox != NULL){//PERCORRE A LISTA E VE SE TEM O USUARIO(SE ELE EXISTE)
		if(auxperc->prox->Id == id){//CASO ELE EXISTA//SE A MINHA LISTA FOR VAZIA 
			if(CriaEmail->proximo == NULL){//E A PRIMEIRA CELULA FOR VAZIA, QUE E A PROXIMA DA CECULA CABEÇA
									
										
				CriaEmail->proximo = NewEmail;	//ADICIONO O EMAIL DIRETO
				CriaEmail->proximo->Id = id;
				CriaEmail->proximo->Prioridade = prioridade;
			}
			else{
				while(auxperc1->proximo != NULL){
					auxperc1 = auxperc1->proximo;//SE A MINHA LISTA NÃO ESTIVER VAZIA EU PERCORRO ELA TODA COM UMA AUXILIAR
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
//FUNÇÃO PRA CONSUTAR O USUARIO
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
	auxarmazena = (email*) malloc(sizeof(email));//ALOCAÇÃO PARA GUARDAR O EMAIL, PARA TER GARANTIA DE TER ESPAÇO PARA A MENSAGEM
	
	while(auxmail->proximo != NULL){//PERCORRO A LISTA PRA VER SE EXISTE MENSAGENS NA CAIXA DE ENTRADA
		if(auxmail->proximo->Id == id){//PARA PODER GARANTIR QUE O EMAIL MOSTRADO VAI SER O DE MAIOR PRIORIDADE
			if(auxmail->proximo->Prioridade > auxpri){	//FAÇO UMA CONDIÇÃO DA PRIORIDADE SER MAIOR QUE 0 OU MAIOR QUE A MENSAGEM GUARDADA ANTERIORMENTE
													
												
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
		else//SE NÃO FOR A ULTIMA, A ANTERIOR DELA COMEÇA A PONTAR PARA PROXIMA QUE ERA A QUE ELA APONTAVA
											
		auxmail1->proximo = auxarmazena->proximo;
		free(auxarmazena);
		// EXCLUI A MENSAGEM QUE JA FOI VISUALIZADA :)
		auxpri=0;
	}
}

