#include <stdio.h>

int main() {
    int n;
    int x;
    int xmin, xmax;
    int i;
    double normalizado;

    scanf("%d", &n);

    scanf("%d", &x);

    xmin = x;
    xmax = x;

    for (i = 1; i < n; i++) {
        scanf("%d", &x);

        if (x < xmin) {
            xmin = x;
        }

        if (x > xmax) {
            xmax = x;
        }
    }

    scanf("%d", &x);

    if (xmin == xmax) {
        normalizado = 0.0;
    } else {
        normalizado = (double)(x - xmin) / (xmax - xmin);
    }

    printf("Minimo = %d\n", xmin);
    printf("Maximo = %d\n", xmax);
    printf("Normalizado = %.6f\n", normalizado);

    return 0;
}