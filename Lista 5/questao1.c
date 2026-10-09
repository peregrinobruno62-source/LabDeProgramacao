#include <stdio.h>

int main() {
    int num1, num2, soma;
    int *p;

    printf("Digite o primeiro e o segundo número: ");
    scanf("%d %d", &num1, &num2);

    soma = num1 + num2;
    p = &soma;

    printf("\nA soma de %d e %d é %d\n", num1, num2, *p);
    printf("Endereço de memória da soma é %p\n", (void*)p);

    return 0;
}