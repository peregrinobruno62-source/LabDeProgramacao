#include <stdio.h>
#define TAM 3

void mostrarVetor(unsigned tamanho, const *const p) {
    for (int i = 0; i < tamanho; i++) {
        printf("u[%d] é %d \n", i, *(p + i));
    }
}

int main() {
    int u[TAM];

    for (int i = 0; i < TAM; i++) {
        printf("Informe o valor na posição %d: ", i);
        scanf("%d", u + i);
    }

    mostrarVetor(TAM, u);

    return 0;
}