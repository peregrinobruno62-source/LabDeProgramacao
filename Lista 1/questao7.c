#include <stdio.h>

int main() {
    int valor, quadrado;

    printf("Digite um valor inteiro qualquer: ");
    scanf("%d", &valor);
    
    quadrado = valor * valor;

    printf("Esse número ao quadrado é %d \n", quadrado);

    return 0;
}