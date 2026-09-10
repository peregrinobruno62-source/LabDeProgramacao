#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, x, q, xReconstruido, erro;
    int somaErros = 0;
    float erroMedio;

    printf("Digite a quantidade de amostras: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {

        printf("\nDigite o valor da amostra %d (0 a 255): ", i);
        scanf("%d", &x);

        q = x >> 4;
        xReconstruido = q << 4;
        erro = abs(x - xReconstruido);
        somaErros += erro;

        printf("\nValor original: %d\n", x);
        printf("Valor quantizado: %d\n", q);
        printf("Valor reconstruído: %d\n", xReconstruido);
        printf("Erro de quantização: %d\n", erro);
    }
    erroMedio = (float)somaErros / n;
    printf("\nErro médio de quantização: %.2f\n", erroMedio);

    return 0;
}