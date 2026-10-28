#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

// Protótipos das Funções
int *alocarMemoriaInt(const unsigned tamanho);
void gerarVetor(int tamanho, int *vetor);
void copiarVetor(int tamanho, int *origem, int *destino);
void ordenarVetor(int tamanho, int *vetor);
float calcularMedia(int tamanho, int *vetor);
float calcularMediana(int tamanho, int *ordenado);
int calcularModa(int tamanho, int *ordenado, int *frequencia);

int main() {
    srand(time(NULL));
    int *vet = alocarMemoriaInt(TAM);
    int *ord = alocarMemoriaInt(TAM);
    int freq = 0;

    gerarVetor(TAM, vet);

    // Mediana e moda exigem o vetor ordenado (a cópia preserva o original)
    copiarVetor(TAM, vet, ord);
    ordenarVetor(TAM, ord);

    printf("Média: %.2f \n", calcularMedia(TAM, vet));
    printf("Mediana: %.2f \n", calcularMediana(TAM, ord));

    int moda = calcularModa(TAM, ord, &freq);
    if(freq > 1) {
        printf("Moda: %d (aparece %d vezes) \n", moda, freq);
    } else {
        printf("Moda: não há (vetor amodal) \n");
    }

    free(vet);
    free(ord);

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

void gerarVetor(int tamanho, int *vetor) {
    puts("Vetor gerado: ");
    for(int i = 0; i < tamanho; i++) {
        *(vetor + i) = rand() % 20; // faixa menor para aumentar a chance de repetição
        printf("[%d] ", *(vetor + i));
    }
    printf("\n\n");
}

void copiarVetor(int tamanho, int *origem, int *destino) {
    for(int i = 0; i < tamanho; i++) {
        *(destino + i) = *(origem + i);
    }
}

// Ordenação por seleção (crescente)
void ordenarVetor(int tamanho, int *vetor) {
    for(int i = 0; i < tamanho - 1; i++) {
        int menor = i;
        for(int j = i + 1; j < tamanho; j++) {
            if(*(vetor + j) < *(vetor + menor)) {
                menor = j;
            }
        }
        int aux = *(vetor + i);
        *(vetor + i) = *(vetor + menor);
        *(vetor + menor) = aux;
    }
}

float calcularMedia(int tamanho, int *vetor) {
    int soma = 0;
    for(int i = 0; i < tamanho; i++) {
        soma += *(vetor + i);
    }
    return (float)soma / tamanho;
}

float calcularMediana(int tamanho, int *ordenado) {
    if(tamanho % 2 != 0) {
        return (float)*(ordenado + tamanho / 2);
    }
    return (*(ordenado + tamanho / 2 - 1) + *(ordenado + tamanho / 2)) / 2.0f;
}

// Percorre o vetor ordenado contando sequências de valores iguais
int calcularModa(int tamanho, int *ordenado, int *frequencia) {
    int moda = *ordenado;
    int maiorFreq = 1;
    int freqAtual = 1;

    for(int i = 1; i < tamanho; i++) {
        if(*(ordenado + i) == *(ordenado + i - 1)) {
            freqAtual++;
        } else {
            freqAtual = 1;
        }
        if(freqAtual > maiorFreq) {
            maiorFreq = freqAtual;
            moda = *(ordenado + i);
        }
    }
    *frequencia = maiorFreq;
    return moda;
}
