#include <stdio.h>

int main() {
    int x;
    int y;

    x = 10;
    y = x--; 
    printf("Pós-Decremento: \n");
    printf("Valor atribuido ao y: %d\n", y);
    printf("Valor final de x: %d\n\n", x);

    x = 10;
    y = --x;
    printf("Pré-Decremento: \n");
    printf("Valor atribuido ao y: %d\n", y);
    printf("Valor final de x: %d\n", x);

    return 0;
}