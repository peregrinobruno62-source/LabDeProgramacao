#include <stdio.h>

int main() {
    float r;
    float pi = 3.14159;

    printf("Informe o raio do círculo: ");
    scanf("%f", &r);

    printf("O valor da diâmetro é %.2f \n", (r * 2.0));
    printf("O valor da circunferência é %.2f \n", (2.0 * pi * r));
    printf("O valor da área é %.2f \n", (pi * r * r));

    return 0;
}