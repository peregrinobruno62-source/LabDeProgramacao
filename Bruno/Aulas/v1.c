#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
#define MX 10

int main() {
    unsigned char x[TAM];

    srand (time(NULL));

    puts ("Entre com os dados: ");
    for (int k=0; k<TAM; k++) {
        // scanf("%hhu", &x[k]);
        x[k] = rand() % MX;
    }

    puts ("Dados fornecidos: ");
    for (int k=0; k<TAM; k++) {
       printf("x[%d] - [%p] : %hhu\n",k,&x[k],x[k]);
    }

    // Descobrir o menor e o maior valor do vetor
    int menor, maior;

    menor = maior = x[0];

    for(int k=0; k<TAM; k++) {
        menor = (menor > x[k]) ? x[k]: menor;
        maior = (maior < x[k]) ? x[k]: maior;
    }

    printf("Menor: %d \n", menor);
    printf("Maior: %d \n", maior);

    return 0;

}