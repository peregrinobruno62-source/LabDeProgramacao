#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIN 4
#define COL 5

// Protótipos das Funções
int *alocarMemoriaInt(const unsigned tamanho);
void gerarMatriz(int lin, int col, int *matriz);
void imprimirMatriz(int lin, int col, int *matriz);
void binarizarMatriz(int lin, int col, int *M, int *S, int limiar);

int main() {
    srand(time(NULL));
    int *M = alocarMemoriaInt(LIN * COL); // matriz armazenada de forma linear
    int *S = alocarMemoriaInt(LIN * COL);
    int limiar;

    gerarMatriz(LIN, COL, M);
    puts("Matriz M: ");
    imprimirMatriz(LIN, COL, M);

    printf("Informe o limiar (t): ");
    scanf("%d", &limiar);

    binarizarMatriz(LIN, COL, M, S, limiar);
    puts("\nMatriz S (binarizada): ");
    imprimirMatriz(LIN, COL, S);

    free(M);
    free(S);

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

void gerarMatriz(int lin, int col, int *matriz) {
    for(int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            *(matriz + i * col + j) = rand() % 100;
        }
    }
}

void imprimirMatriz(int lin, int col, int *matriz) {
    for(int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            printf("[%2d] ", *(matriz + i * col + j));
        }
        printf("\n");
    }
}

// S[i][j] = 1 se M[i][j] > t, 0 caso contrário
void binarizarMatriz(int lin, int col, int *M, int *S, int limiar) {
    for(int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            *(S + i * col + j) = (*(M + i * col + j) > limiar) ? 1 : 0;
        }
    }
}
