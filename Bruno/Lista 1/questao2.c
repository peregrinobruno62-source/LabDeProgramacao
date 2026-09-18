#include <stdio.h>

int main() {
    float x;

    printf("Escreva um valor real: ");
    scanf("%f", &x);
    
    printf("O valor com apenas uma casa decimal é %.1f \n", x);

    return 0;
}