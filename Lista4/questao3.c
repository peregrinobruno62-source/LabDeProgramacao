#include <stdio.h>
#include <string.h>
#define TAM 100

int main() {
    char str[TAM];
    int contador = 0;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            contador++;
        }
    }

    printf("A string digitada possui %d caracteres (sem incluir espaços em branco e sem incluir o ENTER) \n", contador);

    return 0;
}