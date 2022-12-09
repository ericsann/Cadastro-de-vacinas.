#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
/*==============PACIENT REGISTRATION==============*/
struct cadastro{
	char nome[30];
	char cpf[15];
	char vacina[15];
	char data[15];
	int lote;
};
/*==============MAIN ALGORITHM==============*/
int main(){
	setlocale(LC_ALL, "Portuguese");
	struct cadastro ficha[999];
	int op, i, cont, acha;
	char cpfbusca[15];
	i=0;
	cont=0;
/*==============MENU OPTIONS==============*/
	while (op!=4){
		system("cls");
		printf("1- Cadastrar Vacina.\n");
		printf("2- Listar Aplicações.\n");
		printf("3- Consultar por CPF.\n");
		printf("4- Sair.\n");
		scanf("%d", &op);
		fflush(stdin);
		switch(op){
			case 1:
				system("cls");
				printf("Digite o nome do paciente:\n");
				gets(ficha[i].nome);
				fflush(stdin);
				printf("Digite o CPF do paciente:\n");
				gets(ficha[i].cpf);
				fflush(stdin);
				printf("Digite a vacina aplicada:\n");
				gets(ficha[i].vacina);
				fflush(stdin);
				printf("Digite a data de aplicação:\n");
				gets(ficha[i].data);
				fflush(stdin);
				printf("Digite o lote da vacina:\n");
				scanf("%d", &ficha[i].lote);
				fflush(stdin);
				i++;
				cont=i;
				break;
			case 2:
				system("cls");
				for(i=0;i<cont;i++){
					printf("Código: %d\n", i);	
					printf("Nome: %s\n", ficha[i].nome);
					printf("CPF: %s\n", ficha[i].cpf);
					printf("Vacina: %s\n", ficha[i].vacina);
					printf("Data: %s\n", ficha[i].data);
					printf("Lote: %d\n", ficha[i].lote);
					printf("===============================================\n");
				}
				system("pause");
				break;
			case 3:
				system("cls");
				i=0;
				acha=0;
				printf("Digite o CPF para busca:\n");
				gets(cpfbusca);
				while((i<cont) && (acha == 0)){
					if(strcmp(ficha[i].cpf, cpfbusca)==0){
						acha=1;
					}
					else{
						i++;
					}
					if (acha == 1){
					printf("Nome: %s\n", ficha[i].nome);
					printf("CPF: %s\n", ficha[i].cpf);
					printf("Vacina: %s\n", ficha[i].vacina);
					printf("Data: %s\n", ficha[i].data);
					printf("Lote: %d\n", ficha[i].lote);
					}
					else{
						printf("Paciente não cadastrado");		
					}						
				}
				system("pause");
				break;
			case 4:
				system("cls");
				printf("Saindo...\n");
				break;
			default:
				system("cls");
				printf("Opção inválida\n");
				system("pause");
				break;				
		}		
	}
	return(0);
}
