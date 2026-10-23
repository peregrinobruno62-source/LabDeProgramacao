#include <stdio.h>
#include <stdlib.h>

void menu () {

    char ch;

    printf("[1] Checar ortografia \n");
    printf("[2] Corrigir erros de ortografia \n");
    printf("[3] Mostrar erros de ortografia \n");
    printf("Pressione qualquer outra tecla para sair \n");
    printf("Entre com sua escolha: ");

    ch = getchar();

    switch(ch){
        case '1':
        checar_ortografia(); break;
        case '2':
        corrigir_erros(); break;
        case '3':
        mostrar_erros(); break;
        default:
        printf("Nenhuma opção selicionada ");
    }

}