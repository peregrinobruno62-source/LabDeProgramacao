#include <stdio.h>

int main() {
    int A, B;
    int soma = 0;
    int qtd = 0;
    float media;

    printf("Informe o primeiro valor da faixa de valores: ");
    scanf("%d", &A);
    printf("Informe o último valor da faixa de valores: ");
    scanf("%d", &B);

    for (int i = A; i <= B; i++) {
        soma += i;
        qtd++;
    }
    media = (float)soma / qtd;
    printf("A média dos números entre %d e %d é %.1f \n", A, B, media);
    
    return 0;
}