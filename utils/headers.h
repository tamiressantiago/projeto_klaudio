#include <string.h>
#include <stdio.h>

#ifndef MEU_HEADER_H
#define MEU_HEADER_H

// Declaração de estruturas
struct livros{
	char titulo[100];
	char autor[50];
	char genero[50];
	int qtd_paginas;
	int lancamento;
};

// declaração de funções
int menu(){
	int op;
	
	printf("[1] - Cadastrar Livro\n");
	printf("[2] - Ver livros\n");
	printf("[3] - Filtrar\n");
	printf("[0] - Sair\n");
	scanf("%d", &op);
	
	return op;
}

void cadastrar_livro(struct livros livro1){
	FILE *db;
	db = fopen("database/teste.txt", "a");

	if(db){
		printf("- Digite as informacoes do livro -");

		getchar();
		printf("\nTitulo: ");
		fgets(livro1.titulo, 100, stdin);
		livro1.titulo[strcspn(livro1.titulo, "\n")] = '\0';

		printf("\nAutor: ");
		fgets(livro1.autor, 50, stdin);
		livro1.autor[strcspn(livro1.autor, "\n")] = '\0';

		printf("\nGenero: ");
		fgets(livro1.genero, 50, stdin);
		livro1.genero[strcspn(livro1.genero, "\n")] = '\0';


		printf("\nTotal de paginas: ");
		scanf("%d", &livro1.qtd_paginas);
		getchar(); //limpar buffer
		
		fprintf(db, "\n%s, \n%s, \n%s, \n%d\n", livro1.titulo, livro1.autor, livro1.genero, livro1.qtd_paginas);
		
		fclose(db);
	}
	else{
		printf("Base de dados nao encontrada.\n");
	}
}

void pegar_info(){
	FILE *db;
	char c;
	db = fopen("database/teste.txt", "r");
	
	if (db){
		while((c = getc(db)) != EOF){
			printf("%c", c);
		}
		fclose(db);
	}
	else{
		printf("Base de dados nao encontrada\n");
	}

}


void pegar_chave(){
	FILE *db;
	char c;
	char chave[50];

	printf("Digite a chave: \n");
	fgets(chave, 50, stdin);
	chave[strcspn(chave, "\n")] = '\0';

	db = fopen("database/teste.txt", "r");
	if (db){
		while((c = getc(db)) != EOF){
			if (strcmp(c, chave) == 0){
				printf("%c", c);
			}
			else{
				printf("Titulo nao encontrado");
			}
		}
		fclose(db);
	}
	else{
		printf("Base de dados nao encontrada\n");
	}
	
}

#endif