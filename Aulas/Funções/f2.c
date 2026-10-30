#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *alocarMemoria(const unsigned);
void popularVetor(int *const, const unsigned, int, int);
void imprimirVetor(const int *const, const unsigned);

int main(){
    unsigned n;
    puts("Qual o tamanho do vetor: ");
    if (scanf("%u", &n) != 1 || n == 0) return 1;

    int limite;
    puts("Qual o maior valor possível (limite)?: ");
    if (scanf("%d", &limite) != 1 || limite <= 0) return 1;

    int *pv = alocarMemoria(n);
    
    srand(time(NULL));
    popularVetor(pv, n, 0, limite);
    printf("\n--- VETOR COMPLETO ---\n");
    imprimirVetor(pv, n);

    unsigned long int qtdPares = 0;
    for (int i = 0; i < n; i++) {
        qtdPares += (*(pv + i) % 2 == 0) ? 1 : 0;
    }

    // Se não houver nenhum número par, não precisamos fazer a alocação
    if (qtdPares > 0) {
        int **pPares = NULL;
        if (!(pPares = (int **) malloc(qtdPares * sizeof(int *)))) {
            puts("Erro na alocação de pPares");
            exit(1);
        }

        unsigned c = 0;
        for (int i = 0; i < n; i++) {
            if (!((*(pv + i)) % 2)) {
                pPares[c] = pv + i;
                c++;
            }
        }

        printf("\n--- ELEMENTOS PARES ENCONTRADOS ---\n");
        for (int i = 0; i < qtdPares; i++) {
            printf("[%p] Endereço apontado: %p -> Valor: %d \n", 
                   (void*)(pPares + i), (void*)*(pPares + i), *(*(pPares + i)));
        }
        printf("\nQuantidade de Pares: %lu \n", qtdPares);
        free(pPares);
    } else {
        puts("Nenhum número par foi gerado no vetor.");
    }
    
    free(pv);
    return 0;
}

int *alocarMemoria(const unsigned tamanho){
    int *p = NULL;
    if (!(p = (int *) malloc(tamanho * sizeof(int)))){
        puts("Não há memória disponível");
        exit(1);
    }
    return p;
}

void popularVetor(int *const p, const unsigned tamanho, int base, int limite){
    for (unsigned k = 0; k < tamanho; k++){
        *(p+k) = base + (rand() % (limite - base));
    }
}

void imprimirVetor(const int *const p, const unsigned tamanho){
    for (unsigned k = 0; k < tamanho; k++){
        printf("[%p] %d\n", (void*)(p+k), *(p+k));
    }
}