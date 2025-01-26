#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_sequencial.c"

//convenções
typedef REGISTRO ITEM;
#define key(A) (A.chave)
// #define less(A, B) (key(A) < key(B)) // para apenas 1 chave
#define less(A, B) ((key(A) < key(B)) || (key(A) == key(B) && (A.chave2 < B.chave2))) // para 2 chaves
#define swap(A, B) {ITEM temp = A; A = B; B = temp;}
#define comp_swap(A, B) {if (less(B, A)) swap(A, B);}
#define TOTAL_ELEMENTOS 50

void bubble_sort_iterativo(LISTA* lista, int left, int right) {
    for (int i = right; i > left; i--) { // Percorre do final ao início
        for (int j = left; j < i; j++) { // Até a última posição não ordenada
            if (less(lista->A[j + 1], lista->A[j])) {
                swap(lista->A[j + 1], lista->A[j]); // Troca se necessário
            }
        }
    }
}


int main() {
    LISTA lista_base, lista;
    // Inicializa o gerador de números aleatórios com uma semente baseada no tempo atual
    srand(time(NULL));
    clock_t inicio, fim;
    double tempo_gasto;

    inicializarLista(&lista);

    // Nome do arquivo CSV
    const char* nomeArquivo = "pratos_teste.csv";

    // Carregar dados do CSV para a lista
    if (carregarDadosCSV(nomeArquivo, &lista)) {
        printf("Dados carregados com sucesso!\n");
    } else {
        printf("Falha ao carregar os dados.\n");
    }

    // Exibir os dados carregados
    exibirLista(&lista);

    // bubble sort iterativo
   
    // Exibindo o estado inicial da lista
    printf("\nEstado inicial da lista:\n");
    exibirLista(&lista);
    printf("Numero de elementos na lista: %i.\n", tamanho(&lista));


    printf("Ordenando a lista - bubble_sort iterativo\n");
    inicio = clock();  // Início da medição
    bubble_sort_iterativo(&lista, 0, 20);
    fim = clock();  // Fim da medição

    // Exibindo o estado final da lista
    printf("Estado final da lista:\n");
    exibirLista(&lista);

    // Calcula o tempo gasto em segundos
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.2f segundos\n", tempo_gasto);





    return 0;
}
