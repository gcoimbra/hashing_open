// TRABALHO PRÁTICO DE AEDS II

// Alunos: Gabriel Coimbra - 3044
// 				 Maria Dalila Vieira - 3030
//				 Naiara Cristine - 3005

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_HASH 7
#define MAX_STRING 20

typedef struct item item;
typedef struct item{
	int codigo;
	char nome[MAX_STRING];
}item;

typedef struct hashOpen
{
	int weights[MAX_HASH];
	item info[MAX_HASH];
} hashOpen;

void hashOpenCria(hashOpen *table);
void hashOpenPesquisa(hashOpen *table, char *reg);
int hashOpenTransfrom(hashOpen *table, char *reg);
void hashOpenInsere(hashOpen *table,char *reg, int cod);
void hashOpenImprime(hashOpen *table);
