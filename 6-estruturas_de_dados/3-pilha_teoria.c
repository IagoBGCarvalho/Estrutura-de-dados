#include <stdio.h>
#include <stdlib.h>

int main() {
    // Pilhas são estruturas que se assemelham a listas, mas que seguem regras específicas
    // sobre a inserção e remoção de elementos.

    // Se quiser acessar determinado elemento na pilha, é necessário remover TODOS os
    // itens que estiverem sobre o elemento desejado.

    // Ou seja, é uma estrutura LIFO (Last In First out) "Último a entrar, primeiro a sair".
    // Funciona como uma pilha de pratos, o último a sair foi o primeiro colocado na pilha,
    // enquanto o último que entrou será o primeiro a ser removido.

    // Um bom exemplo de pilha é a operação de calcular o valor binário de um número decimal.
    // O número é dividido por 2, até o 0, e ao final o resto de cada divisão (0 ou 1) é concatenado ao contrário, gerando o número binário.

    // Exemplo (233):
    // 233 / 2 = 116 (resto 1)
    // 116 / 2 = 58 (resto 0)
    // 58 / 2 = 29 (resto 0)
    // 29 / 2 = 14 (resto 1)
    // 14 / 2 = 7 (resto 0)
    // 7 / 2 = 3 (resto 1)
    // 3 / 2 = 1 (resto 1)
    // 1 / 2 = 0 (resto 1)

    // Representação binária de 233: 11101001

    // Tipos de pilhas:

    // 1 - Alocação estática com acesso sequencial:

    // A quantidade de elementos da pilha é informado no momento da compilação, fazendo com
    // que os elementos sejam inseridos na memória sequencialmente.

    // 2 - Alocação dinâmica com acesso encadeado:

    // O espaço de memória é alocado em tempo de execução, ou seja, aumenta e diminui
    // conforme solicitado. Cada elemento pode estar em um local da memória, mas são
    // encadeados por meio de ponteiros

    // As operações básicas de uma pilha são:

    // stack() - Cria a pilha
    // push(item) - Insere um item na pilha
    // pop() - Remove o item que está no topo da lista
    // peek() - Retorna o item no topo, mas sem remover el
    // isEmpty() - Testa se a pilha está vazia
    // size() - Retorna o número de itens da pilha

    // Implementações:

    void push(Pilha* p, int v){ // p é a pilha já criada com stack() e v o valor a ser inserido
        PilhaNo* n = (PilhaNo*)malloc(sizeof(PilhaNo)); // Este malloc é necessário pois cada elemento da pilha se trata um nó(valor, ponteiro*), então a cada vez que um elemento for adicionado, é necessário gerar um espaço dinâmico do tamanho de um PilhaNo. n é o novo nó a ser criado e será o último elemento da pilha.
        n->item = v; // n recebe o parâmetro (v) que representa o valor a ser adicionado
        n->prox = p->topo; // o próximo de n recebe o topo, visto que agora n é o primeiro elemento. Simplicando, levando em consideração que n é novo elemento da lista, (então será o primeiro a ser removido com um pop()), o próximo elemento, em relação a ele, deve ser o antigo elemento que seria o primeiro a ser removido (o prato mais de cima).
        p->topo = n; // Finalmente, a pilha p recebe, como elemento do topo, n, sendo ele, a partir de então, o primeiro elemento a ser removido da pilha
    }

    int pop(Pilha* p) {
        PilhaNo* t = p->topo; // t é um ponteiro que aponta para o topo da pilha
        int v = t->item; // v é valor a ser excluído, então recebe o item de t (que é o topo da pilha) para ser retornado no final da função
        p->topo = t->prox; // Agora o topo se torna o próximo item de t
        free(t); // O ponteiro é liberado
        return v; // O valor do topo é finalmente retornado
    }
    return 0;
}