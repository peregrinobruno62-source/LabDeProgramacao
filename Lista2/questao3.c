#include <stdio.h>

int main() {
    int F;
    int fatorial = 1;

    printf("Informe um valor inteiro e positivo: ");
    scanf("%d", &F);

    for (int i = F; i >= 1; i--) {
        fatorial = fatorial * i;
    }

    printf("O fatorial de %d é %d \n", F, fatorial);

    return 0;
}