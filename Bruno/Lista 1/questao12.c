#include <stdio.h>

int main() {
    int a, b, auxiliar;

    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);

    auxiliar = a;
    a = b;
    b = auxiliar;

    printf("A: %d \n", a);
    printf("B: %d \n", b);

    return 0;
}