#include <stdio.h>
#include <stdlib.h>

int main(){
    int numero, i;
    printf("Digite o numero desejado: ");
    scanf("%d", &numero);

    for(i = 0; i <= numero; i++){
        printf("%d\n", i);
    }
    return 0;
}