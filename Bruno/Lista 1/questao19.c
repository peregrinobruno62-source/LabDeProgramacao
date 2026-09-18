#include <stdio.h>

int main() {
    int n;

    printf("Informe um valor inteiro: ");
    scanf("%d", &n);

    (n % 2 == 0) ? printf("O número %d é par \n", n) : printf("O número %d é impar \n", n);

    return 0;
}
