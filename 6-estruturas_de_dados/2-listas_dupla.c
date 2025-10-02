#include <stdio.h>
#include <stdlib.h>

// Lista duplamente encadeada

// Cada elemento da lista se trata de um nó que possui um ponteoiro apontando para o elemento da frente e um apontando para o elemento de trás.

typedef struct lista Lista;
typedef struct listano ListaNo;

struct lista{
    ListaNo* prim;
    ListaNo* ult;
}

struct listano {
    int elem;
    ListaNo* prox;
    ListaNo* ant;
}

Lista* cria_lista(void) {
    Lista* l = (Lista*)malloc(sizeof(Lista*));

    l->prim = NULL;
    l->ult = NULL;

    return l; // Retorna o ponteiro que aponta para o começo da lista (no caso, a lista)
}

void cria_no(Lista* l, int valor) {
    ListaNo* novo = (ListaNo*)malloc(sizeof(ListaNo))

    novo->elem = valor;
    novo->prox = l->prim;
    novo->ant = NULL;

    if (l->prim != NULL) {
        l->prim->ant = novo;
    } else {
        l->ult = novo;
    }
    l->prim = novo; // Como a lista insere no começo, o primeiro elemento da lista é sempre o novo
}

void imprime(Lista* l) {
    for(ListaNo* p = l->prim; p->prox != NULL; p = p->prox) { // p começa do começo da lista (l->prim), vai imprimir enquanto o proxímo elemento for diferente de nulo, e a cada loop p irá receber o próximo elemento
        printf("Item = %d\n", p->elem);
    }
}

int busca(Lista* l, int valor) {
    for(ListaNo* p = l->prim; p != NULL; p = p->prox) {
        if(p->elem == valor) {
            return p;
        }
    }
    return NULL;
}

int vazia(Lista* l) {
    return (l-prim == NULL);
}

void remove(Lista* l, int valor) {
    ListaNo* p = busca(l, valor);

    if(p == NULL) {
        return;
    }

    if(p == l->prim) {
        l->prim = p->prox;
    } else {
        p->ant->prox = p->prox; // O ponteiro prox do elemento anterior ao elemento a ser removido (que está no meio da lista) deve receber o próximo elemento ao que se quer excluir, mantendo o encadeamento.
    }

    if(p == l->ult) {
        l->ult = p->ant;
        p->ant->prox = NULL;
    } else {
        p->prox->ant = p->ant;
    }
}

int main() {


    return 0;
}