#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

// Protótipos das Funções
float *alocarMemoriaFloat(const unsigned tamanho);
void gerarVetorFloat(int tamanho, float *vetor);
void imprimirVetorFloat(int tamanho, float *vetor);
float calcularEQM(int n, float *a, float *b);

int main() {
    srand(time(NULL));
    float *A = alocarMemoriaFloat(TAM);
    float *B = alocarMemoriaFloat(TAM);

    puts("Vetor A: ");
    gerarVetorFloat(TAM, A);
    imprimirVetorFloat(TAM, A);

    puts("Vetor B: ");
    gerarVetorFloat(TAM, B);
    imprimirVetorFloat(TAM, B);

    printf("Erro médio quadrático: %.4f \n", calcularEQM(TAM, A, B));

    free(A);
    free(B);

    printf("\n");
    return 0;
}

float *alocarMemoriaFloat(const unsigned tamanho) {
    float *p = NULL;
    if(!(p = (float *) malloc(tamanho * sizeof(float)))) {
        puts("Não há memória disponível");
        exit(1);
    }
    return p;
}

void gerarVetorFloat(int tamanho, float *vetor) {
    for(int i = 0; i < tamanho; i++) {
        *(vetor + i) = (float)rand() / RAND_MAX * 10.0f; // valores entre 0 e 10
    }
}

void imprimirVetorFloat(int tamanho, float *vetor) {
    for(int i = 0; i < tamanho; i++) {
        printf("[%.2f] ", *(vetor + i));
    }
    printf("\n\n");
}

// EQM = (1/n) * somatório de (A_i - B_i)^2
float calcularEQM(int n, float *a, float *b) {
    float soma = 0.0f;
    for(int i = 0; i < n; i++) {
        float dif = *(a + i) - *(b + i);
        soma += dif * dif;
    }
    return soma / n;
}
