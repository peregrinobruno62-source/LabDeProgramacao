#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *alocarMemoria(const unsigned);
void popularVetor(int *const, const unsigned, int, int);
void imprimirVetor(const int *const, const unsigned);
unsigned long int *alocarMemoria_unsigned_long(const unsigned tamanho);
void calcularFrequencia(const int *const p, unsigned tam_p, unsigned long **f, unsigned tam_f);
void imprimirVetor2(const unsigned long int *const p, const unsigned tamanho);


int main(){
    unsigned n;
    puts("Qual o tamanho do vetor: ");
    scanf("%u",&n);

    int limite; // base;
    puts("Qual o maior valor possível (limite)?: ");
    scanf("%d",&limite);

    // puts("Qual o menor valor possível (base)?: ");
    // scanf("%i",&base);

    int *pv = alocarMemoria(n);
    
    srand(time(NULL));
    popularVetor(pv, n, 0, limite);
    imprimirVetor(pv, n);

    // contar frequência
    unsigned long int *f = NULL;
    calcularFrequencia(pv, n, &f, limite);

    puts("Vetor de Frequência");
    imprimirVetor2(f, limite);
        
    return 0;
}

void calcularFrequencia(const int *const p, unsigned tam_p, unsigned long **f, unsigned tam_f){

    *f = alocarMemoria_unsigned_long(tam_f);

    for (int k=0; k<tam_p; k++){
        (*f)[p[k]]++;
    }
}

int *alocarMemoria(const unsigned tamanho){
    int *p = NULL;
    
    if (!(p = (int *) malloc(tamanho * sizeof(int)))){
        puts("Não há memória disponível");
        exit(1);
    }

    return p;
}

 unsigned long int *alocarMemoria_unsigned_long(const unsigned tamanho){
    unsigned long *p = NULL;
    
    if (!(p = (unsigned long int *) calloc(tamanho,sizeof(unsigned long int)))){
        puts("Não há memória disponível");
        exit(1);
    }

    return p;
}

void popularVetor(int *const p, const unsigned tamanho, int base, int limite){
    for (int k=0; k < tamanho; k++){
        *(p+k) = base + ( rand() % (limite - base));
    }
}

void imprimirVetor(const int *const p, const unsigned tamanho){
    for (int k=0; k < tamanho; k++){
        printf("[%p] %d\n",p+k, *(p+k));
    }
}

void imprimirVetor2(const unsigned long int *const p, const unsigned tamanho){
    for (int k=0; k < tamanho; k++){
        printf("[%p] %lu\n",p+k, *(p+k));
    }
}