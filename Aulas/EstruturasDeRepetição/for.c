#include <stdio.h>
#include <stdlib.h>

int main () {

    int i;
    
    // Laço finito
    for (i = 0; i < 10; i++) {
        printf("%d \n", i);
    }

    // Laço infinito
    for (;;) {
        printf("Repete ... \n");
    }
    
    return 0;
}