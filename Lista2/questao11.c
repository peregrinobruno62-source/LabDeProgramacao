#include <stdio.h>

int main() {
    int A, B;

    printf("Informe o valor de A: ");
    scanf("%d", &A);
    printf("Informe o valor de B: ");
    scanf("%d", &B);

    if (A > B) {
        for (int i = B; i <= A; i++) {
            if (i % 4 == 0) {
                printf("O quadrado de %d é %d \n", i, i * i);
            }
        } 
    }

    if (A < B) {
        for (int i = A; i <= B; i++) {
            if (i % 4 == 0) {
                printf("O quadrado de %d é %d \n", i, i * i);
            }
        } 
    }

    return 0;
}