#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

// Protótipos das Funções
int *alocarMemoriaInt(const unsigned tamanho);
float *alocarMemoriaFloat(const unsigned tamanho);
void gerarVetor(int tamanho, int *vetor);
int buscarMenor(int tamanho, int *vetor);
int buscarMaior(int tamanho, int *vetor);
void normalizarVetor(int tamanho, int *vetor, float *normalizado);
void imprimirVetorFloat(int tamanho, float *vetor);

int main() {
    srand(time(NULL));
    int *vet = alocarMemoriaInt(TAM);
    float *norm = alocarMemoriaFloat(TAM);

    gerarVetor(TAM, vet);
    printf("Menor: %d | Maior: %d\n\n", buscarMenor(TAM, vet), buscarMaior(TAM, vet));

    normalizarVetor(TAM, vet, norm);
    puts("Vetor normalizado (min-max): ");
    imprimirVetorFloat(TAM, norm);

    free(vet);
    free(norm);

    printf("\n");
    return 0;
}

int *alocarMemoriaInt(const unsigned tamanho) {
    int *p = NULL;
    if(!(p = (int *) malloc(tamanho * sizeof(int)))) {
        puts("Não há memória disponível");
        exit(1);
    }
    return p;
}

float *alocarMemoriaFloat(const unsigned tamanho) {
    float *p = NULL;
    if(!(p = (float *) malloc(tamanho * sizeof(float)))) {
        puts("Não há memória disponível");
        exit(1);
    }
    return p;
}

void gerarVetor(int tamanho, int *vetor) {
    puts("Vetor gerado: ");
    for(int i = 0; i < tamanho; i++) {
        *(vetor + i) = rand() % 100;
        printf("[%d] ", *(vetor + i));
    }
    printf("\n\n");
}

int buscarMenor(int tamanho, int *vetor) {
    int menor = *vetor;
    for(int i = 1; i < tamanho; i++) {
        if(*(vetor + i) < menor) {
            menor = *(vetor + i);
        }
    }
    return menor;
}

int buscarMaior(int tamanho, int *vetor) {
    int maior = *vetor;
    for(int i = 1; i < tamanho; i++) {
        if(*(vetor + i) > maior) {
            maior = *(vetor + i);
        }
    }
    return maior;
}

// X' = (X - min(X)) / (max(X) - min(X))
void normalizarVetor(int tamanho, int *vetor, float *normalizado) {
    int menor = buscarMenor(tamanho, vetor);
    int maior = buscarMaior(tamanho, vetor);
    int amplitude = maior - menor;

    for(int i = 0; i < tamanho; i++) {
        if(amplitude == 0) { // evita divisão por zero (todos os valores iguais)
            *(normalizado + i) = 0.0f;
        } else {
            *(normalizado + i) = (float)(*(vetor + i) - menor) / amplitude;
        }
    }
}

void imprimirVetorFloat(int tamanho, float *vetor) {
    for(int i = 0; i < tamanho; i++) {
        printf("[%.3f] ", *(vetor + i));
    }
    printf("\n");
}
