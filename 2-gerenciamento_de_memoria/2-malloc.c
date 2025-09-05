#include <stdio.h>
#include <stdlib.h>

int main() {
    // A função malloc serve para alocar memória durante a execução do programa
    // É ela que faz o pedido de memória ao computador e retorna um ponteiro com o endereço do início do espaço de memória alocado
    // Normalmente retorna a primeiro posição do array

    int *p;
    p = (int *) malloc(5*sizeof(int)); // Está atribuindo a p o endereço retornado pelo malloc que equivale a 5 x 4 bytes (tamanho de memória utilizado por um int)


    return 0;
}