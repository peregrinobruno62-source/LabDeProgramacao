#include <stdio.h>

int main () {

    unsigned int idade;

    printf("Digite a idade do sujeito: \n");
    scanf("%u", &idade);
    
    if (idade < 16) {
        printf("Não votar e não dirigir \n");
    } else if (idade < 18) {
        printf("Votar e não dirigir \n");
    } else {
       printf("Votar e dirigir \n");
    }
    
    return 0;
}