#include <stdio.h>

int eh_maior(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else if (num2 > num1) {
        return num2;
    } else {
        return 0;
    }
}

int main() {
    int num1, num2;
    printf("Digite ambos os números: \n");
    scanf("%d %d", &num1, &num2);
    int numero_eh_maior = eh_maior(num1, num2);
    printf("%d", numero_eh_maior);
    return 0;
}