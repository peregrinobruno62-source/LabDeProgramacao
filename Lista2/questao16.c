#include <stdio.h>

int main() {
    int soma_div3 = 0;
    int soma_div5 = 0;

    for (int i = 0; i <= 200; i++) {
        
        if (i >= 0 && i <= 100) {
            if (i % 3 == 0) {
                soma_div3 += i;
            }
        }
        
        if (i > 100 && i <= 200) {
            if (i % 5 == 0) {
                soma_div5 += i;
            }
        }
    }

    // Exibe os resultados
    printf("Somatorio dos divisiveis por 3 no intervalo [0,100]: %d\n", soma_div3);
    printf("Somatorio dos divisiveis por 5 no intervalo ]100,200]: %d\n", soma_div5);

    return 0;
}
