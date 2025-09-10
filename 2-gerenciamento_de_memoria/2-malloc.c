#include <stdio.h>
#include <stdlib.h>

int main() {
    // A função malloc serve para alocar memória durante a execução do programa
    // É ela que faz o pedido de memória ao computador e retorna um ponteiro com o endereço do início do espaço de memória alocado
    // Normalmente retorna a primeiro posição do array, mas caso dê erro, retorna null

    int *p;
    p = (int *) malloc(5*sizeof(int)); // Está atribuindo a p o endereço retornado pelo malloc que equivale a 5 x 4 bytes (tamanho de memória utilizado por um int)

    // A função malooc retorna um ponteiro do tipo void, podendo ser atribuído a qualquer tipo
    int i;
    for (i=0; i < 5; i++) {
        printf("Digite o valor da posição %d: ", i);
        scanf("%d", &p[i]); // & para atribuir os valores dinamicamente alocados ao endereço da memória apontado pelo ponteiro
    }
    return 0;
}