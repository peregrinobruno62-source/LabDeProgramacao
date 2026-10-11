#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main() {
    char vet[TAM];

    for(int i = 0; i < TAM; i++) {
        printf("Digite o %dº valor: ", i + 1);
        scanf(" %c", &vet[i]);
    }

    system("clear");
    for(int i = 0; i < TAM; i++) {
        printf("O %dº valor digitado foi: %c \n", i + 1, vet[i]);
        printf("O endereço do %dº valor digitado é: %p \n\n", i + 1, (void*)&vet[i]);
    }
    
    // Os endereços de memória que eu testei foram:
    // 0x7ffff8585100: float
    // 0x7fff91e8cec0: int
    // 0x7ffc9b16bbf3: char
    // Os endereços fornecidos representam diferentes tipos de dados armazenados na memória;
    return 0;
}