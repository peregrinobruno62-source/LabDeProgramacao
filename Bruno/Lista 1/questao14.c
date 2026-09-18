#include <stdio.h>

int main()
{
    int dias_trabalhados;
    float valor_liquido, valor_bruto;
    
    printf("Quantos dias o vendedor trabalhou: ");
    scanf("%d", &dias_trabalhados);
    
    if (dias_trabalhados <= 10) {
        valor_bruto = dias_trabalhados * 50.25;
    } else if (dias_trabalhados > 10 && dias_trabalhados <= 20)  {
        valor_bruto = dias_trabalhados * 50.25 * 1.20;
    } else {
        valor_bruto = dias_trabalhados * 50.25 * 1.30;
    }
    
    valor_liquido = valor_bruto * 0.9;
    
    printf("O valor ĺıquido a ser pago ao mesmo é %.2f \n", valor_liquido);

    return 0;
}