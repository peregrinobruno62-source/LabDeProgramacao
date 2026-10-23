#include <stdio.h>
#include <string.h>

#define TAM 5

int main () {
    char str[TAM];
    char s2[TAM];

    printf("Digite seu nome: ");
    fgets(str,TAM,stdin);

    char ch;
    while ( (ch = getchar()) != '\n');

    fgets(s2,TAM,stdin);

    unsigned count = 0;
    while(str[count] != '\0') count++;

    printf("\nNome digitado: %s\n", str);
    printf("Segunda string: %s\n", s2);
    printf("Quantidade de caracteres: %u\n", count);

    return 0;
}