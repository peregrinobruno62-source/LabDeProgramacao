#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *alocarMemoria(const unsigned);
unsigned long int *alocarMemoria_unsigned_long(const unsigned);
void popularVetor(int *const, const unsigned, int, int);
void imprimirVetor(const int *const, const unsigned);
void calcularFrequencia(const int *const, unsigned, unsigned long *const);
void imprimirVetorFreq(const unsigned long int *const, const unsigned);

int main() {
    srand(time(NULL));
    unsigned n;
    int limite;

    puts("Tamanho do vetor: ");
    scanf("%u", &n);

    puts("Valor máximo: ");
    scanf("%d", &limite);

    int *pv = alocarMemoria(n);

    popularVetor(pv, n, 0, limite);
    puts("\nVetor Gerado:");
    imprimirVetor(pv, n);

    unsigned long int *f = alocarMemoria_unsigned_long(limite+1);
    
    calcularFrequencia(pv, n, f);
    puts("\nVetor Frequência:");
    imprimirVetorFreq(f, limite);

    return 0;
}

int *alocarMemoria(const unsigned tamanho) {
    int *p = NULL;
    if(!(p = (int *) malloc(tamanho * sizeof(int)))) {
        puts("Não há memória disponível");
        exit(1);
    }
    return p;
}

unsigned long int *alocarMemoria_unsigned_long(const unsigned tamanho) {
    unsigned long int *p = NULL;
    if(!(p = (unsigned long int *) calloc(tamanho, sizeof(unsigned long int)))) {
        puts("Não há memória disponível");
        exit(1);
    }
    return p;
}

void popularVetor(int *const p, const unsigned tamanho, int base, int limite) {
    for (int i = 0; i < tamanho; i++) {
        *(p+i) = base + (rand() % (limite - base));
    } 
}

void imprimirVetor(const int *const p, const unsigned tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("[%p] %d \n", p+i, *(p+i));
    }
}

void calcularFrequencia(const int *const p, unsigned tam_p, unsigned long *const f) {
    for (int i = 0; i < tam_p; i++) {
        f[p[i]]++;
    }
}

void imprimirVetorFreq(const unsigned long int *const p, const unsigned tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("[%p] %lu \n", p+i, *(p+i));
    }
}