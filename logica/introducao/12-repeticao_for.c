#include <stdio.h>

int main() {
    int a, b, c;

    printf("Digite o primeiro número: ");
    scanf("%d", &a);

    printf("Digite o segundo número: ");
    scanf("%d", &b);

    for (c = a; c <= b; c++) { // (início do loop; condição do loop; o que fazer com a variável a cada loop)
        printf("%d \n", c);
    }
    return 0;
}