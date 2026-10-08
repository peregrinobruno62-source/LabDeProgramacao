#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3

int main() {
    int mat[LINHAS][COLUNAS];

    for(int i = 0; i < LINHAS; i++) {
        for(int j = 0; j < COLUNAS; j++) {
            printf("Digite o valor para linha %d e a coluna %d: ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\nDiagonal principal da matriz digitada:\n");
    for(int i = 0; i < LINHAS; i++) {
        for(int j = 0; j < COLUNAS; j++) {
            if(i == j) {
                printf("%d ", mat[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}