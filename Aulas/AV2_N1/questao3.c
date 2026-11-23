#include <stdio.h>
#include <stdlib.h>

int ehSimetrica(int **M, int N);
int contaSeguidores(int **M, int N, int u);

int main() {
    int N;
    int u;

    printf("Digite o tamanho da matriz (N): ");
    scanf("%d", &N);

    int **M = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        M[i] = (int *)malloc(N * sizeof(int));
    }

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("M[%d][%d] = ", i, j);
            scanf("%d", &M[i][j]);
        }
    }

    if (ehSimetrica(M, N)) {
        printf("A matriz é simétrica.\n");
    } else {
        printf("A matriz não é simétrica.\n");
    }

    printf("Digite o índice do usuário para contar os seguidores: ");
    scanf("%d", &u);
    
    if (u >= 0 && u < N) {
        int seguidores = contaSeguidores(M, N, u);
        printf("O usuário %d tem %d seguidores.\n", u, seguidores);
    } else {
        printf("Índice de usuário inválido.\n");
    }

    for (int i = 0; i < N; i++) {
        free(M[i]);
    }
    free(M);

    return 0;
}

int ehSimetrica(int **M, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (M[i][j] != M[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int contaSeguidores(int **M, int N, int u) {
    int contador = 0;
    for (int j = 0; j < N; j++) {
        if (M[j][u] == 1) {
            contador++;
        }
    }
    return contador;
}