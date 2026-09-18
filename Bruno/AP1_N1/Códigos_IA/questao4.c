#include <stdio.h>

int main(void) {
    int numero;
    int soma = 0;
    int contador = 0;

    do {
        printf("Digite um número (-1 para encerrar): ");
        scanf("%d", &numero);

        if (numero != -1) {
            soma += numero;
            contador++;
        }

    } while (numero != -1);

    printf("Soma = %d\n", soma);
    printf("Quantidade = %d\n", contador);

    return 0;
}