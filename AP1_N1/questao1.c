#include <stdio.h>

int main() {
    unsigned char M;

    printf("Digite um número inteiro (0 a 255): ");
    scanf("%hhu", &M);

    unsigned char R = (M >> 2) & 1;
    unsigned char G = (M >> 1) & 1;
    unsigned char B = M & 1;

    printf ("R = %hhu \n", R);
    printf ("G = %hhu \n", G);
    printf ("B = %hhu \n", B);

    return 0;
}
