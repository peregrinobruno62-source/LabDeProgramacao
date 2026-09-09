#include <stdio.h>

int main() {
    int numero;

    printf("Digite um número inteiro de 5 dígitos: ");
    scanf("%d", &numero);

    int dezena_de_milhar = (numero / 10000) % 10;
    int unidade_de_milhar = (numero / 1000) % 10;
    int centena = (numero / 100) % 10;
    int dezena = (numero / 10) % 10;
    int unidade = numero % 10;

    if (dezena_de_milhar == unidade && unidade_de_milhar == dezena) {
        printf("O número é um palíndromo.\n");
    } else {
        printf("O número não é um palíndromo.\n");
    }

    return 0;
}