#include <stdio.h>
#include <string.h> // Possui o strcmp para comparar strings

long long SOMA(long num1, long num2) {
    /*Retorna a soma de dois valores*/
    return num1 + num2;
}

long long SUBTRACAO(long num1, long num2) {
    /*Retorna a subtração de dois valores*/
    return num1 - num2;
}

long long MULTIPLICACAO(long num1, long num2) {
    /*Retorna a multiplicação de dois valores*/
    return num1 * num2;
}

long long DIVISAO(long num1, long num2) {
    /*Retorna a divisão de dois valores*/
    return num1 / num2;
}

int main() {
    long n1, n2; 
    int resultado_escolha;
    long long resultado_switch;
    char escolha[20];
    scanf("%s", escolha);
    scanf("%li", &n1); // É necessário passar n1 e n2 como ponteiros pois o scanf precisa do endereço de memória das variáveis para alterar elas em si
    scanf("%li", &n2); // long = %li e long long = %lli

    if (strcmp(escolha, "SOMA") == 0) { // sStá comparando se a variável "escolha" é igual a soma
        resultado_escolha = 1;
    } else if (strcmp(escolha, "SUBTRACAO") == 0) {
        resultado_escolha = 2;
    } else if (strcmp(escolha, "MULTIPLICACAO") == 0) {
        resultado_escolha = 3;
    } else if (strcmp(escolha, "DIVISAO") == 0) {
        resultado_escolha = 4;
    }

    switch(resultado_escolha) {
        case 1: resultado_switch = SOMA(n1, n2); break;
        case 2: resultado_switch = SUBTRACAO(n1, n2); break;
        case 3: resultado_switch = MULTIPLICACAO(n1, n2); break;
        case 4: resultado_switch = DIVISAO(n1, n2); break;

    }
    if (resultado_escolha == 1 || resultado_escolha == 2 || resultado_escolha == 3 || resultado_escolha == 4) {
        printf("%lli\n", resultado_switch);
    } else {
        printf("Operação inválida!\n");
    }

    return 0;
}