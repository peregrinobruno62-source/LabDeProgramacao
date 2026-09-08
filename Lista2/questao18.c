#include <stdio.h>

int main() {
    unsigned long long total_graos = 0;
    unsigned long long graos_no_quadro = 1;

    for (int quadro = 1; quadro <= 64; quadro++) {
        total_graos += graos_no_quadro;
        graos_no_quadro *= 2;
    }

    printf("O total de grãos de trigo no tabuleiro é igual a %llu \n", total_graos);

    return 0;
}