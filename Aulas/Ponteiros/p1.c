#include <stdio.h>
#define TAM 2

// Protótipo da Função
void lerVetor(int *const, const unsigned);
void imprimirVetor(const int *const, const unsigned);
void somar(const int *const, const unsigned, int *const);

int main() {
    int vetor[TAM], resultado;
    int *const pa = vetor;

    lerVetor(pa, TAM);
    imprimirVetor(pa, TAM);

    somar(pa, TAM, &resultado);

    printf("Somátorio do vetor: %d \n", resultado);
   
    return 0;
}

void lerVetor(int *const p, const unsigned tamanho) {
    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o elemento %d \n", i);
        scanf("%d", p+i);
    }
}

void imprimirVetor(const int *const p, const unsigned tamanho) {
    for (int i = 0; i < tamanho; i++)
    {
        printf("[%p] %d \n", p+i, *(p+i));
    }
}

void somar(const int *const p, const unsigned tamanho, int *const p_res) {
    *p_res = 0;
    for (int i = 0; i < tamanho; i++)
    {
        *p_res += *(p+i);
    }
}