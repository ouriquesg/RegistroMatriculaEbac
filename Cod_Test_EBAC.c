#include <stdio.h> // <-- Biblioteca de comunica��o com o usu�rio, e lembrando que ela n�o cont�m acentos, apenas textos e letras simples. //
#include <stdlib.h> // <-- Biblioteca para aloca��o de espa�o na mem�ria. //
#include <locale.h> // <-- Biblioteca de texto por regi�o, ser� respons�vel pelos acentos e caracteres especiais. //
#include <string.h> // <-- Biblioteca que � respons�vel por armazenar as strings //

// NOVA MATRICULA
int matricula()
{
	// VARI�VEIS
	char arquivo[16];
	char cpf[16];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Mensagem de sauda��o pela escolha
	printf("\t ### Voc� escolheu nova matr�cula ###\n\n");
	// Pedindo o CPF
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	// Comando biblioteca para alocar uma string na outra
	strcpy(arquivo,cpf); // Respons�vel por copiar os valores das strings
	// Gerando arquivo
	FILE *file; // Antes do asteriscos � o comando para buscar na biblioteca a fun��o criar arquivo, e depois o nome que tu vai dar aquele arquivo criado.
	file = fopen(arquivo,"w"); // Com arquivo criado, voc� abre o arquivo "fopen" com nome da vari�vel escolhida e determino que � para salvar um novo usando o "w" wright.
	fprintf(file,cpf); // Salva o valor da vari�vel determinada.
	fclose(file); // Fechamento e conclus�o do arquivo gerado.
	// Dando espa�o entre as informa��es armazenadas.
	file = fopen(arquivo,"a"); // O comando "a" serve para atualizar a informa��o.
	fprintf(file," -> CPF\n"); // Incluindo mais informa��es.
	fclose(file); // Fechar o arquivo depois de qualquer atualiza��o.
	// Pedindo o NOME
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	// Armazenando o nome
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	// Comando V�RGULA
	file = fopen(arquivo,"a");
	fprintf(file," -> NOME\n");
	fclose(file);
	// Pedindo o SOBRENOME
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	// Armazenando sobrenome
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	// Comando V�rgula
	file = fopen(arquivo,"a");
	fprintf(file," -> SOBRENOME\n");
	fclose(file);
	// Pedindo CARGO
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	// Armazenando cargo
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	// Comando V�rgula
	file = fopen(arquivo,"a");
	fprintf(file," -> CARGO\n");
	fclose(file);
	
	system("pause"); // FIM CADASTRO DE MATR�CULA
}
// CONSULTA MATRICULA
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Uma fun��o n�o acessa a outra, sendo assim para reconhecer acentos tem que colocar o comando em todos que sejam necess�rios.
	// VARI�VEIS
	char cpf[16];
	char conteudo [200];
	// Mensagem de sauda��o pela escolha 
	printf("\t ### Voc� escolheu consultar matr�cula ###\n\n");
	// In�cio de CONSULTA
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	printf("\nEssas s�o as informa��es do usu�rio: \n");
	// Usando biblioteca para consultar
	FILE *file;
	file = fopen(cpf,"r"); // Read "r" � para ler o arquivo que foi criado na etapa anterior
	// VALIDADOR -- Caso n�o ache o arquivo
	if(file == NULL)
	{
		printf("### ERRO ### CPF inv�lido ou N�O cadastrado ###\n");
	}
	// Gerar um la�o para tentar localizar o conte�do. "fgets" = Buscar nos arquivos de outra forma 
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	system("pause");
}
// DELETAR MATRICULA
int deletar()
{
	// VARI�VEIS
	char cpf[16];
	// Mensagem de sauda��o
	printf("\t ### Voc� escolheu o cancelamento de matr�cula ###\n");
	// INICIO DELETE
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf); // Info que o usu�rio fornece
	// Fun��o/Comando DELETAR
	remove(cpf);
	// Valida��o para DELETAR corretamente.
	FILE *file; // Buscar nos arquivos
	file = fopen(cpf,"r"); // "r" Read ler o arquivo
	// Valida��o etapa 2
	if(file == NULL)
	{
		printf("### N�O existe matr�culas com esse CPF no sistema!. ###\n");
		system("pause");
	}
}
// ESCOLHA ERRADA
int erro()
{
	printf("\t ### ERRO !! Voc� escolheu uma op��o inv�lida! ###\n");
	system("pause");
}
// INICIO DO PROGRAMA - MENU
int main()
{	
		// Vari�veis
	int opcao=0;
	int laco=1;
		// Declarando operador de repeti��o
	for (laco=1;laco=1;)
	{
		system("cls"); // Clean para o reset e reiniciar o menu.
		
		setlocale(LC_ALL, "Portuguese"); // <-- Respons�vel por definir qual a regi�o da biblioteca que o computador deve buscar. 
			//Cabe�alho do Menu - �nicio Menu
		printf("\t ### Registro de Alunos EBAC ###\n"); // <-- Lembrar que o "\n" � para quebrar a linha	
		printf("#### Bem vindo a tela principal colaborador. ####\n\n");
		printf("\tEscolha uma das op��es do menu:\n\n"); // <-- "\t" Ele vai executar um espa�o antes da frase
			//Op��es do menu -- Ajustar depois se necess�rio
		printf("\t1 - Matr�cular Aluno\n");
		printf("\t2 - Consultar Matr�cula\n");
		printf("\t3 - Cancelamento de Matr�cula\n");
		printf("\nQual a op��o que voc� deseja escolher: ");
			// Fim Menu
			//Comandos
		scanf("%d", &opcao); // Armazanando a op��o.
		system("cls"); // Clean na tela para um novo menu apartir da escolha que o usu�rio fez.
	
			//Estruturas condicional
		switch(opcao)
		{
			case 1:
				matricula();
				break;
			case 2:
				consulta();
				break;
			case 3:
				deletar();
				break;
			default:
				erro();
				break;
		} // Fim das estruturas
			//Cr�ditos //Assinatura // Rodap�
		printf("\n\n#### Software desvolvido por Guilherme Vargas Ouriques. ####\n\n");
			//Assinado dessa maneira para identificar o meu nome ao enviar o projeto modificar depois.
	}
}
