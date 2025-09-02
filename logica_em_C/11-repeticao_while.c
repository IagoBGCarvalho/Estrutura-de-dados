#include <stdio.h>

int main() {
    int a, b;

    printf("Digite o primeiro número: ");
    scanf("%d", &a);

    printf("Digite o segundo número: ");
    scanf("%d", &b);

    while (a < b) {
        printf("%d \n", a);
        a++; // Enquanto a for menor do que b, incremente a
    }
    return 0;
}