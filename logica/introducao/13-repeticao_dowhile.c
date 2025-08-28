#include <stdio.h>

int main() {
    int i;

    do {
        printf("Escolha uma opção: \n");
        printf("(1) Opção 1 \n");
        printf("(2) Opção 2 \n");
        printf("(3) Opção 3 \n");
        scanf("%d", &i);
    } while ((i < 1) || (i > 3));

    printf("Você escolheu a opção %d. \n", i);
    return 0;
}