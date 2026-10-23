#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BASE -5
#define AMP 100

int main() {
    int n;
    float mediana;
    srand(time(NULL));

    printf("Informe a quantidade de termos: ");
    scanf("%d", &n);

    int vetor[n];

    for (int i = 0; i < n; i++) {
        vetor[i] = BASE + rand() % AMP;
    }

    for (int i = 0; i < n - 1; i++) {        
        for (int j = i + 1; j < n; j++) {
            if (vetor[i] > vetor[j]) {
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    printf("\nValores ordenados:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n\n");

    if (n % 2 == 0) {
        mediana = (vetor[(n/2) - 1] + vetor[n/2]) / 2.0f;
    } else {
        mediana = vetor[n/2];
    }

    printf("Mediana: %.1f \n", mediana);


}