#include <stdio.h>

int main() {

    int n = 10;
    int soma = 0;
    int xi_1, xi, xi1;
    
    for(int i = 2; i <= n; i++) {
        printf("Informe o valor de x%d x%d e x%d: ", i-2, i-1, i);
        scanf("%d %d %d", &xi_1, &xi, &xi1);
        soma = xi_1 + xi + xi1;
        float y = soma / 3.0;
        printf("O valor de y%d é %.2f \n", i-1, y);
    }

    return 0;
}