#include <stdio.h>

int main() {
    int n = 5;
    unsigned char x, intensidade, x_min, x_max;

    printf("Informe a intensidade de X (0 a 255): ");
    scanf("%hhu", &x);

    for (int i = 1; i <= n; i++) {
        printf("Informe a intensidade de X%d (0 a 255): ", i);
        scanf("%hhu", &intensidade);

        if (intensidade < x_min) {
            x_min = intensidade;
        }

        if (intensidade > x_max) {
            x_max = intensidade;
        }
    }

    unsigned char x_normalizado = (x - x_min) / (x_max - x_min);
    printf("X' = %hhu \n", x_normalizado);
}