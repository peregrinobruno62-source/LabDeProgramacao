#include <stdio.h>
#include <math.h>

int main() {
    float n1, n2, n3;
    float media_aritmetica, media_geometrica;

    printf("Digite três números: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    media_aritmetica = (n1 + n2 + n3) / 3;
    media_geometrica = pow(n1 * n2 * n3, 1.0 / 3.0);

    printf("Media aritmetica: %.2f\n", media_aritmetica);
    printf("Media geometrica: %.2f\n", media_geometrica);

    return 0;
}
