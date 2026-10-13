#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 14
#define N 7

int main() {
    srand(time(NULL));
    int X[TAM], Y[TAM], M[N][N] = {0};

    printf("X: ");
    for(int i = 0; i < TAM; i++) {
        X[i] = rand() % N;
        Y[i] = rand() % N;
        M[X[i]][Y[i]] += 1;
        printf("%d ", X[i]);
    }
    printf("\n");

    printf("Y: ");
    for(int i = 0; i < TAM; i++) {
        printf("%d ", Y[i]);
    }
    printf("\n\n");

    printf("Matriz gerada: \n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    return 0;
}