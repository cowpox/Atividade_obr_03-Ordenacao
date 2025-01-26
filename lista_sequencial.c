/******************************************************************************
//     listaSequencial.c
// Este programa gerencia listas lineares sequenciais.
// As listas gerenciadas podem ter MAX elementos (posicoes de 0 a MAX-1 no
//   arranjo A). 
******************************************************************************/
#include "lista_sequencial.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inicializarLista(LISTA* l) {
    l->nroElem = 0;
}

/* Retornar o tamanho da lista (numero de elementos "validos") */
int tamanho(LISTA* l) {
  return l->nroElem;
} /* tamanho */

bool inserirElemLista(LISTA* l, REGISTRO reg, int i) {
    if ((l->nroElem >= MAX) || (i < 0) || (i > l->nroElem)) 
        return false; // Lista cheia ou índice inválido
    for (int j = l->nroElem; j > i; j--) 
        l->A[j] = l->A[j-1];
    l->A[i] = reg;
    l->nroElem++;
    return true;
}

void exibirLista(LISTA* l) {
    printf("Lista:\n");
    for (int i = 0; i < l->nroElem; i++) {
        printf("Prioridade: %d, Tempo: %d, Nome: %s\n", 
               l->A[i].chave, l->A[i].chave2, l->A[i].nome);
    }
}

bool carregarDadosCSV(const char* nomeArquivo, LISTA* lista) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return false;
    }

    char linha[100];
    int linhaAtual = 0;

    // Ler cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo)) {
        linhaAtual++;

        // Ignorar o cabeçalho
        if (linhaAtual == 1) continue;

        REGISTRO reg;
        char* token;

        // Extrair o campo 'prioridade'
        token = strtok(linha, ",");
        if (token == NULL) {
            printf("Erro ao processar a linha %d: %s\n", linhaAtual, linha);
            continue;
        }
        reg.chave = atoi(token);

        // Extrair o campo 'tempo'
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Erro ao processar a linha %d: %s\n", linhaAtual, linha);
            continue;
        }
        reg.chave2 = atoi(token);

        // Extrair o campo 'nome'
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Erro ao processar a linha %d: %s\n", linhaAtual, linha);
            continue;
        }
        strncpy(reg.nome, token, sizeof(reg.nome));
        reg.nome[strcspn(reg.nome, "\n")] = '\0';  // Remover o caractere de nova linha, se presente

        // Inserir na lista
        if (!inserirElemLista(lista, reg, lista->nroElem)) {
            printf("Erro ao inserir elemento na lista\n");
            fclose(arquivo);
            return false;
        }
    }

    fclose(arquivo);
    return true;
}



