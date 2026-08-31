#include <stdio.h>

int main() {
    int n1, n2;

    printf("Informe um valor inteiro: ");
    scanf("%d", &n1);
    printf("Informe outro valor inteiro: ");
    scanf("%d", &n2);

    (n1 % n2 == 0) ? printf("O %d é multiplo de %d \n", n1, n2) : printf("O %d não é multiplo de %d \n", n1, n2);

    return 0;
}