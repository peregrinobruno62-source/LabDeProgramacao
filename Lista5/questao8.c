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

    char *ptr = &caractere;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == *ptr) {
            ptr = &str[i];
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 1) {
        printf("\nA string contém o caractere '%c' \n", *ptr);
    } else {
        printf("\nA string não contém o caractere '%c' \n", *ptr);
    }

    return 0;
}