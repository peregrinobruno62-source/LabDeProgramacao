#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100

int main() {
    srand(time(NULL));
    int str[TAM];
    int min, max;

    printf("Digite o valor mínimo para o intervalo: ");
    scanf("%d", &min);

    printf("Digite o valor máximo para o intervalo: ");
    scanf("%d", &max);

    for(int i = 0; i < TAM; i++) {
        str[i] = rand() % (max - min + 1) + min;
    }

    for(int i = 0; i < TAM - 1; i++) {
        for(int j = i + 1; j < TAM; j++) {
            if(str[j] < str[i]) {
                int auxiliar = str[i];
                str[i] = str[j];
                str[j] = auxiliar;
            }
        }
    }
    printf("\n");
    printf("Números ordenados: ");
    for(int i = 0; i < TAM; i++) {
        printf("%d ", str[i]);
    }
    printf("\n");
    return 0;
}