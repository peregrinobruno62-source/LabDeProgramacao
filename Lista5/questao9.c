#include <stdio.h>

#define TAM 10

int main() {
    int vet[TAM];
    
    for(int i = 0; i < TAM; i++) {
        printf("Digite o %dº valor: ", i + 1);
        scanf("%d", &vet[i]); 
    }

    for(int i = 0; i < TAM - 1; i++) {
        for(int j = 0; j < TAM - i - 1; j++) {
            if(vet[j] > vet[j+1]) {
                int *p1 = &vet[j];
                int *p2 = &vet[j+1];
                
                int temp = *p1;
                *p1 = *p2;
                *p2 = temp;
            }
        }
    }

    printf("\nNumeros ordenados: ");
    for(int i = 0; i < TAM; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
    return 0;
}

