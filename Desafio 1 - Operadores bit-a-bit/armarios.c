#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ARMARIOS 8

unsigned char controle = 0;

int estaOcupado(unsigned char var, int pos) {
    return (var & (1 << pos)) != 0;
}

void ocuparBit(int pos) {
    controle = controle | (1 << pos);
}

void liberarBit(int pos) {
    controle = controle & ~(1 << pos);
}

void exibirStatus(void) {
    printf("\n--- Situacao dos armarios ---\n");
    for (int i = NUM_ARMARIOS - 1; i >= 0; i--) {
        printf("Armario %d: %s\n", i, estaOcupado(controle, i) ? "OCUPADO" : "livre");
    }
    printf("------------------------------\n");
}

int ocuparAleatorio(void) {
    if (controle == 0xFF) {
        return 0;
    }

    int pos;
    do {
        pos = rand() % NUM_ARMARIOS;
    } while (estaOcupado(controle, pos));

    ocuparBit(pos);
    printf("Armario %d foi ocupado.\n", pos);
    return 1;
}

void liberarArmario(void) {
    int pos;
    printf("Digite a posicao do armario a ser liberado (0 a %d): ", NUM_ARMARIOS - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= NUM_ARMARIOS) {
        printf("Posicao invalida!\n");
        return;
    }

    if (!estaOcupado(controle, pos)) {
        printf("O armario %d ja estava disponivel.\n", pos);
        return;
    }

    liberarBit(pos);
    printf("Armario %d foi liberado.\n", pos);
}

int main(void) {
    int opcao;

    srand((unsigned int) time(NULL));

    do {
        printf("\n===== MENU =====\n");
        printf("1. Ocupar armario.\n");
        printf("2. Liberar armario.\n");
        printf("3. Sair.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (!ocuparAleatorio()) {
                    printf("Nao ha armarios disponiveis!\n");
                }
                exibirStatus();
                break;

            case 2:
                liberarArmario();
                exibirStatus();
                break;

            case 3:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 3);

    return 0;
}
