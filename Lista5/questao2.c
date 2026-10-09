#include <stdio.h>

int main() {
    int num1, num2;
    int *p1, *p2;

    printf("Digite o primeiro e o segundo valor: ");
    scanf("%d %d", &num1, &num2);

    p1 = &num2;
    p2 = &num1;

    printf("\n1ª valor (Antes era o 2ª): %d \n", *p1);
    printf("2ª valor (Antes era o 1ª): %d \n", *p2);

    return 0;
}