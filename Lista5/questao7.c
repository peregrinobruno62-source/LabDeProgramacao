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

    char *ptr = str;
    char *ptr2 = srt2;

    printf("Concatenando as strings: ");

    while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++;
    }

    while (*ptr2 != '\0') {
        printf("%c", *ptr2);
        ptr2++;
    }
    printf("\n");
    return 0;
}