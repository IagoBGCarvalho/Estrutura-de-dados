#include <stdio.h>
#include <stdlib.h>

int e_maior_que(int numero1, int numero2){
    if (numero1 > numero2){
        return 1;
    } else if (numero2 > numero1){
        return 2;
    } else {
        return 0;
    }
}

int main(){
    int n1, n2;
    printf("Digite o primeiro número: ");
    scanf("%d", &n1);

    printf("Digite o segundo número: ");
    scanf("%d", &n2);

    int resultado = e_maior_que(n1, n2);

    switch (resultado){
        case 1: printf("%d é maior do que %d\n", n1, n2); break;
        case 2: printf("%d é maior do que %d\n", n2, n1); break;
        case 0: printf("%d e %d são números iguais.\n", n1, n2); break;
    }
    return 0;
}