#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1, x2, y2, dist;

    printf("Digite x1 e y1: ");
    scanf("%f %f", &x1, &y1);

    printf("Digite x2 e y2: ");
    scanf("%f %f", &x2, &y2);

    dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    printf("A distância entre os pontos e: %.2f \n", dist);

    return 0;
}
