#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#include <stdbool.h>

// #define MAX 500
#define MAX 500000
#define ERRO -1

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;   // prioridade
    TIPOCHAVE chave2;  // tempo de preparo
    char nome[50];     // nome do prato
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int nroElem;
} LISTA;

// Funções públicas
void inicializarLista(LISTA* l);
int tamanho(LISTA* l);
bool inserirElemLista(LISTA* l, REGISTRO reg, int i);
void exibirLista(LISTA* l);
bool carregarDadosCSV(const char* nomeArquivo, LISTA* lista);
void copiarLista(LISTA* destino, LISTA* origem);

#endif
