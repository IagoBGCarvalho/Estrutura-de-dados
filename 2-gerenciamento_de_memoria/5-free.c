#include <stdio.h>
#include <stdlib.h>

int main() {
    // Free é utilizada para liberar a memória dinamicamente alocada e não mais utilizada
    // Recebe um ponteiro como parâmetro, que deve apontar para o início de memória alocada

    int *p, i; // Criando o ponteiro
    p = (int *) malloc(50*sizeof(int)); // Está atribuindo a p o endereço retornado pelo malloc que equivale a 5 x 4 bytes (tamanho de memória utilizado por um int)


    if (p == NULL) {
        printf("Erro: Memoria Insuficiente.\n");
        exit(1);
    }

    for (i = 0; i < 50; i++) {
        p[i] = i + 1; // Preenchendo a memoria
    }

    for (i = 0; i < 50; i++) {
        printf("%d\n", p[i]);
    }

    free(p); // Libera a memoria vinculada ao ponteiro p
    return 0;
}