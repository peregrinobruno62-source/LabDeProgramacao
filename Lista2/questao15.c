#include <stdio.h>
#include <math.h>

int main() {
    for (int i = 0; i <= 7; i++) {
        printf("3 elevado a %d é igual a %.1f \n", i, pow(3.0, (double)i));
    }

    return 0;
}