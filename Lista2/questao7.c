#include <stdio.h>

int main() {
    float x, y;

    printf("Informe o valor do numerador: ");
    scanf("%f", &x);

    do {
        printf("Informe o valor do denominador: ");
        scanf("%f", &y);
    } while (y == 0);

    printf("O valor da divisão entre %.1f e %.1f é %.2f \n ", x, y, x / y);

    return 0;
}