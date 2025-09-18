#include <stdio.h>

int main() {
    int num = 5;

    /*if else:*/

    if (num == 5) {
        printf("O número é igual a 5.\n");
    } else {
        printf("O número não é igual a 5.");
    }

    /*switch case*/
    switch(num) {
        case 1: printf("É o número 1!!\n"); break;
        case 2: printf("É o número 2!!\n"); break;
        case 3: printf("É o número 3!!\n"); break;
        case 4: printf("É o número 4!!\n"); break;
        case 5: printf("É o número 5!!\n"); break;
        default: printf("Não é nenhum número de 1 a 5!"); break;
    }

    return 0;
}