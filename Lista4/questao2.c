#include <stdio.h>
#include <string.h>
#define TAM 100

int main() {
    char str[TAM];
    char caractere;
    int encontrado = 0;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Digite o caractere que deseja buscar: ");
    scanf(" %c", &caractere);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == caractere) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 1) {
        printf("A string contém o caractere '%c' \n", caractere);
    } else {
        printf("A string não contém o caractere '%c' \n", caractere);
    }

    return 0;
}