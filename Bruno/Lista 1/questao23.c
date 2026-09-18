#include <stdio.h>

int main() {
    int x, n, resp;

    printf("Informe um valor inteiro (x): ");
    scanf("%d", &x);
    printf("Informe outro valor inteiro (n) (expoente de 2): ");
    scanf("%d", &n);
    
    resp = x << n;

    printf("O produto entre %d e 2 elevado a %d é igual a %d \n", x, n, resp);
    return 0;
}