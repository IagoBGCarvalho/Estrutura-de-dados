#include <stdio.h>
#include <stdlib.h>

int main() {
    // Variáveis ponteiro são variáveis que armazenam, como valor, o endereço na memória de uma variável previamente declarada
    // Uma variável ponteiro DEVE ter o mesmo tipo de dado da variável que planeja apontar
    // Sintaxe: tipo_do_ponteiro *nome_ponteiro;
    // Após a declaração do ponteiro:
    // ptr = variavel

    int var = 15;
    int *ptr;

    ptr = &var; // O "&" está atribuindo o endereço da variável como o conteúdo do ponteiro

    printf("\n");

    printf("Conteúdo da var = %d\n", var);
    printf("Endereço da var = %p\n", &var); //%p serve para inserir o endereço da memória

    printf("\n\n");

    printf("Conteúdo apontado por ptr = %d\n", *ptr); // Retorna o conteúdo apontado pelo ponteiro
    printf("Endereço apontado por ptr = %p\n", ptr); // Retorna o endereço apontado pelo ponteiro, ou seja, o endereço de var
    printf("Endereço do ponteiro ptr = %p\n", &ptr); // Retorna o endereço do PRÓPRIO ponteiro

    printf("\n\n-----Fim do código-----\n");

    return 0;
}