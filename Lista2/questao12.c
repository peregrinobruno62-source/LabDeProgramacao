#include <stdio.h>

int main() {
    int n;

    printf("Informe um valor: ");
    scanf("%d", &n);
    
    for (int i = 0; i <= 10; i++) {
        printf("%d * %d = %d \n", n, i, n * i);
    }

    return 0;
}