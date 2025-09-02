#include <stdio.h>

int main() {
    char nome[20];
    int dia, mes, ano;

    printf("Digite o seu nome: \n");
    scanf("%s", nome);
    printf("Agora digite a sua data de nascimento: ");
    scanf("%d%d%d", &dia, &mes, &ano); /*O "&" é utilizado para dizer para o scan que a entrada não é uma string!!!*/
    printf("%s nasceu no dia %d do %d de %d.\n", nome, dia, mes, ano);

    return 0;
}