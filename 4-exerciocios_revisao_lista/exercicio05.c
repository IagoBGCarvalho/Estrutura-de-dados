#include <stdio.h>
#include <stdlib.h>

int main(){
    int dia_da_semana; 
    printf("Digite o número referente ao dia da semana: [1] - Segunda, [2] - Terça, [3] - Quarta, [4] - Quinta, [5] - Sexta, [6] - Sábado e [7] - Domingo: ");
    scanf("%d", &dia_da_semana);

    switch (dia_da_semana){
        case 1: printf("Hoje é segunda!!\n"); break;
        case 2: printf("Hoje é terça!!\n"); break;
        case 3: printf("Hoje é quarta!!\n"); break;
        case 4: printf("Hoje é quinta!!\n"); break;
        case 5: printf("Hoje é sexta!!\n"); break;
        case 6: printf("Hoje é sábado!!!!!\n"); break;
        case 7: printf("Hoje é domingo!\n"); break;
        default: printf("Número maior ou menor do que 1-7.\n");
    }
    return 0;
}