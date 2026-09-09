#include <stdio.h>

int main() {
    int num;
    int maior, menor;
    int primeiro = 1;

    printf("Digite números inteiros (Para sair: digite um negativo PAR):\n");

    while (1) {
        printf("Número: ");
        scanf("%d", &num);

        if (num < 0 && num % 2 == 0) {
            break;
        }

        if (primeiro) {
            maior = num;
            menor = num;
            primeiro = 0;
        } else {
            if (num > maior) {
                maior = num;
            }
            if (num < menor) {
                menor = num;
            }
        }
    }

    long long produto = (long long)maior * menor;
    printf("\nMaior numero: %d\n", maior);
    printf("Menor numero: %d\n", menor);
    printf("Produto do maior pelo menor: %lld\n", produto);

    return 0;
}
