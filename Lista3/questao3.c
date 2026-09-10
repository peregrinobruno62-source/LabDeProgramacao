#include <stdio.h>
#include <math.h>

int main() {
    float a1, p1, v1, a2, p2, v2, aX, pX, vX;
    int gT, numObjetos;
    int acertosChebyshev = 0;
    int acertosManhattan = 0;
    int acertosEuclidiana = 0;

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
        printf("Digite a classe correta (GT) de X%d: ", i);
        scanf("%d", &gT);

        float area1 = fabs(aX - a1);
        float perimetro1 = fabs(pX - p1);
        float num_vertices1 = fabs(vX - v1);
        float distanciaChebyshev1 = fmax(fmax(area1, perimetro1), num_vertices1);
        float distanciaManhattan1 = area1 + perimetro1 + num_vertices1;
        float distanciaEuclidiana1 = sqrt(pow(area1, 2) + pow(perimetro1, 2) + pow(num_vertices1, 2));

        float area2 = fabs(aX - a2);
        float perimetro2 = fabs(pX - p2);
        float num_vertices2 = fabs(vX - v2);
        float distanciaChebyshev2 = fmax(fmax(area2, perimetro2), num_vertices2);
        float distanciaManhattan2 = area2 + perimetro2 + num_vertices2;
        float distanciaEuclidiana2 = sqrt(pow(area2, 2) + pow(perimetro2, 2) + pow(num_vertices2, 2));


        if(distanciaChebyshev1 < distanciaChebyshev2 &&  gT == 1) {
            acertosChebyshev++;
        } else if (distanciaChebyshev1 > distanciaChebyshev2 && gT == 2) {
            acertosChebyshev++;
        }

        if(distanciaManhattan1 < distanciaManhattan2 && gT == 1) {
            acertosManhattan++;
        } else if (distanciaManhattan1 > distanciaManhattan2 && gT == 2) {
            acertosManhattan++;
        }

        if(distanciaEuclidiana1 < distanciaEuclidiana2 && gT == 1) {
            acertosEuclidiana++;
        } else if (distanciaEuclidiana1 > distanciaEuclidiana2 && gT == 2) {
            acertosEuclidiana++;
        }
    }

    float acuraciaC = acertosChebyshev * 100.0 / numObjetos;
    float acuraciaM = acertosManhattan * 100.0 / numObjetos;
    float acuraciaE = acertosEuclidiana * 100.0 / numObjetos;

    printf("\nAcurácia (Chebyshev): %.2f%%\n", acuraciaC);
    printf("Acurácia (Manhattan): %.2f%%\n", acuraciaM);
    printf("Acurácia (Euclidiana): %.2f%%\n", acuraciaE);

    if (acuraciaC > acuraciaM && acuraciaC > acuraciaE) {
        printf("Melhor método de classificação: Chebyshev\n");
    } else if (acuraciaM > acuraciaC && acuraciaM > acuraciaE) {
        printf("Melhor método de classificação: Manhattan\n");
    } else if (acuraciaE > acuraciaC && acuraciaE > acuraciaM) {
        printf("Melhor método de classificação: Euclidiana\n");
    } else {
        printf("Empate entre os métodos de classificação.\n");
    }

    return 0;
}