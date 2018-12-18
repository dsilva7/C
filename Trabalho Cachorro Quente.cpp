#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>
#define N 10





/*DECLARAMOS A ESTRUTURA CAD_CLIENTE ONDE COLOCAMOS OS DADOS BÁSICOS DO CADASTRO*/
struct cad_cliente
{
	int codigo;
	char nome[50];
	char endereco[50];
	char telefone[50];
	int cad_ativo;
	float cpf;	
};

/*DECLARAMOS O VETOR DA STRUCT GLOBAL COM "N"CADASTROS NO "DEFINE"*/
struct cad_cliente cc[N];

int i; // INDICE GLOBAL. PARA USARMOS EM TODAS OS "FOR" DO CÓDIGO;
int num_clientes = 0; // VARIÁVEL GLOBAL NUM_CLIENTES, PARA EFETUAR A CONTAGEM DE CADASTROS REALIZADAS;

/*FUNÇÃO MENU, SERÁ A PRIMEIRA TELA A SER VISTA PELO USUÁRIO AO ABRIR O PROGRAMA*/
int menu ()
{	/*APRESENTADOS AS OPÇÕES DE ESCOLHA AO USUÁRIO*/
			int escolha;
	 			printf ("\n					 	     BEM VINDO AO \n");
			printf ("                                                                  ~~~~~~    \n");
			printf ("                                     ddddd     oooooo    ggggg     aaaa    oooooo\n");
			printf ("                                     d     d  o      o   g        a    a  o      o\n");
			printf ("                                     d     d  o      o   g  ggg   aaaaaa  o      o\n");
			printf ("                                     d     d  o      o   g   gg   a    a  o      o\n");
			printf ("                                     ddddd     oooooo     g ggg   a    a   oooooo   \n");
			printf ("\n\n");
			printf ("====================================================== M E N U =========================================================\n\n");
			printf ("\n");
			printf ("========================================================================================================================\n\n");
			printf ("                                        |   1- CADASTRAR CLIENTE         |\n");    
			printf ("                                        |   2- CONSULTA DE CADASTRO      |  \n"); 
			printf ("                                        |   3- LISTAR CLIENTES           |   \n");		
			printf ("                                        |   4- DESATIVAR/ATIVAR CADASTRO |    \n");
			printf ("                                        |   5- COMPRAS E PAGAMENTOS      |    \n");			
			printf ("                                        |   0- SAIR                      |     \n");
			printf ("\n\n");
			printf ("========================================================================================================================\n\n");
			printf (" Escolha: ");
			scanf ("%i",&escolha);
			system("cls");
			return escolha;//FUNCAO RETORNA A OPÇÃO ESCOLHIDA PELO USUÁRIO;	
}

/*FUNÇÃO VOID CADASTRO_FEITO, ONDE APENAS É ADICIONADO MAIS UM CADASTRO NO VETOR GLOBAL*/
void cadastro_feito (struct cad_cliente nv_cliente) 
{			
	cc[num_clientes] = nv_cliente;//VETOR GLOBAL  RECEBE MAIS UM CADASTRO;
	num_clientes++;// ADICIONA UM CLIENTE NO CONTADOR;
}

/*FUNCAO STRUCT PARA PREENCHER DADOS, ONDE DECLARAMOS UMA VARIAVEL STRUCT CAD_CLIENTE AUX
QUE SERÁ NOSSO AUXILIAR PARA RECEBER OS DADOS PREENCHIDOS*/
struct cad_cliente preencher_dados ()
{
	
struct cad_cliente aux;
printf ("\n\n\n");	
aux.codigo= rand() % 10; //DEFINIMOS UM CÓDIGO RANDÔMICO USANDO A FUNÇÃO "RAND";
	printf ("                                       	       +      Código: %i\n ",aux.codigo);
	
	
	
		
	printf ("                                              +      Nome: ");
	fflush (stdin);
	gets (aux.nome);
	printf ("                                               +      Endereço: ");
	fflush (stdin);
	gets (aux.endereco);
	printf ("                                               +      Telefone: ");
	fflush (stdin);	
	gets (aux.telefone);
	printf ("                                               +      CPF (Somente números): ");
	fflush(stdin);
	scanf("%f",&aux.cpf);
	aux.cad_ativo = 2; /*A VARIAVEL "CAD_ATIVO" SEMPRE RECEBERÁ 2 NO MOMENTO DO CADASTRO, POIS
	SIGNIFICA QUE O CADASTRO FEITO SERÁ UM "CADASTRO ATIVO" */
	
	printf ("\n\n\n");
	
	printf ("======================================== Cadastro Realizado com Sucesso! ===============================================\n\n");

 	
	printf ("\n\n Pressione qualquer tecla para retornar ao menu: ");
	getch();
	system("cls");	
	return aux;/* A FUNCAO RETORNARÁ O AUX, QUE SÃO OS DADOS DAS VARIÁVEIS DA STRUCT PREENCHIDOS*/
	
			
		
}

/*FUNCAO CONSULTA, FAZ UMA CONSULTA INDIVIDUAL DE CADASTROS USANDO COMO DADO DE PESQUISA O CPF DO CLIENTE*/
void consulta_cliente()
{	
	int opcao2;
	float cod_cli;
	printf ("\n=================================================== C O N S U L T A ====================================================\n\n"); 
	printf ("                                       	        +      CPF: ");
	scanf ("%f",&cod_cli);
	system("cls");                                      /*PROGRAMA PEDE O CPF PARA REALIZAR A CONSULTA*/
	printf ("\n\n                                               +      Consulta do cpf: %.f\n\n",cod_cli);
	
	
	for(i=0;i<num_clientes;i++)
	{		if (cod_cli == cc[i].cpf)
			{
			printf ("\n=================================================== C O N S U L T A ====================================================\n\n");
			if (cc[i].cad_ativo == 2){ // - ESTA CONDIÇÃO, CASO VERDADEIRA, INFORMA AO USUÁRIO QUE O CADASTRO ESTÁ ATIVO;
				printf (" STATUS DO CADASTRO: ATIVO\n\n");
			}
			if (cc[i].cad_ativo == 1){// - ESTA CONDIÇÃO, CASO VERDADEIRA, INFORMA AO USUÁRIO QUE O CADASTRO ESTÁ INATIVO;
				printf ("STATUS DO CADASTRO: INATIVO\n\n");
				
			} /*APRESENTA OS DADOS DO CLIENTE PESQUISADO*/
			printf ("                                       	      +      Código: %i\n" ,cc[i].codigo);					
			printf ("                                              +      Nome do Cliente: %s\n",cc[i].nome);			
			printf ("                                              +      Endereco: %s\n",cc[i].endereco);			
			printf ("                                              +      Telefone: %s\n",cc[i].telefone);
			printf ("                                       	      +      CPF: %.f\n ",cc[i].cpf);
			break;						
			}
		}/*CASO O USUÁRIO INSIRA UM CPF QUE NÃO CONSTA NOS CADASTROS
		O PROGRAMA INFORMA QUE O POSSIVEL CLIENTE NÃO FOI CADASTRADO*/
			if(cod_cli != cc[i].cpf){
				printf("\n\n");
				printf ("\n=============================================== CLIENTE NÃO CADASTRADO =================================================\n\n");
			}
				printf ("\n========================================================================================================================\n\n");
				printf ("                                         +       O que deseja fazer?\n");
				printf ("                                         +       1 - Continuar consulta individual\n");				
				printf ("                                         +       0 - Retornar ao menu\n\n");
				scanf ("%i",&opcao2);
				
					if (opcao2 == 1){            /*INSERIMOS UMA CONDICAO PARA EVITAR QUE O USUÁRIO TENHA
												QUE RETORNAR AO MENU A CADA AÇÃO REALIZADA, INSERIMOS UMA
												RECURSIVIDADE (FUNÇÃO RETORNA ELA MESMA.*/
						system("cls");
						consulta_cliente();
					}
							
					
					if (opcao2 == 0){//CASO O USUÁRIO QUEIRA, É POSSIVEL RETORNAR AO MENU APÓS REALIZAR
											
						printf ("                                 +        Pressione qualquer tecla para retornar ao Menu\n");
					}
			
		
			
		
			
				
				
}
/*FUNCAO LISTAR CLIENTES É UMA OUTRA FORMA DE CONSULTA DE CADASTROS, MAS AQUI,
O USUÁRIO LISTA TODOS OS CADASTROS REALIZADOS, ATIVOS OU INATIVOS*/
void listar_clientes()
{	int opcao;
	
	
		printf ("\n=========================================== L I S T A  D E  C L I E N T E S  ===========================================\n\n");
		
		printf ("Quais clientes deseja listar??\n\n");/*MENU PARA ESCOLHA DO USUÁRIO
														SE DESEJA CONSULTAR OS CADASTROS ATIVOS OU INATIVOS*/
		printf (" 1 - Ativos\n");
		printf (" 2 - Inativos\n");
		scanf ("%i",&opcao);
		
			switch (opcao)
			{
				/*CASO ESCOLHA 1, O PROGRAMA APRESENTA TODOS OS CADASTROS ATIVOS*/	
				case 1:
				for (i=0;i<num_clientes;i++)
				{
					if (cc[i].cad_ativo == 2)//REALIZADO COM BASE NA VARIÁVEL DA STRUCT CAD_ATIVO;
					{				
					printf ("                                    	    +      Código: %i\n" ,cc[i].codigo);					
					printf ("                                           +      Nome do Cliente: %s\n",cc[i].nome);			
					printf ("                                           +      Endereco: %s\n",cc[i].endereco);			
					printf ("                                           +      Telefone: %s\n",cc[i].telefone);
					printf ("                                           +      CPF: %.f\n ",cc[i].cpf);
					printf ("\n\n");
					printf ("========================================================================================================================\n\n");	
					}
				}
				break;
				
				/*CASO ESCOLHA 2, O PROGRAMA APRESENTA TODOS OS CADASTROS INATIVOS*/
				case 2:
					for (i=0;i<num_clientes;i++)
				{
					if (cc[i].cad_ativo == 1)//REALIZADO COM BASE NA VARIÁVEL DA STRUCT CAD_ATIVO;
					{				
					printf ("                                    	    +      Código: %i\n" ,cc[i].codigo);					
					printf ("                                           +      Nome do Cliente: %s\n",cc[i].nome);			
					printf ("                                           +      Endereco: %s\n",cc[i].endereco);			
					printf ("                                           +      Telefone: %s\n",cc[i].telefone);
					printf ("                                       	+      CPF: %.f\n ",cc[i].cpf);
					printf ("\n\n");
					printf ("========================================================================================================================\n\n");	
					}
				}
				break;					
			}
}

/*FUNCAO EXCLUIR, OPTAMOS POR DESATIVAR POR ESCOLHA DO USUÁRIO, SENDO POSSÍVEL CASO QUEIRA, REATIVAR O CADASTRO.*/
void excluir_clientes()
{					
					int j,opcao,opcao2;				
					float cod_cli;
					//MENU PARA ESCOLHAS;
					printf ("\n========================================== A T I V A R / D E S A T I V A R ===================================\n\n"); 
					printf ("\n");
					printf ("                         +               O que deseja fazer?\n\n ");
					printf ("                        +               1 - Desativar Cliente\n");
					printf ("                         +               2 - Ativar Cliente\n");
					printf ("                         +               0 - Retornar ao menu\n");
					scanf ("%i",&opcao);
							switch (opcao)
							{//TODAS AS PESQUISAS SAO FEITAS SOLICITANDO O CPF DO CLIENTE, PARA EVITAR REPETIÇÕES;
							/*CASO 1 - O USUÁRIO PODE DESATIVAR CADASTROS*/
								case 1:
								printf ("                                       +     Digite o cpf do cliente:\n\n ");
								fflush(stdin);
								scanf ("%f",&cod_cli);	
							for (i=0;i<num_clientes;i++)
							{					
								if (cod_cli == cc[i].cpf)
								{//ANTES DE DESATIVAR, O PROGRAMA APRESENTA OS DADOS PARA CONFIRMAÇÃO DO USUÁRIO;
								printf ("                                       +     Código = %i\n",cc[i].codigo);
								printf ("                                       +     Nome = %s\n",cc[i].nome);
								printf ("                                       +      CPF: %.f\n ",cc[i].cpf);
								printf ("\n\n");
								printf ("                +         Deseja desativar este cliente? 1-sim / 2-não ");
								scanf ("%i",&cc[i].cad_ativo);//O CADASTRO É ALTERADO DIRETO NA VARIAVEL CAD_ATIVO;
								break;													
								}																
						}
							if(cod_cli != cc[i].cpf) {
										
							printf ("Código inválido ");
						}
					
							break;
							/*CASO 2 - O USUÁRIO PODE REATIVAR CADASTROS*/
								case 2:
								printf ("                                       +     Digite o CPF do cliente:\n\n ");
								fflush(stdin);
								scanf ("%f",&cod_cli);	
			
							for (i=0;i<num_clientes;i++)
							{	
					
								if (cod_cli == cc[i].cpf)
								{
								printf ("                                       +     Código = %i\n",cc[i].codigo);
								printf ("                                       +     Nome = %s\n",cc[i].nome);
								printf ("                                      +     CPF: %.f\n ",cc[i].cpf);
								printf ("\n\n");
						/*É APRESENTADO O CADASTRO CONTENDO ALGUNS DADOS DO CLIENTE, PARA EFETUAR ATIVAR/DESATIVAR*/
								printf ("                +         Deseja ATIVAR este cliente? [2-sim] / [1-não] ");
								scanf ("%i",&cc[i].cad_ativo);	
								break;												
								}																
							
				}
							if(cod_cli != cc[i].cpf) {
							/*CASO O USUÁRIO, INSIRA UM CPF QUE NAO EXISTA, APRESENTA UMA MENSAGEM CÓDIGO INVALIDO*/				
							printf ("Código inválido ");
						}
							break;
								case 0:
								break;
								default:
								printf ("                         +         *****  Código invalido  *****\n");
								break;
							}
						/*NOVAMENTE INSERIMOS UMA RECURSIVIDADE, CASO O USUÁRIO QUEIRA, ELE PODE ATIVAR OU DESATIVAR CADASTROS
						SEM RETORNAR AO MENU*/	
						system("cls");
						printf ("                                             +      O que deseja fazer?\n");
						printf ("                                             +      1 - Desativar/Ativar cadastros\n");
						printf ("                                             +      2 - Consultar cadastros\n");
						printf ("                                             +      0 - Retornar ao menu\n\n");
						scanf ("%i",&opcao2);
								if (opcao2 == 1)
								{	
									system("cls");								
									excluir_clientes();									
								}
						/*NESSA PARTE, O USUÁRIO TEM A OPCAO DE FAZER UMA CONSULTA A TODOS OS CADASTROS, PARA CONFIRMAR 
						OS QUE ELE DESEJA DESATIVAR, APÓS ISSO, ELE NOVAMENTE RETORNA A TELA DE MANIPULAÇÃO DE CADASTROS*/		
								if (opcao2 == 2)
								{
									system("cls");
									listar_clientes();
									system("pause");
									system("cls");
									excluir_clientes();	
								}
						/*DIGITANDO 0 ELE RETORNA AO MENU PRINCIPAL*/										
								if (opcao2 == 0)
									system("cls");	
						
}

/*FUNCAO COMPRAS, AQUI CONTROLAMOS UM FLUXO DE CAIXA ONDE É SOLICITADO O CPF DO CLIENTE
SOMENTE ASSIM, O USUÁRIO PODERÁ EFETUAR UMA POSSIVEL COMPRA*/

float compras_cliente()
{

	int dog,p,beb;
	float cod_compra;
	float soma=0;
	printf("========================================================================================================================\n");
	printf("                                         +    Informe o cpf do cliente: \n");	
	scanf("%f",&cod_compra);
	system("cls");
	for(i=0;i<num_clientes;i++){
	/*NESTA PARTE, O USUÁRIO INSERE O CPF DO CLIENTE, E SOMENTE CADASTROS ATIVOS PODEM EFETUAR A COMPRA,
	CASO CONTRÁRIO O PROGRAMA ENVIARÁ UMA MENSAGEM DE QUE "O CADASTRO ESTÁ INATIVO E QUE NÃO É POSSIVEL
	REALIZAR COMPRAS NESTE CPF*/
	if(cod_compra == cc[i].cpf && cc[i].cad_ativo==2){
	
	/*CASO O CPF ESTEJA ATIVO, É APRESENTADO UM MENU CONTENDO ALGUNS TIPOS DE DOGS PARA ESCOLHA DO USUÁRIO*/
	 do{ 
	 	printf ("====================================================== D O G S =========================================================\n\n"); 
  	    printf("               1- Dog da casa -------------- R$ 15,00\n");
	 	printf("           *Frango, bacon, maionese, ervilha, milho, 2 vinas, molho da casa, catupiry, cheddar, tomate, calabresa\n\n");
		printf("               2- Dog Avontz --------------- R$ 9,00\n ");
		printf("           *Calabresa, bacon, 2 vinas, batata palha, molho da casa, purê, tomate\n\n");
		printf("               3- Dog Boqueirão ------------ R$ 9,00\n");
		printf("           *Catupiry, milho, batata palha, 2 vinas, ervilha, tomate, bacon\n\n");
					
		printf("==================================================== B E B I D A S =====================================================\n\n");
		printf("                                          1- Refrigerantes ------- R$ 4,00\n");
		printf("                                          2- Sucos --------------- R$ 3,50\n");
		printf("                                          3- Água ---------------- R$ 2,50\n");
		printf ("\n");
		printf("    			                                                             *0 (zero), caso não deseje bebida.\n\n");
		printf("========================================================================================================================\n\n");
		
		// PROGRAMA PERGUNTA QUAIS AS OPÇÕES DESEJADAS PELO CLIENTE			
		printf("                                   +       Qual opção de dog: ");
		fflush(stdin);
		scanf("%i",&dog);
		printf("                                   +       Qual bebida: ");
		fflush(stdin);
		scanf("%i",&beb);
		
		//SWITCH FAZ O CÁLCULO DOS PEDIDOS;
		switch(dog){
		case 1:
			soma= soma+15;
			
			break;
		case 2:
		    soma= soma+9;
		    
			break;
		case 3:
		    soma= soma+9;
		    
			break;		
		
	}
	switch(beb){
		case 1:
			soma= soma+4;
			
			break;
		case 2:
			soma= soma+3,50;
			
			break;	
		case 3:
			soma= soma+2,50;
			
			break;
		case 0:
			break;	
	}
	/*PROGRAMA PERGUNTA SE O CLIENTE DESEJA OUTRO PEDIDO*/
   printf("                                   +       Deseja outro dog? 1- sim/ 2- não \n");
   fflush(stdin);
   scanf("%i",&p);      
   system("cls");
        
	}
	
	
	/*FUNCAO DO/WHILE VERIFICA SE O CLIENTE DESEJA REALIZAR MAIS ALGUM PEDIDO
	OFERECENDO A OPCAO CASO ELE NAO QUEIRA OUTRA BEBIDA*/
	while(p!= 2);
	return soma;//FUNCAO RETORNA O VALOR TOTAL DA COMPRA DO CLIENTE;
	
} 

}
  if(cc[i].cad_ativo != 2){
  	/*MENSAGEM CASO DA COMPRA, O CADASTRO ESTEJA INATIVO*/
	printf("\n==================================================== CADASTRO INATIVO  ================================================\n\n\n");
	getch();
}

}
				 

/*FUNCAO CONTA_CLIENTE RECEBE A SOMA E APRESENTA O VALOR A PAGAR*/
void conta_cliente()
{
	int conta_cli;
	float total_pagar,cod_cli;
	/*VARIÁVEL TOTAL_PAGAR RECEBE A FUNCAO COMPRAS_CLIENTE,COM O VALOR */
	total_pagar = compras_cliente();	
	printf("\n==================================================== P A G A M E N T O S ===============================================\n\n");	
	printf ("                                               +     Total a Pagar: %.2f\n\n",total_pagar);
    getch();	
    system("cls");

}
/*AQUI INICIA A FUNCAO PRINCIPAL (MAIN)*/
int main ()
{
	system("color F0");
	setlocale(LC_ALL,"portuguese");
	int opcao;	
	struct cad_cliente nc;//DECLARAMOS A ESTRUTURA (STRUCT);	

	
	/*FUNCAO DO/WHILE PARA O USUÁRIO TER ACESSO AO PROGRAMA
	ENQUANDO NÃO FINALIZAR (0 - SAIR))*/	
	do{			
	opcao=menu();//OPCAO RECEBE A FUNCAO MENU, NO QUAL O CLIENTE ESCOLHEU A OPÇÃO DESEJADA NO INÍCIO;
	
	/*SWITCH/CASE PARA RECEBER AS OPCOES ESCOLHIDAS*/	
	switch(opcao)
	{
		case 1:
		printf ("\n=================================================== C A D A S T R O ===================================================\n\n"); 
		if (num_clientes == N)
		{
		
			printf (" Não é possível cadastrar novos clientes.\n\n");
			printf(" BANCO DE DADOS cheio. Por favor, altere o valor do DEFINE.\n\n");
			printf("========================================================================================================================\n\n");
			system("pause");
			break;		
		
		}
		nc = preencher_dados();/*AQUI A VARIÁVEL STRUCT CAD_CLIENTE NC, RECEBE A FUNCAO PREENCHER_DADOS
		NO CASO, APÓS O PREENCHIMENTO, ESTA VARIAVEL RECEBE UM CADASTRO COMPLETO*/
		cadastro_feito(nc);	/*A FUNCAO CADASTRO_FEITO É EXECUTADA,E O VETOR RECEBE MAIS UM CADASTRO */	
		break;
				
		/*CASE 2 - EXECUTA A FUNCAO CONSULTA_CLIENTE*/				
		case 2:
		consulta_cliente();	
			
		getch ();
		system("cls");
		break;
	  
		/*CASE 3 - EXECUTA A FUNCAO LISTAR_CLIENTES*/
		case 3:
		listar_clientes();
		printf ("\n\n Pressione qualquer tecla para retornar ao menu: ");				
		getch ();
		system("cls");		
		break;
		
		/*CASE 4 - EXECUTA A FUNCAO EXCLUIR_CLIENTES (ATIVAR / DESATIVAR) */
		case 4:
		excluir_clientes();
		printf ("\n\n Pressione qualquer tecla para voltar ao menu");
		getch ();
		system("cls");
		break;
		/*CASE 5 - EXECUTA A FUNCAO CONTA_CLIENTE*/	
		case 5:	
		conta_cliente();
		break;
			
				 
	}
    
	
	
	
}
/*ENQUANTO O CLIENTE NÃO DIGITAR PARA SAIR DO PROGRAMA*/	
while (opcao != 0);	
/*CASO ELE SAIA, O PROGRAMA APRESENTA UMA MENSAGEM, E FINALIZA O PROGRAMA.*/	
	printf("========================================================================================================================\n\n");
	
	printf("========================================================================================================================");
	printf  ("\n                                             | | OBRIGADO E VOLTE SEMPRE! | |\n\n");
	
	printf("========================================================================================================================\n\n");
	printf("========================================================================================================================\n\n");
	
	
	system("pause");
	return 0;
}




