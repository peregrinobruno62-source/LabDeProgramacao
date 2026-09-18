#include <stdio.h>
#include <math.h>

int main() {
    int aA, pA, vA, aB, pB, vB, area, perimetro, vertices;
    float dist_de_Chebyshev;

    printf("Digite a área, o perímetro e o número de vértices de A: ");
    scanf("%d %d %d", &aA, &pA, &vA);
    printf("Digite a área, o perímetro e o número de vértices de B: ");
    scanf("%d %d %d", &aB, &pB, &vB);

    area = ((aB - aA) > 0) ? (aB - aA) : -(aB - aA);
    perimetro = ((pB - pA) > 0) ? (pB - pA) : -(pB - pA);
    vertices = ((vB - vA) > 0) ? (vB - vA) : -(vB - vA);

    mod = (n > 0) ? n : -n;

    dist_de_Chebyshev = ;
    d(A, B) = max ((aB - aA), (pB − pA), (vB − vA));

    media_aritmetica = (n1 + n2 + n3) / 3;
    media_geometrica = pow(n1 * n2 * n3, 1.0 / 3.0);

    printf("Media aritmetica: %.2f\n", media_aritmetica);
    printf("Media geometrica: %.2f\n", media_geometrica);

    return 0;
}