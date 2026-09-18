#include <stdio.h>

int main(void) {
    const int n = 5;
    unsigned char x;
    unsigned char intensidade;
    unsigned char x_min;
    unsigned char x_max;

    printf("Informe a intensidade de X (0 a 255): ");
    scanf("%hhu", &x);

    printf("Informe a intensidade de X1 (0 a 255): ");
    scanf("%hhu", &intensidade);

    x_min = intensidade;
    x_max = intensidade;

    for (int i = 2; i <= n; i++) {
        printf("Informe a intensidade de X%d (0 a 255): ", i);
        scanf("%hhu", &intensidade);

        if (intensidade < x_min) {
            x_min = intensidade;
        }

        if (intensidade > x_max) {
            x_max = intensidade;
        }
    }

    if (x_max == x_min) {
        printf("Não é possível normalizar: máximo e mínimo são iguais.\n");
        return 1;
    }

    double x_normalizado =
        (double)(x - x_min) / (x_max - x_min);

    printf("X' = %.2f\n", x_normalizado);

    return 0;
}