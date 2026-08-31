#include <stdio.h>

int main() {
    float conta, total;

    printf("Qual o valor da conta: R$ ");
    scanf("%f", &conta);

    total = conta * 1.10;
    
    printf("O total a ser pago é %.2f reais \n", total);

    return 0;
}