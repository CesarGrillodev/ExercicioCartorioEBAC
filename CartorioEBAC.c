
#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca que gerencia as string

int registrar()// 
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40]; //reserva da memória para as variáveis strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s",cpf); //entrada do usuário com uma string
	
	strcpy(arquivo, cpf); //responsável por nomear o arquivo com a string cpf
	
	FILE *file; //busca um arquivo
	file = fopen(arquivo, "w"); //inicia o conteúdo do arquivo
	fprintf(file,cpf); //salva o valor da variável no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualiza conteúdo do arquivo
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
	
	printf("\nCadastro de usuário finalizado!\n\n");
	
	system("pause"); //pausa a tela para leitura do usuário
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
			
	if(file == NULL) // condição se o arquivo for nulo
	{
		printf("\nNão foi possível abrir o arquivo, CPF não cadastrado! \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // preenche a variável conteudo com as strings do arquivo
	{
		printf("\nInformações do usuário cadastrado: ");
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
	
	printf("Digite o CPF do usuário a ser deletado do sistema: \n");
	printf("CPF: ");
	scanf("%s",cpf);
	printf("\n");
	
	remove(cpf); //comando de remoção do conteúdo do arquivo cpf
			
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário deletado do sistema!\n\n");
		
		system("pause");
	}
}

int main() 
{	
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //retorna após fim da função escolhida
	{	
		system("cls");
					
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem/idioma
												
		printf("\t=== Cartório de registro de pessoas EBAC ===\n\n"); //início do menu								
		printf("\tDefina a opção desejada do menu:\n\n");
		printf("\t1 - Registrar usuário a ser cadastrado\n");
		printf("\t2 - Consultar usuário do cadastro\n");
		printf("\t3 - Excluir usuário do cadastro\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //fim do menu	
				
		scanf("%d", &opcao); //armazenando escolha do usuário
				
		system("cls");
		
		switch(opcao) //início da seleção
		{
			case 1:
			registrar(); // entrada da função criada
			break; // encerra a função
			
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
			
			default: // é acionado caso opção escolhida não exista
			printf("Essa opção não está disponível !\n");
			system("pause");
			break; 	
		}// final da seleção
	}
}

