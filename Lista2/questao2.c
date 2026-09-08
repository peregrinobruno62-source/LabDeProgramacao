#include <stdio.h>

int main() {
    int valor;

    do {
        printf("Informe um valor (1-7): ");
        scanf("%d", &valor);

        if (valor >= 1 && valor <= 7) {
            switch (valor) {
            case 1:
                printf("Domingo\n");
                break;
            case 2:
                printf("Segunda-feira\n");
                break;
            case 3:
                printf("Terça-feira\n");
                break;
            case 4:
                printf("Quarta-feira\n");
                break;
            case 5:
                printf("Quinta-feira\n");
                break;
            case 6:
                printf("Sexta-feira\n");
                break;
            case 7:
                printf("Sábado\n");
                break;
            }
        } else {
            printf("Número de dia não válido. \n");
        }

    } while (valor != 0);

    return 0;
}