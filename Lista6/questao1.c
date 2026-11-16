#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Protótipos das Funções
int *alocarMemoria(const unsigned tamanho);
void gerarVetor(int tamanho, int *vetor, int limiteMax);
int *buscarPrimeiroPar(int tamanho, int *vetor);

// Digitar o tamanho do vetor e o limite no TERMINAL
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
    int *vet = alocarMemoria(tam);
    int *pPares = NULL;

    gerarVetor(tam, vet, limiteMax);
    pPares = buscarPrimeiroPar(tam, vet);

    if (pPares != NULL) {
        printf("1ª valor par: %d \n", *pPares);
        printf("Endereço: [%p] \n", (void*)pPares);
    } else {
        printf("Nenhum valor par foi gerado.\n");
    }

    free(vet);

    printf("\n");
    return 0;
}

int *alocarMemoria(const unsigned tamanho) {
    int *p = NULL;
    if(!(p = (int *) malloc(tamanho * sizeof(int)))) {
        puts("Erro na alocação de memória");
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

int *buscarPrimeiroPar(int tamanho, int *vetor) {
    for(int i = 0; i < tamanho; i++) {
        if(*(vetor + i) % 2 == 0) {
            return (vetor + i);
        }
    }
    return NULL;
}
