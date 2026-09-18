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

    unsigned count = 0;
    unsigned char flag = 0;
   for (int i = 0; i < TAM; i++) {
    flag = 0;
        for (int j = 0; j < TAM - 1; j++) {
            if (numeros[j] > numeros[j+1]) {
                int auxiliar = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = auxiliar;
                flag = 1;
            }
        }
        if (flag) {
            count++;
        } else {
            break;
        }
    }

    printf("\nValores do vetor em ordem crescente (BUBBLE SORT):\n");
    for (int j = 0; j < TAM; j++) {
        printf("%d ", numeros[j]);
    }
    printf("\n");

    printf("Contador de Interações: %u \n", count);

    return 0;
}