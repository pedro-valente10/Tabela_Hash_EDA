#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 131          // Tamanho primo da tabela para ~100 chaves
#define VAZIO -1LL     // Indica posição livre

typedef struct {
    long long tabela[M];
    int total_colisoes;
} HashStruct;

// Inicializa a tabela
void inicializa(HashStruct *h) {
    for (int i = 0; i < M; i++) h->tabela[i] = VAZIO;
    h->total_colisoes = 0;
}

// Insere usando Double Hashing
int insere(HashStruct *h, long long cpf) {
    int h1 = cpf % M;
    int h2 = 1 + (cpf % (M - 1)); // O passo nunca pode ser 0
    int k = 0;
    int pos;

    while (k < M) {
        pos = (h1 + k * h2) % M;

        if (h->tabela[pos] == VAZIO) {
            h->tabela[pos] = cpf;
            return k; // Retorna número de colisões nesta inserção específica
        }
        
        if (h->tabela[pos] == cpf) return 0; // CPF já existe

        h->total_colisoes++;
        k++;
    }
    return -1; // Tabela cheia
}

int main() {
    HashStruct minhaTabela;
    inicializa(&minhaTabela);

    FILE *arq = fopen("cpfs.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    char linha[15];
    int contador = 0;

    printf("Inserindo chaves...\n");
    printf("Chaves | Colisoes Acumuladas\n");
    printf("---------------------------\n");

    while (fgets(linha, sizeof(linha), arq)) {
        long long cpf = atoll(linha); // Converte string para long long
        insere(&minhaTabela, cpf);
        contador++;

        // Imprime a cada 20 inserções para o relatório/gráfico
        if (contador % 20 == 0) {
            printf("%6d | %d\n", contador, minhaTabela.total_colisoes);
        }
    }

    fclose(arq);
    printf("---------------------------\n");
    printf("Total final de colisoes: %d\n", minhaTabela.total_colisoes);

    return 0;
}
