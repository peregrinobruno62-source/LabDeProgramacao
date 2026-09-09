#include <stdio.h>

int main() {
    double pi = 0.0;
    double numerador = 4.0;
    double denominador = 1.0;
    int sinal = 1;

    for (int i = 1; i <= 500000; i++) {
        pi += sinal * (numerador / denominador);

        printf("%.15f \n", pi);

        denominador += 2.0;
        sinal *= -1;
    }
    return 0;
}
