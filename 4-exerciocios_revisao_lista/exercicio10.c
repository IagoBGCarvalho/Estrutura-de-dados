#include <stdio.h>
#include <stdlib.h>

struct Cadastro{
        // Estrutura cadastro que possui nome, idade e endereco.
        char nome[50];
        int idade;
        char endereco[100];
    };

struct Cadastro* criaVetorCadastro(int N){
    // "struct Cadastro* vetor" para o vetor ser do mesmo tipo que o dado que vai alocar e "(struct Cadastro* malloc...)" para fazer o cast de NULL para struct Cadastro.
    struct Cadastro* vetor = (struct Cadastro*) malloc(N * sizeof(struct Cadastro));

    if (vetor == NULL){
        printf("Memória insuficiente!\n");
        return 0;
    }

    for (int i = 0; i < N; i++){
        // Enquanto i for menor do que o numero de espacos alocados...
        printf("Digite o nome: ");
        scanf("%s", vetor[i].nome); // Armazena o valor no espaco [i] (0) e na variavel nome

        printf("Digite a idade: ");
        scanf("%d", &vetor[i].idade);

        printf("Digite o endereco: ");
        scanf("%s", vetor[i].endereco);
    }
    return vetor; // Retorna o ponteiro que aponta para o inicio da memoria dinamicamente alocada
}

int main(){
    int numeroDeCadastros;

    printf("Digite o numero de espacos que deseja alocar: ");
    scanf("%d", &numeroDeCadastros);

    struct Cadastro* listaDeCadastros = criaVetorCadastro(numeroDeCadastros); // Cria um ponteiro que aponta para o ponteiro retornado pela funcao e que aponta para o inicio da memoria alocada e ativa os codigos de preenchimento da memoria

    printf("Cadastros realizados.\n");

    for (int i = 0; i < numeroDeCadastros; i++){
        printf("Cadastro de numero %d: \n", i + 1);
        printf("Nome: %s\n", listaDeCadastros[i].nome); // Retorna o valor da variavel nome da variavel struct Cadastro que está no primeiro índice da memória alocada
        printf("Idade: %d\n", listaDeCadastros[i].idade);
        printf("Endereco: %s\n", listaDeCadastros[i].endereco);
        printf(" ");
    }

    free(listaDeCadastros); // Libera a memoria alocada que está sendo apontada por este ponteiro
    listaDeCadastros = NULL;

    return 0;
}