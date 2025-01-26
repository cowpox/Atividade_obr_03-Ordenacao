#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_sequencial.c"

//convenções
typedef REGISTRO ITEM;
#define key(A) (A.chave)
// #define less(A, B) (key(A) < key(B)) // para apenas 1 chave
#define less(A, B) ((key(A) < key(B)) || (key(A) == key(B) && (A.chave2 < B.chave2))) // para 2 chaves
#define lessequal(A, B) (key(A) <= key(B))
#define swap(A, B) {ITEM temp = A; A = B; B = temp;}
#define comp_swap(A, B) {if (less(B, A)) swap(A, B);}
#define TOTAL_ELEMENTOS 10

void selection_sort_recursivo(LISTA* lista, int left, int right) {
    // condicao de parada
    if (left >= right) return;

    int min = left;  // o menor elemento começa sendo o da esquerda
    for (int j = left + 1; j <= right; j++) {
        // percorre o restante do vetor e procura se existe um indice
        // que resulta em uma chave menor que a chave esquerda
        if (less(lista->A[j], lista->A[min])) min = j;
    }
    // atualiza o elemento da esquerda para o que tenha a chave de menor valor
    swap(lista->A[min], lista->A[left]);
    // agora precisamos rodar esse codigo para os outros elementos do vetor
    selection_sort_recursivo(lista, left + 1, right);
}

void selection_sort_iterativo(LISTA* lista, int left, int right) {
    for (int i = left; i < right; i++) {

        int min = i;  // o menor elemento começa sendo o da esquerda
        for (int j = i + 1; j <= right; j++) {
            // percorre o restante do vetor e procura se existe um indice
            // que resulta em uma chave menor que a chave esquerda
            if (less(lista->A[j], lista->A[min])) min = j;
        }
        // atualiza o elemento da esquerda para o que tenha a chave de menor
        // valor
        swap(lista->A[min], lista->A[i]);
        // agora precisamos rodar esse codigo para os outros elementos do vetor
    }
}

void bubble_sort_recursivo(LISTA* lista, int left, int right) {
    if (right <= left) return;

    for (int j = left; j < right; j++) {  // Até a última posição não ordenada
        if (less(lista->A[j + 1], lista->A[j])) {
            swap(lista->A[j + 1], lista->A[j]);  // Troca se necessário
        }
    }
    bubble_sort_recursivo(lista, left, right - 1);
}

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

int main() {
    LISTA lista_base, lista;
    // Inicializa o gerador de números aleatórios com uma semente baseada no tempo atual
    srand(time(NULL));
    clock_t inicio, fim;
    double tempo_gasto;

    inicializarLista(&lista_base);
    inicializarLista(&lista);

    // Inserindo os números na lista
    for (int i = 0; i < TOTAL_ELEMENTOS; i++) {
        REGISTRO reg;
        reg.chave = rand() % (2 * TOTAL_ELEMENTOS);
        inserirElemLista(&lista_base, reg, i);
    }

    //selection sort recursivo
    lista = lista_base;

    // Exibindo o estado inicial da lista
    printf("\nEstado inicial da lista:\n");
    exibirLista(&lista);
    printf("Numero de elementos na lista: %i.\n", tamanho(&lista));



    printf("Ordenando a lista - sequential_sort recursivo\n");
    inicio = clock();  // Início da medição
    selection_sort_recursivo(&lista, 0, TOTAL_ELEMENTOS - 1);
    fim = clock();  // Fim da medição

    // Exibindo o estado final da lista
    printf("Estado final da lista:\n");
    exibirLista(&lista);

    // Calcula o tempo gasto em segundos
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.2f segundos\n", tempo_gasto);
    
    
    // selection sort iterativo
    lista = lista_base;

    // Exibindo o estado inicial da lista
    printf("\nEstado inicial da lista:\n");
    exibirLista(&lista);
    printf("Numero de elementos na lista: %i.\n", tamanho(&lista));


    printf("Ordenando a lista - sequential_sort iterativo\n");
    inicio = clock();  // Início da medição
    selection_sort_iterativo(&lista, 0, TOTAL_ELEMENTOS - 1);
    fim = clock();  // Fim da medição

    // Exibindo o estado final da lista
    printf("Estado final da lista:\n");
    exibirLista(&lista);

    // Calcula o tempo gasto em segundos
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.2f segundos\n", tempo_gasto);




    // bubble sort recursivo
    lista = lista_base;

    // Exibindo o estado inicial da lista
    printf("\nEstado inicial da lista:\n");
    exibirLista(&lista);
    printf("Numero de elementos na lista: %i.\n", tamanho(&lista));


    printf("Ordenando a lista - bubble_sort recursivo\n");
    inicio = clock();  // Início da medição
    bubble_sort_recursivo(&lista, 0, TOTAL_ELEMENTOS - 1);
    fim = clock();  // Fim da medição

    // Exibindo o estado final da lista
    printf("Estado final da lista:\n");
    exibirLista(&lista);

    // Calcula o tempo gasto em segundos
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.2f segundos\n", tempo_gasto);


    // bubble sort iterativo
    lista = lista_base;

    // Exibindo o estado inicial da lista
    printf("\nEstado inicial da lista:\n");
    exibirLista(&lista);
    printf("Numero de elementos na lista: %i.\n", tamanho(&lista));


    printf("Ordenando a lista - bubble_sort iterativo\n");
    inicio = clock();  // Início da medição
    bubble_sort_iterativo(&lista, 0, TOTAL_ELEMENTOS - 1);
    fim = clock();  // Fim da medição

    // Exibindo o estado final da lista
    printf("Estado final da lista:\n");
    exibirLista(&lista);

    // Calcula o tempo gasto em segundos
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.2f segundos\n", tempo_gasto);




    // quick sort
    lista = lista_base;

    // Exibindo o estado inicial da lista
    printf("\nEstado inicial da lista:\n");
    exibirLista(&lista);
    printf("Numero de elementos na lista: %i.\n", tamanho(&lista));


    printf("Particionando a lista - retorna a posição do pivot\n");
    inicio = clock();  // Início da medição
    int pivot_idx = quick_sort_partition(&lista, 0, TOTAL_ELEMENTOS - 1);
    fim = clock();  // Fim da medição

    // Exibindo a posição do pivot
    printf("A posição do pivot é %i\n", pivot_idx);

    // Exibindo o estado final da lista
    printf("Estado final da lista:\n");
    exibirLista(&lista);

    // Calcula o tempo gasto em segundos
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.2f segundos\n", tempo_gasto);





    return 0;
}