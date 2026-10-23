#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
   unsigned tam;
   puts("Digite o tamanho");
   scanf("%d", &tam);

   int *p = NULL;

   p = malloc(tam *sizeof(int));
   // p = calloc(tam, sizeof(int));

   if(!p) {
    puts("Não tem memória");
    exit(1);
   }

   for(int i = 0; i < tam; i++) {
    *(p+i) = rand() % MAX;
    // ou pode usar p[i] = rand() % MAX;
   }

   free(p);
   return 0;
}