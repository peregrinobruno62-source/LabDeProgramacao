#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Protótipos de Funções
int *alocarMemoria(const unsigned tamanho);
void popular_vetor(int *vetor, int tamanho, int min, int max, int (*gerador)(void));

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Uso: %s <tamanho_vetor> <valor_min> <valor_max>\n", argv[0]);
        return 1;
    }

    int tamanho = atoi(argv[1]);
    int min = atoi(argv[2]);
    int max = atoi(argv[3]);

    if (tamanho <= 0) {
        fprintf(stderr, "Erro: O tamanho do vetor deve ser maior que zero.\n");
        return 1;
    }

    if (min > max) {
        fprintf(stderr, "Erro: O valor minimo (%d) não pode ser maior que o máximo (%d).\n", min, max);
        return 1;
    }

    int *vetor = alocarMemoria(tamanho);

    srand((unsigned int)time(NULL));
    popular_vetor(vetor, tamanho, min, max, rand);

    printf("Vetor gerado: \n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(vetor + i));
    }

    printf("\n");
    free(vetor);
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

void popular_vetor(int *vetor, int tamanho, int min, int max, int (*gerador)(void)) {
    int amplitude = max - min + 1;
    int *ptr = vetor; // Ponteiro "cursor" que aponta pra primeira gaveta do vetor
    int *fim = vetor + tamanho; // Calcular o endereço final do vetor

    while (ptr < fim) {
        int r1 = min + (gerador() % amplitude);
        int r2 = min + (gerador() % amplitude);

        *ptr = (r1 + r2) / 2;
        ptr++; 
    }
}