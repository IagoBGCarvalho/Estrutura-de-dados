#include <stdio.h>
#include <stdlib.h>

int main(){
    int numero, i;
    printf("Digite o numero: ");
    scanf("%d", &numero);

    for (i = 1; i <= numero; i++){
        int divisor = numero;
        if ((divisor % i) == 0){
            printf("%d\n", i);
        }
    }
    return 0;
}