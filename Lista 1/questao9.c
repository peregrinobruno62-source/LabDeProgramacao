#include <stdio.h>

int main() {
    float comprimento, largura, altura, volume;

    printf("Digite o valor do comprimento: ");
    scanf("%f", &comprimento);
    printf("Digite o valor da largura: ");
    scanf("%f", &largura);
    printf("Digite o valor da altura: ");
    scanf("%f", &altura);

    volume = comprimento * largura * altura;

    printf("O volume é %.1f \n", volume);

    return 0;
}