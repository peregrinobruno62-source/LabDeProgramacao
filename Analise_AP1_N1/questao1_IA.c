#include <stdio.h>

int main() {
    int R, G, B, M;

    scanf("%d %d %d", &R, &G, &B);
    scanf("%d", &M);

    R = (R & ~1) | ((M >> 2) & 1);
    G = (G & ~1) | ((M >> 1) & 1);
    B = (B & ~1) | (M & 1);

    printf("R = %d\n", R);
    printf("G = %d\n", G);
    printf("B = %d\n", B);

    return 0;
}