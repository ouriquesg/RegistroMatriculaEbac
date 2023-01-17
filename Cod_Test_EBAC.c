#include <stdio.h> // <-- Biblioteca de comunicação com o usuário, e lembrando que ela não contém acentos, apenas textos e letras simples. //
#include <stdlib.h> // <-- Biblioteca para alocação de espaço na memória. //
#include <locale.h> // <-- Biblioteca de texto por região, será responsável pelos acentos e caracteres especiais. //
#include <string.h> // <-- Biblioteca que é responsável por armazenar as strings //

// NOVA MATRICULA
int matricula()
{
	// VARIÁVEIS
	char arquivo[16];
	char cpf[16];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Mensagem de saudação pela escolha
	printf("\t ### Você escolheu nova matrícula ###\n\n");
	// Pedindo o CPF
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	// Comando biblioteca para alocar uma string na outra
	strcpy(arquivo,cpf); // Responsável por copiar os valores das strings
	// Gerando arquivo
	FILE *file; // Antes do asteriscos é o comando para buscar na biblioteca a função criar arquivo, e depois o nome que tu vai dar aquele arquivo criado.
	file = fopen(arquivo,"w"); // Com arquivo criado, você abre o arquivo "fopen" com nome da variável escolhida e determino que é para salvar um novo usando o "w" wright.
	fprintf(file,cpf); // Salva o valor da variável determinada.
	fclose(file); // Fechamento e conclusão do arquivo gerado.
	// Dando espaço entre as informações armazenadas.
	file = fopen(arquivo,"a"); // O comando "a" serve para atualizar a informação.
	fprintf(file," -> CPF\n"); // Incluindo mais informações.
	fclose(file); // Fechar o arquivo depois de qualquer atualização.
	// Pedindo o NOME
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	// Armazenando o nome
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	// Comando VÍRGULA
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
	// Comando Vírgula
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
	// Comando Vírgula
	file = fopen(arquivo,"a");
	fprintf(file," -> CARGO\n");
	fclose(file);
	
	system("pause"); // FIM CADASTRO DE MATRÍCULA
}
// CONSULTA MATRICULA
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Uma função não acessa a outra, sendo assim para reconhecer acentos tem que colocar o comando em todos que sejam necessários.
	// VARIÁVEIS
	char cpf[16];
	char conteudo [200];
	// Mensagem de saudação pela escolha 
	printf("\t ### Você escolheu consultar matrícula ###\n\n");
	// Início de CONSULTA
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	printf("\nEssas são as informações do usuário: \n");
	// Usando biblioteca para consultar
	FILE *file;
	file = fopen(cpf,"r"); // Read "r" é para ler o arquivo que foi criado na etapa anterior
	// VALIDADOR -- Caso não ache o arquivo
	if(file == NULL)
	{
		printf("### ERRO ### CPF inválido ou NÃO cadastrado ###\n");
	}
	// Gerar um laço para tentar localizar o conteúdo. "fgets" = Buscar nos arquivos de outra forma 
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	system("pause");
}
// DELETAR MATRICULA
int deletar()
{
	// VARIÁVEIS
	char cpf[16];
	// Mensagem de saudação
	printf("\t ### Você escolheu o cancelamento de matrícula ###\n");
	// INICIO DELETE
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf); // Info que o usuário fornece
	// Função/Comando DELETAR
	remove(cpf);
	// Validação para DELETAR corretamente.
	FILE *file; // Buscar nos arquivos
	file = fopen(cpf,"r"); // "r" Read ler o arquivo
	// Validação etapa 2
	if(file == NULL)
	{
		printf("### NÃO existe matrículas com esse CPF no sistema!. ###\n");
		system("pause");
	}
}
// ESCOLHA ERRADA
int erro()
{
	printf("\t ### ERRO !! Você escolheu uma opção inválida! ###\n");
	system("pause");
}
// INICIO DO PROGRAMA - MENU
int main()
{	
		// Variáveis
	int opcao=0;
	int laco=1;
		// Declarando operador de repetição
	for (laco=1;laco=1;)
	{
		system("cls"); // Clean para o reset e reiniciar o menu.
		
		setlocale(LC_ALL, "Portuguese"); // <-- Responsável por definir qual a região da biblioteca que o computador deve buscar. 
			//Cabeçalho do Menu - Ínicio Menu
		printf("\t ### Registro de Alunos EBAC ###\n"); // <-- Lembrar que o "\n" é para quebrar a linha	
		printf("#### Bem vindo a tela principal colaborador. ####\n\n");
		printf("\tEscolha uma das opções do menu:\n\n"); // <-- "\t" Ele vai executar um espaço antes da frase
			//Opções do menu -- Ajustar depois se necessário
		printf("\t1 - Matrícular Aluno\n");
		printf("\t2 - Consultar Matrícula\n");
		printf("\t3 - Cancelamento de Matrícula\n");
		printf("\nQual a opção que você deseja escolher: ");
			// Fim Menu
			//Comandos
		scanf("%d", &opcao); // Armazanando a opção.
		system("cls"); // Clean na tela para um novo menu apartir da escolha que o usuário fez.
	
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
			//Créditos //Assinatura // Rodapé
		printf("\n\n#### Software desvolvido por Guilherme Vargas Ouriques. ####\n\n");
			//Assinado dessa maneira para identificar o meu nome ao enviar o projeto modificar depois.
	}
}
