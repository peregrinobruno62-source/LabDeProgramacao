#include <stdio.h>

int main() {
    int x = 1;
    int y = 1;
    int z = 0;

    printf("%d \n", x);
    printf("%d \n", y);

    for (int i = 3; i <= 20; i++) {
        z = x + y;
        printf("%d \n", z);
        x = y;
        y = z;
    }

    return 0;
}