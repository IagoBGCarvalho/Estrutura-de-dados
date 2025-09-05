#include <stdio.h>
#include <stdlib.h>

struct ponto {
    int x, y;
};

int main() {
    // A função sizeof() é usada para saber o número de bytes necessários para alocar um único elemento de determinado tipo de dado
    printf("Tamanho char: %d\n", sizeof(char));
    printf("Tamanho int: %d\n", sizeof(int));
    printf("Tamanho float: %d\n", sizeof(float));
    printf("Tamanho double: %d\n", sizeof(double));
    printf("Tamanho struct ponto: %d\n", sizeof(struct ponto));

    int x;
    double y;

    printf("Tamanho da variável x: %d\n", sizeof x);
    printf("Tamanho da variável y: %d\n", sizeof y);
    return 0;
}