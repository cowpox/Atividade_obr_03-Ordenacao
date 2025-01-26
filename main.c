#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_sequencial.c"

//convenções
typedef REGISTRO ITEM;
#define key(A) (A.chave)
// #define less(A, B) (key(A) < key(B)) // para apenas 1 chave
#define less(A, B) ((key(A) < key(B)) || (key(A) == key(B) && (A.chave2 < B.chave2))) // para 2 chaves
// #define lessequal(A, B) (key(A) <= key(B)) // para apenas 1 chave
#define lessequal(A, B) ((key(A) < key(B)) || (key(A) == key(B) && (A.chave2 <= B.chave2))) // para 2 chaves
#define swap(A, B) {ITEM temp = A; A = B; B = temp;}
#define comp_swap(A, B) {if (less(B, A)) swap(A, B);}
#define TOTAL_ELEMENTOS 500000

void bubble_sort_iterativo(LISTA* lista, int left, int right) {
    for (int i = right; i > left; i--) { // Percorre do final ao início
        for (int j = left; j < i; j++) { // Até a última posição não ordenada
            if (less(lista->A[j + 1], lista->A[j])) {
                swap(lista->A[j + 1], lista->A[j]); // Troca se necessário
            }
        }
    }
}

int quick_sort_partition(LISTA* lista, int left, int right) {
    ITEM pivot = lista->A[right];  // vamos iniciar escolhendo o pivot pela direita
    int j = left;
    for (int k = left; k < right; k++) {
        if (lessequal(lista->A[k], pivot)) {
            swap(lista->A[k], lista->A[j]);
            j++;
        }
    }
    swap(lista->A[j], lista->A[right]);
    return j;
}

void quick_sort_recursion(LISTA* lista, int left, int right) {
    int j;
    if (right <= left) return;

    j = quick_sort_partition(lista, left, right);  // posição do pivot

    quick_sort_recursion(lista, left, j - 1);   // ordena à esquerda do pivot
    quick_sort_recursion(lista, j + 1, right);  // ordena à esquerda do pivot
}

void quick_sort_recursion_mediana3(LISTA* lista, int left, int right) {
    int j;
    if (right <= left) return;

    //compara 3 pivot (esquerda, meio e direita)
    //e coloca o mediano na direita, para ser o pivot do qs
    comp_swap(lista->A[(left + right) / 2], lista->A[right]);
    comp_swap(lista->A[left], lista->A[(left + right) / 2]);
    comp_swap(lista->A[right], lista->A[(left + right) / 2]);


    j = quick_sort_partition(lista, left, right);  // posição do pivot

    quick_sort_recursion(lista, left, j - 1);   // ordena à esquerda do pivot
    quick_sort_recursion(lista, j + 1, right);  // ordena à esquerda do pivot
}


int main() {
    bool mostrar_lista = false;  // Flag para controle de exibição

    LISTA* lista = (LISTA*)malloc(sizeof(LISTA));
    LISTA* lista_base = (LISTA*)malloc(sizeof(LISTA));

    srand(time(NULL));
    clock_t inicio, fim;
    double tempo_gasto;

    inicializarLista(lista_base);
    inicializarLista(lista);

    // Nome do arquivo CSV
    // const char* nomeArquivo = "pratos_teste.csv"; // 21 registros
    const char* nomeArquivo = "restaurante_pratos.csv";

    // Carregar dados do CSV para a lista
    if (carregarDadosCSV(nomeArquivo, lista_base)) {
        printf("Dados carregados com sucesso!\n");
        printf("Tamanho da lista: %i registros.\n", tamanho(lista_base));
    } else {
        printf("Falha ao carregar os dados.\n");
        free(lista);
        free(lista_base);
        return 1;
    }

    // Quick Sort
    copiarLista(lista, lista_base);
    if (mostrar_lista) {
        printf("\nLista antes do Quick Sort:\n");
        exibirLista(lista);
    }

    printf("\nOrdenando a lista - Quick Sort com 1 pivot = direita...\n");
    inicio = clock();
    quick_sort_recursion(lista, 0, lista->nroElem - 1);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Quick Sort concluído em %.3f segundos.\n", tempo_gasto);

    if (mostrar_lista) {
        printf("\nLista após o Quick Sort:\n");
        exibirLista(lista);
    }


    // Quick Sort com mediana de 3 pivot
    copiarLista(lista, lista_base);
    if (mostrar_lista) {
        printf("\nLista antes do Quick Sort:\n");
        exibirLista(lista);
    }

    printf("\nOrdenando a lista - Quick Sort com mediana de 3 pivot...\n");
    inicio = clock();
    quick_sort_recursion_mediana3(lista, 0, lista->nroElem - 1);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Quick Sort concluído em %.3f segundos.\n", tempo_gasto);

    if (mostrar_lista) {
        printf("\nLista após o Quick Sort:\n");
        exibirLista(lista);
    }



    // // Bubble Sort
    // copiarLista(lista, lista_base);
    // if (mostrar_lista) {
    //     printf("\nLista antes do Bubble Sort:\n");
    //     exibirLista(lista);
    // }

    // printf("\nOrdenando a lista - Bubble Sort...\n");
    // inicio = clock();
    // bubble_sort_iterativo(lista, 0, lista->nroElem - 1);
    // fim = clock();
    // tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    // printf("Bubble Sort concluído em %.2f segundos.\n", tempo_gasto);

    // if (mostrar_lista) {
    //     printf("\nLista após o Bubble Sort:\n");
    //     exibirLista(lista);
    // }



    // Libera a memória alocada
    free(lista);
    free(lista_base);


    return 0;
}
