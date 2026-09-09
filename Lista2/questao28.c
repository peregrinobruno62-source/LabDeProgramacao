#include <stdio.h>

int main() {
    unsigned char X, Y;
    int indice_bit = 7;

    printf("Digite o valor de X (0 a 255): ");
    scanf("%hhu", &X);

    printf("Digite o valor de Y (minimo 5, ate 251): ");
    scanf("%hhu", &Y);

    printf("\nProcessando os vizinhos de Y (%d):\n", Y);
    printf("========================================\n");

    for (int i = -4; i <= 4; i++) {
        if (i == 0) {
            continue;
        }

        unsigned char vizinho_original = Y + i;
        unsigned char bit_de_X = (X >> indice_bit) & 1;
        unsigned char vizinho_modificado = (vizinho_original & 0xFE) | bit_de_X;

        printf("Vizinho original: %3d | Escondendo bit %d (valor %d) | Resultado final: %3d\n", vizinho_original, indice_bit, bit_de_X, vizinho_modificado);

        indice_bit--;
    }

    return 0;
}
