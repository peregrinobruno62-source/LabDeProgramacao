#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

// Protótipos das Funções
float *alocarMemoriaFloat(const unsigned tamanho);
void gerarVetorFloat(int tamanho, float *vetor);
void somarVetor(int tamanho, float *vetor, float *soma);

int main() {
    srand(time(NULL));
    float *vet = alocarMemoriaFloat(TAM);
    float soma = 0.0f;

    gerarVetorFloat(TAM, vet);
    somarVetor(TAM, vet, &soma); // somatório passado por referência

    printf("Somatório: %.2f \n", soma);

    free(vet);

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
    puts("Vetor gerado: ");
    for(int i = 0; i < tamanho; i++) {
        *(vetor + i) = (float)rand() / RAND_MAX * 100.0f; // valores entre 0 e 100
        printf("[%.2f] ", *(vetor + i));
    }
    printf("\n\n");
}

void somarVetor(int tamanho, float *vetor, float *soma) {
    *soma = 0.0f;
    for(int i = 0; i < tamanho; i++) {
        *soma += *(vetor + i);
    }
}
