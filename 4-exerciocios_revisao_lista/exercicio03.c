#include <stdio.h>

int main(){
    char nome[20];
    int dia, mes, ano;
    printf("Digite o nome: ");
    scanf("%s", nome);

    printf("Digite o dia, mês e ano de nascimento, linha por linha: ");
    scanf("%d%d%d", &dia, &mes, &ano);

    printf("%s nasceu no dia %d/%d/%d", nome, dia, mes, ano);
}