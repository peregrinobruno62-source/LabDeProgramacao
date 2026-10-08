#include <stdio.h>
#include <string.h>

#define TAM 100

int main() {
    char str[TAM], srt2[TAM];

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Digite outra string: ");
    fgets(srt2, sizeof(srt2), stdin);
    srt2[strcspn(srt2, "\n")] = '\0';

    int i = 0;
    int sao_iguais = 0;

    while (str[i] != '\0' || srt2[i] != '\0') {
        if (str[i] != srt2[i]) {
            sao_iguais = 1;
            break;
        }
        i++;
    }

    if (sao_iguais == 0) {
        printf("As strings digitadas são iguais.\n");
    } else {
        printf("As strings digitadas não são iguais.\n");
    }

    return 0;
}