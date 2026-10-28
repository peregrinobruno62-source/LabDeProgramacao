#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

// Protótipos das Funções
int *alocarMemoriaInt(const unsigned tamanho);
void gerarVetor(int tamanho, int *vetor);
void buscarPrimeiroEUltimoPar(int tamanho, int *vetor, int **vetor_enderecos);

int main() {
    srand(time(NULL));
    int *vet = alocarMemoriaInt(TAM);
    int **vetor_enderecos = (int **) malloc(2 * sizeof(int *));

    if (vetor_enderecos == NULL) {
        puts("Nao ha memoria disponivel");
        exit(1);
    }
    
    vetor_enderecos[0] = NULL;
    vetor_enderecos[1] = NULL;

    gerarVetor(TAM, vet);
    buscarPrimeiroEUltimoPar(TAM, vet, vetor_enderecos);

    if (vetor_enderecos[0] != NULL) {
        printf("1ª valor par: %d \n", *vetor_enderecos[0]);
        printf("Endereço do 1ª valor par: [%p] \n\n", (void*)vetor_enderecos[0]);
    } else {
        printf("Nenhum valor par foi gerado.\n\n");
    }

    if (vetor_enderecos[1] != NULL) {
        printf("Último valor par: %d \n", *vetor_enderecos[1]);
        printf("Endereço do último valor par: [%p] \n", (void*)vetor_enderecos[1]);
    }

    free(vet);
    free(vetor_enderecos); 
    
    printf("\n");
    return 0;
}

int *alocarMemoriaInt(const unsigned tamanho) {
    int *p = NULL;
    if(!(p = (int *) malloc(tamanho * sizeof(int)))) {
        puts("Não há memoria disponivel");
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

void buscarPrimeiroEUltimoPar(int tamanho, int *vetor, int **vetor_enderecos) {
    for(int i = 0; i < tamanho; i++) {
        if(vetor[i] % 2 == 0) {
            if(vetor_enderecos[0] == NULL) {
                vetor_enderecos[0] = &vetor[i];
            }
            vetor_enderecos[1] = &vetor[i];
        }
    }
}
