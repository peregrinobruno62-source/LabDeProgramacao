#include <stdio.h>

int main()
{
    float C, F;
    
    printf("Qual a temperatura em Celsius (°C): ");
    scanf("%f", &C);
    
    F = (9 * C + 160) / 5;
    
    printf("A temperatura em Fahrenheit é %.1f °F \n", F);

    return 0;
}