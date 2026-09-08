#include <stdio.h>
#include <stdlib.h>

int main() {
    int voto = 1;
    char confirmar;
    int totVotosPaulo = 0;
    int totVotosRenata = 0;
    int totVotosBrancos = 0;
    int totVotosNulos = 0;

    while (voto >= 0) {
    printf("=================\n");
    printf(" E L E I Ç Õ E S \n");
    printf("=================\n");
    printf("[5] - Votar no Paulo \n");
    printf("[7] - Votar na Renata \n");
    printf("[0] - Votar em Branco \n");
    printf("Obs: Digite um valor negativo para sair. \n\n");

    printf("Escolha seu voto: ");
    scanf("%d", &voto);

    if (voto < 0) {
        break;
    }

    switch (voto) {
        case 5:
            printf("Você tem certeza que vai votar no Paulo ? [S/N] \n");
            scanf(" %c", &confirmar);
            if (confirmar == 'S' || confirmar == 's') {
                printf("Você votou no Paulo \n");
                totVotosPaulo++;
            }
            if (confirmar == 'N' || confirmar == 'n') {
                printf("Você não votou no Paulo \n");
            }
            break;
        case 7:
            printf("Você tem certeza que vai votar na Renata ? [S/N] \n");
            scanf(" %c", &confirmar);
            if (confirmar == 'S' || confirmar == 's') {
                printf("Você votou na Renata \n");
                totVotosRenata++;
            }
            if (confirmar == 'N' || confirmar == 'n') {
                printf("Você não votou na Renata \n");
            }
            break;
        case 0:
            printf("Você tem certeza que vai votar em Branco ? [S/N] \n");
            scanf(" %c", &confirmar);
            if (confirmar == 'S' || confirmar == 's') {
                printf("Você votou em Branco \n");
                totVotosBrancos++;
            }
            if (confirmar == 'N' || confirmar == 'n') {
                printf("Você não votou em Branco \n");
            }
            break;
        default:
            printf("Número de candidato não válido. \n");
            totVotosNulos++;
    }
    
    system("clear");
    }
    system("clear");
    printf("Resultados da eleição:\n");
    printf("======================\n");
    printf("Paulo: %d votos\n", totVotosPaulo);
    printf("Renata: %d votos\n", totVotosRenata);
    printf("Branco: %d votos\n", totVotosBrancos);
    printf("Nulo: %d votos\n", totVotosNulos);

    return 0;
}