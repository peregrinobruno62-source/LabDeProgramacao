#include <stdio.h>

int main() {
    int A, B;
    int div3 = 0;

    printf("Informe o valor de A: ");
    scanf("%d", &A);
    printf("Informe o valor de B: ");
    scanf("%d", &B);

    if (B < A) {
        for (int i = B; i <= A; i++) {
            if (i % 3 == 0) {
                div3 += 1;
            }
        } 
    }

    if (A < B) {
        for (int i = A; i <= B; i++) {
            if (i % 3 == 0) {
                div3 += 1;
            }
        } 
    }

    printf("A quantidade de números divisíveis por 3 entre %d e %d é %d \n", A, B, div3);

    return 0;
}