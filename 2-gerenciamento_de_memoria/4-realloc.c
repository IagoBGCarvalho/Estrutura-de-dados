#include <stdio.h>
#include <stdlib.h>

int main() {
    // realloc modifica o tamanho da memória previamente alocada e apontada
    // Se o tamanho de memória solicitada for 0, a memória apontada pelo ponteiro é liberada

    // Sintaxe: void *realloc(void *ptr, unsigned int num);
    // Recebe dois parâmetro de entrada: 
    // ptr: Ponteiro apontando para o bloco de memória previamente alocado
    // e num: Tamanho em bytes do espaço de memória a ser alocado

    // Retorna o ponteiro para a posição do array alocado

    // Alocando com malloc:
    int *p;
    p = (int *) malloc(5*sizeof(int));

    int i;
    for (i=0; i < 5; i++) {
        printf("Digite o valor da posição %d: ", i);
        scanf("%d", &p[i]);
    }

    for (i = 0; i < 5; i++) {
        printf("%d\n", p[i]); // Printa os valores do array armazenados dinamicamente
    }

    // Diminuindo o tamanho do array utilizando realloc
    p = realloc(p,3*sizeof(int));
    for (i = 0; i < 3; i++) {
        printf("%d\n", p[i]); // Printando novamente o array, mas com menos espaço na memória
    }





    return 0;
}