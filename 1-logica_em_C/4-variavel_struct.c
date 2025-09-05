#include <stdio.h>

struct aluno { // Está definindo um tipo de dado (como no coq)
    int matri;
    char nome[20];
    char mencao[3];
};

typedef struct aluno aluno;

int main() {
    aluno iago = {251039406, "Iago", "SS"};

    printf("A menção do aluno %s de matrícula %d foi: %s\n", iago.nome, iago.matri, iago.mencao);
    return 0;
}