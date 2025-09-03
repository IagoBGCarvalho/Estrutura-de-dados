#include <stdio.h>
#include <stdlib.h>

int soma(int num1, int num2) { // As funções devem ser declaradas antes da main
    /*
    * Recebe dois números inteiros e retorna a soma de ambos
    */
    return (num1 + num2);
}

int main() {
    int num1, num2;
    printf("Digite os números a serem somados: \n");
    scanf("%d %d", &num1, &num2);
    int soma_numeros = soma(num1, num2);
    printf("%d\n", soma_numeros);
    return 0;
}