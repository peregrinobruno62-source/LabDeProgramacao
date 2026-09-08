#include <stdio.h>

int main() {
    float alturaJose = 1.50;
    float CrescPorAnoJose = 0.02;
    float alturaPedro = 1.10;
    float CrescPorAnoPedro = 0.03;
    int anos = 0;

    while (alturaJose > alturaPedro) {
        alturaJose += CrescPorAnoJose;
        alturaPedro += CrescPorAnoPedro;
        anos++;
    }

    printf("Serão necessários %d anos para que Pedro ultrapasse José em altura. \n", anos);

    return 0;
}