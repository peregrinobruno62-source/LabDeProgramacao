#include <stdio.h>

int main() {
    int n;
    int anterior, atual, proximo;
    int i;

    scanf("%d", &n);

    if (n < 3) {
        return 0;
    }

    scanf("%d", &anterior);
    scanf("%d", &atual);

    for (i = 2; i < n; i++) {
        scanf("%d", &proximo);

        printf("%.2f", (anterior + atual + proximo) / 3.0);

        if (i < n - 1) {
            printf(" ");
        }

        anterior = atual;
        atual = proximo;
    }

    printf("\n");

    return 0;
}