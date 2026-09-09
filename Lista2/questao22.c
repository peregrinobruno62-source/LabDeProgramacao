#include <stdio.h>
#include <stdlib.h>

int main() {
    long long numero;
    int qtd_setes = 0;

    printf("Digite um número inteiro: ");
    scanf("%lld", &numero);

    long long n = llabs(numero);

    while (n > 0) {
        int digito = n % 10;
        if (digito == 7) {
            qtd_setes++;
        }
        n /= 10;
    }

    printf("O número de algarismos 7 é %d \n", qtd_setes);

    return 0;
}
