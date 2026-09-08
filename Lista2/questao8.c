#include <stdio.h>

int main() {
    float valor;
    int sistema;

    printf("Informe o valor da mercadoria: ");
    scanf("%f", &valor);

    printf("Informe qual tipo de sistema você deseja: \n");
    printf("[1] - Entrada e prestações são iguais \n");
    printf("[2] - Apenas as prestações são iguais \n");
    scanf("%d", &sistema);

    switch (sistema) {
        case 1:
            printf("O valor da entrada é %.2f reais e o valor de cada prestação é %.2f reais \n", valor / 3.0, valor / 3.0);
            break;
        case 2:
            printf("O valor da entrada é %.2f reais e o valor de cada prestação é %.2f reais \n", valor * 0.3394, valor *  0.3303);
            break;
        default:
            printf("Opção inválida. \n");
    }

    return 0;
}