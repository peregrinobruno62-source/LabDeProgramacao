#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

// Protótipos das Funções
int *alocarMemoriaInt(const unsigned tamanho);
void gerarMatriz(int n, int *matriz);
void imprimirMatriz(int n, int *matriz);
int somarDiagonalPrincipal(int n, int *matriz);

int main() {
    srand(time(NULL));
    int *M = alocarMemoriaInt(N * N);

    gerarMatriz(N, M);
    puts("Matriz gerada: ");
    imprimirMatriz(N, M);

    int soma = somarDiagonalPrincipal(N, M);
    printf("\nSomatório da diagonal principal: %d \n", soma);
    printf("O somatório é %s. \n", (soma % 2 == 0) ? "PAR" : "ÍMPAR");

    free(M);

    printf("\n");
    return 0;
}

int *alocarMemoriaInt(const unsigned tamanho) {
    int *p = NULL;
    if(!(p = (int *) malloc(tamanho * sizeof(int)))) {
        puts("Não há memória disponível");
        exit(1);
    }
    return p;
}

void gerarMatriz(int n, int *matriz) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            *(matriz + i * n + j) = rand() % 100;
        }
    }
}

void imprimirMatriz(int n, int *matriz) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("[%2d] ", *(matriz + i * n + j));
        }
        printf("\n");
    }
}

// Elementos da diagonal principal: posições (i, i)
int somarDiagonalPrincipal(int n, int *matriz) {
    int soma = 0;
    for(int i = 0; i < n; i++) {
        soma += *(matriz + i * n + i);
    }
    return soma;
}
