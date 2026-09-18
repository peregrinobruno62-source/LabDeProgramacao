                                                                                                                                                                                                                                                                                      #include <stdio.h>

int main() {
    int n, mod;

    printf("Informe um valor inteiro: ");
    scanf("%d", &n);

    mod = (n > 0) ? n : -n;

    printf("O valor absoluto de %d é %d \n", n, mod);

    return 0;
}
