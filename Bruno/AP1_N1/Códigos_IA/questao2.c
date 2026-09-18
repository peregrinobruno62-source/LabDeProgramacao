#include <stdio.h>

int main(void) {
    const int n = 10;

    for (int i = 2; i <= n; i++) {
        int xi_1, xi, xi1;

        printf("Informe o valor de x%d x%d e x%d: ",
               i - 2, i - 1, i);

        scanf("%d %d %d", &xi_1, &xi, &xi1);

        float y = (xi_1 + xi + xi1) / 3.0f;

        printf("O valor de y%d é %.2f\n", i - 1, y);
    }

    return 0;
}