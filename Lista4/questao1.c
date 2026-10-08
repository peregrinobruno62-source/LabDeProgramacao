#include <stdio.h>
#define TAM 15

int main() {
    float v[TAM];

    for(int i = 0; i < TAM; i++) {
        printf("Digite o %dª valor: ", i + 1);
        scanf("%f", &v[i]);
    }

    for(int i = 0; i < TAM - 1; i++) {
        for(int j = i + 1; j < TAM; j++) {
            if(v[j] < v[i]) {
                float auxiliar = v[i];
                v[i] = v[j];
                v[j] = auxiliar;
            }
        }
    }

    printf("A soma do menor e do maior valor é: %.1f\n", v[0] + v[TAM - 1]);
    return 0;
}