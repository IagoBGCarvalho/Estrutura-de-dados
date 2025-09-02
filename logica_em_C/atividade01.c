#include <stdio.h>

int main() {
    int idade;
    int categoria;

    // Entrada de dados
    printf("EScreva a idade do nadador: ");
    scanf("%d", &idade);

    if (idade >= 5 && idade <= 7) {
        categoria = 1;
    } else if (idade >= 8 && idade <= 10) {
        categoria = 2;
    } else if (idade >= 11 && idade <= 13) {
        categoria = 3;
    } else if (idade >= 14 && idade <= 17) {
        categoria = 4;
    } else {
        categoria = 5;
    }

    switch(categoria) {
        case 1: printf("Infantil A \n"); break;
        case 2: printf("Infantil B \n"); break;
        case 3: printf("Juvenil A \n"); break;
        case 4: printf("Juvenil B \n"); break;
        case 5: printf("Sênior \n"); break;
    }
}