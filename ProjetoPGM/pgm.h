#ifndef PGM_H
#define PGM_H

// Lê apenas as informações iniciais do arquivo para a main saber o tamanho da matriz
int ler_cabecalho_pgm(const char *nome_arquivo, char *tipo, int *largura, int *altura, int *max_val);

// Preenche uma matriz já alocada com os pixels do arquivo PGM
int preencher_matriz_pgm(const char *nome_arquivo, int **matriz, int largura, int altura);

// Imprime um intervalo da matriz na tela
void imprimir_matriz(int **matriz, int lin_ini, int lin_fim, int col_ini, int col_fim);

// Salva o recorte em um novo arquivo PGM
void salvar_recorte_pgm(const char *nome_saida, int **matriz, int lin_ini, int lin_fim, int col_ini, int col_fim, int max_val);

#endif