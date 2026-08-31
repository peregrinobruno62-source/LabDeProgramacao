#include <stdio.h>

int main()
{
    int horas_trabalhadas;
    float valor_hora, inss, salario_bruto, salario_liquido;
    
    printf("Quantos horas você trabalhou no mês: ");
    scanf("%d", &horas_trabalhadas);
    printf("Qual valor você recebe por hora trabalhada: ");
    scanf("%f", &valor_hora);
    printf("Qual o percentual de desconto do INSS (em porcentagem): ");
    scanf("%f", &inss);
    
    salario_bruto = horas_trabalhadas * valor_hora;
    salario_liquido = salario_bruto * ((100 - inss) / 100);
    
    printf("O salário bruto a ser pago é %.2f \n", salario_bruto);
    printf("O salário ĺıquido a ser pago é %.2f \n" ,salario_liquido);

    return 0;
}