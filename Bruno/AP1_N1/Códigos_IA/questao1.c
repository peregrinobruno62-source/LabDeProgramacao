#include <stdio.h>

int main(void) {
    unsigned int M;

    printf("Digite um número inteiro (0 a 255): ");

    if (scanf("%u", &M) != 1 || M > 255) {
        printf("Valor inválido.\n");
        return 1;
    }

    unsigned int R = (M >> 2) & 1;
    unsigned int G = (M >> 1) & 1;
    unsigned int B = M & 1;

    printf("R = %u\n", R);
    printf("G = %u\n", G);
    printf("B = %u\n", B);

    return 0;
}