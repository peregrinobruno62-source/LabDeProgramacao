#include <stdio.h>

int main() {
    float altura, peso;
    char genero;

    printf("Qual sua altura em metros: ");
    scanf("%f", &altura);
    printf("Qual seu gênero [M/F]: ");
    scanf(" %c", &genero);

    if (genero == 'M' || genero == 'm') {
        peso = 72.7 * altura - 58;
        printf("Como homem, o seu peso ideal é %.2f kg \n", peso);
    }

    if (genero == 'F' || genero == 'f') {
        peso = 62.1 * altura - 44.7;
        printf("Como mulher, o seu peso ideal é %.2f kg \n", peso);
    }

    return 0;
}