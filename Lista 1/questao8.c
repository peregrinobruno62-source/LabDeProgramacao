#include <stdio.h>

int main() {
    int valor, antecessor, sucessor;

    printf("Digite um valor inteiro qualquer: ");
    scanf("%d", &valor);
    
    sucessor = valor + 1;
    antecessor = valor - 1;

    printf("O antecessor de %d é %d \n", valor, antecessor);
    printf("O sucessor de %d é %d \n", valor, sucessor);

    return 0;
}