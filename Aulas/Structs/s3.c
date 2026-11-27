#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Protótipo da Struct
struct Aluno {
    float n1;
    float n2;
    float media;
};

// Protótipos das Funções
struct Aluno *alocarTurma(unsigned tamanho);
void preencherNotas(struct Aluno *turma, unsigned tamanho);
void calcularMedias(struct Aluno *turma, unsigned tamanho);
void imprimirBoletim(const struct Aluno *turma, unsigned tamanho);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <quantidade_alunos>\n", argv[0]);
        printf("Exemplo: %s 4\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        puts("Erro: A quantidade de alunos deve ser maior que zero.");
        return 1;
    }
    
    srand(time(NULL));

    struct Aluno *turma = alocarTurma(n);

    preencherNotas(turma, n);
    calcularMedias(turma, n);
    imprimirBoletim(turma, n);

    free(turma);
    return 0;
}

struct Aluno *alocarTurma(unsigned tamanho) {
    struct Aluno *p = (struct Aluno *) malloc(tamanho * sizeof(struct Aluno));
    if (p == NULL) {
        puts("Erro na alocação de memória.");
        exit(1);
    }
    return p;
}

void preencherNotas(struct Aluno *turma, unsigned tamanho) {
    for (unsigned i = 0; i < tamanho; i++) {
        turma[i].n1 = ((float)rand() / RAND_MAX) * 10.0f;
        turma[i].n2 = ((float)rand() / RAND_MAX) * 10.0f;
    }
}

void calcularMedias(struct Aluno *turma, unsigned tamanho) {
    for (unsigned i = 0; i < tamanho; i++) {
        turma[i].media = (turma[i].n1 + turma[i].n2) / 2.0f;
    }
}

void imprimirBoletim(const struct Aluno *turma, unsigned tamanho) {
    printf("\n==============================\n");
    printf("       BOLETIM DA TURMA       \n");
    printf("==============================\n");
    for (unsigned i = 0; i < tamanho; i++) {
        printf("Aluno %02u | N1: %5.2f | N2: %5.2f | Média: %5.2f\n", i + 1, turma[i].n1, turma[i].n2, turma[i].media);
    }
}