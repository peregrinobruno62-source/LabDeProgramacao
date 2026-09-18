#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10
#define BASE -5
#define AMP 100

int main() {
    int numeros[TAM];
    srand(time(NULL));

    for (int i = 0; i < TAM; i++) {
        numeros[i] = BASE + rand() % AMP;
    }

    printf("Valores do vetor:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    for (int i = 0; i < TAM - 1; i++) {        
        for (int j = i + 1; j < TAM; j++) {
            if (numeros[i] > numeros[j]) {
                int auxiliar = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = auxiliar;
            }
        }
    }

    printf("\nValores do vetor em ordem crescente:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    for (int i = 0; i < TAM - 1; i++) {        
        for (int j = i + 1; j < TAM; j++) {
            if (numeros[i] < numeros[j]) {
                int auxiliar = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = auxiliar;
            }
        }
    }

    printf("\nValores do vetor em ordem decrescente:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}