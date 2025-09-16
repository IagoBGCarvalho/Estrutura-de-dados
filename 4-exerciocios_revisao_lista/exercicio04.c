#include <stdio.h>

int main(){
    int idade;
    int categoria;

    printf("Digite a idade do nadador: ");
    scanf("%d", &idade);

    if (idade >= 5 && idade <= 7){
        categoria = 1;
    } else if (idade >= 8 && idade <= 10){
        categoria = 2;
    } else if (idade >= 11 && idade <= 13){
        categoria = 3;
    } else if (idade >= 14 && idade <= 17){
        categoria = 4;
    } else if (idade >= 18){
        categoria = 5;
    } else {
        printf("Tem que ser maior de 5 anos.");
    }

    switch (categoria){
        case 1: printf("O nadador pertence a categoria 'Infantil A'."); break;
        case 2: printf("O nadador pertence a categoria 'Infantil B'."); break;
        case 3: printf("O nadador pertence a categoria 'Juvenil A'."); break;
        case 4: printf("O nadador pertence a categoria 'Juvenil B'."); break;
        case 5: printf("O nadador pertence a categoria 'Sênior'."); break;
        default: printf("O nadador não tem mais de 4 anos.");
    }
}