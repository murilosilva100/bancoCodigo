#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Funcionarios.h"
#include "cliente.h"

static char ADM[10] = "31031519", funcionario[10] = "12", cliente[10]= "13";


void menu_funcionario( FILE *arquivo_cliente, FILE *arquivo_funcionario){
	char menu_f;
	do{
		system("cls");
		printf("MENU Funcionário");
		printf("\n\n1 – Abetura de conta \n2 – Encerramento de conta \n3 – Consultar dados \n4 – Alterar dados \n5 – Cadastro de Funcionários \n6 – Gear relatórios \n7 - Sair");
		printf("\n\nEscolha uma opção: ");
		
		menu_f = getch();
		
		switch(menu_f){
			case '1':
				abrir_conta( arquivo_cliente );
			break;
			case '2':
				excluir_conta_senha( ADM, arquivo_cliente );
			break;
			case '3':
				consultar_dados(arquivo_cliente, arquivo_funcionario);
			break;
			case '4':
				alterar_dados(ADM, arquivo_cliente, arquivo_funcionario);
			break;
			case '5':
				cadastro_funcionario( arquivo_funcionario, ADM );
			break;
			case '6':
				gerar_relatorio(funcionario);
			break;
			case '7':
				printf("\n\nVolte sempre :)");
				sleep(1);
			break;
			default: 
				printf("\n\nOpção inválida!");
			break;
		}
	} while ( menu_f != '7');
}

void menu_cliente( FILE *arquivo_cliente){
	char menu_c;
	do{
		system("cls");
		printf("MENU Cliente\n");
		printf("\n1 - Saldo \n2 - Depósito \n3 - Saque \n4 - Extrato \n5 - Consultar limite \n6 - Sair");
		printf("\n\nEscolha uma opção: ");
		
		menu_c= getch();
		
		switch(menu_c){
			case '1':
				saldo_cliente(arquivo_cliente);
			break;
			case '2':
				deposito_cliente(arquivo_cliente);
			break;
			case '3':
				saque_cliente(arquivo_cliente);
			break;
			case '4':
				extrato_cliente(arquivo_cliente);
			break;
			case '5':
				consultarlimite_cliente(arquivo_cliente);
			break;
			case '6':
				printf("\n\nVoltando para o menu principal...");
				sleep(1);
				main();
			break;
			default:
				printf("\n\nOpção inválida. Tente novamente!");
				sleep(1);
			break;
		}	
	}	while (menu_c != '6');
}

void verificacao(char opcao, FILE *arquivo_cliente, FILE *arquivo_funcionario){
	char senha[10];
	
	if ( opcao == '1'){
		printf("Funcionário \n\ndigite sua senha: ");
		scanf(" %s", senha);
		if ( strcmp(senha, funcionario) == 0){
			//vai para o menu do funcionário
			printf("\nBem-Vindo Funcionário!");
			sleep(1);
			menu_funcionario(arquivo_cliente, arquivo_funcionario);
		}
		else{
			printf("\nSenha incorreta!");
			sleep(2);
		}
	}
	else {
		printf("Cliente \n\ndigite sua senha: ");
		scanf(" %s", senha);
		if ( strcmp(senha, cliente) == 0){
			//vai para o menu do cliente
			printf("\nBem-Vindo Cliente!");
			sleep(2);
			menu_cliente(arquivo_cliente);
		}
		else{
			printf("\nSenha incorreta!");
			sleep(2);
		}
	}
}

int main() {
	
//	abre os arquivos e define a linguagem
	setlocale(LC_ALL, "Portuguese");
	
	FILE *arquivo_cliente, *arquivo_funcionario;
	arquivo_cliente = fopen("dados cliente.txt", "r+");
	arquivo_funcionario = fopen("dados funcionario.txt", "r+");
	
	if( arquivo_cliente == NULL ){
		arquivo_cliente = fopen("dados cliente.txt", "w+");
	}
	if( arquivo_funcionario == NULL ){
		arquivo_funcionario = fopen("dados funcionario.txt", "w+");
	}
	if ( arquivo_cliente == NULL || arquivo_funcionario == NULL){
		printf("Não foi possivel abrir os arquivos");
		return 1;
	}
	
	char menu;
	
	//Menu principal
	do{
		system("cls");
		printf("  MENU\n\n");
		printf("1 - Funcionário \n2 - Cliente \n3 - Sair \n\nEscolha uma opção: ");
		menu = getch();
	
		switch(menu){
			
			case '1':
				//verifica a senha do funcionário
				system("cls");
				verificacao(menu, arquivo_cliente, arquivo_funcionario);
			break;
			case '2':
				//verifica a senha do cliente
				system("cls");
				verificacao(menu, arquivo_cliente, arquivo_funcionario);
			break;
			case '3':
				printf("\nVolte sempre :)");
			break;
			default: 
				printf("\nOpção inválida!");
				sleep(2);
			break;
		}
	}while ( menu != '3');
	
	
	return 0;
}
