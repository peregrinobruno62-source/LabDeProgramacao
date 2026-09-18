#include <stdio.h>

int main() {
    float reais, cotacao, dolares;

    printf("Digite a quantidade de reais que você quer converter: ");
    scanf("%f", &reais);
    printf("Qual o valor da cotação do dólar: ");
    scanf("%f", &cotacao);

    dolares = reais / cotacao;

    printf("O valor da conversão em dólar é %.2f \n", dolares);

    return 0;
}