#include <stdio.h>

int main() {
    int valor = -1;
    int maior_valor, menor_valor;

    while(valor != 0) {
        printf("Informe um valor: ");
        scanf("%d", &valor);

        if (valor > maior_valor) {
            maior_valor = valor;
        }

        if (valor < menor_valor) {
            menor_valor = valor;
        }
    }

    printf("O maior valor digitado foi: %d \n", maior_valor);
    printf("O menor valor digitado foi: %d \n", menor_valor);

    return 0;
}