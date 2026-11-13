#include <stdio.h>
#include <stdlib.h>
#include "pgm.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso incorreto! Informe o nome da imagem.\n");
        printf("Exemplo: %s img05.pgm\n", argv[0]);
        return 1;
    }

    const char *nome_imagem = argv[1];
    char tipo[3];
    int largura, altura, max_val;

    // 1. Descobre as dimensões da imagem antes de alocar
    if (!ler_cabecalho_pgm(nome_imagem, tipo, &largura, &altura, &max_val)) {
        printf("Erro ao abrir ou ler o cabecalho de '%s'!\n", nome_imagem);
        return 1;
    }

    // 2. Aloca a matriz dinamicamente na própria main usando ponteiros
    int **matriz = (int **)malloc(altura * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }
    for (int i = 0; i < altura; i++) {
        matriz[i] = (int *)malloc(largura * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro de alocacao de memoria na linha %d!\n", i);
            return 1;
        }
    }

    // 3. Preenche a matriz já alocada com os pixels da imagem
    preencher_matriz_pgm(nome_imagem, matriz, largura, altura);

    printf("Imagem '%s' (%s) carregada com sucesso!\n", nome_imagem, tipo);
    printf("Dimensoes: %d linhas (0 a %d) x %d colunas (0 a %d)\n", 
           altura, altura - 1, largura, largura - 1);

    // 4. Pede a coordenada e o tamanho do recorte ao usuário
    int lin_ini, col_ini, tam;
    printf("\nDigite a coordenada inicial (linha coluna): ");
    scanf("%d %d", &lin_ini, &col_ini);

    printf("Digite o tamanho do pedaco quadrado (ex: 5 para 5x5): ");
    scanf("%d", &tam);

    int lin_fim = lin_ini + tam;
    int col_fim = col_ini + tam;
    if (lin_fim > altura) lin_fim = altura;
    if (col_fim > largura) col_fim = largura;

    if (lin_ini < 0 || col_ini < 0 || lin_ini >= altura || col_ini >= largura) {
        printf("Coordenada invalida!\n");
    } else {
        // 5. Mostra apenas o pedaço escolhido na tela e salva
        printf("\n=== PEDACO ESCOLHIDO ===\n");
        imprimir_matriz(matriz, lin_ini, lin_fim, col_ini, col_fim);
        salvar_recorte_pgm("recorte.pgm", matriz, lin_ini, lin_fim, col_ini, col_fim, max_val);
    }

    // 6. Libera a memória alocada na própria main
    for (int i = 0; i < altura; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}