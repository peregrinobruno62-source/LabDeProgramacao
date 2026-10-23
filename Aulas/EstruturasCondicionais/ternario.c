#include <stdio.h>

int main () {

    int x;
    int y;

    puts("Digite um valor:");
    scanf("%d", &x);

    y = (x % 2)? printf("%d \n", x*10): printf("%d \n", x*2); // Impar multiplica por 10, Par multiplica por 2
    
    return 0;
}