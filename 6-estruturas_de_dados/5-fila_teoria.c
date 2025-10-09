#include <stdio.h>
#include <stdlib.h>

int main(){

    // Uma fila se trata de uma estrutura FIFO, "first in, first out".
    // O primeiro elemento é o primeiro que sai, como uma fila de mercado.

    // Tratarei das filas dinâmicamente encadeadas

    // Operações básicas da fila:

    // queue(): cria a fila
    // enqueue(item): insere um novo elemento na fila
    // dequeue(): remove o item do início da fila
    // front(): retorna o item do início da fila
    // isEmpty(): verifica se a fila está vazia
    // size(): retorna o número de elementos da fila

    void enqueue(Fila* f, int v) {
        FilaNo* n = (FiloNo*)malloc(sizeof(FilaNo)) // Ponteiro que cria um nó do tamanho de FilaNo
        n->item = v; // o item alocado na localização do ponteiro é o valor a ser adicionado em si
        n->prox = null; // Como o elemento de uma fila é adicionado no final dele, o próximo dele será sempre nulo

        if (f->fim != NULL){
            // Segunda vez que um elemento é adicionado:
            f->fim->prox = NULL;
        } else {
            // Exclusivamente na inserção do primeiro elemento, ele será o primeiro
            f->ini = n;
        }
        f->fim = n; // n é, finalmente, o último elemento de f 
    }

    float dequeue(Fila* f) {
        FilaNo* t = f->ini; // Variável auxiliar para capturar o primeiro valor da fila
        int v = t->item; // Variável auxiliar para guardar o valor a ser excluído e o retornar no final da função
        f->ini = t->prox; // O início da fila agora se torna o próximo elemento de t (antigo primeiro elemento)

        if (f->ini == NULL) { // Verifica se a vila está vazia
            f->fim = NULL; // Logo, o fim não tem nenhum elemento e ela estávaiza
        }
        free(t); // Libera a variável auxiliar
        return v; // Retorna o item eliminado
    }
    return 0;
}