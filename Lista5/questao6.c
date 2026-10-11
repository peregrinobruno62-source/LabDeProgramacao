#include <stdio.h>
#include <string.h>
#define TAM 100

int main() {
    char origem[TAM], destino[TAM];

    printf("Digite a string original: ");
    fgets(origem, sizeof(origem), stdin);
    origem[strcspn(origem, "\n")] = '\0';

    char *p_origem = origem;
    char *p_destino = destino;

    while (*p_origem != '\0') {
        *p_destino = *p_origem;
        p_origem++;
        p_destino++;
    }

    *p_destino = '\0';

    printf("String destino (copiada): %s\n", destino);

    return 0;
}
