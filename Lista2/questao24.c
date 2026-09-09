#include <stdio.h>

int main() {
    int cateto1, cateto2, hipotenusa;
    long long contador = 0;

    // Teste de das combinações possíveis
    for (cateto1 = 1; cateto1 <= 500; cateto1++) {
        for (cateto2 = cateto1; cateto2 <= 500; cateto2++) {
            for (hipotenusa = 1; hipotenusa <= 500; hipotenusa++) {
                
                // Teste do Teorema de Pitágoras
                if ((cateto1 * cateto1) + (cateto2 * cateto2) == (hipotenusa * hipotenusa)) {
                    printf("%d %d %d \n", cateto1, cateto2, hipotenusa);
                    contador++;
                }
                
            }
        }
    }

    printf("-----------------------------------------\n");
    printf("Total de triplas encontradas: %lld\n", contador);

    return 0;
}