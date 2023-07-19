// TRABALHO PRÁTICO DE AEDS II

// Alunos: Gabriel Coimbra - 3044
// 				 Maria Dalila Vieira - 3030
//				 Naiara Cristine - 3005

#include "HashOpen.h"

//Funcao de transformação com hashing universal
int hashOpenTransfrom(hashOpen *table, char *reg){
	assert(table != NULL);
	assert(reg != NULL);

	size_t index = 0;

	// Para cada letra, multiplica sua representação ASCII pelo valor do peso
	for (size_t i = 0; i < strlen(reg); i++)
		index += table->weights[(int)reg[i]] * reg[i];

	// Retorna no máximo MAX_HASH - 1
	return index % MAX_HASH;
}

void hashOpenCria(hashOpen *table)
{
	assert(table != NULL);

	// Inicializa tabela com código nulo para deteção de vazios
	for (size_t i = 0; i < MAX_HASH; i++)
		table->info[i].nome[0] = 0;

	// Gera pesos aleatórios
	for (size_t i = 0; i < MAX_HASH; i++)
		table->weights[i] = rand()%MAX_HASH;
}

void hashOpenInsere(hashOpen *table,char *reg,int cod)
{
	assert(table != NULL);
	assert(reg != NULL);

	int hash_code = hashOpenTransfrom(table,reg);
	assert(hash_code < MAX_HASH);
  assert(hash_code >= 0);

	// Hashing linear adiciona 1 até termos um espaço vazio
	while(table->info[hash_code].nome[0] != 0)
	{
		// Calcula próximo hash code
		hash_code += 1;
		hash_code = hash_code % MAX_HASH;
	}

	strcpy(table->info[hash_code].nome,reg);
	table->info[hash_code].codigo=cod;
}

void hashOpenPesquisa(hashOpen *table, char *reg)
{
	assert(table != NULL);
	assert(reg != NULL);

	int hash_code = hashOpenTransfrom(table,reg);

	assert(hash_code < MAX_HASH  && hash_code >= 0);

	int j = hash_code;

	if(strcmp(table->info[j].nome,reg) == 0){
		puts("Tripulante econtrado!");
		return;
	}

	// Percorre tabela até encontrar
	while(strcmp(table->info[j].nome,reg) != 0)
	{
		j += 1;
		j = j% MAX_HASH;

		// Percorremos tabela inteira, não existe registro
		if(hash_code == j){
				puts("Tripulante não econtrado!");
			return;
		}
	}
	printf("Tripulante econtrado!\n");
	printf("Nome: %s\nCódigo: %d\n", table->info[j].nome, table->info[j].codigo);
}

void hashOpenImprime(hashOpen *table)
{
	 int  i;
	 printf("\nTabela hash\n");
	 for(i = 0; i < MAX_HASH; i++)
	 {
		 if(table->info[i].nome[0] != 0)
			 printf("[%d]: %s codigo %d\n", i,table->info[i].nome,table->info[i].codigo);
	 }
}
