#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

// Protótipos das Funções
int *alocarMemoriaInt(const unsigned tamanho);
void gerarVetor(int tamanho, int *vetor);
int *buscarPrimeiroPar(int tamanho, int *vetor);

int main() {
    srand(time(NULL));
    int *vet = alocarMemoriaInt(TAM);
    int *pv = NULL;

    gerarVetor(TAM, vet);
    pv = buscarPrimeiroPar(TAM, vet);

    if (pv != NULL) {
        printf("1ª valor par: %d \n", *pv);
        printf("Endereço: [%p] \n", (void*)pv);
    } else {
        printf("Nenhum valor par foi gerado.\n");
    }

    free(vet);

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
        *(vetor + i) = rand() % 100;          
        printf("[%d] ", *(vetor + i));
    }
    printf("\n\n");
}

int *buscarPrimeiroPar(int tamanho, int *vetor) {
    for(int i = 0; i < tamanho; i++) {
        if(*(vetor + i) % 2 == 0) {
            return (vetor + i);
        }
    }
    return NULL;
}