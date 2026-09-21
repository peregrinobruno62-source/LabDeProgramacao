#include <stdio.h>

int main() {
    int numero;
    int soma = 0;
    int contador = 0;

    scanf("%d", &numero);

    while (numero != -1) {

        if (numero >= 0 && numero <= 255) {
            soma += numero;
            contador++;
        }

        scanf("%d", &numero);
    }

    printf("Soma = %d\n", soma);
    printf("Quantidade = %d\n", contador);

    return 0;
}