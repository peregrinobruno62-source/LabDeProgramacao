#include <stdio.h>
#include <string.h>
#define TAM 100

int main() {
    char str[TAM];
    int contador = 0;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    char *ptr = str;

    while (*ptr != '\0') {
        if (*ptr != ' ') {
            contador++;
        }
        ptr++;
    }

    printf("A string digitada possui %d caracteres (sem incluir espacos e o ENTER) \n", contador);

    return 0;
}