#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
#define MX 10

int main(){
    unsigned char x[TAM];

    puts("Entre com os dados: ");
    for (int k=0; k<TAM; k++){
        scanf("%hhu",&x[k]);
    }

    puts("Dados fornecidos: ");
    for (int k=0; k<TAM; k++){
        printf("x[%d] - [%p] : %hhu\n",k,&x[k],x[k]);
    }

    return 0;
}