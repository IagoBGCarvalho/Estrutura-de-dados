#include <stdio.h>

int fatorial(int n) {
    if (n == 0) {
        return 1; // retorna "true" caso a condição de parada seja satisfeita
    } 
    else {
        return n*fatorial(n-1);
    }
}

int main() {
    int numero;
    printf("Digite o número a ter o fatorial calculado: ");
    scanf("%d", &numero);

    int resultado_fatorial = fatorial(numero);
    printf("%d! = %d\n", numero, resultado_fatorial);

    return 0;
}