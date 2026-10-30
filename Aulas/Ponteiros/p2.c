#include <stdio.h>
#include <stdlib.h>

// Protótipo da Função
void lerVetor(int *const, const unsigned);
void imprimirVetor(const int *const, const unsigned);
void somar(const int *const, const unsigned, int *const);
int *alocarMemoria(const unsigned tamanho);

int main() {
    int resultado;
    unsigned tamanho = 0;

    puts("Entre com a qtd. de elemntos: ");
    scanf("%u", &tamanho);

    int *pa = alocarMemoria(tamanho);

    lerVetor(pa, tamanho);
    imprimirVetor(pa, tamanho);
    somar(pa, tamanho, &resultado);

    printf("Somátorio do vetor: %d \n", resultado);

    free(pa);
    return 0;
}

int *alocarMemoria(const unsigned tamanho) {
    int *p = NULL;

    if(!(p = (int *) malloc(tamanho * sizeof(int)))) {
        puts("Não há memória disponível");
        exit(1);
    }
    return p;
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