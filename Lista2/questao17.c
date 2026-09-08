#include <stdio.h>

int main() {
    for (int i = 10; i <= 100; i += 10) {
        printf("%d °C é igual a %.1f °F \n", i, (i * 9.0 / 5.0) + 32);
    }
    return 0;
}
