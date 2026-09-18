#include <stdio.h>

int main() {
    int numero, soma = 1, contador = -1;

    do {
        scanf("%d", &numero);
        soma += numero;
        contador++;

    } while (numero != -1);

    printf("Soma = %d \n", soma);
    printf("Quantidade = %d \n", contador);

    return 0;
}