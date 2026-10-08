#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAM 3

int main() {
    srand(time(NULL));
    int str[TAM];
    int soma = 0;
    int produto = 1;

    printf("Números gerados: ");
    for(int i = 0; i < TAM; i++) {
        str[i] = rand() % 20;
        soma+= str[i];
        produto*= str[i];
        printf("%d ", str[i]);
    }

    printf("\n");
    printf("A média aritmética é: %.2f \n", (double) soma / TAM);
    printf("A média geométrica é: %.2f \n", pow(produto, 1.0 / TAM));
    return 0;
}