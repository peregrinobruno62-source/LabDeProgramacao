#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 14
#define N 7

int main() {
    srand(time(NULL));
    int X[TAM], Y[TAM], M[N][N] = {0};

    for(int i = 0; i < TAM; i++) {
        X[i] = rand() % N;
        int r = (rand() % 10) + 1; 
        
        if (r >= 1 && r <= 3) {
            Y[i] = X[i];
        } else if (r > 3 && r <= 5) {
            Y[i] = X[i] - 1;
        } else if (r > 5 && r <= 7) {
            Y[i] = X[i] + 1;
        } else if (r == 8 || r == 9) {
            Y[i] = X[i] - 2;
        } else if (r == 10) {
            Y[i] = X[i] + 2;
        } else {
            Y[i] = X[i];
        }

        if (Y[i] < 0) {
            Y[i] = 0;
        }

        if (Y[i] >= N) {
            Y[i] = N - 1;
        }

        M[X[i]][Y[i]] += 1;
    }

    printf("X: ");
    for(int i = 0; i < TAM; i++) {
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