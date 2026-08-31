#include <stdio.h>

int main() {
    int horas, min, seg, total;

    printf("Qual a qtd de horas: ");
    scanf("%d", &horas);
    printf("Qual a qtd de minutos: ");
    scanf("%d", &min);
    printf("Qual a qtd de segundos: ");
    scanf("%d", &seg);

    total = (horas * 3600) + (min * 60) + seg;
    printf("Total de segundos: %d \n", total);

    return 0;
}