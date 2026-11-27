#include <stdio.h>

#define QTD_NOTAS 3

// Protótipo da Struct
struct aluno
{
    float notas[3], media[2];
};

// Protótipo da Função
void calcularMedia(struct aluno *const px);

int main() {
    struct aluno a1, a2;

    puts("Digite as notas do 1ª aluno:");
    for (int i = 0; i < QTD_NOTAS; i++)
    {
        scanf("%f", &a1.notas[i]);
    }

    puts("Digite as notas do 2ª aluno:");
    for (int i = 0; i < QTD_NOTAS; i++)
    {
        scanf("%f", &a2.notas[i]);
    }

    calcularMedia(&a1);
    calcularMedia(&a2);

    return 0;
}

void calcularMedia(struct aluno *const px) {
    float s = 0;
    for (int i = 0; i < QTD_NOTAS; i++)
    {
        s += px->notas[i];
    }
    
}