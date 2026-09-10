#include <stdio.h>
#include <math.h>

int main() {
    float a1, p1, v1, a2, p2, v2, aX, pX, vX;
    int numObjetos;

    printf("Quantos objetos deseja classificar? ");
    scanf("%d", &numObjetos);

    printf("\nDigite a área de C1: ");
    scanf("%f", &a1);
    printf("Digite o perimetro de C1: ");
    scanf("%f", &p1);
    printf("Digite o número de vértices de C1: ");
    scanf("%f", &v1);

    printf("Digite a área de C2: ");
    scanf("%f", &a2);
    printf("Digite o perimetro de C2: ");
    scanf("%f", &p2);
    printf("Digite o número de vértices de C2: ");
    scanf("%f", &v2);

    for (int i = 1; i <= numObjetos; i++) {
        printf("\nDigite a área de X%d: ", i);
        scanf("%f", &aX);
        printf("Digite o perimetro de X%d: ", i);
        scanf("%f", &pX);
        printf("Digite o número de vértices de X%d: ", i);
        scanf("%f", &vX);

        float area1 = fabs(aX - a1);
        float perimetro1 = fabs(pX - p1);
        float num_vertices1 = fabs(vX - v1);
        float distanciaChebyshev1 = fmax(fmax(area1, perimetro1), num_vertices1);

        float area2 = fabs(aX - a2);
        float perimetro2 = fabs(pX - p2);
        float num_vertices2 = fabs(vX - v2);
        float distanciaChebyshev2 = fmax(fmax(area2, perimetro2), num_vertices2);

        if(distanciaChebyshev1 < distanciaChebyshev2) {
            printf("A classe é C1 \n");
        } else if (distanciaChebyshev1 > distanciaChebyshev2) {
            printf("A classe é C2 \n");
        } else {
            printf("EMPATE! \n");
        }
    }
    
    return 0;
}