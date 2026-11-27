#include <stdio.h>

// Protótipo da Struct
struct aluno
{
    float n1, n2, media;
};

// Protótipo da Função
void calcularMedia(struct aluno *const px);

int main() {
    struct aluno a1, a2;

    puts("Digite as notas do 1ª aluno:");
    scanf("%f %f", &a1.n1, &a1.n2);

    puts("Digite as notas do 2ª aluno:");
    scanf("%f %f", &a2.n1, &a2.n2);

    calcularMedia(&a1);
    calcularMedia(&a2);

    return 0;
}

void calcularMedia(struct aluno *const px) {
    px->media = (px->n1 + px->n2) / 2;
    printf("Média: %.2f\n", px->media);
}