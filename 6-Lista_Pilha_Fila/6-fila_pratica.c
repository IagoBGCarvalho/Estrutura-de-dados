#include <stdio.h>
#include <stdlib.h>

typedef struct fila Fila;
typedef struct filano FilaNo;

struct filano {
    int item;
    FilaNo* prox;
};

struct fila{
    FilaNo* prim;
    FilaNo* ult;
};

// Funções genéricas:

void imprimirFila(Fila* f){
    for(FilaNo* n = f->prim; n != NULL; n = n->prox){
        printf("Item da fila: %d\n", n->item);
    }
}

int isEmpty(Fila* f){
    /// Função que verifica 
    if(f->prim == NULL){
        printf("Fila vazia.\n");
        return 1;
    }
    return 0;
}

void liberaFila(Fila* f){
    /// Função que libera todos os nós da estrutura e a própria estrutura em si
    FilaNo* n = f->prim;
    while(n != NULL){
        FilaNo* aux = n->prox;
        free(n);
        n = aux;
    }
    printf("Fila liberada!\n");
    free(f);
}

// Funções próprias da fila:

Fila* queue(){
    /// Função que cria a fila
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->prim = NULL;
    f->ult = NULL;
    return f;
}

void enqueue(Fila* f, int v){
    /// Função que aloca um nó na fila
    FilaNo* novo = (FilaNo*)malloc(sizeof(FilaNo));
    novo->item = v;
    novo->prox = NULL; // O novo elemento da fila é sempre o último, e o próximo do último é sempre nulo

    if(f->ult != NULL){
        // Se o último elemento for diferente de nulo, significa que já existem elementos na fila
        f->ult->prox = novo; // Se existe pelo menos um elemento na fila, o próximo do atual último será o novo elemento adicionado
    }else{
        f->prim = novo; // Caso o último da lista seja igual a nulo, significa que ela está vazia, então o primeiro da fila será o novo elemento adicionado
    }
    f->ult = novo;
}

int dequeue(Fila* f){
    /// Função que remove um elemento da fila
    FilaNo* no = f->prim; // Variável para armazenar o nó que será removido (o primeiro da fila)
    int v;

    if(isEmpty(f)){
        return 0;
    }else{
        v = no->item; // A variável que será retornada recebe o valor do item do nó
        f->prim = no->prox; // O primeiro item da fila se torna o próximo do que será excluído
    }

    if(f->prim == NULL){
        // A condição anterior apenas atualiza o prim para nulo, mas não o ult, então é necessário fazer uma condição para atualizar o último quando o primeiro receber nulo
        f->ult = NULL;
    }
    free(no);
    return v;
}

int main(){
    Fila* f = queue(); // Cria a fila
    dequeue(f);

    enqueue(f, 20);
    enqueue(f, 30);
    enqueue(f, 40);
    enqueue(f, 50);

    printf("Fila criada!\n");
    imprimirFila(f);

    printf("Primeiro elemento removido: %d\n", dequeue(f));
    imprimirFila(f);

    printf("Segundo elemento removido: %d\n", dequeue(f));
    imprimirFila(f);

    liberaFila(f);
    return 0;
}