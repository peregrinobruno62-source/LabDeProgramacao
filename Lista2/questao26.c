#include <stdio.h>

void imprimirBinario(int n) {
    for (int i = 8; i >= 0; i--) {
        int bit = (n >> i) & 1;
        printf("%d", bit);
    }
}

int main() {
    printf("Decimal | Binário | Octal | Hexadecimal \n");
    printf("=======================================\n");

    for (int i = 1; i <= 256; i++) {
        printf("%d | ", i);
        imprimirBinario(i);
        printf(" | %o | %X \n", i, i);
    }

    return 0;
}