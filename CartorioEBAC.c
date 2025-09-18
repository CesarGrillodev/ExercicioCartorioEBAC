
#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca que gerencia as string

int registrar()// 
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40]; //reserva da mem�ria para as vari�veis strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s",cpf); //entrada do usu�rio com uma string
	
	strcpy(arquivo, cpf); //respons�vel por nomear o arquivo com a string cpf
	
	FILE *file; //busca um arquivo
	file = fopen(arquivo, "w"); //inicia o conte�do do arquivo
	fprintf(file,cpf); //salva o valor da vari�vel no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualiza conte�do do arquivo
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
		
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	printf("\nCadastro de usu�rio finalizado!\n\n");
	
	system("pause"); //pausa a tela para leitura do usu�rio
}

int consultar()
{
	char cpf[40];
	char conteudo[200];
	
	setlocale(LC_ALL, "Portuguese");
		
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
		
	FILE *file;
	file = fopen(cpf,"r"); //abre o arquivo para leitura 
			
	if(file == NULL) // condi��o se o arquivo for nulo
	{
		printf("\nN�o foi poss�vel abrir o arquivo, CPF n�o cadastrado! \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // preenche a vari�vel conteudo com as strings do arquivo
	{
		printf("\nInforma��es do usu�rio cadastrado: ");
		printf("%s", conteudo);
		printf("\n\n");
		
		system("pause");
	}
	
	fclose(file);
}

int excluir()
{
	char cpf[40];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF do usu�rio a ser deletado do sistema: \n");
	printf("CPF: ");
	scanf("%s",cpf);
	printf("\n");
	
	remove(cpf); //comando de remo��o do conte�do do arquivo cpf
			
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio deletado do sistema!\n\n");
		
		system("pause");
	}
}

int main() 
{	
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) //retorna ap�s fim da fun��o escolhida
	{	
		system("cls");
					
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem/idioma
												
		printf("\t=== Cart�rio de registro de pessoas EBAC ===\n\n"); //in�cio do menu								
		printf("\tDefina a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar usu�rio a ser cadastrado\n");
		printf("\t2 - Consultar usu�rio do cadastro\n");
		printf("\t3 - Excluir usu�rio do cadastro\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //fim do menu	
				
		scanf("%d", &opcao); //armazenando escolha do usu�rio
				
		system("cls");
		
		switch(opcao) //in�cio da sele��o
		{
			case 1:
			registrar(); // entrada da fun��o criada
			break; // encerra a fun��o
			
			case 2:
			consultar();
			break;
			
			case 3:
			excluir();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0; //faz com que encerre o sistema
			break;
			
			default: // � acionado caso op��o escolhida n�o exista
			printf("Essa op��o n�o est� dispon�vel !\n");
			system("pause");
			break; 	
		}// final da sele��o
	}
}

