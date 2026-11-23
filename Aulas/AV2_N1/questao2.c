#include <stdio.h>
#include <stdlib.h>

double **filtraAlertas(double *T, int N, double L, int *k);
void saturaAlertas(double **A, int k, double L);

int main() {
    unsigned int tam;
    double limiar;

    puts ("Digite o tamanho do vetor T:");
    scanf("%u", &tam);
    puts ("Digite o valor do limiar:");
    scanf("%lf", &limiar);
    double *vetT = malloc(tam * sizeof(double));

    puts ("\nPreencha o vetor T:");
    for(int i = 0; i < tam; i++) {
        printf("T[%d] = ", i);
        scanf("%lf", &*(vetT + i));
    }

    double **vetA = filtraAlertas(vetT, tam, limiar, &tam);
    printf("\n");
    saturaAlertas(vetA, tam, limiar);

    for (int i = 0; i < tam; i++) {
        printf("A[%d] = %.2lf\n", i, *vetA[i]);
    }

    free(vetT);
    free(vetA);
    return 0;
}

double **filtraAlertas(double *T, int N, double L, int *k) {
    *k = 0;
    for (int i = 0; i < N; i++) {
        if (*(T + i) > L) {
            (*k)++;
        }
    }

    double **A = malloc(*k * sizeof(double *));
    int j = 0;

    for (int i = 0; i < N; i++) {
        if (*(T + i) > L) {
            *(A + j) = &(*(T + i));
            j++;
        }
    }
    return A;
}

void saturaAlertas(double **A, int k, double L) {
    for (int i = 0; i < k; i++) {
        *A[i] = L;
    }
}