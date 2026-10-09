#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, min, primeiroValor = 1;       
    int *p = &min;

    do {
        printf("Digite um número (Digite -1 pra encerrar o programa): ");
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        if (primeiroValor || num < *p) {
            *p = num;
            primeiroValor = 0;
        }

        printf("O menor valor até agora foi %d \n\n", *p);

    } while (num != -1);

    system("clear");
    printf("Programa encerrado. O menor valor foi: %d\n", *p);

    return 0;
}
