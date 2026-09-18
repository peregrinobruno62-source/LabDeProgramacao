#include <stdio.h>

int main() {
    int n, unidade, dezena, centena, nInvertido;

    printf("Digite um número de três dígitos: ");
    scanf("%d", &n);

    centena = n / 100;
    dezena = (n / 10) % 10;
    unidade = n % 10;

    nInvertido = (unidade * 100) + (dezena * 10) + centena;

    printf("O número invertido é %d \n", nInvertido);

    return 0;
}
