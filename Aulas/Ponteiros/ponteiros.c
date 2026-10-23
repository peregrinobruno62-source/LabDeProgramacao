#include <stdio.h>

void troca(int *a, int *b) {
    *a = 20;
    *b = 10;
}

int main() {
    int x = 10;
    int y = 20;
    printf("Os valores de x e y são %d e %d \n", x, y);

    troca(&x, &y);
    
    printf("Os valores de x e y (Depois da troca) são %d e %d \n", x, y);

    return 0;
}
