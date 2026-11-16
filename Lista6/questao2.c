#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Protótipos das Funções
int *alocarMemoria(const unsigned tamanho);
void gerarVetor(int tamanho, int *vetor, int limiteMax);
void buscarPrimeiroEUltimoPar(int tamanho, int *vetor, int **vetor_enderecos);

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
    int **vet_enderecos = calloc(2, sizeof(int *));
    if (vet_enderecos == NULL) {
        puts("Erro na alocação de memória");
        exit(1);
    }

    gerarVetor(tam, vet, limiteMax);
    buscarPrimeiroEUltimoPar(tam, vet, vet_enderecos);

    if (vet_enderecos[0] != NULL) {
        printf("1ª valor par: %d \n", *vet_enderecos[0]);
        printf("Endereço do 1ª valor par: [%p] \n\n", (void*)vet_enderecos[0]);
    } else {
        printf("Nenhum valor par foi gerado.\n\n");
    }

    if (vet_enderecos[1] != NULL) {
        printf("Último valor par: %d \n", *vet_enderecos[1]);
        printf("Endereço do último valor par: [%p] \n", (void*)vet_enderecos[1]);
    }

    free(vet);
    free(vet_enderecos); 
    
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
