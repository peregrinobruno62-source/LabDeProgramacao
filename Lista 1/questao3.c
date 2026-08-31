#include <stdio.h>

int main() {
    int x;

    printf("Escreva um valor inteiro: ");
    scanf("%d", &x);
    
    printf("Seu triplo é %d \n", x+x+x);
    printf("Seu quadrado é %d \n", x*x);
    printf("Sua metade é %d \n", x/2);

    return 0;
}