#include <stdio.h>

int main() {
    int n, a;

    printf("Digite o número: ");
    scanf("%d", &n);

    for (a = 0; a <= n; a++) {
        printf("%d \n", a);
    }
    return 0;
}