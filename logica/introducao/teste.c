#include <stdio.h>

typedef struct aluno {
        int matri;
        char nome[20];
        float notas[3];
    };

int main() {
    
    struct aluno iago = {251039406, "Iago", {7, 8, 10}};

    printf("As notas do aluno %s de matrícula %d foram: %.1f, %1f, %.1f\n", iago.nome, iago.matri, iago.notas[0], iago.notas[1], iago.notas[2]);

    return 0;
}