#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pgm.h"

// Função interna auxiliar para pular comentários (#)
static void pular_comentarios(FILE *arquivo) {
    int ch = fgetc(arquivo);
    while (ch == ' ' || ch == '\n' || ch == '\r') {
        ch = fgetc(arquivo);
    }
    if (ch == '#') {
        while (fgetc(arquivo) != '\n');
    } else {
        ungetc(ch, arquivo);
    }
}

int ler_cabecalho_pgm(const char *nome_arquivo, char *tipo, int *largura, int *altura, int *max_val) {
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        return 0;
    }

    fscanf(arquivo, "%2s", tipo);
    pular_comentarios(arquivo);
    fscanf(arquivo, "%d %d", largura, altura);
    fscanf(arquivo, "%d", max_val);

    fclose(arquivo);
    return 1;
}

int preencher_matriz_pgm(const char *nome_arquivo, int **matriz, int largura, int altura) {
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        return 0;
    }

    char tipo[3];
    int l, a, max;

    // Avança o cabeçalho para chegar exatamente onde começam os pixels
    fscanf(arquivo, "%2s", tipo);
    pular_comentarios(arquivo);
    fscanf(arquivo, "%d %d", &l, &a);
    fscanf(arquivo, "%d", &max);
    fgetc(arquivo); // Consome a quebra de linha após o max_val

    if (strcmp(tipo, "P2") == 0) {
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < largura; j++) {
                fscanf(arquivo, "%d", &matriz[i][j]);
            }
        }
    } else if (strcmp(tipo, "P5") == 0) {
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < largura; j++) {
                unsigned char pixel;
                fread(&pixel, sizeof(unsigned char), 1, arquivo);
                matriz[i][j] = (int)pixel;
            }
        }
    }

    fclose(arquivo);
    return 1;
}

void imprimir_matriz(int **matriz, int lin_ini, int lin_fim, int col_ini, int col_fim) {
    for (int i = lin_ini; i < lin_fim; i++) {
        for (int j = col_ini; j < col_fim; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void salvar_recorte_pgm(const char *nome_saida, int **matriz, int lin_ini, int lin_fim, int col_ini, int col_fim, int max_val) {
    FILE *saida = fopen(nome_saida, "w");
    if (saida == NULL) {
        printf("Erro ao criar o arquivo %s!\n", nome_saida);
        return;
    }

    int nova_altura = lin_fim - lin_ini;
    int nova_largura = col_fim - col_ini;

    fprintf(saida, "P2\n");
    fprintf(saida, "%d %d\n", nova_largura, nova_altura);
    fprintf(saida, "%d\n", max_val);

    for (int i = lin_ini; i < lin_fim; i++) {
        for (int j = col_ini; j < col_fim; j++) {
            fprintf(saida, "%d ", matriz[i][j]);
        }
        fprintf(saida, "\n");
    }

    fclose(saida);
    printf("\nRecorte salvo com sucesso no arquivo '%s'!\n", nome_saida);
}