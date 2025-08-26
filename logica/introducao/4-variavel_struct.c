#include <stdio.h>

typedef struct aluno iago;

struct aluno { /*Está definindo um tipo de dado*/
        int matri;
        char nome[20]; /*É necessário declarar o tamanho da variável*/
        char mencao[3];
    };

int main() {
    
    aluno iago = {251039406, "Iago", "SS"};

    printf("A menção do aluno %s de matrícula %d foram: %f\n", iago.nome, iago.matri, iago.mencao);
    return 0;
}