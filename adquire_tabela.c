#include "lista_sequencial.c"

bool carregarDadosCSV(const char* nomeArquivo, LISTA* lista) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return false;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo)) {
        REGISTRO reg;
        if (sscanf(linha, "%d %d %29[^\n]", &reg.chave, &reg.chave2, reg.nome) == 3) {
            if (!inserirElemLista(lista, reg, lista->nroElem)) {
                printf("Erro ao inserir elemento na lista\n");
                fclose(arquivo);
                return false;
            }
        } else {
            printf("Erro ao processar a linha: %s\n", linha);
        }
    }

    fclose(arquivo);
    return true;
}