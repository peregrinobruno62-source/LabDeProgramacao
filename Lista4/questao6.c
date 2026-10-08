#include <stdio.h>
#include <string.h>

#define TAM 100

int main() {
    char str[TAM];

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    for(int i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}