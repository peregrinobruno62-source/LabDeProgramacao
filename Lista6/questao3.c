#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Protótipos das Funções
int *alocarMemoriaInt(const unsigned tamanho);
float *alocarMemoriaFloat(const unsigned tamanho);
void gerarVetor(int tamanho, int *vetor, int limiteMax);
void buscarMinMax(int tamanho, int *vetor, int *menor, int *maior);
void normalizarVetor(int tamanho, int *vetor, float *normalizado, int menor, int maior);
void imprimirVetorFloat(int tamanho, float *vetor);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <tamanho_do_vetor> [limite_maximo]\n", argv[0]);
        printf("Exemplo: %s 15 50\n", argv[0]);
        return 1;
    }

    int tam = atoi(argv[1]);
    
    if (tam <= 0) {
        puts("Erro: O tamanho do vetor deve ser maior que zero.");
        return 1;
    }

    int limiteMax = 100;
    if (argc >= 3) {
        limiteMax = atoi(argv[2]);
        if (limiteMax <= 0) {
            limiteMax = 100;
        }
    }

    srand(time(NULL));
    int *vet = alocarMemoriaInt(tam);
    float *norm = alocarMemoriaFloat(tam);

    gerarVetor(tam, vet, limiteMax);

    int menor, maior;
    buscarMinMax(tam, vet, &menor, &maior);
    printf("Menor: %d | Maior: %d\n\n", menor, maior);

    normalizarVetor(tam, vet, norm, menor, maior);
    puts("Vetor normalizado (min-max): ");
    imprimirVetorFloat(tam, norm);

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

void gerarVetor(int tamanho, int *vetor, int limiteMax) {
    puts("Vetor gerado: ");
    for(int i = 0; i < tamanho; i++) {
        *(vetor + i) = rand() % limiteMax;          
        printf("[%d] ", *(vetor + i));
    }
    printf("\n\n");
}

void buscarMinMax(int tamanho, int *vetor, int *menor, int *maior) {
    *menor = *vetor;
    *maior = *vetor;

    for (int i = 1; i < tamanho; i++) {
        if (*(vetor + i) < *menor) {
            *menor = *(vetor + i);
        }
        if (*(vetor + i) > *maior) {
            *maior = *(vetor + i);
        }
    }
}

// X' = (X - min(X)) / (max(X) - min(X))
void normalizarVetor(int tamanho, int *vetor, float *normalizado, int menor, int maior) {
    float amplitude = (float)maior - (float)menor;

    for (int i = 0; i < tamanho; i++) {
        if (amplitude == 0.0f) {
            *(normalizado + i) = 0.0f;
        } else {
            *(normalizado + i) = (*(vetor + i) - menor) / amplitude;
        }
    }
}

void imprimirVetorFloat(int tamanho, float *vetor) {
    for(int i = 0; i < tamanho; i++) {
        printf("[%.3f] ", *(vetor + i));
    }
    printf("\n");
}
