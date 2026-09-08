#include <stdio.h>

int main() {
    int A, B;
    int somatorio = 0;

    printf("Informe o valor de A: ");
    scanf("%d", &A);
    printf("Informe o valor de B: ");
    scanf("%d", &B);

    if (A > B) {
        for (int i = B; i <= A; i++) {
            if (i % 2 == 0) {
                somatorio += i;
            }
        } 
    }

    if (A < B) {
        for (int i = A; i <= B; i++) {
            if (i % 2 == 0) {
                somatorio += i;
            }
        } 
    }

    printf("A soma dos números pares entre %d e %d é: %d \n", A, B, somatorio);

    return 0;
}