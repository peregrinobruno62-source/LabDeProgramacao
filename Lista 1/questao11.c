#include <stdio.h>

int main() {
    int n1, n2;

    printf("Digite um número: ");
    scanf("%d", &n1);
    printf("Digite outro número: ");
    scanf("%d", &n2);

    printf("O valor da soma é %d \n", (n1 + n2));
    printf("O valor do produto é %d \n", (n1 * n2));
    printf("O valor da diferença é %d \n", (n1 - n2));
    printf("O valor do quociente é %d \n", (n1 / n2));
    printf("O valor do resto da divisão é %d \n", (n1 % n2));

    return 0;
}