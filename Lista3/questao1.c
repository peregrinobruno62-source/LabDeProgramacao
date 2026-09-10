#include <stdio.h>
#include <math.h>

int main() {
    float aA, pA, vA, aB, pB, vB;

    printf("Digite a área de A: ");
    scanf("%f", &aA);
    printf("Digite o perimetro de A: ");
    scanf("%f", &pA);
    printf("Digite o número de vértices de A: ");
    scanf("%f", &vA);

    printf("Digite a área de B: ");
    scanf("%f", &aB);
    printf("Digite o perimetro de B: ");
    scanf("%f", &pB);
    printf("Digite o número de vértices de B: ");
    scanf("%f", &vB);

    float area = fabs(aA - aB);
    float perimetro = fabs(pA - pB);
    float num_vertices = fabs(vA - vB);
    float distanciaChebyshev = fmax(fmax(area, perimetro), num_vertices);

    printf("A distância de Chebyshev entre A e B é %.2f \n", distanciaChebyshev);
    
    return 0;
}