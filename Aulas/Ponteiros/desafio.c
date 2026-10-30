#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 9
#define N 5

// Protótipo das Funções
int *alocarMemoriaInt(const unsigned tamanho);
double *alocarMemoriaDouble(const unsigned tamanho);
void gerarVetor(int tamanho, int numeros, int *vetor, int *frequencia);
void mostrarFrequencia(const int *frequencia, int numeros);
void mostrarProbabilidade(const int *frequencia, double *probabilidade, int numeros, int tamanho);
int *buscarEndercoDoMenorValor(const int *vetor, int tamanho);

int main() {
    srand(time(NULL));

    int *vet = alocarMemoriaInt(TAM);
    int *F = (int *) calloc(N, sizeof(int));
    double *P = alocarMemoriaDouble(N);

    if (F == NULL) {
        puts("Erro ao alocar memória para F!\n");
        exit(1);
    }

    gerarVetor(TAM, N, vet, F);
    mostrarFrequencia(F, N);
    mostrarProbabilidade(F, P, N, TAM);

    int *ptrMenor = buscarEndercoDoMenorValor(vet, TAM);
    printf("\n\nMenor valor: %d || Endereço de memória: [%p] || Posição no vetor V: %ld", *ptrMenor, (void*)ptrMenor, ptrMenor - vet);

    free(vet);
    free(F);
    free(P);

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

double *alocarMemoriaDouble(const unsigned tamanho) {
    double *p = NULL;
    if(!(p = (double *) malloc(tamanho * sizeof(double)))) {
        puts("Não há memória disponível");
        exit(1);
    }
    return p;
}

void gerarVetor(int tamanho, int numeros, int *vetor, int *frequencia) {
    puts("Vetor gerado: \n");
    for(int i = 0; i < tamanho; i++) {
        *(vetor + i) = rand() % numeros;          
        *(frequencia + *(vetor + i)) += 1;
        printf("%d ", *(vetor + i));
    }
}

void mostrarFrequencia(const int *frequencia, int numeros) {
    puts("\n\nVetor F (Frequência): \n");
    for(int i = 0; i < numeros; i++) {
        printf("%d ", *(frequencia + i));
    }
}

void mostrarProbabilidade(const int *frequencia, double *probabilidade, int numeros, int tamanho) {
    puts("\n\nVetor P (Probabilidade): \n");
    for(int i = 0; i < numeros; i++) {
        *(probabilidade + i) = (double) *(frequencia + i) / tamanho;
        printf("%.2f ", *(probabilidade + i));
    }
}

int *buscarEndercoDoMenorValor(const int *vetor, int tamanho) {
    if (tamanho <= 0 || vetor == NULL) {
        return NULL;
    }

    const int *pMenor = vetor;
    for (int i = 1; i < tamanho; i++) {
        if (*(vetor + i) < *pMenor) {
            pMenor = vetor + i;
        }
    }

    return (int *)pMenor;
}