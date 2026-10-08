#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 3
#define COLUNAS 3

int main() {
    srand(time(NULL));
    int mat[LINHAS][COLUNAS];
    int x, cont = 0;

    printf("Matriz gerada:\n");
    for(int i = 0; i < LINHAS; i++) {
        for(int j = 0; j < COLUNAS; j++) {
            mat[i][j] = rand() % 100;
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\nDigite um valor inteiro x: ");
    scanf("%d", &x);

    for(int i = 0; i < LINHAS; i++) {
        for(int j = 0; j < COLUNAS; j++) {
            if(mat[i][j] == x) {
                cont++;
            }
        }
    }

    printf("O valor %d aparece %d vezes na matriz.\n", x, cont);

    return 0;
}