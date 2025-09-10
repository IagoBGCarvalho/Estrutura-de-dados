#include <stdio.h>
#include <stdlib.h>

int main() {
    // Também serve para alocar memória durante a execução do programa
    // Escopo: void *calloc(unsigned int num, unsigned int size);
    // Recebe dois parâmetro de entrada: 
    // num: o tamanho em bytes do espaço de memória a ser alocado
    // e size: o tamanho de cada elemento do array

    // A diferença é que são passados os valores da quantidade de elementos 
    // alocados e do tipo de dado alocado como parâmetros distintos da função
    // e que o calloc() incializa todos os bits alocados com 0s

    // Alocação com malloc:
    int *p;
    p = (int *) malloc(50*sizeof(int);

    if (p == NULL) {
        printf("Erro: Memória insuficiente!\n");
    }

    // Alocação com calloc:
    int *p1;
    p1 = (int *) calloc(50,sizeof(int));
    
    if (p1 == NULL) {
        printf("Erro: Memoria insuficiente\n")
    }

    return 0;
}