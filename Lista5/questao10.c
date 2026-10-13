#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 14
#define N 7

int main() {
    srand(time(NULL));
    int X[TAM], F[N] = {0};

    for(int i = 0; i < TAM; i++) {
        X[i] = rand() % N;
        F[X[i]] += 1;
        printf("%d ", X[i]);
    }
    printf("\n");

    for(int i = 0; i < N; i++) {
        printf("%d ", F[i]);
    }

    printf("\n");
    return 0;
}